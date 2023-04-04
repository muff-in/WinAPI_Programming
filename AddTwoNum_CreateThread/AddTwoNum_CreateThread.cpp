#include <iostream>
#include <Windows.h>

using namespace std;

int a[2];

DWORD ThreadFun(LPVOID lpParam) {

    int x, y, result;
    x = a[0];
    y = a[1];

    result = x + y;

    cout << "Addition: " << result << '\n';

    return 0;
}


int main()
{

    cout << "Enter your first num: " << '\n';
    cin >> a[0];
    cout << "Enter your second num: " << '\n';
    cin >> a[1];
    

    DWORD dwThreadID;

    HANDLE hThreadCreation{

        CreateThread(
            NULL,
            0,
            ThreadFun,
            (void*)&a,
            0,
            &dwThreadID
        )
    };


    if (hThreadCreation == NULL) {

        cout << "Thread Creation failed with code: " << GetLastError() << "\n";
    }

    CloseHandle(hThreadCreation);


    system("PAUSE");
    return 0;


}
