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
    int l=0,r=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            l++;
        }else{
            r++;
        }
    }
    int cl=0,cr=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cl++;
        }else{
            cr++;
        }
        if(cr==r || cl == l){
            cout<<i+1<<'\n';
            return;
        }
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
