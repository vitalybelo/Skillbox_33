#pragma once
#include <iostream>
#include <vector>

template<typename Tk, typename Tv>
class DataRegister {
private:
    std::vector<std::pair<Tk,Tv>> data;

public:
    DataRegister() = default;

    void add();
    void list();
    void find();
    void remove();

};

template<typename Tk, typename Tv>
void DataRegister<Tk, Tv>::add() {

    std::pair<Tk, Tv> p;
    std::cout << "\tВведите значение ключа: ";
    std::cin >> p.first;
    std::cout << "\tВведите значение для этого ключа: ";
    std::cin >> p.second;

    data.push_back(p);
}

template<typename Tk, typename Tv>
void DataRegister<Tk, Tv>::remove() {

    Tk key;
    std::cout << "\tВведите значение ключа: ";
    std::cin >> key;

    int found_records = 0;
    typename std::vector<std::pair<Tk, Tv>>::iterator iter = data.begin();
    while(iter != data.end()) {
        if (iter->first == key) {
            data.erase(iter);
            ++found_records;
        } else {
            ++iter;
        }
    }
    std::cout << "\t\tКоличество найденных и удаленных записей = " << found_records << std::endl;
}

template<typename Tk, typename Tv>
void DataRegister<Tk, Tv>::find() {

    Tk key;
    std::cout << "\tВведите значение ключа: ";
    std::cin >> key;

    int i = 1;
    int found_records = 0;
    for(std::pair<Tk, Tv> p : data) {
        if (p.first == key) {
            ++found_records;
            std::cout << "\t\t№" << i++ << ". ключ: " << p.first << " :: значение = " << p.second << std::endl;
        }
    }
    std::cout << "\t\tКоличество найденных записей в реестре = " << found_records << std::endl;;
}

template<typename Tk, typename Tv>
void DataRegister<Tk, Tv>::list() {

    if (!data.empty()) {
        int i = 0;
        std::cout << "\nСодержание реестра:\n";
        for (std::pair<Tk, Tv> p: data) {
            std::cout << "\t№" << ++i << ". ключ: " << p.first << " :: значение = " << p.second << std::endl;
        }
    } else {
        std::cout << "\n\tРеестр пустой, записей нет.\n";
    }
}
