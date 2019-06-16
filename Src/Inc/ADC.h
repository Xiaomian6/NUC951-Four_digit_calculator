/****************************************************************************************************
 *                                                               
 * W90P910 ADC Registers  
 *
 ****************************************************************************************************/
//#define ADC_BA				0xb800a000


#define ADC_CON_ADD			((ADC_BA+0x0000))	
#define ADC_TSC_ADD			((ADC_BA+0x0004))	
#define ADC_DLY_ADD			((ADC_BA+0x0008))	
#define ADC_XDATA_ADD		((ADC_BA+0x000C))	
#define ADC_YDATA_ADD		((ADC_BA+0x0010))	
#define LV_CON_ADD			((ADC_BA+0x0014))	
#define LV_STS_ADD			((ADC_BA+0x0018))	

#ifndef EBI_BA
#define EBI_BA				0xb0001000
#endif
#define EBICON_ADD				(EBI_BA+0x000)
#define EBI0CON_ADD				(EBI_BA+0x018)


typedef union {
    unsigned int value;
    struct{
       unsigned int ebi_dbwd:2,ebi_tcos:3,ebi_tacs:3,ebi_tcoh:3,ebi_tacc:4,ebi_adrs:1,ebi_size:3,ebi_basaddr:13;
          }EBI0CON_field;
} ebi_0con_union;
#define EBI_DBWD 			(EBI0CON_REG.EBI0CON_field.ebi_dbwd)
#define EBI_tCOS			(EBI0CON_REG.EBI0CON_field.ebi_tcos)
#define EBI_tACS			(EBI0CON_REG.EBI0CON_field.ebi_tacs)
#define EBI_tCOH			(EBI0CON_REG.EBI0CON_field.ebi_tcoh)
#define EBI_tACC			(EBI0CON_REG.EBI0CON_field.ebi_tacc)
#define EBI_ADRS			(EBI0CON_REG.EBI0CON_field.ebi_adrs)
#define EBI_SIZE			(EBI0CON_REG.EBI0CON_field.ebi_size)
#define EBI_BASADDR			(EBI0CON_REG.EBI0CON_field.ebi_basaddr)


typedef union {
    unsigned int value;
    struct{
        unsigned int adc_finish:1,adc_div:8,adc_mux:3,adc_read_conv:1,adc_conv:1,adc_tsc_mode:2,adc_rst:1,adc_en:1,
        	adc_int:1,lvd_int:1,wt_int:1,adc_int_en:1,lvd_int_en:1,wt_int_en:1,con_unused:8;
          }ADC_CON_field;
} adc_con_union;
#define ADC_FINISH 		(ADC_CON_REG.ADC_CON_field.adc_finish)
#define ADC_DIV 		(ADC_CON_REG.ADC_CON_field.adc_div)
#define ADC_MUX 		(ADC_CON_REG.ADC_CON_field.adc_mux)
#define ADC_READ_CONV 	(ADC_CON_REG.ADC_CON_field.adc_read_conv)
#define ADC_CONV 		(ADC_CON_REG.ADC_CON_field.adc_conv)
#define ADC_TSC_MODE 	(ADC_CON_REG.ADC_CON_field.adc_tsc_mode)
#define ADC_RST 		(ADC_CON_REG.ADC_CON_field.adc_rst)
#define ADC_EN 			(ADC_CON_REG.ADC_CON_field.adc_en)
#define ADC_INT 		(ADC_CON_REG.ADC_CON_field.adc_int)
#define LVD_INT 		(ADC_CON_REG.ADC_CON_field.lvd_int)
#define WT_INT 			(ADC_CON_REG.ADC_CON_field.wt_int)
#define ADC_INT_EN 		(ADC_CON_REG.ADC_CON_field.adc_int_en)
#define LVD_INT_EN 		(ADC_CON_REG.ADC_CON_field.lvd_int_en)
#define WT_INT_EN 		(ADC_CON_REG.ADC_CON_field.wt_int_en)


/**************************************************************************************************************/

typedef union {
    unsigned int value;
    struct{
       unsigned int adc_udb:1,adc_tsc_type:2,adc_pu_en:1,adc_tsc_ym:1,adc_tsc_yp:1,adc_tsc_xm:1,adc_tsc_xp:1,tsc_xy:1,tsc_unused:23;
          }ADC_TSC_field;
} adc_tsc_union;
#define ADC_UD 			(ADC_TSC_REG.ADC_TSC_field.adc_udb)
#define ADC_TSC_TYPE	(ADC_TSC_REG.ADC_TSC_field.adc_tsc_type)
#define ADC_PU_EN 		(ADC_TSC_REG.ADC_TSC_field.adc_pu_en)
#define ADC_TSC_YM 		(ADC_TSC_REG.ADC_TSC_field.adc_tsc_ym)
#define ADC_TSC_YP 		(ADC_TSC_REG.ADC_TSC_field.adc_tsc_yp)
#define ADC_TSC_XM 		(ADC_TSC_REG.ADC_TSC_field.adc_tsc_xm)
#define ADC_TSC_XP 		(ADC_TSC_REG.ADC_TSC_field.adc_tsc_xp)
#define ADC_TSC_XY 		(ADC_TSC_REG.ADC_TSC_field.tsc_xy)

/**************************************************************************************************************/



typedef union {
    unsigned int value;
    struct{
        unsigned int adc_delay:18,dly_unused:14;
          }ADC_DLY_field;
} adc_dly_union;
#define ADC_DELAY 			(ADC_DLY_REG.ADC_DLY_field.adc_delay)

/**************************************************************************************************************/


typedef union {
    unsigned int value;
    struct{
        unsigned int adc_xdata:10,xdata_unused:22;
          }ADC_XDATA_field;
} adc_xdata_union;
#define ADC_XDATA 			(ADC_XDATA_REG.ADC_XDATA_field.adc_xdata)


/**************************************************************************************************************/

typedef union {
    unsigned int value;
    struct{
        unsigned int adc_ydata:10,ydata_unused:22;
          }ADC_YDATA_field;
} adc_ydata_union;
#define ADC_YDATA 			(ADC_YDATA_REG.ADC_YDATA_field.adc_ydata)


/**************************************************************************************************************/

typedef union {
    unsigned int value;
    struct{
        unsigned int sw_con:2,lv_en:1,lv_con_unused:29;
          }LV_CON_field;
} lv_con_union;
#define SW_CON 			(LV_CON_REG.LV_CON_field.sw_con)
#define LV_EN 			(LV_CON_REG.LV_CON_field.lv_en)


/**************************************************************************************************************/

typedef union {
    unsigned int value;
    struct{
        unsigned int lv_status:1,lv_sts_unused:31;
          }LV_STS_field;
} lv_sts_union;
#define LV_STATUS 			(LV_STS_REG.LV_STS_field.lv_status)

/**************************************************************************************************************/





#define CLKEN	(0xB0000200)