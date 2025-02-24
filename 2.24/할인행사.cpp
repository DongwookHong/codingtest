#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map <string ,int>  fruits;
    
    for (size_t i = 0; i < want.size(); ++i) 
        fruits[want[i]] = number[i];
    
    int n = discount.size();
    
    for (int i =0 ; i <=n-10;i++)
    {
        unordered_map<string, int> dc;
        
        for (int j = 0; j < 10; j++) 
            dc[discount[i + j]]++;
        
       if (dc == fruits) {
            answer++;
        } 

    }
    
    return answer;
}

//속도가 그렇게 빠르지는않음 .. 음 unordered_map 이것도 비교할 수 있다는걸알게되어서 사용했다 
// 기본적으로 unordered_map -> map의 차이는  map -> 키순으로 정렬이됨 , unorded-> g해쉬기반으로 순서 x
// 속도 차이가 생각보다 많이남 o log N , o(1) 최악일경우 o(n); 
// 벗 메모리는 Unorded -> 해쉬를 사용하기때문에더 많이사용 