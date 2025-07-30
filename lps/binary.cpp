#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int>prefix(n+1,0);
    for(int i =0;i<n;i++)
    {
        prefix[i+1]=prefix[i]+nums[i];
    }
    int size = 10;
    int j =0;
    
    for( int i=1 ;i<prefix.size();i++)
    {
            
         while(prefix[i]-prefix[j]>=target)
         {
            size = min(size,i-j);
            j++;
           
         }
        

    }
   return size ;

}
int main()
{
   int num = 0;
   int ans = 0;
   int count =0;
   for(int i=0;i<10;i++)
   {
      for(int j=i+1;j<10;j++)  
      {
         for(int k=j+1;k<10;k++)
         {
            count++;
         }
      }
   }
  
   cout<<count;
   
}