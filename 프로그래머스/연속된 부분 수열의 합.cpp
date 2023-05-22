#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
vector<int> answer(2, 0); // answer[0]을 쓰기 위해 할당
queue<pair<int, int>> q; // 인덱스도 받아야 하기 저장해놔야 나중에 저장할수있기 때문에 pair
int sum = 0;  
 int Min_Num = 1000001;
for(int i = 0; i < sequence.size(); i++){
sum += sequence[i];
q.push({sequence[i], i});
while(sum > k){
sum -= q.front().first; // sum이 k보다 작거나 같아질때까지
q.pop();
}
if(sum == k){  
 if(Min_Num > q.size()){
int x = q.front().second, y = q.back().second;
Min_Num = q.size();
answer[0] = x, answer[1] = y;
}
}  
 }

    return answer;

}
