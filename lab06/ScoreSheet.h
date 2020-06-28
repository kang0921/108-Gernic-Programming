#include <bits/stdc++.h>

using namespace std;

class ScoreSheet{

public:
    ScoreSheet(){
    }
    ScoreSheet(int math, int english, int chinese)
    :Math(math), English(english), Chinese(chinese){
        this -> Average = (double)( math + english + chinese )/3;
    }
    int getMath() const {
        return Math;
    }
    int getEnglish() const {
        return English;
    }
    int getChinese() const {
        return Chinese;
    }
    double getAverage() const {
        return Average;
    }
private:
    int Math;
    int English;
    int Chinese;
    double Average;
};

