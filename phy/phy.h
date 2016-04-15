struct phy_ops {
f_ptr init;
// +4
f_ptr change_channel;
// +0x18
f_ptr bb_init
};

//.irom0.text:
// All these function call phy_ops
0000001c rf_init
00000016 bb_init();
00000030 phy_init
0000001c RFChannelSel()
00000016 phy_delete_channel
00000016 phy_enable_agc
00000016 phy_disable_agc
00000016 phy_initialize_bb
00000016 phy_set_sense
//.text:
void register_phy_ops(struct*);
void register_get_phy_addr(struct*);
void phy_change_channel();
u32 phy_get_mactime(void);
