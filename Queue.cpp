#include <iostream>
#include "Queue.h"
using namespace std;

// 생성자
Queue::Queue() { front = rear = NULL; }

void Queue::push(Process* job) {
	if (front == NULL) {	// 큐가 비어있는 경우
		front = rear = job;
	}
	else {
		rear->link = job;
		rear = job;
	}
}

Process* Queue::pop() {
	if (front == NULL) {	// 큐가 비어있는 경우
		return NULL;
	}

	Process* temp = front;
	front = temp->link;
	temp->link = NULL;
	return temp;
}

