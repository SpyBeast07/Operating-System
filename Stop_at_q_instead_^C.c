#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <sys/select.h>
#include <termios.h>
#include <sys/ioctl.h>

int kbhit(void) {
    struct timeval tv;
    fd_set read_fd;

    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&read_fd);
    FD_SET(0, &read_fd);

    if (select(1, &read_fd, NULL, NULL, &tv) == -1)
        return 0;

    return FD_ISSET(0, &read_fd);
}
#endif

void signalhandler(int sig) {
    printf("\nCaught signal %d\n", sig);
}

int ques1() {
    signal(SIGINT, signalhandler);

    while (1) {
        printf("Hello\n");
        if (kbhit()) {
            char s = getchar();
            if (s == 'q') {
                break;
            }
        }
        sleep(1);
    }
    return 0;
}

int main() {
    ques1();

    return 0;
}
