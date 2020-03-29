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
    ll x = 0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int i=0;i<3;i++){
            if(s[i]=='+'){
                x++;
                break;
            }else if(s[i]=='-'){
                x--;
                break;
            }
        }
    }
    cout<<x<<'\n';
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
