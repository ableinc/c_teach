#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
float divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }
    return (float)a / b;
}
int multiply(int a, int b) {
    return a * b;
}
int modulus(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Modulus by zero\n");
        exit(EXIT_FAILURE);
    }
    return a % b;
}
int power(int base, int exp) {
    if (exp < 0) {
        fprintf(stderr, "Error: Negative exponent not supported\n");
        exit(EXIT_FAILURE);
    }
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        fprintf(stderr, "Error: LCM of zero not defined\n");
        exit(EXIT_FAILURE);
    }
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    return (a / gcd(a, b)) * b;
}

int main() {
    int a = 12, b = 5;
    printf("Add: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtract: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiply: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Divide: %d / %d = %.2f\n", a, b, divide(a, b));
    printf("Modulus: %d %% %d = %d\n", a, b, modulus(a, b));
    printf("Power: %d ^ %d = %d\n", a, b, power(a, b));
    printf("GCD: gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("LCM: lcm(%d, %d) = %d\n", a, b, lcm(a, b));
    return 0;
}