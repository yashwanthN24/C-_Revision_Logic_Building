#include <iostream>
#include <vector>

using namespace std;

int main(){
    // vector<int> v2 = {2 , 7 , 11 , 14};
    int n ;
    cout << "Enter number of elements : " ;
    cin >> n;
    vector<int> v1(n);
    
    for(int i =0 ; i<v1.size() ; i++){
        cout << v1.at(i) << " ";
    }
    cout << endl;


    for(int i = 0 ; i<v1.size() ; i++){
        cin >> v1[i];
    }

    

    
    


}