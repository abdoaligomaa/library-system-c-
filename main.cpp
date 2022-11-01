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
    /* data */
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
        users[usersLen++]=u;
    }

    void printAllUsers(){
        for (size_t i = 0; i < usersLen; i++)
        {
            cout<< "user :"<<users[i].name<<" , Id : "<<users[i].id<<endl;
        }
        
    }



    void run()
    {
        cout << "the system is running" << endl;
    }
};

int main()
{
    library l;
    l.addUser();
    l.addUser();
    l.printAllUsers();

    return 0;
}
