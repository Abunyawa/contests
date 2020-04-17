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

int binp(vl &a,int n,ll x){
    int l = n,r = a.size()-1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(a[mid]>=x){
            r = mid;
        }else{
            l = mid;
        }
    }

    if(a[r]<=x)
        return r;
    if(a[l]<=x)
        return l;
    return l;
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    if((a+b+c)%2==1){
        cout<<"Impossible\n";
        return;
    }else{
        for(int x = 0;x<=min(a,b);x++){
            int y = b-x;
            int z = a-x;
            if(x+y+z==(a+b+c)/2){
                cout<<x<<' '<<y<<' '<<z<<'\n';
                return;
            }
        }
    }
    cout<<"Impossible\n";
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
