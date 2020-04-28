#include "Scheduler.h"
#include <iomanip>

// 생성자
Scheduler::Scheduler(Process** process) {
	job = process;
	runtime = 0;
	
	int totalTime = 0;
	for (int i = 0; i < 5; i++) 
		totalTime += job[i]->getServiceTime();
	timeSum = totalTime;

	resultArr = new int* [5];	// 5개의 job
	for (int i = 0; i < 5; i++) {	// 각각의 job마다 받아온 총 수행 시간 크기의 배열 생성
		resultArr[i] = new int[timeSum];
		for (int j = 0; j < timeSum; j++)
			resultArr[i][j] = 0;
	}
}

// 스케줄링 결과 출력
void Scheduler::printSchedule() {
	cout << endl <<  "2) Visualization" << endl << endl;
	for (int i = 0; i < 5; i++) {
		cout << " " << (char)('A' + job[i]->getPid()) << " ";
		for (int j = 0; j < timeSum; j++) {
			if (resultArr[i][j] == 0) cout << setw(4) << "□";
			else cout << setw(4) <<  "■";
		}
		cout << endl;
	}
}