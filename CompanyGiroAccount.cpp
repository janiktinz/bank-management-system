#include "CompanyGiroAccount.h"
#include "TransactionsGenerator.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

CompanyGiroAccount::CompanyGiroAccount(int account_number)
{
	this->account_number = account_number;
	account_type = "company";
}

CompanyGiroAccount::CompanyGiroAccount(int account_number, float account_balance)
{
	this->account_number = account_number;
	this->account_balance = account_balance;
	account_type = "company";
}

CompanyGiroAccount::~CompanyGiroAccount()
{
}

void CompanyGiroAccount::add_transaction(float amount)
{
	Transaction *newTransaction;
	time_t rawtime;
	time(&rawtime);
	string time = ctime(&rawtime);
	time = time.substr(0, 24);

	float charge = amount*0.002;
	if (charge < 0.10)
		charge = 0.10;
	amount = amount - charge;

	account_balance = account_balance + amount;

	string transaction_id = TransactionsGenerator::generateID();

	newTransaction = new Transaction(amount, charge, time, transaction_id);
	takeTransaction(newTransaction);
}

void CompanyGiroAccount::print()
{
	cout << "Giro account: " << account_type << endl;
	cout << "Account number: " << account_number << endl;
	cout << "Account balance: " << account_balance << endl;
}