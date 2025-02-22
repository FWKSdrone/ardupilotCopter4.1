#pragma once

#include <AP_Logger/LogStructure.h>

#define LOG_IDS_FROM_ESC_TELEM                  \
    LOG_ESC_MSG

// @LoggerMessage: ESC
// @Description: Feedback received from ESCs
// @Field: TimeUS: microseconds since system startup
// @Field: Instance: ESC instance number
// @Field: RPM: reported motor rotation rate
// @Field: RawRPM: reported motor rotation rate without slew adjustment
// @Field: Volt: Perceived input voltage for the ESC
// @Field: Curr: Perceived current through the ESC
// @Field: Temp: ESC temperature in centi-degrees C
// @Field: CTot: current consumed total mAh
// @Field: MotTemp: measured motor temperature in centi-degrees C
// @Field: Err: error rate
struct PACKED log_Esc {
    LOG_PACKET_HEADER;
    uint64_t time_us;
    uint8_t instance;
    int32_t rpm;
    int32_t raw_rpm;
    float voltage;
    float current;
    int16_t esc_temp;
    float current_tot;
    int16_t motor_temp;
    uint16_t error_count;
};

#define LOG_STRUCTURE_FROM_ESC_TELEM \
    { LOG_ESC_MSG, sizeof(log_Esc), \
      "ESC",  "QBeeffcfcH", "TimeUS,Instance,RPM,RawRPM,Volt,Curr,Temp,CTot,MotTemp,ErCount", "s#qqvAOaO#", "F-BB--BCB-" , true },
