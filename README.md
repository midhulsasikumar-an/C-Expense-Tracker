# C-Expense-Tracker
C-based Expense Tracker: Add, view, update, delete, and calculate your daily expenses with persistent storage.

A simple Expense Tracker built in C that allows users to manage their daily expenses using file handling. All data is stored persistently in a text file.

Features

Add Expense – Record a new expense with item name and amount.

View Expenses – Display all recorded expenses.

Update Expense – Modify an existing expense entry.

Delete Expense – Remove an expense entry.

Calculate Total Expense – View the total of all recorded expenses.

File Handling – All data is stored permanently in ExpenseTracker.txt.

How It Works

The program uses a struct to store expense details (item name and amount).

File operations (fopen, fprintf, fscanf, fclose) are used to read/write data.

Users can perform CRUD operations: Create, Read, Update, Delete.

A menu-driven interface allows easy navigation.

Installation

Clone the repository:

git clone https://github.com/midhulsasikumar-an/c-programming.git


Navigate to the project folder:

cd c-programming/ExpenseTracker


Compile the program:

gcc ExpenseTracker.c -o ExpenseTracker


Run the program:

./ExpenseTracker

Usage

Add Expense: Enter the item name and amount.

View Expenses: See a list of all expenses stored in the file.

Update/Delete Expense: Select the item number to modify or remove.

Total Expense: Shows the sum of all recorded expenses.

Project Structure
ExpenseTracker/
├── ExpenseTracker.c       # Main C program file
├── ExpenseTracker.txt     # File storing expense data (created automatically)
└── README.md             # Project documentation

Technologies Used

Programming Language: C

Concepts: File handling, structs, arrays, loops, functions

License

This project is open-source and free to use.
