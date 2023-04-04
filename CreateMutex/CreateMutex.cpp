#include <iostream>
#include <Windows.h>



int main()
{
    // Mutex is a locking mechanism
    // Mutex has only one state locked or unlocked
    // Mutex has mutual ownership means those who acquire the lock only can release the lock
    // If Mutex is locked more than once in NON-RECURSIVE, then deadlock will occur.
    // Mutex is only used for Thread synchronization
    // In windows: i. Named Mutex ii. UnNamed Mutex

    
    HANDLE hUnMutex{

        CreateMutex(
            NULL,
            FALSE,
            NULL // Unnamed Mutex
        )
    };

    if (hUnMutex == NULL) {

        std::cout << "Create Mutex failed with error code: " << GetLastError() << '\n';
    }
    

   

    HANDLE hNMutex{

        CreateMutex(
            NULL,
            FALSE,
            L"MYMUTEX" // Named Mutex

            )

    };

    if (hNMutex == NULL) {

        std::cout << "Create MUtex failed with error code: " << GetLastError() << '\n';
    }


    CloseHandle(hUnMutex);
    CloseHandle(hNMutex);


    system("PAUSE");
    return 0;
}

