#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    ll q;
    cin>>q;
    ll ans = q;
    vector<int> num;
    while(q!=0){
        num.pb(q%3);
        q/=3;
    }
  
    int start = 0;
    for(int i = 0;i<num.size();i++){
        if(i!=num.size()-1){
            num[i+1]+=num[i]/3;
        }else{
            if(num[i]/3!=0)
                num.pb(num[i]/3);
        }
        num[i]%=3;
        if(num[i]==2){
            start = i+1;
            if(i!=num.size()-1){
                num[i+1]++;
            }else{
                num.pb(1);
            }
        }
    }
    ans = 0;

    for(int i=start;i<num.size();i++){
        ans+=pow(3,i)*num[i];
    }

    cout<<ans<<'\n';

}

int main(){
    /*
    freopen("trains.in","r",stdin);
    freopen("trains.out","w",stdout);
    */
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
