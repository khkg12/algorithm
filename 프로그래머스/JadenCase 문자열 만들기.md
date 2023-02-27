#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
string answer = "";

    for(int i = 0 ; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32; // 전체 s 소문자로 변환
        }
    }

    for(int i = 0 ; i < s.size(); i++){
        if(i == 0 && 'a' <= s[i] && s[i] <= 'z'){
            s[i] -= 32;
        }
        else if(s[i-1] == ' ' && 'a' <= s[i] && s[i] <= 'z'){
            s[i] -= 32;
        }
    }




    answer = s;
    return answer;

}
