/* ----------------------------------------------------------------------
 * Project:      CMSIS DSP Library
 * Title:        arm_cos_q15.c
 * Description:  Fast cosine calculation for Q15 values
 *
 * $Date:        23 April 2021
 * $Revision:    V1.9.0
 *
 * Target Processor: Cortex-M and Cortex-A cores
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2021 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "dsp/fast_math_functions.h"
#include "arm_common_tables.h"

#include <stdlib.h>

/**
  @ingroup groupFastMath
 */

/**
  @defgroup divide Fixed point division

 */

/**
  @addtogroup divide
  @{
 */

/**
  @brief         Fixed point division
  @param[in]     numerator    Numerator
  @param[in]     denominator  Denominator
  @param[out]    quotient     Quotient value normalized between -1.0 and 1.0
  @param[out]    shift        Shift left value to get the unnormalized quotient
  @return        error status

  When dividing by 0, an error ARM_MATH_NANINF is returned. And the quotient is forced
  to the saturated negative or positive value.
 */

arm_status arm_divide_q15(q15_t numerator,
  q15_t denominator,
  q15_t *quotient,
  int16_t *shift)
{
  int16_t sign=0;
  q31_t temp;
  int16_t shiftForNormalizing;

  *shift = 0;

  sign = (numerator>>15) ^ (denominator>>15);

  if (denominator == 0)
  {
     if (sign)
     {
        *quotient = -32768;
     }
     else
     {
        *quotient = 32767;
     }
     return(ARM_MATH_NANINF);
  }

  arm_abs_q15(&numerator,&numerator,1);
  arm_abs_q15(&denominator,&denominator,1);
  
  temp = ((q31_t)numerator << 15) / ((q31_t)denominator);

  shiftForNormalizing= 17 - __CLZ(temp);
  if (shiftForNormalizing > 0)
  {
     *shift = shiftForNormalizing;
     temp = temp >> shiftForNormalizing;
  }

  if (sign)
  {
    temp = -temp;
  }

  *quotient=temp;

  return(ARM_MATH_SUCCESS);
}

/**
  @} end of divide group
 */
