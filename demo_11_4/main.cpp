#include <iostream>
#include <typeinfo>

using namespace std;


class DataType1{};
class DataType2{};
template <typename T>
class DataType
{
    T value;
};

int main()
{
    cout << "CMake test demo" << endl;

    int i_1;
    DataType1 d_1;
    DataType2 d_2;
    DataType<char> cd;

    cout << typeid(i_1).name() << "\t" << typeid(i_1).hash_code() << endl;
    cout << typeid(d_1).name() << "\t" << typeid(d_1).hash_code() << endl;
    cout << typeid(d_2).name() << "\t" << typeid(d_2).hash_code() << endl;
    cout << typeid(cd).name() << "\t" << typeid(cd).hash_code() << endl;


    return 0;
}
