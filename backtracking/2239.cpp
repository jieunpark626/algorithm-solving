#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> loc;

void print(int board[10][10]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}

bool can_fill(int board[10][10], int x, int y, int num){
    for(int c=0; c<9; c++){
        if(board[x][c]==num) return false;
    }
    for(int r=0; r<9; r++){
        if(board[r][y]==num) return false;
    }
    int grid_x=x/3*3; int grid_y=y/3*3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i+grid_x][j+grid_y]==num) return false;
        }
    }
    return true;
}

bool dfs(int board[10][10], int idx){
    if(idx==loc.size()){
        print(board);
        return true;
    }
    int x=loc[idx].first; int y=loc[idx].second;
    for(int num=1; num<=9; num++){
        if(can_fill(board, x, y, num)){
            board[x][y]=num;
            if(dfs(board, idx+1)) return true;
            board[x][y]=0; // 만약 x,y를 num으로 바꿨는데 아래에서 실패하면(false) 다시 돌려줌
        }
    }
    return false; //어떤 경우라도 성공했으면 return true로 빠졌을것임
}

int main(){
    int board[10][10];

    string line;
    for(int i=0; i<9; i++){
        cin>>line;
        for(int j=0; j<9; j++){
            board[i][j] = line[j]-'0';
            if(board[i][j]==0) loc.push_back({i,j});
        }
    }
    dfs(board, 0);

    return 0;
}