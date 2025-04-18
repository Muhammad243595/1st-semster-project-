# Parking Management System

A robust, console‑based Parking Management System written in modern C++ (C++11+).  
Provides secure user authentication, intuitive parking‑lot operations, and persistent data storage.

---

## Table of Contents

1. [Overview](#overview)  
2. [Features](#features)  
3. [Tech Stack & Dependencies](#tech-stack--dependencies)  
4. [Architecture](#architecture)  
5. [Prerequisites](#prerequisites)  
6. [Installation & Build](#installation--build)  
7. [Usage](#usage)  
8. [Configuration](#configuration)  
9. [Project Structure](#project-structure)  
10. [Contributing](#contributing)  
11. [License](#license)  
12. [Contact](#contact)  

---

## Overview

The **Parking Management System** is a command‑line application designed to simplify day‑to‑day parking‑lot administration. It allows administrators to:

- **Register** new users and store credentials securely  
- **Authenticate** returning users with masked password entry  
- **View** real-time occupancy for up to *N* spots  
- **Park** vehicles in the first available slot  
- **Remove** vehicles by specifying their spot number  
- **Persist** all data between sessions to plain‑text files  

By keeping dependencies minimal and code modular, this project is ideal for learning fundamental C++ file I/O, user input handling, and simple data persistence.

---

## Features

- **User Management**  
  - Create and store usernames/passwords (masked input)  
  - Retry on failed login or exit gracefully  
- **Parking Operations**  
  - Display layout in configurable rows  
  - Auto‑assign first free spot or remove by index  
- **Data Persistence**  
  - `users.txt`: Stores `username password` pairs  
  - `parkingData.txt`: Stores one line per spot (`Empty` or vehicle ID)  
  - Automatic load on startup and save on exit  
- **Extensibility**  
  - Change total spots or row size via constants  
  - Easily switch to JSON or database backends  

---

## Tech Stack & Dependencies

- **Language**: C++ (C++11 or higher)  
- **Standard Library**: `<iostream>`, `<fstream>`, `<string>`, `<vector>`  
- **Platform‑Specific**: `<conio.h>` (Windows `_getch()`); for POSIX, replace with `termios`‑based input  
- **Build Tools**: `g++`, `clang++`, or MSVC

---


1. **CLI Layer** (`main.cpp`)  
2. **Business Logic** (parking operations)  
3. **Data Layer** (file I/O for users & parking)

---

## Prerequisites

- A development environment supporting C++11 or newer  
- On **Windows**: ensure `<conio.h>` is available (e.g. MSVC, MinGW)  
- On **Linux/macOS**: modify password input to use `termios` or remove masking  
- Git (for cloning)  

---

## Installation & Build


1. **CLI Layer** (`main.cpp`)  
2. **Business Logic** (parking operations)  
3. **Data Layer** (file I/O for users & parking)

---

## Prerequisites

- A development environment supporting C++11 or newer  
- On **Windows**: ensure `<conio.h>` is available (e.g. MSVC, MinGW)  
- On **Linux/macOS**: modify password input to use `termios` or remove masking  
- Git (for cloning)  

---

## Installation & Build

# 1. Clone the repository
git clone https://github.com/yourusername/parking-management-system.git
cd parking-management-system

# 2. Build with DEV c++

#    - On Windows (MinGW/MSVC)
g++ -std=c++11 main.cpp -o ParkingSystem.exe

#    - On Linux/macOS
g++ -std=c++11 main.cpp -o ParkingSystem
