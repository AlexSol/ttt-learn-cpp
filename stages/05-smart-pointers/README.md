# 🧩 Етап 05 — Smart Pointers (RAII)

У цьому етапі ми демонструємо **управління памʼяттю в C++** за допомогою `std::unique_ptr`.

Мета — перейти від **ручного управління обʼєктами** до **RAII-підходу (Resource Acquisition Is Initialization)**, який робить програму безпечнішою та чистішою.

---

## 🎯 Мета етапу

- Створити гру динамічно через `std::unique_ptr<Game>`
- Пояснити ідею RAII — автоматичне очищення ресурсів
- Підготуватись до більш складних сценаріїв, де передача володіння має значення

---

## 📖 Теоретичне підґрунтя

- 📘 **Стівен Прата – C++ Primer Plus**
  - Глава 10–11: *Динамічна памʼять, new/delete*
  - Глава 12: *Концепт RAII і класи-обгортки*

- 📗 **Ліппман – C++ Primer**
  - Chapter 12: *Dynamic Memory and Smart Pointers*
  - Chapter 13: *Resource Management*

---

## 📂 Файли

```bash
📁 stages/05-smart-pointers/
├── main.cpp
└── README.md


Що змінено
Було	Стало
Game game;	std::unique_ptr<Game> game = make_unique<Game>();
Обʼєкт створено на стеку	Обʼєкт живе в купі (heap)
Ручне видалення (немає)	Автоматичне очищення (RAII)