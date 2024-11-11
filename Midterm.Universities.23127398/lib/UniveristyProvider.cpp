#include "UniversityProvider.h"

UniversityProvider::UniversityProvider() {
    // do nothing
}

UniversityProvider::UniversityProvider(string prompt) {
    cout << prompt << endl;
}

University UniversityProvider::getUniversityFromLine(string line) {
    string name = "";
    string tuition = "";
    int index = 0;
    int cnt = 0;
    for(index; index < line.size(); ++index)
    {
        if(line[index] == ',') break;
        name += line[index];
    }
    int flag  = 0;
    
    for(index = index + 1; index < line.size() - 1; ++index)
    {
        // cout << line[index];
        if(line[index] == ',' && flag == 1) continue;
        if(flag == 0 && line[index] == '\"') {
            flag = 1;
            continue;
        }
        if(flag == 1 && line[index] == '\"') {
            flag = 0;
        }
        if(line[index] == ',' && flag == 0) {
            cnt++;
            if(cnt == 3) break;
        }
        if(cnt == 3) break;
        
    }
    for(index = index + 2; index < line.size() -1; ++index)
    {
        if(line[index] == '\"' && line[index + 1] == ',') break;
        tuition += line[index];
        
    }
    return University(name, tuition);
}

vector<University> UniversityProvider::next(string fileName) { 
    vector<University> universities;
    ifstream file(fileName);
    if(file.is_open())
    {
        string line;
        getline(file, line);
        
        while(getline(file, line))
        {
            universities.push_back(getUniversityFromLine(line));
        }
    }
    file.close();
    return universities;
}