#ifndef DNS_STRUCTS_H
#define DNS_STRUCTS_H

/* ---------- DNS STRUCTURES ---------- */

/* ---------- DNS HEADER ---------- */
typedef struct {
    unsigned short id;         // Transaction ID

    unsigned char rd :1;       // Recursion Desired
    unsigned char tc :1;       // Truncated
    unsigned char aa :1;       // Authoritative Answer
    unsigned char opcode :4;   // Opcode
    unsigned char qr :1;       // Query/Response flag

    unsigned char rcode :4;    // Response code
    unsigned char cd :1;       // Checking Disabled
    unsigned char ad :1;       // Authenticated Data
    unsigned char z :1;        // Z reserved bit
    unsigned char ra :1;       // Recursion Available

    unsigned short q_count;    // Number of questions
    unsigned short ans_count;  // Number of answers
    unsigned short auth_count; // Number of authority records
    unsigned short add_count;  // Number of additional records
} DNS_Header;


/* ---------- DNS QUESTION ---------- */
typedef struct {
    unsigned short qtype;
    unsigned short qclass;
} DNS_Question;


#endif