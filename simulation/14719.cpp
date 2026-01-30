#include <iostream>
#include <algorithm>
using namespace std;

int H,W;
int arr[501];
int left_max[501];
int right_max[501];
int main(){
    cin>>H>>W;
    for(int i=0; i<W; i++){
        cin>>arr[i];
    }

    int cur_max = arr[0];
    left_max[0] = cur_max;
    for(int i=1; i<W; i++){
        if(cur_max<arr[i]) cur_max = arr[i];
        left_max[i] = cur_max;
    }

    cur_max = arr[W-1];
    right_max[W-1] = cur_max;
    for(int i=W-1; i>=0; i--){
        if(cur_max<arr[i]) cur_max = arr[i];
        right_max[i] = cur_max;
    }

    int ans = 0;
    for(int i=1; i<W-1; i++){
        if(right_max[i]<=arr[i] || left_max[i]<=arr[i]) continue;
        ans += min(right_max[i],left_max[i]) - arr[i];
    }
    cout<<ans;
    return 0;
}