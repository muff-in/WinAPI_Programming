#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    cout << "Enter the path of the file you want to rename or move: ";
    wstring path{};
    getline(wcin, path);

    LPCWSTR pathName = path.c_str();

    cout << "Enter the path where you want to save the renamed or moved file: ";

        wstring path2{};
        getline(wcin, path2);

        LPCWSTR pathname2 = path2.c_str();


    bool bFile{};

    bFile = MoveFile(
        pathName,
        pathname2
    );

    if (bFile == FALSE) {

        cout << "Moving File failed with error code:  " << GetLastError() << '\n';
    }
    
    else {

        cout << "Moving File Successful\n";
    }

    system("PAUSE");

    
}

