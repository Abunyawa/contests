#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
/*
6 5 0
2 5 0
2 4 0
1 2 1
1 3 0
6 2 0

*/
map<pii,int> p;
int ans[100100];
vi g[100100];
bool used[100100];
int n;
int curN = 0;
void dfs(int v){
    used[v] = true;
    queue<pii> q;
    q.push({v,-1});
    while(!q.empty()){
        int prev = q.front().S;
        int cr = q.front().F;
        q.pop();

        if(prev!=-1){
            ans[p[{prev,cr}] ] = curN%(n-1);
            curN+=(n-2);
        }
        for(int i=0;i<g[cr].size();i++){
            if(!used[g[cr][i]]){
                q.push({g[cr][i],cr});
                used[g[cr][i]] = true;
            }
        }
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u-1].pb(v-1);
        p[{u-1,v-1}] = i;
    }
    
    dfs(0);
    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<endl;
    }
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}