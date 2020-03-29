#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int ctr[110];
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll prev;
    cin>>prev;
    vector<int> s;
    for(int i=0;i<n-1;i++){
        ll p;
        cin>>p;
        s.pb(p-prev);
        prev = p;
    }
    ll ans = 0;
    sort(all(s));
    if(k>=n){
        ans+=n;
    }else{
        ll need = n-k;
        ans+=n-need;
        for(int i=0;i<need;i++){
            ans+=s[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}