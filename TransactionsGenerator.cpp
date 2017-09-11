#include "TransactionsGenerator.h"
#include "Management.h"
#include "Account.h"
#include <vector>
#include <ctime>
#include <random>
using namespace std;

TransactionsGenerator::TransactionsGenerator()
{
}

TransactionsGenerator::~TransactionsGenerator()
{
}

string TransactionsGenerator::generateID()
{
	srand((unsigned)time(0));
	string key = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	int length = key.length();
	string transaction_id;
	int value;

	for (int i = 0; i < 4; i++)
	{
		value = (rand() % length+1);
		transaction_id.append(key.substr(value, 1));
	}
	while (exists(transaction_id))   
	{
		for (int i = 0; i < 4; i++)
		{
			value = (rand() % length+1);
			transaction_id.append(key.substr(value, 1));
		}
	}
	return transaction_id;
}

bool TransactionsGenerator::exists(string transaction_id)   
{
	Management& management = Management::getInstance();
	for (int i = 0; i < management.getAccounts().size(); i++)
	{
		for (int j = 0; j < management.getAccounts().at(i)->getTransactions().size(); j++)
		{
			if (transaction_id == management.getAccounts().at(i)->getTransactions().at(j)->getTransactionId())
				return true;
		}
	}
	return false;
}
