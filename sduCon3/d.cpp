#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int n = str.size();
    stack<char> a;
    int k=0;
    for(int i=0;i<n;i++){
        if(a.empty()){
            a.push(str[i]);
        }else{
            if(a.top() ==str[i]){
                a.pop();
                k++;
            }else{
                a.push(str[i]);
            }
        }
    }
    if(k%2==1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;

    }

    return 0;
}
