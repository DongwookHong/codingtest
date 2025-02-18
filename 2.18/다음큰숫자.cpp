#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

int oneCount(int n)
{
    int cnt =0;
    bitset<32> bit(n);
    
    for (int i =0; i<32; i++)
        if(bit[i]==1)cnt++;
    
    return cnt;
}

int solution(int n) {
    int num = oneCount(n);
    int nextnum= n+1;    
    while(num != oneCount(nextnum))
        ++nextnum;

    return nextnum;
}





// #include <string>
// #include <vector>

// using namespace std;

// int solution(int num) {
//    int ones = __builtin_popcount(num); // 현재 숫자의 1의 개수

//     while (true) {
//         num++; // 다음 숫자로 이동
//         if (__builtin_popcount(num) == ones) {
//             return num; // 1의 개수가 같으면 반환
//     }
// }


//c++도 자바와 같은기능이 있다고 해서 한번 찾아봄 
// 속도차이는 거의 미비하다고 볼수있음 