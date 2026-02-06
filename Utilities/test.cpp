#include<iostream>
//#include"stack.h"
#include"queue.h"

using namespace std;

int main() {
	/*Stack s;
	s.push(10);
	s.push(20);
	*/
	Queue q;
	q.enqueue(100);
	q.enqueue(200);
	q.enqueue(300);
	/*
	cout << "Stack:\n";
	cout << s.pop() << endl;
	cout << s.peek() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;*/
	
	cout << "Queue:\n";
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	return 0;
}
