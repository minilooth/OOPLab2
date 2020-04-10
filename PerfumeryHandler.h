#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <fstream>

#include "Functions.h"

#include "MensPerfumes.h"
#include "WomenPerfumes.h"

//#include "StreamTable.h"
//#include "ExcelStream.h"

#include "PerfumeryNotFoundException.h"
#include "PerfumeryToEditNotSettedException.h"
#include "EmptyPerfumeryListException.h"
#include "NullArgumentException.h"
#include "InvalidInputException.h"

using namespace std;

class PerfumeryHandler
{
	static list<Perfumery> perfumes_;

	static Perfumery* perfumeryToEdit_;

	static string dataFilename;

	static void editBrand();
	static void editFlavor();
	static void editAromaGroup();
	static void editManufacturer();
	static void editType();
	static void editPrice();

	static void writeInTxt();
	static void readFromTxt();

	//static void writeInXls();
	//static void readFromXls();

	static void showEditPerfume();
public:
	enum PerfumeryType
	{
		MEN = 1,
		WOMEN
	};

	enum PerfumeryMenuAction
	{
		ADD_PERFUMERY = 1,
		DELETE_PERFUMERY,
		EDIT_PERFUMERY,
		SHOW_PERFUMERY,
		FIND_PERFUMERY,
		BACK_TO_MAIN_MENU
	};

	enum PerfumeryEditMenuAction
	{
		EDIT_BRAND = 1,
		EDIT_FLAVOR,
		EDIT_AROMA_GROUP,
		EDIT_MANUFACTURER,
		EDIT_TYPE,
		EDIT_PRICE,
		BACK_TO_PERFUMERY_MENU
	};

	PerfumeryHandler();
	explicit PerfumeryHandler(const list<Perfumery>& perfumes);

	static void setPerfumes(const list<Perfumery> perfumes);

	static list<Perfumery>& getPerfumes();

	static void perfumeryMenu();
	static void editMenu();

	static void addPerfumery();
	static void deletePerfumery();

	static void findByBrand();

	static void showPerfumes();

	~PerfumeryHandler();
};

