#ifndef __CANSTRUCTS_H
#define __CANSTRUCTS_H

#include "../drivers/stmHAL/stm32h5xx_hal.h"
#include <stdint.h>

#pragma pack(push, 1)

typedef struct {
    uint32_t id;
    uint32_t data_length;
    uint64_t data;
} txMessage;

typedef struct {
    FDCAN_RxHeaderTypeDef header;
    uint64_t data;
} rxMessage;

// Pedalbox APPS/Brake
typedef struct {
    uint16_t mV_apps1;
    uint16_t mV_apps2;
    uint16_t mV_brakePressureFront;
    uint16_t mV_brakePressureRear;
} PedalboxAPPSBrake;
#define PEDALBOX_APPS_BRAKE_ID 0x1C0

// Pedalbox Positions/Current
typedef struct {
    uint8_t pct_pedApps;
    uint8_t pct_pedBpps;
    uint16_t mV_brakePosition;
    uint16_t mV_currentSense;
    uint16_t mV_tsReady;
} PedalboxPositionsCurrent;
#define PEDALBOX_POSITIONS_CURRENT_ID 0x1C1

// Pedalbox Faults
typedef struct {
    uint8_t apps1Ov : 1,
            apps1Uv : 1,
            apps2Ov : 1,
            apps2Uv : 1,
            bpfOv : 1,
            bpfUv : 1,
            bprOv : 1,
            bprUv : 1;
    uint8_t currOv : 1,
            currUv : 1,
            bspdOk : 1,
            bspdHardware : 1,
            brakelight : 1,
            appsImplaus : 1,
            appsAndBrake : 1,
            hardBrakeThreshold : 1;
    uint8_t brakeDrag;
} PedalboxFaults;
#define PEDALBOX_FAULTS_ID 0x1C2

// Pedalbox Hist Faults
typedef struct {
    uint8_t apps1OvHist : 1,
            apps1UvHist : 1,
            apps2OvHist : 1,
            apps2UvHist : 1,
            bpfOvHist : 1,
            bpfUvHist : 1,
            bprOvHist : 1,
            bprUvHist : 1;
    uint8_t currOvHist : 1,
            currUvHist : 1,
            bspdOkHist : 1,
            bspdHardwareHist : 1,
            brakelightHist : 1,
            appsImplausHist : 1,
            appsAndBrakeHist : 1,
            hardBrakeThresholdHist : 1;
} PedalboxHistFaults;
#define PEDALBOX_HIST_FAULTS_ID 0x1C3

// IMU Linear Acceleration
typedef struct {
    int16_t mg_linearAccelerationX;
    int16_t mg_linearAccelerationY;
    int16_t mg_linearAccelerationZ;
    int16_t blank;
} IMULinearAcceleration;
#define IMU_LINEAR_ACCELERATION_ID 0x1C4

// IMU Angular Velocity
typedef struct {
    int16_t ddps_angularVelocityX;
    int16_t ddps_angularVelocityY;
    int16_t ddps_angularVelocityZ;
    int16_t blank;
} IMUAngularVelocity;
#define IMU_ANGULAR_VELOCITY_ID 0x1C5

// IMU Euler Angle
typedef struct {
    int16_t cdeg_eulerAngleX;
    int16_t cdeg_eulerAngleY;
    int16_t cdeg_eulerAngleZ;
    int16_t blank;
} IMUEulerAngle;
#define IMU_EULER_ANGLE_ID 0x1C6

// IMU Raw Acceleration
typedef struct {
    int16_t mg_rawAccelerationX;
    int16_t mg_rawAccelerationY;
    int16_t mg_rawAccelerationZ;
    int16_t cDegC_temperature;
} IMURawAcceleration;
#define IMU_RAW_ACCELERATION_ID 0x1C7

// SW Buttons/TSReady
typedef struct {
    uint8_t button1 : 1,
            button2 : 1,
            button3 : 1,
            button4 : 1,
            button5 : 1;
    int8_t switch1;
    int8_t switch2;
    uint16_t mV_tsready;
} SWButtonsTsready;
#define SW_BUTTONS_TSREADY_ID 0x1C8

// LVM Voltage/SOC
typedef struct {
    uint32_t dmV_bmsVoltage;
    uint16_t cDegC_highestTemp;
    uint16_t dpct_socEstimate;
} LVMVoltageSOC;
#define LVM_VOLTAGE_SOC_ID 0x1C9

// VCU Controls/Torque
typedef struct {
    uint8_t disCh1 : 1,
            disCh2 : 1,
            disCh3 : 1,
            disCh4 : 1,
            disCh5 : 1,
            disCh6 : 1,
            disCh7 : 1,
            disCh8 : 1;
    uint8_t enAirsPos : 1,
            enAirsNeg : 1,
            enPrecharge : 1,
            enDcdc : 1;
    uint8_t kW_maxPower;
    int16_t dNm_mcTorqueRequest;
} VCUControlsTorque;
#define VCU_CONTROLS_TORQUE_ID 0x240

// VCU TSReady/Faults
typedef struct {
    uint16_t mV_tsReadyPwr;
    uint16_t mV_tsReady;
    uint8_t tsready : 1,
            imdOk : 1,
            bspdOk : 1,
            bmsOk : 1,
            latch : 1,
            infoFault : 1,
            nonCritFault : 1,
            critFault : 1;
    uint8_t tssiFault : 1,
            launchControl : 1,
            drsOn : 1,
            tsreadyAirs : 1;
    uint8_t vcuState;
    uint8_t regenState;
} VCUTsreadyFaults;
#define VCU_TSREADY_FAULTS_ID 0x3C0

// VCU Wheel Speeds
typedef struct {
    uint16_t drpm_wheelSpeedFl;
    uint16_t drpm_wheelSpeedFr;
    uint16_t drpm_wheelSpeedRl;
    uint16_t drpm_wheelSpeedRr;
} VCUWheelSpeeds;
#define VCU_WHEEL_SPEEDS_ID 0x3C1

// VCU DRS Status
typedef struct {
    uint16_t dDeg_drsFrPos;
    uint16_t dDeg_drsFlPos;
    uint16_t dDeg_drsRlPos;
    uint16_t dDeg_drsRrPos;
} VCUDRSStatus;
#define VCU_DRS_STATUS_ID 0x3C2

// VCU MC Temps 1
typedef struct {
    int16_t dDegC_igbtATemp;
    int16_t dDegC_igbtBTemp;
    int16_t dDegC_igbtCTemp;
    int16_t dDegC_gdbTemp;
} VCUMCTemps1;
#define VCU_MC_TEMPS_1_ID 0x3C3

// VCU MC Temps 2
typedef struct {
    int16_t dDegC_controlBoardTemp;
    int16_t dDegC_rtd1Temp;
    int16_t dDegC_rtd2Temp;
    int16_t dDegC_stallBurstTemp;
} VCUMCTemps2;
#define VCU_MC_TEMPS_2_ID 0x3C4

// VCU MC Temps 3
typedef struct {
    int16_t dDegC_coolantTemp;
    int16_t dDegC_hotSpotTemp;
    int16_t dDegC_motorTemp;
    int16_t torqueShudder;
} VCUMCTemps3;
#define VCU_MC_TEMPS_3_ID 0x3C5

// VCU MC Analog Voltages
typedef struct {
    uint16_t messy;
    uint16_t ass;
    uint16_t bitfield;
    uint16_t bruh;
} VCUMCAnalogVoltages;
#define VCU_MC_ANALOG_VOLTAGES_ID 0x3C6

// VCU MC Digital Input
typedef struct {
    uint16_t another;
    uint16_t useless;
    uint16_t bitfield;
    uint16_t gang;
} VCUMCDigitalInput;
#define VCU_MC_DIGITAL_INPUT_ID 0x3C7

// VCU MC Position Info
typedef struct {
    int16_t dDeg_motorAngle;
    int16_t rpm_motorSpeed;
    int16_t dHz_outputFrequency;
    int16_t dDeg_resolverDelta;
} VCUMCPositionInfo;
#define VCU_MC_POSITION_INFO_ID 0x3C8

// VCU MC Current Info
typedef struct {
    int16_t dA_phaseACurrent;
    int16_t dA_phaseBCurrent;
    int16_t dA_phaseCCurrent;
    int16_t dA_dcBusCurrent;
} VCUMCCurrentInfo;
#define VCU_MC_CURRENT_INFO_ID 0x3C9

// VCU MC Voltage Info
typedef struct {
    int16_t dV_dcBusVoltage;
    int16_t dV_outputVoltage;
    int16_t dV_vabVoltage;
    int16_t dV_vbcVoltage;
} VCUMCVoltageInfo;
#define VCU_MC_VOLTAGE_INFO_ID 0x3CA

// VCU MC Flux Info
typedef struct {
    int16_t mW_vdFf;
    int16_t mW_vqFf;
    int16_t dA_id;
    int16_t dA_iq;
} VCUMCFluxInfo;
#define VCU_MC_FLUX_INFO_ID 0x3CB

// VCU MC Internal Voltages
typedef struct {
    int16_t cV_refVoltage15;
    int16_t cV_refVoltage25;
    int16_t cV_refVoltage50;
    int16_t cV_refVoltage12;
} VCUMCInternalVoltages;
#define VCU_MC_INTERNAL_VOLTAGES_ID 0x3CC

// VCU MC Internal States Info
typedef struct {
    uint8_t state;
    uint8_t kHz_pwmFreq;
    uint8_t inverterState;
    uint8_t relayStates;
    uint8_t inverterCrap;
    uint8_t crap2;
    uint8_t crap3;
    uint8_t crap4;
} VCUMCInternalStatesInfo;
#define VCU_MC_INTERNAL_STATES_INFO_ID 0x3CD

// VCU MC Fault Codes
typedef struct {
    uint32_t postFaults;
    uint32_t runFaults;
} VCUMCFaultCodes;
#define VCU_MC_FAULT_CODES_ID 0x3CE

// VCU MC Torque Timer
typedef struct {
    int16_t dNm_commandedTorque;
    int16_t dNm_torqueFeedback;
    uint32_t powerOnTime;
} VCUMCTorqueTimer;
#define VCU_MC_TORQUE_TIMER_ID 0x3CF

// VCU MC Flux Weakening
typedef struct {
    uint16_t modulationIndex;
    int16_t dA_fluxWeakeningOutput;
    int16_t dA_idCommand;
    int16_t dA_idCommand2;
} VCUMCFluxWeakening;
#define VCU_MC_FLUX_WEAKENING_ID 0x3D0

// VCU MC Firmware Info
typedef struct {
    uint16_t eepromVersion;
    uint16_t softwareVersion;
    uint16_t dateCode1;
    uint16_t dateCode2;
} VCUMCFirmwareInfo;
#define VCU_MC_FIRMWARE_INFO_ID 0x3D1

// VCU MC Torque Speed
typedef struct {
    int16_t dNm_torqueCommand;
    int16_t dNm_torqueFeedback;
    int16_t rpm_motorSpeed;
    int16_t dV_dcBusVoltage;
} VCUMCTorqueSpeed;
#define VCU_MC_TORQUE_SPEED_ID 0x3D2

// VCU MC Torque Capability
typedef struct {
    int16_t dNm_availableTorque;
    int16_t dNm_availableRegenTorque;
    uint32_t unused;
} VCUMCTorqueCapability;
#define VCU_MC_TORQUE_CAPABILITY_ID 0x3D3

// LVM TSReady/Fans
typedef struct {
    uint16_t mV_tsreadyIn;
    uint16_t mV_tsreadyAirs;
    uint16_t mA_fanIsense;
    uint16_t mV_fanVsense;
} LVMTsreadyFans;
#define LVM_TSREADY_FANS_ID 0x5C0

// Charger Data
typedef struct {
    uint16_t dV_outputVoltage;
    uint16_t dA_outputCurrent;
    uint8_t hardwareFailure : 1,
            overTemperature : 1,
            inputVoltageWrong : 1,
            startingState : 1,
            communicationTimeout : 1;
    uint8_t reserved1;
    uint8_t reserved2;
    uint8_t reserved3;
} ChargerData;
#define CHARGER_DATA_ID 0x6C0

// LVM Status/DCDC
typedef struct {
    uint8_t bmsOk : 1,
            tsready : 1,
            tslive : 1,
            airsPos : 1,
            airsNeg : 1,
            precharge : 1,
            fanEnCh1 : 1,
            fanEnCh2 : 1;
    uint8_t dcdcFault : 1,
            dcdcEnable : 1,
            dcdcPrecharge : 1,
            dcdcRelay : 1,
            lsOk : 1;
    uint16_t cDegC_dcdcTemp;
    int16_t dA_dcdcCurrent;
    uint16_t pct_fanPwm;
} LVMStatusDCDC;
#define LVM_STATUS_DCDC_ID 0x7C0

// LVM Current/Task Status
typedef struct {
    uint16_t mV_currentv;
    int16_t A_currenta;
    uint8_t taskStatus;
} LVMCurrentTaskStatus;
#define LVM_CURRENT_TASK_STATUS_ID 0x7C1

// LVM BMS Data
typedef struct {
    uint16_t dmV_lowestVolt;
    uint16_t dmV_highestVolt;
    uint16_t cDegC_lowestTemp;
    uint16_t cDegC_averageTemp;
} LVMBMSData;
#define LVM_BMS_DATA_ID 0x7C2

// LVM Module 1 Volts 1
typedef struct {
    uint16_t dmV_voltage1;
    uint16_t dmV_voltage2;
    uint16_t dmV_voltage3;
    uint16_t dmV_voltage4;
} LVMModule1Volts1;
#define LVM_MODULE_1_VOLTS_1_ID 0x7C3

// LVM Module 1 Volts 2
typedef struct {
    uint16_t dmV_voltage5;
    uint16_t dmV_voltage6;
    uint16_t dmV_voltage7;
    uint16_t dmV_voltage8;
} LVMModule1Volts2;
#define LVM_MODULE_1_VOLTS_2_ID 0x7C4

// LVM Module 1 Volts 3
typedef struct {
    uint16_t dmV_voltage9;
    uint16_t dmV_voltage10;
    uint16_t dmV_voltage11;
    uint16_t dmV_voltage12;
} LVMModule1Volts3;
#define LVM_MODULE_1_VOLTS_3_ID 0x7C5

// LVM Module 1 Volts 4
typedef struct {
    uint16_t dmV_voltage13;
    uint16_t dmV_voltage14;
    uint16_t dmV_voltage15;
    uint16_t dmV_voltage16;
} LVMModule1Volts4;
#define LVM_MODULE_1_VOLTS_4_ID 0x7C6

// LVM Module 2 Volts 1
typedef struct {
    uint16_t dmV_voltage1;
    uint16_t dmV_voltage2;
    uint16_t dmV_voltage3;
    uint16_t dmV_voltage4;
} LVMModule2Volts1;
#define LVM_MODULE_2_VOLTS_1_ID 0x7C7

// LVM Module 2 Volts 2
typedef struct {
    uint16_t dmV_voltage5;
    uint16_t dmV_voltage6;
    uint16_t dmV_voltage7;
    uint16_t dmV_voltage8;
} LVMModule2Volts2;
#define LVM_MODULE_2_VOLTS_2_ID 0x7C8

// LVM Module 2 Volts 3
typedef struct {
    uint16_t dmV_voltage9;
    uint16_t dmV_voltage10;
    uint16_t dmV_voltage11;
    uint16_t dmV_voltage12;
} LVMModule2Volts3;
#define LVM_MODULE_2_VOLTS_3_ID 0x7C9

// LVM Module 2 Volts 4
typedef struct {
    uint16_t dmV_voltage13;
    uint16_t dmV_voltage14;
    uint16_t dmV_voltage15;
    uint16_t dmV_voltage16;
} LVMModule2Volts4;
#define LVM_MODULE_2_VOLTS_4_ID 0x7CA

// LVM Module 3 Volts 1
typedef struct {
    uint16_t dmV_voltage1;
    uint16_t dmV_voltage2;
    uint16_t dmV_voltage3;
    uint16_t dmV_voltage4;
} LVMModule3Volts1;
#define LVM_MODULE_3_VOLTS_1_ID 0x7CB

// LVM Module 3 Volts 2
typedef struct {
    uint16_t dmV_voltage5;
    uint16_t dmV_voltage6;
    uint16_t dmV_voltage7;
    uint16_t dmV_voltage8;
} LVMModule3Volts2;
#define LVM_MODULE_3_VOLTS_2_ID 0x7CC

// LVM Module 3 Volts 3
typedef struct {
    uint16_t dmV_voltage9;
    uint16_t dmV_voltage10;
    uint16_t dmV_voltage11;
    uint16_t dmV_voltage12;
} LVMModule3Volts3;
#define LVM_MODULE_3_VOLTS_3_ID 0x7CD

// LVM Module 3 Volts 4
typedef struct {
    uint16_t dmV_voltage13;
    uint16_t dmV_voltage14;
    uint16_t dmV_voltage15;
    uint16_t dmV_voltage16;
} LVMModule3Volts4;
#define LVM_MODULE_3_VOLTS_4_ID 0x7CE

// LVM Module 4 Volts 1
typedef struct {
    uint16_t dmV_voltage1;
    uint16_t dmV_voltage2;
    uint16_t dmV_voltage3;
    uint16_t dmV_voltage4;
} LVMModule4Volts1;
#define LVM_MODULE_4_VOLTS_1_ID 0x7CF

// LVM Module 4 Volts 2
typedef struct {
    uint16_t dmV_voltage5;
    uint16_t dmV_voltage6;
    uint16_t dmV_voltage7;
    uint16_t dmV_voltage8;
} LVMModule4Volts2;
#define LVM_MODULE_4_VOLTS_2_ID 0x7D0

// LVM Module 4 Volts 3
typedef struct {
    uint16_t dmV_voltage9;
    uint16_t dmV_voltage10;
    uint16_t dmV_voltage11;
    uint16_t dmV_voltage12;
} LVMModule4Volts3;
#define LVM_MODULE_4_VOLTS_3_ID 0x7D1

// LVM Module 4 Volts 4
typedef struct {
    uint16_t dmV_voltage13;
    uint16_t dmV_voltage14;
    uint16_t dmV_voltage15;
    uint16_t dmV_voltage16;
} LVMModule4Volts4;
#define LVM_MODULE_4_VOLTS_4_ID 0x7D2

// LVM Module 5 Volts 1
typedef struct {
    uint16_t dmV_voltage1;
    uint16_t dmV_voltage2;
    uint16_t dmV_voltage3;
    uint16_t dmV_voltage4;
} LVMModule5Volts1;
#define LVM_MODULE_5_VOLTS_1_ID 0x7D3

// LVM Module 5 Volts 2
typedef struct {
    uint16_t dmV_voltage5;
    uint16_t dmV_voltage6;
    uint16_t dmV_voltage7;
    uint16_t dmV_voltage8;
} LVMModule5Volts2;
#define LVM_MODULE_5_VOLTS_2_ID 0x7D4

// LVM Module 5 Volts 3
typedef struct {
    uint16_t dmV_voltage9;
    uint16_t dmV_voltage10;
    uint16_t dmV_voltage11;
    uint16_t dmV_voltage12;
} LVMModule5Volts3;
#define LVM_MODULE_5_VOLTS_3_ID 0x7D5

// LVM Module 5 Volts 4
typedef struct {
    uint16_t dmV_voltage13;
    uint16_t dmV_voltage14;
    uint16_t dmV_voltage15;
    uint16_t dmV_voltage16;
} LVMModule5Volts4;
#define LVM_MODULE_5_VOLTS_4_ID 0x7D6

// LVM Module 6 Volts 1
typedef struct {
    uint16_t dmV_voltage1;
    uint16_t dmV_voltage2;
    uint16_t dmV_voltage3;
    uint16_t dmV_voltage4;
} LVMModule6Volts1;
#define LVM_MODULE_6_VOLTS_1_ID 0x7D7

// LVM Module 6 Volts 2
typedef struct {
    uint16_t dmV_voltage5;
    uint16_t dmV_voltage6;
    uint16_t dmV_voltage7;
    uint16_t dmV_voltage8;
} LVMModule6Volts2;
#define LVM_MODULE_6_VOLTS_2_ID 0x7D8

// LVM Module 6 Volts 3
typedef struct {
    uint16_t dmV_voltage9;
    uint16_t dmV_voltage10;
    uint16_t dmV_voltage11;
    uint16_t dmV_voltage12;
} LVMModule6Volts3;
#define LVM_MODULE_6_VOLTS_3_ID 0x7D9

// LVM Module 6 Volts 4
typedef struct {
    uint16_t dmV_voltage13;
    uint16_t dmV_voltage14;
    uint16_t dmV_voltage15;
    uint16_t dmV_voltage16;
} LVMModule6Volts4;
#define LVM_MODULE_6_VOLTS_4_ID 0x7DA

// LVM Module 1 Temps 1
typedef struct {
    uint16_t cDegC_temp1;
    uint16_t cDegC_temp2;
    uint16_t cDegC_temp3;
    uint16_t cDegC_temp4;
} LVMModule1Temps1;
#define LVM_MODULE_1_TEMPS_1_ID 0x7DB

// LVM Module 1 Temps 2
typedef struct {
    uint16_t cDegC_temp5;
    uint16_t cDegC_temp6;
    uint16_t cDegC_temp7;
    uint16_t cDegC_temp8;
} LVMModule1Temps2;
#define LVM_MODULE_1_TEMPS_2_ID 0x7DC

// LVM Module 1 Temps 3
typedef struct {
    uint16_t cDegC_temp9;
    uint16_t cDegC_temp10;
} LVMModule1Temps3;
#define LVM_MODULE_1_TEMPS_3_ID 0x7DD

// LVM Module 2 Temps 1
typedef struct {
    uint16_t cDegC_temp1;
    uint16_t cDegC_temp2;
    uint16_t cDegC_temp3;
    uint16_t cDegC_temp4;
} LVMModule2Temps1;
#define LVM_MODULE_2_TEMPS_1_ID 0x7DE

// LVM Module 2 Temps 2
typedef struct {
    uint16_t cDegC_temp5;
    uint16_t cDegC_temp6;
    uint16_t cDegC_temp7;
    uint16_t cDegC_temp8;
} LVMModule2Temps2;
#define LVM_MODULE_2_TEMPS_2_ID 0x7DF

// LVM Module 2 Temps 3
typedef struct {
    uint16_t cDegC_temp9;
    uint16_t cDegC_temp10;
} LVMModule2Temps3;
#define LVM_MODULE_2_TEMPS_3_ID 0x7E0

// LVM Module 3 Temps 1
typedef struct {
    uint16_t cDegC_temp1;
    uint16_t cDegC_temp2;
    uint16_t cDegC_temp3;
    uint16_t cDegC_temp4;
} LVMModule3Temps1;
#define LVM_MODULE_3_TEMPS_1_ID 0x7E1

// LVM Module 3 Temps 2
typedef struct {
    uint16_t cDegC_temp5;
    uint16_t cDegC_temp6;
    uint16_t cDegC_temp7;
    uint16_t cDegC_temp8;
} LVMModule3Temps2;
#define LVM_MODULE_3_TEMPS_2_ID 0x7E2

// LVM Module 3 Temps 3
typedef struct {
    uint16_t cDegC_temp9;
    uint16_t cDegC_temp10;
} LVMModule3Temps3;
#define LVM_MODULE_3_TEMPS_3_ID 0x7E3

// LVM Module 4 Temps 1
typedef struct {
    uint16_t cDegC_temp1;
    uint16_t cDegC_temp2;
    uint16_t cDegC_temp3;
    uint16_t cDegC_temp4;
} LVMModule4Temps1;
#define LVM_MODULE_4_TEMPS_1_ID 0x7E4

// LVM Module 4 Temps 2
typedef struct {
    uint16_t cDegC_temp5;
    uint16_t cDegC_temp6;
    uint16_t cDegC_temp7;
    uint16_t cDegC_temp8;
} LVMModule4Temps2;
#define LVM_MODULE_4_TEMPS_2_ID 0x7E5

// LVM Module 4 Temps 3
typedef struct {
    uint16_t cDegC_temp9;
    uint16_t cDegC_temp10;
} LVMModule4Temps3;
#define LVM_MODULE_4_TEMPS_3_ID 0x7E6

// LVM Module 5 Temps 1
typedef struct {
    uint16_t cDegC_temp1;
    uint16_t cDegC_temp2;
    uint16_t cDegC_temp3;
    uint16_t cDegC_temp4;
} LVMModule5Temps1;
#define LVM_MODULE_5_TEMPS_1_ID 0x7E7

// LVM Module 5 Temps 2
typedef struct {
    uint16_t cDegC_temp5;
    uint16_t cDegC_temp6;
    uint16_t cDegC_temp7;
    uint16_t cDegC_temp8;
} LVMModule5Temps2;
#define LVM_MODULE_5_TEMPS_2_ID 0x7E8

// LVM Module 5 Temps 3
typedef struct {
    uint16_t cDegC_temp9;
    uint16_t cDegC_temp10;
} LVMModule5Temps3;
#define LVM_MODULE_5_TEMPS_3_ID 0x7E9

// LVM Module 6 Temps 1
typedef struct {
    uint16_t cDegC_temp1;
    uint16_t cDegC_temp2;
    uint16_t cDegC_temp3;
    uint16_t cDegC_temp4;
} LVMModule6Temps1;
#define LVM_MODULE_6_TEMPS_1_ID 0x7EA

// LVM Module 6 Temps 2
typedef struct {
    uint16_t cDegC_temp5;
    uint16_t cDegC_temp6;
    uint16_t cDegC_temp7;
    uint16_t cDegC_temp8;
} LVMModule6Temps2;
#define LVM_MODULE_6_TEMPS_2_ID 0x7EB

// LVM Module 6 Temps 3
typedef struct {
    uint16_t cDegC_temp9;
    uint16_t cDegC_temp10;
} LVMModule6Temps3;
#define LVM_MODULE_6_TEMPS_3_ID 0x7EC

// Front CB 1DOF/PiT/StrPot
typedef struct {
    uint16_t mV_fr1Dof;
    uint16_t mV_fl1Dof;
    int16_t Pa_pitotTube;
    uint16_t mV_steeringPot;
} FrontCB1DOFPitStrpot;
#define FRONT_CB_1DOF_PIT_STRPOT_ID 0x5C1

// Front CB SP/SG
typedef struct {
    uint16_t mV_frStrainGauge;
    uint16_t mV_flStrainGauge;
    uint16_t mV_frShockPots;
    uint16_t mV_fhShockPots;
} FrontCBSPSG;
#define FRONT_CB_SP_SG_ID 0x5C2

// Rear CB SP/SG
typedef struct {
    uint16_t mV_rrStrainGauge;
    uint16_t mV_rlStrainGauge;
    uint16_t mV_rrShockPots;
    uint16_t mV_rhShockPots;
} RearCBSPSG;
#define REAR_CB_SP_SG_ID 0x5C3

// Rear CB Thermistors/FlowRate
typedef struct {
    uint16_t mV_thermistorRadIn;
    uint16_t mV_thermistorRadOut;
    uint16_t mV_thermistorMcOut;
    uint16_t mLpm_flowRate;
} RearCBThermistorsFlowrate;
#define REAR_CB_THERMISTORS_FLOWRATE_ID 0x5C4

// Rear CB 1DOF/CurrentSense
typedef struct {
    uint16_t mV_rr1Dof;
    uint16_t mV_rl1Dof;
    uint16_t mA_currentSense;
} RearCB1DOFCurrentsense;
#define REAR_CB_1DOF_CURRENTSENSE_ID 0x5C5

// TTPMS FL Pressure
typedef struct {
    uint16_t serialNumber;
    uint16_t batteryVoltage;
    uint16_t pressure;
    uint16_t gaugePressure;
} TTPMSFLPressure;
#define TTPMS_FL_PRESSURE_ID 0x600

// TTPMS FL IR Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} TTPMSFLIRTemps1;
#define TTPMS_FL_IR_TEMPS_1_ID 0x601

// TTPMS FL IR Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} TTPMSFLIRTemps2;
#define TTPMS_FL_IR_TEMPS_2_ID 0x602

// TTPMS FL IR Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} TTPMSFLIRTemps3;
#define TTPMS_FL_IR_TEMPS_3_ID 0x603

// TTPMS FL IR Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} TTPMSFLIRTemps4;
#define TTPMS_FL_IR_TEMPS_4_ID 0x604

// TTPMS FL Sensor Data
typedef struct {
    uint16_t transmissionCount;
    uint16_t rssi;
    uint16_t sensorTemperature;
    uint16_t sensorNodeId;
} TTPMSFLSensorData;
#define TTPMS_FL_SENSOR_DATA_ID 0x605

// TTPMS FR Pressure
typedef struct {
    uint16_t serialNumber;
    uint16_t batteryVoltage;
    uint16_t pressure;
    uint16_t gaugePressure;
} TTPMSFRPressure;
#define TTPMS_FR_PRESSURE_ID 0x606

// TTPMS FR IR Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} TTPMSFRIRTemps1;
#define TTPMS_FR_IR_TEMPS_1_ID 0x607

// TTPMS FR IR Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} TTPMSFRIRTemps2;
#define TTPMS_FR_IR_TEMPS_2_ID 0x608

// TTPMS FR IR Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} TTPMSFRIRTemps3;
#define TTPMS_FR_IR_TEMPS_3_ID 0x609

// TTPMS FR IR Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} TTPMSFRIRTemps4;
#define TTPMS_FR_IR_TEMPS_4_ID 0x60A

// TTPMS FR Sensor Data
typedef struct {
    uint16_t transmissionCount;
    uint16_t rssi;
    uint16_t sensorTemperature;
    uint16_t sensorNodeId;
} TTPMSFRSensorData;
#define TTPMS_FR_SENSOR_DATA_ID 0x60B

// TTPMS RL Pressure
typedef struct {
    uint16_t serialNumber;
    uint16_t batteryVoltage;
    uint16_t pressure;
    uint16_t gaugePressure;
} TTPMSRLPressure;
#define TTPMS_RL_PRESSURE_ID 0x60C

// TTPMS RL IR Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} TTPMSRLIRTemps1;
#define TTPMS_RL_IR_TEMPS_1_ID 0x60D

// TTPMS RL IR Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} TTPMSRLIRTemps2;
#define TTPMS_RL_IR_TEMPS_2_ID 0x60E

// TTPMS RL IR Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} TTPMSRLIRTemps3;
#define TTPMS_RL_IR_TEMPS_3_ID 0x60F

// TTPMS RL IR Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} TTPMSRLIRTemps4;
#define TTPMS_RL_IR_TEMPS_4_ID 0x610

// TTPMS RL Sensor Data
typedef struct {
    uint16_t transmissionCount;
    uint16_t rssi;
    uint16_t sensorTemperature;
    uint16_t sensorNodeId;
} TTPMSRLSensorData;
#define TTPMS_RL_SENSOR_DATA_ID 0x611

// TTPMS RR Pressure
typedef struct {
    uint16_t serialNumber;
    uint16_t batteryVoltage;
    uint16_t pressure;
    uint16_t gaugePressure;
} TTPMSRRPressure;
#define TTPMS_RR_PRESSURE_ID 0x612

// TTPMS RR IR Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} TTPMSRRIRTemps1;
#define TTPMS_RR_IR_TEMPS_1_ID 0x613

// TTPMS RR IR Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} TTPMSRRIRTemps2;
#define TTPMS_RR_IR_TEMPS_2_ID 0x614

// TTPMS RR IR Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} TTPMSRRIRTemps3;
#define TTPMS_RR_IR_TEMPS_3_ID 0x615

// TTPMS RR IR Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} TTPMSRRIRTemps4;
#define TTPMS_RR_IR_TEMPS_4_ID 0x616

// TTPMS RR Sensor Data
typedef struct {
    uint16_t transmissionCount;
    uint16_t rssi;
    uint16_t sensorTemperature;
    uint16_t sensorNodeId;
} TTPMSRRSensorData;
#define TTPMS_RR_SENSOR_DATA_ID 0x617

// IR Tire FL Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} IRTireFLTemps1;
#define IR_TIRE_FL_TEMPS_1_ID 0x640

// IR Tire FL Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} IRTireFLTemps2;
#define IR_TIRE_FL_TEMPS_2_ID 0x641

// IR Tire FL Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} IRTireFLTemps3;
#define IR_TIRE_FL_TEMPS_3_ID 0x642

// IR Tire FL Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} IRTireFLTemps4;
#define IR_TIRE_FL_TEMPS_4_ID 0x643

// IR Tire FR Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} IRTireFRTemps1;
#define IR_TIRE_FR_TEMPS_1_ID 0x644

// IR Tire FR Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} IRTireFRTemps2;
#define IR_TIRE_FR_TEMPS_2_ID 0x645

// IR Tire FR Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} IRTireFRTemps3;
#define IR_TIRE_FR_TEMPS_3_ID 0x646

// IR Tire FR Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} IRTireFRTemps4;
#define IR_TIRE_FR_TEMPS_4_ID 0x647

// IR Tire RL Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} IRTireRLTemps1;
#define IR_TIRE_RL_TEMPS_1_ID 0x648

// IR Tire RL Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} IRTireRLTemps2;
#define IR_TIRE_RL_TEMPS_2_ID 0x649

// IR Tire RL Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} IRTireRLTemps3;
#define IR_TIRE_RL_TEMPS_3_ID 0x64A

// IR Tire RL Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} IRTireRLTemps4;
#define IR_TIRE_RL_TEMPS_4_ID 0x64B

// IR Tire RR Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} IRTireRRTemps1;
#define IR_TIRE_RR_TEMPS_1_ID 0x64C

// IR Tire RR Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} IRTireRRTemps2;
#define IR_TIRE_RR_TEMPS_2_ID 0x64D

// IR Tire RR Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} IRTireRRTemps3;
#define IR_TIRE_RR_TEMPS_3_ID 0x64E

// IR Tire RR Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} IRTireRRTemps4;
#define IR_TIRE_RR_TEMPS_4_ID 0x64F

// IR Brake FL Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} IRBrakeFLTemps1;
#define IR_BRAKE_FL_TEMPS_1_ID 0x680

// IR Brake FL Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} IRBrakeFLTemps2;
#define IR_BRAKE_FL_TEMPS_2_ID 0x681

// IR Brake FL Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} IRBrakeFLTemps3;
#define IR_BRAKE_FL_TEMPS_3_ID 0x682

// IR Brake FL Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} IRBrakeFLTemps4;
#define IR_BRAKE_FL_TEMPS_4_ID 0x683

// IR Brake FL Sensor Temp
typedef struct {
    uint16_t sensorTemp;
} IRBrakeFLSensorTemp;
#define IR_BRAKE_FL_SENSOR_TEMP_ID 0x684

// IR Brake FR Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} IRBrakeFRTemps1;
#define IR_BRAKE_FR_TEMPS_1_ID 0x685

// IR Brake FR Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} IRBrakeFRTemps2;
#define IR_BRAKE_FR_TEMPS_2_ID 0x686

// IR Brake FR Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} IRBrakeFRTemps3;
#define IR_BRAKE_FR_TEMPS_3_ID 0x687

// IR Brake FR Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} IRBrakeFRTemps4;
#define IR_BRAKE_FR_TEMPS_4_ID 0x688

// IR Brake FR Sensor Temp
typedef struct {
    uint16_t sensorTemp;
} IRBrakeFRSensorTemp;
#define IR_BRAKE_FR_SENSOR_TEMP_ID 0x689

// IR Brake RL Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} IRBrakeRLTemps1;
#define IR_BRAKE_RL_TEMPS_1_ID 0x68A

// IR Brake RL Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} IRBrakeRLTemps2;
#define IR_BRAKE_RL_TEMPS_2_ID 0x68B

// IR Brake RL Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} IRBrakeRLTemps3;
#define IR_BRAKE_RL_TEMPS_3_ID 0x68C

// IR Brake RL Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} IRBrakeRLTemps4;
#define IR_BRAKE_RL_TEMPS_4_ID 0x68D

// IR Brake RL Sensor Temp
typedef struct {
    uint16_t sensorTemp;
} IRBrakeRLSensorTemp;
#define IR_BRAKE_RL_SENSOR_TEMP_ID 0x68E

// IR Brake RR Temps 1
typedef struct {
    uint16_t dDegC_irTempCh1;
    uint16_t dDegC_irTempCh2;
    uint16_t dDegC_irTempCh3;
    uint16_t dDegC_irTempCh4;
} IRBrakeRRTemps1;
#define IR_BRAKE_RR_TEMPS_1_ID 0x68F

// IR Brake RR Temps 2
typedef struct {
    uint16_t dDegC_irTempCh5;
    uint16_t dDegC_irTempCh6;
    uint16_t dDegC_irTempCh7;
    uint16_t dDegC_irTempCh8;
} IRBrakeRRTemps2;
#define IR_BRAKE_RR_TEMPS_2_ID 0x690

// IR Brake RR Temps 3
typedef struct {
    uint16_t dDegC_irTempCh9;
    uint16_t dDegC_irTempCh10;
    uint16_t dDegC_irTempCh11;
    uint16_t dDegC_irTempCh12;
} IRBrakeRRTemps3;
#define IR_BRAKE_RR_TEMPS_3_ID 0x691

// IR Brake RR Temps 4
typedef struct {
    uint16_t dDegC_irTempCh13;
    uint16_t dDegC_irTempCh14;
    uint16_t dDegC_irTempCh15;
    uint16_t dDegC_irTempCh16;
} IRBrakeRRTemps4;
#define IR_BRAKE_RR_TEMPS_4_ID 0x692

// IR Brake RR Sensor Temp
typedef struct {
    uint16_t sensorTemp;
} IRBrakeRRSensorTemp;
#define IR_BRAKE_RR_SENSOR_TEMP_ID 0x693

// Live Telemetry Status
typedef struct {
    uint8_t state;
    uint8_t users;
    uint32_t s_time;
    uint16_t ms_ms;
} LiveTelemetryStatus;
#define LIVE_TELEMETRY_STATUS_ID 0x6C1

// AeroCAN Message 1
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage1;
#define AEROCAN_MESSAGE_1_ID 0x700

// AeroCAN Message 2
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage2;
#define AEROCAN_MESSAGE_2_ID 0x701

// AeroCAN Message 3
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage3;
#define AEROCAN_MESSAGE_3_ID 0x702

// AeroCAN Message 4
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage4;
#define AEROCAN_MESSAGE_4_ID 0x703

// AeroCAN Message 5
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage5;
#define AEROCAN_MESSAGE_5_ID 0x704

// AeroCAN Message 6
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage6;
#define AEROCAN_MESSAGE_6_ID 0x705

// AeroCAN Message 7
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage7;
#define AEROCAN_MESSAGE_7_ID 0x706

// AeroCAN Message 8
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage8;
#define AEROCAN_MESSAGE_8_ID 0x707

// AeroCAN Message 9
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage9;
#define AEROCAN_MESSAGE_9_ID 0x708

// AeroCAN Message 10
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage10;
#define AEROCAN_MESSAGE_10_ID 0x709

// AeroCAN Message 11
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage11;
#define AEROCAN_MESSAGE_11_ID 0x70A

// AeroCAN Message 12
typedef struct {
    int16_t Pa_pressure1;
    int16_t Pa_pressure2;
    int16_t Pa_pressure3;
    int16_t Pa_pressure4;
} AerocanMessage12;
#define AEROCAN_MESSAGE_12_ID 0x70B

// PDC Channels 1,2
typedef struct {
    uint16_t mV_voltage1;
    uint16_t mA_current1;
    uint16_t mV_voltage2;
    uint16_t mA_current2;
} PDCChannels12;
#define PDC_CHANNELS_1_2_ID 0x740

// PDC Channels 3,4
typedef struct {
    uint16_t mV_voltage3;
    uint16_t mA_current3;
    uint16_t mV_voltage4;
    uint16_t mA_current4;
} PDCChannels34;
#define PDC_CHANNELS_3_4_ID 0x741

// PDC Channels 5,6
typedef struct {
    uint16_t mV_voltage5;
    uint16_t mA_current5;
    uint16_t mV_voltage6;
    uint16_t mA_current6;
} PDCChannels56;
#define PDC_CHANNELS_5_6_ID 0x742

// PDC Channels 7,8
typedef struct {
    uint16_t mV_voltage7;
    uint16_t mA_current7;
    uint16_t mV_voltage8;
    uint16_t mA_current8;
} PDCChannels78;
#define PDC_CHANNELS_7_8_ID 0x743

// PDC Status
typedef struct {
    uint8_t ch1 : 1,
            ch2 : 1,
            ch3 : 1,
            ch4 : 1,
            ch5 : 1,
            ch6 : 1,
            ch7 : 1,
            ch8 : 1;
} PDCStatus;
#define PDC_STATUS_ID 0x744

// Laser 1
typedef struct {
    uint16_t cmm_rideHeight;
    uint16_t rawRideHeight;
    uint16_t degC_temperature;
    uint16_t unused;
} Laser1;
#define LASER_1_ID 0x780

// Laser 2
typedef struct {
    uint16_t cmm_rideHeight;
    uint16_t rawRideHeight;
    uint16_t degC_temperature;
    uint16_t unused;
} Laser2;
#define LASER_2_ID 0x781

// Laser 3
typedef struct {
    uint16_t cmm_rideHeight;
    uint16_t rawRideHeight;
    uint16_t degC_temperature;
    uint16_t unused;
} Laser3;
#define LASER_3_ID 0x782

// Laser 4
typedef struct {
    uint16_t cmm_rideHeight;
    uint16_t rawRideHeight;
    uint16_t degC_temperature;
    uint16_t unused;
} Laser4;
#define LASER_4_ID 0x783

// IMD General
typedef struct {
    uint16_t kOhm_isolationResistanceCorrected;
    uint8_t isolationResistanceStatus;
    uint8_t isolationMeasurementCounter;
    uint8_t deviceErrorActive : 1,
            hvPosConnectionFailure : 1,
            hvNegConnectionFailure : 1,
            earthConnectionFailure : 1,
            isolationAlarm : 1,
            isolationWarning : 1,
            isolationOutdated : 1,
            unbalanceAlarm : 1;
    uint8_t undervoltageAlarm : 1,
            unsafeToStart : 1,
            earthliftOpen : 1;
    uint8_t deviceActivity;
    uint8_t unused;
} IMDGeneral;
#define IMD_GENERAL_ID 0x7F0

// IMD Isolation Detail
typedef struct {
    uint16_t kOhm_hvNegIsolation;
    uint16_t kOhm_hvPosIsolation;
    uint16_t isolationResistanceOriginal;
    uint8_t isolationMeasurementCounter;
    uint8_t pct_isolationQuality;
} IMDIsolationDetail;
#define IMD_ISOLATION_DETAIL_ID 0x7F1

// IMD Voltage
typedef struct {
    uint16_t V_hvSystemVoltage;
    uint16_t V_hvNegEarthVoltage;
    uint16_t V_hvPosEarthVoltage;
    uint8_t voltageMeasurementCounter;
    uint8_t unused;
} IMDVoltage;
#define IMD_VOLTAGE_ID 0x7F2

// IMD IT System
typedef struct {
    uint16_t duF_hvLeakageCapacitance;
    uint8_t capacitanceMeasurementCounter;
    uint8_t pct_isolationUnbalance;
    uint8_t unbalanceMeasurementCounter;
    uint8_t unused;
    uint16_t unused2;
} IMDITSystem;
#define IMD_IT_SYSTEM_ID 0x7F3

#pragma pack(pop)
#endif
