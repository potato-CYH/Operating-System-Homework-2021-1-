#include <stdio.h>
#include <Windows.h>

DWORD WINAPI Thread1(PVOID pArg);
DWORD WINAPI Thread2(PVOID pArg);

DWORD WINAPI Thread1(PVOID pArg) {
    int i = 1;
    while (i++ < 20) {
        printf("A");
        printf("B");
        printf("C  ");
    }

    return 0;
}

DWORD WINAPI Thread2(PVOID pArg) {
    int i = 1;
    while (i++ < 20) {
        printf("1");
        printf("2");
        printf("3  ");
    }
    return 0;
}
int main() {
    HANDLE  hThread1, hThread2;
    DWORD dwThreadID1 = 0, dwThreadID2 = 1;
    int i = 1;
    
    hThread1 = CreateThread(NULL, 0, Thread1, (PVOID)0, 0, &dwThreadID1);
    hThread2 = CreateThread(NULL, 0, Thread2, (PVOID)0, 0, &dwThreadID2);
    CloseHandle(hThread1);
    CloseHandle(hThread2);
    while (i++ < 3) {
        printf("m");
        printf("m");
        printf("m");
    }
    
    return 0;
}