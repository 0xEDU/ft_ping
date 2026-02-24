#include "ft_ping.h"

double get_timestamp() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + ((double)tv.tv_usec) / 1000000;
}

void throw_generic_error() {
  perror("ping");
  exit(EXIT_FAILURE);
}

int create_socket() {
  int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (socket_fd < 0) {
    throw_generic_error();
  }
  return socket_fd;
}

char *resolve_hostname(const char *hostname) {
  struct addrinfo hints, *res;
  bzero(&hints, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_RAW;
  hints.ai_protocol = IPPROTO_ICMP;

  int status = getaddrinfo(hostname, NULL, &hints, &res);
  if (status != 0) {
    fprintf(stderr, "ft_ping: %s\n", gai_strerror(status));
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
  char *ip_str = malloc(INET_ADDRSTRLEN);
  if (ip_str == NULL) {
    perror("malloc");
    freeaddrinfo(res);
    exit(EXIT_FAILURE);
  }

  inet_ntop(AF_INET, &(addr->sin_addr), ip_str, INET_ADDRSTRLEN);
  freeaddrinfo(res);
  return ip_str;
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
      break;
    default:
      print_help();
      break;
    }
  }

  if (flag_v) {
    printf("Flag -v is set.\n");
  }

  char **hostnames = &argv[optind];
  if (hostnames[0] == NULL) {
    print_help();
  }

  int socket_fd = create_socket();

  // TODO: Resolve hostnames in loop
  for (int i = 0; hostnames[i] != NULL; i++) {
    char *ip_str = resolve_hostname(hostnames[i]);
    printf("Resolved IP address: %s\n", ip_str);
    free(ip_str);
  }

  close(socket_fd);
  return 0;
}
