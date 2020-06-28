D#include <bits/stdc++.h>

using namespace std;

class data
{
public:
    friend istream &operator>>(istream &input, data &d){
        input >> d.name >> d.grade >> d.number;
        return input;
    }

    friend ostream &operator<<(ostream &output, data &d){
        output << "Room No.[" << d.number <<"]:[ "<< d.name << ", " << d.grade << " ]" ;
        return output;
    }

    friend bool operator<( const data& ls, const data & rs){
        if(ls.number==rs.number)
            return ls.name < rs.name;
        return ls.number < rs.number;
    }

    data(string _name, string _grade, int _number)
        :name(_name), grade(_grade), number(_number) {};
    string getName(){
        return name;
    }
    string getGrade(){
        return grade;
    }
    int getNumber(){
        return number;
    }


private:
    string name;
    string grade;
    int number;
};

int main()
{
    string name, grade, ignore;
    set<data>s[5];
    int num, cases;
    vector<data>V;
    while(cin>>cases){
        for(int i = 0; i<cases; i++){
            getline(cin, ignore);
            cin >> name >> grade >> num;
            V.push_back(data(name, grade, num));
        }

        for(size_t i = 0; i<V.size(); i++)
        {
            int tmp = V[i].getNumber();
            switch(tmp/100)
            {
            case 1 : case 2 :
                s[0].insert( V[i] );
                break;
            case 3 : case 4 :
                s[1].insert( V[i] );
                break;
            case 5 : case 6 :
                s[2].insert( V[i] );
                break;
            case 7 : case 8 :
                s[3].insert( V[i] );
                break;
            case 9 :
                s[4].insert( V[i] );
                break;
            default:
                break;
            }
        }
        for(int j = 0; j<5; j++){
            if(j!=4)
                cout <<"[ "<< 2*j+1 <<" floor ~ " << 2*j+2 <<" floor ]"<<endl;
            else
                cout << "[ "<< 2*j+1 <<" floor ]" <<endl;

            for(auto i: s[j]){
                cout << i << endl;
            }
            cout << endl;
        }

        int q_cases;
        size_t q_grade;
        string q_name;
        vector<data> find_queue;
        while(cin>>q_cases){S
            while(q_cases--){
                cin >> q_name >> q_grade;
                for (size_t j = 0; j < 5; ++j){
                    set<data>::iterator find_room_num;
                    find_room_num = find_if(s[j].begin(), s[j].end(), [&q_name, &q_grade](data s)->bool{
                                                                        string str_q_grade;
                                                                        switch(q_grade){
                                                                            case 1 :str_q_grade = "freshman"; break;
                                                                            case 2 :str_q_grade = "sophomore"; break;
                                                                            case 3 :str_q_grade = "junior"; break;
                                                                            case 4 :str_q_grade = "senior"; break;
                                                                            default :str_q_grade = "graduate_school"; break;
                                                                        }
                                                                        return q_name == s.getName()
                                                                                && str_q_grade == s.getGrade();}
                    );

                    if (find_room_num != s[j].end()){
                        find_queue.push_back(*find_room_num);
                        break;
                    }
                }
                if (find_queue.size() != 0)
                    cout << find_queue.back().getName() << " lives in Room No.[ " << find_queue.back().getNumber() <<" ]"<< endl;
                else
                    cout << "Not Found." << endl;
                find_queue.clear();
                cout << endl;
            }
        }
    }

    return 0;
}
