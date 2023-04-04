#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Create Directory or Remove Directory: Press c to create and r to remove \n";

    char userInput{};
    cin >> userInput;

    if (userInput == 'c' || userInput == 'C') {
        wcout << L"Enter the path to create a Directory: \n";
        wstring path;
        wcin.ignore(); 
        getline(wcin, path);

        LPCWSTR lpPathName = path.c_str();

        bool bDir;
        bDir = CreateDirectoryW(lpPathName, NULL);

        if (bDir == FALSE) {
            wcout << L"Create Directory Failed & error no = " << GetLastError() << '\n';
        }
        else {
            wcout << L"Create Directory Successful" << '\n';
        }
    }

    if (userInput == 'r' || userInput == 'R') {
        wcout << L"Enter the path to remove a Directory: \n";
        wstring path2;
        wcin.ignore(); 
        getline(wcin, path2);

        LPCWSTR lpPathName2 = path2.c_str();

        bool rDir;
        rDir = RemoveDirectoryW(lpPathName2);

        if (rDir == FALSE) {
            wcout << L"RemovedDirectory Failed and Error no = " << GetLastError() << '\n';
        }
        else {
            wcout << L"Removed Directory Success\n";
        }
    }

    system("PAUSE");
    return 0;
}
