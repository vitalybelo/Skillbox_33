#include <iostream>
#include "Basket.h"
#include "use_lib.h"
using namespace std;

void solution_1() {

    cout << "\n*************** Решение №1 ***************\n";
    Basket basket;

    string command;
    do {
        clearStdin();
        cout << "\nВведите команду: ";
        command = getCommand();
        if (command == "add") {
            try {
                basket.add();
            } catch (const invalid_argument & e) {
                cout << e.what();
            }

        } else if (command == "list") {
            basket.list();
        } else if (command == "remove") {
            try {
                basket.remove();
            } catch (const invalid_argument & e) {
                cout << e.what();
            }
        }
    } while(command != "exit");


}