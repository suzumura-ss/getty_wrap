#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <signal.h>
#include <unistd.h>


struct termios tios_old;

void exit_handler()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tios_old);
}


int main(int argc, char* const argv[])
{
    if (tcgetattr(STDIN_FILENO, &tios_old) != 0) return -1;
    atexit(exit_handler);

    struct termios tios_new = tios_old;
    tios_new.c_lflag &= ~ECHO;    // disable echo back
    tios_new.c_lflag &= ~ICANON;  // disable buffering
    tios_new.c_lflag &= ~ISIG;    // disable signal
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tios_new) != 0) return -1;

    puts("\n--- Dropping keyboard events. Enter CTRL-C 5 times to login console. ---");
    int control_c = 0;
    while (control_c<5) {
        if (getchar()==3) {
            control_c++;
        } else {
            control_c = 0;
        }
    }

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tios_old);

    if (argc>0) {
      return execv(argv[1], argv+1);
    }
    return 0;
}
