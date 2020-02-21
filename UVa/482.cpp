#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;
typedef long long int lli;
#define For(i,n) for(lli I=i;I<n;I++)
#include<sstream>
lli toint(string a) {
  stringstream geek(a);
  lli x;
  geek>>x;
  return x;
}
vector<lli> getclause() {
      lli c;
        vector<lli> cl;
          std::string line;
          while(line=="")
            std::getline(cin, line);
              std::istringstream iss(line);
              // cout<<"line is "<<line<<endl;
                while ( iss >> c) {    
                      cl.push_back(c);
                      // cout<<c<<endl;
                        }
                  return cl;
}

vector<string> getclaused() {
      string c;
        vector<string> cl;
          std::string line;
            while(line=="")
              std::getline(cin, line);
              std::istringstream iss(line);
                while ( iss >> c) {    
                      cl.push_back(c);
                        }
                  return cl;
}

int main() {
	lli t;
  double n;
	cin>>t;
  string sss;
	while(t--) {
    vector<lli> ind;
    // getline(cin,sss);
    vector<lli> temp = getclause();
    for(auto it=temp.begin();it!=temp.end();++it)
    {
      ind.push_back(*it);
    }
    unordered_map<lli,string> mp;
    lli i=0;
    vector<string> temp2 = getclaused();
    for( auto num : temp2 )
    {
      mp[ind[i]]=num;
      // cout<<num<<endl;
      ++i;
    }
    i=1;
    while(mp.find(i)!=mp.end())
      cout<<mp[i++]<<endl;
    if(t)
      cout<<endl;
  }
}	


