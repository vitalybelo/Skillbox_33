#include <iostream>
#include "use_lib.h"
#include "DataRegister.h"
using namespace std;

void solution_3_vector() {

    cout << "\n********************** Решение №3 *********************";
    cout << "\n:  реализовано с помощью VECTOR                       :";
    cout << "\n:                                                     :";
    cout << "\n:  доступные команды:                                 :";
    cout << "\n:  addBasket: добавить запись                               :";
    cout << "\n:  print: список всех записей реестра (listBasket)          :";
    cout << "\n:  removeBasket: удаление всех записей с заданным ключом    :";
    cout << "\n:  find: поиск всех записей с заданным ключом         :";
    cout << "\n:  exit: выход                                        :";
    cout << "\n*******************************************************\n";

    DataRegister<int, string> data;

    string command;
    do {
        clearStdin();
        cout << "\nВведите команду: ";
        command = getCommand();
        if (command == "addBasket") {
            data.add();
        } else if (command == "listBasket" || command == "print") {
            data.list();
        } else if (command == "find") {
            data.find();
        } else if (command == "removeBasket") {
            data.remove();
        }
    } while(command != "exit");

}