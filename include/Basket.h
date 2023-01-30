#include <iostream>
#include <map>

class Basket {
private:
    // key = vendor code, value = product amount
    std::map<std::string, int> basket {{"A101",2},{"A102",4}}; // изначально в корзине

public:
    Basket() = default;

    void add();
    void remove();
    void list();
    static std::pair<std::string, int> getConsolePair();

};
