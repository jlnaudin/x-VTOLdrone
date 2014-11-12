/* builtin command list - automatically generated, do not edit */
#include <nuttx/config.h>
#include <nuttx/binfmt/builtin.h>
extern int sercon_main(int argc, char *argv[]);
extern int serdis_main(int argc, char *argv[]);
extern int ArduPilot_main(int argc, char *argv[]);
extern int adc_main(int argc, char *argv[]);
extern int auth_main(int argc, char *argv[]);
extern int bl_update_main(int argc, char *argv[]);
extern int blinkm_main(int argc, char *argv[]);
extern int boardinfo_main(int argc, char *argv[]);
extern int ets_airspeed_main(int argc, char *argv[]);
extern int fmu_main(int argc, char *argv[]);
extern int gps_main(int argc, char *argv[]);
extern int hmc5883_main(int argc, char *argv[]);
extern int i2c_main(int argc, char *argv[]);
extern int l3gd20_main(int argc, char *argv[]);
extern int ll40ls_main(int argc, char *argv[]);
extern int mb12xx_main(int argc, char *argv[]);
extern int meas_airspeed_main(int argc, char *argv[]);
extern int mixer_main(int argc, char *argv[]);
extern int mkblctrl_main(int argc, char *argv[]);
extern int mpu6000_main(int argc, char *argv[]);
extern int ms5611_main(int argc, char *argv[]);
extern int mtd_main(int argc, char *argv[]);
extern int nshterm_main(int argc, char *argv[]);
extern int perf_main(int argc, char *argv[]);
extern int pwm_main(int argc, char *argv[]);
extern int px4io_main(int argc, char *argv[]);
extern int reboot_main(int argc, char *argv[]);
extern int rgbled_main(int argc, char *argv[]);
extern int tests_main(int argc, char *argv[]);
extern int tone_alarm_main(int argc, char *argv[]);
extern int top_main(int argc, char *argv[]);
extern int uorb_main(int argc, char *argv[]);
const struct builtin_s g_builtins[] = {
    {"sercon", SCHED_PRIORITY_DEFAULT, 2048, sercon_main},
    {"serdis", SCHED_PRIORITY_DEFAULT, 2048, serdis_main},
    {"ArduPilot", SCHED_PRIORITY_DEFAULT, 4096, ArduPilot_main},
    {"adc", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, adc_main},
    {"auth", SCHED_PRIORITY_DEFAULT, 64000, auth_main},
    {"bl_update", SCHED_PRIORITY_DEFAULT, 4096, bl_update_main},
    {"blinkm", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, blinkm_main},
    {"boardinfo", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, boardinfo_main},
    {"ets_airspeed", SCHED_PRIORITY_DEFAULT, 2048, ets_airspeed_main},
    {"fmu", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, fmu_main},
    {"gps", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, gps_main},
    {"hmc5883", SCHED_PRIORITY_DEFAULT, 4096, hmc5883_main},
    {"i2c", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, i2c_main},
    {"l3gd20", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, l3gd20_main},
    {"ll40ls", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, ll40ls_main},
    {"mb12xx", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, mb12xx_main},
    {"meas_airspeed", SCHED_PRIORITY_DEFAULT, 2048, meas_airspeed_main},
    {"mixer", SCHED_PRIORITY_DEFAULT, 4096, mixer_main},
    {"mkblctrl", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, mkblctrl_main},
    {"mpu6000", SCHED_PRIORITY_DEFAULT, 4096, mpu6000_main},
    {"ms5611", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, ms5611_main},
    {"mtd", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, mtd_main},
    {"nshterm", SCHED_PRIORITY_DEFAULT, 3000, nshterm_main},
    {"perf", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, perf_main},
    {"pwm", SCHED_PRIORITY_DEFAULT, 4096, pwm_main},
    {"px4io", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, px4io_main},
    {"reboot", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, reboot_main},
    {"rgbled", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, rgbled_main},
    {"tests", SCHED_PRIORITY_DEFAULT, 12000, tests_main},
    {"tone_alarm", SCHED_PRIORITY_DEFAULT, CONFIG_PTHREAD_STACK_DEFAULT, tone_alarm_main},
    {"top", SCHED_PRIORITY_DEFAULT, 3000, top_main},
    {"uorb", SCHED_PRIORITY_DEFAULT, 4096, uorb_main},
    {NULL, 0, 0, NULL}
};
const int g_builtin_count = 32;
