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
    user borrowedUsers[100]; // assume that only 100 users can borrow this book
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
    void AddUserToBorrowed(user u)
    {
        borrowedUsers[userBorrowedLen++] = u;
    }
};

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
        book B;
        user U;
        cout << "Enter the book name : ";
        cin >> bookName;
        cout << "Enter the user name : ";
        cin >> userName;

        // get the book by name
        bool isValidBook=false;
        for (size_t i = 0; i < booksLen; i++)
        {
            if (bookName == books[i].name)
            {
                B = books[i];
                isValidBook=true;
                break;
            }
        }
        // check is valid book name or not
        if(isValidBook){
            cout<<"there are not book by this name"<<endl;
            cout << "**************************************************" << endl;
            return;
        }

        // get the user by name
        for (size_t i = 0; i < usersLen; i++)
        {
            if (userName == users[i].name)
            {
            }
        }
    }

    void printAllUsers()
    {
        cout << " ******************  all user  *********************" << endl;
        for (size_t i = 0; i < usersLen; i++)
        {
            cout << "user number " << i + 1;
            cout << " , Name :" << users[i].name << " , Id : " << users[i].id << endl;
        }
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
        for (size_t i = 0; i < booksLen; i++)
        {
            cout << "Book :" << books[i].name << " , Id : " << books[i].id << ", quantity: " << books[i].quantity << endl;
        }
        cout << "**************************************************" << endl;
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
                cout << "add new book" << endl;
            }
            else if (choice == 4)
            {
                printAllBooks();
                cout << "print all books" << endl;
            }
            else if (choice == 5)
            {
                cout << "borrow book" << endl;
            }
            else if (choice == 6)
            {
                cout << "return book" << endl;
            }
            else if (choice == 7)
            {
                cout << "print all user who borrow a book" << endl;
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
    library l;
    l.run();

    return 0;
}
