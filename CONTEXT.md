# ft_ping — Project Specification (LLM Context)

## Overview
The **ft_ping** project consists of reimplementing the Unix `ping` command in C.

The program must:
- Test the reachability of a host over an IP network
- Measure round-trip time (RTT) for packets

Reference implementation:
- `inetutils-2.0` (`ping -V`)

---

## Objectives
- Understand low-level networking (ICMP, sockets)
- Work with raw sockets in C
- Handle packet construction and parsing
- Implement timing and statistics
- Build robust CLI tools

---

## Technical Constraints

### Environment
- Must run in a **Debian VM (>= 7.0)**
- Kernel version **> 3.14**
- Must be usable from cluster machines

### Language & Build
- Language: **C**
- Must include a **Makefile**
- Makefile must:
  - Compile the project
  - Avoid unnecessary recompilation
  - Include standard rules (`all`, `clean`, `fclean`, `re`)

### Allowed
- All **libc functions**
- `printf` family

### Forbidden
- Calling system `ping`
- Copying or using existing ping source code

---

## Program Requirements

### Executable
- Name: `ft_ping`

### Supported Input
- IPv4 address
- Hostname (FQDN)

### DNS Constraint
- Must handle FQDN
- **Must NOT perform DNS resolution inside packet return**

---

## Mandatory Features

### Core Behavior
- Send ICMP Echo Request packets
- Receive ICMP Echo Reply packets
- Measure RTT
- Display results similar to `inetutils ping`

### Output
- Must match indentation of `inetutils-2.0`
- RTT tolerance: **±30 ms**

### Options
- `-v`: Verbose mode
  - Display additional information
  - Show packet errors without exiting
  - TTL manipulation may be used to simulate errors

- `-?`: Help / usage

### Error Handling
- Program must **never crash**
- Handle:
  - Invalid input
  - Network errors
  - Packet errors

---

## Networking Details (Expected Knowledge)

### Protocol
- ICMP (Internet Control Message Protocol)

### Packet Types
- Echo Request (Type 8)
- Echo Reply (Type 0)

### Likely Implementation Areas
- Raw sockets (`socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)`)
- Packet struct construction
- Checksum calculation
- Time measurement (e.g. `gettimeofday`)
- TTL handling
- Signal handling (e.g. Ctrl+C)

