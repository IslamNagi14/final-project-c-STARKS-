![MasterHead]([https://img.freepik.com/free-vector/colorful-welcome-lettering-modern-banner-invitation_1017-50216.jpg?t=st=1714678657~exp=1714682257~hmac=e2d86abf6913cfea54eec94656ee7ffaf6287f0fca13ce6fcafa1e7750fa352b&w=1800](https://i.giphy.com/media/v1.Y2lkPTc5MGI3NjExd2o1Y3A5ZDduOHBtbGhoc21sOHQybmxmMjVvZGYwdzk0NW85OWY0OSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/felyWZRMgfd28/giphy.gif))
# Library management system

~ Overview:

The Library management system is a project designed to efficiently manage library information. It provides a user-friendly interface for adding (admins - users - books), removing (admins - users - books) , updating data of (admins - users - books), and searching (admins - users - books). 

~ Features:

	•	Add Admin : Allows owner to add a new Admin with details such as ID , password and thier permissions.
	•	Remove Admin: Enables owner to remove a Admin based on unique identifiers like admin ID.
	•	Add user : Allows owner or admin(who has permission) to add a new user with details such as ID , name , password , Card Id , Card balance.
	•	Remove user: Enables owner or admin(who has permission) to remove a user based on unique identifiers like user ID.
	•	Add Book : Allows owner or admin(who has permission) to add a new Book with details such as ID , name , auther , price , total amount.
	•	Remove Book: Enables owner or admin(who has permission) to remove a Book based on unique identifiers like book name.
 
	

~ File Structure:

	•	interface.c: Contains the main program logic and user interface for interacting with the     system.
	•	interface.h: Header file containing function declarations for the interface.
	•	admin.h: Header file containing admin's function declarations.
	•	user.h: Header file containing  user's function declarations.
    •book.h: Header file containing  book's function declarations.
    • library.h :  Header file containing  (admin/user/book) related data structure and additional function declarations


~ Technologies Used:

	•	Language: C

~ Usage:

	•Owner abilites : 
 	1- Add new Admin              2- Remove Admin
    3- Veiw all admins            4- Edit Admin permissions
    5- Add new User               6- Edit user ID
    7- Delete user by their ID    8- Veiw all users
    9- Add new Book               10- Remove Book
    11- Veiw all books

    
    •Admin abilites : 
    1- Add new User                2- Remove User
    3- Veiw all Users              4- Edit user ID              
    5- Add new Book                6- Remove Book
	7- Veiw all books

     •User abilites : 
      1- Veiw user's data
      2- Edit Your pass
      3- search By book name
      4- search By book id 
      5- search By book author
      6- Borrow Book
      7- Return book to library
      8- Buying Book
