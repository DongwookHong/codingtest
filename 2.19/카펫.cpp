#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer; 
    int total = brown + yellow;
    
    for (int w = 3; w <= total; ++w) {
        if (total % w == 0) { 
            int h = total / w;
            
            if ((w - 2) * (h - 2) == yellow) { 
                answer.push_back(h);
                answer.push_back(w);
                return answer;
            }
        }
    }
    
    return answer; 
}

//너무 어려움 .. 