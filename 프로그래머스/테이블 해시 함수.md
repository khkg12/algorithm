#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int idx; 
    int first;
    int col;
}state;

bool cmp(state a, state b){
    if(a.col != b.col) return a.col < b.col;
    return a.first > b.first;
}

int sum(vector<vector<int>> data, int row, int mod){
    int num = 0;
    for(int i = 0; i < data[row].size(); i++){        
        num += data[row][i] % mod;
    }
    return num;
}



int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<state> v;
    
    for(int i = 0; i < data.size(); i++){
        v.push_back({i, data[i][0], data[i][col-1]}); // 인덱스, 기본키, 기준컬럼
    }
    sort(v.begin(), v.end(), cmp); // 정렬
    
    for(int i = row_begin-1; i < row_end; i++){
        int num = sum(data, v[i].idx, i+1);        
        answer ^= num;
    }
    
    return answer;
}