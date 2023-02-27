#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int zero;
int change;  
 int length;
size_t pos;
string tmp;

vector<int> solution(string s) {
vector<int> answer;

    while(s != "1"){
        tmp = "";
        while((pos = s.find("0")) != string::npos){
            s.erase(pos, 1);
            zero++;
        }
        length = s.size();
        while(length != 0){
            tmp.insert(0, to_string(length % 2));
            length /= 2;
        }
        s = tmp;
        change++;
    }

    answer.push_back(change);
    answer.push_back(zero);


    return answer;

}
