#include "admin.h"

////////////////////////////////////////////////////////////owner
void add_admin()
{
    struct admin *ptr = NULL;
    struct admin *temp = HEAD;
    struct admin *search = HEAD;
	char *id;
    if(HEAD == NULL)
    {
        ptr=(struct admin*)malloc(sizeof(struct admin));
        HEAD = ptr;
    }
    else
    {
        while(temp->NEXT != NULL )
            temp = temp->NEXT;

        ptr=(struct admin*)malloc(sizeof(struct admin));
        temp->NEXT= ptr;
    }
    ptr->NEXT=NULL;

   
    id = (char*)malloc(max * sizeof(char));
    printf("\nEnter ID : ");
    strcpy(id, takestring_v2());

    while (search != NULL) {
        if (strcmp(search->id, id) == 0) {
            printf("\nID Already Exists.\n");
            // Prompt for ID input again
            printf("\nEnter ID: ");
             strcpy(id, takestring_v2());
            // Reset temp pointer to head for rechecking
            search = HEAD;
        } else {
            search = search->NEXT;
        }
    }
	ptr->id = (char*)malloc(max * sizeof(char));
    strcpy(ptr->id, id);

   
    ptr->pass = (char*)malloc(max * sizeof(char));
    printf("\nEnter their Password : ");
    strcpy(ptr->pass, takestring_v2());
	ptr->permissions = (char*)malloc(max * sizeof(char));
	for(int i = 0; i < 7 ;i++)
	{
		ptr->permissions[i] = '1';
		
	}
	
   
}

void DeleteAdmin(char *id)  //delete  student with its id
{
    int found = 0;
    char check[10];
    printf("Are you sure you want to delete this admin? Press (Y) for Yes or anything else for No : ");
    strcpy(check, takestring_v2());

    if ( strcmp(check, "Y") != 0 && strcmp(check, "y") != 0 ){
        printf("\t\t\t\t[[ admin is NOT deleted ]]\n");
    }
    else {
        if (HEAD) {
            struct admin *temp = HEAD;
            struct admin *pre = NULL;
            while (temp) {
                if (!strcmp(temp->id, id)) {
                    if (pre) {
                        pre->NEXT = temp->NEXT;
                    } else {
                        HEAD = temp->NEXT;

                    }
                    //struct admin* ptr = temp;
                    free(temp);
                    found = 1;
                    printf("\t\t\t\t[[ admin is deleted successfully ]]\n");
                    break;
                }

                pre = temp;
                temp = temp->NEXT;
            }
        }
        if(!found)
            printf("This ID does NOT exist\n");
        //writeFile(head, "file.csv");
    }
}

void ViewAAdmin()
{
	struct admin* current=HEAD;
	if(HEAD==NULL)
	{
		printf("empty list \n");
	}
	while(current)
	{
	printf("id is %s  \n",current->id);
    printf("password is %s  \n",current->pass);
    printf("-----------\n");
    current=current->NEXT;
	}
}//////////////////////////////////////////////////////////////////////

void EApermissions()
{
	
	 int found = 0;
	char *id;
	char *edition; edition = (char*) malloc(max * sizeof(char));
	id = (char*)malloc(max * sizeof(char));
	printf("Enter admin ID: ");
    scanf("%s", id);	

        if (HEAD) 
		{
            struct admin *temp = HEAD;
           
            while (temp) 
			{
                if (!strcmp(temp->id, id)) 
				{
					found = 1;
					char *choise;choise = (char*) malloc(max * sizeof(char));
					printf("1- Add new User\n2- Remove User\n3- Veiw all Users\n");
					printf("4- Edit user ID \n");
					printf("5- Add new Book\n6- Remove Book\n");
					printf("7- Veiw all books\n");
					lable:
					printf("Enter the permission that U want to edit : ");
                    strcpy(choise, takestring_v2());
					printf("Do you need to 1- add this feature or 2- delete it : ");
                    strcpy(edition, takestring_v2());
				   switch(atoi(choise))
				   {
					    case 1:
								if(!strcmp(edition,"1"))
								{
									if(temp->permissions[atoi(choise)-1] == '0')
									{
										temp->permissions[atoi(choise)-1] = '1';
										printf("this feature added successfully\n");
									}
									else
									{
										printf("this admin already has this feature\n");
									}
								}
								else if(!strcmp(edition,"2"))
								{
									if(temp->permissions[atoi(choise)-1] == '1')
									{
										temp->permissions[atoi(choise)-1] = '0';
										printf("this feature removed successfully\n");
									}
									else
									{
									printf("this admin already has NOT  this feature\n");
									}
								}
								else
								{
									printf("Wrong input...\n");
									goto lable;
								}
						break;
						
					    case 2:
								if(!strcmp(edition,"1"))
								{
									if(temp->permissions[atoi(choise)-1] == '0')
									{
										temp->permissions[atoi(choise)-1] = '1';
										printf("this feature added successfully\n");
									}
									else
									{
										printf("this admin already has this feature\n");
									}
								}
								else if(!strcmp(edition,"2"))
								{
									if(temp->permissions[atoi(choise)-1] == '1')
									{
										temp->permissions[atoi(choise)-1] = '0';
										printf("this feature removed successfully\n");
									}
									else
									{
									printf("this admin already has NOT  this feature\n");
									}
								}
								else
								{
									printf("Wrong input...\n");
									goto lable;
								}
						break;
						
					    case 3:
								if(!strcmp(edition,"1"))
								{
									if(temp->permissions[atoi(choise)-1] == '0')
									{
										temp->permissions[atoi(choise)-1] = '1';
										printf("this feature added successfully\n");
									}
									else
									{
										printf("this admin already has this feature\n");
									}
								}
								else if(!strcmp(edition,"2"))
								{
									if(temp->permissions[atoi(choise)-1] == '1')
									{
										temp->permissions[atoi(choise)-1] = '0';
										printf("this feature removed successfully\n");
									}
									else
									{
									printf("this admin already has NOT  this feature\n");
									}
								}
								else
								{
									printf("Wrong input...\n");
									goto lable;
								}
						break;
						
					    case 4:
								if(!strcmp(edition,"1"))
								{
									if(temp->permissions[atoi(choise)-1] == '0')
									{
										temp->permissions[atoi(choise)-1] = '1';
										printf("this feature added successfully\n");
									}
									else
									{
										printf("this admin already has this feature\n");
									}
								}
								else if(!strcmp(edition,"2"))
								{
									if(temp->permissions[atoi(choise)-1] == '1')
									{
										temp->permissions[atoi(choise)-1] = '0';
										printf("this feature removed successfully\n");
									}
									else
									{
									printf("this admin already has NOT  this feature\n");
									}
								}
								else
								{
									printf("Wrong input...\n");
									goto lable;
								}
						break;
						
					   case 5:
								if(!strcmp(edition,"1"))
								{
									if(temp->permissions[atoi(choise)-1] == '0')
									{
										temp->permissions[atoi(choise)-1] = '1';
										printf("this feature added successfully\n");
									}
									else
									{
										printf("this admin already has this feature\n");
									}
								}
								else if(!strcmp(edition,"2"))
								{
									if(temp->permissions[atoi(choise)-1] == '1')
									{
										temp->permissions[atoi(choise)-1] = '0';
										printf("this feature removed successfully\n");
									}
									else
									{
									printf("this admin already has NOT  this feature\n");
									}
								}
								else
								{
									printf("Wrong input...\n");
									goto lable;
								}
						break;
						
					    case 6:
								if(!strcmp(edition,"1"))
								{
									if(temp->permissions[atoi(choise)-1] == '0')
									{
										temp->permissions[atoi(choise)-1] = '1';
										printf("this feature added successfully\n");
									}
									else
									{
										printf("this admin already has this feature\n");
									}
								}
								else if(!strcmp(edition,"2"))
								{
									if(temp->permissions[atoi(choise)-1] == '1')
									{
										temp->permissions[atoi(choise)-1] = '0';
										printf("this feature removed successfully\n");
									}
									else
									{
									printf("this admin already has NOT  this feature\n");
									}
								}
								else
								{
									printf("Wrong input...\n");
									goto lable;
								}
						break;
						
					    case 7:
								if(!strcmp(edition,"1"))
								{
									if(temp->permissions[atoi(choise)-1] == '0')
									{
										temp->permissions[atoi(choise)-1] = '1';
										printf("this feature added successfully\n");
									}
									else
									{
										printf("this admin already has this feature\n");
									}
								}
								else if(!strcmp(edition,"2"))
								{
									if(temp->permissions[atoi(choise)-1] == '1')
									{
									temp->permissions[atoi(choise)-1] = '0';
										printf("this feature removed successfully\n");
									}
									else
									{
									printf("this admin already has NOT  this feature\n");
									}
								}
								else
								{
									printf("Wrong input...\n");
									goto lable;
								}
								break;
					   default:
								printf("this feature is NOT avaliable\n");
					   break;
				   }
				}
				

                temp = temp->NEXT;
            }
        }
        if(!found)
            printf("This ID does NOT exist\n");
}