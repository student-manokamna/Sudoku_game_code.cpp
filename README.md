# 🧩 Sudoku_Game

### 🔍 A Simple Yet Powerful Sudoku Solver in C++

This is a lightweight **9x9 Sudoku solver** built using **backtracking and recursion**. Just input a partially filled grid and let the algorithm do the thinking for you!

---

## 🛠️ Features

- ✅ Solves any valid **9x9 Sudoku puzzle**
- 📋 **Displays** the puzzle before & after solving
- 🔄 Uses **backtracking + recursion** for efficient solving
- 🎨 **ASCII-formatted grid** for clean console output
- 🚫 Detects unsolvable puzzles and notifies the user

---

## 👨‍💻 How It Works

The core logic uses **depth-first search (DFS)** and **backtracking** to fill the empty cells by trying all numbers from 1 to 9 while checking validity in real-time.

```cpp
bool isSafe(int row, int col, int num);
bool solveSudoku();
