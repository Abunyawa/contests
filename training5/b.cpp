#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
using namespace std;


void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<char> a(n); 
    int ctr = 0;
    int l = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='0'){
            if(ctr>l){
                l = ctr;
            }
            ctr=0;
        }else{
            ctr++;
        }
    }

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(x<=l){
            no();
        }else{
            yes();
        }
    }

    return 0;
}