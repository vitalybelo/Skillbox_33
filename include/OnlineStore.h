#pragma once
#include <iostream>
#include <map>

class OnlineStore {
private:
    // key = vendor code, value = product amount
    const std::string inv_a = "\nInvalid arguments exception: ";
    std::map<std::string, int> products;
    std::map<std::string, int> basket;

public:
    OnlineStore() = default;

    [[maybe_unused]] explicit OnlineStore(const std::map<std::string, int> &products);

    // методы заведения товаров интернет магазина
    void listProducts();

    // методы работы с корзиной
    void listBasket();
    void addBasket();
    void removeBasket();
    int inputProductAmount();
    std::string inputVendorCode();

};
