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

	// FIFO, MLFQ, RR, Stride 객체를 담을 Scheduler 포인터 객체 생성
	Scheduler* scheduler = NULL;

	// 프로세스 생성 및 정보 조회
	Process* processPtr[5];
	setProcess(processPtr);

	// 각 스케줄러의 이름을 숫자로 대응시키기 위해 열거형 선언
	enum cat {
		eFIFO,
		eRR_1,
		eRR_4,
		eMLFQ_1_4,
		eMLFQ_1_3,
		eMLFQ_1_5_4,
		eMLFQ_2i_4,
	};

	// 반복문을 이용해 각각의 스케줄러를 한 번씩 수행
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

		// 스케줄링 수행
		scheduler->doSchedule();
		// 프로세스 객체의 performedTime을 0으로 리셋
		for (int i = 0; i < 5; i++)
			processPtr[i]->resetPerformedTime();
	}
}

void setProcess(Process** ptr) {
	int processNum[5][2] = { {0, 3}, {2, 6}, {4, 4}, {6, 5}, {8, 2} };

	// 프로세스 객체 생성
	for (int i = 0; i < 5; i++)
		ptr[i] = new Process(processNum[i][0], processNum[i][1]);

	// 프로세스 정보 조회
	cout << "************ Process Info ************\n\n";
	cout << setw(3) << "NAME" << setw(15) << "arrive time" << setw(15) << "service time\n";
	for (int i = 0; i < 5; i++) {
		cout << setw(2) << (char)('A' + ptr[i]->getPid()) << setw(10) << ptr[i]->getArriveTime()
			<< setw(15) << ptr[i]->getServiceTime() << endl;
	}
}