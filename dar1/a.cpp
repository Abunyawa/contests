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
    int pr = 0;
    int cr = 0;
    int p;
    int c;
    bool flag = true;
    for(int i=0;i<n;i++){
        cin>>p>>c;
        if(p-pr<0 || c-cr<0){
            flag = false;
        }else if(c-cr>p-pr){
            flag = false;
        }
        pr = p;
        cr = c;
    }
    if(flag){
        yes();
    }else{
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
