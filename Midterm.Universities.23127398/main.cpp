#include "main.h"


bool compareTuition(University u1, University u2) {
    return u1.getTuition() > u2.getTuition();
}

int main() {
    string fileName = "gapminder.csv";
    UniversityProvider provider("Phan tich du lieu cac truong dai hoc 2024\n");
    vector<University> universities = provider.next(fileName);
    sort(universities.begin(), universities.end(), compareTuition);

    vector<string> headers = {"STT","Ten truong", "Hoc phi"};
    vector<int> columnSizes = {4, 50, 10};

    UnviersityConverter converter(headers, columnSizes);

    string info =  converter.convert(universities, "Top 10 truong co hoc phi cao nhat", 10);
    cout << info << endl;
    return 0;
}

