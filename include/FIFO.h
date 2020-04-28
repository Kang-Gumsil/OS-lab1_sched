#ifndef FIFO_H
#define FIFO_H
#include <iostream>
#include "include/Process.h"
#include "include/Scheduler.h"
#include "include/Queue.h"
using namespace std;

class FIFO : public Scheduler {
private:
	Queue* queue;

public:
	FIFO(Process** process);
	void pushProcess(int time);
	void runProcess(int time);
	virtual void doSchedule();
};

#endif
