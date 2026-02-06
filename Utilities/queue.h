#include"node.h"

class Queue {
	private:
		node *front, *rear;
		
	public:
		Queue();
		void enqueue(int key);
		int dequeue();
		bool isEmpty();
};
