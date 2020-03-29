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
double smAll(vector<int> &a,int l, int r){
    double sm = 0;
    for(int i=l;i<=r;i++){
        sm+=a[i];
    }
    return sm;
}

int main(){
    int n,m;
    cin>>n>>m;
    int  g[n+1][n+1];
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        cin>>g[l][r];
    }
    int p5,q5,p6,q6;
    cin>>p5>>q5>>p6>>q6;
    const int INF = 1000000000; 

    vector<bool> used (n);
    vector<int> min_e (n, INF), sel_e (n, -1);
    min_e[0] = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;

        used[v] = true;
        if (sel_e[v] != -1)
            cout << v << " " << sel_e[v] << endl;
    
        for (int to=0; to<n; ++to)
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    return 0;
}