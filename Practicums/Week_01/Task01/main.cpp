#include "library.cpp"
#include<iomanip>
int main()
{
    

    library Library[20];
    int size,i,choice;

    std::cout << "Enter size: ";
    std::cin >> size;

    for (i = 0; i < size; i++)
    {
        std::cout << "Enter title to add: ";
        std::cin >> Library[i].title;
        std::cout << "Enter author: ";
        std::cin >> Library[i].author;
        std::cout << "Enter ISBN: ";
        std::cin >> Library[i].ISBN;
    }

    do
    {
        std::cout << std::endl;
        std::cout << "            Main menu: " << std::endl;
        std::cout << "Enter 1 to add a new book, 2 to remove a book, 3 to display the number of books, 4 to display them and 0 to exit: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            AddBook(Library, i + 1);
            size = size + 1;
            break;
        case 2:
            removeBook(Library,size);
            break;
        case 3:
            std::cout <<"The total number of real books is: "<< numberOfBooks(Library, size)<<std::endl;
            break;
        case 4:
            print(Library, size);
            break;
        default:
            break;
        }
    } 
    while (choice!=0);


    

}