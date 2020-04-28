#ifndef QUEUE_H
#define QUEUE_H
#include "Process.h"

class Queue {
private:
	Process* front, * rear;

public:
	Queue();
	void push(Process* job);
	Process* pop();
};

#endif