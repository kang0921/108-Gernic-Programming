#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
    unsigned seed = time(NULL);
    srand(seed);

    freopen("in.in","w", stdout);
    char ch[8] {'A', 'a', 'C', 'c', 'G', 'g', 'T', 't'};
    int N = stoi(argv[1]);
    int M = stoi(argv[2]);
    int D = stoi(argv[3]);
    
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << ch[rand()%8];
        }
        cout << " ";
        for(int k = 0; k < D; k++) {
            cout << ch[rand()%8];
        }
        cout<<endl;
    }
    fclose(stdout);

    
}
