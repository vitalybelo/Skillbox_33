#include <iostream>
#include <random>
#include "FishGame.h"
using namespace std;

void displayField(GameField* field) {
    cout << "GAME FIELD: [";
    for (int i = 0; i < FIELD_SIZE; ++i) {
        char a = '.';
        if (field[i].fish) {
            a = 'F';
        } else if (field[i].boot) {
            a = 'B';
        }
        cout << a;
    }
    cout << "]\n\n";
}

void distributeField(GameField* field) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, FIELD_SIZE - 1);

    int boot_locator = 0;
    field[dist(gen)].fish = true; // селим рыбу в пруд

    // туда же кидаем еще 3 сапога
    while (boot_locator < 3) {
        int i = dist(gen);
        if (!field[i].fish && !field[i].boot) {
            field[i].boot = true;
            ++boot_locator;
        }
    }
}

void playGame(GameField* field) {

    // кидаем удочку и смотрим что получается
    do {
        int i;
        cout << "\nВведите номер сектора: ";
        cin >> i;
        if (i < 0 || i > FIELD_SIZE - 1) {
            cout << "\tВнимание: значение номера сектора должно быть от 0 до " << FIELD_SIZE - 1 << endl;
            continue;
        } else if (field[i].fish) {
            throw FishFoundException();
        } else  if (field[i].boot) {
            throw BootFoundException();
        }
        cout << "\tПусто, давайте попробуем еще раз\n";
    } while(true);

}
