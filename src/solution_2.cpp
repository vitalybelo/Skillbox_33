#include <iostream>
#include "FishGame.h"
using namespace std;

void solution_2() {

    cout << "\n********************** Решение №2 *********************\n";

    GameField field[FIELD_SIZE]{};  // организуем игровое поле
    distributeField(field);         // заселяем поле рыбкой и сапогами
    displayField(field);            // выводим игровое поле

    try {                           // играем и заканчиваем блоками catch
        playGame(field);
    } catch(const FishFoundException & f) {
        cerr << f.what();
    } catch(const BootFoundException & b) {
        cerr << b.what();
    }

}
