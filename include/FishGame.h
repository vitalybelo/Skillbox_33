#pragma once
#include <exception>
#define FIELD_SIZE 9

struct GameField {
    bool fish = false;
    bool boot = false;
};

class FishFoundException : public std::exception {
public:
    [[nodiscard]] const char * what() const noexcept override {
        return "\nРЫБА поймана. GAME OVER\n";
    }
};

class BootFoundException : public std::exception {
public:
    [[nodiscard]] const char * what() const noexcept override {
        return "\nВам достался САПОГ. GAME OVER\n";
    }
};

void distributeField(GameField* field);
void displayField(GameField* field);
void playGame(GameField* field);
