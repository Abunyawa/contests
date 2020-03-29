#include<bits/stdc++.h>
using namespace std;


bool cmp(string a,string b){
    int i = 0;
    while(a[i]==b[i] && i<a.size() && i<b.size()){
        i++;
    }
    if(i>a.size()){
        return true;
    }else if(i>b.size()){
        return false;
    }else{
        return (int)a[i]<(int)b[i];
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    vector<string> logs;
    for(int i=1;i<=a.size();i++){
        for(int j = 1;j<=b.size();j++){
            logs.push_back(a.substr(0,i)+b.substr(0,j));
        }
    }
    sort(logs.begin(),logs.end(),cmp);

    cout<<logs[0]<<endl;
    return 0;
}