#include <iostream>
using namespace std;

int solution(int n)
{
    int cnt = 1;
    
    while(n/2>0)
    {
        if(n%2 ==1)
        {
            n=n-1;
            ++cnt;
        }
        else
            n= n/2;
    }

    return cnt;
}
//dp문제인줄알고 접근했다가 생각보다 간단하게 풀이를했다 
