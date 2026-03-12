#include <iostream>
#include <string>

using namespace std;


string line; 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--){
        cin>>line;
        if(line[0]>'F'){
            cout<<"Good\n";
            continue;
        }

        int cnt=0; int idx=1;
        if(line[0]=='A') cnt++;
        
        bool found = false;
        for(char c: {'A','F','C'}){
            if(found) break;
            while(line[idx]==c){ cnt++; idx++; }
            if(cnt<1){
                cout<<"Good\n"; found = true;
            }
            cnt=0;
        }

        if(found) continue;

        if(line[line.size()-1]>'F'){
            cout<<"Good\n"; continue;
        }
        
        cout<<"Infected!\n";
    }

    return 0;
}