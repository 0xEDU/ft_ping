#include "ft_ping.h"

double get_timestamp()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + ((double)tv.tv_usec) / 1000000;
}

void ping(char *hostname) {
    int ping_fd = -1;

    (void)hostname;
    if ((ping_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    int opt = 0;
    bool flag_v = false;

    if (argc == 1) {
        print_help();
    }

    while ((opt = getopt(argc, argv, "v?")) != -1) {
        switch (opt) {
            case 'v':
                flag_v = true;
                break;
            case '?':
                print_help();
            default:
                print_help();
        }
    }


    if (flag_v) {
        printf("Flag -v is set.\n");
    }

    char **hostnames = &argv[optind];
    if (hostnames[0] == NULL) {
        print_help();
    }

    for (int i = 0; hostnames[i] != NULL; i++) {
        printf("Host: %s\n", hostnames[i]);
        ping(hostnames[i]);
    }

    return 0;
}
