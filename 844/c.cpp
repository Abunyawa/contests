// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rall(x) (x).rbegin(), (x).rend()
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



void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    vi ctr(26,0);

    for(int i=0;i<n;i++){
        ctr[s[i]-'a']++;
    }
    pair<int,int> ans = {1,n};
    for(int lets = 1;lets<=26;lets++){
        if(n%lets!=0){
            continue;
        }

        int bad = 0;
        int free = 0;
        int need = n/lets;
        vi sm;
        int left = 0;
        for(int i=0;i<26;i++){
            if(ctr[i]>need){
                free += ctr[i]-need;
                bad+= ctr[i]-need;
            }else if(ctr[i]<need){
                sm.pb(ctr[i]);
                left+=ctr[i];
            }
        }

        sort(rall(sm));

        int fx = (left+free)/need;
        
        for(int i=fx;i<sm.size();i++){
            bad+=sm[i];
        }

        if(bad<=ans.se){
            ans = {lets,bad};
        }
    }


    int need = n/ans.fi;

    //cout<<need<<'\n';
    int free = 0;
    int left=  0;
    vector<pii> sm;
    for(int i=0;i<26;i++){
        if(ctr[i]>need){
            free += ctr[i]-need;
            ctr[i] = need;
        }else if(ctr[i]<need){
            sm.pb({ctr[i], i});
            left+=ctr[i];
        }
    }

    int fx = (left+free)/need;

    sort(rall(sm));

    for(int i=0;i<fx;i++){
        ctr[sm[i].se] = need; 
    }

    for(int i=fx;i<sm.size();i++){
        ctr[sm[i].se] = 0;
    }



    vi ctr2(26,0);

    for(int i=0;i<n;i++){
        ctr2[s[i]-'a']++;
    }


    for(int i=0;i<n;i++){
        if(ctr2[s[i]-'a']==ctr[s[i]-'a']){
            continue;
        }

        if(ctr2[s[i]-'a']>ctr[s[i]-'a']){
            for(int j=0;j<26;j++){
                if(ctr2[j]<ctr[j]){
                    ctr2[j]++;
                    ctr2[s[i]-'a']--;
                    s[i] = 'a'+j;
                    break;
                }
            }
        }    
    }

    cout<<ans.se<<'\n';
    cout<<s<<'\n';
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

