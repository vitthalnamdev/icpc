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
ll mod = 1e9+7;
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
ll ncr(ll fact[] , ll n , ll r )
{
    return (fact[n]*(inv((fact[r]*(fact[n-r]))%mod)))%mod;
}
void solve(){
   int n,k;cin>>n>>k;
   vector<int>arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   ll fact[n+1];
   fact[0] = 1;
   for(int i=1;i<=n;i++){
     fact[i] = (fact[i-1]*i);
     fact[i]%=mod;
   }
   ll ans = ncr(fact , n , k);
   int z = 0;
   for(int i=0;i<n;i++){
       z+=(arr[i]^1);
   }
   int o = (n-z);
   if(o<k/2+1){
     cout<<0<<endl;return;
   }
   for(int i=k/2+1;i<=min(k,z);i++){
    int left = k-i;    
    ll selectzero = ncr(fact , z , i);
    ll selectones = ncr(fact , o , left);
    
    ll finalresult = (selectones*selectzero)%mod;
    ans-=finalresult;
    ans = (ans+mod)%mod;
   }
 
   cout<<(ans + mod)%mod<<'\n';
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}