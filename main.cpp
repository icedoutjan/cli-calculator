//
//  main.cpp
//  arduinoTR
//
//  Created by Jan Giritsch on 15.03.24.
//

#include <iostream>
#include "calc.h"

using namespace std;
calc calc;



void arduinoBack(){
    
    int len = 0;
    double numbers[10];
    char operatoren[10];
    for(int i = 0;i < 10;i++){
      
        char zahlen[10]; //textfeld
        
        char input;
        std::cin >> input;
        
        if(calc.is_number(input)){
            zahlen[i] = input;
        }else{
            operatoren[len] = input;
            numbers[len] = calc.char_to_int(zahlen, i);
            len++;
            i = -1;
        }
        // if the programm is finsch
        if(input == '='){
            cout << calc.cl(numbers, operatoren, len) << " ist die summe\n";
            break;
        }
    }
    
}
//simulierte main
int main(int argc, char* argv[]){
        /*      exampel of my idea
         * zahlen[i] operatoren[i] zahlen[i + 1]        = 3
         * zahlen[0] operatoren[0] zahlen[1]            = 3
         *        1             +         2             = 3
         */
    string s = argv[1];
    int len = 0;
    double numbers[10];
    char operatoren[10];
    
    char tempNum[10];
    int temp = 0;
    for(int i = 0;i < s.length();i++){
        //cout << s[i] << "\n";
        if(s[i] != '\u0020'){
            //cout << s[i] << "\n";
            if(calc.is_number(s[i])){
                //cout << s[i] << "\n";
                tempNum[temp] = s[i];
                temp++;
            }else{
                operatoren[len] = s[i];
                numbers[len] = calc.char_to_int(tempNum,temp);
                len++;
                temp = 0;
                //cout << s[i] << "\n";
            }
        }
            
    }
    cout << calc.cl(numbers, operatoren, len) << " ergebnis\n";
    //arduinoBack();
        
        return 0;
}

