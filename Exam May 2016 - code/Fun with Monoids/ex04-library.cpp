#include <iostream>
#include "ex04-library.h"

using namespace std;

// Exercise 4 (a)
template <class C>
Monoid<C>::Monoid(C constant){
    m1 = nullptr;
    m2 = nullptr;
    this->constant = constant;
}

// Exercise 4 (b)
template <class C>
Monoid<C>::Monoid(Monoid<C> & m1, Monoid<C> & m2){
    this->m1 = &m1;
    this->m2 = &m2;
}

// Exercise 4 (c)
template <class C>
Monoid<C>::Monoid(Monoid & m){
     this->constant = m.constant;
     m1 = m.m1;
     m2 = m.m2;
}

// Exercise 4 (d)
template <class C>
Monoid<C> Monoid<C>::operator*(Monoid<C> & m){
    Monoid<C> monoidPleb(*this, m);
    return monoidPleb;
}

// Exercise 4 (e)
template <class C>
C Monoid<C>::eval(C (*f)(C,C)){
    if(this->m1 == nullptr){
      return constant;
    } else{
      return f(m1->eval(f), m2->eval(f));
    }
}

// Do not modify
template <class C>
void Monoid<C>::print(void){
    if (m1 == nullptr) cout << constant ;
    else {
        m1->print();
        cout << " * " ;
        m2->print();
    }
}

// Do not modify
template class Monoid<string>;
template class Monoid<unsigned int>;
