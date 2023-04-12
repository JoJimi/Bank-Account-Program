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
	cout << "1. 개좌 개설" << endl;
	cout << "2. 개좌 조회" << endl;
	cout << "3. 계좌 입금" << endl;
	cout << "4. 계좌 출금" << endl;
	cout << "9. 업무 종료" << endl;
}

void ATMachine::createAccount() {
	string name;
	string password;
	srand((unsigned int)time(0));
	int AccNum = BASE_ACCOUNT_ID + (rand() % 901);
	cout << "------ 개설 ------" << endl;
	cout << "이름 입력 : ";
	cin >> name;
	cout << "암호 입력 : ";
	cin >> password;

	if (idx >= 1000) {
		cout << "계좌가 1000개가 넘어가서 더이상 계좌 개설이 불가능합니다." << endl;
		return;
	}
	cout << endl << name << "님 " << AccNum;
	cout << "번 계좌번호가 정상적으로 개설되었읍니다. 감사합니다" << endl;

	Account* account = new Account(AccNum, 0, name, password);
	pAcctArray[idx] = account;
	idx++;

}

void ATMachine::closeAccount() {
	for (int i = 0; i < idx; i++)
		delete pAcctArray[i];
	cout << "안녕히 가세요" << endl;
}

void ATMachine::checkMoney() {
	int id, res = 0;
	string password;
	cout << "------ 조회 ------" << endl;
	cout << "계좌번호 입력 : ";
	cin >> id;
	cout << "비밀번호 입력 : ";
	cin >> password;
	for (int i = 0; i < idx; i++) {
		if (pAcctArray[i]->check(id, password) != AUTHENTIFICATION_FAIL) {
			res = 1;
			cout << "현재 잔액 : " << pAcctArray[i]->check(id, password) << endl;
			return;
		}
	}
	if (res == 0)
		cout << "계좌 인증 실패";
}

void ATMachine::depositMoney() {
	int id, money, res;
	string password;
	cout << "------ 입금 ------" << endl;
	cout << "계좌번호 입력 : ";
	cin >> id;
	cout << "비밀번호 입력 : ";
	cin >> password;
	cout << "입금액 입력 : ";
	cin >> money;

	for (int i = 0; i < idx; i++) {
		if (pAcctArray[i]->getAcctID() == id && pAcctArray[i]->getPassword() == password) {
			res = pAcctArray[i]->deposit(money);
			cout << "현재 잔액 : " << res << endl;
			return;
		}
	}
	cout << "계좌 인증 실패";
}

void ATMachine::widrawMoney() {
	int id, money, res;
	string password;
	cout << "------ 출금 ------" << endl;
	cout << "계좌번호 입력 : ";
	cin >> id;
	cout << "비밀번호 입력 : ";
	cin >> password;
	cout << "출금액 입력 : ";
	cin >> money;
	for (int i = 0; i < idx; i++) {
		if (pAcctArray[i]->getAcctID() == id && pAcctArray[i]->getPassword() == password) {
			res = pAcctArray[i]->widraw(money);
			if (res == 0) {
				cout << "잔액 부족" << endl;
				break;
			}
			cout << "현재 잔액 : " << res << endl;
			return;
		}
	}
	cout << "계좌 인증 실패" << endl;
}