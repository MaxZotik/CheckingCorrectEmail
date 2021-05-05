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
    for(int i = 0; i < str.length() - 1; i++){
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
bool checkLength(std::string str, int start, int end){
    return str.size() >= start && str.size() <= end;
}

//check the string for valid characters
bool checkValidity(std::string str, std::string strChar){
    bool temp = true;

    for(char i : str){
        if(temp){
            for(char n : strChar){
                if(!(i == n || (i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))){
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

    int indexLast = findFirstMatchRight(str, '@');

    if(indexLast == -1){
        return false;
    }

    std::string strLeft = substr(str, 0, indexLast);
    std::string strRight = substr(str, indexLast + 1, str.length());

    if(!findTwoMatchRow(str, '.')){
        return false;
    }else if(!(checkLength(strLeft, 1, 64) && checkLength(strRight, 1, 63))){
        return false;
    }else if(!(checkValidity(strLeft, "!#$%&'*+-/=?^_`{|}~.") && checkValidity(strRight, "-."))){
        return false;
    }

    return true;
}

int main() {
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
