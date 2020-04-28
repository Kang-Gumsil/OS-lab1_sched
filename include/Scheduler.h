#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <iostream>
#include "Process.h"
using namespace std;

class Scheduler {
protected:
	int** resultArr;		// �� �ʸ��� ���� ���� ��� �����ϴ� �迭
	int timeSum;			// ��� job�� service time �հ�
	int runtime;			// �����ٷ� ����ð�
	Process* running;		// �������� ���μ���
	Process** job;			// Process�� �迭�� ������

public:
	Scheduler(Process** process);   // ������
	virtual void doSchedule() = 0;
	void printSchedule();   // ��� ���
};
#endif