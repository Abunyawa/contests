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
const ll M = 10e9+7;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
bool is_prime(ll x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    abu;
    said;
    ll n,a,b;
    cin>>n>>a>>b;
    ll s=a*b;
    ll mn = min(a,b);
    ll mx = max(a,b);
    ll need = 6*n;
    
    if(need <= s){
        cout<<s<<endl;
        cout<<a<<' '<<b<<endl;
    }else{
        ll curAns = 999999999999999999;
        ll ansa;
        ll ansb;
        if(a<b){
            for(ll i = a;i<=sqrt(need)+1;i++){
                ll tb = (need+i-1)/i;
                if(i*tb<curAns && tb>=b){
                    ansa=i;
                    ansb=tb;
                    curAns = i*tb;
                }
            }
        }else{
            for(ll i = b;i<=sqrt(need)+1;i++){
                ll ta = (need+i-1)/i;
                if(i*ta<curAns && ta>=a){
                    ansa=ta;
                    ansb=i;
                    curAns = i*ta;
                }
            }
        }
        cout<<curAns<<endl;
        cout<<ansa<<' '<<ansb<<endl;
    }
    return 0;
}