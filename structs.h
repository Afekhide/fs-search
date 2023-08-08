
#ifndef UNTITLED1_STRUCTS_H_H
#define UNTITLED1_STRUCTS_H_H


// IPv4 AF_INET sockets:
struct sockaddr_in {
    short            sin_family;
    unsigned short   sin_port;
    struct in_addr   sin_addr;
    char             sin_zero[8];
};


typedef struct in_addr {
    union {
        struct {
            unsigned char s_b1,s_b2,s_b3,s_b4;
        } S_un_b;
        struct {
            unsigned short s_w1,s_w2;
        } S_un_w;
        unsigned long S_addr;
    } S_un;
} IN_ADDR, *PIN_ADDR, FAR *LPIN_ADDR;


struct sockaddr {
    unsigned short    sa_family;    // address family, AF_xxx
    char              sa_data[14];  // 14 bytes of protocol address
};


#endif //UNTITLED1_STRUCTS_H_H
