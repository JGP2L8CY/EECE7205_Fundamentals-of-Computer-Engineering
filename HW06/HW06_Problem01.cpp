#include <iostream>
#include <time.h>
using namespace std;

// Problem01 // 
int Arr[100]; // Global Variance
int FibonacciR(int n){
    /*Recursive Fibonacci Sequence*/
    if (n <= 1){
        return n;
    }else{
        return FibonacciR(n - 1) + FibonacciR(n - 2); // Recursive method
    }
}

int fibd(int n){
    /*FibonacciD helper function*/
    if (n < 2) return n;
    if (Arr[n] != -1) return Arr[n];
    Arr[n] = fibd(n - 1) + fibd(n - 2);
    return Arr[n];
}
int FibonacciD(int n){
    /*Fibonacci Sequence using Dynamic Programming method*/
    Arr[0] = 0;
    Arr[1] = 1;
    return fibd(n);
}

int main(){
    /*Test the code culculating time duration*/
    int n;
    clock_t start, finish; 
    double duration;
    cout << "Input n: ";
    cin >> n;

    for (int i = 0; i <= n; i++) Arr[i] = -1;
    start = clock(); 
    cout << "Fibonacci Recursive: " << FibonacciR(n) << endl;
    finish = clock(); 
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%fsec", duration);
    cout << endl;

    start = clock(); 
    cout << "FibonacciD number: " << FibonacciD(n) << endl;
    finish = clock(); 
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%fsec", duration);
    cout << endl;
}