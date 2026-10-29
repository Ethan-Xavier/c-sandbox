# 🛒 Simple Cashier & Receipt Generator

A minimalist command-line interface (CLI) application built in C that simulates a store checkout system. It dynamically tracks items, prices, and quantities to calculate an itemized receipt with tax.

## 🌟 Features
* **Dynamic Item Entry:** Allocates memory on the fly based on exactly how many items you need to process.
* **Input Sanitization:** Automatically strips trailing newline characters from text inputs for clean receipt printing.
* **Formatted Billing:** Calculates subtotal, applies a flat 5% sales tax, and prints an aligned, itemized receipt.
* **Safe Memory Management:** Implements complete manual cleanup (`free`) to guarantee zero memory leaks.

## 🛠️ Tech Stack
* **Language:** C (Standard C99/C11)
* **Core Concepts:** Dynamic Memory Allocation (`malloc`), Pointers, File I/O Buffering (`fgets`/`getchar`).

## 🚀 Getting Started

### Prerequisites
You only need a standard C compiler (like `gcc` or `clang`) installed on your system.

### Installation & Setup

1. **Clone or download the repository:**
   ```bash
   git clone https://github.com
   cd simple-cashier-c
   ```

2. **Compile the program:**
   ```bash
   gcc main.c -o cashier
   ```

3. **Run the executable:**
   ```bash
   ./cashier
   ```

## 💡 Usage Example

```text
--- CASHIER ---
Enter the number of items you want to buy: 2
Enter the name of item #1: Apple
Enter the name of item #2: Bread
------------------------------------------
Enter the price of item #1: \$1.20
Enter the price of item #2: \$2.50
------------------------------------------
Enter the quantity of item #1: #3
Enter the quantity of item #2: #1
------------------------------------------

--- RECEIPT ---
1. Apple       x3  @ \$1.20  = \$3.60
2. Bread       x1  @ \$2.50  = \$2.50

Subtotal: \$6.10
Tax (%5): \$0.31
Total Bill: \$6.41
------------------------------------------
```
