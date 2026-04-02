#include "protocol.h"
#include <string.h>
#include <arpa/inet.h>

void encode_header(vpn_header_t *hdr, uint8_t *buffer) {
    buffer[0] = hdr->opcode;

    uint16_t cid = htons(hdr->client_id);
    memcpy(buffer + 1, &cid, 2);

    memcpy(buffer + 3, hdr->payload, 8);
}

int decode_header(uint8_t *buffer, int len, vpn_header_t *hdr) {
    if (len < VPN_HEADER_SIZE) {
        return -1; // paquete inválido
    }

    hdr->opcode = buffer[0];

    uint16_t cid;
    memcpy(&cid, buffer + 1, 2);
    hdr->client_id = ntohs(cid);

    memcpy(hdr->payload, buffer + 3, 8);

    return 0;
}