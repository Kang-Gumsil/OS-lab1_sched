#ifndef PROCESS_H
#define PROCESS_H
#define NULL 0

class Queue; // friend ������ ���� ����
class Process {
	friend Queue; // Queue���� ������ �� �ֵ��� friend ����

private:
	static int count; // ������ ���μ����� ���� -> ���μ����� �̸��� ���ϱ� ����
	int serviceTime;
	int arriveTime;
	int performedTime; // �� ���μ����� ���� �� �ð�
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