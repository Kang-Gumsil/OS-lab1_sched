#include <cmath>
#include "MLFQ.h"
#include "Scheduler.h"

// ������
MLFQ::MLFQ(Process** process, int quantum, int s, int q) : Scheduler(process) {
	queue = new Queue[q];
	timeQuantum = quantum;
	S = s;
	Q = q;
}

// �����ٸ� ����
void MLFQ::doSchedule() {
	int priority;
	for (int t = 0; t < timeSum; t++) {
		// ���� ���� job�� �ֻ��� ť�� �־���
		pushProcess(t);

		// ���� ����ð��� �ð��� �帧(t)�� ����ȭ �����ֱ� ����
		if (t == runtime) {

			// job ����
			if (timeQuantum) 
				runProcess(t, timeQuantum, priority);
			else
				runProcess(t, priority);

			// timeout�� job�� ť�� �ٽ� �־���
			if (running)
				repushProcess(priority);
		}

		// �ֱ⸶�� �ν��� ����
		if ((t + 1) % S == 0) {
			boosting();
		}
	}
	printSchedule();
}

// S���� ��� ť�� �ֻ����� �ø� -> rule 5
void MLFQ::boosting() {
	for (int i = 1; i < Q; i++) {
		while (Process* temp = queue[i].pop())
			queue[0].push(temp);
	}
}

// ���� ���� job�� �ֻ��� ť�� �־��� -> rule 3
void MLFQ::pushProcess(int time) {
	for (int i = 0; i < 5; i++)
		if (time == job[i]->getArriveTime())
			queue[0].push(job[i]);
}

// ������ time quantum��ŭ �����ϰ� ���� ���� �ð��� �����ִ� job�� ���� ť�� ���� -> rule 4
void MLFQ::repushProcess(int p) {
	if (running) {
		if (running->getServiceTime() > running->getPerformedTime()) {
			if (p != Q - 1)
				queue[p + 1].push(running);
			else
				queue[p].push(running);
		}
	}
}

// ���μ��� ����
void MLFQ::runProcess(int time, int quantum, int& p) {
	// �켱 ������ ���� ť���� ����, ���� ť�� �ִ� job���� RR ������μ��� -> rule 1 & rule 2
	for (p = 0; p < Q; p++) {
		if (running = queue[p].pop()) {
			// ť���� job�� ������ 1�ʵ��� ����
			for (int q = 0; running && q < quantum; q++) {
				cout << (char)(running->getPid() + 'A') << " ";
				running->addPerformedTime(1); // ����ð� 1�� �߰�
				resultArr[running->getPid()][time + q] = 1;
				runtime++;
				// quantum�� ������ �ʾҴ��� job�� ������ ������ ����
				if (running->getServiceTime() == running->getPerformedTime()) {
					running = NULL;
					break;
				}
			}
			break;
		}
	}
}

// ���μ��� ���� - time slice = 2^i �� ���
void MLFQ::runProcess(int time, int& p) {
	// �켱 ������ ���� ť���� ����, ���� ť�� �ִ� job���� RR ������μ��� -> rule 1 & rule 2
	for (p = 0; p < Q; p++) {
		int quantum = pow(2, p);
		if (running = queue[p].pop()) {
			// ť���� job�� �����ͼ� time slice��ŭ ����
			for (int q = 0; running && q < quantum; q++) {
				cout << (char)(running->getPid() + 'A') << " ";
				running->addPerformedTime(1); // ����ð� 1�� �߰�
				resultArr[running->getPid()][time + q] = 1;
				runtime++;
				// quantum�� ������ �ʾҴ��� job�� ������ ������ ����
				if (running->getServiceTime() == running->getPerformedTime()) {
					running = NULL;
					break;
				}
			}
			break;
		}
	}
}