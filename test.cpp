#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));
    int y = rand();
    string g = "gel";
    cin >> g;
    cout << g<< endl;
    srand(time(NULL));
    string t = "2|300";
    cout << t.substr(t.find('|')+1) << endl;
    cout << y%27<< endl;
    return 0;
}