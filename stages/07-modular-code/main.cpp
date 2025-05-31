#include <iostream>
#include <memory>
#include "game.hpp"

int main()
{
    std::cout << "=== Хрестики-Нулики — Етап 07: Modular Code ===\n";
    auto game = std::make_unique<ttt::Game>();
    game->Play();
    std::cout << "=== Кінець гри ===\n";
    return 0;
}
