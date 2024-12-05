/*
Programmer: Tran Nguyen Thanh Duy - 24880013
OS: MacOS
Code editor: Visual Studio Code.
*/ 

#include <stdio.h>
#include <string.h>
#include "DocGia.h"
#include "Sach.h"
#include "Statistic.h"
#include "Ticket.h"

#define MAX_READER 100
#define MAX_BOOK 100
#define MAX_NAME_LEN 100
#define MAX_TICKET 100

int main(void)
{
	struct DocGia reader[MAX_READER];
    struct Sach book[MAX_BOOK];
	struct ThongKe statistic[MAX_READER];
	struct Ticket borrowTicker[MAX_BORROW];
	int readerCount = 0;
	int bookCount = 0;
	int borrowCount = 0;

    int opt;
	do
	{
		printf("**** Library Management Menu ***\n");
		printf(" 1.  Print out the list of readers\n");
		printf(" 2.  Add a new reader\n");
		printf(" 3.  Edit the information of reader\n");
		printf(" 4.  Delete a reader\n");
		printf(" 5.  Search readers by identication number\n");
		printf(" 6.  Search readers by name\n");
		printf(" 7.  Print out the list of books\n");
		printf(" 8.  Add a new book\n");
		printf(" 9.  Edit the information of books\n");
		printf(" 10. Delete a book\n");
		printf(" 11. Search books by ISBN\n");
		printf(" 12. Search books by name\n");
		printf(" 13. Create the borrowing books form\n");
		printf(" 14. Create the returning books form \n");
		printf(" 15. Count the number of books in the library\n");
		printf(" 16. Count the number of books by type\n");
		printf(" 17. Count the number of readers in the library\n");
		printf(" 18. Count the number of readers by gender\n");
		printf(" 19. Count number of borrowed books\n");
		printf(" 20. Count the number of reader returning books lately\n");
		printf(" 0.  Close this program\n");
		printf("=========================================================\n");
		//Checking intial input of user
		int validInput;
        do
        {
            printf("Please choose the function: ");
            validInput = scanf("%d", &opt);

            if (validInput != 1 || opt < 0) // Checking if opt is positive integer or not
            {
                printf("Invalid input. Please enter one of above listed functions!\n");
                while (getchar() != '\n'); // Delete remaining characters in the buffer to avoid infinite loop
                validInput = 0;
            }
        } while (validInput == 0);
		
		switch (opt)
		{
			case 1:
				PrintReader(reader, readerCount);
				break;
			case 2:
				readerCount = AddReader(reader, readerCount);
				break;
			case 3:
				EditReaderInfo(reader, readerCount);
				break;
			case 4:
				readerCount = DeleteReader(reader, readerCount);
				break;
			case 5:
				SearchReaderByID(reader, readerCount);
				break;
			case 6:
				SearchReaderByName(reader, readerCount);
				break;
			case 7:
				PrintBook(book, bookCount);
				break;
			case 8:
				bookCount = AddBook(book, bookCount);
				break;
			case 9:
				EditBookInfo(book, bookCount);
				break;
			case 10:
				bookCount = DeleteBook(book, bookCount);
				break;
			case 11:
				SearchBookByISBN(book, bookCount);
				break;
			case 12:
				SearchBookByName(book, bookCount);
				break;
			case 13:
				borrowCount = CreateBorrowTicket(borrowTicker, borrowCount, book, readerCount, bookCount);
				break;
			case 14:
				printf("This function is still in development phase!\n");
				break;
			case 15:
				BookStatistic(book, bookCount);
				break;
			case 16:
				CountBookByType(book, statistic, bookCount);
				break;
			case 17:
				ReaderStatistic(reader, readerCount);
				break;
			case 18:
				CountReaderByGender(reader, statistic, readerCount);
				break;
			case 19:
				printf("This function is still in development phase!\n");
				break;
			case 20:
				printf("This function is still in development phase!\n");
				break;
			case 0: 
				printf("Closing the program...Good Bye!\n");
				break;
			default:
				printf("Invalid function. Please choose agian!\n");
				break;
		}
	} while (opt != 0);
	return 0;
}
