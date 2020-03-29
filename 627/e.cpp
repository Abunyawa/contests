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
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
/*
4 8 2  6  2
4 5 4  1  3
0 3 -2 5 -1
-2 -1 0 3 5
\                
*/

void solve(){
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    vi a(n);
    vi d(n);
    vector<bool> is(n,false);
    int cr = 0;
    int ha = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int cp = cr%h+a[i];
        cr+=a[i];
        d[i] = cp-l;
        a[i] = cr;
    }
    int rat = r-l;
    ll ans = 0;
    int tod = 0;

    for(int i=0;i<n;i++){
        tod;
        if(d[i]>=0){
            if(d[i]<=rat){
                ans++;
                tod = i+1;
            }else{
                if(d[i]-rat<=i-tod+1){
                    int ctr = 1;
                    for(int j=i-ctr-1;j<n;j++){
                        d[j]-=ctr;
                        if(ctr<d[j]-rat)
                            ctr++;
                    }
                    ans++;
                    tod = i+1;
                }
            }
        }
    }
    /*
    for(auto e: d){
        cout<<e<<' ';
    }
    cout<<endl;
    */
    cout<<ans<<endl;
}

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}