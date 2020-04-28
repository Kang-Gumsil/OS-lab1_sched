#include <iomanip>
#include "include/Scheduler.h"

// 생성자
Scheduler::Scheduler(Process** process) {
	job = process;
	running = NULL;
	runtime = 0;
	timeSum = 0;
	
	for (int i = 0; i < 5; i++) 
		timeSum += job[i]->getServiceTime();

	resultArr = new int* [5];	// 5개의 job
	for (int i = 0; i < 5; i++) {	// 각각의 job마다 받아온 총 수행 시간 크기의 배열 생성
		resultArr[i] = new int[timeSum];
		for (int j = 0; j < timeSum; j++)
			resultArr[i][j] = 0;
	}
}

// 스케줄링 결과 출력
void Scheduler::printSchedule() {
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << " " << (char)('A' + job[i]->getPid()) << " ";
		for (int j = 0; j < timeSum; j++) {
			if (resultArr[i][j] == 0) cout << setw(2) << "□";
			else cout << setw(2) << "■";
		}
		cout << endl;
	}
}