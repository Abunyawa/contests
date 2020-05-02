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

void solve(){
    int u;
    cin>>u;
    map<char,int> m; 
    set<char> let;
    for(int i=0;i<10000;i++){
        ll q;
        cin>>q;
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            let.insert(s[j]);
        }
        m[s[0]]++;
    }
    
    vector<pair<int,char>> ans;
    for(auto i = let.begin();i!=let.end();i++){
        ans.pb({m[*i],*i});
    }
    sort(all(ans));
    cout<<ans[0].S;
    for(int i=9;i>=1;i--){
        cout<<ans[i].S;
    }
    cout<<'\n';
}

int main(){
    abu;
    said;
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int t = 1;
    cin>>t;
    for(int i = 1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}
