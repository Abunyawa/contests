#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string a;
    cin>>a;
    int n = a.length();
    int in = 0, out = 0;
    for(int i=0;i<n;i++){
        if(a[i] == '+'){
            in++;
            out = max(out-1,0);
        }else{
            out++;
            in = max(in-1,0);
        }
    }
 
    cout<<in+out<<endl;
    return 0;
}