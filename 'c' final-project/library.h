#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Global Declarations
#define max 88
extern char adpas[30];
extern char check[4];
struct user {
    char *name;
    char *id;
    char *pass;
    char *card_id;
    char *card_balance;
    char *BorrowedBooks1;
    char *BorrowedBooks2;
    int BorrowedNumber;
    
    struct user *Next;
};


 struct admin
{
	char *id;
	char *pass;
	char *permissions;
	
	struct admin *NEXT;
	
};
 struct book
{
	char *name;
	char *id;
	char *author;
	char *price;
	char *total_number;
	int borrowed;
	
	struct book *next;
};
struct admin *HEAD;
struct user *Head;
struct book *head;


//Global temporarely object to save data temporarely



//FUNCTION TO CREATE A STUDENT AND STORE THEM IN A STRUCTURE
//struct student *createStudent(char id[], char *paswrd, char phnum[], char *name, char gender[], char grd[]);

//TAKING STRING AS INPUT DYNAMICALLY "FUNCTION"
char *takestring_v2();

//SAVING CHANGES MADE FUNCTION
bool save();

//FUNCTION TO REVERT SPACES
char *revert_spaces(char *name);



// @ FILE HANDLING >>
// <<<<<<<<<<<<<<<<user>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Function to create a new user node
struct user* createUser(const char *,const char *,const char *,const char *,const char *,const char *,const char *, int);

// Function to read data from user file into linked list
void readUFile(struct user** , const char* );

// Function to write data from linked list to file
void writeUFile(struct user* , const char* );
//<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// <<<<<<<<<<<<<<<<admin>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Function to create a new admin node
struct admin* createAdmin(const char *, const char *,const char *);

// Function to read data from admin file into linked list
void readAFile(struct admin** , const char* );

// Function to write admin data from linked list to file
void writeAFile(struct admin* header, const char* filename); 

//<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// <<<<<<<<<<<<<<<<admin>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Function to create a new book node
struct book* createBook(char *, char *, char *, char *, char *, int);

// Function to read data from book file into linked list
void readBFile(struct book** , const char*);

// Function to write book data from linked list to file
void writeBFile(struct book* , const char* ); 

//<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// @ FILE HANDLING >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>




//Validate Name
bool check_name(const char* name);
//Validate numbers
bool check_number(const char* temp);
#endif //PROJECT_LIBRARY_H
