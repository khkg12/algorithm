#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int func(int a, string s){
string str;  
 int plus = s.size(), cnt = 1;
bool flag = false;

    str = s.substr(0, a);

    for(int i = a; i < s.size(); i+=a){
        string str2;
        str2 = s.substr(i, a);
        if(str == str2){
            plus -= a;
            flag = true;
            cnt++;
        }
        else{
            if(flag == true){
                if(cnt < 10) plus++;
                else if(cnt >= 10 && cnt < 100) plus += 2;
                else if(cnt >= 100 && cnt < 1000) plus += 3;
                else if(cnt == 1000) plus += 4;
            }
            cnt = 1;
            flag = false;
            str = str2;
        }
    }
    if(flag == true){
        if(cnt < 10) plus++;
        else if(cnt >= 10 && cnt < 100) plus += 2;
        else if(cnt >= 100 && cnt < 1000) plus += 3;
        else if(cnt == 1000) plus += 4;
    }

    return plus;

}

int solution(string s) {
int answer = 1001;
int size = s.size() / 2;
for(int i = 1; i <= size; i++){
int num = func(i, s);
answer = min(answer, num);
}
if(s.size() == 1) return 1;
return answer;
}
