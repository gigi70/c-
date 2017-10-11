/*gianni santin
pledged
program 7
oct 10. */

#include <iostream>
using namespace std;

template <class T>
struct node
{
	T info;
	node * next;
};

template <class T>
class List
{
public:
   List();
   void MakeEmpty();
   bool IsFull() const;
   int GetLength() const;
   int RetrieveItem(T item, bool & found);
   void InsertItem(T item);
   void DeleteItem(T item);
   void ShowList();
   ~List(){MakeEmpty();}
private:
  int length;
  node<T>* listPtr;
};

template <class T>
List<T>::List()
{
  length = 0;
  listPtr = NULL;
}


template <class T>
int List<T>::GetLength() const
{
  return length;
}

template <class T>
bool List<T>::IsFull() const
{

  node<T>* temp;
  try{
  temp = new node<T>;
  delete temp;
  return false;
  }
  catch(std::bad_alloc exception)
  {
      return true;
  }
}
template <class T>
void List<T>::MakeEmpty()
{

  int i;
  node<T>* temp;
  for (i = 1; i <= length; i++)
  {
      temp = listPtr;
      listPtr = listPtr->next;
      delete temp;
  }
  length = 0;
}
template <class T>
void List<T>::InsertItem(T item)
{
   /* node<T>* temp = new node<T>;
    temp->info = item;
    node<T>* current;
    node<T>* previous;

    if (length == 0)
    {
        temp->next=NULL;
        listPtr = temp;
    }
    else
    {
        current=listPtr;
        previous = listPtr;
        while((current->info < item) && (current->next != NULL))
        {
            previous = current;
            current = current->next;
        }
        previous->next = temp;
        temp->next  = current;
    }*/
 node<T>* newNode = new node<T>;
 node<T>* predLoc = new node<T>;
 node<T>* location = new node<T>;
 bool moreToSearch;

 location = listPtr;
 predLoc = NULL;
 moreToSearch = (location != NULL);

    while(moreToSearch)
  {
     if (location->info < item)
     {
         predLoc = location;
         location = location->next;
         moreToSearch = (location != NULL);
     }
     else
        moreToSearch = false;
  }
        newNode = new node<T>;
        newNode->info = item;
        if (predLoc == NULL)
        {
            newNode->next = listPtr;
            listPtr = newNode;
        }
        else
        {
            newNode->next = NULL;
            predLoc->next = newNode;
        }
        length++;
    cout << "Added item " << item << endl;
}
template <class T>
void List<T>::DeleteItem(T item)
{

   node<T>* previousPtr, *currentPtr, *tempPtr;
   if (item == listPtr->info) {
      tempPtr = listPtr;
      listPtr = listPtr->next;
      delete tempPtr;
		 length--;
   }
   else {
        previousPtr = listPtr;
        currentPtr = listPtr->next;
  while ((currentPtr != NULL) && (currentPtr->info != item))
		{
      previousPtr = currentPtr;
		currentPtr = currentPtr->next;
      }
      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->next = currentPtr->next;
         delete tempPtr;
         length--;
      }
   }

}
template <class T>
int List<T>::RetrieveItem(T  item, bool&  found )
{  bool  moreToSearch;
	 node<T>*  location;
   location = listPtr;
	 found = false ;
	 moreToSearch = ( location  !=  NULL );
	 while ( moreToSearch  &&  !found )
	    {  if ( item  == location->info )
          {  found = true;
		        item  = location->info;
	        }
	   else
	   {  location = location->next;
		   moreToSearch = ( location  !=  NULL );
      }   }
   return item;
}
template <class T>
void List<T>::ShowList()
{
    node<T>* p = listPtr;
    while (p)
       {
        cout << p->info << endl;
        p = p->next;
       }
}

main()
{   int a, i;
    char ch;
    bool b;
    float y;
    List<int> A;
    List<char> B;
    List<float> C;
    for (i = 1; i <= 10; i++)
        A.InsertItem(i+100);
    cout << "Length is " <<A.GetLength() << endl<<"Here is the list: " << endl;
    A.ShowList();
    if (A.IsFull())
        cout << "List is Full. " << endl;
    else
        cout << "List is not full. "  << endl;
    A.MakeEmpty();
    cout << "Length is now " << A.GetLength()<< endl << "List: " << endl;
    A.ShowList();
    cout<<endl<<endl<<endl;
    B.InsertItem('x');
    B.InsertItem('y');
    B.InsertItem('z');
    cout << "Length is " << B.GetLength()<< endl;
    B.DeleteItem('y');
    cout << "Deleted an element; list is now " << B.GetLength() << endl;
    for (ch = 'A'; ch <= 'Z'; ch++)
        B.InsertItem(ch);
    cout << "Length is " <<B.GetLength() << endl<<"Here is the list: " << endl;
    B.ShowList();
    cout<<endl<<endl<<endl<<endl;
    C.InsertItem(1.5);
    C.InsertItem(2.5);
    C.InsertItem(3.5);
    cout << "Length is " << C.GetLength()<< endl;
    C.DeleteItem(2.5);
    cout << "Deleted an element; list is now " << C.GetLength() << endl;
    for (y = 1.5; y <= 10.5; y = y + 1)
        C.InsertItem(y);
    cout << "Length is " <<C.GetLength() << endl<<"Here is the list: " << endl;
    C.ShowList();
}
