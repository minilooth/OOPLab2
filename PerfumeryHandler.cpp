#include "PerfumeryHandler.h"

list<Perfumery> PerfumeryHandler::perfumes_;
Perfumery* PerfumeryHandler::perfumeryToEdit_ = nullptr;
string PerfumeryHandler::dataFilename = "perfumery_data.txt";

void PerfumeryHandler::editBrand()
{
	try
	{
		showEditPerfume();

		string brand;
		cout << "������� ����� �����: ";
		cin >> brand;
		alphabetCheck(brand);

		perfumeryToEdit_->setBrand(brand);
		writeInTxt();

		system("cls");
		showEditPerfume();
		cout << "����� ������� �������!" << endl;
	}
	catch (PerfumeryToEditNotSettedException& ex)
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

void PerfumeryHandler::editFlavor()
{
	try
	{
		showEditPerfume();

		string flavor;
		cout << "������� ����� ������: ";
		cin >> flavor;
		alphabetCheck(flavor);

		perfumeryToEdit_->setFlavor(flavor);
		writeInTxt();

		system("cls");
		showEditPerfume();
		cout << "������ ������� �������!" << endl;
	}
	catch (PerfumeryToEditNotSettedException & ex)
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

void PerfumeryHandler::editAromaGroup()
{
	try
	{
		showEditPerfume();

		string aromaGroup;
		cout << "������� ����� ������ ��������: ";
		cin >> aromaGroup;
		alphabetCheck(aromaGroup);

		perfumeryToEdit_->setAromaGroup(aromaGroup);
		writeInTxt();

		system("cls");
		showEditPerfume();
		cout << "������ �������� ������� ��������!" << endl;
	}
	catch (PerfumeryToEditNotSettedException & ex)
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

void PerfumeryHandler::editManufacturer()
{
	try
	{
		showEditPerfume();

		string manufacturer;
		cout << "������� ����� ������-������������: ";
		cin >> manufacturer;
		alphabetCheck(manufacturer);

		perfumeryToEdit_->setManufacturer(manufacturer);
		writeInTxt();

		system("cls");
		showEditPerfume();
		cout << "������-������������ ������� ��������!" << endl;
	}
	catch (PerfumeryToEditNotSettedException & ex)
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

void PerfumeryHandler::editType()
{
	try
	{
		while (true)
		{
			try
			{

				system("cls");
				
				showEditPerfume();

				string choice;
				cout << "�������� ����� ���:" << endl;
				cout << "1.�������." << endl;
				cout << "2.�������." << endl;
				cout << "3.�����." << endl;
				cout << "��� �����: ";
				cin >> choice;
				integerCheck(choice);

				switch (stoul(choice))
				{
				case 1:
					perfumeryToEdit_ = new MensPerfumes(*perfumeryToEdit_);

					system("cls");
					showEditPerfume();
					cout << "��� ������� �������!" << endl;
					return;
				case 2:
					perfumeryToEdit_ = new WomenPerfumes(*perfumeryToEdit_);

					system("cls");
					showEditPerfume();
					cout << "��� ������� �������!" << endl;
					return;
				case 3:
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
	catch (PerfumeryToEditNotSettedException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void PerfumeryHandler::editPrice()
{
	try
	{
		showEditPerfume();

		string price;
		cout << "������� ����� ����: ";
		cin >> price;
		doubleCheck(price);

		perfumeryToEdit_->setPrice(stod(price));
		writeInTxt();

		system("cls");
		showEditPerfume();
		cout << "���� ������� ��������!" << endl;
	}
	catch (PerfumeryToEditNotSettedException & ex)
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

void PerfumeryHandler::writeInTxt()
{
	ofstream perfumeryData;
	perfumeryData.open(dataFilename, ios::trunc);

	if (!perfumeryData)
	{
		cerr << "���������� ������� ���� " << dataFilename << " !\n";
		exit(1);
	}

	if (perfumeryData.is_open())
	{
		for (auto it = perfumes_.begin(); it != perfumes_.end(); it++)
		{
			perfumeryData << it->getBrand() << ";"
				<< it->getFlavor() << ";"
				<< it->getAromaGroup() << ";"
				<< it->getManufacturer() << ";"
				<< it->getType() << ";"
				<< it->getPrice() << endl;
		}
		perfumeryData.close();
	}
}

void PerfumeryHandler::readFromTxt()
{
	string token;

	string brand;
	string flavor;
	string aromaGroup;
	string manufacturer;
	string type;
	string price;

	ifstream perfumeryData;

	perfumeryData.open(dataFilename);

	if (!perfumeryData)
	{
		cerr << "���������� ������� ���� " << dataFilename << " !\n";
		exit(1);
	}

	if (perfumeryData.is_open())
	{
		while (!perfumeryData.eof())
		{
			if (getline(perfumeryData, token, '\n'))
			{
				auto data = stringSplitter(token);

				brand = data.at(0);
				flavor = data.at(1);
				aromaGroup = data.at(2);
				manufacturer = data.at(3);
				type = data.at(4);
				price = data.at(5);

				if (type == "�������")
				{
					perfumes_.push_back(MensPerfumes(brand, flavor, aromaGroup, manufacturer, stod(price)));
				}
				else
				{
					perfumes_.push_back(WomenPerfumes(brand, flavor, aromaGroup, manufacturer, stod(price)));
				}
			}
		}
		perfumeryData.close();
	}
}

//void PerfumeryHandler::writeInXls()
//{
//	ExcelLoader xls;
//	xls.LoadExcel(dataFilename, 1);
//
//	excelstream os(xls.range_, 1, 1);
//
//	StreamTable st(os);
//	st.SetCols(6);
//
//	st.MakeBorderExt(false);
//	st.SetDelimRow(false);
//	st.SetDelimCol(true, excel_stringbuf::colDelim);
//
//	st << "#" << "�����" << "���" << "������" << "������ ��������" << "�������������" << "����";
//
//	for (auto it = perfumes_.begin(); it != perfumes_.end(); it++)
//	{
//		st << it->getBrand() << it->getType() << it->getFlavor() << it->getAromaGroup() << it->getManufacturer() << it->getPrice();
//	}
//
//	os.flush();
//	xls.Detach();
//}

PerfumeryHandler::PerfumeryHandler()
{
	readFromTxt();
	perfumeryToEdit_ = nullptr;
}

PerfumeryHandler::PerfumeryHandler(const list<Perfumery>& perfumes)
{
	perfumes_ = perfumes;
	perfumeryToEdit_ = nullptr;
}

void PerfumeryHandler::setPerfumes(const list<Perfumery> perfumes)
{
	perfumes_ = perfumes;
}

list<Perfumery>& PerfumeryHandler::getPerfumes()
{
	return perfumes_;
}

void PerfumeryHandler::perfumeryMenu()
{
	while (true)
	{
		try
		{
			system("cls");
		
			string choice;
			cout << "���� ������ � �����������: " << endl;
			cout << "1.�������� ����������." << endl;
			cout << "2.������� ����������." << endl;
			cout << "3.������������� ����������." << endl;
			cout << "4.�������� ��� ����������." << endl;
			cout << "5.����� ������ �� ������." << endl;
			cout << "6.�����." << endl;
			cout << "��� �����: ";
			cin >> choice;

			integerCheck(choice);

			switch (stoul(choice))
			{
			case PerfumeryMenuAction::ADD_PERFUMERY :
				system("cls");
				addPerfumery();
				system("pause");
				break;
			case PerfumeryMenuAction::DELETE_PERFUMERY :
				system("cls");
				deletePerfumery();
				system("pause");
				break;
			case PerfumeryMenuAction::EDIT_PERFUMERY :
				system("cls");
				editMenu();
				break;
			case PerfumeryMenuAction::SHOW_PERFUMERY :
				system("cls");
				showPerfumes();
				system("pause");
				break;
			case PerfumeryMenuAction::FIND_PERFUMERY :
				system("cls");
				findByBrand();
				system("pause");
				break;
			case PerfumeryMenuAction::BACK_TO_MAIN_MENU :
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

void PerfumeryHandler::editMenu()
{
	try
	{
		if (perfumes_.empty())
		{
			throw EmptyPerfumeryListException();
		}

		showPerfumes();

		string id;
		cout << "������� ��: ";
		cin >> id;
		integerCheck(id);

		auto editIt = next(perfumes_.begin(), stoul(id));

		if (editIt == perfumes_.end())
		{
			throw PerfumeryNotFoundException();
		}

		perfumeryToEdit_ = new Perfumery(*editIt);

		while (true)
		{
			try
			{
				system("cls");

				showEditPerfume();

				string choice;
				cout << "���� �������������� ����������:" << endl;
				cout << "1.�������� �����." << endl;
				cout << "2.�������� ������." << endl;
				cout << "3.�������� ������ ��������." << endl;
				cout << "4.�������� �������������." << endl;
				cout << "5.�������� ���." << endl;
				cout << "6.�������� ����." << endl;
				cout << "7.�����." << endl;
				cout << "��� �����: ";
				cin >> choice;
				integerCheck(choice);

				switch (stoul(choice))
				{
				case PerfumeryEditMenuAction::EDIT_BRAND :
					system("cls");
					editBrand();
					system("pause");
					break;
				case PerfumeryEditMenuAction::EDIT_FLAVOR :
					system("cls");
					editFlavor();
					system("pause");
					break;
				case PerfumeryEditMenuAction::EDIT_AROMA_GROUP :
					system("cls");
					editAromaGroup();
					system("pause");
					break;
				case PerfumeryEditMenuAction::EDIT_MANUFACTURER :
					system("cls");
					editManufacturer();
					system("pause");
					break;
				case PerfumeryEditMenuAction::EDIT_TYPE :
					system("cls");
					editType();
					system("pause");
					break;
				case PerfumeryEditMenuAction::EDIT_PRICE :
					system("cls");
					editPrice();
					system("pause");
					break;
				case PerfumeryEditMenuAction::BACK_TO_PERFUMERY_MENU :
					perfumes_.erase(next(perfumes_.begin(), stoul(id)));
					perfumes_.emplace(next(perfumes_.begin(), stoul(id)), *perfumeryToEdit_);
					writeInTxt();
					perfumeryToEdit_ = nullptr;
					return;
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
	catch (EmptyPerfumeryListException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
		system("pause");
	}
	catch (PerfumeryNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
		system("pause");
	}
}

void PerfumeryHandler::addPerfumery()
{
	try
	{
		string brand;
		cout << "������� �����: ";
		cin >> brand;
		alphabetCheck(brand);

		string flavor;
		cout << "������� ������: ";
		cin >> flavor;
		alphabetCheck(flavor);

		string aromaGroup;
		cout << "������� ������ ��������: ";
		cin >> aromaGroup;
		alphabetCheck(aromaGroup);

		string manufacturer;
		cout << "������� ������-�������������: ";
		cin >> manufacturer;
		alphabetCheck(manufacturer);

		string price;
		cout << "������� ����: ";
		cin >> price;
		doubleCheck(price);

		string choice;
		cout << "�������� ��� ����������: " << endl;
		cout << "1.������." << endl;
		cout << "2.�������." << endl;
		cout << "��� �����: ";
		cin >> choice;
		integerCheck(choice);

		switch (stoul(choice))
		{
		case PerfumeryType::MEN:
			perfumes_.push_back(Perfumery(MensPerfumes(brand, flavor, aromaGroup, manufacturer, stod(price))));
			break;
		case PerfumeryType::WOMEN:
			perfumes_.push_back(Perfumery(WomenPerfumes(brand, flavor, aromaGroup, manufacturer, stod(price))));
			break;
		}

		writeInTxt();

		cout << "���������� ������� ���������!" << endl;
	}
	catch (NullArgumentException& ex)
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

void PerfumeryHandler::deletePerfumery()
{
	try
	{
		if (perfumes_.empty())
		{
			throw EmptyPerfumeryListException();
		}

		showPerfumes();

		string id;
		cout << endl << "������� �� ��� ��������: ";
		cin >> id;
		integerCheck(id);

		if (stoul(id) + 1 > perfumes_.size())
		{
			throw PerfumeryNotFoundException();
		}

		perfumes_.erase(next(perfumes_.begin(), stoul(id)));
		writeInTxt();

		system("cls");
		cout << "���������� ������� �������!" << endl;
	}
	catch (NullArgumentException& ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (PerfumeryNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
	catch (EmptyPerfumeryListException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void PerfumeryHandler::findByBrand()
{
	try
	{
		if (perfumes_.empty())
		{
			throw EmptyPerfumeryListException();
		}

		string brand;
		cout << "������� �����: ";
		cin >> brand;
		alphabetCheck(brand);

		list<Perfumery> found;
		for (auto it = perfumes_.begin(); it != perfumes_.end(); it++)
		{
			if (it->getBrand() == brand)
			{
				found.push_back(*it);
			}
		}

		if (found.empty())
		{
			throw PerfumeryNotFoundException();
		}

		system("cls");

		cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;
		cout << "|       �����      |     ���     |      ������     |   ������ ��������   |   �������������  |   ����   |" << endl;
		cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;

		for (auto it = found.begin(); it != found.end(); it++)
		{
			cout << *it << endl;
		}

		cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;
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
	catch (PerfumeryNotFoundException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void PerfumeryHandler::showPerfumes()
{
	try
	{
		if (perfumes_.empty())
		{
			throw EmptyPerfumeryListException();
		}

		cout << "+------+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;
		cout << "|  ��  |       �����      |     ���     |      ������     |   ������ ��������   |   �������������  |   ����   |" << endl;
		cout << "+------+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;

		for (auto it = perfumes_.begin(); it != perfumes_.end(); it++)
		{
			cout << "|" << setw(6) << left << distance(perfumes_.begin(), it);
			cout << *it << endl;
		}

		cout << "+------+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;
	}
	catch (EmptyPerfumeryListException & ex)
	{
		system("cls");
		cout << ex.getError() << endl;
	}
}

void PerfumeryHandler::showEditPerfume()
{
	if (perfumeryToEdit_ == nullptr)
	{
		throw PerfumeryToEditNotSettedException();
	}

	cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;
	cout << "|       �����      |     ���     |      ������     |   ������ ��������   |   �������������  |   ����   |" << endl;
	cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;

	cout << *perfumeryToEdit_ << endl;

	cout << "+------------------+-------------+-----------------+---------------------+------------------+----------+" << endl;
}

PerfumeryHandler::~PerfumeryHandler()
{
	perfumeryToEdit_ = nullptr;
}
