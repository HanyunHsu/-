#pragma once
#include <string>
#include "stationery.h"

class Eraser: public Stationery{
    private:
        std::string _eraser;
        std::string _brand;
        
    public:
        Eraser(std::string eraser,std::string brand):Stationery(" "), _eraser(eraser),_brand(brand){
            if(eraser != "Small" && eraser != "Medium" && eraser != "Large"){
            throw std::string("mistake");
        }
            if(brand != "Staedtler" && brand != "MUJI" && brand != "Pentel"){
            throw std::string("mistake");
        }
        }
        Eraser(std::string id,std::string eraser,std::string brand): Stationery(id),_eraser(eraser),_brand(brand){
            if(eraser != "Small" && eraser != "Medium" && eraser != "Large"){
            throw std::string("mistake");
        }
            if(brand != "Staedtler" && brand != "MUJI" && brand != "Pentel"){
            throw std::string("mistake");
        }
        }
        
    double price(){
        double size_number;
        double brand_number;
        if(_eraser == "Small"){
            size_number = 1;
        }else if(_eraser == "Medium"){
            size_number = 2;
        }else if(_eraser == "Large"){
            size_number = 4;
        }
        if(_brand == "Staedtler"){
            brand_number = 15;
        }else if(_brand == "MUJI"){
            brand_number = 29;
        }else if(_brand == "Pentel"){
            brand_number = 39;
        }
        double eraser_price = size_number * brand_number;

        return eraser_price;
    }

    std::string name() const{
        std::string eraser_name;
        if(_eraser == "Small" && _brand == "Staedtler"){
            eraser_name = "Small Staedtler Eraser";
        }else if(_eraser == "Medium" && _brand == "Staedtler"){
            eraser_name = "Medium Staedtler Eraser";
        }else if(_eraser == "Large" && _brand == "Staedtler"){
            eraser_name = "Large Staedtler Eraser";
        }else if(_eraser == "Small" && _brand == "MUJI"){
            eraser_name = "Small MUJI Eraser";
        }else if(_eraser == "Medium" && _brand == "MUJI"){
            eraser_name = "Medium MUJI Eraser";
        }else if(_eraser == "Large" && _brand == "MUJI"){
            eraser_name = "Large MUJI Eraser";
        }else if(_eraser == "Small" && _brand == "Pentel"){
            eraser_name = "Small Pentel Eraser";
        }else if(_eraser == "Medium" && _brand == "Pentel"){
            eraser_name = "Medium Pentel Eraser";
        }else if(_eraser == "Large" && _brand == "Pentel"){
            eraser_name = "Large Pentel Eraser";
        }

        return eraser_name;
    }
    

};