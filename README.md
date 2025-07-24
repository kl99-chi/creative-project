# Creative Project: Top 10 Popular Anime List Manager

This repository contains a C++ console application designed to read, display, and sort a list of the top 10 most popular anime. The program reads anime data from a text file (`animeList.txt`) and provides functionalities to sort the list based on various criteria.

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [How It Works](#how-it-works)
- [File Structure](#file-structure)
- [Local Setup Instructions](#local-setup-instructions)
- [Usage](#usage)
- [Development Environment](#development-environment)
- [Contact](#contact)

## Project Overview

This project serves as a practical demonstration of C++ programming skills, including file I/O, data structures (likely arrays or vectors of structs/classes), and sorting algorithms. It provides a simple command-line interface for interacting with the anime data.

## Features

-   **Read Anime Data:** Reads the top 10 most popular anime entries from `animeList.txt`.
-   **Display List:** Shows the current list of anime with their details.
-   **Sort by Name:** Sorts the anime list alphabetically by name.
-   **Sort by Year of Release:** Sorts the anime list by their release year (ascending/descending).
-   **Sort by Ratings:** Sorts the anime list based on their ratings (e.g., from highest to lowest).

## How It Works

The program:
1.  Loads anime data from `animeList.txt` into an in-memory data structure (e.g., a `std::vector` of `Anime` objects/structs). Each line in `animeList.txt` is expected to represent one anime entry, with fields like name, year, and rating separated by a delimiter (e.g., comma, tab).
2.  Presents a menu to the user for displaying the list or choosing a sorting option.
3.  Implements sorting algorithms (e.g., Bubble Sort, Insertion Sort, Merge Sort, or `std::sort` with custom comparators) to reorder the anime list based on the user's selection.
4.  Displays the sorted list to the console.

## File Structure

creative-project/
├── .cbp                 # Code::Blocks project file
├── main.cpp             # Main C++ source code for the application
├── animeList.txt        # Text file containing the list of anime data
└── README.md            # This README file


## Local Setup Instructions

To set up and run this C++ project using Code::Blocks:

1.  **Prerequisites:**
    * **Code::Blocks IDE:** Download and install Code::Blocks from its official website ([https://www.codeblocks.org/](https://www.codeblocks.org/)). Ensure it's installed with a C++ compiler (like MinGW/GCC).

2.  **Clone the repository:**
    ```bash
    git clone https://github.com/kl99-chi/creative-project.git
    ```
    (This URL uses your specific GitHub username and repository name.)

3.  **Navigate to the project directory:**
    ```bash
    cd creative-project
    ```

4.  **Open the project in Code::Blocks:**
    * Launch Code::Blocks.
    * Go to `File` > `Open...` or `Open project...`.
    * Navigate to the `creative-project` directory you just cloned and select the `.cbp` file (e.g., `45541442_CreativeProject.cbp`).

5.  **Ensure `animeList.txt` is present:**
    * Make sure the `animeList.txt` file is located in the same directory as your `main.cpp` or in a location accessible by your program's file I/O logic. A sample format for `animeList.txt` might be:
        ```
        Attack on Titan,2013,9.0
        Death Note,2006,8.6
        Fullmetal Alchemist: Brotherhood,2009,9.1
        ...
        ```

6.  **Build and Run:**
    * In Code::Blocks, go to `Build` > `Build and Run` (or press `F9`). This will compile your C++ code and execute the program in a console window.

## Usage

Once the program is running, follow the on-screen prompts in the console. You will typically be presented with options to:
-   Display the current anime list.
-   Sort the list by name.
-   Sort the list by year of release.
-   Sort the list by ratings.
-   Exit the program.

## Development Environment

-   **IDE:** Code::Blocks
-   **Compiler:** GNU GCC Compiler
-   **Language:** C++

## Contact

For any questions or inquiries regarding this project, please contact:
-   **Keletso Ramothibe:** keletsoramothibe99@gmail.com
-   **GitHub:** [https://github.com/kl99-chi](https://github.com/kl99-chi)
-   **LinkedIn:** [https://www.linkedin.com/in/keletso-ramothibe-793583376](https://www.linkedin.com/in/keletso-ramothibe-793583376)

---
© 2025 Keletso Ramothibe. All rights reserved.
