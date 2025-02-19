#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end()); 
    int index = 0;  
    int k = people.size()-1;
    int cnt = 0;

    while (index <= k) {
        if (people[index] + people[k] <= limit)index++;
        k--; 
        cnt++;
    }
    
    return cnt;
}
