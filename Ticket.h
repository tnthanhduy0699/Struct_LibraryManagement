#include "Sach.h"

#define MAX_READER 100
#define MAX_BOOK 100
#define MAX_NAME_LEN 100
#define MAX_BORROW 3
#define MAX_TICKET 100


#ifndef TICKET_H
#define TICKET_H

struct Ticket
{
    int readerNo; 
    int bookID; 
    int borrowDate;
    int borrowMonth;
    int borrowYear;
    int returnDay;
    int returnMonth;
    int returnYear;
};

#endif

//Dinh Nghia ham
int CreateBorrowTicket(struct Ticket borrowTicker[], int borrowCount, struct Sach book[], int readerCount, int bookCount);