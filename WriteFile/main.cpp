#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{

    // Creating a File
    cout << "Enter the path with your file name you want to create: ";
    wstring sourcePath{};
    getline(wcin, sourcePath);

    LPCWSTR pathName = sourcePath.c_str();

    HANDLE hFile{
        CreateFile(pathName,
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

        cout << "File Creation Successful." << '\n';
    }

    // Writing to the file


    cout << "What you want to write in the text file: ";
    char chBuffer[100]{};
    cin.getline(chBuffer, 100);
    DWORD dwNoByteToWrite = strlen(chBuffer);
    DWORD dwNoByteWritten{};
    


    BOOL bFile{
        WriteFile(

            hFile,
            chBuffer,
            dwNoByteToWrite,
            &dwNoByteWritten,
            NULL
     )
    };

    if (bFile == FALSE) {

        cout << "Writing in the file failed with error no: " << GetLastError() << '\n';
    }

    else {

        cout << "Writing in the file successful.\n";
    }


    CloseHandle(hFile);


    system("PAUSE");


}
