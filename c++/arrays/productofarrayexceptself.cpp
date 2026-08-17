#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    
    // Calculate the product of all elements to the left of each index
    int leftProduct = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }
    
    // Calculate the product of all elements to the right of each index
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}

int main(){
    vector<int> v = {1 , 2 , 4 , 6};

    vector<int> ans = productExceptSelf(v);

    for(int c: ans){
        cout << c << " ";
    }   

    
}