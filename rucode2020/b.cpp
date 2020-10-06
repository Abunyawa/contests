#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <ios>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w, d;
    cin >> n >> w >> d;
    int arr[n];
    map<int, int> h;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        h[arr[i]]++;
        mx = max(h[arr[i]], mx);
    }
    if (h.size() > w || mx > d)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (auto i = h.begin(); i != h.end(); i++)
        {
            cout << i->F << ' ';
        }
        cout << '\n';
        for (auto i = h.begin(); i != h.end(); i++)
        {
            int x = i->S;
            while (x > 0)
            {
                int mn = min(x, d);
                cout << mn << ' ';
                x -= mn;
            }
        }
    }
    return 0;
}