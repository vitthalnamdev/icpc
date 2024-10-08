// Don't look the rank , if you want a good rank
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
////--------- DEBUG START---------////
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
void _print(int a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(long long int a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(bool a) { cerr << a; }
template <class T1, class T2>
void _print(pair<T1, T2> a)
{
    cerr << "{ ";
    cerr << a.first << " " << a.second;
    cerr << " }";
}
template <class T>
void _print(vector<T> &a)
{
    cerr << "[ ";
    for (T i : a)
    {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
template <class T>
void _print(set<T> &a)
{
    cerr << "[ ";
    for (T i : a)
    {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
template <class T>
void _print(multiset<T> &a)
{
    cerr << "[ ";
    for (T i : a)
    {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
////------DEBUG END---------////
int mod = 1e9 + 7;
ll inv(ll a)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inv(mod % a) % mod;
}
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
class Table
{
public:
    void build(vector<ll> &arr, int n, vector<vector<ll>> &table)
    {
        for (int i = 0; i < n; i++)
        {
            table[i][0] = arr[i];
        }
        for (int j = 1; j < 20; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int now = (i + (1 << (j - 1)));
                if (now >= n)
                {
                    break;
                }
                table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r, vector<vector<ll>> &table)
    {
        int sz = (r - l + 1);
        int cnt = 0;
        for (int i = 0; i < 20; i++)
        {
            int now = (1 << i);
            if (now > sz)
            {
                cnt = i - 1;
                break;
            }
        }
        return max(table[l][cnt], table[r - (1 << cnt) + 1][cnt]);
    }
};
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
void yeh_bhi_krr_lete_hain()
{
    int n;
    cin >> n;
    vector<ll> arr(n), brr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cin >> brr[i];
    int m;
     
    cin >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }
     for (int i = 0; i < n; i++)
        {
            if (arr[i] < brr[i])
            {

                cout << "NO" << endl;
                return;
            }
        }
    map<int, int> cnt;
    for (int i = 0; i < m; i++)
    {
        cnt[x[i]]++;
    }
    map<int, int> pos;
    vector<vector<ll>> table(n + 1, vector<ll>(20, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            table[i][j] = 0;
        }
    }
     Table curr = Table();
    curr.build(brr, n, table);
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == brr[i])
        {
            continue;
        }
        if (pos[brr[i]] == 0)
        {
            cnt[brr[i]]--;
        }
        if (pos[brr[i]] != 0)
        {
            int ele = curr.query(i, pos[brr[i]], table);
            if (ele > brr[i])
            {
                cnt[brr[i]]--;
            }
        }
        pos[brr[i]] = i;
        if (cnt[brr[i]] < 0)
        {

            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        yeh_bhi_krr_lete_hain();
    }
}