#include <iostream>
#include <iomanip>
#include <string>
#include "FIFO.h"
#include "MLFQ.h"
#include "RR.h"

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
			cout << "\n1. FIFO\n1) Execution Result : ";
			scheduler = new FIFO(processPtr);
		}
		else if (i == eRR_1) {
			cout << "\n\n2. RR (time slice=1)\n1) Execution Result : ";
			scheduler = new RR(processPtr, 1);
		}
		else if (i == eRR_4) {
			cout << "\n\n3. RR (time slice=4)\n1) Execution Result : ";
			scheduler = new RR(processPtr, 4);
		}
		else if (i == eMLFQ_1_4) {
			cout << "\n\n4. MLFQ (time slice=1, number of Queue=4)\n1) Execution Result : ";
			scheduler = new MLFQ(processPtr, 1, 999, 4);
		}
		else if (i == eMLFQ_1_3) {
			cout << "\n\n4. MLFQ (time slice=1, number of Queue=3)\n1) Execution Result : ";
			scheduler = new MLFQ(processPtr, 1, 999, 3);
		}
		else if (i == eMLFQ_1_5_4) {
			cout << "\n\n5. MLFQ (time slice=1, S=5, number of Queue=4)\n1) Execution Result : ";
			scheduler = new MLFQ(processPtr, 1, 5, 3);
		}
		else if (i == eMLFQ_2i_4) {
			cout << "\n\n6. MLFQ (time slice=2^i, number of Queue=4)\n1) Execution Result : ";
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
	int processNum[5][2] = { {0, 3}, {2, 6}, {4, 4}, {6, 5}, {8, 2} };

	// ���μ��� ��ü ����
	for (int i = 0; i < 5; i++)
		ptr[i] = new Process(processNum[i][0], processNum[i][1]);

	// ���μ��� ���� ��ȸ
	cout << "************ Process Info ************\n\n";
	cout << setw(3) << "NAME" << setw(15) << "arrive time" << setw(15) << "service time\n";
	for (int i = 0; i < 5; i++) {
		cout << setw(2) << (char)('A' + ptr[i]->getPid()) << setw(10) << ptr[i]->getArriveTime()
			<< setw(15) << ptr[i]->getServiceTime() << endl;
	}
}