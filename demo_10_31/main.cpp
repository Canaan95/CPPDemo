#include <iostream>

using namespace std;

double& func()
{
    static double t = 1.2;
    return t;
}

int main()
{
    double& dp = func();
    cout << dp << endl; 

    return 0;
}
