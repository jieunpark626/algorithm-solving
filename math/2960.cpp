#include <iostream>

using namespace std;

bool nums[1000+4];
int N,K;

int main(){
    cin>>N>>K;
    int cnt=0;
    for(int i=2; i<=N; i++){
        if(nums[i]==true) continue;
        for(int j=i; j<=N; j+=i){
            if(nums[j]==false){
                nums[j] = true;
                cnt++;
                if(cnt==K) cout<<j<<endl;
            }
        }
    }
}