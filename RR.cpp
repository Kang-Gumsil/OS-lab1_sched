#include <iomanip>
#include "include/RR.h"

RR::RR(Process** process, int quantum) : Scheduler(process) {
	timeQuantum = quantum;
	queue = new Queue();
}

// �����ٸ� ����
void RR::doSchedule() {
	for (int t = 0; t < timeSum; t++) { // 1�ʸ��� ����

		// ������ job�� ť�� ����
		pushProcess(t);

		// timeout�� job�� ť�� �ٽ� �־���
		if (t == runtime) {
			if (running)
				repushProcess();
		}

		// ���μ��� ����
		if (t == runtime) {
			runProcess(t, timeQuantum);
		}
	}

	// ��� ���
	printSchedule();
}

// ť�� ������ job �־���
void RR::pushProcess(int time) {
	for (int i = 0; i < 5; i++) {
		if (time == job[i]->getArriveTime())
			queue->push(job[i]);
	}
}

// �� ������ ������ �ʾ����� time quantum�� ���� job �ٽ� ť�� �־���
void RR::repushProcess() {
	if (running->getServiceTime() > running->getPerformedTime()) {
		queue->push(running);
		running = NULL;
	}
}

// ���μ��� ����
void RR::runProcess(int time, int quantum) {
	running = queue->pop();
	for (int q = 0; running && q < quantum; q++) {
		cout << setw(2) << (char)(running->getPid() + 'A');
		running->addPerformedTime(1); // ����ð� 1�� �߰�
		resultArr[running->getPid()][runtime] = 1; // ��� ��� ���� �迭�� 1����
		runtime++; // ��Ÿ�� ����

		// time quantum�� ������ �ʾ����� job�� ������ ������ ����
		if (running->getServiceTime() == running->getPerformedTime()) {
			running = NULL;
			break;
		}
	}
}
