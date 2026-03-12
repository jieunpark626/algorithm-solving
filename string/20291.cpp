#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;

map<string,int> m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    string line;
    while(N--){
        cin>>line;
        int idx=0;
        while(line[idx]!='.'){
            idx++;
        }
        line = line.substr(idx+1);
        m[line]+=1;
    }

    for(auto& [key,value]: m){
        cout<<key<<" "<<value<<'\n';
    }


}