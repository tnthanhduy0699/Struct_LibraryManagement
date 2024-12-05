#include <stdio.h>
#include <string.h>
#include "Ticket.h"

int CreateBorrowTicket(struct Ticket borrowTicket[], int borrowCount, struct Sach book[], int readerCount, int bookCount)
{
    int readerNo;
    int numBooksToBorrow;

    if (readerCount == 0 && bookCount == 0)
    {
		printf("There is no reader and book in the library!\n");
        return 0;
    }
    if (readerCount == 0)
    {
		printf("There is no reader in the library!\n");
        return 0;
    }
    if (readerNo == 0)
    {
		printf("There is no book in the library!\n");
        return 0;
    }

    printf("Enter reader number: ");
    scanf("%d", &readerNo);
    
    // Check the amount of book borrowed by reader
    int borrowedByReader = 0;
    for (int i = 0; i < borrowCount; i++)
    {
        if (borrowTicket[i].readerNo == readerNo)
        {
            borrowedByReader++;
        }
    }

    if (borrowedByReader >= MAX_BORROW)
    {
        printf("This reader has already borrowed 3 books and cannot borrow more.\n");
        return borrowCount;
    }

    printf("Enter the number of books to borrow (1-3): ");
    scanf("%d", &numBooksToBorrow);
    
    if (numBooksToBorrow < 1 || numBooksToBorrow > MAX_BORROW || borrowedByReader + numBooksToBorrow > MAX_BORROW)
    {
        printf("Invalid number of books. Each reader can borrow up to 3 books.\n");
        return borrowCount;
    }

    for (int j = 0; j < numBooksToBorrow; j++)
    {
        int bookID;
        printf("Enter book ISBN for book %d: ", j + 1);
        scanf("%d", &bookID);

        // Check the book is existed and borrowed or not?
        int bookFound = 0, alreadyBorrowed = 0;
        for (int k = 0; k < bookCount; k++)
        {
            if (book[k].bookISBN == bookID)
            {
                bookFound = 1;
                // Check the input book is borrowed or not
                for (int i = 0; i < borrowCount; i++)
                {
                    if (borrowTicket[i].bookID == bookID)
                    {
                        alreadyBorrowed = 1;
                        break;
                    }
                }
                break;
            }
        }

        if (bookFound == 0)
        {
            printf("Book with ISBN %d does not exist in the library.\n", bookID);
            j--;
            continue;
        }

        if (alreadyBorrowed == 1)
        {
            printf("Book with ISBN %d has already been borrowed.\n", bookID);
            j--;
            continue;
        }

        do {
        printf("Enter borrowing date: ");
        scanf("%d", &borrowTicket[borrowCount].borrowDate);
        if (borrowTicket[borrowCount].borrowDate < 1 || borrowTicket[borrowCount].borrowDate > 31)
        {
            printf("Invalid date. Please enter again!\n");
        }
        } while (borrowTicket[borrowCount].borrowDate < 1 || borrowTicket[borrowCount].borrowDate > 31);
	    //Month of birth cannot be smaller than 1 and greater than 12
        do {
        printf("Enter borroing month: ");
        scanf("%d", &borrowTicket[borrowCount].borrowMonth);
        if (borrowTicket[borrowCount].borrowMonth < 1 || borrowTicket[borrowCount].borrowMonth > 12)
        {
            printf("Invalid month. Please enter again!\n");
        }
         } while (borrowTicket[borrowCount].borrowMonth < 1 || borrowTicket[borrowCount].borrowMonth > 12);
	    //Year of birth cannot be smaller than 1900 and greater than 2024
        do {
        printf("Enter borrowing year: ");
        scanf("%d", &borrowTicket[borrowCount].borrowYear);
        if (borrowTicket[borrowCount].borrowYear < 1900 || borrowTicket[borrowCount].borrowYear > 2024)
        {
            printf("Invalid year. Please enter again!\n");
        }
         } while (borrowTicket[borrowCount].borrowYear < 1900 || borrowTicket[borrowCount].borrowYear > 2024);

        //Calculate the expected return date
        int tempDate = borrowTicket[borrowCount].borrowDate + 7;
        int tempMonth = borrowTicket[borrowCount].borrowMonth;
        int tempYear = borrowTicket[borrowCount].borrowYear;

        if (tempDate > 31)
        {
            tempDate = tempDate - 31;
            tempMonth++;
        }
        if (tempMonth > 12)
        {
            tempMonth = tempMonth - 12;
            tempYear++;
        }

        borrowTicket[borrowCount].readerNo = readerNo;
        borrowTicket[borrowCount].bookID = bookID;
        borrowTicket[borrowCount].returnDay = tempDate;
        borrowTicket[borrowCount].returnMonth = tempMonth;
        borrowTicket[borrowCount].returnYear = tempYear;

        // Increase the ticket amount
        borrowCount++;
        printf("Book with ISBN %d has been successfully borrowed.\n", bookID);
    }

    printf("+-----------+----------+------------------+------------------+\n");
    printf("| Reader No | Book ISBN| Borrowed Date    | Expected Return  |\n");
    printf("+-----------+----------+------------------+------------------+\n");
    for (int i = 0; i < borrowCount; i++)
    {
        printf("| %-9d | %-8d | %02d/%02d/%04d       | %02d/%02d/%04d       |\n",
               borrowTicket[i].readerNo,
               borrowTicket[i].bookID,
               borrowTicket[i].borrowDate,
               borrowTicket[i].borrowMonth,
               borrowTicket[i].borrowYear,
               borrowTicket[i].returnDay,
               borrowTicket[i].returnMonth,
               borrowTicket[i].returnYear);
    }
    printf("+-----------+----------+------------------+------------------+\n");

    return borrowCount;
}
