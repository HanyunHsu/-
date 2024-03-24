#pragma once
#include <string>
#include "stationery.h"
#include <iostream>
class Pencil: public Stationery{
private:
    std::string _hardness;
    
    double _length;

public:
    Pencil(double length, std::string hardness) :Stationery(" "), _length(length), _hardness(hardness){
        if(length <= 0 || length > 50){
            throw std::string("mistake");
        }
        if(hardness != "H" && hardness != "2H" && hardness != "HB" && hardness != "B" && hardness != "2B"){
            throw std::string("mistake");
        }

    }
    Pencil(std::string id,double length, std::string hardness) : Stationery(id),_length(length), _hardness(hardness){
        if(length <= 0 || length > 50){
            throw std::string("mistake");
        }
        if(hardness != "H" && hardness != "2H" && hardness != "HB" && hardness != "B" && hardness != "2B"){
            throw std::string("mistake");
        }

    }

    double price(){
        double number;
        if(_hardness == "H"){
            number = 3.1;
            
        }else if(_hardness == "2H"){
            number = 2.6;
        }else if(_hardness == "HB"){
            number = 1.9;
        }else if(_hardness == "B"){
            number = 2.5;
        }else if(_hardness == "2B"){
            number = 2.0;
            
        }
        double pencil_price = _length * number ;
        return pencil_price;
    }
    
    std::string name() const {
        std::string pencil_name;
        if(_hardness == "H"){
            pencil_name = "H Pencil";
        }else if(_hardness == "2H"){
            pencil_name = "2H Pencil";
        }else if(_hardness == "HB"){
            pencil_name = "HB Pencil";
        }else if(_hardness == "B"){
            pencil_name = "B Pencil";
        }else if(_hardness == "2B"){
            pencil_name = "2B Pencil";
        }
        return pencil_name;
        
    }
    
};