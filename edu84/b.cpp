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

void solve(){
    int n;
    cin>>n;
    vector<int> g[n];
    vector<bool> used(n+1,false); 
    vector<bool> usedF(n,false); 
    for(int i =0; i<n;i++){
        int k;
        cin>>k;
        int min = n+1;
        for(int j=0;j<k;j++){
            int a;
            cin>>a;
            g[i].pb(a);
        }
    }
    for(int i=0;i<n;i++){
        int j=0;
        while(j<g[i].size() && used[g[i][j]]){
            j++;
        }
        if(j<g[i].size()){
            used[g[i][j]] = true;
            usedF[i] = true;
        }
    }
    for(int i=0;i<n;i++){
        if(!usedF[i]){
            for(int j=1;j<=n;j++){
                if(!used[j]){
                    cout<<"IMPROVE"<<endl;
                    cout<<i+1<<' '<<j<<endl;
                    return;
                }
            }
        }
    }
    cout<<"OPTIMAL"<<endl;
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
