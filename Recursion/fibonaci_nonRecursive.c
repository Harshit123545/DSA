#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, nextTerm;
    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", a);
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    printf("\n");
}

int main() {
    int n = 10; 
    fibonacci(n);
    return 0;
}