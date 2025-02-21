#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long answer = 0;
    int dp[n];
    int a= 1234567;
    dp[0] =0;
    dp[1]=1;
    dp[2]=2;
    
    
    for(int i =3; i<=n;i++)
        dp[i]= (dp[i-2] + dp[i-1])%a;
    
    return dp[n];
}
//dp 인가 ??,or  완전탐색 ??

//1 일때 1, 
//2 일때 (1,1) ,(2)
//3 일때는 (1,1,1) , (1,2),(2,1)
//4 일때는 (1,1,1,1),(1,2,1),(2,1,1),(1,1,2) ,(2,2)