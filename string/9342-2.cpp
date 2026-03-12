#include <iostream>
#include <string>

using namespace std;

bool isValid(char c){
    return c>='A' && c<='F';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--){
        string line; cin >> line;

        // 중복 제거
        string compressed = "";
        for(int i=0; i<line.size(); i++){
            if(i==0||line[i] != line[i-1]){
                compressed += line[i];
            }
        }

        // 규칙 검사
        /*
        1. "{A-F|x}AFC"
        2. "AFC{A-F|x}"
        */
        
        string target = compressed;
        if(!target.empty() && target[0] != 'A' && isValid(target[0])) target.erase(0,1);

        if(!target.empty() && target.back() != 'C' && isValid(target[target.back()])) target.pop_back();

        if(target == "AFC") cout<<"Infected!\n";
        else cout<<"Good\n";
    }

    return 0;
}