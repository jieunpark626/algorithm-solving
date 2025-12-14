#include <iostream>
#include <vector>


using namespace std;

vector<pair<int,int>> loc;

bool can_fill(int board[10][10], int x, int y, int num){
    //1. 가로 검사 x행
    for(int c=0; c<9; c++){
        if(board[x][c]==num) return false;
    }

    //2. 세로 검사 y열
    for(int r=0; r<9; r++){
        if(board[r][y]==num) return false;
    }

    //3. 3*3 검사
    int grid_x = x/3*3; int grid_y=y/3*3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i+grid_x][j+grid_y]==num) return false;
        }
    }

    return true;
}

bool dfs(int board[10][10], int idx){
    if(idx==loc.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        return true;
    }
    int x = loc[idx].first; int y = loc[idx].second;

    // 들어가다가 안되면 다른거 넣어보기
    for(int i=1; i<=9; i++){
        if(can_fill(board, x,y,i)){
            board[x][y] = i;
            if(dfs(board, idx+1)) return true;
            board[x][y] = 0;
        }
    }

    // 1-9 아무것도 못넣으면 false 반환
    return false;
}

int main(){ 
    int board[10][10];

    int num;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>num;
            board[i][j]=num;
            if(num==0) loc.push_back({i,j});
        }
    }

    dfs(board, 0);

    return 0;
}