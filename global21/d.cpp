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

void solve() {
    int n;
    cin>>n;

    vi a(n);
    vi p(n+1);

    for(int i=0;i<n;i++){
        cin>>a[i];
        p[a[i]] = i;
    }
    stack<int> st;
    vi mx(n);
    vi mn(n);

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(i);
            mx[i] = i;
        }else{
            while(!st.empty() && a[st.top()]<a[i]){
                st.pop();
            }

            if(st.empty()){
                mx[i] = i;
            }else{
                mx[i] = st.top();
            }

            st.push(i);
        }
    }

    while(!st.empty()){
        st.pop();
    }

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(i);
            mn[i] = i;
        }else{
            while(!st.empty() && a[st.top()]>a[i]){
                st.pop();
            }

            if(st.empty()){
                mn[i] = i;
            }else{
                mn[i] = st.top();
            }

            st.push(i);
        }
    }

    for(int i=0;i<n;i++){
        cout<<mx[i]<<' ';
    }
    cout<<'\n';

    for(int i=0;i<n;i++){
        cout<<mn[i]<<' ';
    }
    cout<<'\n';


    int ctr = 0;
    for(int i =0;i<n-1;){
        int mxN = mx[i];
        int mnN = mn[i];
        ctr++;
        if(mxN==mx[mxN]){
            i = mnN;
            continue;
        }

        if(mnN==mn[mnN]){
            i = mxN;
            continue;
        }

        if(mxN<mnN){
            while(mx[mxN]<mnN){
                
                mxN = mx[mxN];
                if(mxN==mx[mxN]){
                    break;
                }
            }
        }else{
            while(mn[mnN]<mxN){
                mnN = mn[mnN];
                if(mnN==mn[mnN]){
                    break;
                }
            }
        }
        
        i = min(mxN, mnN);
        
    }

    cout<<ctr<<'\n';
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

