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

bool isPrfix(string s, string name)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!(s[i] == name[i]))
            return false;
    }
    return true;
}

struct book
{
    int id;
    string name;
    int quantity;
    string borrowedUsers[20]; // assume that only 100 users can borrow this book
    int userBorrowedLen;
    book(){

    };

    // add new book using method
    void addNewBook(int _id, string _name, int _quantity)
    {
        id = _id;
        name = _name;
        quantity = _quantity;
        userBorrowedLen = 0;
    }

    // borrow function
    bool canBorrow()
    {
        if (quantity > 0)
            return true;
        return false;
    }
    // add user to userborrowed array to used for borrow book funciton
    void AddUserToBorrowed(string s)
    {
        borrowedUsers[userBorrowedLen++] = s;
        quantity--;
    }

    bool isBorrowd(string userName)
    {
        for (size_t i = 0; i < userBorrowedLen; i++)
        {
            if (userName == borrowedUsers[i])
            {
                return true;
            }
        }
        return false;
    }

    bool hasPrfix(string s)
    {
        if (s.length() > name.length())
            return false;
        if (isPrfix(s, name))
            return true;
        return false;
    }

    void removeBorrowUser(string userName)
    {
        int index = -1;
        for (size_t i = 0; i < userBorrowedLen; i++)
        {
            if (userName == borrowedUsers[i])
            {
                index = i;
            }
            break;
        }
        // remove the name from the borrowdedUsers array  => shift left
        for (size_t i = index; i < userBorrowedLen - 1; i++)
        {
            borrowedUsers[i] = borrowedUsers[i + 1];
        }

        // increase the quantity and decrease userborrowlen;
        quantity++;
        userBorrowedLen--;
    }
    void print()
    {
        cout << "book id : " << id << " , book name : " << name << " ,book quantity : " << quantity << endl;
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

void printUserByName(user arr[], int len, string name)
{
    int cnt = 1;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i].name == name)
        {
            cout << cnt << " )";
            cout << " Name :" << arr[i].name << " , Id : " << arr[i].id << endl;
        }
        cnt++;
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
    }
    return false;
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
    }
    return false;
}
// get user by name
int getUserIndexByName(user arr[], int len, string userName)
{
    for (size_t i = 0; i < len; i++)
    {
        if (userName == arr[i].name)
        {
            return i;
        }
    }
    return -1;
}

// get book by name
int getBookIndexByName(book arr[], int len, string bookName)
{
    for (size_t i = 0; i < len; i++)
    {
        if (bookName == arr[i].name)
        {
            return i;
        }
    }
    return -1;
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
    
    void searchForBook()
    {
        string s;
        cout << "Enter the bookName or some letter of it : ";
        cin >> s;
        for (size_t i = 0; i < booksLen; i++)
        {
            if (books[i].hasPrfix(s))
            {
                books[i].print();
            }
        }
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
        // get book index and user index
        int bookIndex = getBookIndexByName(books, booksLen, bookName);
        int userIndex = getUserIndexByName(users, usersLen, userName);

        // check if this user is borrowed this book?
        bool isborrowed = books[bookIndex].isBorrowd(userName);
        if (isborrowed)
        {
            cout << "you can't borrow two copies from this book, you already borrow one" << endl;
            cout << " ***************************************" << endl;
            return;
        }
        // check if there are available copies to borrow;
        bool canBorrow = books[bookIndex].canBorrow();
        if (!canBorrow)
        {
            cout << "the quantity of this book exits, you can't borrow " << endl;
            cout << " ***************************************" << endl;
            return;
        }
        // borrow operation
        books[bookIndex]
            .AddUserToBorrowed(userName);
    }

    // return book function
    void userRetrunBook()
    {
        string bookName;
        string userName;

        cout << "Enter the book name : ";
        cin >> bookName;
        cout << "Enter the user name : ";
        cin >> userName;

        // check if valid user and book or not
        if (!(isValidBook(books, booksLen, bookName) && isValidUser(users, usersLen, userName)))
        {
            cout << "the inputes (user,book) doesn't true you should Enter valid book or user " << endl;
            cout << "**************************************************" << endl;
            return;
        }

        int bookIndex = getBookIndexByName(books, booksLen, bookName);
        int userIndex = getUserIndexByName(users, usersLen, userName);

        // check if this user is borrowed this book?
        bool isborrowed = books[bookIndex].isBorrowd(userName);
        if (!isborrowed)
        {
            cout << "user did't borrow this book you can't retun it !!" << endl;
            cout << " ***************************************" << endl;
            return;
        }
        // remove from array operation
        books[bookIndex].removeBorrowUser(userName);
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

        int bookIndex = getBookIndexByName(books, booksLen, bookName);

        // print all users from user borrowed array
        cout << " ******************  users who borrow book  *********************" << endl;
        for (size_t i = 0; i < books[bookIndex].userBorrowedLen; i++)
        {
            printUserByName(users, usersLen, books[bookIndex].borrowedUsers[i]);
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
        cout << "8) Search for book  " << endl;
        cout << "9) Exit " << endl;
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
                userRetrunBook();
            }
            else if (choice == 7)
            {
                printBorrowedUsers();
            }
            else if (choice == 8)
            {
                searchForBook();
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
