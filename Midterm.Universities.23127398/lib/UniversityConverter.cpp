#include "UniversityConverter.h"
#include <algorithm>
UnviersityConverter::UnviersityConverter() {
    _headers = {};
    _columnSizes = {};
}

UnviersityConverter::UnviersityConverter(vector<string> headers, vector<int> columnSizes) {
    _headers = headers;
    _columnSizes = columnSizes;
}

string UnviersityConverter::convert(vector<University> universities, string prompt, int top) {
    cout << prompt << endl << endl;
    stringstream ss;
    string header = "";
    for(int i = 0; i < _headers.size(); i++) {
        header += "|";
        header += _headers[i];
        for(int j = 0; j < _columnSizes[i] - _headers[i].size(); j++) {
            header += " ";
        }
    }
    header += "|";
    ss << header << endl;
    for(int i = 0; i < header.size(); i++) {
        ss << "-";
    }
    ss << endl;
    string row;
    int n = std::min(static_cast<int>(universities.size()), top);
    for(int i = 0; i < n; i++) {
        row = "|";
        row += to_string(i+1);
        for(int j = 0; j < _columnSizes[0] - to_string(i+1).size(); j++) {
            row += " ";
        }
        row += "|";
        row += universities[i].getName();
        for(int j = 0; j < _columnSizes[1] - universities[i].getName().size(); j++) {
            row += " ";
        }
        row += "|";
        row += universities[i].getTuition();
        for(int j = 0; j < _columnSizes[2] - universities[i].getTuition().size(); j++) {
            row += " ";
        }
        row += "|";
        ss << row << endl;
    }
    return ss.str();

}