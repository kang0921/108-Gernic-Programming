#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    regex reg ("\\+\\(\\d{3}\\)-\\d{1}-\\d{4}-(\\d{4})");

    while(getline(cin, str)){
        bool found = regex_search(str, reg);
        if(found)
            cout << regex_replace(str, reg, "+(XXX)-X-XXXX-\$1") << endl;
        else cout << str << endl;
    }

    return 0;
}
