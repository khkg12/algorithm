#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void change(string &s){
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '#') s[i-1] = tolower(s[i-1]), s.erase(s.begin()+i);
    }
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int max = 0;
    change(m);
    for(auto i : musicinfos){
        int hour = (stoi(i.substr(6,2)) - stoi(i.substr(0,2))) * 60;        
        int minute = (stoi(i.substr(9,2)) - stoi(i.substr(3,2)));        
        int time = hour + minute;            
        
        string info = i.substr(12),
               title = info.substr(0, info.find(',')),
               melody = info.substr(info.find(',')+1);
        change(melody);        
        string str = "";
        for(int j = 0; j < time; j++){
            int idx = j % melody.size();            
            str.push_back(melody[idx]);            
        }
        
        if(str.find(m) != string::npos){
            if(max < time) max = time, answer = title;
        }
        // 비교해서 찾기 존재한다면 pair에 재생시간과 노래제목 저장
    }
    
   
    
    
    return answer;
}