#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
stack<char> stk;

    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == '('){
            stk.push(s[i]);
        }
        else{
            if(!stk.empty()){ // 스택이 비어있지 않다면
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
    }

    if(stk.empty()){ // 비어있다면
        return true;
    }
    else{
        return false;
    }

}
