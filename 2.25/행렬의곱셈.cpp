#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rows = arr1.size();     
    int cols = arr2[0].size();  
    
    
    vector<vector<int>> answer(rows, vector<int>(cols, 0));
    
    vector<vector<int>> col(arr2[0].size(), vector<int>(arr2.size()));

    for (int i = 0; i < arr2[0].size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            col[i][j] = arr2[j][i]; 
        }
    }

    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            for (int k = 0; k < arr2.size(); k++) {
                answer[i][j] += arr1[i][k] * col[j][k]; 
            }
        }
    }

    return answer;
}
