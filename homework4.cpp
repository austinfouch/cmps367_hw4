#include <ctime>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void calc_Levenshtein_Distance(const string &a, const string &b)
{
    /* copy strings from args, get lengths, create the arrays */
    string S = a;
    string T = b;
    int M = S.length() + 1;
    int N = T.length() + 1;
    int D[N][M];
    int E[N][M];
    int i,j;
    /* fill arrays */
    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
        {
            D[i][j] = 0;
            E[i][j] = 0;
        }
    for(i = 0; i < M; i++)
        D[0][i] = i;
    for(j = 0; j < N; j++)
        D[j][0] = j;
    /* get the edit distance */
    int x, y, z;
    for(i = 1; i < N; i++)
        for(j = 1; j < M; j++)
            if(S[j-1] == T[i-1])
            {
                D[i][j] = D[i-1][j-1];
            } 
            else
            {
                x = D[i-1][j] + 1;
                y = D[i][j-1] + 1;
                z = D[i-1][j-1] + 1;
                D[i][j] = min(x, min(y, z));
                if(D[i][j] == x)
                    E[i][j] = 1;
                else if(D[i][j] == y)
                    E[i][j] = 2;
                else if(D[i][j] == z)
                    E[i][j] = 0;
            }
    /* creating result strings */
    string S_RESULT = "";
    string T_RESULT = "";
    i = N - 1;
    j = M - 1;
    while(i > 0 || j > 0)
    {
        if(E[i][j] == 0)
        {
            S_RESULT.insert(0, 1, S[j-1]);
            T_RESULT.insert(0, 1, T[i-1]);
            i -= 1;
            j -= 1;
        }
        if(E[i][j] == 1)
        {
            S_RESULT.insert(0, 1, '-');
            T_RESULT.insert(0, 1, T[i-1]);
            i -= 1;
        }
        if(E[i][j] == 2)
        {
            S_RESULT.insert(0, 1, S[j-1]);
            T_RESULT.insert(0, 1, '-');
            j -= 1;
        }
    }
    /* printing results */
    cout << "Aligned Sequences" << endl;
    cout << string(30, '-') << endl;
    cout << S_RESULT << endl;
    cout << T_RESULT << endl;
    cout << string(30, '-') << endl;
    cout << "The minimum edit distance is " << D[N-1][M-1] << endl;
}

int main(int argv, char ** argc) {
    /* start timer */
    clock_t start, end;
    start = clock();
    /* parse files into strings */
    ifstream f1(argc[1]);
    string str1((istreambuf_iterator<char>(f1)),
    			 istreambuf_iterator<char>());
    ifstream f2(argc[2]);
    string str2((istreambuf_iterator<char>(f2)),
    			 istreambuf_iterator<char>());
    /* print and pass results to edit distance calculator */
    cout << "Input Sequences" << endl;
    cout << string(30, '-') << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << string(30, '-') << endl;
    calc_Levenshtein_Distance(str1, str2);
    cout << string(30, '-') << endl;
    /* print time */
    end = clock();
    float diff = ((float)end - (float)start);
    float seconds = diff / CLOCKS_PER_SEC;
    cout << "Completed in " << setprecision(10) << seconds << " seconds." << endl;
    return 0;
}