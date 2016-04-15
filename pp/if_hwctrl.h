extern u8 interface_mask;

struct if_ctl {
// size 16
// 0
char mac[6];
// +8
u32 // == 1 means non-STA
// +0xc
u8 // == 0 means STA, == 1 means p2p
// +0xd
u8 ptk_alg;
// +0xe
u8 gtk_alg;
};

extern struct if_ctl if_ctrl[2];

struct if_ctl *ic_get_addr(int if_no);

void ic_set_opmode(int if_no, u32 arg1, u8 arg2);


// Returns number of enabled if's
int ic_enable_interface(int if_no, char *mac, u32 opmode_arg1, u8 opmode_arg2);
int ic_disable_interface(int if_no);

bool ic_interface_enabled(int if_no);

bool ic_is_pure_sta(int if_no);

u8 ic_get_ptk_alg(int if_no);
u8 ic_get_gtk_alg(int if_no);

bool ic_interface_is_p2p(int if_no);

char *ic_get_addr(int if_no);
