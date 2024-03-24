#pragma once
#include "./publication.h"

class Novel : public Publication {
private:
    std::string _author;
public:
    Novel(int id, std::string name, std::string author) : Publication(id, name), _author(author) {
    }

    std::string name_of_type() const override {
        return "novel";
    }

    std::string author() const {
        return _author;
    }
};