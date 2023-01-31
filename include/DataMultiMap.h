#include <iostream>
#include <map>
#pragma once

template<typename T_key, typename T_value>
class DataMultiMap {
private:
    std::multimap<T_key, T_value> data;

public:

    void add();
    void list();
    void find();
    void remove();

};

template<typename T_key, typename T_value>
void DataMultiMap<T_key, T_value>::add() {

    std::pair<T_key, T_value> p;
    std::cout << "\tВведите значение ключа: ";
    std::cin >> p.first;
    std::cout << "\tВведите значение для этого ключа: ";
    std::cin >> p.second;

    data.emplace(p);
}

template<typename T_key, typename T_value>
void DataMultiMap<T_key, T_value>::list() {

    if (!data.empty()) {
        int i = 0;
        for (std::pair<T_key, T_value> p: data) {
            std::cout << "\t№" << ++i << ". ключ: " << p.first << " :: значение = " << p.second << std::endl;
        }
    } else {
        std::cout << "\n\tРеестр пустой, записей нет.\n";
    }
}

template<typename T_key, typename T_value>
void DataMultiMap<T_key, T_value>::find() {

    T_key key;
    std::cout << "\tВведите значение ключа: ";
    std::cin >> key;

    typename std::multimap<T_key, T_value>::iterator it = data.lower_bound(key);
    typename std::multimap<T_key, T_value>::iterator it_end = data.upper_bound(key);

    for(int i = 1; it != it_end; ++it, ++i)
        std::cout << "\t\t№" << i << ". ключ: " << it->first << " :: значение = " << it->second << std::endl;

    std::cout << "\t\tКоличество найденных записей в реестре = " << data.count(key) << std::endl;
}

template<typename T_key, typename T_value>
void DataMultiMap<T_key, T_value>::remove() {

    T_key key;
    std::cout << "\tВведите значение ключа: ";
    std::cin >> key;

    auto found_records = data.erase(key);
    std::cout << "\t\tКоличество найденных и удаленных записей = " << found_records << std::endl;
}
