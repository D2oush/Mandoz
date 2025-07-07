// no_net.h - Disable all network and external execution functions

#ifndef NO_NET_H
#define NO_NET_H

// ========== Block POSIX/Linux networking ==========

#define socket(...)        -1
#define connect(...)       -1
#define send(...)          -1
#define sendto(...)        -1
#define recv(...)          -1
#define recvfrom(...)      -1
#define bind(...)          -1
#define listen(...)        -1
#define accept(...)        -1
#define gethostbyname(...) NULL
#define getaddrinfo(...)   EAI_FAIL
#define inet_ntoa(...)     NULL
#define inet_addr(...)     ((in_addr_t)-1)

// ========== Block Windows-specific internet APIs ==========

#define InternetOpen(...)         NULL
#define InternetConnect(...)      NULL
#define HttpOpenRequest(...)      NULL
#define HttpSendRequest(...)      FALSE
#define InternetReadFile(...)     FALSE
#define InternetCloseHandle(...)  FALSE
#define URLDownloadToFile(...)    E_FAIL

// ========== Block external program execution ==========

#define system(...)               -1
#define ShellExecute(...)         NULL
#define ShellExecuteA(...)        NULL
#define ShellExecuteW(...)        NULL
#define CreateProcess(...)        FALSE
#define CreateProcessA(...)       FALSE
#define CreateProcessW(...)       FALSE
#define WinExec(...)              0
#define _wsystem(...)             -1
#define popen(...)                NULL
#define _popen(...)               NULL
#define _wpopen(...)              NULL

// ========== Optional: Disable file/network-based logging (paranoid mode) ==========
// Uncomment the following lines if you want to prevent any accidental output

// #define fopen(...)               NULL
// #define freopen(...)             NULL
// #define printf(...)              ((void)0)
// #define fprintf(...)             ((void)0)
// #define puts(...)                ((void)0)

#endif // NO_NET_H
