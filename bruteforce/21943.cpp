#include <iostream>
#include <vector>

using namespace std;

int N, P, Q;
vector<int> nums;
vector<int> group[10];
int cnt=0;
int ans=0;


int calc(){
    int result=1;

    for(int i=0; i<Q+1; i++){
        int sum=0;
        for(int num: group[i]){
            sum+=num;
        }
        result*=sum;
    }
    return result;
}

void solve(int idx){
    if(idx==N){
        cnt++;
        for(int i=0; i<Q+1; i++){
            if(group[i].size()==0) return;
        }
        int ret =calc();
        if(ret>ans) ans=ret;
        return;
    }


    for(int i=0; i<Q+1; i++){
        group[i].push_back(nums[idx]);
        solve(idx+1);
        group[i].pop_back();

        if(group[i].size()==0) break;
    }
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){ int n; cin>>n; nums.push_back(n); }
    cin>>P>>Q;
    // Q 그룹으로 나누기 각 그룹 더해서 곱하기
    solve(0);
    cout<<ans;
    return 0;
}