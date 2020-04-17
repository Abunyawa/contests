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

bool used[10][10];

void solve(){
    int col[9][9];
    int cur = 1;
    for(int i=8;i>=1;i--){
        for(int j=1;j<9;j++){
            col[i][j] = cur;
            cur^=1;
        }
        cur^=1;
    }
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    if(r1==r2 && c1==c2){
        cout<<0<<' '<<0<<' '<<0<<'\n';
    }else{
        if(r1==r2 || c1==c2){
            cout<<1<<' ';
        }else{
            cout<<2<<' ';
        }
        int b1 = 1;
        if(col[r1][c1] == col[r2][c2]){
            if(r1-c1==r2-c2 || r1+c1 == r2+c2){
                cout<<1<<' ';
            }else{
                cout<<2<<' ';
            }
        }else{
            cout<<0<<' ';
        }
        cout<<max(abs(r1-r2),abs(c1-c2))<<'\n';
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
