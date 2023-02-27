#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
stack<char> stk;

    int answer = 0;

    for(int i = 0; i < s.size(); i++){
        if(stk.size()>0 && stk.top() == s[i]) stk.pop();
        else stk.push(s[i]);
    }
    answer = stk.empty();
    return answer;

}
