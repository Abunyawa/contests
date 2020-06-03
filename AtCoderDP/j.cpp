#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;
ll const MOD = 1000000007;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

ll fact(int n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans = (ans*i)%MOD;
    }

    return ans;
}

ll powM(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*powM(n,x-1))%MOD;
    }
}

ll C(int n, int k){
    return (fact(n) * powM((fact(k)*fact(n-k))%MOD,MOD-2))%MOD;
}

ll A(int n, int k){
    return (fact(n) * powM(fact(n-k)%MOD,MOD-2))%MOD;
}

int const N = 302;
double p[N][N][N],ev[N][N][N];
int cnt[4];

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    p[cnt[1]][cnt[2]][cnt[3]] = 1;
    for(int c = n;c>=0;c--){
        for(int b = n;b>=0;b--){
            for(int a = n;a>=0;a--){
                if(a==0 && b==0 && c==0){
                    continue; 
                }
                if((a+b+c)>n){
                    continue;
                }
                double p_waste = (double)(n-(a+b+c))/n;
                double ev_waste = p_waste/(1-p_waste);
                ev[a][b][c] += ev_waste*p[a][b][c];
                if(a!=0){
                    p[a-1][b][c] += p[a][b][c] * (double)a/(a+b+c);
                    ev[a-1][b][c] += ev[a][b][c] *(double) a/(a+b+c);
                }
                if(b!=0){
                    p[a+1][b-1][c] +=p[a][b][c] * (double)b/(a+b+c);
                    ev[a+1][b-1][c] += ev[a][b][c] *(double) b/(a+b+c);
                }
                if(c!=0){
                    p[a][b+1][c-1] +=p[a][b][c] * (double)c/(a+b+c);
                    ev[a][b+1][c-1] +=ev[a][b][c] * (double)c/(a+b+c);
                }

            }
        }
    }
    printf("%.10f\n",ev[0][0][0]+cnt[1]+2*cnt[2]+3*cnt[3]);
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
