#pragma once

#include <string>
#include <vector>

#include "CustomerHandler.h"

#include "NullArgumentException.h"
#include "InvalidInputException.h"

void alphabetCheck(const string& input);
void integerCheck(const string& input);
void doubleCheck(const string& input);
void telephoneCheck(const string& input);
vector<string> stringSplitter(string& source);