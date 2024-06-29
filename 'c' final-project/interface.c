#include "interface.h"
void Welcome(){
    printf("\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t############ |WELCOME TO STARKS library| ###############\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
\t\t\t\t\t\t\t\t\t\t\t#################################################################\n\
");
    printf("\t\t\t\t\t\t\t\t\t\t\t>>>>> [ Press (b) anytime to return to previous process ] <<<<<<\n\
");}



void ownerMode()
{
	char name[max] = "Owner";
	char ownerpass[max] = "1234";
    char input_password[30];
    int attempts = 3;
    while (attempts > 0) 
	{
        printf("Enter Owner password: ");
        scanf("%s", input_password);
        getchar();

        if (strcmp(ownerpass, input_password) == 0) {
            printf("\t\t\t\t>> Login successful <<\n");
            break;
        } 
		else 
		{
            attempts--;
            printf("Incorrect password. %d attempts remaining.\n", attempts);
            if (attempts == 0) 
			{
                printf("\t\t\t\t>> Login failed. Exiting <<\n");
                return;
            }
        }
    }

    while(1)
    {  
        char str[8];
        int choice;
        char back[8];
        back:
        printf(">> Owner Menu:\n");
        printf("1- Add new Admin\n2- Remove Admin\n3- Veiw all admins\n4- Edit Admin permissions\n");
        printf("5- Add new User\n6- Edit user ID\n");
        printf("7- Delete user by their ID \n8- Veiw all users\n");
        printf("9- Add new Book\n10- Remove Book\n");
        printf("11- Veiw all books\n12- Exit\n");
        printf("Enter your choice : ");
        scanf("%s",str);
        choice = atoi(str);
        switch(choice)
        {
            case 1:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                   goto back;
                //calling
                add_admin();
                break;
            case 2:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                printf("Enter Admin's ID : ");
                DeleteAdmin(takestring_v2());
                break;
            case 3:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back,"b"))
                    goto back;
                //calling
                ViewAAdmin();
                break;
            case 4:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                 EApermissions();
                break;
            case 5:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                add_user();
                //writeFile(head, "students.csv");
                break;
            case 6:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                EUid();
                break;
				  case 7:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                DeleteUser();
                break;
				  case 8:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                 ViewAUser();
                break;
				  case 9:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                 add_book();
                break;
				  case 10:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                 RemoveBook();
                break;
				  case 11:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
                //calling
                 VAbooks();
                break;
				 
            case 12:
                printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                scanf("%s",back);
                if(!strcmp(back, "b"))
                    goto back;
            
                break;
            default:
                printf("\n\nwrong choice...Choose again.\n\n");
                goto back;
                //break;
        }
        if( choice == 12 ) {break;}
        printf("If you want to do another operation, press (Y) for YES or any other value for NO :\n");fflush(stdin);fflush(stdout);
        scanf("%s", back);
        if (strcmp(back, "Y") != 0 && strcmp(back, "y") != 0)
            {break;}
    }
}


    //user Mode
void userMode() 
{

    char id[88];
    char pass[88];
    char str[8];
    int choice;
    char back[8];

    // Ask user for ID and password
    printf("Enter your ID: ");
    scanf("%s", id);

    printf("Enter your password: ");
    scanf("%s", pass);

    struct user *temp = Head;
    int found = 0;

    while (temp != NULL) 
	{
        if (!strcmp(temp->id, id)) // ID matchs, check password
		{
            // ID matchs, check password
            
            if (!strcmp(temp->pass, pass)) 
			{
				found = 1;
                back1:
                while(1)
                {
                    back:
                    printf(">> user Menu:\n");
                    printf("1- Veiw user's data\n");
                    printf("2- Edit Your pass\n");
                    printf("3- search By book name \n");
                    printf("4- search By book id \n5- search By book author\n");
                    printf("6- Borrow Book\n7- Return book to library\n");
                    printf("8- Buying Book \n9- Exit\n\n");
                    printf("Enter your choice : ");
                    scanf("%s",str);
                    choice = atoi(str);
                    //scanf("%d",&choice);
                    //choice = getchar();
                    switch(choice)
                    {
                        case 1:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            ViewUWid(temp);
                            break;
                        case 2:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                             EUpass(temp);
                            //writeFile(head, "students.csv"); fflush(stdin);fflush(stdout);
                            break;
                        case 3:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                           SearchBookName();
                            break;
                        case 4:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            SearchBookId();
                            break;
						case 5:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                           SearchBookAuther();
                            break;
						case 6:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                           BorrowBook(temp);
                            break;
						case 7:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                           ReturningBooks(temp);
                            break;
						case 8:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                         BuyingBook(temp);
                            break;
                        case 9:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            break;
                        default:
                            printf("\n\nwrong choise...Choose again.\n\n");
                            goto back;
                            //break;
                    }
                    if( choice == 9) {break;}
                    printf("Do you want to do other process press (Y) for YES and any other for NO\n");fflush(stdin);fflush(stdout);
                    scanf("%s",back);
                    if (strcmp(back, "Y") != 0 && strcmp(back, "y") != 0)
                    {break;}
                }
                break;
            }
           
        }
        temp = temp->Next;
    }

    if (!found) 
	{
        printf("\t\t\t\t[[ user is NOT found or Incorrect Password. ]]\n");
    }
}


void adminMode() 
{

    char id[max];
    char pass[max];
    char str[8];
    int choice;
    char back[8];

    // Ask user for ID and password
    printf("Enter your ID: ");
    scanf("%s", id);

    printf("Enter your password: ");
    scanf("%s", pass);

    struct admin *temp = HEAD;
    int found = 0;

    while (temp != NULL) 
	{
        if (!strcmp(temp->id, id)) // ID matchs, check password
		{
            // ID matchs, check password
            
            if (!strcmp(temp->pass, pass)) 
			{
				found = 1;
                back1:
                while(1)
                {
                    back:
                    printf(">> admin Menu:\n");
                     printf("1- Add new User\n2- Remove User\n3- Veiw all Users\n");
					printf("4- Edit user ID \n");
					printf("5- Add new Book\n6- Remove Book\n");
					printf("7- Veiw all books\n8- Exit\n");
                    printf("Enter your choice : ");
                    scanf("%s",str);
                    choice = atoi(str);
                    //scanf("%d",&choice);
                    //choice = getchar();
				if(temp->permissions[choice-1] == '1')
				{
                    switch(choice)
                    {
                        case 1:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            add_user();
                            break;
                        case 2:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            DeleteUser();
                            //writeFile(head, "students.csv"); fflush(stdin);fflush(stdout);
                            break;
                        case 3:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                          ViewAUser();
                            break;
                        case 4:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                            goto back;
                            //calling
							EUid();
                            break;
						case 5:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                           add_book();
                            break;
							
						case 6:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                           RemoveBook();
                            break;
						case 7:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            VAbooks();
                            break;
                        case 8:
                            printf("\t\t\tIf you want to go back, press (b) \n"); fflush(stdin);fflush(stdout);
                            scanf("%s",back);
                            if(!strcmp(back, "b"))
                                goto back;
                            //calling
                            break;
                        default:
                            printf("\n\nwrong choise...Choose again.\n\n");
                            goto back;
                            //break;
                    }
				}
				else
				{
					printf("you are NOT allowed to do this process\n");
				}
                    if( choice == 8) {break;}
                    printf("Do you want to do other process press (Y) for YES and any other for NO\n");fflush(stdin);fflush(stdout);
                    scanf("%s",back);
                    if (strcmp(back, "Y") != 0 && strcmp(back, "y") != 0)
                    {break;}
                }
                break;
            }
           
        }
        temp = temp->NEXT;
    }

    if (!found) 
	{
        printf("\t\t\t\t[[ user is NOT found or Incorrect Password. ]]\n");
    }
}

