#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{

    cout << "Enter the path where you want to make the hardlink: ";
    wstring sourcePath{};
    getline(wcin, sourcePath);

    LPCWSTR path1 = sourcePath.c_str();

    cout << "Enter the path of the file you want to make the hardlink of:  \n";
    wstring sourcePath2{};
    getline(wcin, sourcePath2);

    LPCWSTR path2 = sourcePath2.c_str();

    
    BOOL hardLink{

        CreateHardLink(

            path1, //   lpFileName
            path2, // lpExistingFileName
            NULL // lpSecurityAttributes
        )

    };


    if (hardLink == FALSE) {

        cout << "Error while creating the hard link with error code: " << GetLastError() << '\n';
    }

    system("PAUSE");

}
