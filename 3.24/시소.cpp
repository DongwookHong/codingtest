#include <string>
#include <iostream>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> cnt(1001, 0);

    for (int w : weights) {
        cnt[w]++;
    }
    for (int w : weights) {
        if (w % 2 == 0) {
            long long base = (w / 2) * 3;
            if (base <= 1000) answer += cnt[base];
        }
        if (w % 3 == 0) {
            long long base = (w / 3) * 4;
            if (base <= 1000) answer += cnt[base];
        }
        long long base = w * 2;
        if (base <= 1000) answer += cnt[base];
    }

    for (int i = 100; i <= 1000; i++) {
        if (cnt[i] >= 2) {
            answer += (cnt[i] * (cnt[i] - 1)) / 2;
        }
    }

    return answer;
}
//문제이해가안가서 블로그참조함 