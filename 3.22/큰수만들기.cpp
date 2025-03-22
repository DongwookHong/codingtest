#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int answerSize = number.size() - k; 
    
    
    int start = 0;
    
    
    for(int i = 0; i < answerSize; i++) {
        char num = '0';
        int maxIdx = start;
        
        for(int j = start; j <= k + i; j++) {
            if(num < number[j]) {
                num = number[j];
                maxIdx = j;
            }
        }
        
        
        start = maxIdx + 1;
        answer += num;
    }
    
    return answer;
}
