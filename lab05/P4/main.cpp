#include <bits/stdc++.h>

using namespace std;

int main()
{
	regex reg("\\d*(\\.|[eE][+-]*)\\d*([eE]{1}[+-]*\\d*|[eE]{0})[flFL]?");
	string str;
	smatch sm;

	while(getline(cin,str)){
		if (regex_match(str, sm, reg)){
			cout << "TRUE\n" << endl;
		}
		else{
			cout << "FALSE" << endl;
			while (regex_search(str, sm, reg)){
				cout << sm[0].str() << endl;
				str = sm.suffix().str();
			}
			cout << endl;
		}
	}
	return 0;

}
