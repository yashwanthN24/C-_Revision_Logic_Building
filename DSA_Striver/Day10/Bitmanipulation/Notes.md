1. Swapping Two Numbers Without a Third Variable
A = A ^ B
B = A ^ B
A = A ^ B
2. Checking if the i-th Bit is Set
(1 << i) & num   → set if result ≠ 0
(num >> i) & 1   → set if result ≠ 0
3. Setting the i-th Bit
num | (1 << i)
4. Clearing the i-th Bit
num & ~(1 << i)
5. Toggling the i-th Bit
num ^ (1 << i)