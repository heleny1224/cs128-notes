/*
 * C++ Notes: Understanding & and *
 * Topics: Address, Pointer, Reference, Dereference, Const
 *
 * ============================================================
 * 1. THE BIG PICTURE
 * ============================================================
 *
 * & has two common meanings:
 *
 *   int* p = &x;  -> &x gets the address of x
 *   int& r = x;   -> r is a reference (alias) to x
 *
 * * has two common meanings:
 *
 *   int* p;       -> p is a pointer to int
 *   *p = 10;      -> access the object pointed to by p
 *
 * IMPORTANT:
 * Declaration: tells us what kind of variable we are creating.
 * Expression: performs an operation on an existing value.
 *
 * Spaces do not change the meaning:
 *   int* p;
 *   int *p;
 *   int * p;
 * All three declare p as a pointer to int.
 *
 * ============================================================
 * 2. ADDRESS-OF: &
 * ============================================================
 */

#include <iostream>
#include <string>
#include <vector>

void AddressExample() {
    int x = 10;

    std::cout << x << '\n';   // 10: the value
    std::cout << &x << '\n';  // address of x

    int* p = &x;
    std::cout << p << '\n';   // same address as &x
}

/*
 * Remember:
 *
 *   x   -> value of x
 *   &x  -> address of x
 *   p   -> address stored in p
 *   *p  -> value/object at that address
 *
 * ============================================================
 * 3. POINTER: *
 * ============================================================
 */

void PointerExample() {
    int score = 95;

    int* p = &score;
    // int* means p is a pointer to int.
    // p stores the address of score.

    std::cout << score << '\n';  // 95
    std::cout << p << '\n';      // address of score
    std::cout << *p << '\n';     // 95

    // A pointer can be changed to point to another object.
    int anotherScore = 80;
    p = &anotherScore;

    std::cout << *p << '\n';     // 80

    // Safe initialization when the pointer points to nothing:
    int* empty = nullptr;

    // Never dereference nullptr:
    // std::cout << *empty;  // Undefined behavior
    (void)empty;
}

/*
 * ============================================================
 * 4. DEREFERENCE: *p
 * ============================================================
 */

void DereferenceExample() {
    int x = 10;
    int* p = &x;

    *p = 20;
    // Go to the object p points to and change its value.
    // Since p points to x, x becomes 20.

    std::cout << x << '\n';  // 20

    int y = *p;
    // Read the value pointed to by p and copy it into y.

    std::cout << y << '\n';  // 20
}

/*
 * ============================================================
 * 5. REFERENCE: &
 * ============================================================
 */

void ReferenceExample() {
    int original = 7;

    int& alias = original;
    // alias is another name for original.

    alias = 12;

    std::cout << original << '\n';  // 12
    std::cout << alias << '\n';     // 12

    int other = 99;

    alias = other;
    // IMPORTANT:
    // This copies other's value into original.
    // It does NOT make alias refer to other.

    std::cout << original << '\n';  // 99
    std::cout << other << '\n';     // 99
}

/*
 * Reference rules:
 *
 * 1. A normal reference must be initialized.
 *
 *      int& r;       // ERROR
 *      int x = 5;
 *      int& r = x;   // OK
 *
 * 2. A reference cannot be reseated after initialization.
 *
 * 3. A reference acts like an alias for an existing object.
 *
 * 4. A reference is not the same thing as a pointer.
 *
 * ============================================================
 * 6. POINTER VS REFERENCE
 * ============================================================
 */

void ComparePointerAndReference() {
    int x = 10;
    int y = 20;

    // Pointer
    int* p = &x;
    *p = 11;
    p = &y;  // The pointer now points to y.

    // Reference
    int& r = x;
    r = 12;  // Changes x.

    // r = y would copy y's value into x.
    // It would NOT make r refer to y.

    std::cout << x << '\n';  // 12
    std::cout << y << '\n';  // 20
    std::cout << *p << '\n'; // 20
}

/*
 * Quick comparison:
 *
 * int* p = &x;
 *   - p stores an address.
 *   - Can point to another object.
 *   - Can be nullptr.
 *   - Use *p to access the pointed-to object.
 *
 * int& r = x;
 *   - r is an alias for x.
 *   - Cannot be reseated.
 *   - A normal reference must refer to an object.
 *   - Use r directly; no * is needed.
 *
 * ============================================================
 * 7. FUNCTION PARAMETERS
 * ============================================================
 */

void ChangeByPointer(int* p) {
    if (p != nullptr) {
        *p = 100;
    }
}

void ChangeByReference(int& value) {
    value = 200;
}

void FunctionParameterExample() {
    int a = 1;
    int b = 2;

    ChangeByPointer(&a);
    // Pass the address of a.

    ChangeByReference(b);
    // Pass b as a reference.

    std::cout << a << '\n';  // 100
    std::cout << b << '\n';  // 200
}

/*
 * How to choose:
 *
 * void f(int* p)
 *   Call: f(&x);
 *   The function receives a pointer.
 *   It should consider whether p could be nullptr.
 *
 * void f(int& x)
 *   Call: f(x);
 *   The function receives a reference to the original object.
 *   No nullptr check is needed for an ordinary valid reference.
 *
 * void f(const std::string& s)
 *   Call: f(myString);
 *   Read-only reference; avoids copying the string.
 *
 * ============================================================
 * 8. CONST + POINTER
 * ============================================================
 */

void ConstPointerExample() {
    int x = 1;
    int y = 2;

    // A. Pointer to const int
    const int* p1 = &x;

    // *p1 = 5;  // ERROR: cannot modify x through p1
    p1 = &y;     // OK: p1 can point elsewhere

    std::cout << *p1 << '\n';  // 2

    // B. Const pointer to int
    int* const p2 = &x;

    *p2 = 5;     // OK: modify x
    // p2 = &y;  // ERROR: cannot change p2's address

    std::cout << x << '\n';  // 5

    // C. Const pointer to const int
    const int* const p3 = &x;

    // *p3 = 8;  // ERROR: cannot modify x through p3
    // p3 = &y;  // ERROR: cannot change p3's address

    std::cout << *p3 << '\n';
}

/*
 * Quick way to remember:
 *
 * const int* p
 *   The int is const through this pointer.
 *   p can point elsewhere.
 *
 * int* const p
 *   The pointer p is const.
 *   The pointed-to int can be modified.
 *
 * const int* const p
 *   Neither the pointer's target nor its address can be changed
 *   through p.
 *
 * ============================================================
 * 9. CLASS EXAMPLE: int* AS A DATA MEMBER
 * ============================================================
 */

class BikeRack {
public:
    explicit BikeRack(unsigned int size)
        : size_(size), bikes_(new int[size]{}) {
        // new int[size]{} creates an array initialized to zero.
    }

    ~BikeRack() {
        delete[] bikes_;
        // Match new[] with delete[].
    }

    bool Park(unsigned int slot, int bike) {
        if (slot >= size_) {
            return false;
        }

        if (bikes_[slot] != 0) {
            return false;
        }

        bikes_[slot] = bike;
        // bikes_[slot] accesses an array element.
        // The pointer bikes_ identifies the beginning of the array.

        return true;
    }

    int At(unsigned int slot) const {
        return bikes_[slot];
    }

private:
    unsigned int size_;
    int* bikes_;
};

/*
 * NOTE:
 * A class that owns a raw pointer must handle copying carefully.
 * Default copying can make two objects own the same allocation.
 * For ordinary C++ projects, std::vector<int> is often safer.
 *
 * ============================================================
 * 10. COMMON MISTAKES
 * ============================================================
 */

void CommonMistakes() {
    int x = 5;

    // Mistake 1: uninitialized pointer
    // int* p;
    // std::cout << *p;  // Undefined behavior

    // Better:
    int* p = nullptr;

    // Mistake 2: dereferencing nullptr
    // std::cout << *p;  // Undefined behavior

    // Mistake 3: confusing address and value
    p = &x;

    std::cout << p << '\n';   // Address of x
    std::cout << *p << '\n';  // Value of x: 5

    // Mistake 4: confusing a reference with a pointer
    int& r = x;
    r = 8;  // No * required.

    std::cout << x << '\n';   // 8

    // Mistake 5: incorrect deletion of an array
    // int* arr = new int[5];
    // delete arr;    // WRONG for an array
    // delete[] arr;  // Correct
}

/*
 * ============================================================
 * 11. HOW TO JUDGE WHEN YOU SEE & OR *
 * ============================================================
 *
 * Case 1:
 *   int* p = &x;
 *
 *   int* -> declare a pointer
 *   &x   -> get x's address
 *   p    -> store that address
 *
 * Case 2:
 *   *p = 10;
 *
 *   p  -> the pointer
 *   *p -> the object pointed to by p
 *   =  -> assign 10 to that object
 *
 * Case 3:
 *   int& r = x;
 *
 *   int& -> declare a reference
 *   r    -> another name for x
 *
 * Case 4:
 *   Change(&x);
 *
 *   &x -> pass x's address
 *   Check the function declaration to see whether its parameter is a pointer.
 *
 * Case 5:
 *   const std::string& name
 *
 *   Reference to a string that the function should not modify.
 *   Commonly used to avoid copying strings.
 *
 * ============================================================
 * 12. MINI PRACTICE
 * ============================================================
 */

void MiniPractice() {
    int n = 3;

    int* ptr = &n;
    int& ref = n;

    *ptr = 4;
    ref = 6;

    std::cout << n << '\n';    // 6
    std::cout << *ptr << '\n'; // 6
    std::cout << ref << '\n';  // 6
}

int main() {
    AddressExample();
    PointerExample();
    DereferenceExample();
    ReferenceExample();
    ComparePointerAndReference();
    FunctionParameterExample();
    ConstPointerExample();

    BikeRack rack(3);
    rack.Park(0, 42);
    std::cout << rack.At(0) << '\n';

    CommonMistakes();
    MiniPractice();
}
