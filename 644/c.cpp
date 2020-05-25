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
    int odd=0,even=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            even++;
        }else{
            odd++;
        }
    }
    if(odd%2==0 && even%2==0){
        yes();
        return;
    }else{
        sort(all(a));
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i]==1){
                yes();
                return;
            }
        }
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
