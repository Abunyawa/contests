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


int pr[1000100][3];
vector<array<int,3>> t;
int n;

void init (int nn)
{
	n = nn;
	t.assign (n, {0,0,0});
}

array<int,3> sum (int r)
{
	array<int,3> result = {0,0,0};
	for (; r >= 0; r = (r & (r+1)) - 1){
		result[0] += t[r][0];
        result[1] += t[r][1];
        result[2] += t[r][2];
    }
	return result;
}

void inc (int i, array<int,3> delta)
{
	for (; i < n; i = (i | (i+1))){
		t[i][0] += delta[0];
        t[i][1] += delta[1];
        t[i][2] += delta[2];
    }
}

array<int,3> sum (int l, int r)
{
    array<int,3> right = sum(r);
    array<int,3> left = sum(l-1);
	return {right[0]-left[0],right[1]-left[1],right[2]-left[2]};
}

void init (vector<array<int,3>> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}

void solve() {
    int n,m;
    cin>>n>>m;

    vector<array<int,3>> a(n+1,{0,0,0});

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        a[i][x-1]++;
    }

    init(a);

    ll ans = 0;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;

        array<int,3> cur = sum(x,x);
        cur[0] = -cur[0];
        cur[1] = -cur[1];
        cur[2] = -cur[2];

        cur[y-1]++;
        inc(x,cur);

        array<int,3> left = sum(1,z);
        array<int,3> right = sum(z+1,n);
        
        int smL = left[0] + left[1]*2+left[2]*3;
        int smR = right[0] + right[1]*2+right[2]*3;
        //cout<<'\n';
        //cout<<left[0]<<' '<<left[1]<<' '<<left[2]<<'\n';
        //cout<<right[0]<<' '<<right[1]<<' '<<right[2]<<'\n';
        if(smL==smR){
            continue;
        }else{
            int dif = smR-smL;
            ll ansL = 0;
            if(dif>0){
                int can = min(right[2], left[0]);
                
                ansL+= min(can, dif/4);
                left[0]-=min(can, dif/4);
                left[2]+=min(can, dif/4);
                right[0]+=min(can, dif/4);
                right[2]-=min(can, dif/4);
                dif -= min(can*4, dif/4*4);

                can = min(right[2], left[1]);

                left[1]-=min(can, dif/2);
                left[2]+=min(can, dif/2);
                right[1]+=min(can, dif/2);
                right[2]-=min(can, dif/2);
                ansL+= min(can, dif/2);
                dif -= min(can*2, dif/2*2);

                can = min(right[1], left[0]);

                left[0]-=min(can, dif/2);
                left[1]+=min(can, dif/2);
                right[0]+=min(can, dif/2);
                right[1]-=min(can, dif/2);
                ansL+= min(can, dif/2);
                dif -= min(can*2, dif/2*2);

                if(dif!=0){
                    ansL = -1;
                }
            }else{
                dif = -dif;
                int can = min(left[2], right[0]);
                
                left[0]+=min(can, dif/4);
                left[2]-=min(can, dif/4);
                right[0]-=min(can, dif/4);
                right[2]+=min(can, dif/4);

                ansL+= min(can, dif/4);
                dif -= min(can*4, dif/4*4);

                can = min(left[2], right[1]);


                left[1]+=min(can, dif/2);
                left[2]-=min(can, dif/2);
                right[1]-=min(can, dif/2);
                right[2]+=min(can, dif/2);
                ansL+= min(can, dif/2);
                dif -= min(can*2, dif/2*2);

                can = min(left[1], right[0]);

                left[0]+=min(can, dif/2);
                left[1]-=min(can, dif/2);
                right[0]-=min(can, dif/2);
                right[1]+=min(can, dif/2);
                ansL+= min(can, dif/2);
                dif -= min(can*2, dif/2*2);

                if(dif!=0){
                    ansL = -1;
                }
            }
            //cout<<ansL<<' ';
            ans+=ansL;
        }
    }
    //cout<<'\n';
    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

