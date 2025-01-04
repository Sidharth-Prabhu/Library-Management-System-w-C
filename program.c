#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the Book structure
typedef struct {
    int id;
    char title[100];
    char author[100];
    int isBorrowed; // 0: Available, 1: Borrowed
} Book;

// Function prototypes
void addBook();
void searchBook();
void borrowBook();
void viewAllBooks();
void saveToFile(Book books[], int count);
int loadFromFile(Book books[]);

int main() {
    int choice;
    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Borrow Book\n");
        printf("4. View All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                viewAllBooks();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new book
void addBook() {
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    if (count >= MAX_BOOKS) {
        printf("Library capacity reached! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter Book Title: ");
    getchar(); // Consume newline
    fgets(newBook.title, sizeof(newBook.title), stdin);
    strtok(newBook.title, "\n"); // Remove trailing newline
    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    strtok(newBook.author, "\n"); // Remove trailing newline
    newBook.isBorrowed = 0;

    books[count++] = newBook;
    saveToFile(books, count);
    printf("Book added successfully!\n");
}

// Function to search for a book by title
void searchBook() {
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    char searchTitle[100];
    printf("Enter Book Title to search: ");
    getchar(); // Consume newline
    fgets(searchTitle, sizeof(searchTitle), stdin);
    strtok(searchTitle, "\n"); // Remove trailing newline

    printf("\n--- Search Results ---\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(books[i].title, searchTitle) == 0) {
            printf("ID: %d, Title: %s, Author: %s, Status: %s\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].isBorrowed ? "Borrowed" : "Available");
            found = 1;
        }
    }

    if (!found) {
        printf("No book found with the title \"%s\".\n", searchTitle);
    }
}

// Function to borrow a book
void borrowBook() {
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    int bookId;
    printf("Enter Book ID to borrow: ");
    scanf("%d", &bookId);

    for (int i = 0; i < count; i++) {
        if (books[i].id == bookId) {
            if (books[i].isBorrowed) {
                printf("Book is already borrowed.\n");
            } else {
                books[i].isBorrowed = 1;
                saveToFile(books, count);
                printf("Book borrowed successfully!\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", bookId);
}

// Function to view all books
void viewAllBooks() {
    Book books[MAX_BOOKS];
    int count = loadFromFile(books);

    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Title: %s, Author: %s, Status: %s\n",
               books[i].id, books[i].title, books[i].author,
               books[i].isBorrowed ? "Borrowed" : "Available");
    }
}

// Function to save books to a file
void saveToFile(Book books[], int count) {
    FILE *file = fopen("books.dat", "wb");
    if (file == NULL) {
        printf("Error saving books to file!\n");
        return;
    }
    fwrite(books, sizeof(Book), count, file);
    fclose(file);
}

// Function to load books from a file
int loadFromFile(Book books[]) {
    FILE *file = fopen("books.dat", "rb");
    if (file == NULL) {
        return 0; // No file found, return 0
    }
    int count = fread(books, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
    return count;
}

