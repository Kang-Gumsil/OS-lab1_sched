#include <cmath>
#include "MLFQ.h"
#include "Scheduler.h"

// 생성자
MLFQ::MLFQ(Process** process, int quantum, int s, int q) : Scheduler(process) {
	queue = new Queue[q];
	timeQuantum = quantum;
	S = s;
	Q = q;
}

// 스케줄링 수행
void MLFQ::doSchedule() {
	int priority;
	for (int t = 0; t < timeSum; t++) {
		// 새로 들어온 job을 최상위 큐에 넣어줌
		pushProcess(t);

		// 실제 수행시간과 시간의 흐름(t)을 동기화 시켜주기 위함
		if (t == runtime) {

			// job 수행
			if (timeQuantum) 
				runProcess(t, timeQuantum, priority);
			else
				runProcess(t, priority);

			// timeout된 job을 큐에 다시 넣어줌
			if (running)
				repushProcess(priority);
		}

		// 주기마다 부스팅 수행
		if ((t + 1) % S == 0) {
			boosting();
		}
	}
	printSchedule();
}

// S마다 모든 큐를 최상위로 올림 -> rule 5
void MLFQ::boosting() {
	for (int i = 1; i < Q; i++) {
		while (Process* temp = queue[i].pop())
			queue[0].push(temp);
	}
}

// 새로 들어온 job을 최상위 큐에 넣어줌 -> rule 3
void MLFQ::pushProcess(int time) {
	for (int i = 0; i < 5; i++)
		if (time == job[i]->getArriveTime())
			queue[0].push(job[i]);
}

// 직전에 time quantum만큼 수행하고 아직 수행 시간이 남아있는 job을 하위 큐에 넣음 -> rule 4
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

// 프로세스 수행
void MLFQ::runProcess(int time, int quantum, int& p) {
	// 우선 순위가 높은 큐부터 수행, 같은 큐에 있는 job들은 RR 방식으로수행 -> rule 1 & rule 2
	for (p = 0; p < Q; p++) {
		if (running = queue[p].pop()) {
			// 큐에서 job을 가져와 1초동안 수행
			for (int q = 0; running && q < quantum; q++) {
				cout << (char)(running->getPid() + 'A') << " ";
				running->addPerformedTime(1); // 수행시간 1초 추가
				resultArr[running->getPid()][time + q] = 1;
				runtime++;
				// quantum이 끝나지 않았더라도 job의 수행이 끝나면 종료
				if (running->getServiceTime() == running->getPerformedTime()) {
					running = NULL;
					break;
				}
			}
			break;
		}
	}
}

// 프로세스 수행 - time slice = 2^i 인 경우
void MLFQ::runProcess(int time, int& p) {
	// 우선 순위가 높은 큐부터 수행, 같은 큐에 있는 job들은 RR 방식으로수행 -> rule 1 & rule 2
	for (p = 0; p < Q; p++) {
		int quantum = pow(2, p);
		if (running = queue[p].pop()) {
			// 큐에서 job을 가져와서 time slice만큼 수행
			for (int q = 0; running && q < quantum; q++) {
				cout << (char)(running->getPid() + 'A') << " ";
				running->addPerformedTime(1); // 수행시간 1초 추가
				resultArr[running->getPid()][time + q] = 1;
				runtime++;
				// quantum이 끝나지 않았더라도 job의 수행이 끝나면 종료
				if (running->getServiceTime() == running->getPerformedTime()) {
					running = NULL;
					break;
				}
			}
			break;
		}
	}
}