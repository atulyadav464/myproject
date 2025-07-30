#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string convertToTitle(int columnNumber) {
    string s = "";
    while(columnNumber)
    {
        int x = columnNumber%26;
        if(x==0)
        {     
            x = 26;
            columnNumber--;
        }
        s.push_back(char(x-1+'A'));
        columnNumber/=26;
    }
     reverse(s.begin(),s.end());
     return s;
}
int main()
{
   int x = 26;
   cout<<convertToTitle(x);
}