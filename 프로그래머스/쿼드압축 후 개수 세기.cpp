#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
vector<int> answer;
int array[2] = {0,};



void dfs(vector<vector<int>> &arr, int n, int idx, int idx2){        
    bool zero = true, one = true;    
    
    for(int i = idx; i < idx + n; i++){
        for(int j = idx2; j < idx2 + n; j++){            
            if(arr[i][j] == 1) zero = false;
            if(arr[i][j] == 0) one = false;
        }
    }
    
    if(zero == true) { // 만약 모든 수가 0이라면 거기서 그 재귀함수 dfs는 종료한다.
        array[0]++;
        return;
    }
    if(one == true) {
        array[1]++;
        return;
    }
    
    dfs(arr, n / 2, idx, idx2);
    dfs(arr, n / 2, idx + n / 2, idx2);
    dfs(arr, n / 2, idx, idx2 + n / 2);
    dfs(arr, n / 2, idx + n / 2, idx2 + n / 2);    
}

vector<int> solution(vector<vector<int>> arr) {
    
    int n = arr.size();
    dfs(arr, n, 0, 0);
    
    
    answer.push_back(array[0]);
    answer.push_back(array[1]);
    
    return answer;
}