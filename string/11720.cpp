#include <iostream>
#include <string>

using namespace std;

int N;
string line;

int main(){
    cin>>N>>line;

    int sum=0;
    for(int i=0; i<N; i++){
        sum += line[i]-'0';
    }

    cout<<sum;
    return 0;
}