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

int ask(string s){
    cout<<"? "<<s<<endl;
    int n;
    cin>>n;
    return n;

}
string cur = "";
int st = 0;
int n;



void find(bool last){
    if(!last){
        for(int i=st;i<=cur.length();i++){
            string toAsk="";
            if(i==0){
                toAsk = "1"+cur;
            }else if(i==cur.length()){
                toAsk = cur+"1";
            }else{
                for(int j=0;j<i;j++){
                    toAsk+=cur[j];
                }
                toAsk+="1";
                for(int j=i;j<cur.length();j++){
                    toAsk+=cur[j];
                }
            }
            int res = ask(toAsk);
            if(res==toAsk.length()){
                cur = toAsk;
                st = i+1;
                return;
            }
        }
    }else{
        for(int i=st;i<cur.length();i++){
            string toAsk="";
            if(i==0){
                toAsk = "1"+cur;
            }else if(i==cur.length()){
                toAsk = cur+"1";
            }else{
                for(int j=0;j<i;j++){
                    toAsk+=cur[j];
                }
                toAsk+="1";
                for(int j=i;j<cur.length();j++){
                    toAsk+=cur[j];
                }
            }
            int res = ask(toAsk);
            if(res==toAsk.length()){
                cur = toAsk;
                st = i+1;
                return;
            }
        }
        cur = cur+"1";
    }
}

void solve() {
    cin>>n;
    int numZ = 0;
    string asd = "";
    for(int i=0;i<n;i++){
        asd+="0";
    }
    cout<<"? "<<asd<<endl;
    cin>>numZ;
    for(int  i = 0;i<numZ;i++){
        cur+="0";
    }
    for(int i=0;i<n-numZ;i++){
        if(i==n-numZ-1){
            find(true);
        }else{
            find(false);
        }
    }
    cout<<"! "<<cur<<endl;
}



int main() {
    int tt = 1;
    
    while (tt--) {
        solve();
    }
    

    
    return 0;
}

