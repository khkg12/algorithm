#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
int answer = 0;

    for(int i = 0; i < s.size(); i++){
        stack<char> stk;
        bool check = false;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '(' || s[j] == '{' || s[j] == '['){
               stk.push(s[j]);
                check = true;
            }
            else{
                if(s[j] == ')' && stk.top() == '('){
                    stk.pop();
                }
                if(s[j] == '}' && stk.top() == '{'){
                    stk.pop();
                }
                if(s[j] == ']' && stk.top() == '['){
                    stk.pop();
                }
            }
        }
        if(stk.empty() && check) answer++;
        char first = s.front();
        s.erase(s.begin());
        s.push_back(first);
    }

    return answer;

}
