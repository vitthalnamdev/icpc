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
 
 

void dfs(int node , int parent , vector<int>adj[] ,   int level[] , vector<int>&f)
{  
    
   for(auto i: adj[node])
   {
      if(i==parent){continue;}
      level[i] = level[node] + 1;
      f[i] = node;
       
      dfs(i , node , adj ,  level  , f);
       
   }
}
void yeh_bhi_krr_lete_hain(){
  
  // activatetime = -1;
  int n;
   cin>>n;
  //  temp = n;
   ll ans = 0;
   int level[n+1];
   for(int i=0;i<=n;i++)level[i] = 0;
   int a , b;cin>>a>>b;
   vector<int>adj[n+1];
   for(int i = 0; i < n-1;i++)
   {
      int x , y;cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   int mx = -1;
   vector<int>f(n+1 , -1);
  dfs(a , -1 , adj ,  level , f);
  for(int i=1;i<=n;i++)mx = max(mx , level[i]);
 if(a==b){
     cout<<2*(n-1) - mx<<endl;
 }else{ 
   int mid = level[b]/2 + level[b]%2;
   int node = b;
   for(int i = 0;i<mid;i++){
      node = f[node];
   }
  //  totaltime = 0;
  //  temp = n;
   for(int i=0;i<=n;i++)level[i] = 0;
   dfs(node , -1 , adj , level , f);
   mx = -1;
   for(int i=0;i<=n;i++){
      mx = max(mx , level[i]);
   }
  //  debug(totaltime)
   cout<<2*(n-1) - mx + mid<<endl;
 }

}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
yeh_bhi_krr_lete_hain();
}
}