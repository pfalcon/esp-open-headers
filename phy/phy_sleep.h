extern u32 chip_version;

// .irom0.text
00000034 pm_usec2rtc
00000008 pm_rtc2usec
void pm_set_sleep_cycles(u32 cycles);
void pm_sleep_opt(u32 arg1, u32 arg2, u32 arg3);
void pm_wakeup_opt(u32 arg1, u32 arg2);
u32 get_chip_version(void); // But version in u8
void pm_sleep_opt_bb_off(void);
void pm_sleep_opt_bb_on(void);
void pm_set_pll_xtal_wait_time(void);
void pm_prepare_to_sleep(void);
bool pm_sdio_nidle(void);
void chg_lslp_mem_opt_8266(u8 arg1, u8 arg2, u8 arg3);
bool pm_goto_sleep(u32 enum_);
void pm_wait4wakeup(u32 enum_/*1,2*/);
void pm_open_rf(void);
void pm_sleep_set_mac(void);
00000093 pm_set_wakeup_mac(void);
void pm_check_mac_idle(void);
void pm_set_sleep_btco(void);
void pm_set_wakeup_btco(void);
0000010a pm_set_sleep_mode(u32 sl_mode);
void pm_unmask_bt(u32 sl_mode);
00000210 pm_wakeup_init(u32, u32);
void sleep_opt_8266(u32, u32, u32);
void sleep_opt_bb_on_8266(void);
void sleep_reset_analog_rtcreg_8266(void);

// .text
000000b5 pm_rtc_clock_cali(void *)
void clockgate_watchdog(bool on);
