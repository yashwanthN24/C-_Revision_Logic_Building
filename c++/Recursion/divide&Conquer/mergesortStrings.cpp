#include <iostream>

using namespace std; 

void print(string str[] , int n  ){
    for(int i = 0 ; i< n ; i++){
        cout << str[i] << " ";
    }
    cout << endl;
}

void merge(string str[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;

    int size = high - low + 1;
    string *temp = new string[size];

    while (i <= mid && j <= high) {
        if (str[i] < str[j]) {
            temp[k++] = str[i++];
        } else {
            temp[k++] = str[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = str[i++];
    }

    while (j <= high) {
        temp[k++] = str[j++];
    }

    for (i = low, k = 0; k < size; i++, k++) {
        str[i] = temp[k];
    }

    delete[] temp;
}



void mergesort(string str[] , int low , int high){
    if(low >= high){
        return ;
    }

    int mid = low + (high - low)/2;

    mergesort(str , low , mid);
    mergesort(str , mid+1 , high);

    merge(str , low , mid , high);

}

int main(){
    string str[] = {"sun" , "earth" , "moon" , "mars" , "venus" , "jupiter" , "saturn" , "uranus" , "neptune" , "pluto"};

    print(str , 10);
    int n = sizeof(str) / sizeof(str[0]);
    mergesort(str , 0 , n - 1);
    print (str, n);

}