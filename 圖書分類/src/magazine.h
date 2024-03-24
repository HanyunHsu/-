#pragma once
#include "./publication.h"

class Magazine : public Publication {
private:
    std::string _issue;
    std::string _editor;

public:
    Magazine(int id, std::string name, std::string editor, std::string issue) : Publication(id, name), _editor(editor), _issue(issue) {
    }

    std::string name_of_type() const override {
        return "magazine";
    }

    std::string issue() const {
        return _issue;
    }

    std::string editor() const {
        return _editor;
    }
};