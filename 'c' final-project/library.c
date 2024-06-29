#include "library.h"


char check[4];

// Function to create a new user node
struct user* createUser( const char *name,const char *id,const char *pass,const char *card_id,const char *card_balance,const char *BorrowedBooks1,const char *BorrowedBooks2, int BorrowedNumber)
	{
    struct user* newUser = malloc(sizeof(struct user));
    if (newUser == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newUser->name = (char*)malloc(max * sizeof(char));
    newUser->id = (char*)malloc(max * sizeof(char));
    newUser->pass = (char*)malloc(max * sizeof(char));
    newUser->card_id = (char*)malloc(max * sizeof(char));
    newUser->card_balance = (char*)malloc(max * sizeof(char));
    newUser->BorrowedBooks1 = (char*)malloc(max * sizeof(char));
    newUser->BorrowedBooks2 = (char*)malloc(max * sizeof(char));
	 if (newUser->name == NULL || newUser->pass == NULL || newUser->id == NULL || newUser->card_id == NULL || newUser->card_id == NULL || newUser->BorrowedBooks1 == NULL || newUser->BorrowedBooks2 == NULL) 
	{
        printf("Memory allocation failed.\n");
        free(newUser); // Free allocated memory before returning
        return NULL;
    }
   strcpy(newUser->name, name);
   strcpy(newUser->id, id);
   strcpy(newUser->pass, pass);
   strcpy(newUser->card_id, card_id);
   strcpy(newUser->card_balance, card_balance);
   strcpy(newUser->BorrowedBooks1, BorrowedBooks1);
   strcpy(newUser->BorrowedBooks2, BorrowedBooks2);
   newUser->BorrowedNumber = BorrowedNumber;

   
    
   
    newUser->Next = NULL;

   
    return newUser;
}

// Function to read data from user file into linked list
void readUFile(struct user** header, const char* filename)
 {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char name[max], id[max], pass[max], card_id[max],card_balance[max],BorrowedBooks1[max],BorrowedBooks2[max];int BorrowedNumber;

    while (fscanf(file, "%87s %87s %87s %87s %87s %87s %87s %d", name, id, pass, card_id, card_balance, BorrowedBooks1, BorrowedBooks2, &BorrowedNumber) == 8)
    {
        // Check if memory allocation fails
        struct user* newUser = createUser(name, id, pass, card_id, card_balance, BorrowedBooks1, BorrowedBooks2, BorrowedNumber);
        if (newUser == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        // Insert the new user at the beginning of the list
        newUser->Next = *header;
        *header = newUser;
    }

    // Check if reading stopped due to a format error
    if (!feof(file)) {
        printf("Error reading file. Invalid format.\n");
    }

    fclose(file);
}


// Function to write user data from linked list to file
void writeUFile(struct user* header, const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct user* current = header;
    while (current != NULL) {
        fprintf(file, "%s %s %s %s %s %s %s %d\n", current->name, current->id, current->pass,current->card_id, current->card_balance, current->BorrowedBooks1, current->BorrowedBooks2,current->BorrowedNumber);
        current = current->Next;
    }
    fclose(file);
}


// Function to create a new admin node
struct admin* createAdmin(const char *id, const char *pass,const char* permissions)
	{
    struct admin* newAdmin = malloc(sizeof(struct admin));
    if (newAdmin == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    newAdmin->id = (char*)malloc(max * sizeof(char));
    newAdmin->pass = (char*)malloc(max * sizeof(char));
    newAdmin->permissions = (char*)malloc(max * sizeof(char));
   if (newAdmin->id == NULL || newAdmin->pass == NULL || newAdmin->permissions == NULL)
	{
        printf("Memory allocation failed.\n");
        free(newAdmin); // Free allocated memory before returning
        return NULL;
    }
   
   strcpy(newAdmin->id, id);
   strcpy(newAdmin->pass, pass);
   strcpy(newAdmin->permissions, permissions);
   
   
    newAdmin->NEXT = NULL;

    
    return newAdmin;
}

// Function to read data from admin file into linked list
void readAFile(struct admin** header, const char* filename)
 {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char id[max], pass[max], permissions[max];

    while (fscanf(file, "%87s %87s %87s", id, pass, permissions) == 3)
    {
        // Check if memory allocation fails
        struct admin* newAdmin = createAdmin(id, pass, permissions);
        if (newAdmin == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        // Insert the new user at the beginning of the list
        newAdmin->NEXT = *header;
        *header = newAdmin;
    }

    // Check if reading stopped due to a format error
    if (!feof(file)) {
        printf("Error reading file. Invalid format.\n");
    }

    fclose(file);
}


// Function to write admin data from linked list to file
void writeAFile(struct admin* header, const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct admin* current = header;
    while (current != NULL) {
        fprintf(file, "%s %s %s\n", current->id, current->pass ,current->permissions);
        current = current->NEXT;
    }
    fclose(file);
}














// Function to create a new book node
struct book* createBook(char *name, char *id, char *author, char *price, char *total_number, int borrowed)
	{
    struct book* newBook = malloc(sizeof(struct book));
    if (newBook == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
	newBook->name = (char*)malloc(max * sizeof(char));
    newBook->id = (char*)malloc(max * sizeof(char));
    newBook->author = (char*)malloc(max * sizeof(char));
    newBook->price = (char*)malloc(max * sizeof(char));
    newBook->total_number = (char*)malloc(max * sizeof(char));
   
    if (newBook->id == NULL || newBook->name == NULL || newBook->author == NULL || newBook->price == NULL || newBook->total_number == NULL)
	{
        printf("Memory allocation failed.\n");
        free(newBook); // Free allocated memory before returning
        return NULL;
    }
   
   strcpy(newBook->name, name);
   strcpy(newBook->id, id);
   strcpy(newBook->author, author);
   strcpy(newBook->price, price);
   strcpy(newBook->total_number, total_number);
   newBook->borrowed = borrowed;
   
   
    newBook->next = NULL;

   
    return newBook;
}

// Function to read data from book file into linked list
void readBFile(struct book** header, const char* filename)
 {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char name[max], id[max], author[max], price[max], total_number[max]; int borrowed;

    while (fscanf(file, "%87s %87s %87s %87s %87s %d",name, id, author, price, total_number, &borrowed) == 6)
    {
        // Check if memory allocation fails
        struct book* newBook = createBook(name, id, author, price, total_number, borrowed);
        if (newBook == NULL) 
		{
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        // Insert the new user at the beginning of the list
        newBook->next = *header;
        *header = newBook;
    }

    // Check if reading stopped due to a format error
    if (!feof(file)) {
        printf("Error reading file. Invalid format.\n");
    }

    fclose(file);
}


// Function to write book data from linked list to file
void writeBFile(struct book* header, const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    struct book* current = header;
    while (current != NULL) {
        fprintf(file, "%s %s %s %s %s %d\n",current->name, current->id, current->author, current->price, current->total_number, current->borrowed);
        current = current->next;
    }
    fclose(file);
}



















































char * takestring_v2(){
    char* s = (char *)calloc(1,sizeof(char));
    int len = 1;
    *s = '\0';
    char t;

    t = getchar();

    int c = 1;
    while(t != '\n'){
        if(c == len)
        {
            s = (char *)realloc(s, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(s + c - 1) = t;
        *(s + c) = '\0';
        c++;

        t = getchar();
        if (t == ' ') {
            t = '_';
        }
    }
    fflush(stdin); fflush(stdout);
    if(len == 1)  return takestring_v2();
    if(*s == ' ') {
        printf("Cannot Start With Spaces!\nEnter Again: ");
        return takestring_v2();
    }

    return s;
}

// Saving changes
bool save() {
    //char check[4];
    printf("\nDo you want to Save changes? Press (Y) for yes or any other thing for No : ");
    scanf("%s", check);
    if (!strcmp(check, "Y") || !strcmp(check, "y")) return true;
    else return false;
}

//Revert spaces in names
char* revert_spaces(char* name)
{

    for(int i = 0; i< strlen(name); i++) {
        if (name [i] == '_') {
            name [i] = ' ';
        }
    }
    return name;
}



//check phone number validation
bool check_name(const char* name) 
{
    // Check if the string contains only numeric characters
    for (int i = 0; name[i] != '\0'; i++) {
        if (isdigit(name[i])) 
		{
            return false; // Non-numeric character found
        }
    }
    return true;

}
bool check_number(const char* temp) {
    // Check if the string contains only numeric characters
    for (int i = 0; temp[i] != '\0'; i++) {
        if (!isdigit(temp[i])) {
            return false; // Non-numeric character found
        }
    }
    return true;

}


//admin password write file
/*void admin_File(char current[], const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s" ,current);

    fclose(file);
}


//admin password read file
//Function to read data from file into linked list
void admin_read(char pass[30], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the password from the file
    if (fscanf(file, "%29s", pass) != 1) {
        printf("Error reading password from file.\n");
        fclose(file);
        return;
    }

    fclose(file);

    // Update the global admin password variable
    strcpy(adpas, pass);
}*/

/*void freeList(struct student *header) {
    struct student *current = header;
    struct student *next;

    while (current != NULL) {
        next = current->next; // Store the next pointer before freeing the current node
        free(current); // Free the memory allocated for the current node
        current = next; // Move to the next node
    }
}*/