#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(float amount, string time, string transaction_id)
{
	this->amount = amount;
	this->time = time;
	this->transaction_id = transaction_id;
}

Transaction::Transaction(float amount, float charge, string time, string transaction_id)
{
	this->amount = amount;
	this->time = time;
	this->charge = charge;
	this->transaction_id = transaction_id;
}

Transaction::~Transaction()
{
}

void Transaction::print_transaction()
{
	cout << "TransaktionsID: " << transaction_id << endl;
	cout << "Time: " << time << endl;
	cout << "Amount: " << amount << endl;
}

string Transaction::getTime() const
{
	return this->time;
}

float Transaction::getAmount() const
{
	return this->amount;
}

float Transaction::getCharge() const
{
	return this->charge;
}

string Transaction::getTransactionId() const
{
	return this->transaction_id;
}
