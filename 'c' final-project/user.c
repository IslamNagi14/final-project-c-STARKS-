#include "user.h"
struct user *Head = NULL;
////////////////////////////////////////////////////////////////owner-admin
void add_user()
{
    struct user *ptr = NULL;
    struct user *temp = Head;
    struct user *search = Head;
    struct user *seaid = Head;
	
    if (Head == NULL)
    {
        ptr = (struct user *)malloc(sizeof(struct user));
        Head = ptr;
        ptr->Next = NULL;
    }
    else
    {
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        ptr = (struct user *)malloc(sizeof(struct user));
        temp->Next = ptr;
        ptr->Next = NULL;
    }
    
    printf("\n Enter user's ID : ");
    ptr->id = (char *)malloc(max * sizeof(char));
    strcpy(ptr->id, takestring_v2());
    while (search != NULL)
    {
        if (strcmp(search->id, ptr->id) == 0 && search != ptr)
        {
            printf("\nID Already Exists.\n");
            // Prompt for ID input again
            printf("\nEnter ID: ");
            strcpy(ptr->id, takestring_v2());
            // Reset temp pointer to Head for rechecking
            search = Head;
        }
        else
        {
            search = search->Next;
        }
    }

	ptr->BorrowedBooks1 = "empty";
	ptr->BorrowedBooks2 = "empty";
	ptr->BorrowedNumber = 0;
    ptr->name = (char *)malloc(max * sizeof(char));
	checkname:
    printf("\nEnter user's name : ");
	strcpy(ptr->name, takestring_v2());
	if(!check_name(ptr->name))
	{
		printf("Invalid name (please enter only letters)\n");
		goto checkname;
	}

    ptr->pass = (char *)malloc(max * sizeof(char));
    printf("\nEnter their Password : ");
    strcpy(ptr->pass, takestring_v2());

    printf("\nEnter Card ID : ");
    ptr->card_id = (char *)malloc(max * sizeof(char));
    strcpy(ptr->card_id, takestring_v2());

    while (seaid != NULL)
    {
        if (strcmp(seaid->card_id, ptr->card_id) == 0 && seaid != ptr)
        {
            printf("\nCard ID Already Exists.\n");
            // Prompt for ID input again
            printf("\nEnter Card ID: ");
            strcpy(ptr->card_id, takestring_v2());
        }
        else
        {
            seaid = seaid->Next;
        }
    }


	check:
    ptr->card_balance = (char *)malloc(max * sizeof(char));
    printf("\nEnter Card Library Balance : ");
    strcpy(ptr->card_balance, takestring_v2());
    if (!check_number(ptr->card_balance))
    {
        printf("number of balance should be numerical\n");
        goto check;
    }
    
}
void ViewUWid(struct user *temp)
{
	char *reverted = (char*)malloc(max *sizeof(char));
	
	strcpy(reverted, temp->name);											
    printf("Name : %s\n",revert_spaces(reverted));
	printf("ID : %s\n",temp->id);
	printf("Card ID : %s\n",temp->card_id);
	printf("Card Balance : %s\n",temp->card_balance);
	strcpy(reverted, temp->BorrowedBooks1);
    printf("Borrowed Book: %s\n", revert_spaces(reverted));
	strcpy(reverted, temp->BorrowedBooks2);
    printf("Borrowed Book: %s\n", revert_spaces(reverted));

	free(reverted);
}








void DeleteUser()  //delete  user with its id
{
    int found = 0;
    char check[10];
	char *id;
	id = (char*)malloc(max * sizeof(char));
	printf("Enter User ID: ");
    scanf("%s", id);	
    printf("Are you sure you want to delete this user? Press (Y) for Yes or anything else for No : ");
    strcpy(check, takestring_v2());

    if ( strcmp(check, "Y") != 0 && strcmp(check, "y") != 0 ){
        printf("\t\t\t\t[[ user is NOT deleted ]]\n");
    }
    else {
        if (Head) {
            struct user *temp = Head;
            struct user *pre = NULL;
            while (temp) {
                if (!strcmp(temp->id, id)) {
                    if (pre) {
                        pre->Next = temp->Next;
                    } else {
                        Head = temp->Next;

                    }
                    //struct user* ptr = temp;
                    free(temp);
                    found = 1;
                    printf("\t\t\t\t[[ user is deleted successfully ]]\n");
                    break;
                }

                pre = temp;
                temp = temp->Next;
            }
        }
        if(!found)
            printf("This ID does NOT exist\n");
        //writeFile(Head, "file.csv");
    }
}

void ViewAUser()
{
	struct user* current=Head;
	char *reverted = (char*)malloc(max *sizeof(char));
	if(Head==NULL)
	{
		printf("empty list \n");
	}
	while(current)
	{
		
		printf("id is %s  \n",current->id);
		strcpy(reverted, current->name);											
        printf("Name : %s\n",revert_spaces(reverted));
		printf("password is %s  \n",current->pass);
		printf("Card ID : %s\n",current->card_id);
		printf("Card Balance : %s\n",current->card_balance);
		printf("Number of book he borrowed : %d\n",current->BorrowedNumber);
		strcpy(reverted, current->BorrowedBooks1);
        printf("Borrowed Book: %s\n", revert_spaces(reverted));
		strcpy(reverted, current->BorrowedBooks2);
        printf("\nBorrowed Book: %s\n", revert_spaces(reverted));
		printf("-----------\n");
		current=current->Next;
	}
	free(reverted);

}

void EUid() 
{

	struct user *temp = Head;
	struct user *sid =Head ;
	char *id;
	char *chid= NULL;
	int found = 1;
	id = (char*)malloc(max * sizeof(char));
	printf("Enter User ID: ");fflush(stdin);fflush(stdout);
    scanf("%s", id);	
	
	while (temp != NULL) 
	{
		if (!strcmp(temp->id, id)) 
		{
			found = 0;
					// Input new id
             
			 chid = (char*)malloc(max * sizeof(char));
			printf("\nEnter NEW ID : ");
			strcpy(chid, takestring_v2());

			while (sid != NULL) 
			{

				if (strcmp(sid->id,chid) == 0) 
				{
					printf("\nID Already Exists.\n");fflush(stdin);fflush(stdout);
            // Prompt for ID input again
					printf("\nEnter NEW ID: ");fflush(stdin);fflush(stdout);
					strcpy(chid, takestring_v2());
            // Reset temp pointer to Head for rechecking
					sid = Head;
                    
				}
				else 
				{

                       sid = sid->Next;

				}
			}	
			strcpy(temp->id, chid);

            break;
					
		}
			temp = temp ->Next;
	}			
			if(found)
				printf("this id does NOT exist");
            free(chid);
    
			free(id);
			
 } 
 //////////////////////////////////////////////////////////////////////////////////////////////////
 void voi_user(struct user* temp) 
 {

				char *reverted = (char*)malloc(max *sizeof(char));
				strcpy(reverted, temp->name);											
                printf("\nName : %s",revert_spaces(reverted));
                printf("\nID : %s", temp->id);
                printf("\npassword: %s", temp->pass);
				strcpy(reverted, temp->BorrowedBooks1);
                printf("\nBorrowed Book: %s", revert_spaces(reverted));
				strcpy(reverted, temp->BorrowedBooks2);
                printf("\nBorrowed Book: %s", revert_spaces(reverted));
				free(reverted);
               
}


 void EUpass(struct user* temp) 
 { // edit student pass
    char cnfrm_pass[max]; // Increase size to accommodate passwords
	char *paswrd;
            paswrd = (char*)malloc(max * sizeof(char)); // Allocate memory for new password

            if (paswrd == NULL) {
                printf("Memory allocation failed.\n");
                //free(pass); // Free allocated memory before returning
                return;
            }
    back2:
            printf("Enter your old password : ");
            scanf("%s", paswrd);
            if(!strcmp(paswrd, temp->pass)){
                // ID and password match, allow user to edit password
                printf("\nEnter your new password : ");
                scanf("%s", paswrd);

                printf("Confirm new password : "); fflush(stdin); fflush(stdout);
                scanf("%s", cnfrm_pass);

                if(strcmp(paswrd, cnfrm_pass) == 0) { // Compare passwords
                    strcpy(temp->pass, paswrd); // Update password
					//writeFile(head, "Students.csv");
                    printf("\t\t\t\t Password Updated Successfully\n");
                } else {
                    printf("\t\t\t\t Passwords do not match. Password not updated.\n");
                }
            }
            else {
                printf("\n[[ Wrong Password .. Enter Again ]]\n");
                goto back2;
            }
            free(paswrd); // Free memory allocated for new_pass
}


         

