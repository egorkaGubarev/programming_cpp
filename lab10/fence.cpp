#include <iostream>

int main()
{
    std::string s;
    std::string result = "";
    int cur_num = 0;
    std::getline(std::cin, s);
    for(int i = 0; i < s.length(); i ++) {
        if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')){
            if(cur_num % 2 == 0){
                if('a' <= s[i]){
                    result = result + char(int(s[i]) + int('A') - int('a'));
                }
                else{
                    result = result + s[i];
                }
            }
            else{
                if('Z' >= s[i]){
                    result = result + char(int(s[i]) - int('A') + int('a'));
                }
                else{
                    result = result + s[i];
                }
            }
            cur_num ++;
        }
        else{
            result = result + s[i];
        }
    }
    std::cout << result;
    return 0;
}
