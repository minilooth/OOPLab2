#include "CustomerHandler.h"

map<unsigned, Customer> CustomerHandler::customers_;
Customer* CustomerHandler::currentCustomer_ = nullptr;
Customer* CustomerHandler::customerToEdit_ = nullptr;
string CustomerHandler::dataFilename = "customers_data.txt";

void CustomerHandler::editFirstname()
{
	try
	{
		if (customerToEdit_ == nullptr)
		{
			throw CustomerNotFoundException();
		}

		showEditCustomer();

		string firstname;
		cout << "������� ����� ���: ";
		cin >> firstname;
		alphabetCheck(firstname);

		customerToEdit_->setFirstname(firstname);
		writeInTxt();

		system("cls");
		showEditCustomer();
		cout << "��� ������� ��������!" << endl;
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::editMiddlename()
{
	try
	{
		if (customerToEdit_ == nullptr)
		{
			throw CustomerNotFoundException();
		}

		showEditCustomer();

		string middlename;
		cout << "������� ����� �������: ";
		cin >> middlename;
		alphabetCheck(middlename);

		customerToEdit_->setMiddlename(middlename);
		writeInTxt();

		system("cls");
		showEditCustomer();
		cout << "������� ������� ��������!" << endl;
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::editLastname()
{
	try
	{
		if (customerToEdit_ == nullptr)
		{
			throw CustomerNotFoundException();
		}

		showEditCustomer();

		string lastname;
		cout << "������� ����� ��������: ";
		cin >> lastname;
		alphabetCheck(lastname);

		customerToEdit_->setLastname(lastname);
		writeInTxt();

		system("cls");
		showEditCustomer();
		cout << "������� ������� ��������!" << endl;
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::editTelephone()
{
	try
	{
		if (customerToEdit_ == nullptr)
		{
			throw CustomerNotFoundException();
		}

		showEditCustomer();

		string telephone;
		cout << "������� ����� �������: ";
		cin >> telephone;
		telephoneCheck(telephone);

		customerToEdit_->setTelephone(telephone);
		writeInTxt();

		system("cls");
		showEditCustomer();
		cout << "������� ������� �������!" << endl;
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::editBalance()
{
	try
	{
		if (customerToEdit_ == nullptr)
		{
			throw CustomerNotFoundException();
		}

		showEditCustomer();

		string balance;
		cout << "������� ����� ������: ";
		cin >> balance;
		doubleCheck(balance);

		customerToEdit_->setBalance(stod(balance));
		writeInTxt();

		system("cls");
		showEditCustomer();
		cout << "������ ������� �������!" << endl;
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::writeInTxt()
{
	ofstream customersData;
	customersData.open(dataFilename, ios::trunc);

	if (customersData.is_open())
	{
		for (auto it = customers_.begin(); it != customers_.end(); it++)
		{
			customersData << it->second.getFirstname() << ";"
				<< it->second.getMiddlename() << ";"
				<< it->second.getLastname() << ";"
				<< it->second.getTelephone() << ";"
				<< it->second.getBalance() << endl;
		}
		customersData.close();
	}
}

void CustomerHandler::readFromTxt()
{
	string token;

	string firstname;
	string middlename;
	string lastname;
	string telephone;
	string balance;

	ifstream customersData;

	customersData.open(dataFilename);

	if (customersData.is_open())
	{
		while (!customersData.eof())
		{
			if (getline(customersData, token, '\n'))
			{
				auto data = stringSplitter(token);

				firstname = data.at(0);
				middlename = data.at(1);
				lastname = data.at(2);
				telephone = data.at(3);
				balance = data.at(4);

				customers_.insert(pair<unsigned, Customer>(customers_.empty() ? 1 : (customers_.rbegin()->first + 1), Customer(firstname, middlename, lastname, telephone, stod(balance))));
			}
		}
		customersData.close();
	}
}

void CustomerHandler::showEditCustomer()
{
	cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;
	cout << "|  ��  |     ���     |   �������   |  ��������  |   �������   |   ������   |" << endl;
	cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;

	cout << setw(6) << left << "|" << getCustomerId(customerToEdit_);
	cout << *customerToEdit_ << endl;

	cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;
}

CustomerHandler::CustomerHandler()
{
	readFromTxt();
	currentCustomer_ = nullptr;
	customerToEdit_ = nullptr;
}

CustomerHandler::CustomerHandler(const map<unsigned, Customer> & customers)
{
	customers_ = customers;
	currentCustomer_ = nullptr;
	customerToEdit_ = nullptr;
}

void CustomerHandler::setCustomers(const map<unsigned, Customer>& customers)
{
	customers_ = customers;
}

void CustomerHandler::selectCurrentCustomer()
{
	try
	{
		if (customers_.empty())
		{
			throw EmptyCustomerListException();
		}

		showCustomers();

		string id;
		cout << "������� ��: ";
		cin >> id;
		integerCheck(id);

		currentCustomer_ = getCustomerById(stoul(id));

		if (currentCustomer_ == nullptr)
		{
			throw CustomerNotFoundException();
		}

		system("cls");
		cout << "������� ������ ������� ����������!" << endl;
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (EmptyCustomerListException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::setCurrentCustomerBalance()
{
	try
	{
		if (currentCustomer_ == nullptr)
		{
			throw CurrentCustomerNotSettedException();
		}

		string balance;
		cout << "������� ����� ������: ";
		cin >> balance;
		doubleCheck(balance);

		currentCustomer_->setBalance(stod(balance));

		system("cls");
		cout << "������ ��� �������� ������� ������� ����������!" << endl;
	}
	catch (CurrentCustomerNotSettedException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

map<unsigned, Customer>& CustomerHandler::getCustomers()
{
	return customers_;
}

Customer* CustomerHandler::getCustomerById(unsigned id)
{
	return &(customers_.find(id)->second);
}

Customer* CustomerHandler::getCurrentCustomer()
{
	return currentCustomer_;
}

unsigned CustomerHandler::getCustomerId(Customer* customer)
{
	if (customer == nullptr)
	{
		throw CustomerNotFoundException();
	}

	unsigned id = 0;

	for (auto it = customers_.begin(); it != customers_.end(); it++)
	{
		if (&(it->second) == customer)
		{
			id = it->first;
			break;
		}
	}
	return id;
}

void CustomerHandler::customersMenu()
{
	while (true)
	{
		try
		{
			system("cls");

			string choice;
			cout << "���� ������ � ���������:" << endl;
			cout << "1.�������� �������." << endl;
			cout << "2.������� �������." << endl;
			cout << "3.������������� �������." << endl;
			cout << "4.�������� ���� ��������." << endl;
			cout << "5.����� ������� �� ������ ��������." << endl;
			cout << "6.�����." << endl;
			cout << "��� �����: ";
			cin >> choice;
			integerCheck(choice);

			switch (stoul(choice))
			{
			case CustomersMenuAction::ADD_CUSTOMER :
				system("cls");
				addCustomer();
				system("pause");
				break;
			case CustomersMenuAction::DELETE_CUSTOMER :
				system("cls");
				deleteCustomer();
				system("pause");
				break;
			case CustomersMenuAction::EDIT_CUSTOMER :
				system("cls");
				editMenu();
				break;
			case CustomersMenuAction::SHOW_CUSTOMER :
				system("cls");
				showCustomers();
				system("pause");
				break;
			case CustomersMenuAction::FIND_CUSTOMER :
				system("cls");
				findByTelephone();
				system("pause");
				break;
			case CustomersMenuAction::BACK_TO_MAIN_MENU :
				return;
			default:
				break;
			}
		}
		catch (NullArgumentException & ex)
		{
			system("cls");
			cout << ex.getError() << endl;
		}
		catch (InvalidInputException & ex)
		{
			system("cls");
			cout << ex.getError() << endl;
		}
	}
}

void CustomerHandler::editMenu()
{
	try
	{
		if (customers_.empty())
		{
			throw EmptyCustomerListException();
		}

		showCustomers();

		string id;
		cout << "������� ��: ";
		cin >> id;
		integerCheck(id);

		customerToEdit_ = getCustomerById(stoul(id));

		if (customerToEdit_ == nullptr)
		{
			throw CustomerNotFoundException();
		}

		while (true)
		{
			try
			{
				system("cls");

				showEditCustomer();

				string choice;
				cout << "���� �������������� �������:" << endl;
				cout << "1.�������� ���." << endl;
				cout << "2.�������� �������." << endl;
				cout << "3.�������� ��������." << endl;
				cout << "4.�������� �������." << endl;
				cout << "5.�������� ������." << endl;
				cout << "6.�����." << endl;
				cout << "��� �����: ";
				cin >> choice;
				integerCheck(choice);

				switch (stoul(choice))
				{
				case CustomerEditMenuAction::EDIT_FIRSTNAME :
					system("cls");
					editFirstname();
					system("pause");
					break;
				case CustomerEditMenuAction::EDIT_MIDDLENAME :
					system("cls");
					editMiddlename();
					system("pause");
					break;
				case CustomerEditMenuAction::EDIT_LASTNAME :
					system("cls");
					editLastname();
					system("pause");
					break;
				case CustomerEditMenuAction::EDIT_TELEPHONE :
					system("cls");
					editTelephone();
					system("pause");
					break;
				case CustomerEditMenuAction::EDIT_BALANCE :
					system("cls");
					editBalance();
					system("pause");
					break;
				case CustomerEditMenuAction::BACK_TO_CUSTOMERS_MENU :
					customerToEdit_ = nullptr;
					return;
				default:
					break;
				}
			}
			catch (NullArgumentException & ex)
			{
				system("cls");
				cout << ex.getError() << endl;
			}
			catch (InvalidInputException & ex)
			{
				system("cls");
				cout << ex.getError() << endl;
			}
		}
	}
	catch (EmptyCustomerListException& ex)
	{
		system("cls");
		cout << ex.getError() << endl;
		system("pause");
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
		system("pause");
	}
}

void CustomerHandler::findByTelephone()
{
	try
	{
		if (customers_.empty())
		{
			throw EmptyCustomerListException();
		}

		string telephone;
		cout << "������� ����� ��������: ";
		cin >> telephone;
		telephoneCheck(telephone);

		map<unsigned, Customer> found;
		for (auto it = customers_.begin(); it != customers_.end(); it++)
		{
			if (it->second.getTelephone() == telephone)
			{
				found.insert(pair<unsigned, Customer>(it->first, it->second));
			}
		}

		if (found.empty())
		{
			throw CustomerNotFoundException();
		}

		system("cls");

		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;
		cout << "|  ��  |     ���     |   �������   |  ��������  |   �������   |   ������   |" << endl;
		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;

		for (auto it = found.begin(); it != found.end(); it++)
		{
			cout << setw(6) << left << "|" << it->first;
			cout << it->second << endl;
		}

		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;
	}
	catch (EmptyCustomerListException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::addCustomer()
{
	try
	{
		string firstname;
		cout << "������� ��� �������: ";
		cin >> firstname;
		alphabetCheck(firstname);

		string middlename;
		cout << "������� ������� �������: ";
		cin >> middlename;
		alphabetCheck(middlename);

		string lastname;
		cout << "������� �������� �������: ";
		cin >> lastname;
		alphabetCheck(lastname);

		string telephone;
		cout << "������� ������� �������: ";
		cin >> telephone;
		telephoneCheck(telephone);

		string balance;
		cout << "������� ������ �������: ";
		cin >> balance;
		doubleCheck(balance);

		unsigned int id = customers_.empty() ? 1 : (customers_.rbegin()->first + 1);

		customers_.insert(pair<unsigned, Customer>(id, Customer(firstname, middlename, lastname, telephone, stod(balance))));

		customers_.at(id).writeInFile(dataFilename);

		system("cls");
		cout << "������ ������� ��������!" << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::deleteCustomer()
{
	try
	{
		if (customers_.empty())
		{
			throw EmptyCustomerListException();
		}

		showCustomers();

		string id;
		cout << "������� �� �������: ";
		cin >> id;
		integerCheck(id);

		customers_.erase(stoul(id));
		writeInTxt();

		system("cls");
		cout << "������ ������� ������!" << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (CustomerNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (EmptyCustomerListException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::addPerfumeryToCurrentCustomerBasket()
{
	try
	{
		if (currentCustomer_ == nullptr)
		{
			throw CurrentCustomerNotSettedException();
		}
		if (PerfumeryHandler::getPerfumes().empty())
		{
			throw EmptyPerfumeryListException();
		}

		PerfumeryHandler::showPerfumes();

		string id;
		cout << "������� ��: ";
		cin >> id;
		integerCheck(id);

		if (stoul(id) > PerfumeryHandler::getPerfumes().size())
		{
			throw PerfumeryNotFoundException();
		}
		if (next(PerfumeryHandler::getPerfumes().begin(), stoul(id))->getPrice() > currentCustomer_->getBalance())
		{
			throw NotEnoughtMoneyException();
		}

		currentCustomer_->getBasket().getPerfumes().push_back(*(next(PerfumeryHandler::getPerfumes().begin(), stoul(id))));
		currentCustomer_->setBalance(currentCustomer_->getBalance() - currentCustomer_->getBasket().getPerfumes().back().getPrice());

		system("cls");
		cout << "������ ������� �������� � �������!" << endl;
	}
	catch (CurrentCustomerNotSettedException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (PerfumeryNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NotEnoughtMoneyException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (EmptyPerfumeryListException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (NullArgumentException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::makeOrder()
{
	try
	{
		if (currentCustomer_ == nullptr)
		{
			throw CurrentCustomerNotSettedException();
		}

		customers_.erase(getCustomerId(currentCustomer_));
		writeInTxt();
		currentCustomer_ = nullptr;

		cout << "����� ������� ��������!" << endl;
	}
	catch (CurrentCustomerNotSettedException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::showCustomers()
{
	try
	{
		if (customers_.empty())
		{
			throw EmptyCustomerListException();
		}

		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;
		cout << "|  ��  |     ���     |   �������   |  ��������  |   �������   |   ������   |" << endl;
		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;


		for (auto it = customers_.begin(); it != customers_.end(); it++)
		{
			cout << setw(6) << left << "|" << it->first;
			cout << it->second << endl;
		}

		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;
	}
	catch (EmptyCustomerListException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::showCurrentCustomer()
{
	try
	{
		if (currentCustomer_ == nullptr)
		{
			throw CurrentCustomerNotSettedException();
		}

		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;
		cout << "|  ��  |     ���     |   �������   |  ��������  |   �������   |   ������   |" << endl;
		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;

		cout << setw(6) << left << "|" << getCustomerId(currentCustomer_);
		cout << *currentCustomer_ << endl;
		
		cout << "+------+-------------+-------------+------------+-------------+------------+" << endl;
	}
	catch (CurrentCustomerNotSettedException & ex)
	{
		cout << ex.getError() << endl;
	}
}

void CustomerHandler::showCurrentCustomerBasket()
{
	try
	{
		if (currentCustomer_ == nullptr)
		{
			throw CurrentCustomerNotSettedException();
		}
		if (currentCustomer_->getBasket().getPerfumes().empty())
		{
			throw EmptyBasketException();
		}

		cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;
		cout << "|       �����      |     ���     |      ������     |   ������ ��������   |   �������������  |   ����   |" << endl;
		cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;

		cout << currentCustomer_->getBasket();

		cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;
	}
	catch (CurrentCustomerNotSettedException & ex)
	{
		cout << ex.getError() << endl;
	}
	catch (EmptyBasketException & ex)
	{
		cout << ex.getError() << endl;
	}
}

CustomerHandler::~CustomerHandler()
{
	currentCustomer_ = nullptr;
	customerToEdit_ = nullptr;
}

