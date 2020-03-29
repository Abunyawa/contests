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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int n,m;
vi g[100100];
int col[100100];
bool used[100100];

void solve(){
    int n;
    cin>>n;
    if(n<=3){
        no();
    }else{
        if(n%2==0){
            yes();
            cout<<"1 * 2 = 2"<<endl;
            cout<<"2 * 3 = 6"<<endl;
            cout<<"6 * 4 = 24"<<endl;
            for(int i=5;i<n;i+=2){
                cout<<i+1<<" - "<<i<<" = 1"<<endl;
                cout<<"24 * 1 = 24"<<endl;
            }
        }else{
            yes();
            cout<<"4 * 5 = 20"<<endl;
            cout<<"20 + 3 = 23"<<endl;
            cout<<"2 - 1 = 1"<<endl;
            cout<<"23 + 1 = 24"<<endl;
            for(int i=6;i<n;i+=2){
                cout<<i+1<<" - "<<i<<" = 1"<<endl;
                cout<<"24 * 1 = 24"<<endl;
            }
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
