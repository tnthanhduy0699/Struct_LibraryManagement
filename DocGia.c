#include <stdio.h>
#include <string.h>
#include "DocGia.h"
#include "Statistic.h"

//1. Print out the list of reader in library
void PrintReader(struct DocGia reader[MAX_READER], int readerCount)
{
    //Checking current reader amount, if amount = 0, there is no reader
	if (readerCount == 0)
	{
		printf("There is no reader in the library!\n");
		return;
	}
    //Open the file
    FILE *file = fopen("readers.txt", "r");
    if (file == NULL) {
        printf("Cannot open file!\n");
        return;
    }

    printf("List of readers:\n");
    char temp[1000];
    while (fgets(temp, 1000, file) != NULL)
    {
        printf("%s", temp);
    }
    //Close the txt file after reading.
    fclose(file);
}
//2. Add new reader, then print the data into text file.
int AddReader(struct DocGia reader[MAX_READER], int readerCount)
{
    //Checking reader amount before adding a new reader
    if (readerCount >= MAX_READER) {
        printf("Maximum limit reached. Cannot add more reader!\n");
        return 0;
    }

    printf("Enter the reader No.: ");
    scanf("%d", &reader[readerCount].readerNo);

    printf("Enter reader name: ");
    getchar();
    fgets(reader[readerCount].readerName, MAX_NAME_LEN, stdin);
    reader[readerCount].readerName[strcspn(reader[readerCount].readerName, "\n")] = '\0';
    //Maximum of CCCD is 12 digits
    printf("Enter reader identification number: ");
	fgets(reader[readerCount].readerID, MAX_NAME_LEN, stdin);
	reader[readerCount].readerID[strcspn(reader[readerCount].readerID, "\n")] = '\0';
	//Date of birth cannot be smaller than 1 and greater than 31
	do {
        printf("Enter date of birth: ");
        scanf("%d", &reader[readerCount].readerBirthDate);
        if (reader[readerCount].readerBirthDate < 1 || reader[readerCount].readerBirthDate > 31)
        {
            printf("Invalid date. Please enter again!\n");
        }
    } while (reader[readerCount].readerBirthDate < 1 || reader[readerCount].readerBirthDate > 31);
	//Month of birth cannot be smaller than 1 and greater than 12
    do {
        printf("Enter month of birth: ");
        scanf("%d", &reader[readerCount].readerBirthMonth);
        if (reader[readerCount].readerBirthMonth < 1 || reader[readerCount].readerBirthMonth > 12)
        {
            printf("Invalid month. Please enter again!\n");
        }
    } while (reader[readerCount].readerBirthMonth < 1 || reader[readerCount].readerBirthMonth > 12);
	//Year of birth cannot be smaller than 1900 and greater than 2024
    do {
        printf("Enter year of birth: ");
        scanf("%d", &reader[readerCount].readerBirthYear);
        if (reader[readerCount].readerBirthYear < 1900 || reader[readerCount].readerBirthYear > 2024)
        {
            printf("Invalid year. Please enter again!\n");
        }
    } while (reader[readerCount].readerBirthYear < 1900 || reader[readerCount].readerBirthYear > 2024);

    printf("Enter gender: ");
    getchar();
    fgets(reader[readerCount].readerGender, MAX_NAME_LEN, stdin);
	reader[readerCount].readerGender[strcspn(reader[readerCount].readerGender, "\n")] = '\0';

    printf("Enter email: ");
    fgets(reader[readerCount].readerEmail, MAX_NAME_LEN, stdin);
	reader[readerCount].readerEmail[strcspn(reader[readerCount].readerEmail, "\n")] = '\0';

    printf("Enter location (City): ");
    fgets(reader[readerCount].readerLocation, MAX_NAME_LEN, stdin);
	reader[readerCount].readerLocation[strcspn(reader[readerCount].readerLocation, "\n")] = '\0';
	//Enter the date of library card creation
	do {
        printf("Enter date of library card: ");
        scanf("%d", &reader[readerCount].libraryCardDate);
        if (reader[readerCount].libraryCardDate < 1 || reader[readerCount].libraryCardDate > 31)
        {
            printf("Invalid date. Please enter again!\n");
        }
    } while (reader[readerCount].libraryCardDate < 1 || reader[readerCount].libraryCardDate > 31);
    do {
        printf("Enter month of library card: ");
        scanf("%d", &reader[readerCount].libraryCardMonth);
        if (reader[readerCount].libraryCardMonth < 1 || reader[readerCount].libraryCardMonth > 12)
        {
            printf("Invalid month. Please enter again!\n");
        }
    } while (reader[readerCount].libraryCardMonth < 1 || reader[readerCount].libraryCardMonth > 12);
    do {
        printf("Enter year of library card: ");
        scanf("%d", &reader[readerCount].libraryCardYear);
        if (reader[readerCount].libraryCardYear < 1900 || reader[readerCount].libraryCardYear > 2024)
        {
            printf("Invalid year. Please enter again!\n");
        }
    } while (reader[readerCount].libraryCardYear < 1900 || reader[readerCount].libraryCardYear > 2024);

    reader[readerCount].expiredCardDate = reader[readerCount].libraryCardDate;
    reader[readerCount].expiredCardMonth = reader[readerCount].libraryCardMonth;
	reader[readerCount].expiredCardYear = reader[readerCount].libraryCardYear + 4;

    //Increase current reader number after adding new reader
    readerCount++;

    // Open the file in editable mode "w"
    FILE *file = fopen("readers.txt", "w");
    if (file == NULL) {
        printf("Cannot open or create the file.\n");
        return 0;
    }
    //Print out data as table layout
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    fprintf(file, "|   No.  |        Full name         | Identification |    Date of birth    |  Gender   |           Email           |    Address    | Card creation  |   Expired date   |\n");
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    //Add the loop to print all reader data into txt file.
    for (int i = 0; i < readerCount; i++)
    {
        fprintf(file, "| %03d    | %-25s| %-13s  | %02d / %02d / %04d      | %-9s | %-25s | %-13s | %02d / %02d / %04d | %02d / %02d / %04d   |\n",
        reader[i].readerNo,
        reader[i].readerName,
        reader[i].readerID,
		reader[i].readerBirthDate,
		reader[i].readerBirthMonth,
		reader[i].readerBirthYear,
		reader[i].readerGender,
		reader[i].readerEmail,
		reader[i].readerLocation,
		reader[i].libraryCardDate,
		reader[i].libraryCardMonth,
		reader[i].libraryCardYear,
		reader[i].expiredCardDate,
		reader[i].expiredCardMonth,
		reader[i].expiredCardYear);
    }
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    //Close the file after editing
    fclose(file);

    printf("Add reader successfully!\n");
    return readerCount;
}
//3. Edit the data of reader.
void EditReaderInfo(struct DocGia reader[MAX_READER], int readerCount)
{
    //Checking current reader amount, if amount = 0, there is no reader
    if (readerCount == 0)
	{
		printf("There is no reader in the library!\n");
		return;
	}
    int index;
	printf("Enter the position of reader need to be edited: ");
	scanf("%d", &index);

	if (index < 0 || index - 1 > readerCount - 1)
	{
		printf("This reader is not existed!\n");
		return;
	}

	int choice;
	printf("Attribute can be edited: \n");
	printf("1. Reader no.\n");
	printf("2. Full name\n");
	printf("3. Indentification number\n");
	printf("4. Date of birth\n");
	printf("5. Gender\n");
	printf("6. Email\n");
	printf("7. Address\n");
	printf("8. Date of book borrowing card\n");
	printf("Choose the attrubute need to be edited: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		//Edit reader no.
		printf("Enter new reader no.: ");
		scanf("%d", &reader[index-1].readerNo);
		break;
	case 2:
		//Edit full name
		printf("Enter new full name: ");
		getchar();
		fgets(reader[index-1].readerName, MAX_NAME_LEN, stdin);
		reader[index-1].readerName[strcspn(reader[index-1].readerName, "\n")] = '\0';
		break;
	case 3:
		//Edit identification number
		printf("Enter new identificatation number: ");
		getchar();
		fgets(reader[index-1].readerID, MAX_NAME_LEN, stdin);
		reader[index-1].readerID[strcspn(reader[index-1].readerID, "\n")] = '\0';
		break;
	case 4:
		//Edit date of birth
		do {
        printf("Enter new date of birth: ");
        scanf("%d", &reader[index-1].readerBirthDate);
        if (reader[index-1].readerBirthDate < 1 || reader[index-1].readerBirthDate > 31)
        {
            printf("Invalid date. Please enter again!\n");
        }
        } while (reader[index-1].readerBirthDate < 1 || reader[index-1].readerBirthDate > 31);
	    //Month of birth cannot be smaller than 1 and greater than 12
        do {
        printf("Enter new month of birth: ");
        scanf("%d", &reader[index-1].readerBirthMonth);
        if (reader[index-1].readerBirthMonth < 1 || reader[index-1].readerBirthMonth > 12)
        {
            printf("Invalid month. Please enter again!\n");
        }
        } while (reader[index-1].readerBirthMonth < 1 || reader[index-1].readerBirthMonth > 12);
	    //Year of birth cannot be smaller than 1900 and greater than 2024
        do {
        printf("Enter new year of birth: ");
        scanf("%d", &reader[index-1].readerBirthYear);
        if (reader[index-1].readerBirthYear < 1900 || reader[index-1].readerBirthYear > 2024)
        {
            printf("Invalid year. Please enter again!\n");
        }
        } while (reader[index-1].readerBirthYear < 1900 || reader[index-1].readerBirthYear > 2024);
		break;
	case 5:
		//Edit gender
		printf("Enter new gender: ");
		getchar();
		fgets(reader[index-1].readerGender, MAX_NAME_LEN, stdin);
		reader[index-1].readerGender[strcspn(reader[index-1].readerGender, "\n")] = '\0';
		break;
	case 6:
		//Edit email
		printf("Enter new email: ");
		getchar();
		fgets(reader[index-1].readerEmail, MAX_NAME_LEN, stdin);
		reader[index-1].readerEmail[strcspn(reader[index-1].readerEmail, "\n")] = '\0';
		break;
	case 7:
		//Edit location
		printf("Enter new location: ");
		getchar();
		fgets(reader[index-1].readerLocation, MAX_NAME_LEN, stdin);
		reader[index-1].readerLocation[strcspn(reader[index-1].readerLocation, "\n")] = '\0';
		break;
	case 8:
		//Edit library card creation date
		do {
        printf("Enter new date of library card: ");
        scanf("%d", &reader[index-1].libraryCardDate);
        if (reader[index-1].libraryCardDate < 1 || reader[index-1].libraryCardDate > 31)
        {
            printf("Invalid date. Please enter again!\n");
        }
        } while (reader[index-1].libraryCardDate < 1 || reader[index-1].libraryCardDate > 31);
        do {
        printf("Enter new month of library card: ");
        scanf("%d", &reader[index-1].libraryCardMonth);
        if (reader[index-1].libraryCardMonth < 1 || reader[index-1].libraryCardMonth > 12)
        {
            printf("Invalid month. Please enter again!\n");
        }
        } while (reader[index-1].libraryCardMonth < 1 || reader[index-1].libraryCardMonth > 12);
        do {
        printf("Enter new year of library card: ");
        scanf("%d", &reader[index-1].libraryCardYear);
        if (reader[index-1].libraryCardYear < 1900 || reader[index-1].libraryCardYear > 2024)
        {
            printf("Invalid year. Please enter again!\n");
        }
        } while (reader[index-1].libraryCardYear < 1900 || reader[index-1].libraryCardYear > 2024);
		break;
	default:
		printf("This attribute is not existed!\n");
		break;
	}
    // Update the txt file again after editing reader information
    FILE *file = fopen("readers.txt", "w");
    if (file == NULL) {
        printf("Cannot open or create the file.\n");
        return;
    }
    //Print out data as table layout
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    fprintf(file, "|   No.  |        Full name         | Identification |    Date of birth    |  Gender   |           Email           |    Address    | Card creation  |   Expired date   |\n");
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    //Add the loop to print all reader data into txt file.
    for (int i = 0; i < readerCount; i++)
    {
        fprintf(file, "| %03d    | %-25s| %-13s  | %02d / %02d / %04d      | %-9s | %-25s | %-13s | %02d / %02d / %04d | %02d / %02d / %04d   |\n",
        reader[i].readerNo,
        reader[i].readerName,
        reader[i].readerID,
		reader[i].readerBirthDate,
		reader[i].readerBirthMonth,
		reader[i].readerBirthYear,
		reader[i].readerGender,
		reader[i].readerEmail,
		reader[i].readerLocation,
		reader[i].libraryCardDate,
		reader[i].libraryCardMonth,
		reader[i].libraryCardYear,
		reader[i].expiredCardDate,
		reader[i].expiredCardMonth,
		reader[i].expiredCardYear);
    }
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    //Close the file after editing
    fclose(file);
    printf("Reader information updated successfully in the file!\n");
}
//4. Delete reader out of database
int DeleteReader(struct DocGia reader[MAX_READER], int readerCount)
{
    //Checking current reader amount, if amount = 0, there is no reader
    if (readerCount == 0)
	{
		printf("There is no reader in the library!\n");
		return 0;
	}

	int pos;
	printf("Enter the position of reader need to be deleted: ");
	scanf("%d", &pos);
	//Checking the input of user
	if (pos < 0 || pos - 1 > readerCount - 1)
	{
		printf("This reader is not existed!\n");
		return 0;
	}

	for (int i = pos-1; i < readerCount - 1; i++)
	{
		reader[i].readerNo = reader[i + 1].readerNo;
		strcpy(reader[i].readerName, reader[i + 1].readerName);
		strcpy(reader[i].readerID, reader[i + 1].readerID);
		reader[i].readerBirthDate = reader[i + 1].readerBirthDate;
		reader[i].readerBirthMonth = reader[i + 1].readerBirthMonth;
		reader[i].readerBirthYear = reader[i + 1].readerBirthYear;
		strcpy(reader[i].readerGender, reader[i + 1].readerGender);
		strcpy(reader[i].readerEmail, reader[i + 1].readerEmail);
		strcpy(reader[i].readerLocation, reader[i + 1].readerLocation);
		reader[i].libraryCardDate = reader[i+1].libraryCardDate;
		reader[i].libraryCardMonth = reader[i+1].libraryCardMonth;
		reader[i].libraryCardYear = reader[i+1].libraryCardYear;
	}

	// Reduce reader amount after deleting
	readerCount--;

    // Update the txt file again after editing reader information
    FILE *file = fopen("readers.txt", "w");
    if (file == NULL) {
        printf("Cannot open or create the file.\n");
        return 0;
    }
    //Print out data as table layout
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    fprintf(file, "|   No.  |        Full name         | Identification |    Date of birth    |  Gender   |           Email           |    Address    | Card creation  |   Expired date   |\n");
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    //Add the loop to print all reader data into txt file.
    for (int i = 0; i < readerCount; i++)
    {
        fprintf(file, "| %03d    | %-25s| %-13s  | %02d / %02d / %04d      | %-9s | %-25s | %-13s | %02d / %02d / %04d | %02d / %02d / %04d   |\n",
        reader[i].readerNo,
        reader[i].readerName,
        reader[i].readerID,
		reader[i].readerBirthDate,
		reader[i].readerBirthMonth,
		reader[i].readerBirthYear,
		reader[i].readerGender,
		reader[i].readerEmail,
		reader[i].readerLocation,
		reader[i].libraryCardDate,
		reader[i].libraryCardMonth,
		reader[i].libraryCardYear,
		reader[i].expiredCardDate,
		reader[i].expiredCardMonth,
		reader[i].expiredCardYear);
    }
    fprintf(file, "+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
    //Close the file after editing
    fclose(file);

	printf("Reader is deleted. Database is updated successfully!\n");
	return readerCount;
}
//5. Search reader by identification number
void SearchReaderByID(struct DocGia reader[MAX_READER], int readerCount)
{
    //Checking current reader amount, if amount = 0, there is no reader
	if (readerCount == 0)
	{
		printf("There is no reader in the library!\n");
		return;
	}
    //Open the file to search
    FILE *file = fopen("readers.txt", "r");
    if (file == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    int found = 0;
    char searchID[MAX_NAME_LEN];
    printf("Enter reader identification number need to be searched: ");
    getchar();
    fgets(searchID, MAX_NAME_LEN, stdin);
    searchID[strcspn(searchID, "\n")] = '\0';

    for (int i = 0; i < readerCount; i++)
    {
       if (strcmp(reader[i].readerID, searchID) == 0)
       {
        if (found == 0)
        {
            printf("+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
            printf("|   No.  |        Full name         | Identification |    Date of birth    |  Gender   |           Email           |    Address    | Card creation  |   Expired date   |\n");
            printf("+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
        }
        
        printf("| %03d    | %-25s| %-13s  | %02d / %02d / %04d      | %-9s | %-25s | %-13s | %02d / %02d / %04d | %02d / %02d / %04d   |\n",
        reader[i].readerNo,
        reader[i].readerName,
        reader[i].readerID,
		reader[i].readerBirthDate,
		reader[i].readerBirthMonth,
		reader[i].readerBirthYear,
		reader[i].readerGender,
		reader[i].readerEmail,
		reader[i].readerLocation,
		reader[i].libraryCardDate,
		reader[i].libraryCardMonth,
		reader[i].libraryCardYear,
		reader[i].expiredCardDate,
		reader[i].expiredCardMonth,
		reader[i].expiredCardYear);

        //found will be increased after the ID is found.
        found++;
       }
    }

    if (found == 0)
    {
        printf("Cannot find any reader having this identification number: %s\n", searchID);
    }
    else
    {
        //Print out table footer after searching is complete
        printf("+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
        if (found > 1)
        {
            printf("Found %d readers having the same identification number!\n", found);
        } else
        {
            printf("Found the reader!\n");
        }
    }
    //Close the file after searching completed
    fclose(file);
}
//6. Search reader by name
void SearchReaderByName(struct DocGia reader[MAX_READER], int readerCount)
{
    //Checking current reader amount, if amount = 0, there is no reader
	if (readerCount == 0)
	{
		printf("There is no reader in the library!\n");
		return;
	}
    //Open the file to search
    FILE *file = fopen("readers.txt", "r");
    if (file == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    int found = 0;
    char searchName[MAX_NAME_LEN];
    printf("Enter reader name need to be searched: ");
    getchar();
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < readerCount; i++)
    {
       if (strcmp(reader[i].readerName, searchName) == 0)
       {
        if (found == 0)
        {
            printf("+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
            printf("|   No.  |        Full name         | Identification |    Date of birth    |  Gender   |           Email           |    Address    | Card creation  |   Expired date   |\n");
            printf("+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
        }
        
        printf("| %03d    | %-25s| %-13s  | %02d / %02d / %04d      | %-9s | %-25s | %-13s | %02d / %02d / %04d | %02d / %02d / %04d   |\n",
        reader[i].readerNo,
        reader[i].readerName,
        reader[i].readerID,
		reader[i].readerBirthDate,
		reader[i].readerBirthMonth,
		reader[i].readerBirthYear,
		reader[i].readerGender,
		reader[i].readerEmail,
		reader[i].readerLocation,
		reader[i].libraryCardDate,
		reader[i].libraryCardMonth,
		reader[i].libraryCardYear,
		reader[i].expiredCardDate,
		reader[i].expiredCardMonth,
		reader[i].expiredCardYear);

        //found will be increased after the ID is found.
        found++;
       }
    }

    if (found == 0)
    {
        printf("Cannot find any reader having this name: %s\n", searchName);
    }
    else
    {
        //Print out table footer after searching is complete
        printf("+--------+--------------------------+----------------+---------------------+-----------+---------------------------+---------------+----------------+------------------+\n");
        if (found > 1)
        {
            printf("Found %d readers having the same name!\n", found);
        } else
        {
            printf("Found the reader!\n");
        }
    }
    //Close the file after searching completed
    fclose(file);
}
//17. Count the total number of reader at this time
void ReaderStatistic(struct DocGia reader[MAX_READER], int readerCount)
{
    //Checking current reader amount, if amount = 0, there is no reader
	if (readerCount == 0)
	{
		printf("There is no reader in the library!\n");
		return;
	}

	printf("Total number of reader: %d\n", readerCount);
	//Call the function PrintReader again to show the detail as table view.
	PrintReader(reader, readerCount);
}
//18. Count the number of reader by gender
void CountReaderByGender(struct DocGia reader[MAX_READER], struct ThongKe statistic[MAX_READER], int readerCount)
{
	int genderCount = 0;

	for (int i = 0; i < readerCount; i++)
	{
		int found = 0;
		// Check that readerGender is existed in statistic[j].typeGender or not? If YES, increase the statistic[j].genderAmount
        for (int j = 0; j < genderCount; j++)
		{
			if (strcmp(reader[i].readerGender, statistic[j].typeGender) == 0)
			{
				statistic[j].genderAmount++;
				found = 1;
				break;
			}
		}
		// if NO, add reader[i].readerGender into statistic.typeGender
        if (found == 0)
		{
			strcpy(statistic[genderCount].typeGender, reader[i].readerGender);
			statistic[genderCount].genderAmount = 1;
			genderCount++;
		}
	}
	printf("Statistic table: \n");
	printf("+-----------+--------+\n");
	printf("|  Gender   | Amount |\n");
	printf("+-----------+--------+\n");
	for (int i = 0; i < genderCount; i++)
	{
		printf("| %-9s | %03d    |\n", statistic[i].typeGender, statistic[i].genderAmount);
	}
	printf("+-----------+--------+\n");
}