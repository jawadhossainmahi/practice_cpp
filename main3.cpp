#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int binary_search(int arr[], int search, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start <= end)
    {
        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] >= search)
        {
            binary_search(arr, search, mid + 1, end);
        }
        else
        {
            binary_search(arr, search, start, mid - 1);
        }
    }
    else
    {
        return -1;
    }
}

void file()
{
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
}


int main(void)
{
    file();
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int search;
    cin >> search;

    int result = binary_search(arr, search, 0, n - 1);
    if (result == -1)
    {
        cout << "not found";
    }
    else
    {
        cout << "found in index" << result;
    }
}