#include "University.h"

string University::getName() {
    return _name;
}

University::University() {
    _name = "";
    _tuition = "";
}

University::University(string name, string tuition) {
    this->_name = name;
    this->_tuition = tuition;
}
University::~University() {
    if(_name != "") {
        _name = "";
    }
    if(_tuition != "") {
        _tuition = "";
    }
}

string University::getTuition() {
    return _tuition;
}

University::University(const University &other) {
    this->_name = other._name;
    this->_tuition = other._tuition;
}

const University& University::operator=(const University &other) {
    if(this != &other) {
        this->_name = other._name;
        this->_tuition = other._tuition;
    }
    return *this;
}

