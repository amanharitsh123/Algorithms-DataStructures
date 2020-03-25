#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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

lli merge(vector<lli> &arr,lli lo,lli mid,lli hi) {
  if(lo>=hi)
    return 0;
  
  vector<lli> s1(arr.begin()+lo,arr.begin()+mid+1);
  vector<lli> s2(arr.begin()+mid+1,arr.begin()+hi+1);
  lli i=0,j=0,count=0;
  for(lli x=lo;x<=hi;x++) {
    if(i>=s1.size()) {
     arr[x]=s2[j];
      ++j;
    } else if(j>=s2.size()) {
      arr[x]=s1[i];
      ++i;
    }
    else if(s1[i]<=s2[j]) {
      arr[x]=s1[i];
      ++i;
    } else {
      arr[x]=s2[j];
      count+=s1.size()-i;
      ++j;
    }
  }
  return count;
  
}

lli merge_sort(vector<lli> &arr,lli lo,lli hi) {
  
  if(lo>=hi)
    return 0;
  
  lli mid=(lo+hi)/2;
  lli left=merge_sort(arr,lo,mid);
  lli right=merge_sort(arr,mid+1,hi);
  lli count=merge(arr,lo,mid,hi);
  
  return left+right+count;
}


int main() {
	lli testcases;
	cin>>testcases;
	
  while(testcases--) {
    lli n,local=0,global=0;
    vector<lli> arr;
    cin>>n;
    input(arr,n);
    for(lli i=0;i<n-1;i++)
      if(arr[i]>arr[i+1])
        ++local;
    global=merge_sort(arr,0,n-1);
    if(global==local) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
	}
}

