#include <iomanip>
#include "include/RR.h"

RR::RR(Process** process, int quantum) : Scheduler(process) {
	timeQuantum = quantum;
	queue = new Queue();
}

// 스케줄링 수행
void RR::doSchedule() {
	for (int t = 0; t < timeSum; t++) { // 1초마다 수행

		// 도착한 job을 큐에 넣음
		pushProcess(t);

		// timeout된 job을 큐에 다시 넣어줌
		if (t == runtime) {
			if (running)
				repushProcess();
		}

		// 프로세스 수행
		if (t == runtime) {
			runProcess(t, timeQuantum);
		}
	}

	// 결과 출력
	printSchedule();
}

// 큐에 도착한 job 넣어줌
void RR::pushProcess(int time) {
	for (int i = 0; i < 5; i++) {
		if (time == job[i]->getArriveTime())
			queue->push(job[i]);
	}
}

// 총 실행이 끝나지 않았지만 time quantum이 끝난 job 다시 큐에 넣어줌
void RR::repushProcess() {
	if (running->getServiceTime() > running->getPerformedTime()) {
		queue->push(running);
		running = NULL;
	}
}

// 프로세스 수행
void RR::runProcess(int time, int quantum) {
	running = queue->pop();
	for (int q = 0; running && q < quantum; q++) {
		cout << setw(2) << (char)(running->getPid() + 'A');
		running->addPerformedTime(1); // 수행시간 1초 추가
		resultArr[running->getPid()][runtime] = 1; // 결과 출력 위해 배열에 1저장
		runtime++; // 런타임 증가

		// time quantum이 끝나지 않았지만 job의 수행이 끝나면 종료
		if (running->getServiceTime() == running->getPerformedTime()) {
			running = NULL;
			break;
		}
	}
}
