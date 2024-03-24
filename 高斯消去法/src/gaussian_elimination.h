#pragma once
#include "./math_vector.h"
#include <iostream>

std::vector<MathVector> gaussian_elimination(std::vector<MathVector> matrix)
{
    if (matrix.size() == 2)
    {
        MathVector temp = {{0, 0, 0, 0}};
        int total;
        int time = 1;
        for (int i = 1; i <= matrix[0].dimension(); i++)
        {

            if (matrix[0].at(i) == 0 && matrix[1].at(i) != 0)
            {

                temp = matrix[0];
                matrix[0] = matrix[1];
                matrix[1] = temp;
                time++;

                matrix[0] = matrix[0].multiply(1 / matrix[0].at(i));

                // if(time ==0){

                // }
                // matrix[1] = matrix[0].multiply(matrix[1].at(i)/matrix[0].at(i)*(-1)).add(matrix[1]);

                // matrix[0] = matrix[0].multiply(1/matrix[0].at(i));
                // break;
                // for(int z = 1; z<=matrix[0].dimension();z++){

                //     if(matrix[1].at(z)==0)
                //     {
                //         total++;
                //     }
                //     if(total == matrix[0].dimension()){
                //        return matrix;
                //         break;
                //     }
                // }
            }
            else if (matrix[0].at(i) != 0 && matrix[1].at(i) != 0)
            {
                matrix[0] = matrix[0];
                matrix[1] = matrix[1];
                matrix[1] = matrix[0].multiply(matrix[1].at(i) / matrix[0].at(i) * (-1)).add(matrix[1]);

                matrix[0] = matrix[0].multiply(1 / matrix[0].at(i));
                time++;
                break;
                // break;
            }
            else if (matrix[0].at(i) == 0 && matrix[1].at(i) == 0)
            {
                matrix[0] = matrix[0];
                matrix[1] = matrix[1];
                time++;
            }
            else if (matrix[0].at(i) != 0 && matrix[1].at(i) == 0)
            {

                matrix[0] = matrix[0];
                matrix[1] = matrix[1];
                matrix[0] = matrix[0].multiply(1 / matrix[0].at(i));

                time++;
                break;
                // matrix[0] = matrix[1].multiply(matrix[0].at(i+1)/matrix[1].at(i+1)*(-1)).add(matrix[0]);

                // matrix[0] = matrix[1].multiply(matrix[0].at(i+1)/matrix[1].at(i+1)*(-1)).add(matrix[0]);

                // break;
            }
        }
        for (time; time < matrix[0].dimension(); time++)
        {

            if (matrix[1].at(time) != 0 && matrix[0].at(time) != 0)
            {
                matrix[0] = matrix[1].multiply(matrix[0].at(time) / matrix[1].at(time) * (-1)).add(matrix[0]);
                matrix[1] = matrix[1].multiply(1 / matrix[1].at(time));
            }
            else if (matrix[1].at(time) == 0 && matrix[0].at(time) == 0)
            {
                matrix[0] = matrix[0];
                matrix[1] = matrix[1];
            }
            else if (matrix[1].at(time) != 0 && matrix[0].at(time) == 0)
            {
                matrix[0] = matrix[0];
                matrix[1] = matrix[1];
            }
            else if (matrix[1].at(time) == 0 && matrix[0].at(time) != 0)
            {
                // matrix[0] = matrix[0].multiply(1 / matrix[0].at(time));
                // break;
            }
        }

        //  while(1){
        //         int z =1;
        //         if(matrix[0].at(z) == 0){
        //             z++;
        //         }else if(matrix[0].at(z) != 0){
        //             matrix[0].multiply(1/matrix[0].at(z));
        //         }
        //  }
        // std::cout << " " << matrix[0].at(1) << " " << matrix[0].at(2) << " " << matrix[0].at(3) << " " << matrix[0].at(4) << "\n"
        //           << matrix[1].at(1) << " " << matrix[1].at(2) << " " << matrix[1].at(3) << " " << matrix[1].at(4);
        return matrix;
    }
    for (int column = 1; column <= matrix[0].dimension() / 2; column++)
    {

        MathVector tmp = {{0, 0, 0, 0}};
       

            for (int row = 0; row < matrix.size(); row++)
            {
                if (matrix[0].at(column) == 0 && matrix[1].at(column) != 0)
                {

                    tmp = matrix[0];
                    matrix[0] = matrix[1];
                    matrix[1] = tmp;

                    matrix[0] = matrix[0].multiply(1 / matrix[0].at(column));
                }
                else if (matrix[0].at(column) == 0 && matrix[1].at(column) == 0 && matrix[2].at(column) != 0)
                {
                    tmp = matrix[0];
                    matrix[0] = matrix[2];
                    matrix[2] = tmp;

                    matrix[0] = matrix[0].multiply(1 / matrix[0].at(column));
                }
                else if (matrix[0].at(column) != 0)
                {
                    matrix[row+column] = matrix[column-1].multiply(matrix[row+column].at(column) / matrix[column-1].at(column)).multiply(-1).add(matrix[row+column]);
                    matrix[row+column] = matrix[row+column].multiply(1 / matrix[row+column].at(column));
                    if(row+column == 4){
                        break;
                    }
                }
            }
        
    }

    for (int column = 3; column >= matrix[0].dimension() / 2; column--)
    {

        for (int row = matrix.size() ; row > 0; row--)
        {
            if (matrix[2].at(column) == 0)
            {
                break;
            }
            else if (matrix[2].at(column) != 0)
            {
                matrix[row - 1] = matrix[2].multiply(matrix[row - 2].at(column) / matrix[2].at(column)).multiply(-1).add(matrix[row - 1]);
                matrix[row - 1] = matrix[row - 1].multiply(1 / matrix[row].at(column));
            }
        }
    }

    std::cout << " " << matrix[0].at(1) << " " << matrix[0].at(2) << " " << matrix[0].at(3) << " " << matrix[0].at(4) << "\n"
              << matrix[1].at(1) << " " << matrix[1].at(2) << " " << matrix[1].at(3) << " " << matrix[1].at(4) << "\n"
              << matrix[2].at(1) << " " << matrix[2].at(2) << " " << matrix[2].at(3) << " " << matrix[2].at(4);
    return matrix;
}