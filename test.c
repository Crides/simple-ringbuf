#include <stdio.h>
#include "rbuf.h"

void read_from_rbuf(rbuf_t *rbuf, unsigned char n) {
    if (n == 0) {
        char c;
        while (1) {
            c = rbuf_read(rbuf);
            if (!c) {
                break;
            }
            printf("%c", c);
        }
    } else {
        for (int i = 0; i < n; i ++) {
            char c = rbuf_read(rbuf);
            if (c) {
                printf("%c", c);
            }
        }
    }
    puts("");
}

int main() {
    rbuf_t *rbuf = rbuf_new();
    rbuf_write(rbuf, "Hello World!", 12);
    read_from_rbuf(rbuf, 7);
    rbuf_write(rbuf, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.", 231);
    rbuf_write(rbuf, "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", 213);
    read_from_rbuf(rbuf, 255);
    read_from_rbuf(rbuf, 255);

    rbuf_free(rbuf);
    return 0;
}
