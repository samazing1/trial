#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "cal-new.cpp"
#include <fstream>
#include <string>

using namespace std;
int main(){
    ifstream fileInputAdmin;
    int arr[2]; // { R, W }

    pid_t c_pid = fork();
    if (pipe(arr) != 0){
        return -1;
    }
    if (c_pid == -1){
        cerr << "fork";
        exit(EXIT_FAILURE);
    }else if (c_pid > 0){ //parent process
        char* param[] = {"cal.exe", NULL};
        cout << "Admin: " << c_pid << ", "<< getpid() << endl;
        fileInputAdmin.open("cal.in");
        string adminCalType;
        int adminNumberLines, counter, x, y;
        counter = adminNumberLines;

        fileInputAdmin >> adminNumberLines;
        write(arr[1], &adminNumberLines , 256);

        while(counter != 0) {
            fileInputAdmin >> adminCalType >> x >> y;
            write(arr[1], adminCalType.c_str() , 256);
            write(arr[1], &x, 256);
            write(arr[1], &y, 256);
            counter--;
        }

        wait(NULL);
    }else{//child process
        int adminReadNumberLines, readCounter, x, y;
        readCounter = adminReadNumberLines;
        read(arr[0], &adminReadNumberLines, 256);

        while(readCounter != 0){
            char* readInputLine;
            read(arr[0], readInputLine, 256);
            read(arr[0], &x, 256);
            read(arr[0], &y, 256);
            calNew(readInputLine, x, y);

            readCounter--;
        }

        exit(EXIT_SUCCESS);
    }
    return EXIT_SUCCESS;
}

