#include <iostream>
#include <cmath>

using namespace std;

#include "BankAccount.h"

int main()
{   
	BankAccount account1;
	account1.deposit(10000);
	account1.withdraw(5000);
	account1.withdraw(1000);
	cout << "Balance: " << account1.getBalance() << endl;
	cout << "Expected: 4000" << endl;
	account1.withdraw(2000);
	cout << "Balance: " << account1.getBalance() << endl;
	cout << "Expected: 1990" << endl;
	account1.deposit(1000);  
	account1.withdraw(500);
	cout << "Balance: " << account1.getBalance() << endl;
	cout << "Expected: 2490" << endl;


	BankAccount account2;
	account2.deposit(16000);
	account2.withdraw(1000);
	account2.withdraw(1000);
	account2.withdraw(1000);
	account2.withdraw(1000);
	cout << "Balance: " << account2.getBalance() << endl;
	cout << "Expected: 11980" << endl;
	account2.deposit(20);
	account2.withdraw(4000);
	cout << "Balance: " << account2.getBalance() << endl;
	cout << "Expected: 8000" << endl;

	return 0;
}