
struct library
{
    char title[100];
    char author[100];
    char ISBN[13];
};

void AddBook(library libraryAdd[20], int position);
void print(library libraryView[20], int size);
void removeBook(library libraryRemove[20], int size);
int numberOfBooks(library libraryCount[20], int size);