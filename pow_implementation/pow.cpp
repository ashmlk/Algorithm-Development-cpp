//
//  pow.cpp
//  Implementation of pow(x,y) using divide and conquer
//  Algorithms in O(n) and O(log n)
//
//  Created by ARSHIA on 2/3/20.
//  Copyright © 2020 ARSHIA. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

float pow_linear(float x, int y);
float pow_log(float x, int y);

float pow_linear(float x, int y){
    if(y == 0){
        return 1;
    }
    if(y > 0){
        if(y % 2 == 0){
            return pow_linear(x, y/2) * pow_linear(x, y/2);
        }
        else if( y % 2 != 0){
            return x * pow_linear(x, y/2) * pow_linear(x, y/2);
        }
    }
     else if(y < 0){
         int y_prime = -1 * y;
        if(y % 2 == 0){ //if y is even we have  ( x ^ n/2 ) ^ 2
            return 1/(pow_linear(x, y_prime/2) * pow_linear(x, y_prime/2));
        }
        else if(y % 2 != 0){  //if y is odd we have  x * ( x ^ n/2 ) ^ 2
            return 1/(x * pow_linear(x, y_prime/2) * pow_linear(x, y_prime/2));
        }
    }
    return 0;
}

float pow_log(float x, int y){
    if(y == 0){
        return 1;
    }
    if(y > 0){
        float pow = pow_log(x, y/2); //we save the value of the subproblem once
        if(y % 2 == 0){
            return pow * pow;
        }
        else if( y % 2 != 0){
            return x * pow * pow;
        }
    }
    else if(y < 0){
        int y_prime = -1 * y;
        float pow = pow_log(x, y_prime/2);
        if(y % 2 == 0){
            return 1/(pow * pow);
        }
        else if(y % 2 != 0){
            return 1/(x * pow * pow);
        }
    }
    return 0;
}

int main(int argc, char * argv[]) {
    
    float x = atof(argv[1]);
    int y = atoi(argv[2]);
    
    clock_t begin_pow_linear = clock();
    double result_linear = pow_linear(x, y);
    clock_t end_pow_linear = clock();
    double time_pow_linear = (double(end_pow_linear - begin_pow_linear) / CLOCKS_PER_SEC);
    
    clock_t begin_pow_log = clock();
    double result_log = pow_linear(x, y);
    clock_t end_pow_log = clock();
    double time_pow_log = (double(end_pow_log - begin_pow_log) / CLOCKS_PER_SEC);
    
    using std::setw;
    std::cout << std::left;
    std::cout << "Results:" << '\n' << '\n' <<
    setw(15) << "Algorithm:" << setw(20) << "Linear Runtime" << setw(20) << "Log Runtime" << '\n' <<
    setw(15) << "Result:" << setw(20) << result_linear << setw(20) << result_log << '\n' <<
    setw(15) << "Runtimes:" << setw(20) << time_pow_linear << setw(20) << time_pow_log << '\n';
    
    return 0;
}
