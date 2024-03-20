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

//simulierte main
int main(){
   
        //char zahlen[10]; // to safe all numbers in a array
        /*      exampel of my idea
         * zahlen[i] operatoren[i] zahlen[i + 1]        = 3
         * zahlen[0] operatoren[0] zahlen[1]            = 3
         *        1             +         2             = 3
         */
    int len = 0;
        for(int i = 0;i < 10;i++){
            double numbers[10];
            char operatoren[10];
            
            char zahlen[10]; //textfeld
            
            char input;
            cin >> input;
            
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
                
                
                //double numbers[6] = {12.0 , 11.0 , 3.0 , 20.0, 5.0, 7.0};
                //char operatoren[5] = {'+','*','+','/','+'};
                cout << calc.cl(numbers, operatoren, len) << " ist die summe\n";
                break;
            }
        }
        return 0;
}


