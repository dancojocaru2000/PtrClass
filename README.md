## Ptr Class
C++ inherits pointers from C, and therefore uses the following awkward syntax:

```cpp
void c_syntax() {
    int* p;    // pointer to int, everything fine 
    int x = 5; // declare an int variable
    p = &x;    // get the address of x
    *p = 9;    // wait, * again?!?
}
```

This is not helped by the addition to C++ of references:

```cpp

namespace cpp_references {
    void accept_reference(int &x) {
        x = 6;        // modify x
        int* p = &x;  // uhh... & again?
        *p = 1;       // and * again?
    }
}
```

Therefore, I created the following class: `ptr<T>`.

Notice how the code above is improved:
```cpp
#include <ptr.hpp>
using dcdevelop::ptr;

void using_ptr() {
    ptr<int> p;      // null pointer to int
    int x = 5;       // declare an int variable
    p = ptr<int>(x); // p becomes pointer to x
    p.deref() = 9;   // ah, much better
}
```

Due to implicit conversions, `T*` and `ptr<T>` can be used interchangably! Hooray!

If you want to be extra sure, you can either use the `adrr()` method or simply use a cast.

```cpp

namespace pointer_interop_test {
    int accepts_pointer(int* p) {
        return *p;
    }

    void test() {
        int x = 6;
        auto p = ptr<int>(x);
        accepts_pointer(p);     // Works!

        scanf("%d", (int*)p);	// Just cast!
        scanf("%d", p.addr());  // Or call addr
    }
}

```

---
## C Strings
_also known as `char*`_

C has a really hacky way of dealing with strings: they're actually an array (pointer) of chars, ending with a char with the value `0` (/ `NULL` / `nullptr`).

`string.h` (or `cstring` in C++) has some functions to deal with common stuff you might do, but they feel _unnatural_.

Of course, C++ has `std::string`, but what if you want to keep using `char*` strings?

**Introducing `ptr<char>`.**

Using the magic of templates, C strings can now be worked on in a more natural, OOP kind of way:

```cpp
void cstrings() {
    ptr<char> s = "hey!";
    
    s.length(); // 4, calls strlen

    ptr<char> s2 = new char[50];
    s.copy_to(s2);      // both calls are 
    s2.replace_with(s); // equivalent, using strcpy 
}
```

A lot of similar functions can be found in the header file, and they should be self descriptive.

In order to use the C String functions, please define the following macro **before including the header** (or when compiling):

```cpp
#define DCDEVELOP_PTR_CLASS_CSTRING
```

---
## Enjoy!