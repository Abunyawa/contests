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

/*
1 2 3 4 5 6
 1 1 1 1 1 


(a[i]-a[i+1]+1) = NOD-1
(a[i]-a[i+2]+2) = NOD-2


*/


void solve() {
    int n;
    scanf("%d",&n);
    vl a(n);
    ll sm = 0;
    ll sm1 = 0;
    ll sm2 = 0;
    ll mx =0;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        sm+=a[i]+i+1;
        sm1 += i+1;
        sm2 += a[i];
        mx = max(mx, a[i]+n);
    }


    vl divs;
    ll fx = sqrt(sm);
    for(ll i=2;i<=sqrt(sm);i++){
        if(sm%i==0){
            divs.pb(i);
        }

        while(sm%i==0){
            sm/=i;
        }
    }

    if(sm>1){
        divs.pb(sm);
    }
    ll ans = -1;
    for(int kk=0;kk<divs.size();kk++){
        ll d = divs[kk];

        vi left(min(1LL*n+1,d),n/d);

        for(int i=1;i<=min(1LL*n,n%d);i++){
            left[i]++;
        }
        bool good = true;
        for(int i=0;i<n;i++){
            ll need = (d-a[i]%d)%d;
            if(need>n){
                good=false;
                break;
            }
            if(left[need]>0){
                left[need]--;
            }else{
                good = false;
                break;
            }
        }

        if(good){
            ans = d;
            break;
        }
    }

    
    if(ans==-1){
        no();
    }else{
        ll d = ans;
        yes();
        vl nxt(min(1LL*n+1,d));
        vl answer(n+1);
        for(int i=1;i<=min(1LL*n,d);i++){
            nxt[i%d] = i;
        }

       for(int i=0;i<n;i++){
            ll need = (d-a[i]%d)%d;

            answer[nxt[need]]=a[i];
            nxt[need]+=d;
        } 

        for(int i=1;i<=n;i++){
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
        //test();
    }

    return 0;
}

