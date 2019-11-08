#include <iostream>
#include <vector>

using namespace std;

/*
 * 没事写个快排 快乐下 (*^▽^*)
 * */
void quickSort(std::vector<int>& outOfOrderArray, int left, int right)
{
    int low = left;
    int high = right;
    if (low <= 0 || high >= right)
        return;

    int pivotIndex = low - 1;
    int pivot = outOfOrderArray[pivotIndex];
    while (low < high)
    {
       while(high > low)
       {
           if (outOfOrderArray[high] < pivot)
               break;

           --high;
       }

       while(low < high)
       {
           if (outOfOrderArray[low] > pivot)
               break;

           ++low;
       }

       std::swap(outOfOrderArray[low], outOfOrderArray[high]);
    }

    std::swap(outOfOrderArray[low], outOfOrderArray[pivotIndex]);
    quickSort(outOfOrderArray, low, pivotIndex - 1);
    quickSort(outOfOrderArray, pivotIndex + 1, right);
}


int main()
{
    std::vector<int> array{3, 2, 1, 5, 8};
    quickSort(array, 1, 4);

    for (const auto& value : array)
    {
        cout << value << endl;
    }

    return 0;
}
