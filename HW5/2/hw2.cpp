/*
  The First National Bank of Stroustrup provides accounts in which 
  deposits and balance inquiries have no charge, but there is a 
  $10 charge for withdrawals if after the withdrawal the balance
  falls below $1000. Implement the withdraw member function.
*/

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

	