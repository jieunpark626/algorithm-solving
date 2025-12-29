#include <iostream>
#include <queue>
#include <string>

using namespace std;
const int MAX = 10000;
int A, B;
bool visited[MAX+1];

void init(){
    for(int i=0; i<=MAX+1; i++){
        visited[i]=false;
    }
}

void bfs(){
    queue<pair<int,string>> q;
    q.push({A,""}); visited[A]=true;

    while(!q.empty()){
        pair<int,string> cur = q.front(); q.pop();
        int n=cur.first;
        if(n==B){
            cout<<cur.second<<endl; return;
        }
        int cal[] = {(n*2)%10000, n==0?9999:n-1, (n%1000)*10 +(n/1000), (n%10)*1000+(n/10)};

        for(int i=0; i<4; i++){
            int result = cal[i];
            if(visited[result]==false){
                visited[result]=true; 
                
                char c;
                if(i==0) c='D';
                else if(i==1) c='S';
                else if(i==2) c='L';
                else if(i==3) c='R';

                q.push({result, cur.second+c});
            }
        }
    }

}

int main(){
    int T;   
    cin>>T;

    for(int tc=0; tc<T; tc++){
        cin>>A>>B;
        init();
        bfs();
    } 

    return 0;
}