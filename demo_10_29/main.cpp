#include <iostream>

using namespace std;

/*
 * POD 相关
 * */

struct Base1
{};

struct Base2
{};

struct Drived1 : public Base1
{
    Base1 b;
    int value;
};

struct Drived2 : public Base1
{
    Base2 b;
    int value;
};

int main()
{
    Drived1 d1;
    Drived2 d2;

    cout << hex;

    cout << reinterpret_cast<long long>(&d1) << endl;;
    cout << reinterpret_cast<long long>(&(d1.b)) << endl;
    cout << reinterpret_cast<long long>(&(d1.value)) << endl;

    cout << "-------------------------" << endl;

    cout << reinterpret_cast<long long>(&d2) << endl;
    cout << reinterpret_cast<long long>(&(d2.b)) << endl;
    cout << reinterpret_cast<long long>(&(d2.value)) << endl;

    return 0;
}
