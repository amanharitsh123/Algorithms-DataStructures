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
    int num;
    int pos=32;
    int itr=0;
    while(cin>>num) {
        // reverse bytes
        int ans=0;
        pos=31;
        // Negative Check
        if(num & 1<<8)
            ans=ans | 1<<32;
        
        itr=0;
        while(itr<=31)
        {
            itr+=7;
            // cout<<"1 pos is "<<pos<<" "<<itr<<endl;
            for(int i=7;i>=0;i--)
            {
                if(num&1<<itr)
                {
                    ans=ans|1<<pos;
                    // cout<<"2 pos is "<<pos<<" "<<itr<<endl;
                }
                --itr;
                --pos;
            }
            itr+=9;
        }
        cout<<num<<" converts to "<<ans<<endl;
    }
}