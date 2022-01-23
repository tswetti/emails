# Email
This is a console application for managing emails.

##### It has the following functionalities:
 - creating an account
 - logging in the account
 - deleting the account
 - viewing all mails' numbers and subjects
 - viewing a specific mail
 - sending mails to other accounts (who are also users of this application)

##### How to use:
When you open the application you are directed to the start menu, which contains three options. You can choose between logging in, registering and quitting the application. You have 3 attempts at logging in before the application closes. When you register, you have to choose a username and a password. You'll be notified if the username is unavailable or invalid and if the password is invalid. The quit option you may use at any time except when typing a new mail's subject/content. If you type a wrong command, you'll be asked to type it again. 

After a successfull login or registration, you are redirected to the main menu, which offers 5 functionalities.
 - The first option is to close your account - you have to type your password for security and then all your information is deleted.
 - The second option is to see your inbox - it shows your mails' number and subject in ascending order by number.
 - The third option is to logout - you are redirected to the start menu.
 - The fourth option is to open a mail - you are asked to type which mail you want to open and you can then see its information (if the mail exists).
 - The fifth option is to send a new mail - you have to type the receiver's username, the subject and the content of the mail. Note: you cannot send mails to yourself or to a user who's not registered. The subject cannot be empty.

##### Files:
- **Email.cpp** - the starting point of the application, contains the main() function
- **LoadEmail.cpp** - contains a function which manages the two main menus
- **StartMenu.cpp** - shows the start menu and manages the user's command input
- **MainMenu.cpp** - shows the main menu and mannages the user's command input
- **Login.cpp** - manages the log in process
- **Registration.cpp** - manages the registration process
- **CloseAccount.cpp** - deletes the user's information from the application
- **Inbox.cpp** - allows the user to see their mails' numbers and subjects
- **OpenMail.cpp** - allows the user to open a specific mail
- **SendMail.cpp** - allows the user to send mails to other users of this application
- **Validation.cpp** - has validation functions which are used throughout the application
All .cpp files except the first have a .h file with the same name, which contains the functions' declarations for that .cpp file.
While using the application, additional folders and .txt files may be created. When opening the application for the first time, a file "users.txt" is created, where all users and their hashed passwords are stored. Each user has their own folder which contains their mails and a log file called "totalMails.txt", which notifies them that they received a new mail. For proper work of the application, a mail's subject and content length should be maximum one line.
When deleting an account, all their data is removed.

##### Libraries used:
 - <iostream> - standart input and output
 - <string> - used to store text
 - <fstream> - used to manage the text files
 - <map> - used for the container map which stores the users' usernames(key) and hashed passwords(value)
 - <unordered_map> - used for its hash function
 - <direct.h>	- used to create and delete directories
 - <cstdio> - used for the remove and rename functions
 Linux, not tested - <sys/types.h>, <sys/stat.h> - to create a directory
<unistd.h> - to delete a directory
  
##### OS
The application may work for both Windows and Linux OS. However, the Linux optimisation has not been tested and may not work properly. It can be found in "Registration.cpp" and "CloseAccount.cpp" in the create and delete directory functions.
