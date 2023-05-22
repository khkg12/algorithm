#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;
unordered_map <string,vector<int>> um;

void addCases(string *s, int score)
{
    for(int i = 0; i < 16; i++){ // 4가지의 선택지에서 -를 포함한 경우의수는 2*2*2*2 총 16개
        int num = i;
        string str = "";
        for(int j = 0; j <= 3; j++){
            if(num == 0 || num%2 == 0){ // num이 0이거나 짝수일때 -를 포함시킬것
                str += '-';
            }
            else str += s[j];
            num /= 2; // num값을 2로나누어주면 모든 경우의 수를 구할수있다.
        }
        um[str].push_back(score); // um[str].size()가 query의 조건을 만족하는 갯수 -> 여기서 score를 비교까지
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string s[4], str="";
    
    for(int i=0; i<info.size(); i++) // 모든 info에 대하여 -를 포함한 map해시테이블 구성함수
    {
        istringstream stt(info[i]);
        stt >> s[0] >> s[1] >> s[2] >> s[3] >> str;
        addCases(s, (int)stoi(str));
    }
    
    /*for(auto i : um){ // 값이 변하지않기 때문에 안됨
        sort(i.second.begin(), i.second.end());
    }*/
    
    for(auto i = um.begin(); i != um.end(); i++){ // 마지막원소인 um.end가 아닐때까지 돌리므로 모든원소확인
        sort(i->second.begin(), i->second.end()); // 이렇게 포인터로 sort해줘야 값이 변경됨
    }
    
    for(int i = 0; i < query.size(); i++){
        istringstream stt(query[i]);        
        stt >> s[0] >> str >> s[1] >> str >> s[2] >> str >> s[3] >> str; // str에 and 넣다가 점수로 초기화, += 개념이아니라 = 개념
        int score = (int)stoi(str);
        vector<int> v = um[s[0]+s[1]+s[2]+s[3]];
        if(v.size() != 0){ // 값이 존재한다면
            int idx = lower_bound(v.begin(), v.end(), score) - v.begin(); // str보다 큰 인덱스를 반환해줌, 반환이 이터레이터이므로 그 값을 가지고 싶다면 v.begin()을 빼주면 됨
            answer.push_back(v.size() - idx);
        }
        else answer.push_back(0);
    }
    
    return answer;
}