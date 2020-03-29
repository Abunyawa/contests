#include<bits/stdc++.h>
using namespace std;

vector<int> g[100000];
int used[1000000];
int ans = 0;
void dfs(int x){
    used[x] = 1;
    for(int i=0;i<g[x].size();i++){
        if(used[g[x][i]]==0){
            dfs(g[x][i]);
        }else if(used[g[x][i]]==1){
            ans = 1;
        }
    }
    used[x] = 2;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            if(x){
                g[i].push_back(j);
            }
        }
    }
    for(int i =0;i<n;i++){
        if(used[i]==0){
            dfs(i);
        }
    }
    cout<<ans<<endl;
 
    return 0;
}