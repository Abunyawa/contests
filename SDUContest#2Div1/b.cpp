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
    int n,m,h;
    cin>>n>>m>>h;
    int city[n][m];
    for(int i=0;i<m;i++){
        int p;
        cin>>p;
        for(int j=0;j<n;j++){
            city[j][i] = p;
        }
    }
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        for(int j=0;j<m;j++){
            city[i][j] = min(p,city[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int p;
            cin>>p;
            if(!p){
                city[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<city[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}