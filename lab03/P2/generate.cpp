#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("in.in","w", stdout);
    int page = stoi(argv[1]);
    int num = stoi(argv[2]);

    srand( time(NULL) );
    string str ="";
    for(int i = 0; i<page; i++){
        for(int j = 0; j<num ; j++){
            str += '0' + rand()%10;
        }
    }
    cout<<str<<endl;
    
    return 0;
}
