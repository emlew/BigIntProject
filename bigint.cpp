/*
The bigint class is used to represent positive 
integers. It can represent any integer 0 or 
larger, with an arbitrary number of digits.

This file contains the implementation of all the
methods defined in the interface (bigint.h).

Name: Emily Lewis
Date: 10/2/2022

*/

#include <iostream>
#include <string>
#include "bigint.h"

using namespace std;


bigint::bigint( ) {
  head = new node;
  head->data = 0;
  head->next = NULL;
}


bigint::bigint( int n ) {
  head = NULL;
  int place = 0;
  while (n > 0) {
    place = n % 10;
    addDigit(place, head);
    n = n/10;
  }
}


bigint::bigint( string n ) {
  head = NULL;
  for (int i = 0; i < n.length(); i++){
    char x = n.at(i);
    node* temp = new node;
    temp->data = int(x)-48;
    temp->next = head;
    head = temp;
  }
}


bigint::~bigint( ) {
  node* temp = head;
  node* deleted;
  while ( temp != NULL ) {
    deleted = temp;
    temp = temp->next;
    delete deleted;
    deleted = NULL;
  }
  head = NULL;
}


void bigint::set( int n ) {
  node* temp = head;
  node* deleted;
  while ( temp != NULL ) {
    deleted = temp;
    temp = temp->next;
    delete deleted;
    deleted = NULL;
  }
  head = NULL;
  int place = 0;
  while (n > 0) {
    place = n % 10;
    addDigit(place, head);
  n = n/10;
  }
}


void bigint::set( string n ) {
  node* temp = head;
  node* deleted;
  while ( temp != NULL ) {
    deleted = temp;
    temp = temp->next;
    delete deleted;
    deleted = NULL;
  }
  head = NULL;
  for (int i = 0; i < n.length(); i++){
    char x = n.at(i);
    node* add = new node;
    add->data = int(x)-48;
    add->next = head;
    head = add;
  }
}


void bigint::set( const bigint &n ) {
  node* temp = head;
  node* deleted;
  while ( temp != NULL ) {
    deleted = temp;
    temp = temp->next;
    delete deleted;
    deleted = NULL;
  }
  head = NULL;
  node* add = n.head;
  while (add != NULL ) {
    addDigit( add->data, head);
    add = add->next;
  }
}


void bigint::increment( ) {
  add( 1 );
}


void bigint::add( int n ) {
  node* temp = head;
  temp->data+=n;
  while (temp->data >= 10 ) {
    int nextDigit = temp->data/10;
    temp->data =  temp->data-nextDigit*10;
    if (temp->next == NULL) {
      node* add =  new node;
      add->data = nextDigit;
      add->next = NULL;
      temp->next = add;
      temp = temp->next;
    }
    else {
      temp = temp->next;
      temp->data+=nextDigit;
    }
  }
}


void bigint::print( ) {
  printRecursive(head);
  cout<<endl;
}


void bigint::printRecursive(node* head) {
  if ( head != NULL ) {
    printRecursive(head->next);
    cout<<head->data;
  }
}


void bigint::addDigit( int n, node* &head ) {
  if (head == NULL) {
    node* temp = new node;
    temp->data = n;
    temp->next = NULL;
    head = temp;
    return;
  }
  node* prev = head;
    while ( prev->next != NULL ) {
        prev = prev->next;
    }
    node* temp = new node;
    temp->data = n;
    temp->next = prev->next;
    prev->next = temp;
}


void bigint::multiply( int n ) {
  node* temp = head;
  while (temp != NULL) {
    temp->data = temp->data*n;
    temp = temp->next;
  }
  temp = head;
  while (temp != NULL) {
    if (temp->data >= 10) {
      int nextDigit = temp->data/10;
      temp->data = temp->data-nextDigit*10;
      if (temp->next == NULL) {
        node* add =  new node;
        add->data = nextDigit;
        add->next = NULL;
        temp->next = add;
        temp = temp->next;
      }
      else {
        temp = temp->next;
        temp->data+=nextDigit;
      }
    }
    else {
      temp = temp->next;
    }
  }
}
