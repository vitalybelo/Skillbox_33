#include "use_lib.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include "windows.h"

void to_lower(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}
std::string getCommand() {
    std::string command;
    getline(std::cin,command);
    to_lower(command);
    return command;
}

void clearStdin() {
    std::cin.clear();
    fflush(stdin);
}
void setlocaleRus () {
    setlocale(LC_ALL, "Russian");
}

void setlocaleUTF8() {
    setlocale(LC_ALL,"Russia.Russian.UTF8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}

void setlocale1251() {
    setlocale(LC_ALL,"Russia.Russian.1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int irandom_next(int from, int to) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(from, to);

    return dist(gen);
    //return (int)gen();
}

tm get_TMDate(std::string date_string) {
    time_t t = time(nullptr);
    tm now = *localtime(&t);
    replace(date_string.begin(), date_string.end(), '/', ' ');
    if (std::istringstream(date_string) >> now.tm_mday >> now.tm_mon >> now.tm_year) {
        now.tm_mon -= 1;
        now.tm_year -= 1900;
    }
    return now;
}

