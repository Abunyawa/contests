// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

int conv(int n){
    if(n==0){
        return 0;
    }if(n==1){
        return 1;
    }else if(n==2){
        return 5;
    }else if(n==5){
        return 2;
    }else if(n==8){
        return 8;
    }else{
        return -1;
    }
}


bool isOk(int hh, int mm, int curh, int curm){
    int newH = 0;
    if(conv(curm%10)!=-1){
        newH+=10*conv(curm%10);
    }else{
        return false;
    }
    if(conv(curm/10)!=-1){
        newH+=conv(curm/10);
    }else{
        return false;
    }
    int newM = 0;

    if(conv(curh%10)!=-1){
        newM+=10*conv(curh%10);
    }else{
        return false;
    }
    if(conv(curh/10)!=-1){
        newM+=conv(curh/10);
    }else{
        return false;
    }

    return newH<hh && newM<mm;
}

void solve() {
    int h,m;
    cin>>h>>m;
    string s;
    cin>>s;
    int curH = (s[0]-'0')*10+s[1]-'0';
    int curM = (s[3]-'0')*10+s[4]-'0';
    while(!isOk(h,m,curH,curM)){
        curM++;
        curH+=curM/m;
        curM%=m;
        if(curH>=h){
            curH=0;
        }
    }
    printf("%02d:%02d\n",curH,curM);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

