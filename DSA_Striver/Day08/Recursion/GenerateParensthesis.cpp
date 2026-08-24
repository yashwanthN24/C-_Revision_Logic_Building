
/*


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8



*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void generate(int i, int n, int open, int close, string s, vector<string>& ans) {
        if (i == 2 * n) {
            ans.push_back(s);
            return;
        }

        // add open parenthesis and reduce the count of open parenthesis 
        if (open < n) {
            generate(i + 1, n, open + 1, close, s + '(', ans);
        }

        // add close parenthesis and reduce the count of close parenthesis 
        if (close < open) {
            generate(i + 1, n, open, close + 1, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0 , n , 0 , 0 ,  "" , ans);
        return ans;

    }
};


// for n = 3 we have 6 parenthesis of which 3 are open and 3 are close 

// so for n we have 2n totoal patensthes of which n are open and n are closed parenthesis 