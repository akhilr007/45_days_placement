// problem link https://leetcode.com/problems/integer-to-roman/

/*
approach:

1. create map of roman integers according to thousand, hundred, ten and unit.
2. and find which number lies at hundred, thousand, ten places and look up into the map and place it.
*/

class Solution {
public:
    string intToRoman(int num) {
        
        string units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[] = {"", "M", "MM", "MMM"};

        string result = "";

        result += thousands[num/1000] + hundreds[(num%1000)/100] + tens[(num%100)/10] + units[num%10];
        return result;

    }
};