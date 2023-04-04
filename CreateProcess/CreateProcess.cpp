#include <iostream>
#include <Windows.h>

using namespace std;

auto main() -> int {

	HANDLE hProcess{};
	HANDLE hThread{};
	STARTUPINFO sI{};
	PROCESS_INFORMATION pI{};
	DWORD dwProcessID{};
	DWORD dwThreadID{};
	ZeroMemory(&sI, sizeof(sI));
	ZeroMemory(&pI, sizeof(pI));


	BOOL bCreateProcess{

		CreateProcessW(
			L"C:\\Program Files\\Notepad++\\notepad++.exe",
			NULL,
			NULL,
			NULL,
			FALSE,
			0,
			NULL,
			NULL,
			&sI,
			&pI	)

	};

	if (bCreateProcess == FALSE) {

		cout << "Create Process failed with error code: " << GetLastError() << '\n';
	}

	cout << "Process ID: " << pI.dwProcessId << '\n';
	cout << "Thread ID: " << pI.dwThreadId << '\n';
	cout << "Get Process ID: " << GetProcessId(pI.hProcess) << '\n';
	cout << "Get Thread ID: " << GetThreadId(pI.hThread) << '\n';


	WaitForSingleObject(

		pI.hProcess,
		INFINITE

	);

	CloseHandle(pI.hProcess);
	CloseHandle(pI.hThread);


	system("PAUSE");

	return 0;

}