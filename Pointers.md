# POINTERS

## BASIC POINTERS

```c++
#include <iostream>
using namespace std;

int main(){
 cout << endl;
 int i{2011};
 int * iprt = &i;
 
 cout << i << endl;
 
 cout << "iptr: "<< iptr << endl;
 cout << "*iptr: "<< iptr << endl;

 int * jptr = iptr;
 *jptr = 2014;

 cout << "iptr: "<< iptr << endl;
 cout << "*iptr: "<< *iptr << endl;
 
 cout << "jptr: "<< jptr << endl;
 cout << "*jptr: "<< *jptr << endl;
}

```

#### Explanation 
* This example shows an instance of two pointers pointing to the same object.
* iptr and jptr point to i



## POINTER ARITMETIC

```c++
#include <iostream>
using namespace std;

int main(){
 int intArray[]={1,2,3,4,5};
 if (intArray[3]==*(intArray+3)
  cout << "Pointer aritmetic works!" << endl;
}
```
#### Explanation
* arrays use pointer arithmetic.
* in line 6, both syntaxes return the same value. 



## nullptr

```c++
#include <iostream>
using namespace std;

int main(){
 int *pi = nullptr;
 cout << pi >> endl;
 
 // int i = nullprt; // ERROR

 bool b{nullptr};
 cout << b << endl;

}
```

#### Explanation 
* The nullptr can be assigned to any arbitrary pointer, as seen in line 5.
* The nullptr cannot be assigned to any arbitrary variable except a bool. 
* This will only work when creating a bool through uniform initialization. 



