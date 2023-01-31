#include <iostream>
#include "Basket.h"
#include "use_lib.h"
using namespace std;

void solution_1() {

    cout << "\n********************** Решение №1 *********************";
    cout << "\n:  У Вас 2 товара в корзине, можно продолжить ...     :";
    cout << "\n:                                                     :";
    cout << "\n:  доступные команды:                                 :";
    cout << "\n:  add: добавить в корзину товар (количество)         :";
    cout << "\n:  list: просмотр товаров в корзине                   :";
    cout << "\n:  remove: удаление товаров из корзины                :";
    cout << "\n:  exit: выход                                        :";
    cout << "\n*******************************************************\n";
    Basket basket({{"A1",2},{"A2",4}});

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
            } catch (const range_error & o) {
                cout << o.what();
            }
        }
    } while(command != "exit");

}