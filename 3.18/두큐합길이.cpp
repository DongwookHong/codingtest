#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    deque<int> deq1(queue1.begin(), queue1.end());
    deque<int> deq2(queue2.begin(), queue2.end());

    long long sum1 = 0, sum2 = 0;
    for (int num : queue1) sum1 += num;
    for (int num : queue2) sum2 += num;
    
    long long total = sum1 + sum2;

    long long target = total / 2;
    int cnt = 0;
    int maxcnt = queue1.size() *3;
    while (cnt <= maxcnt) {
        if (sum1 == target) return cnt;

        if (sum1 > target) {  
            int num = deq1.front();
            deq1.pop_front();
            deq2.push_back(num);
            sum1 -= num;
            sum2 += num;
        } else { 
            int num = deq2.front();
            deq2.pop_front();
            deq1.push_back(num);
            sum2 -= num;
            sum1 += num;
        }
        cnt++;
    }
    return -1;  
}
