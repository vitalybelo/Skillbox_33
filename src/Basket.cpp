#pragma once
#include "Basket.h"

using namespace std;


void Basket::add() {
    auto p = getConsolePair();
    auto f = basket.find(p.first);

    if (f == basket.end()) {
        // артикул не найден, добавляем товар в корзину
        basket.emplace(p.first, p.second);
        cout << "\tДобавлен товар :: ";
    } else {
        // товар с таким артикулом уже есть в корзине, добавляем количество
        f->second += p.second;
        p.second = f->second;
        cout << "\tИзменено количество товара :: ";
    }
    cout << "артикул: " << p.first << ", количество = " << p.second << endl;
}

void Basket::list() {
    if (!basket.empty()) {
        cout << "\nКорзина:\n";
        auto iter = basket.begin();
        while (iter != basket.end()) {
            cout << "Артикул: " << iter->first << "\t:: количество = " << iter->second << endl;
            ++iter;
        }
    } else {
        cout << "\nКорзина пустая.\n";
    }
}

void Basket::remove() {


}

pair<string, int> Basket::getConsolePair() {

    pair<string, int> p{};
    const string inv_a = "\nInvalid arguments exception: ";

    // вводим артикул, проверяем на пустую строку
    cout << "\tВведите артикул: ";
    getline(cin, p.first);
    if (p.first.empty())
        throw invalid_argument(inv_a + "артикул товара не указан (empty string).\n");

    // вводим количество, проверяем на положительное значение
    cout << "\tВведите количество: ";
    cin >> p.second;
    if (p.second <= 0)
        throw invalid_argument(inv_a + "количество товара меньше или равно нулю (<= 0).\n");

    return p;
}
