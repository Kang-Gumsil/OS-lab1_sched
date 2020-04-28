#include <iostream>
#include "include/Queue.h"
using namespace std;

Queue::Queue() { front = rear = NULL; }

void Queue::push(Process* job) {
	if (front == NULL) {
		front = rear = job;
	}
	else {
		rear->link = job;
		rear = job;
	}
}

Process* Queue::pop() {
	if (front == NULL) {
		return NULL;
	}

	Process* temp = front;
	front = temp->link;
	temp->link = NULL;
	return temp;
}

