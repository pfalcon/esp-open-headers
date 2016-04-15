.bss + 0x10

struct ? {
// size 0x7c
} sta_trc[9];


struct trc *rcGetTrc(void);

struct ? *rc_get_sta_trc(int sta_no /*0-9*/);
struct ? *rc_get_trc(int sta_no /*0-9*/);

struct ? *rc_get_trc_by_index(int idx /*0-8*/);