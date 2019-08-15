#include <stdio.h>
#include <string.h>

#define MIN_BUF_SIZE 60

void vuln(unsigned char *src, size_t size_)
{
    unsigned char buf1[MIN_BUF_SIZE];
    int size = size_;
    if(size < MIN_BUF_SIZE) {
        memcpy(buf1, src, size);
        memset(buf1 + size, 0, MIN_BUF_SIZE - size);
    }
}

void not_vuln(unsigned char *src, size_t size_)
{
    unsigned char buf1[MIN_BUF_SIZE];
    size_t size = size_;
    if(size < MIN_BUF_SIZE) {
        memcpy(buf1, src, size);
        memset(buf1 + size, 0, MIN_BUF_SIZE - size);
    }
}

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    if(!strcmp(argv[1], "vuln")) {
        char buf[128] = { 0 };
        memset(buf, 0x41, sizeof(buf)-1);
        vuln((unsigned char *)&buf, -1);
    }
    else if(!strcmp(argv[1], "notvuln")) {
        char buf[MIN_BUF_SIZE] = { 0 };
        memset(buf, 0x42, sizeof(buf)-1);
        not_vuln((unsigned char *)&buf, MIN_BUF_SIZE-1);
    }

    return 0;
}
