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
#define MOD 1000000007
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
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}

void solve() {
  lli k, a, b;
  cin >> k >> a >> b;
  lli sum = a+b+(a+b)%10; // d0 + d1 + d2
  vector<lli> arr;
  for(lli i=0;i<=3;i++) {
    arr.push_back(sum%10);
    sum += sum%10;
    sum = sum%10;
  }

  //output(arr);
  sum = a+b+(a+b)%10;
  //cout << "Sum is " << sum << endl;
  lli sum_four = 0;
  for(auto x:arr)
    sum_four += x;

  if(k==2) {
    sum = a+b;
    if(sum%3)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  } else {
    sum = sum%3;
    lli K = k;
    k = (k-3)/4;
    k = k%3;
    k = (k%3*sum_four%3)%3;
    sum += k;
    sum = sum%3;
    lli t=(K-3)%4;
    for(auto x:arr) {
      if(t==0)
        break;
      //cout << "added "<<x<<endl;
      sum += x;
      --t;
    }

    if(sum%3)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
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

