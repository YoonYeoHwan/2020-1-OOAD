#include "AdminCheck.h"

using namespace std;

bool AdminCheck::checkAdmin() {
    string password;
    string inputPassword;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n관리자 계정에 로그인하기 위해서는 비밀번호를 입력해주십시오.\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> inputPassword;
    cout << "------------------------------------------------------------" << endl;
    fstream openFile;
    openFile.open("admin.txt");
    getline(openFile, password);
    if(password.compare(inputPassword) == 0) {
        cout << "\n관리자 계정에 로그인 되셨습니다.\n" << endl;
        cout << "------------------------------------------------------------" << endl;
        return true;
    }
    else {
        cout << "\n비밀번호가 일치하지 않습니다.\n" << endl;
        cout << "------------------------------------------------------------" << endl;
        return false;
    }
}