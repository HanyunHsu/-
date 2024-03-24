#pragma once
#include "math_vector.h"
#include <iostream>

class Matrix
{
private:
    std::vector<MathVector> elements;

public:
    Matrix(const std::vector<MathVector> &v)
        : elements(v)
    {
            if(v.size()!=0){
        for(int i = 1; i<=rows();i++){
            
                if(elements[i-1].dimension() != columns()){
                    throw std::string("mistake");
                }
            
        }
        }
        
        
    }
    
    const MathVector &operator[](int i) const
    {
        return elements[i];
    }
    //Constructor here

    // return number of rows
    int rows() const
    {
        return elements.size();
    }

    // return number of columns
    int columns() const
    {
        return elements[0].dimension();
    }

    // return matrix column as MathVector
    MathVector at_column(int col) const {
        std::vector<double> v(rows());
        for(int i =0;i <rows();i++){
            v[i] = elements[i].at(col);
        }
        MathVector u = {v};
        return u;
    }

    // Return matrix row as MathVector
    MathVector at_row(int row) const {
        std::vector<double> v(columns());
        for(int i =0;i <columns();i++){
           v[i] =  elements[row-1].at(i+1);
        }
        MathVector u ={v};
        return u;
    }

    // Here are tamplate methods, you can use it or define by yourself
    Matrix add(Matrix mv) const
    {
        if(elements[0].dimension() != mv[0].dimension()){
            throw std::string("mistake");
        }
        if(rows() != mv.rows()){
            throw std::string("mistake");
        }
        Matrix add_result(elements);
        for (int i = 0; i < rows(); i++)
        {
            add_result.elements[i] = elements[i].add(mv.elements[i]);
        }

        return add_result;
    }

    Matrix minus(Matrix mv) const
    {
        if(elements[0].dimension() != mv[0].dimension()){
            throw std::string("mistake");
        }
        if(rows() != mv.rows()){
            throw std::string("mistake");
        }
        Matrix minus_result(elements);
        for (int i = 0; i < columns(); i++)
        {
            minus_result.elements[i] = elements[i].minus(mv.elements[i]);
        }

        return minus_result;
    }
    Matrix operator+(Matrix &u) const
    {
        Matrix addition_result(elements);
        return addition_result.add(u);
    }
    Matrix operator*(double a) const
    {   
        Matrix mul_result(elements);
        return mul_result.scalar_multiply(a);
    }
    Matrix operator*(Matrix & v) const
    {   
        Matrix mul_result(elements);
        return mul_result.product(v);
    }
  friend Matrix operator*(double a, const Matrix &matrix)
{
    return matrix.scalar_multiply(a);
}

    Matrix operator-(Matrix &u) const
    {
        Matrix div_result(elements);
        return div_result.minus(u);
    }

    Matrix scalar_multiply(double scalar) const {

        Matrix multiply_result(elements);
        for(int h = 0; h<rows();h++){
            multiply_result.elements[h] = scalar * multiply_result.elements[h];
            
        }
        return multiply_result;
    }
    
    Matrix product(const Matrix mv) const {
        Matrix mul = {{}};
        MathVector result = {{}};
        if(elements[0].dimension() != mv.at_column(1).dimension()){
            throw std::string("mistake");
        }
        std::vector<double> s(mv.columns());


    double product = 0;
    for(int h = 1; h<= rows(); h++){
        for(int j = 1; j<= mv.columns();j++){                              // 1 1  // 1 1 1 1   // 2 2 2 2 
            for(int i = 1; i <= columns(); i++) {                          // 1 1  // 1 1 1 1   // 2 2 2 2
                product += at_row(h).at(i) * mv.at_column(j).at(i);       // 1 1                  2 2 2 2
            }
            s[j-1] = product;
            product = 0;
        }
        result = {s};
        mul.elements.push_back(result);

    }
            
            return mul;
    }

    // Return transposed matrix
    Matrix transpose() const {
        Matrix trans = {{}};
            
        for(int i = 1; i<= columns();i++)
        {
            trans.elements.push_back(at_column(i)); 
        }
        // std::cout<<trans.at_column(1).at(1);
        // std::cout<<"\n"<<u.elements[0].at(1);
        return trans;
    }

    // Return transformed MathVector
    MathVector transform(MathVector v) const {
         if(elements[0].dimension() != v.dimension()){
            throw std::string("mistake");
        }
        std::vector<double> result(rows());
        double num =0;
        for(int i = 0; i<rows();i++){

            for(int j = 1; j<=columns();j++){
                num += elements[i].at(j) * v.at(j);
            }
            result[i] = num;
            num = 0;
        }

        return result;

    }

    // Operator overloading can either be here or outside the class
};
