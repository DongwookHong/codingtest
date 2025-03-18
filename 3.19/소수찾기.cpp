#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

void makenum(string numbers, string current, vector<bool>& used, set<int>& result) {
    if (current.length() > 0) {
        result.insert(stoi(current));
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            makenum(numbers, current + numbers[i], used, result);
            used[i] = false;
        }
    }
}

bool isPrime(int num) {
    if (num < 2) return false;
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) 
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    set<int> n;
    vector<bool> used(numbers.size(), false);
    
    makenum(numbers, "", used, n);
    
    int count = 0;
    
    for (int num : n) {
        if (isPrime(num)) {
            count++;
        }
    }
    
    return count;
}
