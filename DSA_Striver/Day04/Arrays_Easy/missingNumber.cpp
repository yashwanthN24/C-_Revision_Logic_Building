#include <iostream>
#include <vector>

using namespace std;

void findMissingElement(vector<int> arr){

    // given arr of size n-1 but actually element are from 1 to n 
    // sofor 8 elenments arrays we have size as 7 but element from 1 to 8 

    // so only frequncy for all 8 element so array length i.e 7 will give only 0 to 6 but we woant even 8 counbt so 8 still (0 to 7 only so finally 9 whihc is 0 to 8 now have 8 count )

    // so 7 is the size of array arr.siz() + 2 = 9 i.e frequency array legth must be that length
    vector<int> freq(arr.size()+2 , 0);

    for(int i = 0 ; i<arr.size() ; i++){
        freq[arr[i]]++;
    }

    for(int i = 1 ; i<=arr.size()+1 ; i++){
        if(freq[i]==0){
            cout << " Missing number " << i << endl;
        }
    }

}

void method2(vector<int> arr){

    int xor1 = 0 , xor2 = 0;

    for(int i = 0 ; i<arr.size(); i++){
        xor1 = xor1 ^ arr[i];   
    }

    cout << xor1 << endl;

    for(int i = 1 ; i<=arr.size()+1 ; i++){
        xor2 = xor2 ^ i;
    }

    cout << xor2 << endl;

    cout << (xor2 ^ xor1) << endl;
}

int main(){

    vector<int> arr = { 1 , 2 , 3 ,4 , 7 , 5};


    

    findMissingElement(arr);


    method2(arr);
}