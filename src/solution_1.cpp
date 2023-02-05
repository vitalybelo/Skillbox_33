#include <iostream>
#include "OnlineStore.h"
#include "use_lib.h"
using namespace std;

void displayHelp() {

    cout << "\n********************** Решение №1 *********************";
    cout << "\n:  ? - список команд                                  :";
    cout << "\n:  доступные команды:                                 :";
    cout << "\n:  show: просмотр товаров в магазине                  :";
    cout << "\n:                                                     :";
    cout << "\n:  add: добавить в корзину товар (количество)         :";
    cout << "\n:  list: просмотр товаров в корзине                   :";
    cout << "\n:  remove: удаление товаров из корзины                :";
    cout << "\n:                                                     :";
    cout << "\n:  exit: выход                                        :";
    cout << "\n*******************************************************\n";

}

void solution_1() {

    displayHelp();
    string command;
    //OnlineStore store{}; // если хотите проверить работу с пустой базой магазина
    OnlineStore store({{"milk",10},{"cola",10},{"yogurt",10},{"cake",8},{"juice",6},{"water",10},{"toy",2},{"bread",6}});

    try {
        store.listProducts();
    } catch (const invalid_argument &empty) {
        cerr << empty.what();
        return;
    }

    do {
        clearStdin();
        cout << "\nВведите команду: ";
        command = getCommand();
        if (command == "add") {
            try {
                store.addBasket();
            } catch (const invalid_argument & e) {
                cout << e.what();
            } catch (const range_error & o) {
                cout << o.what();
            }
        } else if (command == "list") {
            store.listBasket();
        } else if (command == "show") {
            store.listProducts();
        } else if (command == "remove") {
            try {
                store.removeBasket();
            } catch (const invalid_argument & e) {
                cout << e.what();
            } catch (const range_error & o) {
                cout << o.what();
            }
        } else if (command == "?") {
            displayHelp();
        }

    } while(command != "exit");

}