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
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

int dph[110][110];
int dpv[110][110];

void solve(){
    int n,k;
    cin>>n>>k;
    if(k%n==0){
        cout<<"POSSIBLE\n";
        int d[n][n];
        for(int i=0;i<n;i++){
            d[i][i] = k/n;
        }
        for(int i=0;i<n;i++){
            int cur = k/n+1;
            for(int j=i+1;j%n!=i;j++){
                d[i][j%n] = cur;
                cur++; 
                if(cur==n+1){
                    cur = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<d[i][j]<<' ';
            }
            cout<<'\n';
        }
    }else{
        cout<<"IMPOSSIBLE\n";
    }
    return;
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}
