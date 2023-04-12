#include<iostream>
#include<ctime>
#include<cstdlib>
#include "Account.h"
#include "ATMachine.h"

using namespace std;
Account acc;
void ATMachine::displayMenu() {
	cout << "----------------------" << endl;
	cout << "-    TUKOREA BANK    -" << endl;
	cout << "----------------------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ��ȸ" << endl;
	cout << "3. ���� �Ա�" << endl;
	cout << "4. ���� ���" << endl;
	cout << "9. ���� ����" << endl;
}

void ATMachine::createAccount() {
	string name;
	string password;
	srand((unsigned int)time(0));
	int AccNum = BASE_ACCOUNT_ID + (rand() % 901);
	cout << "------ ���� ------" << endl;
	cout << "�̸� �Է� : ";
	cin >> name;
	cout << "��ȣ �Է� : ";
	cin >> password;

	if (idx >= 1000) {
		cout << "���°� 1000���� �Ѿ�� ���̻� ���� ������ �Ұ����մϴ�." << endl;
		return;
	}
	cout << endl << name << "�� " << AccNum;
	cout << "�� ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�" << endl;

	Account* account = new Account(AccNum, 0, name, password);
	pAcctArray[idx] = account;
	idx++;

}

void ATMachine::closeAccount() {
	for (int i = 0; i < idx; i++)
		delete pAcctArray[i];
	cout << "�ȳ��� ������" << endl;
}

void ATMachine::checkMoney() {
	int id, res = 0;
	string password;
	cout << "------ ��ȸ ------" << endl;
	cout << "���¹�ȣ �Է� : ";
	cin >> id;
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	for (int i = 0; i < idx; i++) {
		if (pAcctArray[i]->check(id, password) != AUTHENTIFICATION_FAIL) {
			res = 1;
			cout << "���� �ܾ� : " << pAcctArray[i]->check(id, password) << endl;
			return;
		}
	}
	if (res == 0)
		cout << "���� ���� ����";
}

void ATMachine::depositMoney() {
	int id, money, res;
	string password;
	cout << "------ �Ա� ------" << endl;
	cout << "���¹�ȣ �Է� : ";
	cin >> id;
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	cout << "�Աݾ� �Է� : ";
	cin >> money;

	for (int i = 0; i < idx; i++) {
		if (pAcctArray[i]->getAcctID() == id && pAcctArray[i]->getPassword() == password) {
			res = pAcctArray[i]->deposit(money);
			cout << "���� �ܾ� : " << res << endl;
			return;
		}
	}
	cout << "���� ���� ����";
}

void ATMachine::widrawMoney() {
	int id, money, res;
	string password;
	cout << "------ ��� ------" << endl;
	cout << "���¹�ȣ �Է� : ";
	cin >> id;
	cout << "��й�ȣ �Է� : ";
	cin >> password;
	cout << "��ݾ� �Է� : ";
	cin >> money;
	for (int i = 0; i < idx; i++) {
		if (pAcctArray[i]->getAcctID() == id && pAcctArray[i]->getPassword() == password) {
			res = pAcctArray[i]->widraw(money);
			if (res == 0) {
				cout << "�ܾ� ����" << endl;
				break;
			}
			cout << "���� �ܾ� : " << res << endl;
			return;
		}
	}
	cout << "���� ���� ����" << endl;
}