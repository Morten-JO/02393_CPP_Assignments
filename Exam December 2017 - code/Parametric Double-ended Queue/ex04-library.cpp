#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
mydeque<T>::mydeque() {
  size=0;
  first=nullptr;
  last=nullptr;
}

//Do not modify
template<class T>
int mydeque<T>::getSize() {
  return size;
}

//Do not modify
template<class T>
void mydeque<T>::print_front() {
  if(size==0){
    cout << "The deque is empty.\n";
  }
  else{
    cout << first->content <<"\n";
  }
}

//Do not modify
template<class T>
void mydeque<T>::print() {
  if(size==0){
    cout << "The deque is empty.\n";
  }
  else{
    cout << "The deque has size " << size << ":\n";
    Node<T> * current =   first;
    while(current!=nullptr){
      cout << "  " <<current->content << "\n";
      current = current->next;
    }
  }
}

//Do not modify
template<class T>
void mydeque<T>::push_when_empty(T v) {
  Node<T> * node = new Node<T>;
  node->content=v;
  node->next=nullptr;
  first=node;
  last=node;
  size=1;
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
mydeque<T>::~mydeque() {
  Node<T> * current =   first;
  while(current!=nullptr){
    Node<T> * next = current->next;
    delete current;
    current = next;
  }
  cout << "Destructor completed\n";
}

//Exercise 4 (b) Implement this function
template<class T>
void mydeque<T>::push_back(T v) {
  if(size == 0){
    push_when_empty(v);
  } else{
    Node<T> * node = new Node<T>;
    node->content = v;
    node->next = nullptr;
    last->next = node;
    last = node;
    size++;
  }
}

//Exercise 4 (c) Implement this function
template<class T>
void mydeque<T>::push_front(T v) {
  if(size == 0){
    push_when_empty(v);
  } else{
    Node<T> * node = new Node<T>;
    node->content = v;
    node->next = first;
    first = node;
    size++;
  }
}

//Exercise 4 (d) Check and correct if necessary
template<class T>
void mydeque<T>::print_back() {
  if(size == 0){
    cout << "The deque is empty.\n";
  }
  else{
    cout << last->content <<"\n";
  }
}

//Exercise 4 (e) Complete body of last else
template<class T>
bool mydeque<T>::pop_front() {
  if(size==0){
    return false;
  } else if(size==1){
    delete first;
    first=nullptr;
    last=nullptr;
    size=0;
    return true;
  }
  else{
    Node<T> * node = first->next;
    delete first;
    first = node;
    size--;
    return true;
  }
}

//Do not modify
template class mydeque<int>;
