#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> answer(1,-1);
int MaxNum = 0;

bool cmp(vector<int> ryan){
for(int i = 10; i >= 0; i--){
if(ryan[i] < answer[i]) return false; // 가장 낮은 점수값이 현재저장되어있는 answer의 값보다 지금 막 생성된 ryan의 값이 더 작을경우, 즉 유지해야함 answer을 따라서 return해주어야함
else if(ryan[i] > answer[i]) return true;
}
}

void calcScore(vector<int> ryan, vector<int> apeach){
int ryanSum = 0, apeachSum = 0;
for(int i = 0; i < 11; i++){
if(ryan[i] > apeach[i]){
ryanSum += 10-i;
}  
 else if(apeach[i] > 0)apeachSum += 10-i;
}
int diff = ryanSum - apeachSum;
if(diff > 0 && MaxNum <= diff){
if(MaxNum == diff && !cmp(ryan)) return;
MaxNum = diff;
answer = ryan;
}
}

void dfs(int idx, int arrow, vector<int> ryan, vector<int> apeach){
cout << idx << " ";
if(idx == 11 || arrow == 0){ // 분배 끝
ryan[10] += arrow; //arrow가 남아있을 때 모든 화살을 마지막화살로
calcScore(ryan, apeach);
ryan[10] -= arrow; // 마찬가지로 아래의 dfs에서 영향주지않기 위함
return;
}
if(apeach[idx] < arrow){ // 어피치가 맞춘 과녁의 화살보다 현재 가지고 있는 화살의 갯수가 더 많다면
ryan[idx] += apeach[idx] + 1;
dfs(idx+1, arrow-apeach[idx]-1, ryan, apeach);  
 ryan[idx] -= apeach[idx] + 1; // 여기서 빼주는 이유는 아래의 dfs문에서의 영향을 주지않기위함
}
dfs(idx+1, arrow, ryan, apeach); // 화살을 부여하지 않는 경우
}

vector<int> solution(int n, vector<int> info) {
vector<int> ryan(11,0);
dfs(0, n, ryan, info);

    return answer;

}
