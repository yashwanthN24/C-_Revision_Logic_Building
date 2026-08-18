#include <iostream>


using namespace std; 

template<typename T , size_t N>
void printArray(T (&arr)[N]){
    cout << "[" ;
    for(size_t i = 0; i<N ; i++){
        cout << arr[i];
        if(i != N-1) cout << ", ";
    }
    cout << "]\n"; 
}


int main(){
    int arr[] = {1 , 2 , 4 , 5};
    printArray(arr);
}

// emplace_back in vectors automatically add value even if its a a object sya Job class object having three field it builds the object adn adds to the vector 

// instead of we doing vector.push_back(Job(val1 , vale 2 val3));


// sort(vec.begin() , vec.end() , [](Job &a , Job &b){ return a.salary < b.salary;});  // this is how we can sort the vector of objects based on the salary field of the object using lambda function in c++11 and above  