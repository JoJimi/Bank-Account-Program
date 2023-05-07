#include<iostream>
using namespace std;
#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"

int Statistics::sum(Account* pArray, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) 
		sum += pArray[i].getBalance();
	return sum;
}
int Statistics::average(Account* pArray, int size) {
	int avg = 0;
	for (int i = 0; i < size; i++)
		avg += pArray[i].getBalance();
	return avg / size;
}
int Statistics::max(Account* pArray, int size) {
	int maxNum = 0;
	for (int i = 0; i < size; i++) {
		if (maxNum < pArray[i].getBalance()) 
			maxNum = pArray[i].getBalance();
	}
	return maxNum;
}
void Statistics::sort(Account* pArray, int size) {
	Account p;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (pArray[i].getBalance() < pArray[j].getBalance()) {
				p = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = p;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " 
			<< pArray[i].getAccountName() << "\t"
			<< pArray[i].getAcctID() << "\t" 
			<< pArray[i].getBalance()
			<< "¿ø" << endl;
	}
	cout << endl;
}