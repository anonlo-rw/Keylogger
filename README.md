# Keylogger for Windows
A hidden and undetectable keylogger written in C++ (works in both Visual C++ and MinGW G++)

# Features
- Logs most keys in a text file which is stored in the %APPDATA% folder as default
- Sends log file over to a specfied FTP server
- Ability to run in the background acting as a system process

# Usage
- If using MinGW (G++): g++ keylogger.cpp -o keylogger -lwininet
- It is built to run in the background of a target machine and logs most keys that are pressed and after a specifed amount of time, sent over to the FTP server
- Make sure when deploying to change the FTP contanst variables to an active FTP server

# Disclaimer

- This program is for educational purposes only! Use at your own risk.
