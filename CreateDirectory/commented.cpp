#include <Windows.h>   // Windows API header file
#include <iostream>    // standard input/output stream header file
#include <string>      // string header file

using namespace std;

int main()
{
    // Print a message to the console asking the user to choose between creating or removing a directory
    cout << "Create Directory or Remove Directory: Press c to create and r to remove \n";

    // Declare a variable to hold the user's input
    char userInput{};
    // Read the user's input from the console
    cin >> userInput;

    // If the user wants to create a directory
    if (userInput == 'c' || userInput == 'C') {
        // Print a message to the console asking for the path to create the directory
        wcout << L"Enter the path to create a Directory: \n";
        // Declare a variable to hold the path
        wstring path;
        // Ignore the newline character left in the input stream by the previous input operation
        wcin.ignore();
        // Read the path from the console
        getline(wcin, path);

        // Convert the wstring to a wide-character C-style string
        LPCWSTR lpPathName = path.c_str();

        // Attempt to create the directory
        bool bDir;
        bDir = CreateDirectoryW(lpPathName, NULL);

        // If the directory creation fails, print an error message with the error code
        if (bDir == FALSE) {
            wcout << L"Create Directory Failed & error no = " << GetLastError() << '\n';
        }
        // If the directory creation succeeds, print a success message
        else {
            wcout << L"Create Directory Successful" << '\n';
        }
    }

    // If the user wants to remove a directory
    if (userInput == 'r' || userInput == 'R') {
        // Print a message to the console asking for the path to remove the directory
        wcout << L"Enter the path to remove a Directory: \n";
        // Declare a variable to hold the path
        wstring path2;
        // Ignore the newline character left in the input stream by the previous input operation
        wcin.ignore();
        // Read the path from the console
        getline(wcin, path2);

        // Convert the wstring to a wide-character C-style string
        LPCWSTR lpPathName2 = path2.c_str();

        // Attempt to remove the directory
        bool rDir;
        rDir = RemoveDirectoryW(lpPathName2);

        // If the directory removal fails, print an error message with the error code
        if (rDir == FALSE) {
            wcout << L"RemovedDirectory Failed and Error no = " << GetLastError() << '\n';
        }
        // If the directory removal succeeds, print a success message
        else {
            wcout << L"Removed Directory Success\n";
        }
    }

    // Pause the console so the user can read the output
    system("PAUSE");
    // Return 0 to indicate successful execution of the program
    return 0;
}

// Create Directory code which is commented by ChatGPT to understand

// Interesing Note: If you remove a directory using the RemoveDirectory function, the directory must be empty. If the directory is not empty, the function fails and GetLastError returns ERROR_DIR_NOT_EMPTY.
// and if you want to remove a directory with files in it, you can use the SHFileOperation function.
// If empty directory is removed using RemoveDirectory function, it does not go in the Recycle Bin. It is permanently deleted.