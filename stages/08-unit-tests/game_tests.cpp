#include "game.hpp"
#include <gtest/gtest.h>

using namespace ttt;

// Допоміжна функція для швидкого виставлення ходів
void FillRow(Game& game, int row, char symbol)
{
    for (int col = 0; col < 3; ++col)
        game.MakeMove(row, col);
}

TEST(GameTest, WinHorizontal)
{
    Game game;
    game.InitBoard();

    // X робить 3 ходи в перший ряд
    game.MakeMove(0, 0);
    game.MakeMove(0, 1);
    game.MakeMove(0, 2);

    ASSERT_TRUE(game.IsWin());
}

TEST(GameTest, WinDiagonal)
{
    Game game;
    game.InitBoard();

    game.MakeMove(0, 0);
    game.MakeMove(1, 1);
    game.MakeMove(2, 2);

    ASSERT_TRUE(game.IsWin());
}

TEST(GameTest, DrawCondition)
{
    Game game;
    game.InitBoard();

    // X O X
    // X O O
    // O X X
    char moves[3][3] = {
        {'X', 'O', 'X'},
        {'X', 'O', 'O'},
        {'O', 'X', 'X'}
    };

    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            game.MakeMove(r, c);

    ASSERT_TRUE(game.IsDraw());
    ASSERT_FALSE(game.IsWin());
}
