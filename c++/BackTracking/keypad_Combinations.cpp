/*

Keypad Combinations
Given a string containing digits from 2-9 inclusive, print all possible letter combinations that
the number could represent. You can print the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1
does not map to any letters.

Sample Input 1 : digits = "23"
Sample Output 1 : "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"

Sample Input 2 : digits = "2"
Sample Output 2 : "a", "b", "c"

Sample Input 3 : digits = ""
Sample Output 3 : ””


*/

#include <iostream>
#include <string>
using namespace std;

string keypad[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void keypadCombinations(string str, string ans, int i) {

    // Base case
    if (i == str.size()) {
        cout << ans << " ";
        return;
    }

    int digit = str[i] - '0';

    // Try every letter corresponding to this digit
    for (char ch : keypad[digit]) {
        keypadCombinations(str, ans + ch, i + 1);
    }
}

void keypadCombinations2(string str, string ans) {

    if(str.length() == 0) {
        cout << ans << " ";
        return;
    }

    int digit = str[0] - '0';

    for(char ch : keypad[digit]) {
        keypadCombinations2(str.substr(1), ans + ch);
    }
}

int main() {

    string str = "23";

    keypadCombinations2(str, "");
}