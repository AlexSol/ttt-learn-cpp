#pragma once

#include <vector>

namespace ttt
{

class Game
{
public:
    Game();
    void Play();

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void InitBoard();
    void PrintBoard() const;
    void AskMove(int& row, int& col) const;
    void MakeMove(int row, int col);
    bool IsWin() const;
    bool IsDraw() const;
    void SwitchPlayer();
};

} // namespace ttt
