#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int pid, x, y, z;

    y = 10;
    z = 6;
    pid = fork();
    printf("pid = %d\n", pid);

    if (pid)
    {
        printf("I am the parent");
        printf("pid = %d\n", pid);
        fflush(stdout);
        wait(0);
    }
    else
    {
        printf("I am the child");
        fflush(stdout);
        // add a call to kill, to stop this process
        // so that we can attach a debugger
        // (1) send ourself a STOP signal
        // (2) get the child process' pid (ps -a)
        // (3) attach gdb to child: gdb <executable> <pid>
        //     gdb ./attach_example <pid>
        // (4) then in gdb, you can set break points, examine runtime state, ...
        // (5) you can get the process to continue running by sending it a
        //     sigcont signal from the gdb prompt:
        //     (gdb) signal SIGCONT
        kill(getpid(), SIGSTOP);
        x = y + z;
    }
    return 0;
}
