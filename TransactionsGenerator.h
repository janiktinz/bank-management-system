#include <string>
using namespace std;

#pragma once
class TransactionsGenerator
{
public:
	TransactionsGenerator();
	~TransactionsGenerator();
	static string generateID();

private:
	static bool exists(string);
};

