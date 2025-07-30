#include "Fibonacci.h"
#include <iostream>

using namespace std;

int Fibonacci::fib(int n) {
    if (n <= 0) {
    	return 0;
    }
    if (n == 1) {
    	return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 
Fibonacci::Fibonacci(int n){
	for (int i = 1; i <= n; i++) {
		cout << fib(i) << " ";
	}
	cout << endl;
}