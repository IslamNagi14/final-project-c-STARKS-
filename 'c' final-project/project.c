
#include "interface.h"
void main()
{
	readAFile(&HEAD, "Admins.csv");
	readUFile(&Head, "Users.csv");
	readBFile(&head, "Books.csv");
	 
	  Welcome();
    while(1) 
	{
        char mode[10];
        printf("Modes:>>\n1. Owner Mode\n2. Admin Mode\n3. User Mode\n4. Exit program\n\n\nChoose Mode : ");
        strcpy(mode, takestring_v2());
        //clearInputBuffer();

        if (!strcmp(mode, "1") ) ownerMode();
        else if (!strcmp(mode, "2") )   adminMode();
        else if (!strcmp(mode, "3") )   userMode();
        else if (!strcmp(mode, "4")) break;
        else printf("\n\nInvalid mode selection..Try again.\n\n");
    }
	writeAFile(HEAD, "Admins.csv");
	writeUFile(Head, "Users.csv");
	writeBFile(head, "Books.csv");
	
	
}					