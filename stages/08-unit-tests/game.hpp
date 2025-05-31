#pragma once
#include <vector>

//  методи IsWin і IsDraw зроблені public для тестування

namespace ttt
{

class Game
{
public:
    Game();
    void Play();

    // Публічні для юніт-тестів:
    void InitBoard();
    void MakeMove(int row, int col);
    bool IsWin() const;
    bool IsDraw() const;

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void PrintBoard() const;
    void AskMove(int& row, int& col) const;
    void SwitchPlayer();
};

} // namespace ttt
