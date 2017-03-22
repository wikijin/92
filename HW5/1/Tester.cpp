#include <iostream>
#include <cmath>

using namespace std;

#include "BankAccount.h"



BankAccount::BankAccount()
{   
	balance = 0;
}

void BankAccount::deposit(double amount)
{  
	double newBalance = balance + amount;
	balance = newBalance;
}

  

double BankAccount::getBalance()
{   
	return balance;
}


int main()
{   
	BankAccount account1;
	account1.deposit(10000);
	account1.withdraw(5000);
	cout << "Balance: " << account1.getBalance() << endl;
	cout << "Expected: 5000" << endl;
	account1.withdraw(4500);
	cout << "Balance: " << account1.getBalance() << endl;
	cout << "Expected: 490" << endl;


	BankAccount account2;
	account2.deposit(15000);
	account2.withdraw(10000);
	cout << "Balance: " << account2.getBalance() << endl;
	cout << "Expected: 5000" << endl;
	account2.withdraw(4000);
	cout << "Balance: " << account2.getBalance() << endl;
	cout << "Expected: 1000" << endl;

	return 0;
}