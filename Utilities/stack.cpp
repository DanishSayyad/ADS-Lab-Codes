#include<iostream>
#include<climits>
#include"stack.h"

Stack :: Stack() {
	top = NULL;
}

void Stack :: push(int key) {
	node *nn = new node(key);
	if(!nn) return;
	
	nn->next = top;
	top = nn;
}

int Stack :: pop() {
	if(!top) return INT_MIN;
	node *ptr = top;
	top = top -> next;
	int data = ptr->data;
	delete ptr;
	return data;
}

int Stack :: peek() {
	if(!top) return INT_MIN;
	return top->data;
}

bool Stack :: isEmpty() {
	return (top ? true : false);
}

