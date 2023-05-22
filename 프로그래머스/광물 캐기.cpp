#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string arr[3] = {"diamond", "iron", "stone"};

int solution(vector<int> picks, vector<string> minerals) {
    int Min_ans = 1000000;
    vector<string> v;
    for(int i = 0; i < picks.size(); i++){
        if(picks[i] != 0){
            for(int j = 0; j < picks[i]; j++){
                v.push_back(arr[i]); 
            }
        }
    }
    sort(v.begin(), v.end());   // next_permutation을 위한 정렬
    
    int size = v.size() * 5;
    
    if(size >= minerals.size()) size = minerals.size(); // 미네랄의 갯수보다 위의 사용횟수가 크다면 미네랄의 개수로 
    
    do{                
        int answer = 0;                        
        int idx = 0;
        int cnt = 0; // 곡괭이 사용회수 체크      
        for(int i = 0; i < size; i++){ // 미네랄을 돌면서         
            if(v[idx] == "diamond"){ // 다이아몬드라면                               
                answer += 1;
                cnt++; // 예제 1의 경우 다이아몬드 곡괭이 갯수가 1개이므로 총 5번을 사용가능               
            }
            else if(v[idx] == "iron"){ // 철이라면                               
                if(minerals[i] == "diamond") answer += 5;
                else answer += 1;
                cnt++;                
            }
            else if(v[idx] == "stone"){ // 돌이라면               
                if(minerals[i] == "diamond") answer += 25;
                else if(minerals[i] == "iron") answer += 5;
                else answer += 1;
                cnt++;                
            }                      
            if(cnt == 5){ // 곡괭이 사용회수 체크했을 때 전부 사용했다면
                idx++; // 다음 곡괭이로           
                cnt = 0; // 카운트 초기화
            }
        }                    
        Min_ans = min(Min_ans, answer);
    }while(next_permutation(v.begin(), v.end())); // 모든 경우의 수
    return Min_ans;
}