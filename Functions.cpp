#include "Functions.h"

void alphabetCheck(const string& input)
{
	if (input.empty())
	{
		throw NullArgumentException();
	}
	if (input.find_first_not_of("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnmÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏĞÎËÄÆİß×ÑÌÈÒÜÁŞéöóêåíãøùçõúôûâàïğîëäæıÿ÷ñìèòüáş ") != string::npos)
	{
		throw InvalidInputException();
	}
}

void integerCheck(const string& input)
{
	if (input.empty())
	{
		throw NullArgumentException();
	}
	if (input.find_first_not_of("1234567890") != string::npos)
	{
		throw InvalidInputException();
	}
}

void doubleCheck(const string& input)
{
	if (input.empty())
	{
		throw NullArgumentException();
	}
	if (input.find_first_not_of("1234567890.") != string::npos)
	{
		throw InvalidInputException();
	}
}

void telephoneCheck(const string& input)
{
	if (input.empty())
	{
		throw NullArgumentException();
	}
	if (input.find_first_not_of("+1234567890") != string::npos)
	{
		throw InvalidInputException();
	}
	if (input.length() != 13)
	{
		throw InvalidInputException();
	}
}

vector<string> stringSplitter(string& source)
{
	size_t pos = 0;
	vector<string> tokenVector;

	while ((pos = source.find(';')) != string::npos)
	{
		tokenVector.push_back(source.substr(0, pos));
		source.erase(0, pos + 1);
	}
	tokenVector.push_back(source);

	return tokenVector;
}