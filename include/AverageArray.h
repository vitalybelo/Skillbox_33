#include <iostream>
#include <vector>

template<typename T>
class AverageArray {
private:
    std::vector<T> list;
    size_t size = 8;

public:
    AverageArray() = default;
    explicit AverageArray(size_t size) : size(size) {}
    AverageArray(const std::vector<T> &list, size_t size) : list(list), size(size) {}
    virtual ~AverageArray() {
        list.clear();
    }

    void input();
    void print();
    T average();

};

template<typename T>
void AverageArray<T>::print() {
    std::cout << "Массив содержит: ";
    T total_amount = 0;
    for (T t : list) {
        total_amount += t;
        std::cout << " + " << t;
    }
    std::cout << " = " << total_amount << std::endl;
}

template<typename T>
T AverageArray<T>::average() {
    T average = 0;
    for (T t : list)
        average += t;
    return (average / size);
}

template<typename T>
void AverageArray<T>::input() {

    std::cout << "Введите " << size << " значений массива (через пробел): ";
    for (int i = 0; i < size; ++i) {
        T value;
        std::cin >> value;
        list.push_back(value);
    }
}
