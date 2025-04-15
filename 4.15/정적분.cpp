#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> v = {k};

    while (k != 1) {
        if (k % 2 == 0) k /= 2;
        else k = k * 3 + 1;
        v.push_back(k);
    }

    int n = v.size() - 1;

    vector<double> area(n);
    for (int i = 0; i < n; ++i) {
        area[i] = (v[i] + v[i + 1]) / 2.0;
    }

    vector<double> answer;
    for (auto& range : ranges) {
        int start = range[0];
        int end = n + range[1]; 

        if (start > end) {
            answer.push_back(-1.0);
        } else {
            double sum = 0;
            for (int i = start; i < end; ++i) {
                sum += area[i];
            }
            answer.push_back(sum);
        }
    }

    return answer;
}
