#include <iostream>
#include <map>

class Basket {
private:
    // key = vendor code, value = product amount
    std::map<std::string, int> basket;

public:
    Basket() = default;
    explicit Basket(const std::map<std::string, int> &basket);

    void add();
    void remove();
    void list();
    static std::pair<std::string, int> getConsolePair();

};
