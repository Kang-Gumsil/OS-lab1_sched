#include "FIFO.h"

FIFO::FIFO(Process** process) : Scheduler(process) { 
	queue = new Queue();
}

// 스케줄링 수행
void FIFO::doSchedule() {

	Process* running = NULL;

	for (int t = 0; t < timeSum; t++) {
		// 도착한 job을 큐에 넣음
		pushProcess(t);

		// job 수행
		if (t == runtime)
			runProcess(t);
	}
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
		cout << (char)(running->getPid() + 'A') << " ";
		running->addPerformedTime(1); // 수행시간 1초 추가
		resultArr[running->getPid()][time + t] = 1;
		runtime++;

		if (running->getServiceTime() == running->getPerformedTime())
			running = NULL;
	}
}
