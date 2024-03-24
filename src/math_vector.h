#pragma once
#include <vector>

class MathVector
{
private:
    std::vector<double> elements;

public:
    // Constructor here
    MathVector(const std::vector<double> &v)
        : elements(v)
    {
    }

    double at(int i) const
    {
        return elements.at(i - 1);
    }

    int dimension() const
    {
        return elements.size();
    }

    MathVector add(const MathVector &v) const
    {
        std::vector<double> result(dimension());
         if(dimension() != v.dimension()){
            throw std::string("mistake");
        }

        for (int i = 1; i <= dimension(); i++)
        {
            result[i - 1] = at(i) + v.at(i);
        }
        MathVector addition_result = {result};

        return addition_result;
    }

    MathVector scalar_multiply(double a) const
    {
        std::vector<double> result(dimension());

        for (int i = 1; i <= dimension(); i++)
        {
            result[i - 1] = a * at(i);
        }
        MathVector multiply_result = {result};

        return multiply_result;
    }

    // Here are the template methods, you can use it or define methods by yourself
    MathVector minus(MathVector &v) const
    {
        
        std::vector<double> result(dimension());
        if(dimension() != v.dimension()){
            throw std::string("mistake");
        }

        for (int i = 1; i <= dimension(); i++)
        {
            result[i - 1] = at(i) - v.at(i);
        }
        MathVector minus_result = {result};

        return minus_result;
    }
    double product(MathVector &v) const{
        
        double num =0;
        
        for(int i = 0;i<dimension() ; i++){

            num += elements[i] * v.at(i+1);
        }

    
    
    
        return num;
    }
    friend MathVector operator*(MathVector &v,int a)
{
    return v.scalar_multiply(a);
}
    friend double operator*(MathVector &v,MathVector &u)
{
    return v.product(u);
}

};

MathVector scalar_multiply(double a, const MathVector &v)
{
    return v.scalar_multiply(a);
}

MathVector operator*(int a, MathVector &v)
{
    return v.scalar_multiply(a);
}
 
MathVector operator+(MathVector &u,MathVector &v)
{
    
    return u.add(v);
}
MathVector operator-(MathVector &u,MathVector &v)
{
    return u.minus(v);
}
