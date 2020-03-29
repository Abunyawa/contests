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
    int n;
    cin>>n;
    int l[n],u[n],s[n],d[n];
    for(int i=0;i<n;i++){
        cin>>l[i]>>u[i]>>s[i]>>d[i];
    }
    ll t = 1;
    int pos = 0;
    for(int i=0;i<n;i++){
        int curPos = s[i] + d[i]*t;
        if(curPos%(u[i]-l[i]+1)%2==1){
            d[i]*=-1;
        }
        curPos = l[i] + curPos%(u[i]-l[i]+1);
        if(curPos == pos){
            t+=2;
        }else{
            if(pos>curPos){
                if(d[i]==1){
                    t+=
                }
            }
        }
    }
    return 0;
}