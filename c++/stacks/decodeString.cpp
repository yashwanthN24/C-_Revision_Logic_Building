// #include <iostream>
// #include <stack>
// using namespace std;

// string decodeString(string str){

//     stack<char> st;
//     string finalstr = "";
    
//     for(int i = 0;i<str.length() ; i++){
//         char ch = str.at(i);
         
//         if(ch != ']'){
//             //  ie push all alpahbets and open parenthesis and even counts
//             st.push(ch);
//         }else{
//             // closing bracket case 
//             // pop until you get open brackt and collect the string 
//            string curStr = "";
//            string expandedStr = "";
//             while(st.top() != '['){
//                 curStr = st.top() + curStr;;
//                 st.pop();
//             }
//             cout << "curStr: " << curStr << endl;


//             // pop the open bracket
//             st.pop();

//             // pop the count 
//             int count = st.top() - '0'; // convert char to int
//             cout << "count: " << count << endl;
            
//             st.pop();

            
//             for(int i = 1; i<= count ; i++){
//                 expandedStr += curStr;
//             }

//             cout << "expandedStr: " << expandedStr << endl;
 


//             finalstr =   finalstr + expandedStr;

//             cout << "finalstr: " << finalstr << endl;
//         }


//     }

//     return finalstr;
    

// }

// // int main(){
// //     // string str = "3[a]2[bc]";
// //     string str = "3[a2[c]]";

// //     cout << decodeString(str);
// // }




#include <iostream>
#include <stack>
using namespace std;

string decodeString(string str) {

    stack<char> st;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch != ']') {
            st.push(ch);
        } else {

            string curStr = "";
            while (st.top() != '[') {
                curStr = st.top() + curStr;
                st.pop();
            }

            st.pop(); // remove '['

            int count = st.top() - '0'; // assume single digit
            st.pop();

            string expandedStr = "";
            while (count--) {
                expandedStr += curStr;
            }

            for (char c : expandedStr) {
                st.push(c);
            }
        }
    }

    string ans = "";
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

int main() {
    string str = "3[a2[c]]";
    cout << decodeString(str);
}