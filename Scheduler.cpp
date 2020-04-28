#include "Scheduler.h"
#include <iomanip>

// ������
Scheduler::Scheduler(Process** process) {
	job = process;
	runtime = 0;
	
	int totalTime = 0;
	for (int i = 0; i < 5; i++) 
		totalTime += job[i]->getServiceTime();
	timeSum = totalTime;

	resultArr = new int* [5];	// 5���� job
	for (int i = 0; i < 5; i++) {	// ������ job���� �޾ƿ� �� ���� �ð� ũ���� �迭 ����
		resultArr[i] = new int[timeSum];
		for (int j = 0; j < timeSum; j++)
			resultArr[i][j] = 0;
	}
}

// �����ٸ� ��� ���
void Scheduler::printSchedule() {
	cout << endl <<  "2) Visualization" << endl << endl;
	for (int i = 0; i < 5; i++) {
		cout << " " << (char)('A' + job[i]->getPid()) << " ";
		for (int j = 0; j < timeSum; j++) {
			if (resultArr[i][j] == 0) cout << setw(4) << "��";
			else cout << setw(4) <<  "��";
		}
		cout << endl;
	}
}