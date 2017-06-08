#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int start = clock();

    for ( int i = 0; i < 10000; i++ ) {
        cout << ".";
    }
    cout << endl;

    int t = clock() - start;
    cout << "Completed in " <<((float)t)/CLOCKS_PER_SEC << " seconds." << endl;;
}