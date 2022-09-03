// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    int ctr[4];
    for(int i=0;i<4;i++){
        cin>>ctr[i];
    }

    string s;
    cin>>s;
    int n = s.length(); 
    int a = 0;
    int b = 0;
    vector<pii> bl;
    int cur = 1;
    for(int i=1;i<n;i++){

        if(s[i]==s[i-1]){
            cur++;
        }else{
            if(s[i-1]=='A'){
                a+=cur;
            }else{
                b+=cur;
            }
            bl.pb({cur,s[i-1]-'A'});
            cur = 1;
        }
    }
    if(s[n-1]=='A'){
        a+=cur;
    }else{
        b+=cur;
    }
    bl.pb({cur,s[n-1]-'A'});


    if((a-ctr[2]-ctr[3])!=ctr[0] || (b-ctr[2]-ctr[3])!=ctr[1]){
        no();
        return;
    }

    int ab = 0;
    int ba = 0;
    int ch = 0;
    
    bl[0].fi = 1;
    bl[bl.size()-1].fi = 2;


    vector<pii> st;
    for(int i=0;i<bl.size();i++){
        int cur = i+1;
        while(cur<bl.size() && bl[cur].fi==1){
            cur++;
        }
        if(cur>=bl.size()){
            cur--;
        }

        if(cur-i+1>2){
            st.pb({bl[i].se, cur-i+1});
        }else{
            if(bl[i].se==0){
                ab++;
            }else{
                ba++;
            }
        }
        if(cur==bl.size()-1){
            break;
        }
        i = cur-1;
        
    }

    sort(rall(st));


    if(ab>=ctr[2] && ba>=ctr[3]){
        a -= ctr[2]+ctr[3];
        b -= ctr[2]+ctr[3];
        if(a==ctr[0] && b==ctr[1]){
            yes();
            return;
        }else{
            no();
            return;
        }
    }else{
        int needAB = max(ctr[2]-ab, 0);
        int needBA = max(ctr[3]-ba, 0);

        int canAB = 0;
        int canBA = 0;

        for(int i=0;i<st.size();i++){
            if(st[i].fi==0){
                canAB += st[i].se/2;
            }else{
                canBA += st[i].se/2;
            }
        }


        if(canAB>=needAB && canBA>=needBA){
            a -= ctr[2]+ctr[3];
            b -= ctr[2]+ctr[3];
            if(a==ctr[0] && b==ctr[1]){
                yes();
                return;
            }else{
                no();
                return;
            }
        }else if(canAB<needAB && canBA<needBA){
            no();
            return;
        }else{
            if(canAB>=needAB){
                int free = canAB-needAB;

                for(int i=0;i<st.size();i++){
                    if(free==0){
                        break;
                    }
                    if(st[i].fi==0 && st[i].se%2==1){
                        int have = st[i].se/2;

                        if(free>=have){
                            free-=have;
                            canBA += have;
                        }else{
                            canBA += free;
                            free = 0;
                        }
                    }
                }

                if(free>0){
                    for(int i=0;i<st.size();i++){
                        if(free==0){
                            break;
                        }
                        if(st[i].fi==0 && st[i].se%2==0){
                            int have = (st[i].se-1)/2;

                            if(free>=have+1){
                                free-=have+1;
                                canBA += have;
                            }else{
                                canBA += free-1;
                                free = 0;
                            }
                        }
                    }
                }

                if(canBA>=needBA){
                    a -= ctr[2]+ctr[3];
                    b -= ctr[2]+ctr[3];
                    if(a==ctr[0] && b==ctr[1]){
                        yes();
                        return;
                    }else{
                        no();
                        return;
                    }
                }else{
                    no();
                    return;
                }

            }else{
                int free = canBA-needBA;

                for(int i=0;i<st.size();i++){
                    if(free==0){
                        break;
                    }
                    if(st[i].fi==1 && st[i].se%2==1){
                        int have = st[i].se/2;

                        if(free>=have){
                            free-=have;
                            canAB += have;
                        }else{
                            canAB += free;
                            free = 0;
                        }
                    }
                }

                if(free>0){
                    for(int i=0;i<st.size();i++){
                        if(free==0){
                            break;
                        }
                        if(st[i].fi==1 && st[i].se%2==0){
                            int have = (st[i].se-1)/2;

                            if(free>=have+1){
                                free-=have+1;
                                canAB += have;
                            }else{
                                canAB += free-1;
                                free = 0;
                            }
                        }
                    }
                }

                if(canAB>=needAB){
                    a -= ctr[2]+ctr[3];
                    b -= ctr[2]+ctr[3];
                    if(a==ctr[0] && b==ctr[1]){
                        yes();
                        return;
                    }else{
                        no();
                        return;
                    }
                }else{
                    no();
                    return;
                }
            }
        }
    }

    assert(0);
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

