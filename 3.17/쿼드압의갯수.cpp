#include <string>
#include <vector>

using namespace std;


int zcnt = 0;
int onecnt = 0;


bool squarecheck(vector<vector<int>>& arr, int x, int y, int size) {
    int value = arr[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != value) {
                return false;
            }
        }
    }
    return true;
}


void cut(vector<vector<int>>& arr, int x, int y, int size) {
  
    if (squarecheck(arr, x, y, size)) {
        if (arr[x][y] == 0) {
            zcnt++;
        } else {
            onecnt++;
        }
        return;
    }
    
    
    int half = size / 2;
    
    
    cut(arr, x, y, half);
    cut(arr, x, y + half, half);
    cut(arr, x + half, y, half);
    cut(arr, x + half, y + half, half);
}

vector<int> solution(vector<vector<int>> arr) {
    vector <int> answer;
    zcnt = 0;
    onecnt = 0;
    
    
    int n = arr.size();
    cut(arr, 0, 0, n);
    
    answer.push_back(zcnt);
    answer.push_back(onecnt);
    return answer;
}
