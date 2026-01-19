#include <iostream>
#include <cstring>
using namespace std;

int T,W;
int loc[1003];
int dp[3][33][1003];
int main(){
    cin>>T>>W;
    for(int i=1; i<=T; i++){
        cin>>loc[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[1][W][0] = 0;

    for(int time=0; time<T; time++){
        int nextPos = loc[time+1]; // 다음에 자두 위치

        for(int pos=1; pos<=2; pos++){
            for(int cnt=0; cnt<=W; cnt++){
                int cur =  dp[pos][cnt][time];
                if(cur == -1) continue;
                if(nextPos==pos){ // 다음에 현재 위치에 자두가 있다면,
                    dp[pos][cnt][time+1]=max(dp[pos][cnt][time+1], cur + 1);
                }
                else{ // 다음에 다른 위치에 자두가 있다면
                    // 1. 자리 안바꾸고 자두도 안받기
                    dp[pos][cnt][time+1] = max(dp[pos][cnt][time+1], cur);
                    // 2. 자리 바꾸고 자두 받기 (cnt 남았을 때만 가능)
                    if(cnt>0){
                        dp[nextPos][cnt-1][time+1] = max(dp[nextPos][cnt-1][time+1],cur+1);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int pos=1; pos<=2; pos++){
        for(int cnt=0; cnt<=W; cnt++){
            // cout<<dp[pos][cnt][T]<<" ";
            if(ans<dp[pos][cnt][T]) ans = dp[pos][cnt][T];
        }
    }
    cout<<ans;
    return 0;   
}