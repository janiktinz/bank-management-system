#include "Account.h"
#include <vector>
#include <string>
using namespace std;

#pragma once
class Management
{
public:
	~Management();
	void add_account(Account*);
	void list();
	Account* getAccount(int);
	void search_transactionsID(string);
	static Management& getInstance();

	vector<Account*> getAccounts() const;

private:
	Management();
	vector<Account*> accounts;
};

