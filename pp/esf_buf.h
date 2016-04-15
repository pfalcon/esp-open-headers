// SDK 1.5.2
// Structure sizes and contents may differ by SDK version
// Compare with esp8266_wifi_raw/user/header.h
// from esp8266_wifi_raw project

/* Types */

// Control block for esf_buf module
struct esf_buf_ctl {
    // +0
    struct esf_buf *next_free_buf_of_type_1_or_2; // alloced as 1 by ieee80211_output_pbuf
    // +4
    struct esf_buf *next_free_buf_of_type_4; // alloced by ieee80211_getmgtframe
    // +8
    struct esf_buf *next_free_buf_of_type_5; // alloced by ieee80211_getmgtframe
    // +0x0c
    struct esf_buf *next_free_buf_of_type_7;
    // +0x10
    struct esf_buf *next_free_buf_of_type_8; // used for RX buffers
    // +0x14
    // This field is decremented by esf_rx_buf_alloc, but initialized to 0
    // and never incremented. So, it's negated number of allocated rx bufs.
    u32 alloc_cnt_rx_bufs_of_type_8;
};

//
// esf_buf extensions, different for different buf types
//

struct esf_buf_sub1 {
    // Size was 24, 28 for older SDKs
    uint8 data[32];
    // from esp8266_wifi_raw project, for much older SDK:
    /* byte 10 increases by 8 for a 1 byte increase in the length. */
    /* bytes 16 to 19 appear to be a timestamp in microseconds */
};

struct esf_buf_sub2 {
    uint8 data[32];
};

// alloced by ieee80211_getmgtframe
// Alloced from OS heap
struct esf_buf_sub4 {
    uint8 data[32];
};

// alloced by ieee80211_getmgtframe
struct esf_buf_sub5 {
    uint8 data[32];
};

// alloced by ieee80211_getmgtframe
// Alloced from OS heap
struct esf_buf_sub6 {
    uint8 data[32];
};

struct esf_buf_sub7 {
    uint8 data[32];
};

struct esf_buf_sub8 {
    uint8 data[12];
};

// from esp8266_wifi_raw project
struct esf_buf {
    struct pbuf *pb1;                       /*  0 */
    struct pbuf *pb2;                       /*  4 */ // = malloc(0xc) // type 4,
    struct pbuf *pb3;                       /*  8 */ // same ptr as above
    uint16 cnt1;                            /* 12 */ // init: 1 // type 4
    uint8 flg;                              /* 14 */
    uint8 pad1[1];
    struct ieee80211_frame *e_data;         /* 16 */ // = malloc(3rd arg to esf_buf_alloc) // type 4
    uint16 len1;                            /* 20 */
    uint16 len2;                            /* 22 */
    uint8 pad2[4];
    uint32 type1;                           /* 28 */
    struct esf_buf *next;                   /* 32 */
    // points to struct esf_buf_subN, depending on buf type
    void *ext;                              /* 36 0x24 */
};

_Static_assert(sizeof(struct esf_buf) == 0x28, "struct esf_buf: wrong size");

/* Data */

// .bss + 0
extern struct esf_buf_ctl esf_buf_ctl;

// .bss + 0x20
// sz:0x500

// type 6 is handled by vPortFree
// type 3 is unhandled by esf_buf_recycle

// init with: esf_buf_recycle(p, 1)
extern struct esf_buf[8/*was in prev SDK: 5*/]; // sz:0x140 // unk_3ffeae40

// init with: esf_buf_recycle(p, 4)
// not in SDK 1.5.2 extern struct { char ?[0x28]; }[8]; // sz:0x140

// init with: esf_buf_recycle(p, 5)
extern struct esf_buf[8]; // sz:0x140

// init with: esf_buf_recycle(p, 7)
extern struct esf_buf[4]; // sz:0xa0

// init with: esf_buf_recycle(p, 8)
extern struct esf_buf[7]; // sz:0x118

// .bss + 0x520
// sz:0x860
extern struct { char ?[0x10c]; }[8]; // sz:0x860

// .bss + 0xd80
// sz:0x260

extern struct { char ?[0x4c]}[8]; // sz:0x260

// .bss + 0xfe0
// sz:0x2c0

extern struct { char ?[0x1c]; }[5]; // sz:0x8c
extern struct { char ?[0x1c]; }[8]; // sz:0xe0
extern struct { char ?[0x1c]; }[8]; // sz:0xe0
extern struct { char ?[0x1c]; }[4]; // sz:0x70

// .bss + 0x12a0
// sz:0x54

extern struct { char ?[0x0c]; }[7]; // sz:0x54

// .bss + 0x12f4 - end of .bss

/* Functions */

//.irom0.text:
// pbuf is NULL for buf_type=5 and non-NULL for buf_type=1
struct esf_buf *esf_buf_alloc(struct pbuf *pbuf, u32 buf_type, u32 size_of_data_buf);
void esf_buf_recycle(struct esf_buf *buf, u32 buf_type);
void esf_buf_setup(void);

//.text:
// This lives in iRAM as apparently called from interrupts
FAST_CODE struct esf_buf *esf_rx_buf_alloc(u32 buf_type/*must be 8*/);
