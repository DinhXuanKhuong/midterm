#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class Result {
public:
    bool success;    
    int errorCode;
    string message; 
    T *data;
public:
    Result() {
        success = false;
        errorCode = 0;
        message = "";
        data = nullptr;
    }
    Result(bool success, int errorCode, string message, T *data) {
        this->success = success;
        this->errorCode = errorCode;
        this->message = message;
        this->data = data;
    }
public:
    Result(const Result& other) {
        success = other.success;
        errorCode = other.errorCode;
        message = other.message;
        if (other.data!=nullptr) {
            data = new T(*other.data);
        }
        else {
            data = nullptr;
        }
    }
    const Result& operator=(const Result& other) {
        if (this != &other) {
            success = other.success;
            errorCode = other.errorCode;
            message = other.message;
            if (other.data!=nullptr) {
                data = new T(*other.data);
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }
    ~Result() {
        
        if (data!=nullptr) {
            delete data;
        }
    }
    
};