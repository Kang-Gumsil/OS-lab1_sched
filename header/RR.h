#ifndef RR_H
#define RR_H
#include "Process.h"
#include "Scheduler.h"
#include "Queue.h"

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
