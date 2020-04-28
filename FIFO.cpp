#include <iomanip>
#include "include/FIFO.h"

FIFO::FIFO(Process** process) : Scheduler(process) { 
	queue = new Queue();
}

// �����ٸ� ����
void FIFO::doSchedule() {
	for (int t = 0; t < timeSum; t++) {
		// ������ job�� ť�� ����
		pushProcess(t);

		// job ����
		if (t == runtime)
			runProcess(t);
	}

	// ��� ���
	printSchedule();
}

// ���� ���� job�� ť�� �־���
void FIFO::pushProcess(int time) {
	for (int i = 0; i < 5; i++)
		if (time == job[i]->getArriveTime())
			queue->push(job[i]);
}

// ���μ��� ����
void FIFO::runProcess(int time) {

	running = queue->pop();
	for (int t = 0; running; t++) {
		cout << setw(2) << (char)(running->getPid() + 'A');
		running->addPerformedTime(1); // ����ð� 1�� �߰�
		resultArr[running->getPid()][time + t] = 1; // ��� ��� ���� �迭�� 1����
		runtime++;

		if (running->getServiceTime() == running->getPerformedTime())
			running = NULL;
	}
}
