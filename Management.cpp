#include "Management.h"
#include "PrivateGiroAccount.h"
#include "CompanyGiroAccount.h"
#include "Transaction.h"
#include <fstream>
#include <iostream>
using namespace std;

Management::Management()
{
	ifstream accountRead;
	accountRead.open("accounts.txt", ios::in);
	
	if (accountRead)
	{
		while (!accountRead.eof())
		{
			string value, account_type;
			int account_number;
			float account_balance;

			getline(accountRead, value, ';');
			account_type = value;

			getline(accountRead, value, ';');
			account_number = stoi(value);

			getline(accountRead, value, '\n');
			account_balance = stof(value);

			if (account_type == "private")
				accounts.push_back(new PrivateGiroAccount(account_number, account_balance));
			if (account_type == "company")
				accounts.push_back(new CompanyGiroAccount(account_number, account_balance));
			if (accountRead.peek() == '\n')
				break;
		}
	}
	else
                cout << "Reading (accounts.txt) is not possible! " << endl;
	accountRead.close();

	ifstream transactionRead;
	transactionRead.open("transactions.txt", ios::in);

	if (transactionRead)
	{
		while (!transactionRead.eof())
		{
			string value, time, transaktion_id;
			int account_number;
			float amount, charge;

			getline(transactionRead, value, ';');
			account_number = stoi(value);

			getline(transactionRead, value, ';');
			transaktion_id = value;

			getline(transactionRead, value, ';');
				amount = stof(value);

			Account *konto = getAccount(account_number);
			if (konto->getAccountType() == "company")
			{
				getline(transactionRead, value, ';');
				charge = stof(value);
			}

			getline(transactionRead, value, '\n');
				time = value;
				
			Transaction *transaction;
			if(konto->getAccountType() == "company")
				transaction = new Transaction(amount, charge, time, transaktion_id);
			else
				transaction = new Transaction(amount, time, transaktion_id);
			
			konto->takeTransaction(transaction);
			if (transactionRead.peek() == '\n')
				break;
		}
	}
	else
		cout << "Reading (transactions.txt) is not possible! " << endl;
	transactionRead.close();
}

Management::~Management()
{
	ofstream accountWrite;
	accountWrite.open("accounts.txt", ios::out);

	for (unsigned int i = 0; i < accounts.size(); i++)
	{
		accountWrite << accounts[i]->getAccountType() << ";"; 
		accountWrite << accounts[i]->getAccountNumber() << ";"; 
		accountWrite << accounts[i]->getAccountBalance() << '\n';
	}
	accountWrite.close();

	ofstream transactionWrite;
	transactionWrite.open("transactions.txt", ios::out);

	for (unsigned int i = 0; i < accounts.size(); i++)
	{	
		for (unsigned int j = 0; j < accounts[i]->getTransactions().size(); j++)
		{
			transactionWrite << accounts[i]->getAccountNumber() << ";";
			transactionWrite << accounts[i]->getTransactions()[j]->getTransactionId() << ";";
			transactionWrite << accounts[i]->getTransactions()[j]->getAmount() << ";"; 
			if (accounts[i]->getAccountType() == "company")
				transactionWrite << accounts[i]->getTransactions()[j]->getCharge() << ";";

			transactionWrite << accounts[i]->getTransactions()[j]->getTime() << '\n';
			delete accounts[i]->getTransactions()[j];
		}
		delete accounts[i];
	}
	transactionWrite.close();
}

void Management::add_account(Account* newAccount)
{
	accounts.push_back(newAccount);
}

void Management::list()
{
	for (int i = 0; i < accounts.size(); i++)
        {
		accounts.at(i)->print();
                cout << endl;
        }
}

Account* Management::getAccount(int account_number)
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getAccountNumber() == account_number)
			return accounts[i];
	}
	return NULL;
}

void Management::search_transactionsID(string transaction_id)
{
	int counter = 0;
	for (int i = 0; i < accounts.size(); i++)
	{
		for (int j = 0; j < accounts[i]->getTransactions().size(); j++)
		{
			if (accounts[i]->getTransactions()[j]->getTransactionId() == transaction_id)
			{
				cout << "Account number (" << accounts[i]->getAccountType() << "): " << accounts[i]->getAccountNumber() << endl;
				accounts[i]->getTransactions()[j]->print_transaction();
				if (accounts[i]->getAccountType() == "company")
					cout << "Charge: " << accounts[i]->getTransactions()[j]->getCharge() << endl;
				counter++;
			}
		}
	}
	if (counter == 0)
		cout << "- TransactionsID does not exist! -" << endl;
}

vector<Account*> Management::getAccounts() const
{
	return this->accounts;
}

Management& Management::getInstance()
{
	static Management instance;
	return instance;
}