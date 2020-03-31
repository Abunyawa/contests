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
    int n,k;
    cin>>n>>k;
    vector<map<char,int>> ct(k);
    vector<int> mx(k,0);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        ct[i%k][c]++;
        if(ct[i%k][c]>mx[i%k]){
            mx[i%k]=ct[i%k][c];
        }
    }
    int l = 0;
    int r = k-1;
    ll ans = 0;
    while(l<r){
        for(auto i ='a';i<='z';i++){
            ct[l][i]+=ct[r][i];
            if(ct[l][i]>mx[l]){
                mx[l] = ct[l][i];
            }
        }
        l++;
        r--;
    }
    if(k%2==0){
        for(int i=0;i<k/2;i++)
            ans+=2*n/k-mx[i];
        cout<<ans<<'\n';
    }else{
        for(int i=0;i<=k/2;i++){
            if(i<k/2){
                ans+=2*n/k-mx[i];
            }else{
                ans+=n/k-mx[i];
            }
        }
        cout<<ans<<'\n';
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
