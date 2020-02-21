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
	bool encountered=false;
  char x;
  while((x=getchar())!=EOF)
  {
    if(x=='\"')
    {
      if(encountered) {
        printf("\'\'");
        encountered=false;
      } else
      {
        encountered=true;
        printf("``");
      }
    } else
    {
      putchar(x);
    }
  }

}

