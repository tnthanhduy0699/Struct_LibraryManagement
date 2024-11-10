#include <stdio.h>
#include <string.h>
#include "Sach.h"
#include "Statistic.h"

//7. Print out the list of book in library
void PrintBook(struct Sach book[MAX_BOOK], int bookCount)
{
    //Checking current book amount, if amount = 0, there is no book
	if (bookCount == 0)
	{
		printf("There is no book in the library!\n");
		return;
	}
    //Open the file
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Cannot open file!\n");
        return;
    }

    printf("List of books:\n");
    char temp[1000];
    while (fgets(temp, 1000, file) != NULL)
    {
        printf("%s", temp);
    }
    //Close the txt file after reading.
    fclose(file);
}
//8. Add new book, then print the data into text file.
int AddBook(struct Sach book[MAX_BOOK], int bookCount)
{
    //Checking book amount before adding a new book
    if (bookCount >= MAX_BOOK) {
        printf("Maximum limit reached. Cannot add more book!\n");
        return 0;
    }

    printf("Enter the book ISBN: ");
    scanf("%d", &book[bookCount].bookISBN);

    printf("Enter book name: ");
    getchar();
    fgets(book[bookCount].bookName, MAX_NAME_LEN, stdin);
    book[bookCount].bookName[strcspn(book[bookCount].bookName, "\n")] = '\0';
    //Maximum of CCCD is 12 digits
    printf("Enter author name: ");
	fgets(book[bookCount].authName, MAX_NAME_LEN, stdin);
	book[bookCount].authName[strcspn(book[bookCount].authName, "\n")] = '\0';

    printf("Enter publisher name: ");
	fgets(book[bookCount].publisher, MAX_NAME_LEN, stdin);
	book[bookCount].publisher[strcspn(book[bookCount].publisher, "\n")] = '\0';
    
    printf("Enter the publish year: ");
    scanf("%d", &book[bookCount].publishedYear);

    printf("Enter book type: ");
    getchar();
    fgets(book[bookCount].bookType, MAX_NAME_LEN, stdin);
    book[bookCount].bookType[strcspn(book[bookCount].bookType, "\n")] = '\0';

    printf("Enter book price: ");
    scanf("%d", &book[bookCount].bookPrice);

    printf("Enter book amount: ");
    scanf("%d", &book[bookCount].bookAmount);

    //Increase current book number after adding new book
    bookCount++;

    // Open the file in editable mode "w"
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Cannot open or create the file.\n");
        return 0;
    }
    //Print out data as table layout
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    fprintf(file, "|    No.   |        Book name         |       Author name        |        Publisher         | Published year |      Book type        |  Book price  | Book amount |\n");
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    //Add the loop to print all book data into txt file.
    for (int i = 0; i < bookCount; i++)
    {
        fprintf(file, "| %03d      | %-25s| %-24s | %-24s | %4d           | %-21s | %06d VND   | %03d         |\n",
        book[i].bookISBN,
        book[i].bookName,
        book[i].authName,
		book[i].publisher,
		book[i].publishedYear,
		book[i].bookType,
		book[i].bookPrice,
		book[i].bookAmount);
    }
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    //Close the file after editing
    fclose(file);

    printf("Add book successfully!\n");
    return bookCount;
}
//3. Edit the data of book.
void EditBookInfo(struct Sach book[MAX_BOOK], int bookCount)
{
    //Checking current book amount, if amount = 0, there is no book
    if (bookCount == 0)
	{
		printf("There is no book in the library!\n");
		return;
	}
    int index;
	printf("Enter the position of book need to be edited: ");
	scanf("%d", &index);

	if (index < 0 || index - 1 > bookCount - 1)
	{
		printf("This book is not existed!\n");
		return;
	}

	int choice;
	printf("Attribute can be edited: \n");
	printf("1. Book ISBN\n");
	printf("2. Book name\n");
	printf("3. Author name\n");
	printf("4. Publisher\n");
	printf("5. Published year\n");
	printf("6. Book type\n");
	printf("7. Book price\n");
	printf("8. Book amount \n");
	printf("Choose the attrubute need to be edited: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		//Edit book ISBN
		printf("Enter new book ISBN: ");
		scanf("%d", &book[index-1].bookISBN);
		break;
	case 2:
		//Edit book name
		printf("Enter new book name: ");
		getchar();
		fgets(book[index-1].bookName, MAX_NAME_LEN, stdin);
		book[index-1].bookName[strcspn(book[index-1].bookName, "\n")] = '\0';
		break;
	case 3:
		//Edit Author name
		printf("Enter new author name: ");
		getchar();
		fgets(book[index-1].authName, MAX_NAME_LEN, stdin);
		book[index-1].authName[strcspn(book[index-1].authName, "\n")] = '\0';
		break;
	case 4:
		//Edit publisher
		printf("Enter new publisher: ");
		getchar();
		fgets(book[index-1].publisher, MAX_NAME_LEN, stdin);
		book[index-1].publisher[strcspn(book[index-1].publisher, "\n")] = '\0';
		break;
	case 5:
		//Edit published year
		printf("Enter new published year: ");
		scanf("%d", &book[index-1].publishedYear);
		break;
	case 6:
		//Edit book type
		printf("Enter new book type: ");
		getchar();
		fgets(book[index-1].bookType, MAX_NAME_LEN, stdin);
		book[index-1].bookType[strcspn(book[index-1].bookType, "\n")] = '\0';
		break;
	case 7:
		//Edit book price
		printf("Enter new book price: ");
		scanf("%d", &book[index-1].bookPrice);
		break;
	case 8:
		//Edit book amount
		printf("Enter new book amount: ");
		scanf("%d", &book[index-1].bookAmount);
		break;
	default:
		printf("This attribute is not existed!\n");
		break;
	}
    // Update the txt file again after editing book information
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Cannot open or create the file.\n");
        return;
    }
    //Print out data as table layout
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    fprintf(file, "|    No.   |        Book name         |       Author name        |        Publisher         | Published year |      Book type        |  Book price  | Book amount |\n");
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    //Add the loop to print all book data into txt file.
    for (int i = 0; i < bookCount; i++)
    {
        fprintf(file, "| %03d      | %-25s| %-24s | %-24s | %4d           | %-21s | %06d VND   | %03d         |\n",
        book[i].bookISBN,
        book[i].bookName,
        book[i].authName,
		book[i].publisher,
		book[i].publishedYear,
		book[i].bookType,
		book[i].bookPrice,
		book[i].bookAmount);
    }
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    //Close the file after editing
    fclose(file);
    printf("Book information updated successfully in the file!\n");
}
//4. Delete book out of database
int DeleteBook(struct Sach book[MAX_BOOK], int bookCount)
{
    //Checking current book amount, if amount = 0, there is no book
    if (bookCount == 0)
	{
		printf("There is no book in the library!\n");
		return 0;
	}

	int pos;
	printf("Enter the position of book need to be deleted: ");
	scanf("%d", &pos);
	//Checking the input of user
	if (pos < 0 || pos - 1 > bookCount - 1)
	{
		printf("This book is not existed!\n");
		return 0;
	}

	for (int i = pos-1; i < bookCount - 1; i++)
	{
		book[i].bookISBN = book[i + 1].bookISBN;
		strcpy(book[i].bookName, book[i + 1].bookName);
		strcpy(book[i].authName, book[i + 1].authName);
		strcpy(book[i].publisher, book[i + 1].publisher);
		book[i].publishedYear = book[i + 1].publishedYear;
		strcpy(book[i].bookType, book[i + 1].bookType);
		book[i].bookPrice = book[i + 1].bookPrice;
		book[i].bookAmount = book[i + 1].bookAmount;
	}

	// Reduce book amount after deleting
	bookCount--;

    // Update the txt file again after editing book information
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Cannot open or create the file.\n");
        return 0;
    }
    //Print out data as table layout
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    fprintf(file, "|    No.   |        Book name         |       Author name        |        Publisher         | Published year |      Book type        |  Book price  | Book amount |\n");
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    //Add the loop to print all book data into txt file.
    for (int i = 0; i < bookCount; i++)
    {
        fprintf(file, "| %03d      | %-25s| %-24s | %-24s | %4d           | %-21s | %06d VND   | %03d         |\n",
        book[i].bookISBN,
        book[i].bookName,
        book[i].authName,
		book[i].publisher,
		book[i].publishedYear,
		book[i].bookType,
		book[i].bookPrice,
		book[i].bookAmount);
    }
    fprintf(file, "+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
    //Close the file after editing
    fclose(file);

	printf("Book is deleted. Database is updated successfully!\n");
	return bookCount;
}
//5. Search book by ISBN number
void SearchBookByISBN(struct Sach book[MAX_BOOK], int bookCount)
{
    //Checking current book amount, if amount = 0, there is no book
	if (bookCount == 0)
	{
		printf("There is no book in the library!\n");
		return;
	}
    //Open the file to search
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    int found = 0;
    int searchISBN;
    printf("Enter book ISBN number need to be searched: ");
    scanf("%d", &searchISBN);

    for (int i = 0; i < bookCount; i++)
    {
       if (book[i].bookISBN == searchISBN)
       {
        if (found == 0)
        {
            printf("+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
            printf("|    No.   |        Book name         |       Author name        |        Publisher         | Published year |      Book type        |  Book price  | Book amount |\n");
            printf("+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
        }
        
        printf("| %03d      | %-25s| %-24s | %-24s | %4d           | %-21s | %06d VND   | %03d         |\n",
        book[i].bookISBN,
        book[i].bookName,
        book[i].authName,
		book[i].publisher,
		book[i].publishedYear,
		book[i].bookType,
		book[i].bookPrice,
		book[i].bookAmount);

        //found will be increased after the ISBN is found.
        found++;
       }
    }

    if (found == 0)
    {
        printf("Cannot find any book having this ISBN: %d\n", searchISBN);
    }
    else
    {
        printf("+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
        if (found > 1)
        {
            printf("Found %d books having the same ISBN number!\n", found);
        } else
        {
            printf("Found the book!\n");
        }
    }
    //Close the file after searching completed
    fclose(file);
}
//6. Search book by name
void SearchBookByName(struct Sach book[MAX_BOOK], int bookCount)
{
    //Checking current book amount, if amount = 0, there is no book
	if (bookCount == 0)
	{
		printf("There is no book in the library!\n");
		return;
	}
    //Open the file to search
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    int found = 0;
    char searchBookName[MAX_NAME_LEN];
    printf("Enter book name need to be searched: ");
    getchar();
    fgets(searchBookName, MAX_NAME_LEN, stdin);
    searchBookName[strcspn(searchBookName, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++)
    {
       if (strcmp(book[i].bookName, searchBookName) == 0)
       {
        if (found == 0)
        {
            printf("+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
            printf("|    No.   |        Book name         |       Author name        |        Publisher         | Published year |      Book type        |  Book price  | Book amount |\n");
            printf("+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
        }
        
        printf("| %03d      | %-25s| %-24s | %-24s | %4d           | %-21s | %06d VND   | %03d         |\n",
        book[i].bookISBN,
        book[i].bookName,
        book[i].authName,
		book[i].publisher,
		book[i].publishedYear,
		book[i].bookType,
		book[i].bookPrice,
		book[i].bookAmount);

        //found will be increased after the name is found.
        found++;
       }
    }

    if (found == 0)
    {
        printf("Cannot find any book having this name: %s\n", searchBookName);
    }
    else
    {
        printf("+----------+--------------------------+--------------------------+--------------------------+----------------+-----------------------+--------------+-------------+\n");
        if (found > 1)
        {
            printf("Found %d books having the same name!\n", found);
        } else
        {
            printf("Found the book!\n");
        }
    }
    //Close the file after searching completed
    fclose(file);
}
//15. Count the total number of book at this time
void BookStatistic(struct Sach book[MAX_BOOK], int bookCount)
{
    //Checking current book amount, if amount = 0, there is no book
	if (bookCount == 0)
	{
		printf("There is no book in the library!\n");
		return;
	}

	printf("Total number of book: %d\n", bookCount);
	//Call the function PrintBook again to show the detail as table view.
	PrintBook(book, bookCount);
}
// 16. Count the total number of book by book type
void CountBookByType(struct Sach book[MAX_BOOK], struct ThongKe statistic[MAX_READER] , int bookCount)
{
	int typeCount = 0;

	for (int i = 0; i < bookCount; i++)
	{
		int found = 0;
		// Check that bookType is existed in statistic[j].typeBook or not? If YES, increase the statistic[j].typeAmount
        for (int j = 0; j < typeCount; j++)
		{
			if (strcmp(book[i].bookType, statistic[j].typeBook) == 0)
			{
				statistic[j].typeAmount ++;
				found = 1;
				break;
			}
		}
		// if NO, add book[i].bookType into statistic.typeBook
        if (found == 0)
		{
			strcpy(statistic[typeCount].typeBook, book[i].bookType);
			statistic[typeCount].typeAmount = 1;
			typeCount++;
		}
	}
	printf("Statistic table: \n");
	printf("+-----------+--------+\n");
	printf("| Book type | Amount |\n");
	printf("+-----------+--------+\n");
	for (int i = 0; i < typeCount; i++)
	{
		printf("| %-9s | %03d    |\n", statistic[i].typeBook, statistic[i].typeAmount);
	}
	printf("+-----------+--------+\n");
}