#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
vector<int> answer;
int arr[1000][1000];

    int state = 0;
    int x = 0, y = 0;
    int num = 0;
    for(int i = 0; i < n; i++){
        switch(state){
            case 0:
                for(int j = i; j < n; j++){
                    arr[x++][y] = ++num;
                }
                x--;
                y++;
                state = 1;
                break;

            case 1:
                for(int j = i; j < n; j++){
                    arr[x][y++] = ++num;
                }
                y -= 2;
                x--;
                state = 2;
                break;

            case 2:
                for(int j = i; j < n; j++){
                    arr[x--][y--] = ++num;
                }
                y++;
                x+=2;
                state = 0;
                break;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(arr[i][j] > 0) answer.push_back(arr[i][j]);
        }
    }
    return answer;

}
