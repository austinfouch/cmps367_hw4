#include <ctime>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
using namespace std;

void fileToString()

void calc_Levenshtein_Distance(const &string a, const &string b)
{

}

int main(int argv, char ** argc) {
    int start = clock();

    /* parse files into strings */
    ifstream f1(argc[1]);
    string str1((istreambuf_iterator<char>(f1)),
    			 istreambuf_iterator<char>());
    ifstream f2(argc[2]);
    string str2((istreambuf_iterator<char>(f2)),
    			 istreambuf_iterator<char>());
    cout << str1 << endl;
    cout << str2 << endl;
    calc_Levenshtein_Distance(str1, str2);

    int t = clock() - start;
    cout << "Completed in " <<((float)t)/CLOCKS_PER_SEC << " seconds." << endl;;
}