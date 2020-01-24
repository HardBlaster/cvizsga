#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "polygon.h"

using namespace std;

long factorial(long a) {
    if (a > 1) {
        return (a * factorial(a - 1));
    } else {
        return 1;
    }
}

int addition(const int a, const int b) {
    return a + b;
}

int addition(const int a, const int b, const int c) {
    return a + b + c;
}

string addition(const string &a, const string &b) {
    return a + b;
}

void multiply(const int a, const int b, int &c) {
    c = a * b;
}

void multiply(const int a, const int b, int *c) {
    *c = a * b;
}

void show(int a[], int size) {
    for (int i = 0; i < size; ++i)
        cout << a[i] << " ";
}

int main() {

//----------------------------------------------------------------------------------------------------------------------
//Változók, mutatók, referenciák (jobb- és balérték referencia).

    int a = 5;
    int b(3);
    int c{2};
    int result;

    a = a + b;
    result = a - c;
    cout << "result: " << result << endl;

    decltype(result) result2;

    cout << "type of result: " << typeid(result).name() << "\ntype of result2: " << typeid(result2).name() << endl;

    unsigned int positive = -15;
    float doubleValue = 15.4f;

    auto autoDetect = positive + doubleValue;

    cout << "positive: " << positive << "\nautoDetect: " << autoDetect << " (" << typeid(autoDetect).name() << ")\n";

    int &aRef = a;
    int *p = &a;
    cout << "aRef: " << aRef << "\na: " << a << "\np: " << p << "\n*p: " << *p << endl;
    a++;
    cout << "aRef: " << aRef << "\na: " << a << "\np: " << p << "\n*p: " << *p << endl;
    aRef++;
    cout << "aRef: " << aRef << "\na: " << a << "\np: " << p << "\n*p: " << *p << endl;

    string text;
    text = "Szia Kornél!";
    cout << text << endl;
    text = "Kövi tétel...";
    cout << text << endl;

//----------------------------------------------------------------------------------------------------------------------
//Függvények, paraméter átadás, függvénynév túlterhelés, operátorok.

    int add1 = 10, add2 = 15, add3 = 0;
    string str1 = "Text 1 ";
    string str2 = "Text 2 ";

    cout << "addition(add1, add2): " << addition(add1, add2) << "\naddition(add1, add2, add2): "
         << addition(add1, add2, add2) << "\naddition(str1, str2): " << addition(str1, str2) << endl;

    cout << "add3: " << add3 << endl;
    multiply(add1, add2, add3);
    cout << "add3: " << add3 << endl;

    int *add = &add3;
    *add = 0;

    cout << "add3: " << add3 << endl;
    multiply(add1, add2, add);
    cout << "add3: " << add3 << endl;

    a = 2;
    b = 7;
    c = (a > b) ? a : b;
    cout << "c: " << c << endl;

//----------------------------------------------------------------------------------------------------------------------
//A C++ objektumorientált eszköztára (absztrakció, bezárás, öröklés, polimorfizmus).

    CRectangle rectangle;
    CTriangle triangle;

    CPolygon *ptr_polygon1 = &rectangle;
    CPolygon *ptr_polygon2 = &triangle;

    ptr_polygon1->setup(2, 2);
    ptr_polygon2->setup(2, 2);

    ptr_polygon1->onscreen();
    ptr_polygon2->onscreen();

    CPolygon *ptr_polygon3 = new CRectangle;
    CPolygon *ptr_polygon4 = new CTriangle;

    ptr_polygon3->setup(3, 3);
    ptr_polygon4->setup(3, 3);

    ptr_polygon3->onscreen();
    ptr_polygon4->onscreen();

    delete ptr_polygon3;
    delete ptr_polygon4;

    CRectangle rectangle2(5, 5);
    CTriangle triangle2(5, 5);

    rectangle2.onscreen();
    triangle2.onscreen();

//----------------------------------------------------------------------------------------------------------------------
//Upcasting/Downcasting

    CPolygon *poly;
    CRectangle rec(2, 3);

    poly = &rec;

    CRectangle *rec2 = (CRectangle *) poly;
    (*rec2).onscreen();
    rec2->onscreen();

    poly = rec2;
    poly->onscreen();

//----------------------------------------------------------------------------------------------------------------------
//STL

    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The array before sorting is : ";
    show(arr, size);

    sort(arr, arr + 10);

    cout << "\nThe array after sorting is : ";
    show(arr, size);

    if (binary_search(arr, arr + 10, 2)) {
        cout << "\nElement '2' found in the array" << endl;
    } else {
        cout << "\nElement not found in the array" << endl;
    }

    vector<int> vect(arr, arr + size);
    reverse(vect.begin(), vect.end());

    cout << "Maximum element of vector is: " << *max_element(vect.begin(), vect.end()) << endl;

    cout << "Minimum element of vector is: " << *min_element(vect.begin(), vect.end()) << endl;

    cout << "The summation of vector elements is: " << accumulate(vect.begin(), vect.end(), 0) << endl;

    all_of(arr, arr + size, [](int x) { return x > 0; }) ? cout << "All are positive elements" : cout
            << "All are not positive elements";

    any_of(arr, arr + size, [](int x) { return x < 0; }) ? cout << "There exists a negative element" : cout
            << "All are positive elements";

    none_of(arr, arr + size, [](int x) { return x < 0; }) ? cout << "No negative elements" : cout
            << "There are negative elements";

    vector<int>::iterator ptr;

    cout << "The vector elements are : ";
    for (ptr = vect.begin(); ptr < vect.end(); ptr++)
        cout << *ptr << " ";
    cout << endl;

    return 0;
}