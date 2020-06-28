#include <bits/stdc++.h>

using namespace std;

class Person {

friend ostream &operator<<(ostream &s, Person p){
    s << p.getFirstName() << " " << p.getLastName();
    return s;
}

public:
    Person(){
    }
    Person(string firstName, string lastName, string _city, string birthday, string _gender)
    :FirstName(firstName), LastName(lastName){
        Birthday = birthday.substr(0,4) + birthday.substr(5,2) + birthday.substr(8,2);
        this -> city = _city;
        this -> gender = _gender;
    }
    string getFirstName() const {
        return FirstName;
    }
    string getLastName() const {
        return LastName;
    }
    string getName() const {
        return FirstName + " " + LastName;
    }
    string getBirthday() const{
        return Birthday;
    }
    string getCityString() const{
        return city;
    }
    enum City{
        TAIPEI,
        TAICHUNG,
        KAOHSIUNG,
        OTHER
    };
    enum Gender{
        MALE,
        FEMALE
    };
    Gender getGender() const {
        if(gender=="MALE")
            return Gender::MALE;
        else
            return Gender::FEMALE;
    }
    City getCity() const {
        if(city == "Taipei")
            return City::TAIPEI;
        else if(city == "Taichung")
            return City::TAICHUNG;
        else if(city == "Kaohsiung")
            return City::KAOHSIUNG;
        else return City::OTHER;
    }
    bool isMALE() const {
        return getGender() == Gender::MALE ;
    }
    bool isFEMALE() const {
        return getGender() == Gender::FEMALE ;
    }

private:
    string FirstName;
    string LastName;
    string Birthday;
    string gender;
    string city;
};
