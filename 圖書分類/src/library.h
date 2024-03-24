#pragma once

class Library {
private:
    std::vector<Publication *> _publications;

public:
    Library() {
    }
    
    Library(std::vector<Publication *> publications):_publications(publications) {
    }

    std::vector<Publication *> publications() const {
        return _publications;
    }

    bool hasPublication(const Publication & publications) const {
        for(int i = 0; i < _publications.size(); i++) {
            if(*_publications.at(i) == publications)
                return true;
        }
        return false;
    }

    void addPublication(Publication * publication) {
        if(hasPublication(*publication)){
            throw std::string("Publication Exists");
        }
        for(int i = 0; i<_publications.size(); i++) {
            if((*_publications.at(i)).id() == (*publication).id())
                throw std::string("cannot have publications with same id");
        }
        _publications.push_back(publication);
    }

    void removePublication(Publication * publication) {
        if(!hasPublication(*publication))
            throw std::string("No publication to remove");

        for(int i = 0; i < _publications.size(); i++){
            if((*_publications.at(i)) == *publication){
                _publications.erase(_publications.begin() + i);
            }
        }
    }
};