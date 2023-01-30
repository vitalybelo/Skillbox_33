#include <iostream>
#include "Basket.h"
#include "use_lib.h"
using namespace std;

void solution_1() {

    cout << "\n********************** Решение №1 *********************";
    cout << "\n:  в корзине уже есть 2 товара, можно продолжить      :";
    cout << "\n:  доступные команды:                                 :";
    cout << "\n:  add: добавить в корзину товар (количество)         :";
    cout << "\n:  list: просмотр товаров в корзине                   :";
    cout << "\n:  remove: удаление товаров из корзины                :";
    cout << "\n*******************************************************\n";
    Basket basket;

    basket.list();
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