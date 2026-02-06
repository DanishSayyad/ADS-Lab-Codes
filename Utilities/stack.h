#include"node.h"

class Stack {
	private:
		node *top;
		
	public:
		Stack();
		void push(int key);
		int pop();
		int peek();
		bool isEmpty();
};
