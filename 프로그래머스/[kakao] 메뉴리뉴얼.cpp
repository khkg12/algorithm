#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    else{
        return a.second > b.second;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
        
    for(int i = 0; i < course.size(); i++){        
        map<string, int> m;
        for(int j = 0; j < orders.size(); j++){            
            if(course[i] <= orders[j].size()){
                vector<int> v;
                for(int k = 0; k < course[i]; k++){
                    v.push_back(1);
                }
                for(int k = 0; k < orders[j].size()-course[i]; k++){
                    v.push_back(0);
                }     
                sort(v.begin(), v.end());
                do{
                    string tmp = "";
                    for(int l = 0; l < v.size(); l++){
                        if(v[l] == 1){
                            tmp.push_back(orders[j][l]);
                        }
                    }
                        sort(tmp.begin(), tmp.end());                                         
                        m[tmp]++;                              
                    }while(next_permutation(v.begin(), v.end()));                
            }
        }
        
        if(m.size() > 0){
            vector<pair<string, int>> v(m.begin(), m.end()); // map값을 정렬하기 위한 vector
            sort(v.begin(), v.end(), cmp);
            int max = v[0].second;
            if(max >= 2){
                for(int l = 0; l < v.size(); l++){
                    if(v[l].second == max){
                        answer.push_back(v[l].first);
                    }
                }
            }
        }
        
    }
   
    sort(answer.begin(), answer.end());
    
    return answer;
}