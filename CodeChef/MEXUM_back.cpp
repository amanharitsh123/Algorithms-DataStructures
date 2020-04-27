#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define kick(t,a) cout<<"Case #"<<t<<": "<<a<<endl;
#define MOD 998244353
using namespace std;
typedef long long int lli;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

lli power(lli num,lli base) {
  if(base==0)
    return 1LL;

  if(base < 0) {
    //cout<<"error "<< base << endl;;
    return 0;
  }

  if(base%2)
    return (num%MOD*power(num,base-1LL)%MOD)%MOD;
  else {
    lli x=power(num,base/2LL);
    x=(x*x)%MOD;
    return x;
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin >> testcases;
  while(testcases--) {
    lli n;
    vector<lli> arr(83, 0);
    cin >> n;
    map<lli,lli> mp;
    lli ma = 0;
    for(int i = 0; i < n; i++) {
      lli temp;
      cin >> temp;
      ma = max(ma, temp);
      if(mp.find(temp)!=mp.end())
        mp[temp]++;
      else
        mp[temp] = 1;
    }

    vector<pi> inp(mp.begin(), mp.end());
    pi.push_bacK({ma+1,0});
    sort(all(inp));
    //test;
    lli ans = 0;
    lli mul = 1;
    lli count = 0;
    lli prev = 0;
    for(lli i = 1LL; i <83LL; i++) {
      count += arr[i];
      lli temp = power(2LL, n-count)%MOD;
      temp = (mul%MOD * temp%MOD) %MOD;
      temp = (i%MOD * temp%MOD)%MOD;
      //ans += i*(mul*(power(2,n-count)) %MOD)%MOD;
      ans = (ans%MOD + temp%MOD)%MOD;
      ans = ans % MOD;
      temp = (power(2LL, arr[i])%MOD - 1LL%MOD)%MOD;
      mul = (mul%MOD * temp%MOD)%MOD;
      //mul *= (power(2, arr[i]) - 1 )%MOD;
      if(arr[i]==0) {
        cout << "BREAKING at " << i << endl;
        break;
      }
    }

    cout << ans << endl;

  }
}

