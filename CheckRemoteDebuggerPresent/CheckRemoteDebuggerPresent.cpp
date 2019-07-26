// CheckRemoteDebuggerPresent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <debugapi.h>
#include <processthreadsapi.h>

int main()
{
	BOOL checked;
	if (CheckRemoteDebuggerPresent(GetCurrentProcess(), &checked) == 0)
	{
		std::cout << "Fialed in CheckRemoteDebuggerPresent: " << GetLastError() << std::endl;
		goto final_step;
	}
	else
	{
		if(checked)
			std::cout << "Hello Debugger!\n";
		else
			std::cout << "No Debugger!\n";
	}

final_step:
	getchar();
	return 0;
}
