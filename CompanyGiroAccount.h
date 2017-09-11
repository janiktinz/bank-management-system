#include "Account.h"
using namespace std;

#pragma once
class CompanyGiroAccount : public Account
{
public:
	CompanyGiroAccount(int);
	CompanyGiroAccount(int, float);
	~CompanyGiroAccount();
	void add_transaction(float);
	void print();
};

