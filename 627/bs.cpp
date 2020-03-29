#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define S second
#define F first
#define all(x) (x).begin(), (x).end()
#define daulet ios_base::sync_with_stdio(0)
#define sungkar cin.tie(0)
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool ans = false;
        map<int, pair<int, int>> d;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(d.find(a) == d.end()){
                d[a] = mp(1, i);
            }
            else{
                d[a].first ++;
                if(i - d[a].second > 1){
                    ans = true;
                }
            }
        }
        if(ans){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}