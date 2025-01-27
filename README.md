# Inverted-Search-Engine
This project creates an inverted index for a collection of .txt files, where each word is mapped to the files containing it and the number of occurrences of that word in each file. The project implements several operations to manage and interact with the database, such as file insertion, updating, searching, and saving to a file.

Key Components:
Database Creation:

Scans each .txt file and builds an index where each word is associated with the files it appears in and the number of times it appears.
The index is stored in a hash table for efficient lookups.
File Insertion:

Supports adding .txt files to the database. Each file is added to a linked list, ensuring that the same file is not added twice.
Search:

Users can search for a word in the database and retrieve all files where that word appears, along with the frequency of occurrences.
Database Display:

Allows displaying the entire database of indexed words and the files they appear in.
Save and Update:

Users can save the database to a .txt file and later update it with new files.
Features:
Inverted Indexing: Each word is mapped to the files it appears in and its frequency within each file.
File Management: Add, update, and display .txt files.
Efficient Searching: Search for words and get a list of files containing them with the word count.
User-Friendly Command-Line Interface: Simple CLI for interacting with the database.
Cross-Platform: Works on any system that supports C (Linux, macOS, Windows).
Prerequisites:
Before running this project, ensure that you have the following:

C Compiler: GCC or Clang (for compiling C code)
Make (optional but recommended for easy compilation)
Text Files: The project works with .txt text files.


Installation:
To install the project, follow these steps:

Clone the repository to your local machine:
Copy
git clone https://github.com/yourusername/inverted-search-engine.git

Compile the project:
gcc -o search_engine main.c -lm
##
For execute You need to Creat text file eg.file.txt then write some words on file,
Then in command line Pass like ./a.out <File_name> dont forgot to Add Extension
Usage:
Create Database: choose 1
Display Database:       2
Search Database:        3 & Enter search <word>
Save Database:          4 & Enter <filename>
Update Database:        5 & Enter <newfile>
Example:
To create the database, display it, and search for a word:


Contributing:
Feel free to fork this repository and submit pull requests for any improvements or fixes. Contributions are welcome!
