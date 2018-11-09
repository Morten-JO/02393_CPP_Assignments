#include "doubly-linked.h"
#include <cmath>
#include <iostream>

using namespace std;

List::List(){
	first = NULL;
}

List::~List(){
	Node* node = first;
	while(node != NULL){
		Node* tempNode = node;
		node = node->next;
		delete tempNode;
	}
}

void List::insert(int n){
	if(first != NULL){
		Node* node = first;
		while(node->next != NULL){
			node = node->next;
		}
		Node* newNode = new Node;
		newNode->val = n;
		newNode->prev = node;
		newNode->next = NULL;
		node->next = newNode;
	} else {
		first = new Node;
		first->val = n;
		first->next = NULL;
		first->prev = NULL;
	}
}

void List::reverse(){
	Node* node = first;
	while(node != NULL){
		Node* prev = node->prev;
		Node* next = node->next;
		node->prev = next;
		node->next = prev;
		if(node->prev == NULL){
			first = node;
		} 
		node = node ->prev;
	}
}

void List::print(){
	Node* node = first;
	bool first = true;
	while(node != NULL){
		if(!first){
			cout << " ";
		} else{
			first = false;
		}
		cout << node->val;
		node = node->next;
	}
	cout << '\n';
}

