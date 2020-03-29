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
    int n;
    cin>>n;
    map<ll,ll> a;
    ll min = 9999999999;
    vl b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        a[b[i]]+=a[b[i]]+1;
        if(b[i]<min){
            min=b[i];
        }
    }
    if(a[min]==1){
        for(int i=0;i<n;i++){
            if(b[i]==min){
                cout<<i+1<<'\n';
                break;
            }
        }
    }else{
        cout<<"Still Rozdil\n";
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
