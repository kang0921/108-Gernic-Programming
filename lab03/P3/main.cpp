#include <iostream>
#include <set>

using namespace std;

class student{
public:
    string name;
    int english, math;

    int total() const{
        return english + math;
    }

    friend bool operator<( const student& ls, const student& rs){
        if(ls.total() == rs.total())
            return ls.name < rs.name;
        return ls.total() < rs.total();
    }

    friend istream &operator>>(istream &s, student &stu){
        s >> stu.name >> stu.english >> stu.math;
        return s;
    }
    friend ostream &operator<<(ostream &s, student stu){
        s << stu.name <<" "<< stu.english <<" "<< stu.math <<endl;
        return s;
    }

};

class RuntimeCmp{
public:
    enum cmp{ LESS, GREATER };
    RuntimeCmp(cmp m = LESS):mode(m){}

    template<typename T>
    bool operator()( const T& ls, const T& rs){
        return mode == LESS ? ls < rs
                            : rs < ls;
    }
private:
    cmp mode;
};

int main()
{
    set<student, RuntimeCmp> setA(RuntimeCmp::LESS);
    set<student, RuntimeCmp> setB(RuntimeCmp::GREATER);

    int N;
    cin>>N;
    student s;
    while(N--){
        cin >> s;
        setA.insert(s);
        setB.insert(s);
    }
    cout<<"Set A:"<<endl;
    for(auto i : setA)
        cout<<i;
    cout<<endl;

    cout<<"Set B:"<<endl;
    for(auto i : setB)
        cout<<i;

    return 0;
}


