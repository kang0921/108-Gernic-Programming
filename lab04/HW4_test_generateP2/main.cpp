#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while(cin>>N){
        string str[N+5], in, ignore;
        for(int i = 0; i<N; i++){
            cin>>in>>ignore>>ignore;
            str[i] = in;
        }
        int num;
        while(cin >> num){
           cout << num << endl;
            srand( time(NULL) );
            for(int i = 0; i<num; i++){
                cout << str[rand()%N] << " " << (rand()%5)+1 << endl;
            }
        }
    }
    return 0;
}
