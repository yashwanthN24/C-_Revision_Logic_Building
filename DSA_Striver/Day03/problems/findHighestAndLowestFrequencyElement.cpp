#include <bits/stdc++.h>
using namespace std;

// Class to count frequencies and find elements with max and min frequency
class FrequencyCounter {
public:
    void countFreq(int arr[], int n)
    {
        vector<bool> visited(n, false); // Track which elements have already been processed
        int maxFreq = 0, minFreq = n;   // Initialize frequency bounds
        int maxEle = 0, minEle = 0;     // Initialize elements with max and min frequency

        for (int i = 0; i < n; i++) {

            // Skip this element if it's already counted
            if (visited[i] == true)
                continue;

            // Count the frequency of arr[i]
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    visited[j] = true; // Mark as visited to avoid recounting
                    count++;
                }
            }

            // Update max frequency and corresponding element
            if (count > maxFreq) {
                maxEle = arr[i];
                maxFreq = count;
            }

            // Update min frequency and corresponding element
            if (count < minFreq) {
                minEle = arr[i];
                minFreq = count;
            }
        }

        // Output the results
        cout << "The highest frequency element is: " << maxEle << "\n";
        cout << "The lowest frequency element is: " << minEle << "\n";
    }
};

int main()
{
    FrequencyCounter fc;                      // Create object of class
    int arr[] = {10, 5, 10, 15, 10, 5};       // Input array
    int n = sizeof(arr) / sizeof(arr[0]);    // Calculate array length
    fc.countFreq(arr, n);                    // Call the function
    return 0;
}
