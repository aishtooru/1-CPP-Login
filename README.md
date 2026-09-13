# Simple CLI Login & Registration System (C++)

A lightweight command-line authentication system built with C++. User credentials and account records are managed locally using C++ file streams (`fstream`).

## Features
* **User Registration (Sign Up):** Create a new account with a username, email, and password.
* **Authentication (Login):** Validate existing user credentials from the database file.
* **Password Recovery (Forgot Password):** Retrieve account credentials by verifying matching username and email.
* **Local Persistence:** Stores account records in a local text file (`login.txt`).

## Tech Stack
* **Language:** C++ (C++20)
* **Compiler:** MinGW-w64 / GCC (`g++`)

## OS
Windows

## Getting Started

### Prerequisites
Ensure `g++` is installed and added to your system's environment `PATH`.

### Build & Run
1. Open a terminal inside the project directory.
2. Compile the source code:
   ```powershell
   g++ -std=c++20 login.cpp -o login.exe
3. Run the code:
   ```powershell
   .\login.exe
