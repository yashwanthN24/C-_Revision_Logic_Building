#include <bits/stdc++.h>
        using namespace std;
        
        int main() {
            vector<int> v = {10, 20, 30};
            cout << "Size: " << v.size() << endl;
            cout << "Capacity: " << v.capacity() << endl;   
            v.clear();
            cout << "Size after clear: " << v.size() << endl;
            cout << "Capacity after clear: " << v.capacity() << endl;
            return 0;
        }