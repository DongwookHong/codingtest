#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


const int fatigue[3][3] = {
    {1, 1, 1}, 
    {5, 1, 1}, 
    {25, 5, 1} 
};


int calculateFatigue(const vector<string>& minerals, int start, int end, int pickType) {
    int totalFatigue = 0;
    for (int i = start; i < end; ++i) {
        if (minerals[i] == "diamond") {
            totalFatigue += fatigue[pickType][0];
        } else if (minerals[i] == "iron") {
            totalFatigue += fatigue[pickType][1];
        } else if (minerals[i] == "stone") {
            totalFatigue += fatigue[pickType][2];
        }
    }
    return totalFatigue;
}


int dfs(vector<int> picks, const vector<string>& minerals, int index) {    
    if (index >= minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)) {
        return 0;
    }

    int minFatigue = INT_MAX;
    
    for (int i = 0; i < 3; ++i) {
        if (picks[i] > 0) { 
            picks[i]--; 
            int nextIndex = min(index + 5, (int)minerals.size());
            int fatigueCost = calculateFatigue(minerals, index, nextIndex, i);
            int remainingFatigue = dfs(picks, minerals, nextIndex); 
            minFatigue = min(minFatigue, fatigueCost + remainingFatigue);
            picks[i]++;
        }
    }

    return minFatigue; 
}

int solution(vector<int> picks, vector<string> minerals) {
    return dfs(picks, minerals, 0);
}


//전에 풀었던문제 다시 푸는데 이번에도 실패했음 / 전에꺼 다시 참고해서 다시풀었음 .. 