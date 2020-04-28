#include <iomanip>
#include "include/FIFO.h"

FIFO::FIFO(Process** process) : Scheduler(process) { 
	queue = new Queue();
}

// 스케줄링 수행
void FIFO::doSchedule() {
	for (int t = 0; t < timeSum; t++) {
		// 도착한 job을 큐에 넣음
		pushProcess(t);

		// job 수행
		if (t == runtime)
			runProcess(t);
	}

	// 결과 출력
	printSchedule();
}

// 새로 들어온 job을 큐에 넣어줌
void FIFO::pushProcess(int time) {
	for (int i = 0; i < 5; i++)
		if (time == job[i]->getArriveTime())
			queue->push(job[i]);
}

// 프로세스 수행
void FIFO::runProcess(int time) {

	running = queue->pop();
	for (int t = 0; running; t++) {
		cout << setw(2) << (char)(running->getPid() + 'A');
		running->addPerformedTime(1); // 수행시간 1초 추가
		resultArr[running->getPid()][time + t] = 1; // 결과 출력 위해 배열에 1저장
		runtime++;

		if (running->getServiceTime() == running->getPerformedTime())
			running = NULL;
	}
}
