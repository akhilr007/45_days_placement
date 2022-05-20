// problem link https://leetcode.com/problems/valid-number/

/*
the negative cases are as follows:

1. decimal point seen again after seen in the past
2. decimal point seen after the exponent e
3. e seen again after seen in the past
4. e with no prefixed number like e7
5. +/- occur at indexes other than 0 or e-1
6. char seen other than .eE0-9+-
*/

class Solution{
public:
    bool isNumber(string s){

        if(s.length() == 0) return false;

        bool numberSeen = false;
        bool decimalSeen = false;
        bool eSeen = false;

        for(int i=0; i<s.length(); i++){
            char c = s[i];

            switch(c){
                case '.':
                // ek baar decimal dekh liya ya fir e ke baad fir se dekh liya to false
                    if(decimalSeen || eSeen) return false;
                    // pehli baar decimal dekha to fir true kar do
                    decimalSeen = true;
                    break;
                
                case 'E':
                case 'e':
                // agar e pehle b dekh liya h ya fir e ke pehle koi number nai h to false
                    if(eSeen || !numberSeen) return false;
                    // pehli barr e dekha to true mark kar do
                    eSeen = true;
                    // e ke baad fir number check karna h to isliye numberSeen ko fir false mark kar do
                    numberSeen = false;
                    break;

                case '+':
                case '-':
                // agar i 0 ya fir i-1 e ke baad nai h to false return kar do
                    if(i != 0 && s[i-1] != 'e') return false;
                    // + - ke baad fir number check karna h to isliye number seen false mark kar do
                    numberSeen = false;
                    break;

                default:
                //  agar digit nai h to false kar do
                    if(!isdigit(c)) return false;
                    numberSeen = true;
            }
        }

        // "." aise case hoga to decimal true mark ho jayga aur loop se bahar lekin ye false h
        return numberSeen;
    }
};