#include <iostream>
using namespace std;
struct user
{
    /* data */
};

struct book
{
    /* data */
};

struct library
{
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
