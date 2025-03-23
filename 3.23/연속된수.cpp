#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> solution(vector<int> sequence, int k) {
    int left = 0, right = 0;
    int sum = sequence[0];
    int min_length = sequence.size() + 1;
    vector<int> answer = {0, static_cast<int>(sequence.size()-1)};
    
    while(right < static_cast<int>(sequence.size())) {  
        if(sum == k) {
            if(right-left < min_length) {
                min_length = right-left;
                answer = {left, right};
            }
            sum -= sequence[left];
            left++;
        } else if(sum > k) {
            sum -= sequence[left];
            left++;
        } else {
            right++;
            if(right < sequence.size()) {
                sum += sequence[right];
            }
        }
    }
    return answer;
}

//존애 퓰었던게잇어서./..