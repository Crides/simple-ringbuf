#include "rbuf.h"
#include <malloc.h>

rbuf_t *rbuf_new() {
    return (rbuf_t *) calloc(1, sizeof(rbuf_t));
}

void rbuf_write(rbuf_t *rbuf, char *d, unsigned char n) {
    for (int i = 0; i < n; i ++) {
        rbuf->buf[rbuf->in_ind] = d[i];
        if (rbuf->in_ind + 1 == rbuf->out_ind) {
            return;
        }
        rbuf->in_ind ++;
    }
}

char rbuf_read(rbuf_t *rbuf) {
    if (rbuf->out_ind != rbuf->in_ind) {
        return rbuf->buf[rbuf->out_ind ++];
    }
    return 0;
}

void rbuf_free(rbuf_t *rbuf) {
    free(rbuf);
}
