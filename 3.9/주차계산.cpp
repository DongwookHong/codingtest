#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;


int timetomin(string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> park; 
    map<string, int> inTime; 
    vector<pair<string, int>> bill;
    
    
    for (string& record : records) {
        stringstream ss(record);
        string time, carnum, entry;
        ss >> time >> carnum >> entry;
        
        int minutes = timetomin(time);
        if (entry == "IN") {
            inTime[carnum] = minutes;
        } else if (entry == "OUT") {
            park[carnum] += (minutes - inTime[carnum]);
            inTime.erase(carnum);
        }
    }
     
    for (auto [carnum, time] : inTime) 
        park[carnum] += (1439 - time);
    

    for (auto [carnum, use] : park) {
        int cost = fees[1];
        if (use > fees[0]) {
            cost += ceil((double)(use - fees[0]) / fees[2]) * fees[3];
        }
        bill.push_back({carnum, cost});
    }
    
    
    sort(bill.begin(), bill.end());
    
    
    
    for (auto [carnum, fee] : bill) {
        answer.push_back(fee);
    }
    return answer;
}
