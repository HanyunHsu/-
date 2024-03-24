#pragma once
#include <vector>
#include <math.h>
#include <iomanip>


class MathVector
{
public:
    std::vector<double> u;
    double at(int i){
        return u.at(i-1);
    }
    int dimension(){
        return u.size();
    }

    MathVector add(MathVector v){
        std::vector<double> result(dimension());
        for(int i = 1; i <= dimension(); i++){
            result[i-1] = v.at(i) + at(i);
        }
    MathVector addition_result = {result};

    return addition_result;

    }

    MathVector multiply(double a){
        std::vector<double> result(dimension());
        for(int i = 1; i <= dimension(); i++){
            result[i-1] = a * at(i);
        }
        MathVector multiply_result = {result};

        return multiply_result;
    }

    
    
};