/*
 * part3_prob3_LQR_private.h
 *
 * Code generation for model "part3_prob3_LQR".
 *
 * Model version              : 1.78
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Oct 09 11:44:51 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_part3_prob3_LQR_private_h_
#define RTW_HEADER_part3_prob3_LQR_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
void part3_prob3_LQR_output0(void);
void part3_prob3_LQR_update0(void);
void part3_prob3_LQR_output2(void);
void part3_prob3_LQR_update2(void);    /* private model entry point functions */
extern void part3_prob3_LQR_derivatives(void);

#endif                                 /* RTW_HEADER_part3_prob3_LQR_private_h_ */