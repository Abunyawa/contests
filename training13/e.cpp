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
bool was[26];
void solve(){
    int n,k;
    cin>>n>>k;
    vector<char> a;
    char let[n];
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        let[i] = x;
        if(!was[x-'a']){
            a.pb(x);
            was[x-'a']=true;
        }
    }
    sort(all(a));
    vector<int> rev(26,-1);
    for(int i=0;i<a.size();i++){
        rev[a[i]-'a']  = i;
    }
    if(k>n){
        for(int i=0;i<n;i++){
            cout<<let[i];
        }
        for(int i=n;i<k;i++){
            cout<<a[0];
        }
        cout<<endl;
    }else{
        int cur[min(n,k)+1];
        for(int i=1;i<=min(n,k);i++){
            cur[i] = rev[let[i-1]-'a'];
        }
        cur[0] = -1;
        cur[min(n,k)]++;
        for(int i = min(n,k);i>0;i--){
            cur[i-1] += cur[i]/a.size();
            cur[i]%=a.size();
        }
        if(cur[0]==0){
            for(int i=0;i<=min(n,k);i++){
                cout<<a[cur[i]];
            }
            cout<<endl;
        }else{
            for(int i=1;i<=min(n,k);i++){
                cout<<a[cur[i]];
            }
            cout<<endl;
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
