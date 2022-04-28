#include <iostream>

using namespace std;

bool continue_() {
    int x;
    cin >> x;
    return (x == 0 ? true : false);
}

int main() {

    cout << "B8" << endl << "B1" << endl;
    if (!continue_()) return 0;
    cout << "G1" << endl;
    if (!continue_()) return 0;
    cout << "G7" << endl;
    if (!continue_()) return 0;
    cout << "A7" << endl;
    if (!continue_()) return 0;
    cout << "H7" << endl;
    if (!continue_()) return 0;
    cout << "A7" << endl;
    if (!continue_()) return 0;

    return 0;
}