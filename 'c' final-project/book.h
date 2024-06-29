#ifndef PROJECT_BOOK_H
#define PROJECT_BOOK_H



#include "library.h"


void add_book();

void VAbooks();

void RemoveBook();

void SearchBookName();

void SearchBookId();

void SearchBookAuther();

void BorrowBook(struct user *);

void ReturningBooks(struct user *temp);

void BuyingBook(struct user *temp);

#endif