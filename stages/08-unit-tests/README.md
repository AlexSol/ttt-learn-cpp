# 🧩 Етап 08 — Unit Tests з GoogleTest

✅ додається GoogleTest
✅ покриваються методи IsWin() та IsDraw()
✅ структура модульна, як і в 07-modular-code




Цей етап демонструє, як додати **юніт-тестування** для гри "Хрестики-Нулики" за допомогою **GoogleTest**.

---

## 🎯 Мета етапу

- Навчитися писати прості тести
- Перевірити логіку перемоги (`IsWin()`) та нічиєї (`IsDraw()`)
- Почати використовувати GoogleTest у проєкті

---

## 📖 Теоретичне підґрунтя

- GoogleTest — популярний фреймворк для тестування C++
- RAII, класові методи, структура `Arrange → Act → Assert`

---

## 📂 Файли

```bash
📁 stages/08-unit-tests/
├── game.hpp         # Основна логіка гри
├── game.cpp
├── main.cpp         # Консольна гра
├── game_tests.cpp   # Тести на базові методи
└── CMakeLists.txt   # (або Makefile)


⚙️ Як зібрати
Варіант 1: через CMake (рекомендовано)
```sh
mkdir build && cd build
cmake ..
make
./GameTests

```

Варіант 2: вручну з g++
```sh
g++ game.cpp game_tests.cpp -o GameTests -std=c++17 -lgtest -lgtest_main -pthread
./GameTests

```
❗ Потрібно встановити GoogleTest (sudo apt install libgtest-dev або збирання з вихідного коду)


Що перевіряється
Тест	Що перевіряє
WinHorizontal	3 символи в одному рядку — перемога
WinDiagonal	Символи на діагоналі — перемога
DrawCondition	Всі клітинки заповнені — нічия