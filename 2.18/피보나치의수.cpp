#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int dp[n];
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for (int i =3; i<=n;++i)
        dp[i]=(dp[i-2]+dp[i-1]) %1234567;

    return dp[n];
}