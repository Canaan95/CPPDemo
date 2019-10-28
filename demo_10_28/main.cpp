#include <iostream>

using namespace std;

/*
 * 类型收窄
 * */

int main()
{
    char* c = new char(1024);
    cout << (int)*c << endl;

    char *d = new char{1024};

    return 0;
}
