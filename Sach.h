#include "Statistic.h"

#define MAX_READER 100
#define MAX_BOOK 100
#define MAX_NAME_LEN 100

//Create the struct called Sach
struct Sach
{
    int bookISBN;
    char bookName[MAX_NAME_LEN];
    char authName[MAX_NAME_LEN];
    char publisher[MAX_NAME_LEN];
    int publishedYear;
    char bookType[MAX_NAME_LEN];
    int bookPrice;
    int bookAmount;
};
//Functions declaration
//7. Print out list of books in library
void PrintBook(struct Sach book[MAX_BOOK], int bookCount);
//8. Add a new book
int AddBook(struct Sach book[MAX_BOOK], int bookCount);
//9. Edit the data of book.
void EditBookInfo(struct Sach book[MAX_BOOK], int bookCount);
//10. Delete book out of library
int DeleteBook(struct Sach book[MAX_BOOK], int bookCount);
//11. Search book by ISBN number
void SearchBookByISBN(struct Sach book[MAX_BOOK], int bookCount);
//12. Search book by name
void SearchBookByName(struct Sach book[MAX_BOOK], int bookCount);
//15. Count the total number of book at this time
void BookStatistic(struct Sach book[MAX_BOOK], int bookCount);
// 16. Count the total number of book by book type
void CountBookByType(struct Sach book[MAX_BOOK], struct ThongKe statistic[MAX_READER] , int bookCount);