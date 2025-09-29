#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

typedef struct Book {
    char title[100];
    float price;
    int pages;
    char language[30];
    float weight;   
    int year;
    struct Book* next;
} Book;

Book* createBook(const char* title, float price, int pages, 
                 const char* language, float weight, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

void appendBook(Book** head, const char* title, float price, int pages, 
                const char* language, float weight, int year) {
    Book* newBook = createBook(title, price, pages, language, weight, year);
    if (*head == NULL) {
        *head = newBook;
    } else {
        Book* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

void printBooks(Book* head) {
    Book* temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("%d) \"%s\"\n", i, temp->title);
        printf("   Cost: %.2f UAH\n", temp->price);
        printf("   Pages: %d\n", temp->pages);
        printf("   Language: %s\n", temp->language);
        printf("   Weight: %.1f g.\n", temp->weight);
        printf("   Year of publication: %d\n\n", temp->year);
        temp = temp->next;
        i++;
    }
}

void freeList(Book* head) {
    Book* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    Book* library = NULL;

    appendBook(&library, "Harry Potter and the Philosopher's Stone", 250.0, 320, "Ukrainian", 400.0, 1997);
    appendBook(&library, "Harry Potter and the Chamber of Secrets", 270.0, 352, "Ukrainian", 420.0, 1998);
    appendBook(&library, "Harry Potter and the Prisoner of Azkaban", 300.0, 435, "Ukrainian", 500.0, 1999);
    appendBook(&library, "Harry Potter and the Goblet of Fire", 350.0, 640, "Ukrainian", 750.0, 2000);
    appendBook(&library, "Harry Potter and the Order of the Phoenix", 400.0, 870, "Ukrainian", 900.0, 2003);
    appendBook(&library, "Harry Potter and the Half-Blood Prince", 380.0, 652, "Ukrainian", 800.0, 2005);
    appendBook(&library, "Harry Potter and the Deathly Hallows", 420.0, 704, "Ukrainian", 850.0, 2007);

    printf("Harry Potter book series:\n\n");
    printBooks(library);

    freeList(library);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
