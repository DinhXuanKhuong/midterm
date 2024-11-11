#pragma once
#include <iostream>

using namespace std;

class University {
private: 
    string _name;
    string _tuition;
public:
    University();
    University(string name, string tuition);
    ~University();
    University(const University &other);    
public:
    string getName();
    string getTuition();
    const University& operator=(const University &other);
};