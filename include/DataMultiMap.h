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

    typename std::multimap<T_key, T_value>::iterator it;
    typename std::multimap<T_key, T_value>::iterator it_beg = data.lower_bound(key);
    typename std::multimap<T_key, T_value>::iterator it_end = data.upper_bound(key);
    int i = 0;
    bool found_flag = false;
    for(it = it_beg; it != it_end; ++it) {
        if (!found_flag) {
            found_flag = true;
            std::cout << "\tПо значению ключа найдено:\n";
        }
        std::cout << "\t\t№" << ++i << ". ключ: " << it->first << " :: значение = " << it->second << std::endl;
    }
    if (!found_flag)
        std::cout << "\t\tПо значению ключа ничего найдено:\n";
}

template<typename T_key, typename T_value>
void DataMultiMap<T_key, T_value>::remove() {

    T_key key;
    std::cout << "\tВведите значение ключа: ";
    std::cin >> key;

    int found_records = (int)data.count(key);
    for(int i = 0; i < found_records; i++)
        data.erase(data.find(key));

    std::cout << "\t\tКоличество найденных и удаленных записей = " << found_records << std::endl;

}
