#include "Account.h"
using namespace std;

#pragma once
class PrivateGiroAccount : public Account
{
public:
	PrivateGiroAccount(int);
	PrivateGiroAccount(int, float);
	~PrivateGiroAccount();
	void add_transaction(float);
	void print();
};

