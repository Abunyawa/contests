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
    string s;
    cin>>s;
    map<pair<pii,pii>,bool> mp;
    int xc=0,yc=0;
    int xd = 0,yd=0;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        xd = xc;
        yd = yc;
        if(s[i]=='N'){
            xd = xc+1;
        }else if(s[i]=='S'){
            xd = xc-1;
        }else if(s[i]=='W'){
            yd = yc -1; 
        }else{
            yd = yc+1;
        }
        if(mp[{{xc,yc},{xd,yd}}]==true || mp[{{xd,yd},{xc,yc}}]==true){
            ans++;
        }else{
            mp[{{xc,yc},{xd,yd}}]=true;
            ans+=5;
        }
        xc = xd;
        yc = yd;
    }
    cout<<ans<<'\n';
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
