#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the path with your file name you want to create: ";
    wstring sourcePath{};
    getline(wcin, sourcePath);

    LPCWSTR pathName = sourcePath.c_str();

    HANDLE hFile { 
        CreateFile  (pathName, 
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,
        NULL
        ) 
    };

    if (hFile == INVALID_HANDLE_VALUE) {

        cout << "File Creation failed with error code: " << GetLastError() << '\n';
    }

    else {

        cout << "File Creation Successful.";
    }


    CloseHandle(hFile);
     


}
