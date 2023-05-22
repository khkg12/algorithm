#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int solution(string dirs) {
int answer = 0;
int size = dirs.size();
map<pair<pair<int, int>, pair<int, int>>, bool> m;
int curX = 0;
int curY = 0;

    for(int i = 0; i < size; i++){
        int startX = curX;
        int startY = curY;
        if(dirs[i] == 'U'){
            if(curY + 1 > 5) continue;
            curY++;
        }
        else if(dirs[i] == 'D'){
            if(curY - 1 < -5) continue;
            curY--;
        }
        else if(dirs[i] == 'R'){
            if(curX + 1 > 5) continue;
            curX++;
        }
        else if(dirs[i] == 'L'){
            if(curX - 1 < -5) continue;
            curX--;
        }

        cout << curX << "," << curY << " / " << startX << "," << startY << " ";

        if(m[make_pair(make_pair(startX, startY), make_pair(curX, curY))] == true) continue;

        m[make_pair(make_pair(startX, startY), make_pair(curX, curY))] = true;
        m[make_pair(make_pair(curX, curY), make_pair(startX, startY))] = true;
        answer++;
    }


    return answer;

}
