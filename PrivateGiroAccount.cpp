#include "PrivateGiroAccount.h"
#include "TransactionsGenerator.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

PrivateGiroAccount::PrivateGiroAccount(int account_number)
{
	this->account_number = account_number;
	account_type = "private";
}

PrivateGiroAccount::PrivateGiroAccount(int account_number, float account_balance)
{
	this->account_number = account_number;
	this->account_balance = account_balance;
	account_type = "private";
}

PrivateGiroAccount::~PrivateGiroAccount()
{
}

void PrivateGiroAccount::add_transaction(float amount)
{
	Transaction *newTransaction;
	time_t rawtime;
	time(&rawtime);
	string time = ctime(&rawtime);
	time = time.substr(0, 24);
	account_balance = account_balance + amount;

	string transaction_id = TransactionsGenerator::generateID();

	newTransaction = new Transaction(amount, time, transaction_id);
	takeTransaction(newTransaction);
}

void PrivateGiroAccount::print()
{
	cout << "Giro account: " << account_type << endl;
	cout << "Account number: " << account_number << endl;
	cout << "Account balance: " << account_balance << endl;
}