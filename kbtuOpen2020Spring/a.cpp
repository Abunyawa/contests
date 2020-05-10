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
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double xa=x1,ya=y1,xb=x2,yb=y2;
    vector<double> ans;
    int n;
    cin>>n;
    vector<pair<double,double>> v;
    for(int i=0;i<n;i++){
        double y,w;
        cin>>y>>w;
        v.pb({y,w});
        yb-=w;
    }
    double dist = sqrt((yb-ya)*(yb-ya)+(xb-xa)*(xb-xa));
    double cur = 0;
    for(int i=0;i<n;i++){
        dist+=v[i].S;
        double y = v[i].F-cur;
        ans.pb((y-ya)*(xb-xa)/(yb-ya)+xa);
        cur+=v[i].S;
    }

    printf("%0.10f\n",dist);
    for(auto e: ans){
        printf("%0.10f\n",e);
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
