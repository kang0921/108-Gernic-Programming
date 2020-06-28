#include <bits/stdc++.h>

using namespace std;

void findAllOccurances(vector<size_t> &v, string str, string n1);
void findPermutations(int patt[], int n, string str);
string int_to_string(int patt[], int n);
void display(int patt[], int n);

int main()
{

    string str;
    int page, num, ques_page, ques_n, N;
    cin >> page >> num >> str;
    vector<int> pattern;

    while(cin >> ques_page >> ques_n >> N ){
        char c = str[ num*(ques_page-1) + ques_n-1 ];
        string n1 (1, c);
        pattern.push_back(c-'0');

        vector<size_t> vec;
        findAllOccurances(vec, str, n1);

        int total = 0;
        for(size_t pos : vec){
            total++;
        }

        printf("%c %d %d\n", c, total, total%N);
    }

    int patt[pattern.size()];
    for(int i = 0; i<pattern.size(); i++){
        patt[i] = pattern[i];
    }
    int n = sizeof(patt) / sizeof(patt[0]);
    cout << int_to_string( patt, n ) <<" ";
    findPermutations( patt, n, str );
    
    return 0;
}

void findAllOccurances(vector<size_t> & vec,string str, string n1)
{
    size_t pos = str.find(n1);
    while( pos != string::npos)
    {
        vec.push_back(pos);
        pos = str.find( n1, pos+n1.size() );
    }

}

void findPermutations(int patt[], int n, string str)
{
    sort(patt, patt + n);
    do{

        string dis = int_to_string(patt, n);
        vector<size_t> vec;
        findAllOccurances(vec, str, dis);
        int total = 0;
        for(size_t pos : vec){
            total++;
        }
        if(total!=0)
            cout<<total<<endl;

    }while(next_permutation(patt, patt+n));
}

void display(int patt[], int n)
{
    for(int i = 0 ; i < n ; i++ ){
        cout << patt[i] <<" ";
    }
    cout << endl;
}

string int_to_string(int patt[], int n)
{
    string str = "";
    for(int i = 0; i < n ; i++ ){
        str += to_string( patt[i] );
    }
    return str;
}
