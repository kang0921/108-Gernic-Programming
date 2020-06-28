#include <bits/stdc++.h>
using namespace std;

void findAllOccurances(vector<size_t> &v, string sour, string dis);

int main()
{
    string sour, dis;
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    while(cin >> sour >> dis){
        transform(sour.begin(), sour.end(), sour.begin(), ::toupper);
        transform(dis.begin(), dis.end(), dis.begin(), ::toupper);
        printf("%d %d %d %d\n", count_if(sour.begin(), sour.end(), [](char ch){return ch=='A';} ),
                                count_if(sour.begin(), sour.end(), [](char ch){return ch=='C';} ),
                                count_if(sour.begin(), sour.end(), [](char ch){return ch=='G';} ),
                                count_if(sour.begin(), sour.end(), [](char ch){return ch=='T';} ));

        vector<size_t> vec;
        findAllOccurances(vec, sour, dis);

        int total = 0;
        for(size_t pos : vec){
            cout << pos <<" ";
            total++;
        }
        cout<<total<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

void findAllOccurances(vector<size_t> & vec,string sour, string dis)
{
    size_t pos = sour.find(dis);
    while( pos != string::npos){
        vec.push_back(pos);
        pos = sour.find( dis, pos+dis.size() );
    }
}

