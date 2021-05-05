#include <iostream>

//method find the first occurrence of a character from the end of a string
int findFirstMatchRight(std::string str, char ch){
    for(int pos = str.length()-1; pos >= 0; pos--){
        if(str[pos] == ch){
            return pos;
        }
    }
    return -1;
}

//method find two consecutive occurrences of a character in string
bool findTwoMatchRow(std::string str, char ch){
    for(int i = 0; i < str.length(); i++){
        if(ch == str[i] && ch == str[i + 1]){
            return false;
        }
    }
    return true;
}

//разделить строку
std::string substr(std::string str, int startIndex, int endIndex){
    std::string result;
    for(int i = startIndex; i < endIndex; i++){
        result += str[i];
    }
    return result;
}

//check the string length
bool checkLength(std::string str){
    if(str.size() < 1 || str.size() > 64){
        return false;
    }
    return true;
}

//check the string for valid characters
bool checkValidity(std::string strOne, std::string strTwo){
    bool temp = true;

    for(int i = 0; i < strOne.length(); i++){
        if(temp){
            for(int n = 0; n < strTwo.length(); n++){
                if(!((strOne[i] == strTwo[n] || strOne[i] >= '0' && strOne[i] <= '9' || strOne[i] >= 'A' && strOne[i] <= 'Z' || strOne[i] >= 'a') && (strOne[i] <= 'z'))){
                    temp = false;
                }else{
                    temp = true;
                    break;
                }
            }
        }else{
            break;
        }
    }

    return temp;
}

//check the address for correctness
bool checkingCorrect(std::string str){

    int indexLast;

    if(findFirstMatchRight(str, '@') != -1){
        indexLast = findFirstMatchRight(str, '@');
    }else {
        return false;
    }

    std::string strLeft = substr(str, 0, indexLast);
    std::string strRight = substr(str, indexLast, str.length());

    if(!findTwoMatchRow(str, '.')){
        return false;
    }else if(!(checkLength(strLeft) && checkLength(strRight))){
        return false;
    }else if(!(checkValidity(strLeft, "!#$%&'*+-/=?^_`{|}~.") && checkValidity(strRight, "-."))){
        return false;
    }

    return true;
}

int main() {
    std::cout << "---Checking the correctness of the email address---" << std::endl;
    std::cout << "---Checking the correctness of the email address---" << std::endl;

    std::string strAddress;

    std::cout << "Enter the email address to check for correctness" << std::endl;
    std::cin >> strAddress;

    if(checkingCorrect(strAddress)){
        std::cout << "Yes!" << std::endl;
    }else{
        std::cout << "No!" << std::endl;
    }

}
