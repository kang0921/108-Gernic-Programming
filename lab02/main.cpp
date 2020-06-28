// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
// self-referential structure
template <typename T>
struct listNode {
    T data; // each listNode contains a character
    struct listNode<T> *nextPtr; // pointer to next node
    typedef input_iterator_tag iterator_category;
}; // end structure listNode

template<typename T>
using ListNode = listNode<T>;
template<typename T>
using ListNodePtr = listNode<T>*;

template <class T>
class nodeWrapper : public iterator<input_iterator_tag, T>
{
public :
    ListNodePtr<T> startPtr;
    nodeWrapper(ListNodePtr<T> p = nullptr) : startPtr(p) { }
    decltype(startPtr->data) operator*() const { return startPtr->data; }
    ListNodePtr<T>& operator->() const{ return *startPtr; }
    nodeWrapper& operator++() { startPtr = startPtr->nextPtr; return *this; }

    bool operator==(const nodeWrapper<T>& i) const { return startPtr == i.startPtr; }
    bool operator!=(const nodeWrapper<T>& i) const { return startPtr != i.startPtr; }
};

// prototypes
template <typename T>
void insert( ListNodePtr<T> *sPtr, T value );
template <typename T>
void deleter( ListNodePtr<T> *sPtr, T value );
template <typename T>
int isEmpty( ListNodePtr<T> sPtr );
template <typename T>
void printList( ListNodePtr<T> currentPtr );

//my I/O format
template <typename T>
void Input(nodeWrapper<T> *, vector<T>);
template <typename T>
void Output(nodeWrapper<T>);
template <typename T>
void Find (nodeWrapper<T>, T);

//type data
void Interger();
void Double();
void Charater();
void String();

int main( void )
{
    Interger();
    Double();
    Charater();
    String();
} // end main

template <typename T>
void Input(nodeWrapper<T> *ob, vector<T> vec){
    for (auto travel : vec){
        insert(&(ob->startPtr), travel);
    }
}

template <typename T>
void Output(nodeWrapper<T> ob){
    printList(ob.startPtr);//no "->"
}

template <typename T>
void Find (nodeWrapper<T> ob, T value){
    nodeWrapper<T> i = find(nodeWrapper<T> (ob.startPtr), nodeWrapper<T> (), value);

    if(i != nullptr)
        cout << "Found : " << value << endl;
    else
        cout << "Not found : " << value << endl;
    cout << endl;
}

void Interger(){
    cout << "=== Interger ===" << endl;
    vector<int> IntergerVec = {1, 2 ,3, 4, 5, 6};
    nodeWrapper<int> ob;
    Input(&ob, IntergerVec);
    Output(ob);
    Find(ob, 2);
    Find(ob, 7);
    deleter(&(ob.startPtr), 2);//no ->
    Output(ob);
    cout << endl << endl;
}

void Double(){
    cout << "=== Double ===" << endl;
    vector<double> DoubleVec = {1.1, 2.2 ,3.3, 4.4, 5.5, 6.6};
    nodeWrapper<double> ob;
    Input(&ob, DoubleVec);
    Output(ob);
    Find(ob, 2.2);
    Find(ob, 7.7);
    deleter(&(ob.startPtr), 2.2);//no ->
    Output(ob);
    cout << endl << endl;
}

void Charater(){
    cout << "=== Charater ===" << endl;
    vector<char> CharVec = {'a', 'b', 'c', 'd', 'e'};
    nodeWrapper<char> ob;
    Input(&ob, CharVec);
    Output(ob);
    Find(ob, 'c');
    Find(ob, 'F');
    deleter(&(ob.startPtr), 'c');//no ->
    Output(ob);
    cout << endl << endl;
}

void String(){
    cout << "=== String ===" << endl;
    string str1 = "aa", str2 = "bb";
    vector<string> StringVec = {str1};
    nodeWrapper<string> ob;
    Input(&ob, StringVec);
    Output(ob);
    string s1 = "aa";
    string s2 = "ff";
    Find(ob, s1);
    Find(ob, s2);
    deleter(&(ob.startPtr), str1);//no ->
    Output(ob);
    cout << endl << endl;
}

// insert a new value into the list in sorted order
template <typename T>
void insert( ListNodePtr<T> *sPtr, T value )
{
   ListNodePtr<T> newPtr; // pointer to new node
   ListNodePtr<T> previousPtr; // pointer to previous node in list
   ListNodePtr<T> currentPtr; // pointer to current node in list

   newPtr = ( ListNode<T>* )malloc( sizeof( ListNode<T> ) ); // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->data = value; // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node

      previousPtr = NULL;
      currentPtr = *sPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && value > currentPtr->data ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // insert new node at beginning of list
      if ( previousPtr == NULL ) {
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } // end if
      else { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } // end else
   } // end if
   else {
      cout << value << " not inserted. No memory available.\n";
   } // end else
} // end function insert

// delete a list element
template <typename T>
void deleter( ListNodePtr<T> *sPtr, T value )
{
    cout << "Delete : " << value << endl;
    cout << "After delete : " << endl;
    ListNodePtr<T> previousPtr; // pointer to previous node in list
    ListNodePtr<T> currentPtr; // pointer to current node in list
    ListNodePtr<T> tempPtr; // temporary node pointer

    // delete first node
    if ( value == ( *sPtr )->data ) {
      tempPtr = *sPtr; // hold onto node being removed
      *sPtr = ( *sPtr )->nextPtr; // de-thread the node
      free( tempPtr ); // free the de-threaded node
    } // end if
    else {
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->data != value ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // delete node at currentPtr
      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
      } // end if
    } // end else
} // end function delete

// return 1 if the list is empty, 0 otherwise
template <typename T>
int isEmpty( ListNodePtr<T> sPtr )
{
   return sPtr == NULL;
} // end function isEmpty

// print the list
template <typename T>
void printList( ListNodePtr<T> currentPtr )
{
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else {
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr != NULL ) {
         cout << fixed << setprecision(3) << (currentPtr->data) << " --> ";
         currentPtr = currentPtr->nextPtr;
      } // end while

      puts( "NULL\n" );
   } // end else
} // end function printList


