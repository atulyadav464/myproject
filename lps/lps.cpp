#include<iostream>
#include<vector>
using namespace std;

int kmp(string haystack, string needle)
{
  vector<int>lps = makelps(haystack);
  int m=needle.size();
  int n=haystack.size();
  int i=0;
  int j=0;
  while(i<n)
  {
    if(haystack[i]==needle[j])
    {
      i++;
      j++;
    }
    
    
      if(j==needle.size())
      {
        return i-j;
      }
      else if(i<n&&haystack[i]!=needle[j]){ 
        if(j!=0)
        {
          j=lps[j-1];
        }
        else{
          i++;
        }

      }
    
  }
  return -1;
}
int main()
{
  string s  = "abcabcabcaa";
  vector<int>ans =makelps(s);
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i];
  }
  string needle = "onions";
  cout<<"a\n";
  cout<<kmp(s,needle);
}

