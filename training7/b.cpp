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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll x;
    for(int i = 0;i<n;i++){
        cin>>x;
        if(x==1){
            no();
            continue;
        }
        if((ll)sqrt(x)*(ll)sqrt(x)==x){
            if(is_prime(sqrt(x))){
                yes();
            }else{
                no();
            }
        }else{
            no();
        }
    }


    return 0;
}