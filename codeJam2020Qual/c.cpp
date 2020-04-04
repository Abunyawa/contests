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
    vector<pair<pii,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].F.F>>a[i].F.S;
        a[i].S = i;
    }
    sort(all(a));
    vector<pair<pii,int>> c;
    vector<pair<pii,int>> j;
    for(int i=0;i<n;i++){
        if(c.empty()){
            c.pb(a[i]);
        }else{
            if(a[i].F.F < c.back().F.S){
                if(j.empty()){
                    j.pb(a[i]);
                }else{
                    if(a[i].F.F < j.back().F.S){
                        cout<<"IMPOSSIBLE\n";
                        return;
                    }else{
                        j.pb(a[i]);
                    }
                }
            }else{
                c.pb(a[i]);
            }
        }
    }
    vector<char> ans(n);
    for(int i=0;i<c.size();i++){
        ans[c[i].S] = 'C';
    }
    for(int i=0;i<j.size();i++){
        ans[j[i].S] = 'J';
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    cout<<'\n';
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
