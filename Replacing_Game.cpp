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
 int n , k;cin>>n>>k;
    string a , b;cin>>a>>b;
    if(a==b){
        cout<<0<<endl;return;
    }
    b+='#';
    // a -> b
    // 2*n
    // a[i]!=b[i] somewhere.
    // before i a[i]==b[i] is true;
    // If this is the last operation i->(i+k-1) , i am converting a[j] = b[i] , where j->[i , i+k-1]
    // (0->(n-k-1)) equal by doing the opearation.
    // then what should i do . 
    // I will check that if after some index from (i->i+k-1), all elements are equal and starting from 
    // (i+k , all elements are equal i.e. a[i]==b[i])
    // if we are able to find some index i , which fulfil these conditions then it is possible. 
    vector<int>suff(n+1 , 0);
    
    for(int i=n-1;i>=0;i--){
        
       if(b[i]==b[i+1]){
           suff[i] = 1+suff[i+1];
       }else{
           suff[i]=1;
       }
    }
    bool f = 0;
    
    vector<pair<int,char>>ans;
    int ind = -1;
    for(int i=0;i<=n-k;i++){
        if(suff[i]==k){
            f=1; ind = i;break;
        }
        ans.push_back({i,b[i]}); 
    }
    if(f==0){
        cout<<-1<<endl;
    }else{
        for(int i=n-k,j=n-1;i>=ind;i--)
        {
            ans.push_back({i,b[j--]});
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first+1<<" "<<ans[i].second<<endl;
        }
    }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}