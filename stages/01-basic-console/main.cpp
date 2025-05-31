// 🧩 Tic-Tac-Toe — Stage 01: Basic Console Version
// Гра "Хрестики-Нулики" на базовому рівні C++
// Все в одному файлі. Коментарі — навчальні.

#include <iostream>  // для std::cout, std::cin
using namespace std;

// 3x3 ігрове поле
char board[3][3];

// Ініціалізація порожнього поля (усі клітинки = ' ')
void InitBoard()
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            board[row][col] = ' ';
        }
    }
}

// Вивід ігрового поля у консоль
void PrintBoard()
{
    cout << "\n";
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            cout << " " << board[row][col];
            if (col < 2) cout << " |";
        }
        cout << "\n";
        if (row < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Перевірка перемоги по горизонталях, вертикалях та діагоналях
bool CheckWin(char player)
{
    // Рядки
    for (int row = 0; row < 3; ++row)
    {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
            return true;
    }

    // Стовпці
    for (int col = 0; col < 3; ++col)
    {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
            return true;
    }

    // Діагоналі
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Перевірка, чи всі клітинки заповнено
bool IsBoardFull()
{
    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            if (board[row][col] == ' ')
                return false;
    return true;
}

int main()
{
    cout << "=== Хрестики-Нулики на C++ ===\n";

    InitBoard();  // Очищаємо поле

    char currentPlayer = 'X';

    while (true)
    {
        PrintBoard();

        int row, col;

        // Ввід гравця
        cout << "Гравець " << currentPlayer << ", введіть рядок і стовпець (0-2): ";
        cin >> row >> col;

        // Перевірка правильності ходу
        if (row < 0 || row > 2 || col < 0 || col > 2)
        {
            cout << "Неприпустимі координати. Спробуйте ще раз.\n";
            continue;
        }

        if (board[row][col] != ' ')
        {
            cout << "Клітинка вже зайнята. Спробуйте ще раз.\n";
            continue;
        }

        // Робимо хід
        board[row][col] = currentPlayer;

        // Перевірка перемоги
        if (CheckWin(currentPlayer))
        {
            PrintBoard();
            cout << "Гравець " << currentPlayer << " переміг!\n";
            break;
        }

        // Нічия?
        if (IsBoardFull())
        {
            PrintBoard();
            cout << "Нічия!\n";
            break;
        }

        // Зміна гравця
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "=== Кінець гри ===\n";
    return 0;
}
