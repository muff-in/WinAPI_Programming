#include <iostream>
#include <Windows.h>

using namespace std;

DWORD WINAPI ThreadFun(LPVOID lpParam) {

	return 0;
}

auto main() -> int {

	// Thread is independent entity which runs within a process.
	// Thread share some resources to the process except STACK & Register
	// By default Thread size in Win is 1MB of stack.
	// We can create MAX 2048 threads in a process.
	// Terminating a Thread does not necessarily remove the thread object from the OS
	// A thread object is deleted when the last handle to the thread is closed

	DWORD ThreadID{};

	HANDLE hThreadCreation{

		CreateThread(
			NULL,
			0,
			ThreadFun,
			NULL,
			0,
			&ThreadID
		)

	};

	if (hThreadCreation == NULL) {

		cout << "Thread Creation failed with error code: " << GetLastError() << '\n';
	}


	cout << "Thread ID: " << ThreadID << '\n';

	CloseHandle(hThreadCreation);

	system("PAUSE");
	return 0;
}