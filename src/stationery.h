#pragma once
#include <string>

class Stationery{
    private:
        const std::string _id;

    public:

        Stationery(std::string ID):_id(ID){


        }

        virtual double price(){
            return 0;
        }

        virtual std::string name() const {
            return 0;
        }

        std::string id() const{

            return _id;
        }
};