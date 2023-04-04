// SoftLink.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
  
	cout << "Of what you want to make shortcut File(f) or Directory(d), press f or d: \n";
	char userInput1{};
	cin >> userInput1;
	cin.ignore(); 

	if (userInput1 == 'f' || userInput1 == 'F') {

		cout << "Enter Path of the file you want to create shortcut of: ";
		wstring fpath1{};
		getline(wcin, fpath1);

		LPCWSTR fpathName1 = fpath1.c_str();


		cout << "Enter path where you want to create the shortcut with the file name also: ";
		wstring fpath2{};
		getline(wcin, fpath2);

		LPCWSTR fpathName2 = fpath2.c_str();

		BOOL bSoft1{
			CreateSymbolicLink(
				fpathName1, //
				fpathName2, //
				0 //
			)
		};


		if (bSoft1 == FALSE) {

			cout << "Creating soft link for file failed with error code: " << GetLastError() << '\n';
		}

		if (GetLastError() == 1314) {

			cout << "You need admin privilege \n";
		}

	}
	else if (userInput1 == 'd' || userInput1 == 'D') {


		cout << "Enter Path of the Directory you want to create shortcut of: ";
		wstring dpath1{};
		getline(wcin, dpath1);

		LPCWSTR dpathName1 = dpath1.c_str();


		cout << "Enter path where you want to create the shortcut with the Directory name also: ";
		wstring dpath2{};
		getline(wcin, dpath2);

		LPCWSTR dpathName2 = dpath2.c_str();

		BOOL bSoft2{
			CreateSymbolicLink(
				dpathName1, //
				dpathName2, //
				0x1 //
			)
		};

		if (bSoft2 == FALSE) {

			cout << "Creating soft link for directory failed with error code: " << GetLastError() << '\n';
		}


		if (GetLastError() == 1314) {

			cout << "You need admin privilege \n";
		}


	}
	else {

		cout << "You didn't enter valid input.";
	}






	system("PAUSE");

	return 0;
}