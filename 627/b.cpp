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
    vi a(n);
    bool flag = false;
    vector<int> is(n+10,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(is[a[i]]){
            if(a[i-1]!=a[i]){
                flag = true;
            }else{
                if(is[a[i]]>2){
                    flag = true;
                }
            }
        }
        is[a[i]]++;
    }

    if(flag)
        yes();
    else{
        no();
    }
    
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}