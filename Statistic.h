#define MAX_READER 100
#define MAX_BOOK 100
#define MAX_NAME_LEN 100

#ifndef STATISTIC_H  // Checking STATISTIC_H is define or not?
#define STATISTIC_H  // If NO, define it
struct ThongKe
{
    char typeGender[MAX_READER];
    int genderAmount;
    char typeBook[MAX_BOOK];
    int typeAmount;
};

#endif // End guard
