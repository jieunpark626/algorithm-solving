#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(){
    cin>>N;
    vector<int> p(N+1,-1);
    
    queue<int> q;
    q.push(N);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();

        if(cur==1) break;

        if(cur%3==0 && p[cur/3]==-1){
            p[cur/3] = cur;
            q.push(cur/3);
        }
        if(cur%2==0 && p[cur/2]==-1){
            p[cur/2] = cur;
            q.push(cur/2);
        }
        if(p[cur-1]==-1){
            p[cur-1] = cur;
            q.push(cur-1);
        }
    }

    int cur = 1;
    vector<int> v;
    
    v.push_back(1);
    while(cur!=N){
        v.push_back(p[cur]);
        cur=p[cur];
    }

    reverse(v.begin(), v.end());
    cout<<v.size()-1<<endl;
    for(int n: v){
        cout<<n<<" ";
    }

    return 0;
}