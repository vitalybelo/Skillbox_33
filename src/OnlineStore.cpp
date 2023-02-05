#include "OnlineStore.h"

using namespace std;

[[maybe_unused]] OnlineStore::OnlineStore(const map<std::string, int> &products) : products(products) {}

void OnlineStore::listProducts() {
    if (!products.empty()) {
        cout << "\nДоступные для заказа товары:\n";
        for (auto & item : products)
            cout << "Артикул: " << item.first << " :: количество = " << item.second << endl;
    } else {
        throw invalid_argument("\nException: empty product database occurred.\n");
    }
}

void OnlineStore::listBasket() {
    if (!basket.empty()) {
        cout << "\nСостав корзины:\n";
        for (auto & item : basket)
            cout << "Артикул: " << item.first << " :: количество = " << item.second << endl;
    } else {
        cout << "\nКорзина пустая.\n";
    }
}

string OnlineStore::inputVendorCode() {
    string s;
    cout << "\tВведите артикул: ";
    getline(cin,s);
    if (s.empty())
        throw invalid_argument(inv_a + "артикул указан неверно (введена пустая строка).\n");
    return s;
}

int OnlineStore::inputProductAmount() {
    int amount;
    cout << "\tВведите количество: ";
    cin >> amount;
    if (amount <= 0)
        throw invalid_argument(inv_a + "количество товара меньше или равно нулю (<= 0).\n");
    return amount;
}

void OnlineStore::addBasket() {

    pair<string, int> p{};

    // вводим артикул, проверяем
    p.first = inputVendorCode();
    auto fp = products.find(p.first);
    if (fp == products.end())
        throw invalid_argument(inv_a + "такого товара нет в базе магазина (выберите другой товар).\n");
    if (fp->second == 0)
        throw range_error("\nДанный товар закончился, пожалуйста выберите другой товар.\n");

    // вводим количество, проверяем и проверяем
    p.second = inputProductAmount();
    if (p.second > fp->second) {
        char a;
        cout << "\n\tВ остатках имеется только = " << fp->second << " (шт) товара \"" << fp->first <<"\"";
        cout << "\n\tВы хотите взять это количество ? или выберите другой товар ?";
        cout << "\n\tВведите ваш выбор y[взять]/n[выбрать другой]: ";
        cin >> a;
        if (a == 'n')
            throw invalid_argument("\nСпасибо. Выберите пожалуйста другой товар для добавления.\n");
        p.second = fp->second;
    }
    fp->second -= p.second;

    // добавляем товар в корзину
    auto fb = basket.find(p.first);
    if (fb == basket.end()) {
        // артикул в корзине не найден, добавляем товар в корзину
        basket.emplace(p.first, p.second);
        cout << "\tДобавлен товар :: ";
    } else {
        // товар с таким артикулом уже есть в корзине, добавляем количество
        fb->second += p.second;
        p.second = fb->second; // изменяем значение только для вывода в консоль
        cout << "\tИзменено количество товара :: ";
    }
    cout << "артикул: " << p.first << ", количество = " << p.second << endl;

}

void OnlineStore::removeBasket() {

    pair<string, int> p{};

    // вводим артикул, проверяем
    p.first = inputVendorCode();
    auto fb = basket.find(p.first);
    if (fb == basket.end())
        // товара с таким артикулом в корзине нет
        throw invalid_argument(inv_a + "товар с таким артикулом в корзине отсутствует\n");

    // товар с таким артикулом найден, ввод количества + проверки++
    cout << "\tВ корзине сейчас " << fb->second << " (шт) товара: \"" << fb->first << "\", сколько убрать ?\n";
    p.second = inputProductAmount();
    if (p.second > fb->second) {
        char a;
        cout << "\n\tВ вашей корзине имеется только = " << fb->second << " (шт) этого товара";
        cout << "\n\tВы хотите убрать всё это количество ? или подумаете и решите потом ?";
        cout << "\n\tВведите ваш выбор y[убрать]/n[подумать]: ";
        cin >> a;
        if (a == 'n')
            throw invalid_argument("\nСпасибо за ваш выбор. Вы можете продолжить делать покупки.\n");
        p.second = fb->second;
    }

    // уменьшаем количество товара по заданному артикулу в корзине
    fb->second -= p.second;
    cout << "\tТекущее количество товара в корзине = " << fb->second << endl;
    // если количество товара стало = 0, удаляем товар из корзины совсем
    if (fb->second == 0) {
        basket.erase(fb);
        cout << "\tТовар удален из корзины.\n";
    }

    // добавляем на полку магазины выложенный из корзины товар
    auto fp = products.find(p.first);
    if (fp == products.end())
        throw range_error("Exception: something was wrong, not found product in database (removeBasket() method)");
    fp->second += p.second;

}



