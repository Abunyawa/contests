    // chrono::system_clock::now().time_since_epoch().count()
    // #include <bits/stdc++.h>
    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <algorithm>
    #include <vector>
    #include <map>
    #include <unordered_map>
    #include <set>
    #include <queue>
    #include <stack>
    #include <chrono>
    #include <random>
    #include <utility>
    #include <array>
    #include <list>
    #include <cassert>
     
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
     
    const int MAXN = 105;
    const int INF = (int)1e9;
     
    int dx[] = {1, -1, 0, 0, 0, 0};
    int dy[] = {0, 0, 1, -1, 0, 0};
    int dz[] = {0, 0, 0, 0, 1, -1};
     
    vector< array<int, 3> > users;
    string field[MAXN][MAXN];
    int d[MAXN][MAXN][MAXN];
    int Z, X, Y;
     
    array<int, 8> get(int z, int x, int y, int k) {
        array<int, 4> pt = {z + x + y, z + x - y, z - x + y, z - x - y};
        array<int, 8> ret;
        
        rep (i, 0, 4) {
            ret[i * 2] = pt[i] - k;
            ret[i * 2 + 1] = pt[i] + k;
        }
     
        return ret;
    }
     
    bool check(int lim) {
        vector< array<int, 3> > important_users;
     
        for (auto &[z, x, y] : users) {
            if (d[z][x][y] > lim) {
                important_users.pb({z, x, y});
            }
        }
     
        rep (z, 0, Z) {
            rep (x, 0, X) {
                rep (y, 0, Y) {
                    if (field[z][x][y] == '.') {
                        bool ok = 1;
     
                        for (auto &[nz, nx, ny] : important_users) {
                            int dis = abs(z - nz) + abs(x - nx) + abs(y - ny);
     
                            if (dis > lim) {
                                ok = 0;
                                break;
                            }
                        }
     
                        if (ok) {
                            return 1;
                        }
                    }
                }
            }
        }
     
        return 0;
    }
     
    void solve() {
        rep (i, 0, Z) {
            rep (j, 0, X) {
                cin >> field[i][j];
            }
        }
     
        users.clear();
        queue< array<int, 3> > Q;
     
        rep (i, 0, Z) {
            rep (x, 0, X) {
                rep (y, 0, Y) {
                    d[i][x][y] = INF;
                    
                    if (field[i][x][y] == '*') {
                        users.pb({i, x, y});
                    }
                    else if (field[i][x][y] == '@') {
                        d[i][x][y] = 0;
                        Q.push({i, x, y});
                    }
                }
            }
        }
     
        while (!Q.empty()) {
            auto &[z, x, y] = Q.front();
            Q.pop();
     
            rep (dir, 0, 6) {
                int nz = z + dz[dir], nx = x + dx[dir], ny = y + dy[dir];
                
                if (0 <= nz && nz < Z && 0 <= nx && nx < X && 0 <= ny && ny < Y) {
                    if (d[z][x][y] + 1 < d[nz][nx][ny]) {
                        d[nz][nx][ny] = d[z][x][y] + 1;
                        Q.push({nz, nx, ny});
                    }
                }
            }
        }
     
        int l = 0, r = 1000, ans = -1;
     
        while (l <= r) {
            int mid = (l + r) >> 1;
     
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
     
        cout << ans << '\n';
    }
     
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
     
        while (cin >> Z >> X >> Y) {
            solve();
        }
     
        return 0;
    }