#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<char>> lines;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int cnt=5;
    string line;
    int maxline=0;
    while(cnt--){
        cin>>line;
        vector<char> tmp;
        for(int i=0; i<line.size(); i++){
            tmp.push_back(line[i]);
        }
        lines.push_back(tmp);
        maxline=max(maxline, int(tmp.size()));
    }
    string str;

    for(int i=0; i<maxline; i++){
        for(int j=0; j<5; j++){
            if(lines[j].size()-1<i) continue;
            str.push_back(lines[j][i]);
        }
    }
    cout<<str;
    return 0;
}