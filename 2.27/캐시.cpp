#include <string>
#include <vector>
#include <deque>
#include <algorithm> 
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache; 

    if (cacheSize == 0) 
        return cities.size() * 5;

      for (string &city : cities) {
        for (char& c : city) c = tolower(c);
          
        auto it = find(cache.begin(), cache.end(), city);

        if (it != cache.end()) { 
            answer += 1;
            cache.erase(it);
        } else { 
            answer += 5;
            if (cache.size() == cacheSize) 
                cache.pop_front();
        }
        cache.push_back(city);
}

    return answer;
}
