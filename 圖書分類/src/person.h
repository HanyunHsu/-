#pragma once

class Person {
private:
    int _id;
    std::string _name;
    std::vector<Publication *> _publications;

public:
    Person(int id, std::string name):_id(id), _name(name){
    }

    int id() const {
        return _id;
    }

    std::string name() const {
        return _name;
    }

    std::vector<Publication *> publicationsBorrowed() const {
        return _publications;
    }

    bool isBorrowed(const Publication & publication) const {
        for(int i = 0; i < _publications.size(); i++) {
            if(*_publications.at(i) == publication)
                return true;
        }
        return false;
    }
    
    void borrowPublication(Publication * publication) {
        if(_publications.size() >= 2)
            throw std::string("publication size limited");
        if(isBorrowed(*publication))
            throw std::string("publication already exists");
        for(int i = 0; i<_publications.size(); i++) {
            if((*_publications.at(i)).id() == (*publication).id())
                throw std::string("publication id already exists");
        }
        _publications.push_back(publication);
    }

    void returnPublication(Publication * publication) {
        if(!isBorrowed(*publication)){
            throw std::string("publication not exist");
        }

        for(int i = 0; i < _publications.size(); i++){
            if((*_publications.at(i)) == *publication){
                _publications.erase(_publications.begin() + i);
            }
        }
    }

    bool operator== (const Person & p) const {
        if (p.id() == _id && p.name() == _name)
        {
            return true;
        }
        return false;
    }
};