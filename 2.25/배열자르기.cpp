#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    
    for (long long i = left; i <= right; ++i) {
    
        long long row = i / n;
    
        long long col = i % n;
        
    
        answer.push_back(max(row, col) + 1);
    }
    
    return answer;
}
//규칙을 못찾음 ... 다른 사람꺼 참고함 