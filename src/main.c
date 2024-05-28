#include "ft_ping.h"

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
    }

    return 0;
}
