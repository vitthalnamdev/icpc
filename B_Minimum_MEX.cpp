// Don't look the rank , if you want a good rank
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
//flags to use    g++ -std=c++17 -Wshadow -Wall -o check check.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
bool check(int mid , vector<int>&arr , int n , int ans  )
{ 
    set<int>s;
    vector<int>cnt(n+1 , 0);
    for(int i=0;i<=n;i++){
        s.insert(i);
    }
     
    for(int i=0;i<mid;i++){
        auto it = s.find(arr[i]);
        if(arr[i]>n)continue;
        cnt[arr[i]]++;
        if(it!=s.end())
        s.erase(it);
    }
    int now = *s.begin();
    if(now==ans){
        return true;
    }
    int p2 = mid;int p1 = 0;
    while(p2<n){
        if(arr[p1]<=n)
        cnt[arr[p1]]--;
        if(arr[p2]<=n)
        cnt[arr[p2]]++;
        if(arr[p1]<=n && cnt[arr[p1]]==0){
            s.insert(arr[p1]);
        }
        auto it = s.find(arr[p2]);
        if(it!=s.end()){
           s.erase(it);
        }
        p1++;p2++;
        int now = *s.begin();
        if(now==ans){
            return true;
        }
    }
    return false;
}


void solve(){
 int n;cin>>n;
 set<int>s;vector<int>arr(n);
 for(int i=0;i<n;i++)cin>>arr[i];
 vector<int>cnt(n+1 , 0);
 for(int i=0;i<=n;i++)s.insert(i);
 for(int i=0;i<n;i++){
    if(arr[i]>n)continue;
    auto it = s.find(arr[i]);
    cnt[arr[i]]++;
    if(it!=s.end()){
       s.erase(it);
    }
 }
 int ans = *s.begin();
 int start = 1 , end = n;
 while(end - start > 1){
    int mid = (start + end ) /2;
    if(check(mid , arr , n , ans)){
        end = mid;
    }else{
        start = mid + 1;
    }
 }
 if(check(start , arr , n , ans)){
    cout<<start<<endl;
 }else{
    cout<<end<<endl;
 }
}
int main(){
std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int t;cin>>t;
while(t--){
solve();
}
}