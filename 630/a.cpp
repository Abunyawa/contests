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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ix,iy,x1,y1,x2,y2;
    cin>>ix>>iy>>x1>>y1>>x2>>y2;
    if(x2-x1==0 && (a!=0 || b!=0)){
        no();
        return;
    }
    if(y2-y1==0 && (c!=0 || d!=0)){
        no();
        return;
    }
    if(iy+d-c<=y2 && iy+d-c>=y1 && ix+b-a>=x1 && ix+b-a<=x2){
        yes();
    }else{
        no();
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
