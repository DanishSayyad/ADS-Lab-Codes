#include<iostream>
#include<climits>
#include"queue.h"

Queue :: Queue() {
	front = rear = NULL;
}

void Queue :: enqueue(int key) {
	node *nn = new node(key);
	if(!nn) return;
	
	rear->next = nn;
	rear = nn;
}

int Queue :: dequeue() {
	if(!front) return INT_MIN;
	node *ptr = front;
	front = front -> next;
	int data = ptr->data;
	delete ptr;
	return data;
}

bool Queue :: isEmpty() {
	return (front ? true : false);
}

