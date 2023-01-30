#include <iostream>
#include <map>

class Basket {
private:
    std::map<std::string, int> basket{}; // key = vendor code, value = product amount

public:
    Basket() = default;

    void add();
    void remove();
    void list();
    static std::pair<std::string, int> getConsolePair();


};
