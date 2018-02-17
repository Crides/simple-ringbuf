typedef struct {
    unsigned char in_ind;
    unsigned char out_ind;
    char buf[256];
} rbuf_t;

rbuf_t *rbuf_new();
void rbuf_write(rbuf_t *rbuf, char *d, unsigned char n);
char rbuf_read(rbuf_t *rbuf);
void rbuf_free(rbuf_t *rbuf);
