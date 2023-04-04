#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << "Enter the path of the file: ";
	wstring sourcePath{};
	getline(wcin, sourcePath);

	LPCWSTR pathName = sourcePath.c_str();

	HANDLE hFile{

		CreateFile(
			pathName,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
			)
	};

	if (hFile == INVALID_HANDLE_VALUE) {

		cout << "Error opening the file with code: " << GetLastError() << '\n';
	}


	char chBuffer[200]{};
	DWORD NumberOfBytesRead{};


	BOOL rFile{

		ReadFile(
			hFile,
			chBuffer,
			sizeof(chBuffer),
			&NumberOfBytesRead,
			NULL
		)
	};

	if (rFile == FALSE)
	{
		cout << "Error reading the file with error code: " << GetLastError() << '\n';

	}

	

	cout << "Data: " << chBuffer << '\n';

	CloseHandle(hFile);

	system("PAUSE");
}