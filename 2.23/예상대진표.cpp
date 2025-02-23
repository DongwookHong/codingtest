#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int cnt = 0; 
    while (n > 1)  
    {
        if ((a + 1) / 2 == (b + 1) / 2)
            break;

        cnt++;
        a = (a + 1) / 2;  
        b = (b + 1) / 2;
        n /= 2; 
    }

    return cnt + 1;  
}

