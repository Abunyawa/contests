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

char mb[] = {'(',')'};



void solve() {
    int n,m;
    cin>>n>>m;
    vl ap;
    vl bp;
    vl an;
    vl bn;
    //debug("++++++++++++++++++");
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x>0){
            ap.pb(x);
        }else{
            an.pb(-x);
        }
    }

    for(int j=0;j<m;j++){
        ll x;
        cin>>x;
        if(x>0){
            bp.pb(x);
        }else{
            bn.pb(-x);
        }
    }

    sort(all(ap));
    sort(all(an));
    sort(all(bp));
    sort(all(bn));

    int ptr1=0;
    int ptr2=0;
    int curP = 0;
    int ansR = 0;
    vector<int> used(bp.size(),0);
    vi ptr(bp.size(),ap.size()-1);

    while(ptr1<ap.size() && ptr2<bp.size()){
        while(ptr2<bp.size() && ap[ptr1]>bp[ptr2]){
            ptr[ptr2] = ptr1;
            ptr2++;
        }

        if(ap[ptr1]==bp[ptr2]){
            used[ptr2]=1;
            curP++;
        }

        ptr1++;
    }

    vi sum(bp.size()+1);
    sum[0] = 0;
    for(int i=1;i<=bp.size();i++){
        sum[i] = sum[i-1] + used[i-1];
    }  
    
    
    for(int i=0;i<bp.size();i++){
        int bef = 0;
        if(ap[ptr[i]]<=bp[i]){
            bef = ptr[i]+1;
        }else{
            bef = ptr[i];
        }
        int l = 0;
        int r = i;
        int target = bp[i]-bef+1;
        while(l<r){
            int m = (l+r)/2;
            if(bp[m]<target){
                
                l = m+1;
            }else{
                if(r==m){
                    break;
                }
                r = m;
            }
        }
        
        if(bp[r]<target){
            r++;
        }
        if(r>i){
            //debug(i);
            //debug("overflow");
            continue;
        }
        if(bef==0){
            continue;
        }
        int loc = i-r +1+ curP - sum[i+1];
        
        ansR = max(ansR,loc);
    }


    ptr1=0;
    ptr2=0;
    int curN = 0;
    int ansL = 0;
    vector<int> used1(bn.size(),0);
    vi ptr0(bn.size(),an.size()-1);

    while(ptr1<an.size() && ptr2<bn.size()){
        while(ptr2<bn.size() && an[ptr1]>bn[ptr2]){
            ptr0[ptr2] = ptr1;
            ptr2++;
        }

        if(an[ptr1]==bn[ptr2]){
            used1[ptr2]=1;
            curN++;
        }

        ptr1++;
    }

    vi sum1(bn.size()+1);
    sum1[0] = 0;
    for(int i=1;i<=bn.size();i++){
        sum1[i] = sum1[i-1] + used1[i-1];
    }

    for(int i=0;i<bn.size();i++){
        int bef = 0;
        if(an[ptr[i]]<=bn[i]){
            bef = ptr0[i]+1;
        }else{
            bef = ptr0[i];

        }
        int l = 0;
        int r = i;
        int target = bn[i]-bef+1;
        while(l<r){
            int m = (l+r)/2;
            if(bn[m]<target){
                
                l = m+1;
            }else{
                if(r==m){
                    break;
                }
                r = m;
            }
        }
        if(bn[r]<target){
            r++;
        }
        if(r>i){
            continue;
        }
        if(bef==0){
            continue;
        }

        
        int loc = i-r +1+ curN - sum1[i+1];
        /*
        debug(curN);
        debug(loc);
        debug(i);
        debug(r);
        debug(bef);
        debug(bn[i]);
        debug(sum1[i+1]);
        debug(target);
        */
        ansL = max(ansL,loc);
    }
    cout<<ansL+ansR<<'\n';
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

