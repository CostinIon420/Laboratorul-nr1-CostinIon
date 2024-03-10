#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct library
{int book_size_as_in_pages;
char author_surname[200];
char title[200];
char author_name[200];
int number_of_books;
} library;
void read_vector (library b[100], int n)
{for (int i= 0; i< n; i++)
{printf("Insert some information about the book: \n");
printf("The title>  ");
scanf("%s", &b[i].title);
printf("The name of the author>  ");
scanf("%s", &b[i].author_name);
printf("The surname of the author>  ");
scanf("%s", &b[i].author_surname);
printf("Number of pages>  ");
scanf("%d", &b[i].book_size_as_in_pages); }}
void show_vector  (library b[100], int n)
{for (int i= 0; i< n;i++)
{printf("The book '%s' is written by %s %s, and has %d pages !\n", b[i].title, b[i].author_name, b[i].author_surname,b[i].book_size_as_in_pages );  }}

void find_a_book(library b[100], int n)
{char key[200];
printf("Insert the name of the book you are looking for> \n");
scanf("%s", &key);
for (int i= 0; i< n; i++)
{if(strcmp(key, b[i].title) == 0)
{printf ("The book named '%s' is located on the %d position.", b[i].title, i+1);  }} }
int main ()
{int number_of_books;
printf ("Insert the number of books you want to have in the system > ");
scanf ("%d", &number_of_books);
library b[number_of_books];
read_vector( b, number_of_books);
show_vector (b, number_of_books);
find_a_book(b ,number_of_books); }

