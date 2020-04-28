#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <iostream>
#include "Process.h"
using namespace std;

class Scheduler {
protected:
	int** resultArr;		// 각 초마다 수행 여부 결과 저장하는 배열
	int timeSum;			// 모든 job의 service time 합계
	int runtime;			// 스케줄러 수행시간
	Process* running;		// 수행중인 프로세스
	Process** job;			// Process형 배열의 포인터

public:
	Scheduler(Process** process);   // 생성자
	virtual void doSchedule() = 0;
	void printSchedule();   // 결과 출력
};
#endif