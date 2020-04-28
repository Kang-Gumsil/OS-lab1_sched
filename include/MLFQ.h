#ifndef MLFQ_H
#define MLFQ_H
#include "include/Process.h"
#include "include/Scheduler.h"
#include "include/Queue.h"

class MLFQ : public Scheduler { // 4개의 Queue를 가지고 있고 time quantum이 1인 MLFQ
private:
	Queue* queue; // 인덱스가 작을수록 높은 큐
	int timeQuantum;
	int S;
	int Q;

public:
	MLFQ(Process** process, int quantum, int s, int q);
	void boosting();
	void pushProcess(int time);
	void repushProcess(int p);
	void runProcess(int time, int quantum, int& priority);
	void runProcess(int time, int& priority);
	virtual void doSchedule();
};
#endif
