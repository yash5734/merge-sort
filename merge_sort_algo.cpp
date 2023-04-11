
// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &array, int left, int mid, int right)
{
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {

        if (array[i] <= array[j])
        {
            temp.push_back(array[i]);
            ++i;
        }
        else
        {
            temp.push_back(array[j]);
            ++j;
        }
    }

    while (i <= mid)
    {
        temp.push_back(array[i]);
        ++i;
    }

    while (j <= right)
    {
        temp.push_back(array[j]);
        ++j;
    }

    for (int i = left; i <= right; ++i)
        array[i] = temp[i - left];
}

void mergeSort(vector<int> &array, int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mergeSort(array, l, mid);
    mergeSort(array, mid + 1, r);
    merge(array, l, mid, r);
}

int main()
{
    int n = 6;
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Given array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
