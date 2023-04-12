#include<iostream>
#include<string>
#ifndef ATMACHINE_H
#define ATMACHINE_H
using std::string;

#define NEGATIVE_ATM_BALANCE -10 // ATM �ܾ� ����
class ATMachine {
private:
	Account* pAcctArray[1000]; // ���� ������ ������ �迭 ������
	int nMachineBalance; // ATM �ܰ�
	int nMaxAccountNum; // ���� ������ ������ �迭 ũ��
	int nCurrentAccountNum; // ������ �� ���� ��
	string strManagerPassword; // ������ ��й�ȣ
	int idx = 0;
public:
	ATMachine() {
		nMaxAccountNum = 1000;
	}
	ATMachine(int size, int balance, string password) {
		nCurrentAccountNum = size;
		nMachineBalance = balance;
		strManagerPassword = password;
	} // ���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ
	~ATMachine() { 	}
	void displayMenu(); // ATM ��� ���� ȭ��
	void createAccount(); // ���� ����
	void closeAccount(); // ���� ����
	void checkMoney(); // ���� ��ȸ
	void depositMoney(); // ���� �Ա�
	void widrawMoney(); // ���� ���
};
#endif