#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll> b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        bool flag = true;
        for(int i=0;i<n-1;i++){
            if(b[i]>=b[i+1]){
                m+=b[i]-b[i+1];
                b[i] = b[i+1];
                m+=min(b[i],k);
            }else{
                ll need = max(b[i+1]-k,0ll) - b[i];
                m-=need;
                if(m<0){
                    flag = false;
                }
            }
        }
        if(flag){
            yes();
        }else{
            no();
        }
    }

    return 0;
}