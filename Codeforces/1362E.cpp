#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

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
#define MOD 1000000007

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

lli mul(lli a, lli b) {
  return (a%MOD*b%MOD)%MOD;
}

lli power(lli a,lli b) {
  lli ans = 1;
  while(b > 0) {
    if(b&1)
      ans = mul(ans, a);
    a = mul(a,a);;
    b >>= 1;
  }
  return ans;
}

const int N = 1e6;
lli p = 1;

lli cal(lli prev, lli count, lli ele) {
  lli ans = prev - ele;
  lli b = p;
  lli t = 1;
  /*while(ans>0) {
    t *= p;
    if(t>N)
      return -1;
    --ans;
  }*/
  if(ans>(log(N)/log(p)))
    return -1;

  while(ans>0) {
    if(ans%2==0) {
      b = b*b;
    } else {
      t = t*b;
      b = b*b;
    }
    ans /= 2;
    if(t>N)
      return -1;
  }

  t*=count;
  if(t<0 or t>N)
    return -1;

  return t;
} 

void solve() {
  lli n;
  cin >> n >> p;
  vector<lli> arr;
  input(arr, n);
  lli diff = 0;
  map<lli, lli> freq;
  for(auto x:arr)
    freq[x] += 1;

  arr.clear();
  for(auto x:freq)
    arr.push_back(x.first);

  lli i=0;
  sort(all(arr));
  reverse(all(arr));
  n = arr.size();
  while(i<n) {
    if(freq[arr[i]]%2==0) {
      ++i;
      continue;
    }

    // try to increase frequency by 1
    lli prev = arr[i];
    lli count = 1;
    bool possible = false;
    for(lli j=i+1; j<n; j++) {
      lli new_count = cal(prev, count, arr[j]);
      if(new_count==-1)
        break;

      if(new_count<=freq[arr[j]]) {
        freq[arr[j]] -= new_count;
        i = j;
        possible = true;
        break;
      } else {
        count = new_count - freq[arr[j]];
        prev  = arr[j];
      }
    }

    if(!possible) {
      diff = power(p, arr[i]);
      for(lli j=i+1; j<n; j++) {
        diff = (diff-mul(freq[arr[j]],power(p, arr[j]))+MOD)%MOD;
      }
      break;
    }
  }

  cout << diff << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>testcases;
  while(testcases--) {
    solve();
  }
}

