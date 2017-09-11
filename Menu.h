#include "Management.h"
using namespace std;

#pragma once
class Menu
{
public:
	Menu();
	~Menu();
	void main_menu();
	void submenu_list();
	void submenu_create();
	void submenu_transaktion();
	void submenu_search();

private:
	Management& management = Management::getInstance();
};

