#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<limits.h>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
// Can be solved using Trie

class node {
  public:
    node* zero;
    node* one;
    bool done;
  node() {
    zero = NULL;
    one = NULL;
  }
};

class trie {
  public:
    node* root = new node();
  void insert(lli val) {
    node* cur = root;
    lli i = 30;
    while(i>=0)
    {
      if(val & 1<<i) // bit is 1
      {  
        if(cur->one)
        {
          cur = cur->one;
        } else
        {
          cur->one = new node();
          cur = cur->one;
        }
      } else
      {
        if(cur->zero)
        {
          cur = cur->zero;
        } else
        {
          cur->zero = new node();
          cur = cur->zero;
        }
      }
      --i;
    }
    cur->done = true;
  }

  lli compute(lli val) {
    lli ans = 0;
    lli i = 30;
    node* cur = root;
    while(i>=0)
    {
      if((val & 1<<i) == 0) // bit is 0
      {  
        if(cur->one)
        {
          cur = cur->one;
          ans = ans | 1<<i;
        } else
        {
          cur = cur->zero;
        }
      } else
      {
        if(cur->zero)
        {
          cur = cur->zero;
          ans = ans | 1<<i;
        } else
        {
          cur = cur->one;
        }
      }
      --i;
    }
    return ans;
  } 
};


void test_vim(lli a) {
  int aa;
  cin>>aa;
}

int main() {
	lli t;
	cin>>t;
  trie tr;
  vector<lli> arr(t);
  For(0,t)
  {
    cin>>arr[I];
    tr.insert(arr[I]);
  }
  lli mi = LLONG_MAX;
  for(auto x:arr)
  {
    mi = min(mi,tr.compute(x));
  }
  cout<<mi<<endl;
}



//3
//1 2 3

