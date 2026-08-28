## Getting started 

**Install Compiler**

https://github.com/brechtsanders/winlibs_mingw/releases/

where.exe <application> Gets all paths of that application set in environmental variables 

https://chatgpt.com/c/6a705153-a7d4-83ee-90ec-15bb51d2c4df

https://chatgpt.com/c/6a705d49-d7c0-83e8-9b5b-1cad966acd50

https://chatgpt.com/c/6a706d54-d0d0-83ee-8c19-b7e538261649


https://chatgpt.com/c/6a70ce2a-2fe0-83e8-9d09-38bcd32e7bd3

https://chatgpt.com/c/6a70d18c-c544-83e8-a9c7-5ae067f08c87

## Passing, Returning, and Assigning Strings
Strings in C++ can be assigned and passed like primitive types. Assigning one string to another makes a deep copy of the character sequence:

In C++, strings can be seamlessly passed between functions. When you pass a string as an argument to a function, you're essentially making a copy of the string. Any changes made to the string within the function won't affect the original string outside of it.

Copying strings is not merely a superficial process, it involves creating a new string with an identical character sequence. Whether you're assigning a string to another or passing it to a function, you're essentially creating a fresh copy.

```
#include <bits/stdc++.h>
```

This contains all the standard libraries in C++. However, it's not recommended for production code due to potential issues with compilation time and namespace pollution. Instead, include only the specific headers you need.


String Comparison
The == known as the equality operator is used for comparing two values to check if they are equal. In programming, it's commonly used to compare variables, such as numbers or strings, to determine if they have the same value. For example, x == y will return true if x is equal to y, and false otherwise.
The != known as the inequality operator is used to check if two values are not equal. It's the opposite of the equality operator. If the values being compared are not equal, != returns true; if they are equal, it returns false. We can check if two strings are equal or not and at the same time we can also check whether particular characters of two strings are equal or not.

```c++
 bool compareStrings(string str1, string str2) {
        // Return true if strings are equal
        return str1 == str2;
    }
```

switch is for int and char and long basically all integral and foating point datatypes  in c++ 


```c++

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int factorial = 1;

    while (n > 0) {
        factorial *= n;  //Keep finding factorial with n and decrement n 
        n--;
    }

    cout << "Factorial of 5 is: " << factorial << endl;  //Print the factorial

    return 0;
}

```

While loops are particularly useful when you need to ensure that a block of code executes only when the condition is satisfied as it terminates as soon as that condition becomes false. This can be vital for tasks like validating user input or processing data until a specific condition is met. By checking the condition at the beginning of the loop, you can control whether the loop body is executed or not.

Java
Java is always pass-by-value, even for objects. But for objects, the value is a reference (confusing right?). So changes to object contents reflect.

![alt text](image.png)


![alt text](image-1.png)


Whenever accessing vector element via v[i] or v.back() or v.front() or v.at(i) make sure your vector is not empty i.e v.empty() returning true 

Rule to remember: Whenever you use .back(), .front(), or access v[0], make sure the vector isn't empty first. A common pattern is:

if (v.empty() || v.back() != x) {
    v.push_back(x);
}

This works because of short-circuit evaluation of ||. (only first conjdition true means done no mor e checking of condifiton


&& first condition false means doesnt check second cndition)


# string hashing


![alt text](image-2.png)

![alt text](image-3.png)

![alt text](image-4.png)





Ch-`0` concerts numbers in string to number as ascii of zero is 48co
nvert string numbers to number

ch + '0' converts number to string as ascii of zero is 48 convert number to string

ch + ' ' (converts uppercase to lowercase as ascii value is 32 take 

ch = 'A' 65 + 32 = 97 = 'a'  )

ch - ' ' (converts lowercase to uppercase as ascii value is 32 take a = 97 - 32 = 65 = 'A'  )   



https://chatgpt.com/share/6a8b5c4e-3f0c-83e9-9f56-d23c072dfb23?ogimg=plain

https://chatgpt.com/share/6a86b085-36ec-83ee-a829-037ccb512fbc?ogimg=plain

https://chatgpt.com/share/6a83e21f-d7e4-83e8-b02f-500cd3cc7d69?ogimg=plain

https://chatgpt.com/share/6a83e0a8-4150-83ee-9172-b705c00b7410?ogimg=plain

https://chatgpt.com/share/6a8382f5-04d0-83ee-8739-d5cac5dc0fb4?ogimg=plain

https://chatgpt.com/share/6a838104-7458-83e8-afb3-33f59f157af2?ogimg=plain

https://chatgpt.com/share/6a837dc9-9a90-83e8-9dfc-2f735bb68f23?ogimg=plain

https://chatgpt.com/share/6a83792b-bda8-83e8-b681-61c1a147619b?ogimg=plain

https://chatgpt.com/share/6a83676d-e2f0-83ee-bd62-dd8ac891411d?ogimg=plain

https://chatgpt.com/share/6a7b2fb6-1438-83e8-9981-8095dd7871ff?ogimg=plain

![alt text](image-5.png)







