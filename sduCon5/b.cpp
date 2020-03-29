#include<bits/stdc++.h>
using namespace std;

bool used[1000000];
vector<int> g[100000];

void dfs(int x){
    used[x] = true;
    for(int i =0;i<g[x].size();i++){
        if(!used[g[x][i]]){
            dfs(g[x][i]);
        }
    }
}

int main(){
    int n,k,m;
    cin>>n>>k>>m;
    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    dfs(k);
    bool flag = true;
    for(int i=1;i<=n;i++){
        if(used[i]==false){
            flag = false;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}