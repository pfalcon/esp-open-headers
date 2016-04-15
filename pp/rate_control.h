
// .bss
struct foo {
//size 8

// 0x4
u8 rts_rate;
// 0x5
u8 ack_rate;
};


u8 RC_GetAckRate(int struct_no);
u16 RC_GetAckTime(int struct_no);
00000094 T RC_GetBlockAckTime
u16 RC_GetCtsTime(type ?);
u8 RC_GetRtsRate(int struct_no);
00000258 T RC_SetBasicRate(type ?, int one/*1*/)
