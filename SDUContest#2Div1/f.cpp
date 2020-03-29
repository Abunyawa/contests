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
int ctr[5001];

int main(){
    ll n,k;
    cin>>n>>k;
    ll have = __builtin_popcountll(n);
    if(have>k || k>n){
        no();
    }else{
        vector<int> a;
        for(int i=0;(1<<i)<=n;i++){
            if((1<<i)&n)
                a.pb(1<<i);
        }
        int ptr = 0;
        while(a.size()!=k){
            while(a[ptr]<=1){
                ptr++;
            }
            while(a[ptr]>1 && a.size()<k){
                a.pb(a[ptr]/2);
                a[ptr]/=2;
            }
        }
        sort(all(a));
        yes();

        for(int i=0;i<a.size();i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}