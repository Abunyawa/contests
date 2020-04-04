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
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dph[i][j] = 0;
            dpv[i][j] = 0;
        }
    }
    int sm = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            dph[i][x]++;
            dpv[j][x]++;
            if(i==j){
                sm+=x;
            }
        }
    }
    int rh = 0;
    int rv = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(dph[i][j]>1){
                rh++;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            if(dpv[i][j]>1){
                rv++;
                break;
            }
        }
    }
    cout<<sm<<' '<<rh<<' '<<rv<<'\n';
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
