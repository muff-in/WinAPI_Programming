#include <iostream>
#include <Windows.h>

using namespace std;

auto main() -> int {


	HANDLE WINAPI hOpenASemaphore{

			OpenSemaphore(
				SEMAPHORE_ALL_ACCESS,
				FALSE,
				L"MySemaphore")
	};

	if (hOpenASemaphore == NULL) {

		cout << " Open Semaphore Creation Failed with error code: " << GetLastError() << endl;
	}



	CloseHandle(hOpenASemaphore);

	system("PAUSE");
	return 0;
}