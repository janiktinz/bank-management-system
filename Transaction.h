#include <string>
using namespace std;

#pragma once
class Transaction
{
public:
	Transaction(float, string, string);
	Transaction(float, float, string, string);
	~Transaction();
	void print_transaction();

	string getTime() const;
	float getAmount() const;
	float getCharge() const;
	string getTransactionId() const;

private:
	string time;
	float amount;
	float charge;
	string transaction_id;
};

