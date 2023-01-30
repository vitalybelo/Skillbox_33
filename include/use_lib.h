#pragma once
#include <iostream>

void to_lower(std::string& s);
std::string getCommand();

void clearStdin();
void setlocaleRus();
void setlocaleUTF8();
void setlocale1251();

int random_nextInt(int from, int to);
tm get_TMDate(std::string date_string);

