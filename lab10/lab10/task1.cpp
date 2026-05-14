#include <iostream>
using namespace std;

int Factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * Factorial(n - 1);

}

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumArray(int arr[], int size) {

    if (size == 0) {
        return 0;
    }
    return arr[size - 1] + sumArray(arr, size - 1);
}

int main() {
    int arr[] = { 20,40,65,54,34 };

    int length = sizeof(arr) / sizeof(arr[0]);

    int sum = sumArray(arr, length);

    cout << "Sum of Array is " << sum << endl;

    cout << "Factorial is " << Factorial(5);
    cout << endl;
    cout << "Fabonaci Series " << fibonacci(6);

    return 0;
}

