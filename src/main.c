#include "ft_ping.h"

int main(int argc, char *argv[]) {
    int opt;
    int flag_f = 0, flag_v = 0, flag_e = 0;

    // Parsing command line arguments using getopt
    while ((opt = getopt(argc, argv, "fve")) != -1) {
        switch (opt) {
            case 'f':
                flag_f = 1;
                break;
            case 'v':
                flag_v = 1;
                break;
            case 'e':
                flag_e = 1;
                break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-f] [-v] [-e]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Handle -f flag
    if (flag_f) {
        printf("Flag -f is set.\n");
        // Add your -f flag handling code here
    }

    // Handle -v flag
    if (flag_v) {
        printf("Flag -v is set.\n");
        // Add your -v flag handling code here
    }

    // Handle -e flag
    if (flag_e) {
        printf("Flag -e is set.\n");
        // Add your -e flag handling code here
    }

    return 0;
}
