#ifndef _MODBUS_REG_H
#define _MODBUS_REG_H
#include "typedef.h"
#include "bsp_battery.h"
#include "bsp_motor.h"
#include "fal_display.h"
#include "fal_misc.h"
#include "fal_imu.h"
#include "bsp_imu.h"

#pragma pack ( push )
#pragma pack (1)
///< ʱ�����Ϣ
typedef struct
{
    uint16_t year;
    uint8_t moon;
    uint8_t date;
    uint8_t weekdate;
    uint8_t hour;
    uint8_t min;
    uint8_t second;
    uint16_t millisecond;
    
}MODBUS_TIMESTAMP_T, *MODBUS_TIMESTAMP_P;

///< ����ͨ�� ״̬
typedef struct
{
    uint16_t bit0_can1_motor_drive1 : 1;
    uint16_t bit1_can2_battery : 1;
    uint16_t bit2_soc_uart1 : 1;
    uint16_t bit3_task_mcu103_uart2: 1;
    uint16_t bit4_luna_uart3: 1;
    uint16_t bit5_nvg_mcu103_uart4: 1;
    uint16_t bit6_imu_uart5: 1;
    uint16_t bit7_flood_io: 1;
    uint16_t bit8_thtb_inner: 1;
    uint16_t bit9_thtb_outside: 1;
    uint16_t bit10_can1_motor_drive2: 1;
    uint16_t bit11: 1;
    uint16_t bit12: 1;
    uint16_t bit13: 1;
    uint16_t bit14: 1;
    uint16_t bit15: 1;

}MODBUS_PERIPHERAL_CONNECT_STA_T, *MODBUS_PERIPHERAL_CONNECT_STA_P;

///< IO ״̬
typedef struct
{
    uint16_t bit0_emerg : 1;                 ///< ��ͣ��ť IO
    uint16_t bit1_crash : 1;                 ///< ��ײ���� IO
    uint16_t bit2_power : 1;                 ///< ���ػ� IO
    uint16_t bit3: 1;
    uint16_t bit4: 1;
    uint16_t bit5: 1;
    uint16_t bit6: 1;
    uint16_t bit7: 1;
    uint16_t bit8: 1;
    uint16_t bit9: 1;
    uint16_t bit10: 1;
    uint16_t bit11: 1;
    uint16_t bit12: 1;
    uint16_t bit13: 1;
    uint16_t bit14: 1;
    uint16_t bit15: 1;

}MODBUS_IO_STA_T, *MODBUS_IO_STA_P;

///< ����״̬
typedef struct
{
    uint16_t bit0_normal : 1;
    uint16_t bit1_emerg : 1;
    uint16_t bit2_cliff : 1;
    uint16_t bit3_crash: 1;
    uint16_t bit4_flood: 1;
    uint16_t bit5_soc_connect: 1;
    uint16_t bit6_speed_zero: 1;
    uint16_t bit7_motor_drive_error_handle: 1;
    uint16_t bit8_emerg_handle: 1;
    uint16_t bit9_low_power: 1;
    uint16_t bit10: 1;
    uint16_t bit11: 1;
    uint16_t bit12: 1;
    uint16_t bit13: 1;
    uint16_t bit14: 1;
    uint16_t bit15: 1;

}MODBUS_RUN_STA_T, *MODBUS_RUN_STA_P;

///< ������״̬
typedef struct
{
    uint16_t bit0_flood : 1;
    uint16_t bit1_rain : 1;
    uint16_t bit2_cliff : 1;
    uint16_t bit3_emerg: 1;
    uint16_t bit4_crash: 1;
    uint16_t bit5_ultra_alow_power: 1;
    uint16_t bit6: 1;
    uint16_t bit7: 1;
    uint16_t bit8: 1;
    uint16_t bit9: 1;
    uint16_t bit10: 1;
    uint16_t bit11: 1;
    uint16_t bit12: 1;
    uint16_t bit13: 1;
    uint16_t bit14: 1;
    uint16_t bit15: 1;

}MODBUS_SENSOR_STA_T, *MODBUS_SENSOR_STA_P;

///< �����������
///< Modbus Addr: 0X3200
///< Modbus Code: 04(dec)
typedef struct
{
    uint16_t eular_yaw;             ///< ��ƫ��              ��λ 0.01 rad�����λ�Ƿ���λ
    uint16_t speed_w;               ///< ���ٶ�(gyro_z)      ��λ mrad/s�����λ�Ƿ���λ
    uint16_t speed_v;               ///< ���ٶ�              ��λ mm/s�����λ�Ƿ���λ
    uint32_t odom_x;                ///< X�᷽��λ��         ��λ cm�����λ�Ƿ���λ
    uint32_t odom_y;                ///< Y�᷽��λ��         ��λ cm�����λ�Ƿ���λ
    uint32_t odom_total;            ///< �����              ��λ cm�����λ�Ƿ���λ
    MODBUS_TIMESTAMP_T ts;          ///< ʱ���
    
}MODBUS_REG_MOTOR_DRIVE_PARAS_T, *MODBUS_REG_MOTOR_DRIVE_PARAS_P;

///< ��ʪ�����
///< Modbus Addr: 0X3002
///< Modbus Code: 04
typedef struct
{
    //float temperature_inner;        ///< �ڲ��¶�          ��λ ����Ҫ��Ӧ��ȷ����λ��
    //float humidity_inner;           ///< �ڲ�ʪ��          ��λ ����Ҫ��Ӧ��ȷ����λ��
    //float temperature_outside;      ///< �ⲿ�¶�          ��λ ����Ҫ��Ӧ��ȷ����λ��
    //float humidity_outside;         ///< �ⲿʪ��          ��λ ����Ҫ��Ӧ��ȷ����λ��
    int16_t temperature_inner;        ///< �ڲ��¶�          ��λ ʵ��ֵ*100
    int16_t humidity_inner;           ///< �ڲ�ʪ��          ��λ ʵ��ֵ*100
    int16_t temperature_outside;      ///< �ⲿ�¶�          ��λ ʵ��ֵ*10
    int16_t humidity_outside;         ///< �ⲿʪ��          ��λ ʵ��ֵ*10

}MODBUS_REG_THTB_T, *THTB_P;

///< ���ߴ�����������
///< Modbus Addr: 0X3015
///< Modbus Code: 04
typedef struct
{
    uint16_t left_adc_val;             ///< ���ߴ�����1ADֵ   ��λ   ʵ��ֵ
    uint16_t left_distance_val;        ///< ���ߴ�����1����   ��λmm ʵ��ֵ
    uint16_t right_adc_val;            ///< ���ߴ�����2ADֵ   ��λ   ʵ��ֵ
    uint16_t right_distance_val;       ///< ���ߴ�����2����   ��λmm ʵ��ֵ

}MODBUS_REG_TOUCH_EDGE_T, *TOUCH_EDGE_P;

///< ������
///< Modbus Addr: 0X3020
///< Modbus Code: 04
typedef struct
{
    uint16_t voltage;               ///< ��ѹ                ��λ mV
    uint32_t cap_remain;            ///< ʣ������            ��λ mAh
    uint32_t current;               ///< ����                ��λ mA
    uint16_t temp_env;              ///< �¶�                ��λ ����
    uint16_t cyc_time;              ///< ������            ��ѭ������
    uint32_t cap_full_in;           ///< ��������            ��λ mAh
    uint16_t volatage_percent;      ///< ��ѹ�ٷֱ�          0-100
    STA_PROTECT_BITS protect;       ///< ����״̬
    STA_WARMING_BITS warming;       ///< ����״̬
    int16_t temp_cell1;             ///< ��о�¶�1

}MODBUS_REG_BATTERY_T, *MODBUS_REG_BATTERY_P;

///< MCU֪ͨSOC�ػ����
///< Modbus Addr: 0X30A0
///< Modbus Code: 04
typedef struct
{
    uint16_t down_cmd;              ///< �ػ�ָ��            0X01:���ػ� 0X02:�ػ�

}MODBUS_REG_SOC_DOWN_CMD_T, *MODBUS_REG_SOC_DOWN_CMD_P;

///< ����������
///< Modbus Addr: 0X30EC
///< Modbus Code: 04
typedef struct
{
    uint16_t dis_1_nvg;             ///< �����峬�����1     ��λ��mm
    uint16_t dis_2_nvg;             ///< �����峬�����2     ��λ��mm
    uint16_t dis_3_nvg;             ///< �����峬�����3     ��λ��mm
    uint16_t dis_4_nvg;             ///< �����峬�����4     ��λ��mm
    uint16_t dis_5_nvg;             ///< �����峬�����5     ��λ��mm
    uint16_t dis_6_nvg;             ///< �����峬�����6     ��λ��mm
    uint16_t dis_7_nvg;             ///< �����峬�����7     ��λ��mm
    uint16_t dis_8_nvg;             ///< �����峬�����8     ��λ��mm
    uint16_t dis_1_task;            ///< ����峬�����1     ��λ��mm
    uint16_t dis_2_task;            ///< ����峬�����2     ��λ��mm
    uint16_t dis_3_task;            ///< ����峬�����3     ��λ��mm
    uint16_t dis_4_task;            ///< ����峬�����4     ��λ��mm
    uint16_t usound_sta;            ///< �������״̬        bit0 : bit11 ʮ��λ��Ӧʮ����̽ͷ  1������ 0������

}MODBUS_REG_USOUND_T, *MODBUS_REG_USOUND_P;

///< ���㼤�������
///< Modbus Addr: 0X3130
///< Modbus Code: 04
typedef struct
{
    uint16_t dis;                   ///< ����                ��λ��cm
    uint16_t laser_strength;        ///< ����ǿ��
    uint16_t temperature;           ///< �¶�                ��λ: ��

}MODBUS_REG_LUNA_T, *MODBUS_REG_LUNA_P;

///< ������״̬���
///< Modbus Addr: 0X3140
///< Modbus Code: 04
typedef struct
{
    uint16_t emerg;                                 ///< ��ͣ����            0���ǽ���ֹͣ 1������ֹͣ
    uint16_t crash;                                 ///< ����                0���Ǵ��� 1������
    MOTOR_ERROR_BITS_T motor_drv1;                  ///< ������1������
    MOTOR_ERROR_BITS_T motor_drv2;                  ///< ������2�����루����Ԥ����
    MODBUS_PERIPHERAL_CONNECT_STA_T perph_con1;     ///< ����ͨ��״̬1
    uint16_t perph_con2;                            ///< ����ͨ��״̬2��Ԥ����
    MODBUS_IO_STA_T io_sta;                         ///< IO ״̬
    uint16_t run_sta;                               ///< ����״̬
    MODBUS_SENSOR_STA_T sensor_sta;                 ///< ������״̬

}MODBUS_REG_ROBOT_STA_T, *MODBUS_REG_ROBOT_STA_P;

///< ����汾���
///< Modbus Addr: 0X3300
///< Modbus Code: 04
typedef struct
{
    uint16_t MCU407;
    uint16_t MCU_103_NVG;
    uint16_t motor_drive_soft;
    uint16_t motor_drive_hard;
    uint8_t date[12];
    uint8_t time[10];
    uint8_t branch[8];
    uint8_t commit[8];

}MODBUS_REG_VERSIFON_T, *MODBUS_REG_VERSION_P;

///< MCU RTC ʱ��
///< Modbus Addr: 0X3400
///< Modbus Code: 04
typedef struct
{
    uint16_t sta;           ///< ״̬              0������ 1������
    MODBUS_TIMESTAMP_T ts;

}MODBUS_REG_RTC_TIME_T, *MODBUS_REG_RTC_TIME_P;

///< ����״̬���
///< Modbus Addr: 0X3500
///< Modbus Code: 04
typedef struct
{
    uint16_t sta_bits;
    uint16_t reserve;

}MODBUS_PERP_STA_T, *MODBUS_PERP_STA_P;

///< ����ٶȿ���
///< Modbus Addr: 0X4000
///< Modbus Code: 03 06/16
typedef struct
{
    uint16_t speed_v;       ///< ���ٶ�              ��λ��mm/s ���λΪ����λ   ע���ĵ�����v �� w �෴
    uint16_t speed_w;       ///< ���ٶ�              ��λ��mrad/s ���λΪ����λ

}MODBUS_MOTOR_CTRL_SPEED_T, *MODBUS_MOTOR_CTRL_SPEED_P;

///< ���ɲ������
///< Modbus Addr: 0X4006
///< Modbus Code: 03 06
typedef struct
{
    uint16_t bit0_drv_enable : 1;
    uint16_t bit1_clear_error : 1;
    uint16_t bit2_emerg_lock : 1;
    uint16_t bit3_normal_lock: 1;
    uint16_t bit4: 1;
    uint16_t bit5: 1;
    uint16_t bit6: 1;
    uint16_t bit7: 1;
    uint16_t bit8: 1;
    uint16_t bit9: 1;
    uint16_t bit10: 1;
    uint16_t bit11: 1;
    uint16_t bit12: 1;
    uint16_t bit13: 1;
    uint16_t bit14: 1;
    uint16_t bit15: 1;

}MODBUS_REG_MOTOR_CTRL_LOCK_T, *MODBUS_REG_MOTOR_CTRL_LOCK_P;

///< �������쳣�¼�����
///< Modbus Addr: 0X4008
///< Modbus Code: 03 06
typedef struct
{
    uint8_t mask[10];                //�¼�������μĴ���

}MODBUS_REG_ROBOT_EXC_CLR_T, *MODBUS_REG_ROBOT_EXC_CLR_P;

///< �������쳣����ܿ���
///< Modbus Addr: 0X400D
///< Modbus Code: 03 06
typedef struct
{
    uint16_t enable;                //�¼�����ܿ���

}MODBUS_REG_ROBOT_EXC_DET_T, *MODBUS_REG_ROBOT_EXC_DET_P;

///< ʾ���ƿ���1
///< Modbus Addr: 0X4100
///< Modbus Code: 03 06/16
typedef struct
{
    uint8_t lamp_strength_lf;        ///< ��ǰʾ��������          0������ ��1~15��Խ��Խ��
    uint8_t lamp_shake_freq_lf;      ///< ��ǰʾ������˸Ƶ��      0������˸��1~30��Ƶ��Խ��Խ��
    uint8_t lamp_strength_lb;        ///< ���ʾ��������          0������ ��1~15��Խ��Խ��
    uint8_t lamp_shake_freq_lb;      ///< ���ʾ������˸Ƶ��      0������˸��1~30��Ƶ��Խ��Խ��
    uint8_t lamp_strength_rf;        ///< ��ǰʾ��������          0������ ��1~15��Խ��Խ��
    uint8_t lamp_shake_freq_rf;      ///< ��ǰʾ������˸Ƶ��      0������˸��1~30��Ƶ��Խ��Խ��
    uint8_t lamp_strength_rb;        ///< ��ǰʾ��������          0������ ��1~15��Խ��Խ��
    uint8_t lamp_shake_freq_rb;      ///< ��ǰʾ������˸Ƶ��      0������˸��1~30��Ƶ��Խ��Խ��
    
}MODBUS_REG_LAMP_CTRL1_T, *MODBUS_REG_LAMP_CTRL1_P;

///< �г��ƿ���
///< Modbus Addr: 0X4108
///< Modbus Code: 03 06
typedef struct
{
    uint16_t turn_on;                ///< ����                    0���رգ�1����
    
}MODBUS_REG_DRV_LED_CTRL_T, *MODBUS_REG_DRV_LED_CTRL_P;

///< ʾ���ƿ���2
///< Modbus Addr: 0X410A
///< Modbus Code: 03 06
typedef struct
{
    uint8_t color;                  ///< ��ɫ����
    uint8_t turn_on;                ///< ���ؿ���                 0��������bit0: ���� bit1: ����
    
}MODBUS_REG_LAMP_CTRL2_T, *MODBUS_REG_LAMP_CTRL2_P;

///< SOC �� MCU ���Ϳ��ؿ���
///< Modbus Addr: 0X4130
///< Modbus Code: 06
typedef struct
{
    uint16_t cmd;                   ///< ���ؿ���                 0X01���ػ���0X02������
    
}MODBUS_REG_SOC_POWER_CTRL_T, *MODBUS_REG_SOC_POWER_CTRL_P;

///< SOC �� MCU ���Ϳ���״̬
///< Modbus Addr: 0X4132
///< Modbus Code: 06
typedef struct
{
    uint16_t sta;                   ///< ����״̬                 0X01���ػ���ɣ�0X02���������
    
}MODBUS_REG_SOC_POWER_STA_T, *MODBUS_REG_SOC_POWER_STA_P;

///< MCU RTC ʱ��
///< Modbus Addr: 0X4200
///< Modbus Code: 16
typedef struct
{
    /*
    uint16_t year;
    uint8_t moon;
    uint8_t date;
    uint8_t weekdate;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    */
    uint16_t year;
    uint8_t date;
    uint8_t moon;
    uint8_t hour;
    uint8_t weekdate;
    uint8_t sec;
    uint8_t min;
    
    
}MODBUS_REG_RTC_TIME_SET_T, *MODBUS_REG_RTC_TIME_SET_P;


///< SOC �� MCU �����������ʾģʽ
///< Modbus Addr: 0X4400
///< Modbus Code: 16
typedef struct
{
    DISPLAY_CMD_T cmd;
    
}MODBUS_REG_SOC_DISPLAY_CTRL_T, *MODBUS_REG_SOC_DISPLAY_CTRL_P;

///< �Զ������أ����λ����Ϣ
///< Modbus Addr: 0X5000
///< Modbus Code: 03
typedef struct
{
    uint16_t location;              ///< ���λ��
    
}MODBUS_REG_AUTO_CHARGE_LOC_T, *MODBUS_REG_AUTO_CHARGE_LOC_P;

///< �Զ������أ��Զ����״̬�������
///< Modbus Addr: 0X5002
///< Modbus Code: 03
typedef struct
{
    uint16_t sta;                   ///< �Զ����״̬             0X01��δ��磻0X02������� 0X03:���ʧ��
    
}MODBUS_REG_AUTO_CHARGE_STA_T, *MODBUS_REG_AUTO_CHARGE_STA_P;

///< �Զ������أ�������ͣ��
///< Modbus Addr: 0X5004
///< Modbus Code: 03
typedef struct
{
    uint16_t parking_req;           ///< �Զ����ͣ������         0X01����ͣ��0X02��ͣ��
    
}MODBUS_REG_AUTO_CHARGE_PARKING_REQ_T, *MODBUS_REG_AUTO_CHARGE_PARKING_REQ_P;

///< �����˳��״̬
///< Modbus Addr: 0X5006
///< Modbus Code: 03
typedef struct
{
    uint16_t sta;                   ///< �Զ����״̬             0X01��δ��磻0X02���Զ������ 0X03:���Ƴ���� 0X04:���߳����
    
}MODBUS_REG_CHARGE_STA_T, *MODBUS_REG_CHARGE_STA_P;

///< �Զ������أ��Զ����ָ��
///< Modbus Addr: 0X6000
///< Modbus Code: 06
typedef struct
{
    uint16_t cmd;                   ///< �Զ����ָ��             0X01����ʼ�Զ���磻0X02��ȡ���Զ����
    
}MODBUS_REG_AUTO_CHARGE_CMD_T, *MODBUS_REG_AUTO_CHARGE_CMD_P;

///< �Զ������أ����ͣ��״̬
///< Modbus Addr: 0X6002
///< Modbus Code: 06
typedef struct
{
    uint16_t parking_sta;          ///< �Զ����ͣ������           0X01��ͣ�����
    
}MODBUS_REG_AUTO_CHARGE_PARKING_STA_T, *MODBUS_REG_AUTO_CHARGE_PARKING_STA_P;

/********************************* ���½����忨����ʹ�� *************************/
///< �豸�Լ�״̬
///< Modbus Addr: 0X4302
///< Modbus Code: 
typedef struct
{
    SELFTEST_STA_T selftest_sta;
    
}MODBUS_REG_SELFTEST_STA_T, *MODBUS_REG_SELFTEST_STA_P;

///< ���ȿ���
///< Modbus Addr: 0X4304
///< Modbus Code: 
typedef struct
{
    uint16_t turn_on;                ///< ����                    0���رգ�1����
    
}MODBUS_REG_HEAT_CTRL_T, *MODBUS_REG_HEAT_CTRL_P;

///< ���̵�������
///< Modbus Addr: 0X4306
///< Modbus Code: 
typedef struct
{
    uint16_t turn_on;                ///< ����                    0���رգ�1����
    
}MODBUS_REG_CHARGE_RELAY_CTRL_T, *MODBUS_REG_CHARGE_RELAY_CTRL_P;

///< ��������Դ����
///< Modbus Addr: 0X4308
///< Modbus Code: 
typedef struct
{
    uint16_t turn_on;                ///< ����                    0���رգ�1����
    
}MODBUS_REG_MOTOR_PWR_CTRL_T, *MODBUS_REG_MOTOR_PWR_CTRL_P;

///< IMU ԭʼ����
///< Modbus Addr: 0X4320
///< Modbus Code: 
typedef struct
{
    IMU_DATA_T imu_sensor_data;
    uint32_t pos_l;                 ///< ���ֱ�����λ��      ת��һȦ���� ���У�600 ɭ��: 5000
    uint32_t pos_r;                 ///< ���ֱ�����λ��      ת��һȦ���� ������600 ɭ��: 5000
    
}MODBUS_REG_IMU_RAW_T, *MODBUS_REG_IMU_RAW_P;

#pragma pack ( pop )

/********************************************************************************/

void modbus_reg_init(void);


#endif

