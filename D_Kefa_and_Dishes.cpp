// Don't look the rank , if you want a good rank
#include<bits/stdc++.h>
using namespace std;
  #define ll long long 
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
////--------- DEBUG START---------////
#define debug(x) cerr << #x <<" "; _print(x); cerr<< endl;
void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(long long int a ){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr << a;}
template<class T1 , class T2>void _print(pair<T1,T2>a){cerr<<"{ ";cerr<<a.first<<" "<<a.second;cerr<<" }";}
template<class T>void _print(vector<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(set<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
template<class T>void _print(multiset<T>&a){cerr<<"[ ";for(T i:a){_print(i);cerr<<" ";}cerr<<" ]";}
////------DEBUG END---------////
int mod = 1e9+7;
ll inv(ll a) {
return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}
long long binpow(long long a, long long b, long long m) {
a %= m;
long long res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
void solve(){
 int n,m,k;cin>>n>>m>>k;
 vector<ll>arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 int mask = (1<<n);
 vector<vector<ll>>dp(mask , vector<ll>(n+1 , 0));
 vector<vector<ll>>rules(n+1 , vector<ll>(n+1 , 0));
 for(int i=0;i<k;i++){
     int x,y,z;cin>>x>>y>>z;
     rules[x-1][y-1] = z;
 }
 for(int i=0;i<n;i++){
    int curr = (1<<i);
    dp[curr][i] = arr[i];
 }
 for(int i=0;i<mask;i++)
 {
    for(int j=0;j<n;j++){
        int now = ((1<<j)&i);
        if(now){
            for(int k=0;k<n;k++){
                if(((1<<k)&i)==0){
                 
                  dp[i|(1<<k)][k] = max(dp[i|(1<<k)][k] , dp[i][j] + rules[j][k] + arr[k]);
                }
            }
        }
    }
 }
  
 ll ans = 0;
 for(int i=0;i<mask;i++){
    int cnt = 0;
    for(int j=0;j<n;j++){
        int now = ((1<<j)&i);
        cnt+=(now>0);
    }
    if(cnt==m){
        for(int j=0;j<n;j++){
          ans = max(ans , dp[i][j]);
        }
    }
 }
 cout<<ans<<'\n';
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}