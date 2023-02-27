#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int number = 0;
int cnt = 0;
stack<char> stk;

void nFunc(int n, int num){  
 if(num == 0) stk.push('0');
while(num != 0){  
 int tmp = num % n;
char c;
if(tmp >= 10) {
tmp = tmp + 55;
c = (char)tmp;
}
else{
c = tmp + '0';  
 }  
 stk.push(c);
num /= n;
}
}

string solution(int n, int t, int m, int p) {
string answer = "";

    for(int i = 0; i < t; i++){
        for(int j = 1; j <= m; j++){
            if(stk.empty()) {
                nFunc(n, number); // 스택이 비어있다면 스택을 채우고
                number++; // num을 올려줌
            }
            if(j == p){
                answer.push_back(stk.top());
            }
            stk.pop(); // 하나씩 뺌
        }
    }

    return answer;

}
