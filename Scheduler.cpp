#include <iomanip>
#include "include/Scheduler.h"

// ������
Scheduler::Scheduler(Process** process) {
	job = process;
	running = NULL;
	runtime = 0;
	timeSum = 0;
	
	for (int i = 0; i < 5; i++) 
		timeSum += job[i]->getServiceTime();

	resultArr = new int* [5];	// 5���� job
	for (int i = 0; i < 5; i++) {	// ������ job���� �޾ƿ� �� ���� �ð� ũ���� �迭 ����
		resultArr[i] = new int[timeSum];
		for (int j = 0; j < timeSum; j++)
			resultArr[i][j] = 0;
	}
}

// �����ٸ� ��� ���
void Scheduler::printSchedule() {
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << " " << (char)('A' + job[i]->getPid()) << " ";
		for (int j = 0; j < timeSum; j++) {
			if (resultArr[i][j] == 0) cout << setw(2) << "��";
			else cout << setw(2) << "��";
		}
		cout << endl;
	}
}