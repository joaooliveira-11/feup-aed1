#include <iostream>
using namespace std;

int main() {
    bool flag = true;
    char tecla;
    while (flag){
        cout << ("Press a  key: \n 1 : \n Q : Quit \n");
        cin >> tecla;
        switch (tecla) {
            case '1':
                cout << (" Turmas");
                break;
            case 'q':
                flag = false;
                break;
            default:
                cout << (" Press a valid key.");
                break;
        }
    }
}
