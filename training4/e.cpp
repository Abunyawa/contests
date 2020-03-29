#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int g[200100];
int ans = 0;
bool used[200100];
int c[200100];

void dfs(int v){
    used[v] = true;
    if(used[v]==0){
        ans+=c[v];
        return;
    }
    if(!used[g[v]]){
        dfs(g[v]);
    }
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x!=i+1){
            if(g[x]!=i+1)
                g[i+1] = x;
        }
    }
    for(int i=1;i<n;i++){
        if(!used[i]){
            dfs(i);
        }
    }

    cout<<ans<<endl;
    return 0;
}