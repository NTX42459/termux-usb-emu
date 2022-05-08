#include <cstdio>
#include <fcntl.h>
#include <cstdlib>
#include <csignal>

#include "str_trim.hpp"


void print_usage(char *prog_name) {
    printf("usage: %s <node>\n", prog_name);
}


int main(int argc, char *argv[]) {
    if (argc == 2) {
        char node[255];
        if (!str_trim(node, sizeof(node), argv[1]))
            print_usage(argv[0]);
        else {
            int fd;
            if ((fd = open(node, O_RDWR)) < 0)
                print_usage(argv[0]);
            else {
                char shell[255];
                if (!str_trim(shell, sizeof(shell), getenv("SHELL")))
                    print_usage(argv[0]);
                else {
                    char fd_str[11];
                    sprintf(fd_str, "%d", fd);
                    setenv("TERMUX_USB_FD", fd_str, 0);
                    execl(shell, shell, nullptr);
                    perror(shell);
                }
            }
        }
    } else {
        print_usage(argv[0]);
    }
    return 0;
}
