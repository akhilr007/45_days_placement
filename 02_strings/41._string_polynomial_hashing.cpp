// string polynomial hashing 

// how to calculate the hashvalue of string
// ax3 + bx2 + cx1 + dx0

#include <iostream>
#include <string>

long hashCode(string s){

    long pow = 31;
    long p = 31;
    long ans = s[0] - 'a' + 1;
    long mod = 1e9+7;

    for(int i=1; i<s.length(); i++){
        ans = (ans + (s[i] - 'a' + 1)*pow)%mod;
        pow = (pow * p)%mod;
    }

    return ans;
}

int main(){
    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;

        cout<<hashCode(s)<<endl;
    }

    return 0;
}