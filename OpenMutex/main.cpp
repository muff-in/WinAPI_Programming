#include <iostream>
#include <Windows.h>

using namespace std;

int main() {


	HANDLE hOpenMutex{

		OpenMutex(
			MUTEX_ALL_ACCESS,
			FALSE,
			L"MYMUTEX"
		)
	};


	if (hOpenMutex == NULL) {


		cout << "Open Mutex failed with error code: " << GetLastError() << "\n";
	}


	CloseHandle(hOpenMutex);


	system("PAUSE");
	return 0;
}