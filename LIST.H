#ifndef _LIST_H_
#define _LIST_H_
  // this directives requires for prevent of
  // repeated include this header in some module
 
class Item
{
  friend class List;
 
private:
  // Base set
  Item * prev;
  Item * next;
 
  // Additional
  List * owner;    // for remove self from list and
                   // for check when item in list
public:
  Item(void);
  ~Item();         // for correct object destruction
                   // with removing it from list
  // Additional
  Item * Next(void) const;  // special for implementation
                            // of iterations algorithms,
                            // returns "next" field
};
 
class List
{
private:
  // Base set
  Item * head;
  Item * tail;
 
  // Additional
  int count;     // for quickly count items in list
 
public:
  List(void);
  ~List();       // kills all of items inself
 
  // Base set
  void Add(Item * p);
  Item * GetItem(int n) const;
  Item * Remove(int n);
  int Count(void) const;
 
  // Additional
  void Insert(Item * p, int n); // insert item by pointer "p"
                                // at position "n" in list or
                                // (VERY IMPORTANT!) at end of list
  int GetIndex(const Item * p) const;
  void Delete(int n);        // found and destroy
  void Clear(void);
  Item * Remove(Item * p);   
 
  Item * First(void) const;   
 
#endif