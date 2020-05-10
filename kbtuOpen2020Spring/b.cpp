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
int pos[200100];

vector<int> g[200100];

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> p;
    for(int i=0;i<n;i++){
        /*
        for(auto e: p){
            cout<<e<<' ';
        }
        cout<<endl;*/
        if(p.empty()){
            p.pb(a[i]);
        }else{
            if(a[i]<p.back()){
                p.pb(a[i]);            
            }else{
                int l = 0;
                int r = p.size()-1;
                while(l<r){
                    int mid = (l+r)/2;
                    if(a[i]<p[mid]){
                        l=mid+1;
                    }else{
                        r = mid;
                    }
                }
                if(p[min(l,r)]<a[i])
                    p[min(l,r)] = a[i];
                else{
                    p[max(l,r)] = a[i];
                }
            }

        }
    }
    cout<<p.size()<<'\n';



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
