#ifndef _LISTNODE_H_
#define _LISTNODE_H_
 
#include <iostream>
#include <string>
 
template<class T>
class List
{
public:
        List():head(0), tail(0)
        {
        }
        
        ~List()
        {
                while(head)
                {
                    tail=head->next;
                    delete head;
                    head=tail;
                }
        }
 
        void push_back(T val)
        {
                Node* Temp;
                Temp=new Node;
                Temp->elem=val;
                if(head==0)
                {
                        head=Temp;
                        tail=Temp;
                        return;
                }
                tail->next=Temp;
                tail=Temp;
        }
 
        void print()
        {
                if(head==0)
                {
                        throw std::string("List is empty!");
                }
                for(Node* ptr=head; ptr!=0; ptr=ptr->next)
                {
                        std::cout<<ptr->elem<<' ';
                }
                std::cout<<'\n';
        }
 
        void push_front(T val)
        {
                Node* Temp;
                Temp=new Node;
                Temp->elem=val;
                Temp->next=head;
                head=Temp;
        }
 
        void erase()
        {
                if(head==0)
                {
                        throw std::string("List is empty!\n");
                }
                Node* delptr=head->next;
                head=head->next;
                delete delptr;
        }
        
        void erase(T val)
        {
                Node* ptrPrev;
                ptrPrev=new Node;
                if(head==0)
                {
                        throw std::string("List is empty\n");
                }
                for(Node* ptr=head; ptr!=0; ptr=ptr->next)
                {
                        if(ptr->elem==val)
                        {
                                ptrPrev->next=ptr->next;
                                delete ptr;
                                break;
                        }
                        ptrPrev=ptr;
                }
                if(ptrPrev->next==0)
                        std::cout<<"There are no elements in list equal to "<< val <<'\n';
        }
 
        void clear()
        {
                while(head!=0)
                        erase();
        }
 
        void find(T val)
        {
                if(head==0)
                {
                        throw std::string("List is empty!\n");
                }
                for(Node* ptr=head; ptr!=0; ptr=ptr->next)
                {
                        if(ptr->elem=val)
                                std::cout<<"Element "<< val <<" is finded\n";
                        return;
                }
                std::cout<<"Element "<< val <<" is not finded\n";
        }
        
        void insert(T val)
        {
                if(head==0)
                {
                        push_front(val);
                        return;
                }
                Node* Temp=new Node;
                Temp->elem=val;
                Node* founded=head;
                for(founded; founded!=0; founded=founded->next)
                {
                        if(founded->elem<val)
                                break;
                }
                if(founded==0)
                {
                        push_front(val);
                        return;
                }
                Temp->next=founded->next;
                founded->next=Temp;
        }
private:
        struct Node
        {
                Node():next(0), elem(0)
                {
                }
                Node* next;
                T elem;
        };
 
        Node* head;
        Node* tail;
};
 
#endif