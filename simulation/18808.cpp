#include <iostream>
#include <vector>

using namespace std;

int N,M,K; // 행,열,갯수
vector<vector<int>> board;
vector<vector<vector<int>>> stickers;
//90도 회전
vector<vector<int>> rotate(vector<vector<int>> v){
    int n = v.size(); // 행
    int m = v[0].size(); //열
    vector<vector<int>> result(m, vector<int>(n)); // m행 n열
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            result[j][i] = v[n-1-i][j];
        }
    }
    return result;
}

int main(){
    cin>>N>>M>>K;
    board.assign(N, vector<int>(M,0));
    stickers.resize(K); // K개의 2차원 벡터 받을 공간만 만들기
    int r,c;
    for(int i=0; i<K; i++){
        cin>>r>>c;
        stickers[i].assign(r,vector<int>(c));
        for(int x=0; x<r; x++){
            for(int y=0; y<c; y++){
                cin>>stickers[i][x][y];
            }
        }
    }

    for(int S=0; S<K; S++){ //스티커마다

        for(int rt=0; rt<4; rt++){ // 회전
            int r = stickers[S].size(); // 행 길이
            int c = stickers[S][0].size(); // 열 길이
            bool possible = false;
        
            for(int sx=0; sx<=N-r; sx++){
                for(int sy=0; sy<=M-c; sy++){
                    possible = true;
                    //비교
                    for(int x=sx; x<sx+r; x++){
                        for(int y=sy; y<sy+c; y++){
                            if(stickers[S][x-sx][y-sy]==1 && board[x][y]==1){
                                possible = false;
                            }
                        }
                    }

                    if(possible){
                        for(int x=sx; x<sx+r; x++){
                            for(int y=sy; y<sy+c; y++){
                                if(stickers[S][x-sx][y-sy]==1){
                                    board[x][y]=1;
                                }
                            }
                        }
                        break;
                    }
                }
                if(possible) break;
            } 
            if(possible) break;
            stickers[S] = rotate(stickers[S]);
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]==1) ans++;
        }
    }
    cout<<ans;
}