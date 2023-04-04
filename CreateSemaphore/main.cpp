// Semaphore
// Semaphore is an integer Variable. (Mutex - Object)
// Semaphore is a Signaling Mechanism. (Mutex - Locking)
// Semaphore Value can be modified by WAIT & SIGNAL Operation. (Mutex - Either Locked or Unlocked)
// Semaphore has two types (Mutex is not categorized)
// 1. Binary
// 2. Counting
// Semaphore value modified by any process by Acquiring or Releasing the Semaphore.
// (Mutex- Those who acquired the lock can only release the lock. i.e Mutual Ownership.

#include <iostream>
#include <Windows.h>

using namespace std;

auto main() -> int {


	HANDLE WINAPI hUnSemaphoreCreation{

		CreateSemaphore(
			NULL,
			1,
			1,
			NULL // UNnamed Semaphore
		)

	};
	 
	if (hUnSemaphoreCreation == NULL) {

		cout << "Semaphore Creation failed with error code: " << GetLastError() << endl;
	}


	HANDLE WINAPI hNSemaphoreCreation{

		CreateSemaphore(
			NULL,
			1,
			1,
			L"MySemaphore"
		)
	};

	if (hNSemaphoreCreation == NULL) {

		cout << "Semaphore Creation failed with error code: " << GetLastError() << endl;
	}

	CloseHandle(hUnSemaphoreCreation); 
	CloseHandle(hNSemaphoreCreation);

	system("PAUSE");
	return 0;
}