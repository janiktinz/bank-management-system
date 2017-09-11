#include <vector>
#include <string>
#include "Transaction.h"
using namespace std;

#pragma once
class Account
{
	public:
		Account();
		virtual ~Account();
		int getAccountNumber() const;
		float getAccountBalance() const;
		vector<Transaction*> getTransactions() const;
		string getAccountType() const;

		virtual void print() = 0;
		virtual void add_transaction(float) = 0;
		void takeTransaction(Transaction*);

	protected:
		int account_number;
		float account_balance;
		vector<Transaction*> transactions;
		string account_type;
};

