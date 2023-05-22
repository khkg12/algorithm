#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
vector<string> answer;
map<string, string> m;
for(int i = 0; i < record.size(); i++){
stringstream str(record[i]);  
 vector<string> v;
string s;
while(str >> s){
v.push_back(s);
}
if(record[i][0] != 'L'){
m[v[1]] = v[2]; // 유저아이디를 키값으로 갖는 map에 닉네임을 저장
}  
 }

    for(int i = 0; i < record.size(); i++){
        stringstream str(record[i]);
        vector<string> v;
        string s;
        while(str >> s){
            v.push_back(s);
        }
        string sen;
        cout << record[i][0] << " ";
        if(record[i][0] == 'E'){
            sen += m[v[1]];
            sen += "님이 들어왔습니다.";
            answer.push_back(sen);
        }
        else if(record[i][0] == 'L'){
            sen += m[v[1]];
            sen += "님이 나갔습니다.";
            answer.push_back(sen);
        }
    }
    return answer;

}
