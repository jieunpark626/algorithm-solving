#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N,M;
int grid[5][5];

vector<vector<pair<int,int>>> b[5][5];
bool visited[5][5];

int answer = 0;
void dfs(int x, int y, int sum){
    int nextX=x; int nextY=y;
    if(x>=N){
        if(sum>answer) answer = sum;
        return;
    }

    if(y==M-1){
        nextX=x+1;
        nextY=0;
    }else{
        nextY+=1;
    }

    if(visited[x][y]==true){
        dfs(nextX, nextY, sum);
        return;
    }

    for(vector<pair<int,int>> combis: b[x][y]){ 
        int num=0;
        bool possible = true;

        for(pair<int,int> locs: combis){
            int nx=locs.first; int ny=locs.second;
            if(visited[nx][ny]){
                possible = false;
                break;
            }
        }
        if(possible == false) continue;

        for(pair<int,int> locs: combis){
            int nx=locs.first; int ny=locs.second;
            if(visited[nx][ny]) continue;
            visited[nx][ny]=true;
            num = 10*num + grid[nx][ny];
        }
        dfs(nextX, nextY, sum+num);
        for(pair<int,int> locs: combis){
            int nx=locs.first; int ny=locs.second;
            visited[nx][ny]=false;
        }
    }
}

int main(){
    cin>>N>>M;
    string line;
    for(int i=0; i<N; i++){
        cin>>line;
        for(int j=0; j<M; j++){
            grid[i][j]=line[j]-'0';
        }
    }

    if(N==1&&M==1){
        cout<<grid[0][0]; return 0;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            vector<pair<int,int>> vy = {};
            for(int y=j; y<M; y++){
                vy.push_back({i,y});
                b[i][j].push_back(vy);
            }
            vector<pair<int,int>> vx = {{i,j}};
            for(int x=i+1; x<N; x++){
                vx.push_back({x,j});
                b[i][j].push_back(vx);
            }
        }
    }

    
    
    dfs(0,0,0);
    cout<<answer;
    return 0;
}