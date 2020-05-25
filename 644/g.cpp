#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
int n,m;


void solve(){
    int a,b;
    cin>>n>>m>>a>>b;
    if(a*n!=b*m){
        no();
        return;
    }

    int offset;

    for(int i=1;i<m;i++){
        if(i*n%m==0){
            offset = i;
            break;
        }
    }
    vector<vector<int>> ans(n,vector<int>(m,0));


    for(int i=0,j=0;i<n;i++,j+=offset){
        for(int k = 0;k<a;k++){
            ans[i][(k+j)%m] = 1;
        }
    }
    yes();

    for(int i=0;i<n;i++){
        for(int j= 0;j<m;j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }

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
