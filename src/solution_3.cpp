#include <iostream>
#include "use_lib.h"
#include "DataRegister.h"
using namespace std;

void solution_3() {

    cout << "\n********************** Решение №3 *********************";
    cout << "\n:  доступные команды:                                 :";
    cout << "\n:  add: добавить запись                               :";
    cout << "\n:  print: список всех записей реестра (list)          :";
    cout << "\n:  remove: удаление всех записей с заданным ключом    :";
    cout << "\n:  find: поиск всех записей с заданным ключом         :";
    cout << "\n:  exit: выход                                        :";
    cout << "\n*******************************************************\n";

    DataRegister<int, int> data;

    string command;
    do {
        clearStdin();
        cout << "\nВведите команду: ";
        command = getCommand();
        if (command == "add") {
            data.add();
        } else if (command == "list" || command == "print") {
            data.list();
        } else if (command == "find") {
            data.find();
        } else if (command == "remove") {
            data.remove();
        }
    } while(command != "exit");

}