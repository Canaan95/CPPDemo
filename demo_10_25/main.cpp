#include <iostream>
#include <vector>

using namespace std;

/*
 * 实现一个特殊的类似数组，能批量访问多个位置
 * 形如d[{1, 2, 5}] = 5
 * */

template <typename T>
class MultiOpArray
{
public:
    MultiOpArray() {}
    ~MultiOpArray() {}

    MultiOpArray& operator[] (initializer_list<T> init_index_list)
    {
        for (const auto& index : init_index_list)
        {
            tmp_index.emplace_back(index);
        }

        return *this;
    }

    MultiOpArray& operator= (T value)
    {
        for (const auto& index : tmp_index)
        {
            array.resize((index >= array.size()) ? index + 1 : array.size());
            array[index] = value;
        }

        tmp_index.clear();

        return *this;
    }

    void PrintArray()
    {
        for (const auto& value : array)
        {
            cout << value << endl;
        }
    }

private:
    std::vector<int> tmp_index;
    std::vector<T> array;
};

int main()
{
    MultiOpArray<int> array;
    array[{1, 2, 5, 6}] = 5;
    array.PrintArray();

    return 0;
}
