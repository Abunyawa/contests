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
    if((n%3==0 && n>3) || n==1 || n==0){
        cout<<-1<<'\n';
    }else{
        if(n==2){
            cout<<2<<'\n';
        }
        if(n==3){
            cout<<3<<'\n';
        }
        if(n==4){
            cout<<2011<<'\n';
        }
        if(n==5){
            cout<<1031<<'\n';
        }
        if(n==7){
            cout<<1123<<'\n';
        }
        if(n==8){
            cout<<251<<'\n';
        }
        if(n==10){
            cout<<73<<'\n';
        }
    }

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
