#include<iostream>
#include<string>
#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"

using std::string;

void Account::create(int id, int money, string name, string password) {
	nID = id;
	nBalance = money;
	strAccountName = name;
	strPassword = password;
}

int Account::check(int id, string password) {
	if (getAcctID() == id && getPassword() == password)
		return nBalance;
	else
		return AUTHENTIFICATION_FAIL;
}

int Account::deposit(int id, int money) {
	if (nID == id) {
		nBalance += money;
		return nBalance;
	}
	else return nBalance;
}

int Account::widraw(int money) {
	if (nBalance < money)
		return 0;
	nBalance -= money;
	return nBalance;
}
