// https://chatgpt.com/c/6a79d1a2-b090-83ee-bfab-775416335edc


/*

Question 3 : Given an array of integers. Find the Inversion Count in the array. (HARD)
Inversion Count: For an array, inversion count indicates how far (or close) the array is
from being sorted. If the array is already sorted then the inversion count is 0. If an array
is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
Sample Input 1 : N = 5, arr[ ] = {2, 4, 1, 3, 5}
Sample Output 1 : 3, because it has 3 inversions - (2, 1), (4, 1), (4, 3).
Sample Input 2 : N = 5, arr[ ] = {2, 3, 4, 5, 6}
Sample Output 2 : 0, because the array is already sorted
Sample Input 3 : N = 3, arr[] = {5, 5, 5}
Sample Output 3 : 0, because all the elements of the array are the same & already in a
sorted manner.
(Hint : A sorting algorithm will be used to solve this question.)
Note - This question is important. Even if you are not able to come up with the approach,
please understand the solution





*/

#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    long long invCount = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);

            // Count inversions
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= high)
        temp.push_back(arr[j++]);

    for (int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }

    return invCount;
}

long long mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long leftInv = mergeSort(arr, low, mid);
    long long rightInv = mergeSort(arr, mid + 1, high);
    long long mergeInv = merge(arr, low, mid, high);

    return leftInv + rightInv + mergeInv;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};

    cout << "Inversion Count = "
         << mergeSort(arr, 0, arr.size() - 1);

    return 0;
}