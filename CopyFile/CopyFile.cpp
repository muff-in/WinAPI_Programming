#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    wcout << "Enter the path of file you want to copy: ";
    wstring path{};
    getline(wcin, path);

    LPCWSTR lpPathName = path.c_str();

    cout << "Enter the path where you want to copy: ";
    wstring path2{};
    getline(wcin, path2);

    LPCWSTR lpPathName2 = path2.c_str();
    
    
    bool bFile;

    bFile = CopyFile(
        lpPathName,
        lpPathName2,
        TRUE
    );

    if (bFile == FALSE) {

        cout << "File COpy failed with error no. = " << GetLastError() << '\n';
    }

    else {

        cout << "Copy File successful.\n";
    }



    system("PAUSE");


    
}

