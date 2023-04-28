#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> w) {
    long long answer = 0;    
    
    sort(w.begin(), w.end());
    for(int i = 0; i < w.size()-1; i++){
        int cnt = i+1;
        while(w[cnt] * 2 <= w[i] * 4){
            if(w[cnt] == w[i]){
                answer++;                       
            }
            else{
                if(w[cnt]*2 == w[i]*3 || w[cnt]*2 == w[i]*4 || w[cnt]*3 == w[i]*4) answer++;
            }            
            cnt++;            
            
        }
    }
    
    
    return answer;
}