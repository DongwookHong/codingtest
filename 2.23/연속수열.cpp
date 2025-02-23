#include <string>
#include <vector>
#include <deque>
#include <unordered_set>  

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    deque<int> d(elements.begin(), elements.end());
    
    
    unordered_set<int> nums; 

    int n = d.size();

    for (int length = 1; length <= n; length++) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < length; j++) {
                sum += d[(i + j) % n];  
            }
            nums.insert(sum);  
        }
        int front = d.front();
        d.pop_front();
        d.push_back(front);
    }

    answer = nums.size();
    return answer;
}
