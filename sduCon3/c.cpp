#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

int t[4*MAXN],a[MAXN], t2[4*MAXN];


int main(){
    int n,k;
    cin>>n>>k;
    bool flag = false;
    int drs[26];
    for(int i=0;i<26;i++){
        drs[i] =0;
    }
    queue<char> g;
    for(int i=0;i<n;i++){
        char s;
        cin>>s;
        g.push(s);
        drs[(int)(s-'A')]++;
    }
    set<char> ii;
    while(!g.empty()){
        char p = g.front();
        g.pop();
        drs[(int)(p-'A')]--;
        ii.insert(p);
        if(ii.size()>k){
            flag = true;
        }
        if(drs[(int)(p-'A')]==0){
            ii.erase(p);
        }
        //cout<<ii.size()<<endl;
        
    }

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}