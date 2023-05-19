#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool check[201] = {false,};
void dfs(vector<vector<int>> computers, int node, int n){
    if(check[node] == true) return;
    else if(check[node] == false){        
        check[node] = true;
        for(int i = 0; i < n; i++){
            if(computers[node][i] == 1 && check[i] == false){
                dfs(computers, i, n);                
            }
        }    
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(check[i] == false){
            dfs(computers, i, n);
            answer++;
        }                
    }
    
    return answer;
}