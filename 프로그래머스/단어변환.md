#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

bool check(string s, string s2){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != s2[i]) sum++;
    }
    if(sum == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<string> q;
    q.push(begin);
    map<string, pair<bool,int>> m;
    
    bool ccc = false;
    
    for(int i = 0; i < words.size(); i++){
        m[words[i]].first = false;        
        if(words[i] == target) ccc = true;
    }
    if(ccc == false) return 0;
    
    while(!q.empty()){        
        string s = q.front();
        q.pop();
        m[s].first = true;   
        if(s == target) break;
        
        for(int i = 0; i < words.size(); i++){
            if(m[words[i]].first == false && check(words[i], s)){
                q.push(words[i]);
                m[words[i]].first = true;
                m[words[i]].second = m[s].second + 1;          
                cout << words[i] << " " << m[words[i]].second << " "; 
            }            
        }
        cout << " a ";
    }
        
    
    return m[target].second;
}