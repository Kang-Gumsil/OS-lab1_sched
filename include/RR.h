#ifndef RR_H
#define RR_H
#include "include/Process.h"
#include "include/Scheduler.h"
#include "include/Queue.h"

class RR : public Scheduler {
private:
	Queue *queue;
	int timeQuantum;

public:
	RR(Process** process, int quantum);
	virtual void doSchedule();
	void pushProcess(int time);
	void repushProcess();
	void runProcess(int time, int quantum);
	
};
#endif
