struct ac_buf {
// Size: 36

// + 0x11
u8 zero_means_idle;
};

// .bss
u8 free_ac_bufs; // initially 8 (lmacInit)

//struct ac_buf *GetAccess(int ac_buf_no);

FAST_CODE bool lmacIsActive(void);
FAST_CODE bool lmacIsIdle(int ac_buf_no);

void lmacInitAc(int ac_buf_no, u8 arg1, u8 arg2, u8 arg3, u16 arg4);
void lmacSetAcParam(int ac_buf_no, u8 arg1, u8 arg2, u8 arg3, u16 arg4);
