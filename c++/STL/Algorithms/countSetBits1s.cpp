// // int count_setbits(int N) { 
// //     int cnt = 0;

// //     while (N > 0) {
// //         cnt += (N & 1);  // check last bit
// //         N = N >> 1;      // right shift
// //     }

// //     return cnt;
// // }


// int main() {
//     int n = 7;
//     cout << __builtin_popcount(n);
//     return 0;
// }

// int main() {
//     long long n = 77777777777777;
//     cout << __builtin_popcountll(n);
//     return 0;
// }

/*

Conclusion
__builtin_popcount() → works for int type.
__builtin_popcountll() → works for long long type.
Both functions help count set bits efficiently in a single line of code.
These functions are widely used in competitive programming because of their simplicity and performance.


*/