#include <iostream>

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int m,n;
int board[502][502];
int dp[502][502];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>m>>n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    dp[0][0]=1;
    for(int x=0; x<m; x++){
        for(int y=0; y<n; y++){
            for(int dir=0; dir<4; dir++){
                int nx=x+dx[dir]; int ny=y+dy[dir];
                if(board[nx][ny]<board[x][y]){
                    dp[nx][ny] += dp[x][y];
                    if(dir<2){
                        int cx = nx; int cy = ny;
                        
                    }
                }

            }
        }
    }
    return 0;
}