class Solution {
public:

    string addBinary(string a, string b) {
        string longer = a.length() >= b.length() ? a:b;
        string shorter = a.length() >= b.length() ? b:a;
        string tmp = "";
        int diff = longer.length () - shorter.length();
        bool stepup = false;
        for(int i = longer.length() - 1; i >= 0; i-- ){
            int mytmp = 0;
            if(longer[i] == '1') mytmp ++;
            if(i - diff >= 0)
                if(shorter[i - diff] == '1') mytmp ++;
            if(stepup) mytmp ++;
            stepup = false;
            if(mytmp == 0) tmp = '0' + tmp;
            else if(mytmp == 1)tmp = '1' + tmp;
            else if(mytmp == 2) {
                stepup = true;
                tmp = '0' + tmp;
            }else{
                stepup = true;
                tmp = '1' + tmp;
            }
        }//end for i
        if(stepup) tmp = '1' + tmp;
        return tmp;
    }
};
