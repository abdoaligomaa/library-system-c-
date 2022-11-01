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
    user(int Id,string S){
        id=Id;
        name=S;
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
    user users[maxUssers];
    
    
    void run()
    {
        cout << "the system is running" << endl;
    }
};

int main()
{
    library l;
    l.run();

    return 0;
}
