#include <iostream>

using namespace std;
int A,B;

int main(){
    cin>>A>>B;
    int cur=B;
    int cnt = 0;
    while(cur>=A){
        cnt++;
        if(cur==A){
            cout<<cnt; return 0;
        } else if(cur%10==1){
            cur /= 10;
        } else if(cur%2==0){
            cur /= 2;
        } else{
            cout<<-1; return 0;
        }
    }
    cout<<-1;
    return 0;
}