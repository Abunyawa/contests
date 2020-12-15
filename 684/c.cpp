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
00 ok
00

10 01 11 00
00 01 10 00

11 00 
11 01 
*/

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> ansT;
    int d[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            d[i][j] = x-'0';
        }
    }
    if(n%2!=0 && m%2!=0){
        if(d[n-1][m-1]==1){
            string ans = "";

            d[n-1][m-1]^=1;
            ans+=to_string(n)+" "+to_string(m)+" ";
            d[n-1][m-2]^=1;
            ans+=to_string(n)+" "+to_string(m-1)+" ";
            d[n-2][m-2]^=1;
            ans+=to_string(n-1)+" "+to_string(m-1)+" ";
            ansT.pb(ans);

        }
    }

    if(n%2==1){
        for(int i = 0;i<m-1;i+=2){
            if(d[n-1][i]==1 && d[n-1][i+1]==1){
                string ans = "";

                d[n-1][i]^=1;
                ans+=to_string(n)+" "+to_string(i+1)+" ";
                d[n-1][i+1]^=1;
                ans+=to_string(n)+" "+to_string(i+2)+" ";
                d[n-2][i]^=1;
                ans+=to_string(n-1)+" "+to_string(i+1)+" ";
                ansT.pb(ans);
            }else if(d[n-1][i]==1){
                string ans = "";

                d[n-1][i]^=1;
                ans+=to_string(n)+" "+to_string(i+1)+" ";
                d[n-2][i+1]^=1;
                ans+=to_string(n-1)+" "+to_string(i+2)+" ";
                d[n-2][i]^=1;
                ans+=to_string(n-1)+" "+to_string(i+1)+" ";
                ansT.pb(ans);
            }else if(d[n-1][i+1]==1){
                string ans = "";

                d[n-1][i+1]^=1;
                ans+=to_string(n)+" "+to_string(i+2)+" ";
                d[n-2][i+1]^=1;
                ans+=to_string(n-1)+" "+to_string(i+2)+" ";
                d[n-2][i]^=1;
                ans+=to_string(n-1)+" "+to_string(i+1)+" ";
                ansT.pb(ans);
            }
        }
    }

    if(m%2==1){
        for(int i = 0;i<n-1;i+=2){
            if(d[i][m-1]==1 && d[i+1][m-1]==1){
                string ans = "";

                d[i][m-1]^=1;
                ans+=to_string(i+1)+" "+to_string(m)+" ";
                d[i+1][m-1]^=1;
                ans+=to_string(i+2)+" "+to_string(m)+" ";
                d[i][m-2]^=1;
                ans+=to_string(i+1)+" "+to_string(m-1)+" ";
                ansT.pb(ans);
            }else if(d[i][m-1]==1){
                string ans = "";

                d[i][m-1]^=1;
                ans+=to_string(i+1)+" "+to_string(m)+" ";
                d[i+1][m-2]^=1;
                ans+=to_string(i+2)+" "+to_string(m-1)+" ";
                d[i][m-2]^=1;
                ans+=to_string(i+1)+" "+to_string(m-1)+" ";
                ansT.pb(ans);
            }else if(d[i+1][m-1]==1){
                string ans = "";

                d[i+1][m-1]^=1;
                ans+=to_string(i+2)+" "+to_string(m)+" ";
                d[i+1][m-2]^=1;
                ans+=to_string(i+2)+" "+to_string(m-1)+" ";
                d[i][m-2]^=1;
                ans+=to_string(i+1)+" "+to_string(m-1)+" ";
                ansT.pb(ans);
            }
        }
    }

    for(int i=0;i<n-1;i+=2){
        for(int j=0;j<m-1;j+=2){

            int ones = 0;
            for(int ii = i;ii<=i+1;ii++){
                for(int jj = j;jj<=j+1;jj++){
                    if(d[ii][jj]==1){
                        ones++;
                    }
                }
            }
            if(ones==0){
                continue;
            }else if(ones==1){
                string ans = "";
                int ctr = 0;
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==1){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }else{
                            if(ctr<2){
                                ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                                d[ii][jj]^=1;
                                ctr++;
                            }
                        }
                    }
                }
                ansT.pb(ans);
                ans = "";
                ctr = 0;
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==0){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }else{
                            if(ctr<1){
                                ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                                d[ii][jj]^=1;
                                ctr++;
                            }
                        }
                    }
                }
                ansT.pb(ans);
                ans = "";
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==1){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }
                    }
                }
                ansT.pb(ans);

            }else if(ones==2){
                string ans = "";
                int ctr = 0;
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==0){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }else{
                            if(ctr<1){
                                ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                                d[ii][jj]^=1;
                                ctr++;
                            }
                        }
                    }
                }
                ansT.pb(ans);
                ans = "";
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==1){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }
                    }
                }
                ansT.pb(ans);
            }else if(ones==3){
                int ctr=0;
                string ans="";
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==1){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }
                    }
                }   
                ansT.pb(ans);

            }else{
                string ans = "";
                int ctr = 0;
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==1){
                            if(ctr<3){
                                ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                                d[ii][jj]^=1;
                                ctr++;
                            }
                        }
                    }
                }
                ansT.pb(ans);
                ctr = 0;
                ans= "";
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==1){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }else{
                            if(ctr<2){
                                ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                                d[ii][jj]^=1;
                                ctr++;
                            }
                        }
                    }
                }
                ansT.pb(ans);
                ans = "";
                ctr = 0;
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==0){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }else{
                            if(ctr<1){
                                ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                                d[ii][jj]^=1;
                                ctr++;
                            }
                        }
                    }
                }
                ansT.pb(ans);
                ans = "";
                for(int ii = i;ii<=i+1;ii++){
                    for(int jj = j;jj<=j+1;jj++){
                        if(d[ii][jj]==1){
                            ans+= to_string(ii+1)+" "+to_string(jj+1)+" "; 
                            d[ii][jj]^=1;
                        }
                    }
                }
                ansT.pb(ans);

            }
        }
    }

    if(ansT.size()>n*m){
        assert(0);
    }
    cout<<ansT.size()<<'\n';

    for(auto x: ansT){
        cout<<x<<'\n';
    }
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

