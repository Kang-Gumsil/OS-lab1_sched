#include <iostream>
#include <iomanip>
#include <string>
#include "include/FIFO.h"
#include "include/MLFQ.h"
#include "include/RR.h"

#define NULL 0
using namespace std;

void setProcess(Process** ptr);
int main() {

	// FIFO, MLFQ, RR, Stride ��ü�� ���� Scheduler ������ ��ü ����
	Scheduler* scheduler = NULL;

	// ���μ��� ���� �� ���� ��ȸ
	Process* processPtr[5];
	setProcess(processPtr);

	// �� �����ٷ��� �̸��� ���ڷ� ������Ű�� ���� ������ ����
	enum cat {
		eFIFO,
		eRR_1,
		eRR_4,
		eMLFQ_1_4,
		eMLFQ_1_3,
		eMLFQ_1_5_4,
		eMLFQ_2i_4,
	};

	// �ݺ����� �̿��� ������ �����ٷ��� �� ���� ����
	for (int i = 0; i < 7; i++) {
		if (i == eFIFO) {
			cout << "\n\n 1. FIFO\n\n  ";
			scheduler = new FIFO(processPtr);
		}
		else if (i == eRR_1) {
			cout << "\n\n\n 2. RR (time slice=1)\n\n  ";
			scheduler = new RR(processPtr, 1);
		}
		else if (i == eRR_4) {
			cout << "\n\n\n 3. RR (time slice=4)\n\n  ";
			scheduler = new RR(processPtr, 4);
		}
		else if (i == eMLFQ_1_4) {
			cout << "\n\n\n 4. MLFQ (time slice=1, number of Queue=4)\n\n  ";
			scheduler = new MLFQ(processPtr, 1, 999, 4);
		}
		else if (i == eMLFQ_1_3) {
			cout << "\n\n\n 5. MLFQ (time slice=1, number of Queue=3)\n\n  ";
			scheduler = new MLFQ(processPtr, 1, 999, 3);
		}
		else if (i == eMLFQ_1_5_4) {
			cout << "\n\n\n 6. MLFQ (time slice=1, S=5, number of Queue=4)\n\n  ";
			scheduler = new MLFQ(processPtr, 1, 5, 3);
		}
		else if (i == eMLFQ_2i_4) {
			cout << "\n\n\n 7. MLFQ (time slice=2^i, number of Queue=4)\n\n  ";
			scheduler = new MLFQ(processPtr, NULL, 999, 3);
		}

		// �����ٸ� ����
		scheduler->doSchedule();
		// ���μ��� ��ü�� performedTime�� 0���� ����
		for (int i = 0; i < 5; i++)
			processPtr[i]->resetPerformedTime();
	}
}

void setProcess(Process** ptr) {

	// ���μ��� ��ü ����
	int processNum[5][2] = { {0, 3}, {2, 6}, {4, 4}, {6, 5}, {8, 2} };
	for (int i = 0; i < 5; i++)
		ptr[i] = new Process(processNum[i][0], processNum[i][1]);

	// ���μ��� ���� ��ȸ
	cout << " ************ Process Info ************\n\n";
	cout << " " << setw(3) << "NAME" << setw(15) << "arrive time" << setw(15) << "service time\n";
	for (int i = 0; i < 5; i++) {
		cout << " " << setw(2) << (char)('A' + ptr[i]->getPid()) << setw(12) << ptr[i]->getArriveTime()
			 << setw(13) << ptr[i]->getServiceTime() << endl;
	}
}