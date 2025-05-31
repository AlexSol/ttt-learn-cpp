// 🧩 Tic-Tac-Toe — Stage 06: STL Usage
// Поле представлено через std::vector + використання STL-алгоритмів
// Чудово! Нижче — готові main.cpp та README.md для етапу 06-stl-usage, де:

// ✅ поле char[3][3] замінено на std::vector<std::vector<char>>
// ✅ використовуються STL-алгоритми (std::all_of, std::count)
// ✅ підготовка до ще гнучкішого й модульного коду


#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // std::all_of, std::count
using namespace std;




const int SIZE = 3;

class Game
{
public:
    Game() : board(SIZE, vector<char>(SIZE, ' ')), currentPlayer('X') {}

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
    vector<vector<char>> board;
    char currentPlayer;

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
        // Перевірка рядків та стовпців через all_of
        for (int i = 0; i < SIZE; ++i)
        {
            if (all_of(board[i].begin(), board[i].end(), [this](char c) { return c == currentPlayer; }))
                return true;

            if (all_of(board.begin(), board.end(), [i, this](const vector<char>& row) { return row[i] == currentPlayer; }))
                return true;
        }

        // Діагоналі
        if (all_of(board.begin(), board.end(), [n = 0, this](const vector<char>& row) mutable { return row[n++] == currentPlayer; }))
            return true;

        if (all_of(board.begin(), board.end(), [n = SIZE - 1, this](const vector<char>& row) mutable { return row[n--] == currentPlayer; }))
            return true;

        return false;
    }

    bool IsDraw() const
    {
        int totalFilled = 0;
        for (const auto& row : board)
            totalFilled += count(row.begin(), row.end(), 'X') + count(row.begin(), row.end(), 'O');

        return totalFilled == SIZE * SIZE;
    }

    void SwitchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

// === Точка входу ===
int main()
{
    cout << "=== Хрестики-Нулики — Етап 06: STL Usage ===\n";
    auto game = make_unique<Game>();
    game->Play();
    cout << "=== Кінець гри ===\n";
    return 0;
}
