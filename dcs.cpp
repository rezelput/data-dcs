#include <iostream>
#include <cassert>
#include "List.H"
 
struct node
{
    node() = default;
    node(int const rhs) : data(rhs) {};
    int data;
    node* next = nullptr, *prev = nullptr;
};
 
class list
{
public:
    list() = default;
    void add(int const rhs)
    {
        node* nn = new node(rhs);
        if (!head)
        {
            head = nn;
            tail = head;
        }
        else
        {
            node* tmp = head;
            for (int i = 0; i < rhs - 1 && tmp; ++i)
            {
                tmp = tmp->next;
            }
            if (!tmp)
            {
                tail->next = nn;
                tail->next->prev = tail;
                tail = tail->next;
            }
            else
            {
                if (tmp == head)
                {
                    head->prev = nn;
                    nn->next = head;
                    head = nn;
                }
                else
                {
                    nn->next = tmp;
                    nn->prev = tmp->prev;
                    tmp->prev = nn;
                    nn->prev->next = nn;
                }
            }
        }
    }
 
    node* find(int const rhs) const
    {
        node* tmp = head;
        while (tmp && rhs != tmp->data)
        {
            tmp = tmp->next;
        }
 
        return tmp;
    }
 
    void del(int const rhs)
    {
        node* tmp = find(rhs);
 
        if (tmp == head)
        {
            if (tail == tmp)
            {
                head = tail = nullptr;
            }
            else
            {
                head = tmp->next;
                head->prev = nullptr;
            }
        }
        else if (tmp == tail)
        {
            tail = tmp->prev;
            tail->next = nullptr;
        }
        else if(tmp)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
 
        delete tmp;
        tmp = nullptr;
    }
 
    void print() const
    {
        node* tmp = head;
        while (tmp)
        {
            std::cout << tmp->data << "  ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
 
 
 
    list(list const&) = delete;
    list& operator=(list const&) = delete;
 
    ~list()
    {
        while (head)
        {
            tail = head;
            head = head->next;
            //std::cout << "\ndel: " << tail->data;
            delete tail;
            tail = nullptr;
        }
        assert(!head && !tail);
    }
private:
    node * head = nullptr, *tail = nullptr;
};
 
int main() 
{
    list lst;
 
    lst.add(5);
    lst.add(1);
    lst.add(7);
    lst.add(3);
    lst.add(3);
 
    lst.print();
 
    lst.del(1);
    lst.del(7);
    lst.del(5);
    lst.del(3);
 
    lst.print();
}