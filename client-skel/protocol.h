#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

#define VPN_HEADER_SIZE 11

typedef struct {
    uint8_t opcode;
    uint16_t client_id;
    uint8_t payload[8];
} vpn_header_t;

// Codificar: struct -> buffer
void encode_header(vpn_header_t *hdr, uint8_t *buffer);

// Decodificar: buffer -> struct
int decode_header(uint8_t *buffer, int len, vpn_header_t *hdr);

#endif