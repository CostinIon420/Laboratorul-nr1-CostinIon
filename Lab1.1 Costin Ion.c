#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
struct element
{int value;
};
void read(struct element **table, int *n)
{printf("Insert the number of elements you want in your table: ");
scanf("%d", n);
*table = (struct element *)malloc(*n * sizeof(struct element));
for (int i = 0; i < *n; i++)
{printf("Insert the value of the %d element: ", i + 1);
scanf("%d", &(*table)[i].value);}}

void show(struct element *table, int n)
{printf("The table's elemets are: ");
for (int i = 0; i < n; i++)
{
printf("%d ", table[i].value);}
printf("\n");}

int search(struct element *table, int n, int val)
{
for (int i = 0; i < n; i++)
{if (table[i].value == val)
{return i; }}        return -1;}

void free_memory(struct element *table) {
  free(table);
}

void sort_element(struct element *table, int n)
{for (int i = 0; i < n - 1; i++)
{for (int j = i + 1; j < n; j++)
{if (table[i].value > table[j].value)
{struct element temp = table[i];
table[i] = table[j];
table[j] = temp;  }}} }

void insert_at_the_end(struct element **table, int *n, int val)
{(*n)++;
*table = (struct element *)realloc(*table, *n * sizeof(struct element));
(*table)[*n - 1].value = val;  }


void insert_at_start(struct element **table, int *n, int val)
{(*n)++;
*table = (struct element *)realloc(*table, *n * sizeof(struct element));
for (int i = *n - 1; i > 0; i--)
{(*table)[i] = (*table)[i - 1]; }
(*table)[0].value = val;}

void insert_at_position_given(struct element **table, int *n, int val, int position)
{(*n)++;
*table = (struct element *)realloc(*table, *n * sizeof(struct element));
for (int i = *n - 1; i > position; i--)
{(*table)[i] = (*table)[i - 1]; }
(*table)[position].value = val;}

void delete_position_given(struct element **table, int *n, int position)
{for (int i = position; i < *n - 1; i++)
{(*table)[i] = (*table)[i + 1]; }
(*n)--;
*table = (struct element *)realloc(*table, *n * sizeof(struct element));}

int main()
{int option, position, val;
int n = 0;
struct element *table = NULL;

do
{
printf("\nMenu:\n");
printf("1. I want to insert the element(s) of the table\n");
printf("2. I want to see all the elemets inserted in the table so far\n");
printf("3. I want to search an element with the value of a field for the structure\n");
printf("4. I want to free the table's memory (delete all elements)\n");
printf("5. I want to sort the elements within the table after a structure's field\n");
printf("6. I want to insert a new element at the end of the table\n");
printf("7. I want to insert a new element at the start of the table\n");
printf("8. I want to insert an element at an X position within the table\n");
printf("9. I want to delete an element from an X position from within the table\n");
printf("10. I want to end it all\n\n");
printf("What now? ");
scanf("%d", &option);
switch (option)
{case 1:
read(&table, &n);
  break;
case 2:
show(table, n);
  break;
case 3:
printf("What's the value of the element you want to search> ");
scanf("%d", &val);
position = search(table, n, val);
if (position == -1)
{printf("The element with the %d value was not found in the table\n", val);}
else
{printf("The element with the %d value was found on the %d position\n", val, position+1);}
  break;
case 4:
free_memory(table);
  break;
case 5:
sort_element(table, n);
  break;
case 6:
printf("What's the value of your new element?  ");
scanf("%d", &val);
insert_at_the_end(&table, &n, val);
  break;
case 7:
printf("What's the value of your new element? ");
scanf("%d", &val);
insert_at_start(&table, &n, val);
  break;
case 8:
printf("What's the value of your new element? ");
scanf("%d", &val);
printf("Where do you want to insert/add your new element? ");
scanf("%d", &position);
insert_at_position_given(&table, &n, val, position);
  break;
case 9:
printf("What's the position of the element you want to delelete (!starting with position 0!): ");
scanf("%d", &position);
delete_position_given(&table, &n, position);
  break;
case 10:
free_memory(table);
printf("The End.\n");
  break;
default:
printf("Whatever you inserted - not a valid input!\n");
  break; }}                                     while (option != 10);    return 0;}
