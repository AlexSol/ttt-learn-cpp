// 🧩 Tic-Tac-Toe — Stage 03: Struct-Based Game
// На цьому етапі вся логіка гри обгорнута в структуру Game

#include <iostream>
using namespace std;

const int SIZE = 3;

// Структура гри: включає поле та основні методи
struct Game
{
    char board[SIZE][SIZE];
    char currentPlayer = 'X';

    // Ініціалізація поля
    void Init()
    {
        for (int row = 0; row < SIZE; ++row)
            for (int col = 0; col < SIZE; ++col)
                board[row][col] = ' ';
    }

    // Вивід поля
    void PrintBoard() const
    {
        cout << "\n";
        for (int row = 0; row < SIZE; ++row)
        {
            for (int col = 0; col < SIZE; ++col)
            {
                cout << " " << board[row][col];
                if (col < SIZE - 1) cout << " |";
            }
            cout << "\n";
            if (row < SIZE - 1) cout << "---+---+---\n";
        }
        cout << "\n";
    }

    // Запит ходу гравця
    void AskMove(int& row, int& col) const
    {
        while (true)
        {
            cout << "Гравець " << currentPlayer << ", введіть координати (рядок і стовпець): ";
            cin >> row >> col;

            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
            {
                cout << "Некоректні координати. Спробуйте ще раз.\n";
                continue;
            }

            if (board[row][col] != ' ')
            {
                cout << "Клітинка зайнята. Спробуйте ще раз.\n";
                continue;
            }

            break;
        }
    }

    // Виконати хід
    void MakeMove(int row, int col)
    {
        board[row][col] = currentPlayer;
    }

    // Перевірка перемоги
    bool IsWin() const
    {
        // Рядки
        for (int row = 0; row < SIZE; ++row)
            if (board[row][0] == currentPlayer && board[row][1] == currentPlayer && board[row][2] == currentPlayer)
                return true;

        // Стовпці
        for (int col = 0; col < SIZE; ++col)
            if (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer)
                return true;

        // Діагоналі
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;

        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    // Перевірка нічиєї
    bool IsDraw() const
    {
        for (int row = 0; row < SIZE; ++row)
            for (int col = 0; col < SIZE; ++col)
                if (board[row][col] == ' ')
                    return false;

        return true;
    }

    // Зміна активного гравця
    void SwitchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

// === Точка входу ===
int main()
{
    cout << "=== Хрестики-Нулики — Етап 03: struct Game ===\n";

    Game game;
    game.Init();

    while (true)
    {
        game.PrintBoard();

        int row, col;
        game.AskMove(row, col);
        game.MakeMove(row, col);

        if (game.IsWin())
        {
            game.PrintBoard();
            cout << "🎉 Гравець " << game.currentPlayer << " переміг!\n";
            break;
        }

        if (game.IsDraw())
        {
            game.PrintBoard();
            cout << "🤝 Нічия!\n";
            break;
        }

        game.SwitchPlayer();
    }

    cout << "=== Кінець гри ===\n";
    return 0;
}
