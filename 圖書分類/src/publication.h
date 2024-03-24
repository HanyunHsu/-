#pragma once

class Publication {
private:
    int _id;
    std::string _name;

public:
    Publication(int id, std::string name):_id(id), _name(name) {
    }

    int id() const {
        return _id;
    }
    
    std::string name() const {
        return _name;
    }

    virtual std::string name_of_type() const = 0;

    std::string introduction() const {
        return "A " + name_of_type() + " named " + _name; 
    }

    bool operator== (const Publication & publication) const {
        if (publication.id() == _id)
            return true;
        return false;
    }
};