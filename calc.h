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
    double kurz(double input);
    public:
    int char_to_int(const char char_array[], int size);
    bool is_number(char input);
    bool is_punkt_operator(char input);
    int cl(double zahlen[], char operatoren[] ,int len);
    char* int_to_char(int input);   // später double_to
};
#endif /* calc_hpp */

