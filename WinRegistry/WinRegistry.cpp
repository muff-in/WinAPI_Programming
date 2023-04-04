#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{




    HKEY hKey;
    DWORD dwData{ 1234 };


    LONG lReg{

        RegCreateKeyEx(

            HKEY_LOCAL_MACHINE,
            L"Software\\Test\\nenee",
            0,
            NULL,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS | KEY_WOW64_64KEY,
            NULL,
            &hKey,
            NULL

        )
    };



    if (lReg != ERROR_SUCCESS) {

        cout << "Creating registry Key failed with error code: " << GetLastError() << '\n';
    }


    LONG lRegValue{

        RegSetValueEx(
            hKey,
            L"VALUE",
            NULL,
            REG_DWORD,
            (LPBYTE)&dwData,
            sizeof(dwData)
        )
    };


    if (lRegValue != ERROR_SUCCESS) {

        cout << "Set Value to the Registry failed with error code: " << GetLastError() << '\n';
    }



    RegCloseKey(hKey);

    system("PAUSE");

    return 0;
    

}
