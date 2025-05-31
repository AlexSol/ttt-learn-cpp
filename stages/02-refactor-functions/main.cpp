// ✅ Розбиваємо логіку гри на окремі маленькі функції
// ✅ Додаємо коментарі з призначенням кожної функції
// ✅ Підготовлюємо ґрунт для переходу до struct і class на наступному етап


// 🧩 Tic-Tac-Toe — Stage 02: Refactor into Functions
// Розбиття коду на менші функції. Підготовка до структур і класів.

// ---------------
// ✅ Що нового в цьому етапі
// Рефакторинг	Що змінено
// main()	Тепер лише координує гру — чистий і читабельний
// AskMove()	Вся логіка введення гравця в окремій функції
// MakeMove()	Виносить зміну масиву — логічне розділення
// IsWin(), IsDraw()	Відповідають тільки за перевірку умов гри

#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

// === ІНІЦІАЛІЗАЦІЯ ===

// Заповнює ігрове поле пробілами
void InitBoard()
{
    for (int row = 0; row < SIZE; ++row)
        for (int col = 0; col < SIZE; ++col)
            board[row][col] = ' ';
}

// Виводить поточний стан ігрового поля
void PrintBoard()
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

// === ПЕРЕВІРКИ ===

// Чи виграв гравець з символом 'X' або 'O'
bool IsWin(char player)
{
    // Перевірка рядків
    for (int row = 0; row < SIZE; ++row)
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
            return true;

    // Перевірка стовпців
    for (int col = 0; col < SIZE; ++col)
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
            return true;

    // Перевірка діагоналей
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Чи поле повністю заповнене (нічия)
bool IsDraw()
{
    for (int row = 0; row < SIZE; ++row)
        for (int col = 0; col < SIZE; ++col)
            if (board[row][col] == ' ')
                return false;

    return true;
}

// === ХІД ГРАВЦЯ ===

// Питає користувача, куди хоче зробити хід
void AskMove(int& row, int& col, char currentPlayer)
{
    while (true)
    {
        cout << "Гравець " << currentPlayer << ", введіть координати (рядок і стовпець від 0 до 2): ";
        cin >> row >> col;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        {
            cout << "Некоректні координати. Спробуйте знову.\n";
            continue;
        }

        if (board[row][col] != ' ')
        {
            cout << "Клітинка зайнята. Спробуйте знову.\n";
            continue;
        }

        break; // валідне введення
    }
}

// Робить хід, змінюючи значення в масиві
void MakeMove(int row, int col, char currentPlayer)
{
    board[row][col] = currentPlayer;
}

// === ГОЛОВНИЙ ЦИКЛ ===

int main()
{
    cout << "=== Хрестики-Нулики — Етап 02: Функції ===\n";

    InitBoard();
    char currentPlayer = 'X';

    while (true)
    {
        PrintBoard();

        int row, col;
        AskMove(row, col, currentPlayer);
        MakeMove(row, col, currentPlayer);

        if (IsWin(currentPlayer))
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

        // Зміна гравця
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "=== Кінець гри ===\n";
    return 0;
}
