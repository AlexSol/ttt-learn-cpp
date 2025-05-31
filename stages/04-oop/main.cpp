// 🧩 Tic-Tac-Toe — Stage 04: OOP Class Game
// Перехід до повноцінного класу з інкапсуляцією

#include <iostream>
using namespace std;

const int SIZE = 3;

class Game
{
public:
    Game() : currentPlayer('X')
    {
        InitBoard();
    }

    void Play()
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
                cout << "🎉 Гравець " << currentPlayer << " переміг!\n";
                break;
            }

            if (IsDraw())
            {
                PrintBoard();
                cout << "🤝 Нічия!\n";
                break;
            }

            SwitchPlayer();
        }
    }

private:
    char board[SIZE][SIZE];
    char currentPlayer;

    void InitBoard()
    {
        for (int row = 0; row < SIZE; ++row)
            for (int col = 0; col < SIZE; ++col)
                board[row][col] = ' ';
    }

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

    void MakeMove(int row, int col)
    {
        board[row][col] = currentPlayer;
    }

    bool IsWin() const
    {
        for (int i = 0; i < SIZE; ++i)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }

        return (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
               (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer);
    }

    bool IsDraw() const
    {
        for (int row = 0; row < SIZE; ++row)
            for (int col = 0; col < SIZE; ++col)
                if (board[row][col] == ' ')
                    return false;

        return true;
    }

    void SwitchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

// === Точка входу ===
int main()
{
    cout << "=== Хрестики-Нулики — Етап 04: Клас Game ===\n";
    Game game;
    game.Play();
    cout << "=== Кінець гри ===\n";
    return 0;
}
