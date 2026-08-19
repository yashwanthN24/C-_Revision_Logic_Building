/*


sort() in C++ STL


3

Sorting is one of the most standard operations used very frequently while writing programs. Writing the complete sorting algorithm might be time consuming and hence STL provides us with a standard inbuilt function to sort any container very easily.

Benefits of using sort():

Ease of implementation – omits writing lengthy code to implement different sorting algorithms.
No need to worry about time complexity – it is one of the most efficient functions with a N*logN time complexity and uses a mix of quicksort and mergesort in its internal implementation.
Syntax:
The sort() function in STL accepts two mandatory parameters: begin and end, and sorts the range within the container in ascending order by default.

sort(begin, end)
begin: An iterator pointing to the first element of a container.
end: An iterator pointing to the element just after the last element of the container.


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {4,2,1};
    sort(arr, arr+3);  //Sort from arr to arr+3 
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    return 0;
}




#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> vec = {4,2,1};
    sort(vec.begin(), vec.end());  //Sort the vector
    cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2];
    return 0;
}


Can we also sort a container in descending order using sort()?

Yes, by using comparators. The role of a comparator is to compare two elements before performing an operation.

In STL, we already have a comparator defined to do this which is called greater(). We just need to pass greater<container_data_type>() as the third parameter to sort function as shown in the below codes and it will sort the container in descending order.


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {4,2,1};
    sort(arr, arr+3, greater<int>());  //Sort from arr to arr+3 elements only
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    return 0;
}




#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> vec = {4,2,1};
    sort(vec.begin(), vec.end(), greater<int>());  //Sort the elements 
    cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2];
    return 0;
}


Can we also sort the container in a custom order – defined by a custom comparator?

Yes, we can. We can write a custom comparator to compare between any two elements as we wish, and it can then be used to sort the entire container accordingly.

But wait, isn't sorting just of two types – ascending and descending? Why do we need a custom sorting algorithm?

Before we answer that, can you think of using the sort() function with a vector of pairs where the vector needs to be sorted according to the second element of all pairs? Or say an array of structures?

This is where we need comparators – to sort custom data types defined by users based on custom parameters.

Let's understand this by the example of a vector of pairs where the vector needs to be sorted in ascending order of the second element of all pairs.

Below is a valid comparator for this:

The above function accepts two pairs "a" and "b", and returns true if the second element of the first pair is smaller than the second element of the second pair; otherwise, it returns false.


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

int main() {
    vector<pair<int, int> > vec = {{10,3}, {20, 1}, {30, 2}};
    sort(vec.begin(), vec.end(), sortbysec);
    for(int i=0; i<3; i++) { //
        cout<<vec[i].first<<" "<<vec[i].second<<"\n";  //print the vec[i].first and then the vec[i].second
    }
    return 0;
}



*/