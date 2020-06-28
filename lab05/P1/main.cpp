#include <bits/stdc++.h>

using namespace std;


int main()
{
    string str;
    regex reg("\\w+");
    smatch m;
    vector<string>v;
    int flag = 0;
    while(getline(cin, str)){
        if(flag)
            cout << endl;
        flag = 1;
        while(regex_search(str, m, reg )){
            v.push_back(m.str());
            str = m.suffix().str();
        }

        sort(v.begin(), v.end(), [](const string &ls, const string &rs){return ls > rs;});
        for(auto i : v)
                cout << i << endl;
        v.clear();
    }
    return 0;
}
