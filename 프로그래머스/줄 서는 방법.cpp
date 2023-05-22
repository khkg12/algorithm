#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int sum = 1;
long long fac(int n){ // 팩토리얼 함수
if(n <= 1) return 1;
return n \* fac(n-1);
}

vector<int> solution(int n, long long k) {
vector<int> answer;
vector<long long> num;

    for(int i = 1; i <= n; i++){ // num vector 채우기
        num.push_back(i);
    }
    long long now = k;
    while(num.size() > 0){ // num의 자리수(첫번째로 올 자리수 다음엔 두번째) 를 구한뒤 삭제
        long long tmp = fac(num.size() - 1); // (n-1)!
        long long first_num = (now-1) / tmp; // k에 1을 빼고 나누는 이유는 인덱스는 1적기때문에 빼주는 것
        now %= tmp;  // k는 tmp로 나눈 나머지로
        if(now == 0) now = tmp; // 만약 k가 나누어떨어진다면 (n-1)!이라는 뜻으로 그대로 넣어줌
        answer.push_back(num[first_num]);
        num.erase(num.begin() + first_num);
    }
    return answer;

}
