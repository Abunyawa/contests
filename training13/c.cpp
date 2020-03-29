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
ll ct(ll a){
    ll sm = 0;
    while(a!=0){
        int cr = a%10;
        a/=10;
        if(cr==0){
            sm+=6;
        }else if(cr==1){
            sm+=2;
        }else if(cr == 2 || cr==3 || cr == 5){
            sm+=5;
        }else if(cr == 4){
            sm+=4;
        }else if(cr==6 || cr == 9){
            sm+=6;
        }else if(cr==7){
            sm+=3;
        }else{
            sm+=7;
        }
    }
    return sm;
}
void solve(){
    ll a,b;
    cin>>a>>b;
    ll sm = 0;
    for(ll i=a;i<=b;i++){
        sm+=ct(i);
    }
    cout<<sm<<endl;
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
