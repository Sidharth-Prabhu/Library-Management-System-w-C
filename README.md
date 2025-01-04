# Library Management System

## Aim
To design a system to manage library books and members using structures and file handling. The system will support features for adding, searching, and borrowing books.

---

## Algorithm

### Step 1: Define Structures
- Create two structures:
  - `Book` with fields:
    - `id` (integer): Book ID.
    - `title` (string): Book title.
    - `author` (string): Author name.
    - `isBorrowed` (integer): 0 for available, 1 for borrowed.
  - `Member` with fields:
    - `id` (integer): Member ID.
    - `name` (string): Member name.

### Step 2: Display Menu
- Provide the user with options:
  1. Add Book
  2. Search Book
  3. Borrow Book
  4. View All Books
  5. Exit

### Step 3: Add Book
- Prompt the user for book details (ID, title, author).
- Append the new book to `books.dat` for persistent storage.

### Step 4: Search Book
- Prompt the user for a book title.
- Read records from `books.dat` and display matching results.

### Step 5: Borrow Book
- Prompt the user for a book ID.
- Check if the book is available.
- Update the `isBorrowed` field to mark it as borrowed and save changes to the file.

### Step 6: View All Books
- Display all books with their status (Available/Borrowed).

### Step 7: Exit
- Terminate the program.

---

## Sample Run
```
--- Library Management System ---
1. Add Book
2. Search Book
3. Borrow Book
4. View All Books
5. Exit
Enter your choice: 1
Enter Book ID: 1
Enter Book Title: Harry Potter
Enter Author Name: JK Rowling
Book added successfully!

--- Library Management System ---
1. Add Book
2. Search Book
3. Borrow Book
4. View All Books
5. Exit
Enter your choice: 4

--- Library Books ---
ID: 1, Title: Harry Potter, Author: JK Rowling, Status: Available

--- Library Management System ---
1. Add Book
2. Search Book
3. Borrow Book
4. View All Books
5. Exit
Enter your choice: 3
Enter Book ID to borrow: 1
Book borrowed successfully!

--- Library Management System ---
1. Add Book
2. Search Book
3. Borrow Book
4. View All Books
5. Exit
Enter your choice: 2
Enter Book Title to search: Harry Potter

--- Search Results ---
ID: 1, Title: Harry Potter, Author: JK Rowling, Status: Borrowed

--- Library Management System ---
1. Add Book
2. Search Book
3. Borrow Book
4. View All Books
5. Exit
Enter your choice: 5
Exiting program...
```
