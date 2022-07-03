// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  string decimalToBinary(int n)
    {
        //finding the binary form of the number and
        //converting it to string.
        string s = bitset<64> (n).to_string();
         
        //Finding the first occurrence of "1"
        //to strip off the leading zeroes.
        const auto loc1 = s.find('1');
         
        if(loc1 != string::npos)
            return s.substr(loc1);
         
        return "0";
    }
    int binaryToDecimal(string n)
    {
        string num = n;
        int dec_value = 0;
     
        // Initializing base value to 1, i.e 2^0
        int base = 1;
     
        int len = num.length();
        for (int i = len - 1; i >= 0; i--) {
            if (num[i] == '1')
                dec_value += base;
            base = base * 2;
        }
     
        return dec_value;
    }
    int minVal(int a, int b) {
        int cnt_b=__builtin_popcount(b);
        int cnt_a=__builtin_popcount(a);
        string bin_a=decimalToBinary(a);
        if(cnt_b<=cnt_a){
            string bin_x=bin_a;
            for(int i=0;i<bin_x.size();i++)bin_x[i]='0';
            int i=0;
            while(cnt_b){
                if(bin_a[i]=='1'){
                    bin_x[i]='1';
                    cnt_b--;
                }
                i++;
                
            }
            return binaryToDecimal(bin_x);
        }
        else{
            string bin_x=bin_a;
            
            for(int i=0;i<bin_x.size();i++)bin_x[i]='0';
            int i=0;
            cnt_b-=cnt_a;
            // cout<<cnt_a<<" "<<cnt_b<<"\n";
            // cout<<bin_a<<" "<<decimalToBinary(b)<<" "<<bin_x<<" 1\n";
            while(cnt_a){
                if(bin_a[i]=='1'){
                    bin_x[i]='1';
                    cnt_a--;
                }
                i++;
            }
            // cout<<bin_x<<" 2\n";
            if(cnt_b>0)
            for(int i=bin_x.size()-1;i>=0&&cnt_b;i--){
                if(bin_x[i]=='0'){
                    bin_x[i]='1';
                    cnt_b--;
                }
            }
            // cout<<bin_x<<" 3\n";
            while(cnt_b>0){
                bin_x="1"+bin_x;
                cnt_b--;
            }
            // cout<<bin_x<<" 4\n";
            return binaryToDecimal(bin_x);
        }
        return cnt_b;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends