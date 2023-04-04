// IPC -> It is a mechanism which is used for communicating between different processes.
// PIPE -> It is a IPC mechanism which is used for communicating the local process or different processes.
// It has two types:
// 1. Anonymous Pipe or Unnamed Pipe
// 2. Named Pipe

// UnNamed or Anonymous PIPE
// 1. Used for one way communication or unidirectional
// 2. Anonymous pipe is local to the system.
// 3. Anonymous pipe can not be used over Network.
// 4. At the one end we can read/write and from the other end we can read/write.
//		i.e. From one end we can write and from another end we can read.


#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

	// Define variables to hold the pipe read and write handles
	HANDLE hRead{};
	HANDLE hWrite{};

	// Define a character buffer and its size for the data to be sent over the pipe
	char szBuffer[512]{ "Hello PIPE WORLD" };
	DWORD dwBufferSize{ sizeof(szBuffer) };

	// Define variables for error checking and to hold the number of bytes read/written
	BOOL bReadFile{};
	BOOL bWriteFile{};
	DWORD dwNoBytesWrite{};
	DWORD dwNoBytesRead{};

	// Create a function pointer to the CreatePipe function
	BOOL WINAPI bPipeCreation{

		// Call the CreatePipe function to create a pipe and store the read/write handles
		CreatePipe(
			&hRead,
			&hWrite,
			NULL,
			dwBufferSize
			)

	};

	// Check if the pipe creation was successful
	if (bPipeCreation == FALSE) {

		// Print an error message with the GetLastError() code
		cout << "Pipe Creation failed with error code: " << GetLastError() << endl;
	}

	// Write the contents of the buffer to the pipe
	bWriteFile = WriteFile(
		hWrite,
		szBuffer,
		dwBufferSize,
		&dwNoBytesWrite,
		NULL
	);

	// Read data from the pipe and store it in the buffer
	bReadFile = ReadFile(
		hRead,
		szBuffer,
		dwBufferSize,
		&dwNoBytesRead,
		NULL
	);

	// Print the data read from the pipe
	cout << "Read from Pipe: " << szBuffer << endl;

	// Close the pipe handles
	CloseHandle(hWrite);
	CloseHandle(hRead);

	// Wait for user input before exiting the program
	system("PAUSE");

	// Return 0 to indicate successful program execution
	return 0;
}
