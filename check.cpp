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
 

#define cntone(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_clzll(x)
#define trailone(x) __builtin_ctzll(x)
void solve(){
   int n;cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   stack<int>s;
   vector<int>right(n+1 , n+1);
   vector<int>left(n+1 , -1);
   for(int i=0;i<n;i++)
   {
       while(!s.empty() &&  arr[s.top()]>=arr[i]){
           s.pop();
       }
       if(!s.empty())
       left[i] = s.top();
       s.push(i);
   } 
   while(!s.empty()){s.pop();}
   for(int i = n-1;i>=0;i--)
   {
       while(!s.empty() && arr[s.top()] >= arr[i])
       {
          s.pop();
       }
       if(!s.empty())
       right[i] = s.top();
       s.push(i);
   }
   vector<int>ans(n+1 , 0);
   for(int i=0;i<n;i++){
      int len = right[i] - left[i] - 1;
      ans[len] = max(ans[len] , arr[i]);
   }
   for(int i=n-1;i>=1;i--)
   {
     ans[i] = max(ans[i] , ans[i+1]);
   }
   for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
   }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t=1;
while(t--){
solve();
}
}