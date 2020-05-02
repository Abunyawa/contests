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
    int x,y;
    cin>>x>>y;
    string s;
    cin>>s;
    vector<pii> cords;
    int curX = x;
    int curY = y;
    for(int i=0;i<s.length();i++){
        if(s[i]=='S'){
            curY--;
        }else if(s[i]=='N'){
            curY++;
        }else if(s[i]=='W'){
            curX--;
        }else{
            curX++;
        }
        cords.pb({curX,curY});
    }
    ll distA = 999999999999999;
    bool flag = false;
    for(int i=0;i<cords.size();i++){
        int dist1 = i+1;
        int dist2 = abs(cords[i].F-0)+abs(cords[i].S-0);
        if(dist1>=dist2){
            flag =true;
            if(dist1<distA){
                distA = dist1;
            }
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<distA<<'\n';
    }

}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    for(int i = 1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}
