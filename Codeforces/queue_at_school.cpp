#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
int main() {
	lli n,t;
	cin>>n>>t;
  char arr[n];
  scanf("%s",arr);
  For(0,t) {
    for(lli I=0;I<n-1;I+=1)
    {
      if(arr[I]=='B' and arr[I+1]=='G')
      {
        char temp;
        temp = arr[I+1];
        arr[I+1]=arr[I];
        arr[I]=temp;
        ++I;
      }
    }
  }
  printf("%s",arr);
}

