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
    string s;
    cin>>s;
    vector<char> ans;
    int prev = 0;
    for(int i=0;i<s.length();i++){
        int cur = s[i]-'0';
        if(cur-prev>0){
            for(int j=0;j<cur-prev;j++){
                ans.pb('(');
            }
        }else if(cur-prev<0){
            for(int j=0;j<prev-cur;j++){
                ans.pb(')');
            }
        }
        ans.pb(s[i]);
        prev = cur;
    }
    for(int i=0;i<prev;i++){
        ans.pb(')');
    }
    for(int i =0;i<ans.size();i++){
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
