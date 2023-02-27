#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
vector<int> answer;
map<string, int> map;

    for(int i = 65; i <= 90; i++){ // 사전 채우기
        char ca = char(i);
        string s;
        s.push_back(ca);
        map[s] = i - 64;
    }


    int num = 26;

    for(int i = 0; i < msg.size();){
        string tmp = "";
        tmp.push_back(msg[i]);

        while(1){
            if(map.find(tmp) != map.end()){ // 사전에 존재하는 값이라면
                tmp.push_back(msg[i+1]);
                i += 1;
            }
            else{ // 사전에 없는 단어라면
                map[tmp] = ++num;
                tmp.erase(tmp.size()-1, 1); // 마지막 단어삭제
                answer.push_back(map[tmp]); // answer에 현재입력값 인덱스 추가
                break;
            }
        }
    }

    cout << map["K"] << " ";
    cout << map["KA"] << " ";

    return answer;

}
