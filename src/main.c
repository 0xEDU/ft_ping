#include "ft_ping.h"
#include <string.h>

double get_timestamp()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + ((double)tv.tv_usec) / 1000000;
}

void throw_generic_error() {
    perror("ping");
    exit(EXIT_FAILURE);
}

void ping(const char *hostname) {
    int ping_fd;
    uint8_t packet[64];

    // Open socket
    if ((ping_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP)) < 0)
        throw_generic_error();

    // Set target hostname. inet_pton convert IPs to address struct
    struct sockaddr_in destination_address;
    bzero(&destination_address, sizeof(destination_address));
    destination_address.sin_family = AF_INET;
    if (inet_pton(AF_INET, hostname, &destination_address.sin_addr) <= 0)
        throw_generic_error();

    // Create ICMP header
    icmp_header_t icmp_header;
    bzero(&icmp_header, sizeof(icmp_header));
    icmp_header.type = ICMP_ECHO_REQUEST;
    icmp_header.code = ICMP_ECHO_CODE;
    icmp_header.id = getpid();
    icmp_header.sequence = 42;

    // Fill packet
    memcpy(packet, &icmp_header, sizeof(icmp_header));
    icmp_header.checksum = calculate_checksum(packet, sizeof(icmp_header));
    memcpy(packet, &icmp_header, sizeof(icmp_header));
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
