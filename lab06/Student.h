#include <bits/stdc++.h>
#include "ScoreSheet.h"
#include "Person.h"

using namespace std;

class Student{

friend ostream &operator<<(ostream &s, Student p){
    s << p.getId() << " " << p.getFirstnameLastname() << " " << p.getPerson().getBirthday();
    return s;
}

public:
    Student(string _Id, Person _info, ScoreSheet _Scores)
    :Id(_Id), info(_info), Scores(_Scores){
    }
    string getId() const{
        return Id;
    }
    string getFirstnameLastname() const{
        return info.getFirstName() + " " + info.getLastName();
    }
    Person getPerson() const{
        return info;
    }
    ScoreSheet getScores() const{
        return Scores;
    }
    double getScoresAverage() const{
        return Scores.getAverage();
    }

private:
    string Id;
    Person info;
    ScoreSheet Scores;
};

