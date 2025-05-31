#include "game.hpp"
#include <iostream>
#include <algorithm>

namespace ttt
{

const int SIZE = 3;

Game::Game() : board(SIZE, std::vector<char>(SIZE, ' ')), currentPlayer('X') {}

void Game::Play()
{
    while (true)
    {
        PrintBoard();

        int row, col;
        AskMove(row, col);
        MakeMove(row, col);

        if (IsWin())
        {
            PrintBoard();
            std::cout << "🎉 Гравець " << currentPlayer << " переміг!\n";
            break;
        }

        if (IsDraw())
        {
            PrintBoard();
            std::cout << "🤝 Нічия!\n";
            break;
        }

        SwitchPlayer();
    }
}

void Game::InitBoard()
{
    for (auto& row : board)
        std::fill(row.begin(), row.end(), ' ');
}

void Game::PrintBoard() const
{
    std::cout << "\n";
    for (int row = 0; row < SIZE; ++row)
    {
        for (int col = 0; col < SIZE; ++col)
        {
            std::cout << " " << board[row][col];
            if (col < SIZE - 1) std::cout << " |";
        }
        std::cout << "\n";
        if (row < SIZE - 1) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

void Game::AskMove(int& row, int& col) const
{
    while (true)
    {
        std::cout << "Гравець " << currentPlayer << ", введіть координати (рядок і стовпець): ";
        std::cin >> row >> col;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        {
            std::cout << "Некоректні координати. Спробуйте ще раз.\n";
            continue;
        }

        if (board[row][col] != ' ')
        {
            std::cout << "Клітинка зайнята. Спробуйте ще раз.\n";
            continue;
        }

        break;
    }
}

void Game::MakeMove(int row, int col)
{
    board[row][col] = currentPlayer;
}

bool Game::IsWin() const
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (std::all_of(board[i].begin(), board[i].end(), [this](char c) { return c == currentPlayer; }))
            return true;

        if (std::all_of(board.begin(), board.end(), [i, this](const std::vector<char>& row) { return row[i] == currentPlayer; }))
            return true;
    }

    if (std::all_of(board.begin(), board.end(), [n = 0, this](const std::vector<char>& row) mutable { return row[n++] == currentPlayer; }))
        return true;

    if (std::all_of(board.begin(), board.end(), [n = SIZE - 1, this](const std::vector<char>& row) mutable { return row[n--] == currentPlayer; }))
        return true;

    return false;
}

bool Game::IsDraw() const
{
    int filled = 0;
    for (const auto& row : board)
        filled += std::count(row.begin(), row.end(), 'X') + std::count(row.begin(), row.end(), 'O');

    return filled == SIZE * SIZE;
}

void Game::SwitchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

} // namespace ttt
