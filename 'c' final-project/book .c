#include "book.h"



void add_book()//book.c
{
	struct book *ptr = NULL;
	struct book *temp = head;
    struct book *search = head;
	char *name;
	char *id;
    if(head == NULL)
    {
        ptr=(struct book*)malloc(sizeof(struct book));
        head = ptr;
    }
    else
    {
        while(temp->next != NULL )
            temp = temp->next;

        ptr=(struct book*)malloc(sizeof(struct book));
        temp->next= ptr;
    }
    ptr->next=NULL;
	name = (char*)malloc(max * sizeof(char));
	checkname:
	printf("Enter the book name : ");
	strcpy(name,takestring_v2());
	if(!check_name(name))
	{
		printf("Invalid name (please enter only letters)\n");
		goto checkname;
	}
	while (search != NULL) 
	{
        if (strcmp(search->name, name) == 0) 
		{
            printf("\nthis book Already Exists.\n");
            // Prompt for name input again
			checkname1:
			printf("Enter the book name : ");
			strcpy(name,takestring_v2());
			if(!check_name(name))
			{
				printf("Invalid name (please enter only letters)\n");
				goto checkname1;
			}
            // Reset temp pointer to head for rechecking
            search = head;
        } 
		else
		{
            search = search->next;
        }
    }
	ptr->name = (char*)malloc(max * sizeof(char));
    strcpy(ptr->name, name);
	search = head;
	id = (char*)malloc(max * sizeof(char));
	printf("Enter the book ID : ");
	strcpy(id,takestring_v2());
	 while (search != NULL) {
        if (strcmp(search->id, id) == 0) {
            printf("\nID Already Exists.\n");
            // Prompt for ID input again
            printf("\nEnter ID: ");
             strcpy(id, takestring_v2());
            // Reset temp pointer to head for rechecking
            search = head;
        } else {
            search = search->next;
        }
    }
	ptr->id = (char*)malloc(max * sizeof(char));
    strcpy(ptr->id, id);
	
	check:
	printf("Enter the the price  : ");
	ptr->price = (char*)malloc(max * sizeof(char));
	strcpy(ptr->price,takestring_v2());
	if(!check_number(ptr->price))
	{
		printf("number of price should be numerical\n");
		goto check;
	}
	
	
	
	ptr->author = (char*)malloc(max * sizeof(char));
	checkname2:
	printf("Enter the author name : ");
	strcpy(name,takestring_v2());
	if(!check_name(name))
	{
		printf("Invalid name (please enter only letters)\n");
		goto checkname2;
	}
	
	strcpy(ptr->author,name);
	check1:
	printf("Enter the total number of its version : ");
	ptr->total_number = (char*)malloc(max * sizeof(char));
	strcpy(ptr->total_number,takestring_v2());
	if(!check_number(ptr->total_number))
	{
		printf("number of book should be numerical\n");
		goto check1;
	}
	
	ptr->borrowed = 0;
	
}
void VAbooks()// view all books
{
	struct book *temp = head;
	char *reverted = (char*)malloc(max *sizeof(char));
	if(head==NULL)
	{
    printf("empty list \n");
	}
	while(temp)
	{
		
		strcpy(reverted, temp->name);											
        printf("\nName : %s\n",revert_spaces(reverted));
		printf("id : %s\n",temp->id);
		printf("price : %s\n",temp->price);
		strcpy(reverted, temp->author);											
        printf("author : %s\n",revert_spaces(reverted));
		printf("amount : %s\n",temp->total_number);
		printf("Borrowed: %d\n",temp->borrowed);
		printf("--------------------------------------------\n\n");
		temp = temp->next;
	}
	free(reverted);
	
}

void SearchBookName()//search with name
{
	struct book *temp = head;
	char *reverted = (char*)malloc(max *sizeof(char));
	char *name;
	int found = 1;
	name = (char*)malloc(max * sizeof(char));
	printf("Enter the book name : ");
	strcpy(name, takestring_v2());
	while(temp)
	{
		if(!strcmp(name,temp->name))
		{
			found = 0;
			strcpy(reverted, temp->name);											
            printf("\nName : %s\n",revert_spaces(reverted));
			printf("id : %s\n",temp->id);
			printf("price : %s\n",temp->price);
			strcpy(reverted, temp->author);											
			printf("author : %s\n",revert_spaces(reverted));
			printf("amount : %s\n",temp->total_number);
			break;
		}
		temp = temp->next;
	}
	free(reverted);
	
	if(found)
	{
		printf("This book does NOT exist...\n");
	}
	
}

void SearchBookId()//search with id
{
	struct book *temp = head;
	char *reverted = (char*)malloc(max *sizeof(char));
	char *id;
	int found = 1;
	id = (char*)malloc(max * sizeof(char));
	printf("Enter the book ID : ");
	strcpy(id, takestring_v2());
	while(temp)
	{
		if(!strcmp(id,temp->id))
		{
			found = 0;
			strcpy(reverted, temp->name);											
            printf("\nName : %s\n",revert_spaces(reverted));
			printf("id : %s\n",temp->id);
			printf("price : %s\n",temp->price);
			strcpy(reverted, temp->author);											
			printf("author : %s\n",revert_spaces(reverted));
			printf("amount : %s\n",temp->total_number);
			break;
		}
		temp = temp->next;
	}
	free(reverted);
	
	if(found)
	{
		printf("This book does NOT exist...\n");
	}
	
}

void SearchBookAuther()//search with author
{
	struct book *temp = head;
	char *reverted = (char*)malloc(max *sizeof(char));
	char *author;
	int found = 1;
	author = (char*)malloc(max * sizeof(char));
	printf("Enter the book author : ");
	strcpy(author, takestring_v2());
	while(temp)
	{
		if(!strcmp(author,temp->author))
		{
			found = 0;
			strcpy(reverted, temp->name);											
            printf("\nName : %s\n",revert_spaces(reverted));
			printf("id : %s\n",temp->id);
			printf("price : %s\n",temp->price);
			strcpy(reverted, temp->author);											
			printf("author : %s\n",revert_spaces(reverted));
			printf("amount : %s\n",temp->total_number);
			printf("-----------------------------------\n\n");
		}
		temp = temp->next;
	}
	free(reverted);
	
	if(found)
	{
		printf("%s works are NOT available now\n",author);
	}
	
}

void RemoveBook() // remove book
{
	char* name;
	char* id;
	int found = 0;
	name = (char*)malloc(max * sizeof(char));
	id = (char*)malloc(max * sizeof(char));
	printf("Enter the book name : ");
	strcpy(name,takestring_v2());
	printf("Enter the book ID : ");
	strcpy(id,takestring_v2());
	    if (head) 
		{
            struct book *temp = head;
            struct book *pre = NULL;
            while (temp) 
			{
                if (!strcmp(temp->id, id) && !strcmp(temp->name, name))
					{
                    if (pre) 
					{
                        pre->next = temp->next;
                    } 
					else 
					{
                        head = temp->next;

                    }
                    free(temp);
                    found = 1;
                    printf("\t\t\t\t[[ Book is deleted successfully ]]\n");
                    break;
                }

                pre = temp;
                temp = temp->next;
            }
        }
        if(!found)
            printf("\nThis Book does NOT exist\n");
	
	
}

void BorrowBook(struct user *temp)
{
	struct book *Bptr = head;
	char *name;
	int found = 1;
	name = (char*)malloc(max * sizeof(char));
	char *reverted = (char*)malloc(max *sizeof(char));
	printf("Enter the book name : ");
	strcpy(name, takestring_v2());
	while(Bptr)
	{
		if(!strcmp(name,Bptr->name))
		{
			
			
			if(Bptr->total_number)
			{
				found = 0;
				
			strcpy(reverted, Bptr->name);											
            printf("\nName : %s\n",revert_spaces(reverted));
			printf("id : %s\n",Bptr->id);
			strcpy(reverted, Bptr->author);											
			printf("author : %s\n",revert_spaces(reverted));
			
			}
			else
			{
				found = 1;
			}
			break;
		}
		Bptr = Bptr->next;
	}
	free(reverted);
	free(name);
	
	if(found)
	{
		printf("This book is NOT Available NOW...\n");
	}
	else
	{
	
		if((temp->BorrowedNumber) == 0)
		{
			temp->BorrowedBooks1 = (char*)malloc(max * sizeof(char));
			strcpy(temp->BorrowedBooks1,Bptr->name);
			(temp->BorrowedNumber)++;
			(Bptr->borrowed)++;
			sprintf(Bptr->total_number,"%d",atoi(Bptr->total_number)-1);
		}
		else if((temp->BorrowedNumber) == 1)
		{
			temp->BorrowedBooks2 = (char*)malloc(max * sizeof(char));
			strcpy(temp->BorrowedBooks2,Bptr->name);
			(temp->BorrowedNumber)++;
			(Bptr->borrowed)++;
			  sprintf(Bptr->total_number,"%d",atoi(Bptr->total_number)-1);
		}
		else
		{
			printf("\nYou've exceeded the limit, so you can't borrow this book.\n\n");
		}	
		
		
	}
}






void ReturningBooks(struct user *temp)
{
	struct book *Bptr = head;
	char *name;
	int found = 1;
	name = (char*)malloc(max * sizeof(char));
	printf("Enter the book name : ");
	strcpy(name, takestring_v2());
	
	if(!strcmp(name,temp->BorrowedBooks1))
	{
		strcpy(temp->BorrowedBooks1,temp->BorrowedBooks2);
		temp->BorrowedBooks2 = "empty";
		(temp->BorrowedNumber)--;
			(Bptr->borrowed)--;
			sprintf(Bptr->total_number,"%d",atoi(Bptr->total_number)+1);
		
	}
	else if(!strcmp(name,temp->BorrowedBooks2))
	{
		temp->BorrowedBooks2 = "empty";
		(temp->BorrowedNumber)--;
		(Bptr->borrowed)--;
		sprintf(Bptr->total_number,"%d",atoi(Bptr->total_number)+1);
	}
	else
	{
		printf("You Did NOT borrow this Book.\n");
	}
	
	
}

void BuyingBook(struct user *temp)
{
	struct book *Bptr = head;
	char *reverted = (char*)malloc(max *sizeof(char));
	char *name;
	int found = 1;
	name = (char*)malloc(max * sizeof(char));
	printf("Enter the book name : ");
	strcpy(name, takestring_v2());
	while(Bptr)
	{
		if(!strcmp(name,Bptr->name))
		{
			
			
			if(atoi(Bptr->total_number) > 0)
			{
				found = 0;
				
				
				strcpy(reverted, Bptr->name);											
				printf("\nName : %s\n",revert_spaces(reverted));
				printf("id : %s\n",Bptr->id);
				strcpy(reverted, Bptr->author);											
				printf("author : %s\n",revert_spaces(reverted));	
				printf("price : %s\n",Bptr->price);	
			}
			else
			{
				found = 1;
			}
			break;
		}
		Bptr = Bptr->next;
	}
	
	free(reverted);
	free(name);
	
	if(found)
	{
		printf("This book is NOT Available NOW...\n");
	}
	else
	{
		char *way;
		way = (char*)malloc(max * sizeof(char));
		printf("Buying process by (1- library card ... 2- cash ) : ");
		strcpy(way,takestring_v2());
		if(!strcmp(way,"1"))
		{
			printf("Enter your card id : ");
			if(!strcmp(temp->card_id,takestring_v2()))
			{
				if(atoi(temp->card_balance) >= atoi(Bptr->price))
				{
					sprintf(Bptr->total_number,"%d",atoi(Bptr->total_number)-1);
					sprintf(temp->card_balance,"%d",atoi(temp->card_balance) - atoi(Bptr->price));
					printf("Buying process Done,sir\n");
				
				}
				else
				{
					printf("Your card balance is NOT enough\n");
				}
			}
			else
			{
				printf("Wrong Id\n");
			}
		}
		else if(!strcmp(way,"2"))
			{
			
			sprintf(Bptr->total_number,"%d",atoi(Bptr->total_number)-1);
				printf("Buying process Done,sir\n");
			}
		else
			{
			printf("Invalid Process..\n");
			}
		

	}
}

