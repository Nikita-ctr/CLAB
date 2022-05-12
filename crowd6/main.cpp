#include <bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
ll pre[maxn];
int n;
ll m;

bool cmp(ll a, ll b){
  return a > b;
}

bool Check(ll x){
  vector<ll> v;
  for(int i=0;i<x;i++) v.push_back(pre[i]);
  sort(v.begin(), v.end(), cmp);
  ll ans = m;
  for(int i=0;i<x;i+=2){
    ans -= v[i];
  }
  return ans >= 0;
}

int main() {
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pre[i]);
    }
    ll l = 0, r = n, mid, ans = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (Check(mid)) {
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}