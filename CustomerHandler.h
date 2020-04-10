#pragma once

#include <iostream>
#include <iomanip>
#include <map>

#include "Functions.h"

#include "Customer.h"
#include "PerfumeryHandler.h"

#include "CurrentCustomerNotSettedException.h"
#include "EmptyCustomerListException.h"
#include "CustomerNotFoundException.h"
#include "PerfumeryNotFoundException.h"
#include "NotEnoughtMoneyException.h"
#include "EmptyPerfumeryListException.h"
#include "NullArgumentException.h"
#include "InvalidInputException.h"

using namespace std;



class CustomerHandler
{
	static map<unsigned, Customer> customers_;
	static Customer* currentCustomer_;
	static Customer* customerToEdit_;

	static string dataFilename;

	static void editFirstname();
	static void editMiddlename();
	static void editLastname();
	static void editTelephone();
	static void editBalance();

	static void writeInTxt();
	static void readFromTxt();

	static void showEditCustomer();
public:
	enum CustomersMenuAction
	{
		ADD_CUSTOMER = 1,
		DELETE_CUSTOMER,
		EDIT_CUSTOMER,
		SHOW_CUSTOMER,
		FIND_CUSTOMER,
		BACK_TO_MAIN_MENU
	};

	enum CustomerEditMenuAction
	{
		EDIT_FIRSTNAME = 1,
		EDIT_MIDDLENAME,
		EDIT_LASTNAME,
		EDIT_TELEPHONE,
		EDIT_BALANCE,
		BACK_TO_CUSTOMERS_MENU
	};

	CustomerHandler();
	explicit CustomerHandler(const map<unsigned, Customer>& customers);

	static void setCustomers(const map<unsigned, Customer>& customers);
	static void selectCurrentCustomer();
	static void setCurrentCustomerBalance();

	static map<unsigned, Customer>& getCustomers();
	static Customer* getCustomerById(unsigned id);
	static Customer* getCurrentCustomer();
	static unsigned getCustomerId(Customer* customer);

	static void customersMenu();
	static void editMenu();

	static void findByTelephone();

	static void addCustomer();
	static void deleteCustomer();

	static void addPerfumeryToCurrentCustomerBasket();

	static void makeOrder();

	static void showCustomers();
	static void showCurrentCustomer();
	static void showCurrentCustomerBasket();

	~CustomerHandler();
};

