#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int dp[n+1];
    
    dp [0] =0;
    dp [1]=1;
    dp[2]=2;
    for(int i= 3; i<=n; ++i)
        dp[i]= (dp[i-2] + dp[i-1])%1000000007;
    answer =dp[n];
    return answer;
}

//n =1 , =>1
//n=2 , =>2
//n=3 , =>3
//n=4, =>5
//n =5 =>8,
//가로의 길이 2 ., 세로의길이 1  세로의 길이가 2 이고 가로의길이가 n 