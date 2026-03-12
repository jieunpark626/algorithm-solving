#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

vector<string> split(string str){
    vector<string> result;
    for(int i=0; i<str.size();){
        string token="";
        if(isdigit(str[i])){
            while(i<str.size() && isdigit(str[i])){
                token += str[i++];
            }
        }else{
            token += str[i++];
        }
        result.push_back(token);
    }
    return result;
}

//true: str1<str2, false: str1>str2;
bool compareNumber(string str1, string str2){
    int len1 = str1.size(); int len2 = str2.size();
    
    string num1= str1.erase(0, min(str1.find_first_not_of('0'), str1.size()-1));
    string num2= str2.erase(0, min(str2.find_first_not_of('0'), str2.size()-1));

    if(num1==num2){
        return len1<len2; // 0의 개수가 적은 것이 작은거(앞에옴)
    }
    if(num1.size()!=num2.size()) return num1.size()<num2.size();
    return num1<num2;
}

// sort 함수: true면 앞으로 보냄
// compare(a, b) 가 true면 a<b -> a가 앞으로
bool compare(vector<string> str1, vector<string> str2){
    int len = min(str1.size(), str2.size());
    for(int i=0; i<len; i++){
        if(str1[i]==str2[i]) continue;

        // 숫자, 영어 -> 숫자가 앞으로 와야함
        bool isdigit1=isdigit(str1[i][0]); 
        bool isdigit2=isdigit(str2[i][0]);
        if(isdigit1 != isdigit2) return isdigit1; // true면 str1이 앞으로, false면 str2가 앞으로

        // 둘 다 숫자라면
        if(isdigit1 && isdigit2){
            return compareNumber(str1[i], str2[i]); 
        }

        // 둘 다 영어라면
        string order = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
        return order.find(str1[i])<order.find(str2[i]);
    }
    return str1.size() < str2.size();
}

int main(){
    int N; cin>>N;
    vector<vector<string>> input;

    while(N--){
        string line;
        cin>>line;
        vector<string> token = split(line);
        input.push_back(token);
    }    
    sort(input.begin(), input.end(), compare);

    for(vector<string> v: input){
        for(string str: v){
            cout<<str;
        }
        cout<<"\n";
    }
    return 0;
}