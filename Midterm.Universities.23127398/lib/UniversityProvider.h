#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include "University.h"

class UniversityProvider
{
public:
    UniversityProvider();
    UniversityProvider(string prompt);
public:
    vector<University> next(string fileName);
    University getUniversityFromLine(string line);
};
