#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool func(vector<string> v, int i, int j){
    if(i + 1 < 5 && v[i+1][j] == 'P') return true;
    if(i - 1 > -1 && v[i-1][j] == 'P') return true;
    if(j + 1 < 5 && v[i][j+1] == 'P') return true;
    if(j - 1 < -1 && v[i][j-1] == 'P') return true;
    if(i + 2 < 5 && v[i+2][j] == 'P' && v[i+1][j] != 'X') return true;
    if(i - 2 > -1 && v[i-2][j] == 'P' && v[i-1][j] != 'X') return true;
    if(j + 2 < 5 && v[i][j+2] == 'P' && v[i][j+1] != 'X') return true;
    if(j - 2 < -1 && v[i][j-2] == 'P' && v[i][j-1] != 'X') return true;
    return false;
}

bool func2(vector<string> v, int i, int j){
    if((i + 1 < 5 && j + 1 < 5 && v[i+1][j+1] == 'P') && (v[i+1][j] != 'X' || v[i][j+1] != 'X')) return true;
    if((i - 1 > -1 && j - 1 > -1 && v[i-1][j-1] == 'P') && (v[i-1][j] != 'X' || v[i][j-1] != 'X')) return true;
    if((i + 1 < 5 && j - 1 > -1 && v[i+1][j-1] == 'P') && (v[i+1][j] != 'X' || v[i][j-1] != 'X')) return true;
    if((i - 1 > -1 && j + 1 < 5 && v[i-1][j+1] == 'P') && (v[i-1][j] != 'X' || v[i][j+1] != 'X')) return true;
    return false;
}

int check(vector<string> v){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(v[i][j] == 'P'){
                if(func(v, i, j)) return 0;
                if(func2(v, i, j)) return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < 5; i++){
        int a = check(places[i]);        
        answer.push_back(a);
    }
    return answer;
}