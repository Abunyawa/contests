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
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int> s;
    int piv = -1;
    for(int i=0;i<n;i++){
        if(s.find(a[i])!=s.end()){
            piv = i;
            break;
        }
        s.insert(a[i]);
    }
    if(piv==-1){
        cout<<0<<'\n';
    }else{
        vector<bool> l(n,false);
        vector<int> la;
        int max = 0;
        for(int i=0;i<piv;i++){
            if(a[i]>max){
                max = a[i];
            }
            la.pb(a[i]);
            if(la.size()==max){
                l[i] = true;
            }
        }
        s.clear();
        for(int i=n-1;i>=0;i--){
            if(s.find(a[i])!=s.end()){
                piv = i;
                break;
            }
            s.insert(a[i]);
        }
        vector<bool> r(n,false);
        vector<int> ra;
        max = 0;
        for(int i=n-1;i>piv;i--){
            if(a[i]>max){
                max = a[i];
            }
            ra.pb(a[i]);
            if(ra.size()==max){
                r[i] = true;
            }
        }
        vector<pii> ans;
        for(int i=0;i<n-1;i++){
            if(r[i+1]&&l[i]){
                ans.pb(mp(i+1,n-i-1));
            }
        }
        cout<<ans.size()<<'\n';
        for(auto e: ans){
            cout<<e.F<<' '<<e.S<<'\n';
        }
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
