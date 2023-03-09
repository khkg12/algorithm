#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
vector<long long> answer;
int size = numbers.size();
for(int i = 0; i < size; i++){
if(numbers[i] % 2 == 0) answer.push_back(numbers[i] + 1);
else{
long long bit = 1;
while(1){
if((numbers[i] & bit) == 0) break; // 1의 자리 연속이 멈춘다면
bit \*= 2; // 비트 한칸 올리기
}
bit /= 2; // 비트의 1의자리연속이 멈췄다는 것은 그 비트보다 한칸 아래의 비트를 더해줘야함
answer.push_back(numbers[i] + bit);
}
}
return answer;
}
