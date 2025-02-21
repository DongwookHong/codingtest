#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());    
    int answer = arr[0]; 
    for (int i = 1; i < arr.size(); i++) 
        answer = lcm(answer, arr[i]);
    return answer;
}
//최대공약수 -> 유클리드호재법 
//1. 큰 수를 작은 수로 나눈다(사실 큰수 작은수 나눠도 상관없다고 한다 나머지로 계산이 되기때문에 지장 X 6%8 = 나머지 8%6 이되기때문에  ).
// 다만  먾은 수가 될수록 속도 차이가 날 수있따
//2. 작은 수를 1에서 나온 나머지로 또 나눈다.
//3. 1-2를 나머지가 0이 될 때까지 반복한다.
//4. 나머지가 0이 됐을 때 나누는 수가 최대공약수이다.
//최소공배수는 -> 두수의 곱 / 최대 공약수 
