
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<climits>
#define all(arr) arr.begin(),arr.end()
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
  T temp;
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

lli max_sub(vector<int> &arr) {
  lli ans=INT_MIN;
  lli temp=0;
  for(size_t i=0;i<arr.size();i++) {
    if(temp<0)
      temp=0;
    temp+=arr[i];
    ans=max(ans,temp);
  }
  return ans;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  lli testcases;
	cin>>testcases;
	while(testcases--) {
    int n,k;
    vector<int> arr;
    cin>>n>>k;
    input(arr,n);
    lli front=INT_MIN,back=INT_MIN,total=0;
    for(int i=0;i<n;i++) {
      total+=arr[i];
      front=max(front,total);
    }

    total=0;
    for(int i=n-1;i>=0;i--) {
      total+=arr[i];
      back=max(back,total);
    }

    if(k==1) {
      front=max(front,max_sub(arr));
      cout<<max(front,back)<<endl;
    }
    else {
      vector<lli> ans={front,back,back+(k-1)*total,front+back+(k-2)*total,max_sub(arr),back+front};
      for(auto x:ans)
        front=max(front,x);
      
      cout<<front<<endl;
    }
	}
}

