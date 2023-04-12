#include<iostream>
using namespace std;
#include "Account.h"
#include "ATMachine.h"

int main() {
	int select;
	ATMachine atm{ 100, 50000, "admin" };

	while (1) {
		atm.displayMenu();
		cout << "�޴��� �����ϼ���: ";
		cin >> select;
		cout << endl;

		switch (select) {
		case 1:
			atm.createAccount();
			break;
		case 2:
			atm.checkMoney();
			break;
		case 3:
			atm.depositMoney();
			break;
		case 4:
			atm.widrawMoney();
			break;
		case 9:
			atm.closeAccount();
			return 0;
		default:
			cout << "��ȣ Ȯ�� �� �ٽ� �Է��ϼ���." << endl;
		}
	}
}