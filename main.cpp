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

        // TODO : check if the id is unique or not

        // put the new user in users array;
        user u = user(id, name);
        users[usersLen++] = u;
    }

    void printAllUsers()
    {
        for (size_t i = 0; i < usersLen; i++)
        {
            cout << "user :" << users[i].name << " , Id : " << users[i].id << endl;
        }
    }

    // books
    void addBook()
    {
        int id, quantity;
        string name;
        cout << " book id : ";
        cin >> id;
        cout<<" book name : ";
        cin >> name;
        cout << " book quantity : ";
        cin >> quantity;
        books[booksLen++].addNewBook(id,name,quantity);
    }

    void printAllBooks()
    {
        for (size_t i = 0; i < booksLen; i++)
        {
            cout << "Book :" << books[i].name << " , Id : " << books[i].id << ", quantity: " <<books[i].quantity<< endl;
        }
    }

    int menu(){
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
        
        cout << "the system is running" << endl;
    }
};

int main()
{
    library l;
    l.addBook();
    l.addBook();
    l.addBook();
    l.printAllBooks();

    return 0;
}
