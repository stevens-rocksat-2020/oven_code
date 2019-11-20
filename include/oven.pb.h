/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Fri Nov  1 17:49:56 2019. */

#ifndef PB_OVEN_PB_H_INCLUDED
#define PB_OVEN_PB_H_INCLUDED
#include <pb.h>

#define PB_FIELD_16BIT

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _OvenState {
    OvenState_OFF = 0,
    OvenState_ON = 1,
    OvenState_PROFILE = 3,
    OvenState_ERROR = 4
} OvenState;
#define _OvenState_MIN OvenState_OFF
#define _OvenState_MAX OvenState_ERROR
#define _OvenState_ARRAYSIZE ((OvenState)(OvenState_ERROR+1))

/* Struct definitions */
typedef struct _OvenStatus {
    bool has_ovenTemp;
    float ovenTemp;
    bool has_ambientTemp;
    float ambientTemp;
    bool has_targetTemp;
    float targetTemp;
    bool has_ovenState;
    OvenState ovenState;
    bool has_outputPower;
    int32_t outputPower;
/* @@protoc_insertion_point(struct:OvenStatus) */
} OvenStatus;

typedef struct _PIDTune {
    bool has_p;
    float p;
    bool has_i;
    float i;
    bool has_d;
    float d;
/* @@protoc_insertion_point(struct:PIDTune) */
} PIDTune;

typedef struct _ReflowPoint {
    int64_t time;
    float temp;
/* @@protoc_insertion_point(struct:ReflowPoint) */
} ReflowPoint;

typedef struct _SetTarget {
    bool has_targetTemp;
    float targetTemp;
/* @@protoc_insertion_point(struct:SetTarget) */
} SetTarget;

typedef struct _ReflowCurve {
    pb_size_t reflowPoints_count;
    ReflowPoint reflowPoints[300];
/* @@protoc_insertion_point(struct:ReflowCurve) */
} ReflowCurve;

typedef struct _OvenConfiguration {
    bool has_pidTune;
    PIDTune pidTune;
    bool has_reflowCurve;
    ReflowCurve reflowCurve;
/* @@protoc_insertion_point(struct:OvenConfiguration) */
} OvenConfiguration;

typedef struct _RxMicro {
    bool has_target;
    SetTarget target;
    bool has_ovenState;
    OvenState ovenState;
    bool has_ovenConfiguration;
    OvenConfiguration ovenConfiguration;
/* @@protoc_insertion_point(struct:RxMicro) */
} RxMicro;

typedef struct _TxMicro {
    bool has_timeStamp;
    int64_t timeStamp;
    bool has_ovenStatus;
    OvenStatus ovenStatus;
    bool has_ovenConfiguration;
    OvenConfiguration ovenConfiguration;
/* @@protoc_insertion_point(struct:TxMicro) */
} TxMicro;

/* Default values for struct fields */

/* Initializer values for message structs */
#define SetTarget_init_default                   {false, 0}
#define ReflowPoint_init_default                 {0, 0}
#define ReflowCurve_init_default                 {0, {ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default, ReflowPoint_init_default}}
#define PIDTune_init_default                     {false, 0, false, 0, false, 0}
#define OvenConfiguration_init_default           {false, PIDTune_init_default, false, ReflowCurve_init_default}
#define OvenStatus_init_default                  {false, 0, false, 0, false, 0, false, _OvenState_MIN, false, 0}
#define TxMicro_init_default                     {false, 0, false, OvenStatus_init_default, false, OvenConfiguration_init_default}
#define RxMicro_init_default                     {false, SetTarget_init_default, false, _OvenState_MIN, false, OvenConfiguration_init_default}
#define SetTarget_init_zero                      {false, 0}
#define ReflowPoint_init_zero                    {0, 0}
#define ReflowCurve_init_zero                    {0, {ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero, ReflowPoint_init_zero}}
#define PIDTune_init_zero                        {false, 0, false, 0, false, 0}
#define OvenConfiguration_init_zero              {false, PIDTune_init_zero, false, ReflowCurve_init_zero}
#define OvenStatus_init_zero                     {false, 0, false, 0, false, 0, false, _OvenState_MIN, false, 0}
#define TxMicro_init_zero                        {false, 0, false, OvenStatus_init_zero, false, OvenConfiguration_init_zero}
#define RxMicro_init_zero                        {false, SetTarget_init_zero, false, _OvenState_MIN, false, OvenConfiguration_init_zero}

/* Field tags (for use in manual encoding/decoding) */
#define OvenStatus_ovenTemp_tag                  1
#define OvenStatus_ambientTemp_tag               2
#define OvenStatus_targetTemp_tag                3
#define OvenStatus_ovenState_tag                 4
#define OvenStatus_outputPower_tag               5
#define PIDTune_p_tag                            1
#define PIDTune_i_tag                            2
#define PIDTune_d_tag                            3
#define ReflowPoint_time_tag                     1
#define ReflowPoint_temp_tag                     2
#define SetTarget_targetTemp_tag                 1
#define ReflowCurve_reflowPoints_tag             1
#define OvenConfiguration_pidTune_tag            3
#define OvenConfiguration_reflowCurve_tag        4
#define RxMicro_target_tag                       1
#define RxMicro_ovenState_tag                    2
#define RxMicro_ovenConfiguration_tag            3
#define TxMicro_timeStamp_tag                    1
#define TxMicro_ovenStatus_tag                   2
#define TxMicro_ovenConfiguration_tag            3

/* Struct field encoding specification for nanopb */
extern const pb_field_t SetTarget_fields[2];
extern const pb_field_t ReflowPoint_fields[3];
extern const pb_field_t ReflowCurve_fields[2];
extern const pb_field_t PIDTune_fields[4];
extern const pb_field_t OvenConfiguration_fields[3];
extern const pb_field_t OvenStatus_fields[6];
extern const pb_field_t TxMicro_fields[4];
extern const pb_field_t RxMicro_fields[4];

/* Maximum encoded size of messages (where known) */
#define SetTarget_size                           5
#define ReflowPoint_size                         16
#define ReflowCurve_size                         5400
#define PIDTune_size                             15
#define OvenConfiguration_size                   5420
#define OvenStatus_size                          28
#define TxMicro_size                             5464
#define RxMicro_size                             5432

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define OVEN_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
