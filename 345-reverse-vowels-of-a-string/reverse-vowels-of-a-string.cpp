class Solution {
public:
    bool isVowel(char c){
        if(c=='a' or c=='e' or  c=='i' or  c=='o' or  c=='u' or c=='A' or  c=='E' or  c=='I' or  c=='O' or  c=='U' )
        return true;
        else
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            if(isVowel(s[i]) && isVowel(s[j]))
            swap(s[i++],s[j--]);
            else if(isVowel(s[i]) && !isVowel(s[j]))
                j--;
            else if(!isVowel(s[i]) && isVowel(s[j]))
                i++;
            else{
            i++;
            j--;}
        } 
        return s; 
    }
};