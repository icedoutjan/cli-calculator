//
//  calc.hpp
//  arduinoTR
//
//  Created by Jan Giritsch on 17.03.24.
//

#ifndef calc_hpp
#define calc_hpp

#include <stdio.h>
class calc{
    void schrink(int input);
    double kurz(double input);
    void point_calc();
    void potenz_calc();
    int zahlen[10];
    char operatoren[10];
    int len;
    
    public:
    int char_to_int(const char char_array[], int size);
    bool is_number(char input);
    bool is_punkt_operator(char input);
    int cl(double p_zahlen[], char p_operatoren[] ,int p_len);
    char* int_to_char(int input);   // später double_to
};
#endif /* calc_hpp */
