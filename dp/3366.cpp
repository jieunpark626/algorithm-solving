#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[43][5];

void init(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            dp[i][j]=987654321;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int input;
    cin>>input;
    while(input!=0){
        init(input);
        pair<int,int> v[43]; // 거리,시간
        for(int i=0; i<input; i++){
            int p,t;
            cin>>p>>t;
            v[i]={p,t};
        }
 
        int dist=v[0].first;
        int time=v[0].second;
        if(dist<=time){
            dp[0][1] = dist;
        } else{
            cout << "NG 1\n"; continue;
        }

        int i;
        for(i=0; i<input-1; i++){
            bool flag=false;
            for(int k=0; k<=3; k++){
                if(dp[i][k]==987654321) continue;

                int pos=v[i].first; int time=v[i].second;
                int npos=v[i+1].first; int ntime=v[i+1].second;
                if(k<3){
                    int move=npos-pos;
                    if(move<0) move = move*(-1); 
                    int move_time=move*(k+1);
                    if(ntime>=time+move_time){
                        flag=true;
                        dp[i+1][k+1] = min(dp[i+1][k+1], dp[i][k] + move);
                    }
                }

                int move=pos+npos; int move_time=pos*(k+1)+npos;
                if(ntime>=time+move_time){
                    flag=true;
                    dp[i+1][1]=min(dp[i+1][1],dp[i][k]+move);
                }
            }
            if(!flag) {
                cout<<"NG "<<i<<'\n';
                break;
            }
        }
        
        if(i==input-1){
            int ans=987654321;
            for(int k=1; k<4; k++){
                ans = min(dp[i][k]+v[i].first,ans);
            }

            cout<<"OK "<<ans<<"\n";
        }


        cin>>input;
    }
    return 0;
}