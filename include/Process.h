#ifndef PROCESS_H
#define PROCESS_H
#define NULL 0

class Queue; // friend 선언을 위한 선언
class Process {
	friend Queue; // Queue에서 접근할 수 있도록 friend 선언

private:
	static int count; // 생성된 프로세스의 개수 -> 프로세스의 이름을 정하기 위함
	int serviceTime;
	int arriveTime;
	int performedTime; // 각 프로세스가 수행 된 시간
	int pid;
	Process* link;

public:
	Process(int arrive, int service);
	int getPid();
	int getServiceTime();
	int getArriveTime();
	int getPerformedTime();
	void addPerformedTime(int time);
	void resetCount();
	void resetPerformedTime();	 
};

#endif