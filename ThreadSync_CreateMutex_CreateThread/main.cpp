// Thread Synchronization
// 1. Printing Odd and Even number using Thread and Mutex
// 2. CreateMutex
// 3. Create Two Threads
// 4. Create Thread Function. In Thread Function use WaitForSingleObject and ReleaseMutex API
// 5. In Main Function Use CloseHandle API

#include <iostream>
#include <Windows.h>

using namespace std;

int gcount{ 1 };

HANDLE hMutex{};

DWORD WINAPI ThreadFunctionEven(LPVOID lpParam) {

	while (gcount < 10) {

		WaitForSingleObject(hMutex, INFINITE);

		if (gcount % 2 == 0) {
			
			cout << "Even numbers: " << gcount++ << "\n";

		}

		ReleaseMutex(hMutex);

	}


	return 0;
}

DWORD WINAPI ThreadFunctionOdd(LPVOID lpParam) {

	while (gcount < 10) {

		WaitForSingleObject(hMutex, INFINITE);

		if (gcount % 2 == 1) {

			cout << "Odd numbers: " << gcount++ << "\n";

		}

		ReleaseMutex(hMutex);

	}

	return 0;
}



auto main() -> int {


	hMutex = CreateMutex(

		NULL,
		FALSE,
		NULL

	);

	HANDLE hThreadCreation1{

		CreateThread(
			NULL,
			0,
			ThreadFunctionEven,
			NULL,
			0,
			NULL
			)

	};

	HANDLE hThreadCreation2{

		CreateThread(
			NULL,
			0,
			ThreadFunctionOdd,
			NULL,
			0,
			NULL
		)

	};

	CloseHandle(hThreadCreation1);
	CloseHandle(hThreadCreation2);

	system("PAUSE");
	return 0;
}