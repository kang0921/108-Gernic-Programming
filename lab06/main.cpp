#include <bits/stdc++.h>
#include "Student.h"

using namespace std;

template <typename T>
inline void Print (const T& a, const string& str="")
{
    cout << str << '\n' << endl;
    for (auto i : a) {
        cout << i << endl;;
    }
    cout<<endl;

}

enum Subject{
    Math,
    English,
    Chinese
};

int main()
{
    int num;
    cin>>num;
    list<Person> personList;
    list<ScoreSheet> scoresheetList;
    list<Student> studentList;

    for(int i = 0; i<num ; i++){
        string id;
        string firstname;
        string lastname;
        string city;
        string birthday;
        string gender;

        int math;
        int english;
        int chinese;
        cin>>id>>firstname>>lastname>>city>>birthday>>gender>>math>>english>>chinese;

        Person person = Person(firstname, lastname, city, birthday, gender);
        personList.push_back(person);
        ScoreSheet scoresheet = ScoreSheet(math, english, chinese);
        scoresheetList.push_back(scoresheet);
        Student student = Student(id, person, scoresheet);
        studentList.push_back(student);

    }
    // Q1: (1)
    studentList.sort( [](const Student &a, const Student &b){
                     return a.getId() > b.getId(); });
    Print(studentList, "Q1(1):");
    // Q1: (2)
    studentList.sort( [](const Student &a, const Student &b){
                     return a.getPerson().getBirthday() > b.getPerson().getBirthday(); });
    Print(studentList, "Q1(2):");
    // Q2
    set< pair <string, Person::City > > citySet ;
    for(auto i : studentList){
        pair<string, Person::City> p ( i.getFirstnameLastname(), i.getPerson().getCity() );
        citySet.insert(p);
    }
    cout<<"Q2:\n"<<endl;
    for(auto i : citySet){
        switch( i.second ){
            case Person::City::TAIPEI:
                cout << i.first << " TAIPEI" << endl;
                break;
            case Person::City::TAICHUNG:
                cout << i.first << " TAICHUNG" << endl;
                break;
            case Person::City::KAOHSIUNG:
                cout << i.first << " KAOHSIUNG" << endl;
                break;
            default:
                cout << i.first << " OTHER" << endl;
                break;
        }
    }
    //Q3
    cout<<"\nQ3:\n"<<endl;
    map<Person::City, list<Student>> cityMap;
    list<Student>TAIPEI_List, TAICHUNG_List, KAOHSIUNG_List, OTHER_List;
    for(auto i : studentList){
        if( i.getPerson().getCity() == Person::City::TAIPEI)
            TAIPEI_List.push_back(i);
        else if( i.getPerson().getCity() == Person::City::TAICHUNG)
            TAICHUNG_List.push_back(i);
        else if( i.getPerson().getCity() == Person::City::KAOHSIUNG)
            KAOHSIUNG_List.push_back(i);
        else OTHER_List.push_back(i);

    }
    for(auto i: studentList){
        if( i.getPerson().getCity() == Person::City::TAIPEI){
            pair<Person::City, list<Student>> p (i.getPerson().getCity(), TAIPEI_List );
            cityMap.insert(p);
        }
        else if( i.getPerson().getCity() == Person::City::TAICHUNG){
            pair<Person::City, list<Student>> p (i.getPerson().getCity(), TAICHUNG_List );
            cityMap.insert(p);
        }
        else if( i.getPerson().getCity() == Person::City::KAOHSIUNG){
            pair<Person::City, list<Student>> p (i.getPerson().getCity(), KAOHSIUNG_List );
            cityMap.insert(p);
        }
        else{
            pair<Person::City, list<Student>> p (i.getPerson().getCity(), OTHER_List );
            cityMap.insert(p);
        }
    }

    for(auto i : cityMap ){
        if(i.first == 0) cout<<"TAIPEI:"<<endl;
        else if(i.first == 1) cout<<"TAICHUNG:"<<endl;
        else if(i.first == 2) cout<<"KAOHSIUNG:"<<endl;
        else cout<<"OTHER:"<<endl;

        for( auto j : i.second )
            cout << "       " << j.getFirstnameLastname() << endl;
        cout << endl;
    }
    //Q4
    cout<<"\nQ4:\n"<<endl;
    map< Person::Gender , list<Student> > genderMap;
    list<Student> MALElist, FEMALElist;
    for(auto i : studentList){
        if(i.getPerson().getGender() == Person::Gender::MALE)
            MALElist.push_back(i);
        else
            FEMALElist.push_back(i);
    }
    for(auto i : studentList){
        if( i.getPerson().getGender() == Person::Gender::MALE){
            pair<Person::Gender, list<Student>> p (i.getPerson().getGender(), MALElist );
            genderMap.insert(p);
        }
        else{
            pair<Person::Gender, list<Student>> p (i.getPerson().getGender(), FEMALElist );
            genderMap.insert(p);
        }
    }
    for(auto i : genderMap ){
        if(i.first == 0) cout<<"MALE:"<<endl;
        else cout<<"FEMALE:"<<endl;

        for( auto j : i.second )
            cout << "       " << j.getFirstnameLastname() << endl;
        cout << endl;
    }

    //Q5
    cout << "Q5:" << endl;
    vector<int>MathVec, EnglishVec, ChineseVec;
    for(auto i : studentList){
        MathVec.push_back(i.getScores().getMath());
        EnglishVec.push_back(i.getScores().getEnglish());
        ChineseVec.push_back(i.getScores().getChinese());
    }
    cout << "Math Average: " << accumulate( MathVec.begin(), MathVec.end(), 0 )/num << endl;
    cout << "English Average: " << accumulate( EnglishVec.begin(), EnglishVec.end(), 0 )/num << endl;
    cout << "Chinese Average: " << accumulate( ChineseVec.begin(), ChineseVec.end(), 0 )/num << '\n' << endl;

    cout << "Math highest: " << *max_element( MathVec.begin(), MathVec.end() ) << endl;
    cout << "English highest: " << *max_element( EnglishVec.begin(), EnglishVec.end() ) << endl;
    cout << "Chinese highest: " << *max_element( ChineseVec.begin(), ChineseVec.end() ) << '\n' << endl;

    cout << "Math lowest: " << *min_element( MathVec.begin(), MathVec.end() ) << endl;
    cout << "English lowest: " << *min_element( EnglishVec.begin(), EnglishVec.end() ) << endl;
    cout << "Chinese lowest: " << *min_element( ChineseVec.begin(), ChineseVec.end() ) << '\n' << endl;

    //Q6
    cout <<"\nQ6:"<<endl;
    map< Subject , map< bool, list<Student> > > failOrNot;
    list<Student> mathFail, mathNotFail, englishFail, englishNotFail, chineseFail, chineseNotFail;

    for(auto s : studentList){
        if( s.getScores().getMath()<60 ){
            mathFail.push_back(s);
        }
        else{
            mathNotFail.push_back(s);
        }
        if( s.getScores().getEnglish()<60 ){
            englishFail.push_back(s);
        }
        else {
            englishNotFail.push_back(s);
        }
        if( s.getScores().getChinese()<60 ){
            chineseFail.push_back(s);
        }
        else {
            chineseNotFail.push_back(s);
        }
     }

    pair< bool, list<Student> > mathF ( false, mathFail);
    pair< bool, list<Student> > mathNF ( true, mathNotFail);
    map< bool, list<Student> > MathMap;
    MathMap.insert(mathF);
    MathMap.insert(mathNF);
    pair< Subject , map< bool, list<Student>>> p1 (Subject::Math, MathMap );
    failOrNot.insert( p1 );

    pair< bool, list<Student> > englishF ( false, englishFail);
    pair< bool, list<Student> > englishNF ( true, englishNotFail);
    map< bool, list<Student> > EnglishMap;
    EnglishMap.insert(englishF);
    EnglishMap.insert(englishNF);
    pair< Subject , map< bool, list<Student>>> p2 (Subject::English, EnglishMap );
    failOrNot.insert( p2 );

    pair< bool, list<Student> > chineseF ( false, chineseFail);
    pair< bool, list<Student> > chineseNF ( true, chineseNotFail);
    map< bool, list<Student> > ChineseMap;
    ChineseMap.insert(chineseF);
    ChineseMap.insert(chineseNF);
    pair< Subject , map< bool, list<Student>>> p3 (Subject::Chinese, ChineseMap );
    failOrNot.insert( p3 );


    for(auto i : failOrNot ){

        if(i.first == 0){
            for( auto j : i.second ){
                if(j.first == false ){
                    cout << "\nMath failed:" << endl;
                    for( auto k : j.second ){
                        cout << "       " << k.getId() << " " << k.getFirstnameLastname() << endl;
                    }
                }
            }
        }
        else if(i.first == 1){
            for( auto j : i.second ){
                if(j.first == false ){
                    cout << "\nEnglish failed:" << endl;
                    for( auto k : j.second ){
                        cout << "       " << k.getId() << " " << k.getFirstnameLastname() << endl;
                    }
                }
            }
        }
        else {
            for( auto j : i.second ){
                if(j.first == false ){
                    cout << "\nChinese failed:" << endl;
                    for( auto k : j.second ){
                        cout << "       " << k.getId() << " " << k.getFirstnameLastname() << endl;
                    }
                }
            }
        }
    }

    //Q7
    cout << "\nQ7:\n" << endl;
    studentList.sort( [](const Student &a, const Student &b){
                     return a.getScores().getAverage() > b.getScores().getAverage(); });
    for(auto i : studentList ){
        cout << i.getId() << " " << i.getFirstnameLastname() << " " << i.getScores().getAverage() << endl;
    }
    return 0;
}
