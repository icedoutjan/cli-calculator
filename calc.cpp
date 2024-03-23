//
//  calc.cpp
//  arduinoTR
//
//  Created by Jan Giritsch on 17.03.24.
//
#include <iostream>
#include "calc.h"

void calc::schrink(int input){
    for (int l = input; l < len; l++){
        /*
         * alle stellen der beiden arrays zurückschieben
         * wie beim snake spiel
         */
        zahlen[l] = zahlen[l + 1];
        operatoren[l] = operatoren[l + 1];
    }
    len--;  // the size of the array schrinkes
}
void calc::potenz_calc(){
    for(int i = 0;i < len;i++){
        if(operatoren[i] == '^'){
            double tempResult = zahlen[i];
            for(int l = 1;l<zahlen[i+1];l++){
                tempResult *= zahlen[i];
            }
            schrink(i);
            zahlen[i] = tempResult;
            i = -1; //to restart to loop until ervery poin calc is done
        }
    }
}
void calc::point_calc(){
    for(int i = 0;i < len ;i++){
        if(is_punkt_operator(operatoren[i])){   //falls es ein punkt rechnung ist
            double tempResult;
            if (operatoren[i] == '*'){          // prüfe welche punkt rechnung
                tempResult = zahlen[i] * zahlen[i + 1]; // führ die rechnung durch
            }else{
                tempResult = zahlen[i] / zahlen[i + 1];
            }
            schrink(i);
            zahlen[i] = tempResult;
            i = -1; //to restart to loop until ervery poin calc is done
        }
    }
}


int calc::char_to_int(const char char_array[], int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        int digit = char_array[i] - '0'; // Konvertieren Sie das Zeichen in eine Ganzzahl
        result = result * 10 + digit; // Multiplizieren Sie das aktuelle Ergebnis mit 10 und addieren Sie die aktuelle Ziffer hinzu
    }
    return result;
}

bool calc::is_number(char input){
    switch (input) {
    case '*':
        return false;
        break;
    case '+':
        return false;
        break;
    case '-':
        return false;
        break;
    case '/':
        return false;
        break;
    case '^':
        return false;
            break;
    case '=':
            return false;
            break;
    default:
        return true;
        break;
    };
}

bool calc::is_punkt_operator(char input){
    switch (input) {
    case '*':
        return true;
        break;
    case '/':
        return true;
        break;
    default:
        return false;
        break;
    }
}

double calc::kurz(double input){
    double factor = 100.0; // Faktor für zwei Nachkommastellen
       double roundedNum = static_cast<int>(input * factor + 0.5) / factor; // Runde auf zwei Nachkommastellen
       return roundedNum;
}

int calc::cl(double p_zahlen[], char p_operatoren[] ,int p_len){
    len = p_len;
    for(int i = 0;i<len + 1;i++){
        zahlen[i] = p_zahlen[i];
        operatoren[i] = p_operatoren[i];
    }
    
    //check for potenz
    potenz_calc();
    
    // zuerst punkt rechnung
    point_calc();
   
    // jetzt nur noch adieren und oder subtrairen
    
    if(len == 0){//check ob noch strich operatoren vorhanden sind
        return zahlen[0];
    }
        
    double result;
    if(operatoren[0] == '-'){
        result = zahlen[0] - zahlen[1];
    }else{
        result = zahlen[0] + zahlen[1];
    }
    for(int i = 1;i < len;i++){
        
        if(operatoren[i] == '-'){
            result -= zahlen[i + 1];
        }else{
            result += zahlen[i + 1];
        }
    }
    
    return result;
}
