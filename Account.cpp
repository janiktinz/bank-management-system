#include "Account.h"
#include "Transaction.h"
using namespace std;

Account::Account()
{
	this->account_balance = 0;
}

Account::~Account()
{
}

int Account::getAccountNumber() const
{
	return this->account_number;
}

float Account::getAccountBalance() const
{
	return this->account_balance;
}

vector<Transaction*> Account::getTransactions() const
{
	return this->transactions;
}

string Account::getAccountType() const
{
	return this->account_type;
}

void Account::takeTransaction(Transaction* newTransaction)
{
	transactions.push_back(newTransaction);
}

