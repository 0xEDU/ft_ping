#include "ft_ping.h"
#include <netdb.h>

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

t_host *resolve_hostname(const char *hostname) {
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

  t_host *host = malloc(sizeof(t_host));
  memcpy(&host->addr, addr, sizeof(struct sockaddr_in));
  inet_ntop(AF_INET, &(addr->sin_addr), host->ip_str, INET_ADDRSTRLEN);

  freeaddrinfo(res);
  return host;
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

  for (int i = 0; hostnames[i] != NULL; i++) {
    t_host *host = resolve_hostname(hostnames[i]);

    printf("Resolved IP address: %s\n", host->ip_str);
    free(host);
  }

  close(socket_fd);
  return 0;
}
