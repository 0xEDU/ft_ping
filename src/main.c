#include "ft_ping.h"

int main(int argc, char *argv[]) {
    int opt = 0;
    bool flag_v = false;

    if (argc == 1) {
        print_help();
    }

    // Parsing command line arguments using getopt
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

    // Handle -v flag
    if (flag_v) {
        printf("Flag -v is set.\n");
        // Add your -v flag handling code here
    }

    return 0;
}
