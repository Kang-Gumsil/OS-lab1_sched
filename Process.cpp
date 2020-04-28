#include "include/Process.h"

int Process::count = 0;	// count 초기화

void Process::resetCount() {
	count = 0;
}

Process::Process(int arrive, int service) {
	pid = count++;
	serviceTime = service;
	arriveTime = arrive;
	performedTime = 0;
	link = NULL; // 해당 큐의 가장 뒤로 넣어줌
}

int Process::getPid() {
	return pid;
}

int Process::getServiceTime() {
	return serviceTime;
}

int Process::getArriveTime() {
	return arriveTime;
}

int Process::getPerformedTime() {
	return performedTime;
}

void Process::addPerformedTime(int time) {
	performedTime += time;
}

void Process::resetPerformedTime() {
	performedTime = 0;
}



