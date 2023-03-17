#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    if(x == y) return 0;
    int answer = 0;
    queue<pair<int, int>> q;
    set<int> set;
    
    q.push({x, 0});
    
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        if(top.first == y){
            answer = top.second;
            break;
        }
        else if(top.first < y){
            int X2 = top.first * 2;
            if(set.insert(X2).second){ // 중복되지않는 값이라면
                q.push({X2, top.second + 1});
            }
            int X3 = top.first * 3;
            if(set.insert(X3).second){ // 중복되지않는 값이라면
                q.push({X3, top.second + 1});
            }
            int Xn = top.first + n;
            if(set.insert(Xn).second){ // 중복되지않는 값이라면
                q.push({Xn, top.second + 1});
            }
        }        
    }
    
    if(answer == 0) return -1;
    
    return answer;
}