#include <string>
#include <vector>
#include <numeric>

using namespace std;
int S;

int Index(int idx){ // 인덱스가 사이즈를 넘어갔을 때 0으로 바꾸기 위한 함수
return idx + 1 >= S \* 2 ? 0 : idx + 1;
}

int solution(vector<int> queue1, vector<int> queue2) {
int answer = 0;
long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
S = queue1.size();
queue1.insert(queue1.end(), queue2.begin(), queue2.end()); // 두 큐 합치기
int p1_1 = 0, p1_2 = S - 1;
int p2_1 = S, p2_2 = queue1.size()-1;
while(answer <= 5\*S){
if(sum1 > sum2){
sum1 -= queue1[p1_1];
sum2 += queue1[p1_1];
p1_1 = Index(p1_1);
p2_2 = Index(p2_2);
}
else if(sum1 < sum2){
sum1 += queue1[p2_1];
sum2 -= queue1[p2_1];
p2_1 = Index(p2_1);
p1_2 = Index(p1_2);
}
else{
return answer;
}
answer++;
}
return -1;
}
