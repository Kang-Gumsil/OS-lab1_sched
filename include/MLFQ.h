#ifndef MLFQ_H
#define MLFQ_H
#include "include/Process.h"
#include "include/Scheduler.h"
#include "include/Queue.h"

class MLFQ : public Scheduler { // 4���� Queue�� ������ �ְ� time quantum�� 1�� MLFQ
private:
	Queue* queue; // �ε����� �������� ���� ť
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
