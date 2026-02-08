#include <Windows.h>
#include <comdef.h>
#include <iostream>

// Requires linking against Excel type libraries

int main() {
    CoInitialize(NULL);
    CLSID clsid;
    CLSIDFromProgID(L"Excel.Application", &clsid);
    IDispatch* pXlApp;
    CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_IDispatch, (void**)&pXlApp);

    // Automation code to open workbook, read cells, etc.

    CoUninitialize();
    return 0;
}
