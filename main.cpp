#include <Windows.h>

#include "PerfumeryHandler.h"
#include "CustomerHandler.h"

using namespace std;

void term_func()
{
	cout << "term_func() ���� ������� terminate().";
	exit(-1);
}

void newHandler()
{
	cout << "������� ������� newHandler: ";
	throw bad_alloc();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	set_terminate(term_func);
	set_new_handler(newHandler);

	PerfumeryHandler* perfumeryHandler = nullptr;
	CustomerHandler* customerHandler = nullptr;

	try
	{
		perfumeryHandler = new PerfumeryHandler();
		customerHandler = new CustomerHandler();
	}
	catch (bad_alloc exept)
	{
		cout << exept.what() << endl;
		system("pause");
		exit(-1);
	}

	while (true)
	{
		try
		{
			string choice;
			system("cls");
			cout << "����: " << endl
				<< "1.���� ������ � ���������." << endl
				<< "2.���� ������ � �����������." << endl
				<< "3.������� �������." << endl
				<< "4.�������� ���������� � ������� �������� �������." << endl
				<< "5.�������� ������� �������� �������." << endl
				<< "6.�������� �����" << endl
				<< "7.�����" << endl
				<< "�����: ";
			cin >> choice;

			integerCheck(choice);

			switch (stoul(choice))
			{
			case 1:
				CustomerHandler::customersMenu();
				break;
			case 2:
				PerfumeryHandler::perfumeryMenu();
				break;
			case 3:
				system("cls");
				CustomerHandler::selectCurrentCustomer();
				system("pause");
				break;
			case 4:
				system("cls");
				CustomerHandler::addPerfumeryToCurrentCustomerBasket();
				system("pause");
				break;
			case 5:
				system("cls");
				CustomerHandler::showCurrentCustomerBasket();
				system("pause");
				break;
			case 6:
				system("cls");
				CustomerHandler::makeOrder();
				system("pause");
				break;
			case 7:
				delete perfumeryHandler;
				delete customerHandler;
				return 0;
			default:
				break;
			}
		}
		catch (NullArgumentException & ex)
		{
			system("cls");
			cout << ex.getError() << endl;
			system("pause");
		}
		catch (InvalidInputException & ex)
		{
			system("cls");
			cout << ex.getError() << endl;
			system("pause");
		}
	}
}