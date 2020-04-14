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
abcccabc
*/
void solve(){
    char d[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>d[i][j];
        }
    }
    d[0][0] = d[0][1];
    d[1][3] = d[1][4];
    d[2][6] = d[2][7];
    d[3][1] = d[3][2];
    d[4][4] = d[4][2];
    d[5][7] = d[5][8];
    d[6][2] = d[6][1];
    d[7][5] = d[7][4];
    d[8][8] = d[8][7];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<d[i][j];
        }
        cout<<'\n';
    }
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
