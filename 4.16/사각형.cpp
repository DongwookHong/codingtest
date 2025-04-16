#include <iostream>
using namespace std;

long long gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long solution(int W, int H) {
    long long w = W;
    long long h = H;
    long long g = gcd(W, H);
    return w * h - (w + h - g);
}