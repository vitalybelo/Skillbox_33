#include <iostream>
#include "use_lib.h"
using namespace std;

void solution_1() {

    cout << "\n*************** Решение №1 ***************\n";

    string command;
    do {
        clearStdin();
        cout << "Введите команду:";
        command = getCommand();



    } while(command != "exit");


}