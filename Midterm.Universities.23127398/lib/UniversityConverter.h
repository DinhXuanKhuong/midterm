#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <algorithm>
#include "University.h"
using namespace std;
class UnviersityConverter {
private:
    vector<string> _headers;
    vector<int> _columnSizes;
public:
    UnviersityConverter();
    
    UnviersityConverter(vector<string> headers, vector<int> columnSizes);
    string convert(vector<University> universities, string prompt, int top);

    
};