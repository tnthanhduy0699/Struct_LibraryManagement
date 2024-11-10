#include "Statistic.h"

#define MAX_READER 100
#define MAX_NAME_LEN 100

//Create the struct called DocGia
struct DocGia
{
    int readerNo;
    char readerName[MAX_NAME_LEN];
    char readerID[MAX_NAME_LEN];
    int readerBirthDate;
    int readerBirthMonth;
    int readerBirthYear;
    char readerGender[MAX_READER];
    char readerEmail[MAX_READER];
    char readerLocation[MAX_READER];
    int libraryCardDate;
    int libraryCardMonth;
    int libraryCardYear;
    int expiredCardDate;
    int expiredCardMonth;
    int expiredCardYear;
};
//Functions declaration
//1. Print the list of reader
void PrintReader(struct DocGia reader[MAX_READER], int readerCount);
//2. Add a new reader
int AddReader(struct DocGia reader[MAX_READER], int readerCount);
//3. Edit the data of reader.
void EditReaderInfo(struct DocGia reader[MAX_READER], int readerCount);
//4. Delete reader out of database
int DeleteReader(struct DocGia reader[MAX_READER], int readerCount);
//5. Search reader by identification number
void SearchReaderByID(struct DocGia reader[MAX_READER], int readerCount);
//6. Search reader by name
void SearchReaderByName(struct DocGia reader[MAX_READER], int readerCount);
//17. Count the total number of reader at this time
void ReaderStatistic(struct DocGia reader[MAX_READER], int readerCount);
//18. Count the number of reader by gender
void CountReaderByGender(struct DocGia reader[MAX_READER], struct ThongKe statistic[MAX_READER] , int readerCount);