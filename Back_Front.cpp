// Don't look up the rank , if you want a good rank
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
// flags to use  -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

int calculate(const string &s , const string &sub){
    int m = sub.size();
	vector<ll>dp(m+1 , 0);
	dp[0] = INT_MAX;
	for(auto i:s){
 	   for(int j=1;j<=m;j++){
         if(i!=sub[j-1]){
		    continue;
		 }       
		 if(dp[j-1]>0){
			dp[j-1]--;
			dp[j]++;
		 }
	  }
	}
	 
	 if(dp[m]==0)return 0;
	 ll ans =  dp[m] + dp[m-1];
	 ll left = dp[m];
	 
	 for(int i = m-2;i>=0;i--)
	 {
		 if(left==0){
			break;
		 }
		 ll req = m-i-1;
		 ll used=min(dp[i] , left/req);
		 left-=(used*req);
		 ans+=used;
		 if(left==0){
           ans--;
		   break;
		 }
	 }
 
	 return ans*(m-1);
}
void yeh_bhi_krr_lete_hain(){
 int n;cin>>n;
 string s;cin>>s;
 ll ans = 0;
 ans+=(calculate(s , "front"));
  
 reverse(s.begin() , s.end());
 ans+=(calculate(s , "kcab"));
 cout<<n-ans<<endl;
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
yeh_bhi_krr_lete_hain();
}
}