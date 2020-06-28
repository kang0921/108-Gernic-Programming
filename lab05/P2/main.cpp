#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int flag = 0;
    while(getline(cin, str)){
        if(flag)
            cout<<'\n';
        flag = 1;
        smatch m;
        bool found = regex_search(str, m, regex("(\\d{4})[-](\\d{4})[-](\\d{4})[-](\\d{4})"));
        if(!found)
            cout << "FALSE" << endl;
        else{
            int n = 0;
            for(int i = 1; i<5; i++)
                n += stoi ( m.str(i) );
            cout << "TRUE " << n << endl;
        }
    }
    return 0;
}
