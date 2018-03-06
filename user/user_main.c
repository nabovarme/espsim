#include <esp.h>
static os_timer_t sample_timer;


ICACHE_FLASH_ATTR void static sample_timer_func(void *arg) {
    printf("timer\n\r");
}

ICACHE_FLASH_ATTR void user_init(void) {
//	system_update_cpu_freq(160);

	printf("\n\r");
//	printf("SDK version: %s\n\r", system_get_sdk_version());
    
    os_timer_disarm(&sample_timer);
    os_timer_setfn(&sample_timer, (os_timer_func_t *)sample_timer_func, NULL);
    os_timer_arm(&sample_timer, 1000, 1);        // every 60 seconds

#ifdef DEBUG
	printf("\t(DEBUG)\n\r");
#endif

#ifdef IMPULSE
	printf("\t(IMPULSE)\n\r");
#endif

#ifdef DEBUG_NO_METER
	printf("\t(DEBUG_NO_METER)\n\r");
#endif

#ifdef DEBUG_SHORT_WEB_CONFIG_TIME
	printf("\t(DEBUG_SHORT_WEB_CONFIG_TIME)\n\r");
#endif

#ifdef FORCED_FLOW_METER
	printf("\t(FORCED_FLOW_METER)\n\r");
#endif

#if !(defined(IMPULSE) || defined(DEBUG_NO_METER))
#ifdef THERMO_NO
	printf("\t(THERMO_NO)\n\r");
#else
	printf("\t(THERMO_NC)\n\r");
#endif
#endif	// not IMPULSE or DEBUG_NO_METER

#if !defined(IMPULSE) || !defined(DEBUG_NO_METER)
#ifdef THERMO_ON_AC_2
	printf("\t(THERMO_ON_AC_2)\n\r");
#endif
#endif	// not IMPULSE or DEBUG_NO_METER

#ifndef AUTO_CLOSE	// reversed!
	printf("\t(NO_AUTO_CLOSE)\n\r");
#endif
}

