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
/*
0000000
1000000
1110000
0000000


*/
void solve(){
    int n;
    cin>>n;
    if(n%4==0){
        for(int i=0;i<n;i+=4){
            cout<<2<<' '<<i+2<<'\n';
            cout<<1<<' '<<i+2<<'\n';
            cout<<2<<' '<<i+4<<'\n';
            cout<<1<<' '<<i+4<<'\n';
        }
    }else if(n/2%2==1 && n%2==1){
        for(int i=0;i<n;i++){
            if(i%2==0)
                cout<<1<<' '<<1+i<<'\n';
            else{
                cout<<n-i<<' '<<n<<'\n';
            }
        }
    }else{
        cout<<-1<<'\n';
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
