#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

long long fibonacciRekursif(int n){
    if (n<=1)
        return n;
    return fibonacciRekursif(n-1)+fibonacciRekursif(n-2);
}

