#include <iostream>
using namespace std;

const int maxUssers = 1000;
const int maxBooks = 1000;

struct user
{
    int id;
    string name;
    user(){

    };

    user(int Id, string S)
    {
        id = Id;
        name = S;
    };
};

struct book
{
    int id;
    string name;
    int quantity;
    user borrowedUsers[20]; // assume that only 100 users can borrow this book
    int userBorrowedLen;
    book(){

    };

    // add new book using struct
    /* book(int _id,string _name,int _quantity){
        id=_id;
        name=_name;
        quantity=_quantity;
     */

    // add new book using method
    void addNewBook(int _id, string _name, int _quantity)
    {
        id = _id;
        name = _name;
        quantity = _quantity;
        userBorrowedLen = 0;
    }

    // add user to userborrowed array to used for borrow book funciton
    void AddUserToBorrowed(const user &u)
    {
        borrowedUsers[userBorrowedLen++] = u;
    }
};

// methods
// print all users
void PrintUsers(user arr[], int len)
{
    cout << " ******************  all user  *********************" << endl;
    for (size_t i = 0; i < len; i++)
    {
        cout << "user number " << i + 1;
        cout << " , Name :" << arr[i].name << " , Id : " << arr[i].id << endl;
    }
}

// print all books
void PrintBooks(book arr[], int len)
{
    cout << "********************** all books ****************************" << endl;

    for (size_t i = 0; i < len; i++)
    {
        cout << "Book :" << arr[i].name << " , Id : " << arr[i].id << ", quantity: " << arr[i].quantity << endl;
    }
    cout << "**************************************************" << endl;
}
// validate by is valid bookname
bool isValidBook(book arr[], int len, string bookName)
{
    for (size_t i = 0; i < len; i++)
    {
        if (bookName == arr[i].name)
        {
            return true;
        }
        return false;
    }
}

// // validate by is valid user name
bool isValidUser(user arr[], int len, string userName)
{
    for (size_t i = 0; i < len; i++)
    {
        if (userName == arr[i].name)
        {
            return true;
        }
        return false;
    }
}
// get user by name
user getUserByName(user arr[], int len, string userName)
{
    for (size_t i = 0; i < len; i++)
    {
        if (userName == arr[i].name)
        {
            return arr[i];
        }
    }
}

// get book by name
book getBookByName(book arr[], int len, string bookName)
{
    for (size_t i = 0; i < len; i++)
    {
        if (bookName == arr[i].name)
        {
            return arr[i];
        }
    }
}
struct library
{
    user users[maxUssers];
    book books[maxBooks];
    int usersLen;
    int booksLen;

    library()
    {
        usersLen = 0;
        booksLen = 0;
    }
    // users
    void addUser()
    {
        int id;
        string name;

        cout << "User Id : ";
        cin >> id;
        cout << "User name : ";
        cin >> name;
        cout << "**************************************************" << endl;

        // TODO : check if the id is unique or not

        // put the new user in users array;
        user u = user(id, name);
        users[usersLen++] = u;
    }

    void borrowBook()
    {
        string bookName;
        string userName;

        cout << "Enter the book name : ";
        cin >> bookName;
        cout << "Enter the user name : ";
        cin >> userName;

        // TODO : code readable here
        // check if valid user and book or not
        if (!(isValidBook(books, booksLen, bookName) && isValidUser(users, usersLen, userName)))
        {
            cout << "the inputes (user,book) doesn't true you should Enter valid book or user " << endl;
            cout << "**************************************************" << endl;
            return;
        }
        // get the book by name
        // const book &B = getBookByName(books, booksLen, bookName);
        // const user &U = getUserByName(users, usersLen, userName);

        getBookByName(books, booksLen, bookName).AddUserToBorrowed(getUserByName(users, usersLen, userName));
    }

    void printBorrowedUsers()
    {
        string bookName;
        
        cout << "book name : ";
        cin >> bookName;

        // TODO : code readable here
        // validate input
        if (!isValidBook(books, booksLen, bookName))
        {
            cout << "the inputes (,book) doesn't true you should Enter valid book  " << endl;
            cout << "**************************************************" << endl;
            return;
        }

        const book &B=getBookByName(books,booksLen,bookName);
        // print all users from user borrowed array
        cout<<"print all users who borrowed this book"<<endl;
        for (size_t i = 0; i < B.userBorrowedLen; i++)
        {
            cout << i + 1 << ")"
                 << " "
                 << " ,name : " << B.borrowedUsers[i].name << " ,id : " << B.borrowedUsers[i].id << endl;
        }
    }

    void printAllUsers()
    {
        PrintUsers(users, usersLen);
    }

    // books
    void addBook()
    {
        int id, quantity;
        string name;
        cout << " book id : ";
        cin >> id;
        cout << " book name : ";
        cin >> name;
        cout << " book quantity : ";
        cin >> quantity;
        cout << "**************************************************" << endl;

        books[booksLen++].addNewBook(id, name, quantity);
    }

    void printAllBooks()
    {
        PrintBooks(books, booksLen);
    }
    // run prograge

    int menu()
    {
        int TheChoice = -1;
        cout << "Enter you choice" << endl;
        cout << "1) Add new user " << endl;
        cout << "2) Print all users " << endl;
        cout << "3) Add a book " << endl;
        cout << "4) Print all Books " << endl;
        cout << "5) Borrow a Book " << endl;
        cout << "6) Retrun a Book " << endl;
        cout << "7) print all users who borrows a book " << endl;
        cout << "8) Exit " << endl;
        cout << "**************************************************" << endl;
        cout << "Your choice is : ";
        cin >> TheChoice;
        if (!(TheChoice <= 8 && TheChoice >= 1))
        {
            cout << "Your choice in incorrect!!!!!!, please try again " << endl;
            cout << "**************************************************" << endl;
            return menu();
        }
        return TheChoice;
    }

    void run()
    {
        while (true)
        {

            int choice = menu();
            if (choice == 1)
            {
                addUser();
            }
            else if (choice == 2)
            {
                printAllUsers();
            }
            else if (choice == 3)
            {
                addBook();
            }
            else if (choice == 4)
            {
                printAllBooks();
            }
            else if (choice == 5)
            {
                borrowBook();
            }
            else if (choice == 6)
            {
                cout << "return book" << endl;
            }
            else if (choice == 7)
            {
                printBorrowedUsers();
            }
            else
            {
                cout << "The Program is exit" << endl;
                break;
            }
        }
    }
};

int main()
{
    library l = library();
    l.run();

    return 0;
}
