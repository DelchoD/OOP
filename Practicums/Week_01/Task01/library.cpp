#include <iostream>
#include<cstring>
#include "library.h"

void AddBook(library libraryAdd[20],int position)
{
    std::cout << "Enter title to add: ";
    std::cin >> libraryAdd[position-1].title;
    std::cout << "Enter author: ";
    std::cin >> libraryAdd[position - 1].author;
    std::cout << "Enter ISBN: ";
    std::cin >> libraryAdd[position - 1].ISBN;
}

void removeBook(library libraryRemove[20],int size)
{
    char ISBNToRemove[13];
    std::cout << "Enter ISBN to remove: ";
    std::cin >> ISBNToRemove;
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(libraryRemove[i].ISBN, ISBNToRemove))
        {
            libraryRemove[i].author[0] = '\0';
            libraryRemove[i].title[0] = '\0';
            libraryRemove[i].ISBN[0] = '\0';
        }
    }
}
void print(library libraryView[20],int size)
{
    for (int i = 0; i < size; i++)
    {
        if (libraryView[i].ISBN[0] != '\0')
        {
            std::cout << libraryView[i].title << " " << libraryView[i].author << " " << libraryView[i].ISBN << std::endl;
        }
    }

}
int numberOfBooks(library libraryCount[20],int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
       if (libraryCount[i].ISBN[0]!='\0')
       {
           count++;
       }
    }
    return count;
}