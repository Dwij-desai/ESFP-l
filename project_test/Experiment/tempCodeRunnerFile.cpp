#include <iostream>
#include <thread>
#include <string>
using namespace std;
int main() {
    string message = "Hello, world!";

    for (char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << std::endl;

    return 0;
}