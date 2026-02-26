#include <iostream>
#include <string>
using namespace std;

template <typename T>
void printArray(T a[], int s) {
    for (int i = 0; i < s; i++) {
        cout << a[i];
        cout << " ";
    }
  
}

template <typename T>
void selectionSort(T ar[], int s) {
    for (int i = 0; i < s; i++) {
        int minindex = i;
        for (int j= i+ 1; j < s; j++) {
            if (ar[j] < ar[minindex]) {
                minindex = j;
            }
        }
        T temp = ar[i];
        ar[i] = ar[minindex];
        ar[minindex] = temp;
       // swap(ar[i], ar[minindex]);
    }
}

int main() {
    int intArray[5] = { 64, 25, 12, 22, 11 };
    int intSize = 5;

    cout << "Original integer array: ";
    printArray(intArray, intSize);
    cout << endl;
    selectionSort(intArray, intSize);

    cout << "Sorted integer array: ";
    printArray(intArray, intSize);

    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    int stringSize = 4;


    cout << "\nOriginal string array: ";
    printArray(stringArray, stringSize);

    selectionSort(stringArray, stringSize);

    cout << "Sorted string array: ";
    printArray(stringArray, stringSize);

    return 0;
}