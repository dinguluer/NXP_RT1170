/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//#include "FreeRTOS.h"
//#include "task.h"

#include <core/lv_obj_scroll.h>
#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


// Screen task
#include "Screen_Task.h"


#define LEFT_LINE_A_LINE_1_X_START 214
#define LEFT_LINE_A_LINE_1_X_END   (LEFT_LINE_A_LINE_1_X_START-11)
#define LEFT_LINE_A_LINE_1_Y_START 368 //369
#define LEFT_LINE_A_LINE_1_Y_END   (LEFT_LINE_A_LINE_1_Y_START-1)

#define LEFT_LINE_A_LINE_2_X_START (LEFT_LINE_A_LINE_1_X_END +1)
#define LEFT_LINE_A_LINE_2_X_END   (LEFT_LINE_A_LINE_2_X_START-11)
#define LEFT_LINE_A_LINE_2_Y_START LEFT_LINE_A_LINE_1_Y_END
#define LEFT_LINE_A_LINE_2_Y_END   (LEFT_LINE_A_LINE_2_Y_START-1)

#define LEFT_LINE_A_LINE_3_X_START (LEFT_LINE_A_LINE_2_X_END +1)
#define LEFT_LINE_A_LINE_3_X_END   (LEFT_LINE_A_LINE_3_X_START-11)
#define LEFT_LINE_A_LINE_3_Y_START LEFT_LINE_A_LINE_2_Y_END
#define LEFT_LINE_A_LINE_3_Y_END   (LEFT_LINE_A_LINE_3_Y_START-1)

#define LEFT_LINE_A_LINE_4_X_START (LEFT_LINE_A_LINE_3_X_END +1)
#define LEFT_LINE_A_LINE_4_X_END   (LEFT_LINE_A_LINE_4_X_START-11)
#define LEFT_LINE_A_LINE_4_Y_START LEFT_LINE_A_LINE_3_Y_END
#define LEFT_LINE_A_LINE_4_Y_END   (LEFT_LINE_A_LINE_4_Y_START-1)

#define LEFT_LINE_A_LINE_5_X_START (LEFT_LINE_A_LINE_4_X_END +1)
#define LEFT_LINE_A_LINE_5_X_END   (LEFT_LINE_A_LINE_5_X_START-11)
#define LEFT_LINE_A_LINE_5_Y_START LEFT_LINE_A_LINE_4_Y_END
#define LEFT_LINE_A_LINE_5_Y_END   (LEFT_LINE_A_LINE_5_Y_START-1)

#define LEFT_LINE_A_LINE_6_X_START (LEFT_LINE_A_LINE_5_X_END +1)
#define LEFT_LINE_A_LINE_6_X_END   (LEFT_LINE_A_LINE_6_X_START-11)
#define LEFT_LINE_A_LINE_6_Y_START LEFT_LINE_A_LINE_5_Y_END
#define LEFT_LINE_A_LINE_6_Y_END   (LEFT_LINE_A_LINE_6_Y_START-1)

#define LEFT_LINE_A_LINE_7_X_START (LEFT_LINE_A_LINE_6_X_END +1)
#define LEFT_LINE_A_LINE_7_X_END   (LEFT_LINE_A_LINE_7_X_START-11)
#define LEFT_LINE_A_LINE_7_Y_START LEFT_LINE_A_LINE_6_Y_END
#define LEFT_LINE_A_LINE_7_Y_END   (LEFT_LINE_A_LINE_7_Y_START-1)

#define LEFT_LINE_A_LINE_8_X_START (LEFT_LINE_A_LINE_7_X_END +1)
#define LEFT_LINE_A_LINE_8_X_END   (LEFT_LINE_A_LINE_8_X_START-11)
#define LEFT_LINE_A_LINE_8_Y_START LEFT_LINE_A_LINE_7_Y_END
#define LEFT_LINE_A_LINE_8_Y_END   (LEFT_LINE_A_LINE_8_Y_START-1)

#define LEFT_LINE_A_LINE_9_X_START (LEFT_LINE_A_LINE_8_X_END +1)
#define LEFT_LINE_A_LINE_9_X_END   (LEFT_LINE_A_LINE_9_X_START-11)
#define LEFT_LINE_A_LINE_9_Y_START LEFT_LINE_A_LINE_8_Y_END
#define LEFT_LINE_A_LINE_9_Y_END   (LEFT_LINE_A_LINE_9_Y_START-1)

#define LEFT_LINE_A_LINE_10_X_START (LEFT_LINE_A_LINE_9_X_END +1)   //124
#define LEFT_LINE_A_LINE_10_X_END   (LEFT_LINE_A_LINE_10_X_START-11) //360
#define LEFT_LINE_A_LINE_10_Y_START LEFT_LINE_A_LINE_9_Y_END         // 113
#define LEFT_LINE_A_LINE_10_Y_END   (LEFT_LINE_A_LINE_10_Y_START-1)  // 359


#define LEFT_LINE_A_LINE_11_X_START (LEFT_LINE_A_LINE_10_X_END +1)
#define LEFT_LINE_A_LINE_11_X_END   (LEFT_LINE_A_LINE_11_X_START-16)
#define LEFT_LINE_A_LINE_11_Y_START LEFT_LINE_A_LINE_10_Y_END
#define LEFT_LINE_A_LINE_11_Y_END   (LEFT_LINE_A_LINE_11_Y_START-1)

#define LEFT_LINE_A_LINE_12_X_START (LEFT_LINE_A_LINE_11_X_END +1)
#define LEFT_LINE_A_LINE_12_X_END   (LEFT_LINE_A_LINE_12_X_START-10)
#define LEFT_LINE_A_LINE_12_Y_START LEFT_LINE_A_LINE_11_Y_END
#define LEFT_LINE_A_LINE_12_Y_END   (LEFT_LINE_A_LINE_12_Y_START-1)

#define LEFT_LINE_A_LINE_13_X_START (LEFT_LINE_A_LINE_12_X_END +3)// modified
#define LEFT_LINE_A_LINE_13_X_END   (LEFT_LINE_A_LINE_13_X_START-6)
#define LEFT_LINE_A_LINE_13_Y_START LEFT_LINE_A_LINE_12_Y_END  //-->
#define LEFT_LINE_A_LINE_13_Y_END   (LEFT_LINE_A_LINE_13_Y_START-1)

#define LEFT_LINE_A_LINE_14_X_START (LEFT_LINE_A_LINE_13_X_END +2)// modified
#define LEFT_LINE_A_LINE_14_X_END   (LEFT_LINE_A_LINE_14_X_START-6)
#define LEFT_LINE_A_LINE_14_Y_START LEFT_LINE_A_LINE_13_Y_END      // modified
#define LEFT_LINE_A_LINE_14_Y_END   (LEFT_LINE_A_LINE_14_Y_START)

#define LEFT_LINE_A_LINE_15_X_START (LEFT_LINE_A_LINE_14_X_END +2)// modified
#define LEFT_LINE_A_LINE_15_X_END   (LEFT_LINE_A_LINE_15_X_START-6)
#define LEFT_LINE_A_LINE_15_Y_START LEFT_LINE_A_LINE_14_Y_END      // modified
#define LEFT_LINE_A_LINE_15_Y_END   (LEFT_LINE_A_LINE_15_Y_START-1)

#define LEFT_LINE_A_LINE_16_X_START (LEFT_LINE_A_LINE_15_X_END +2)
#define LEFT_LINE_A_LINE_16_X_END   (LEFT_LINE_A_LINE_16_X_START-6)
#define LEFT_LINE_A_LINE_16_Y_START LEFT_LINE_A_LINE_15_Y_END      // modified
#define LEFT_LINE_A_LINE_16_Y_END   (LEFT_LINE_A_LINE_16_Y_START-1)

#define LEFT_LINE_A_LINE_17_X_START (LEFT_LINE_A_LINE_16_X_END +2)
#define LEFT_LINE_A_LINE_17_X_END   (LEFT_LINE_A_LINE_17_X_START-6)
#define LEFT_LINE_A_LINE_17_Y_START LEFT_LINE_A_LINE_16_Y_END      // modified
#define LEFT_LINE_A_LINE_17_Y_END   (LEFT_LINE_A_LINE_17_Y_START-1)

#define LEFT_LINE_A_LINE_18_X_START (LEFT_LINE_A_LINE_17_X_END +2)
#define LEFT_LINE_A_LINE_18_X_END   (LEFT_LINE_A_LINE_18_X_START-6)
#define LEFT_LINE_A_LINE_18_Y_START LEFT_LINE_A_LINE_17_Y_END      // modified
#define LEFT_LINE_A_LINE_18_Y_END   (LEFT_LINE_A_LINE_18_Y_START-2)

//#define LEFT_LINE_A_LINE_18_X_START (LEFT_LINE_A_LINE_17_X_END +2)  // modified
//#define LEFT_LINE_A_LINE_18_X_END   (LEFT_LINE_A_LINE_18_X_START-6)
//#define LEFT_LINE_A_LINE_18_Y_START LEFT_LINE_A_LINE_17_Y_END      // modified
//#define LEFT_LINE_A_LINE_18_Y_END   (LEFT_LINE_A_LINE_18_Y_START-2)

#define LEFT_LINE_A_LINE_19_X_START (LEFT_LINE_A_LINE_18_X_END +2)  // modified
#define LEFT_LINE_A_LINE_19_X_END   (LEFT_LINE_A_LINE_19_X_START-6)
#define LEFT_LINE_A_LINE_19_Y_START LEFT_LINE_A_LINE_18_Y_END      // modified
#define LEFT_LINE_A_LINE_19_Y_END   (LEFT_LINE_A_LINE_19_Y_START-2)

#define LEFT_LINE_A_LINE_20_X_START (LEFT_LINE_A_LINE_19_X_END +2)  // modified
#define LEFT_LINE_A_LINE_20_X_END   (LEFT_LINE_A_LINE_20_X_START-6)
#define LEFT_LINE_A_LINE_20_Y_START LEFT_LINE_A_LINE_19_Y_END      // modified
#define LEFT_LINE_A_LINE_20_Y_END   (LEFT_LINE_A_LINE_20_Y_START-3)

#define LEFT_LINE_A_LINE_21_X_START (LEFT_LINE_A_LINE_20_X_END +2)  // modified
#define LEFT_LINE_A_LINE_21_X_END   (LEFT_LINE_A_LINE_21_X_START-2)
#define LEFT_LINE_A_LINE_21_Y_START LEFT_LINE_A_LINE_20_Y_END + 1     // modified
#define LEFT_LINE_A_LINE_21_Y_END   (LEFT_LINE_A_LINE_21_Y_START-2)

#define LEFT_LINE_A_LINE_22_X_START (LEFT_LINE_A_LINE_21_X_END +2)  // modified
#define LEFT_LINE_A_LINE_22_X_END   (LEFT_LINE_A_LINE_22_X_START-4)
#define LEFT_LINE_A_LINE_22_Y_START LEFT_LINE_A_LINE_21_Y_END + 1     // modified
#define LEFT_LINE_A_LINE_22_Y_END   (LEFT_LINE_A_LINE_22_Y_START-2)

#define LEFT_LINE_A_LINE_23_X_START (LEFT_LINE_A_LINE_22_X_END +2)  // modified
#define LEFT_LINE_A_LINE_23_X_END   (LEFT_LINE_A_LINE_23_X_START-4)
#define LEFT_LINE_A_LINE_23_Y_START LEFT_LINE_A_LINE_22_Y_END + 5     // modified
#define LEFT_LINE_A_LINE_23_Y_END   (LEFT_LINE_A_LINE_23_Y_START-4 - 2)

#define LEFT_LINE_A_LINE_24_X_START (LEFT_LINE_A_LINE_23_X_END +2)  // modified
#define LEFT_LINE_A_LINE_24_X_END   (LEFT_LINE_A_LINE_24_X_START-1)
#define LEFT_LINE_A_LINE_24_Y_START LEFT_LINE_A_LINE_23_Y_END + 1 + 1 + 3   // modified
#define LEFT_LINE_A_LINE_24_Y_END   (LEFT_LINE_A_LINE_24_Y_START-6)

#define LEFT_LINE_A_LINE_25_X_START (LEFT_LINE_A_LINE_24_X_END +2)  // modified
#define LEFT_LINE_A_LINE_25_X_END   (LEFT_LINE_A_LINE_25_X_START-4 - 3)
#define LEFT_LINE_A_LINE_25_Y_START LEFT_LINE_A_LINE_24_Y_END + 1  + 2     // modified
#define LEFT_LINE_A_LINE_25_Y_END   (LEFT_LINE_A_LINE_25_Y_START-7)

#define LEFT_LINE_A_LINE_26_X_START (LEFT_LINE_A_LINE_25_X_END +2)  // modified
#define LEFT_LINE_A_LINE_26_X_END   (LEFT_LINE_A_LINE_26_X_START-4)
#define LEFT_LINE_A_LINE_26_Y_START LEFT_LINE_A_LINE_25_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_26_Y_END   (LEFT_LINE_A_LINE_26_Y_START-7)

#define LEFT_LINE_A_LINE_27_X_START (LEFT_LINE_A_LINE_26_X_END -1)  // modified
#define LEFT_LINE_A_LINE_27_X_END   (LEFT_LINE_A_LINE_27_X_START-4)
#define LEFT_LINE_A_LINE_27_Y_START LEFT_LINE_A_LINE_26_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_27_Y_END   (LEFT_LINE_A_LINE_27_Y_START-7)

#define LEFT_LINE_A_LINE_28_X_START (LEFT_LINE_A_LINE_27_X_END +3)  // modified
#define LEFT_LINE_A_LINE_28_X_END   (LEFT_LINE_A_LINE_28_X_START-4)
#define LEFT_LINE_A_LINE_28_Y_START LEFT_LINE_A_LINE_27_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_28_Y_END   (LEFT_LINE_A_LINE_28_Y_START-11)

#define LEFT_LINE_A_LINE_29_X_START (LEFT_LINE_A_LINE_28_X_END )  // modified
#define LEFT_LINE_A_LINE_29_X_END   (LEFT_LINE_A_LINE_29_X_START-2)
#define LEFT_LINE_A_LINE_29_Y_START LEFT_LINE_A_LINE_28_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_29_Y_END   (LEFT_LINE_A_LINE_29_Y_START-11)

#define LEFT_LINE_A_LINE_30_X_START (LEFT_LINE_A_LINE_29_X_END )  // modified
#define LEFT_LINE_A_LINE_30_X_END   (LEFT_LINE_A_LINE_30_X_START-2)
#define LEFT_LINE_A_LINE_30_Y_START LEFT_LINE_A_LINE_29_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_30_Y_END   (LEFT_LINE_A_LINE_30_Y_START-11)

#define LEFT_LINE_A_LINE_31_X_START (LEFT_LINE_A_LINE_30_X_END )  // modified
#define LEFT_LINE_A_LINE_31_X_END   (LEFT_LINE_A_LINE_31_X_START-1)
#define LEFT_LINE_A_LINE_31_Y_START LEFT_LINE_A_LINE_30_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_31_Y_END   (LEFT_LINE_A_LINE_31_Y_START-11)

#define LEFT_LINE_A_LINE_32_X_START (LEFT_LINE_A_LINE_31_X_END )  // modified
#define LEFT_LINE_A_LINE_32_X_END   (LEFT_LINE_A_LINE_32_X_START-2)
#define LEFT_LINE_A_LINE_32_Y_START LEFT_LINE_A_LINE_31_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_32_Y_END   (LEFT_LINE_A_LINE_32_Y_START-11)

#define LEFT_LINE_A_LINE_33_X_START (LEFT_LINE_A_LINE_32_X_END )  // modified
#define LEFT_LINE_A_LINE_33_X_END   (LEFT_LINE_A_LINE_33_X_START-1)
#define LEFT_LINE_A_LINE_33_Y_START LEFT_LINE_A_LINE_32_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_33_Y_END   (LEFT_LINE_A_LINE_33_Y_START-11)

#define LEFT_LINE_A_LINE_34_X_START (LEFT_LINE_A_LINE_33_X_END )  // modified
#define LEFT_LINE_A_LINE_34_X_END   (LEFT_LINE_A_LINE_34_X_START-2)
#define LEFT_LINE_A_LINE_34_Y_START LEFT_LINE_A_LINE_33_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_34_Y_END   (LEFT_LINE_A_LINE_34_Y_START-11)

#define LEFT_LINE_A_LINE_35_X_START (LEFT_LINE_A_LINE_34_X_END )  // modified
#define LEFT_LINE_A_LINE_35_X_END   (LEFT_LINE_A_LINE_35_X_START-1)
#define LEFT_LINE_A_LINE_35_Y_START LEFT_LINE_A_LINE_34_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_35_Y_END   (LEFT_LINE_A_LINE_35_Y_START-11)

#define LEFT_LINE_A_LINE_36_X_START (LEFT_LINE_A_LINE_35_X_END )  // modified
#define LEFT_LINE_A_LINE_36_X_END   (LEFT_LINE_A_LINE_36_X_START-2)
#define LEFT_LINE_A_LINE_36_Y_START LEFT_LINE_A_LINE_35_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_36_Y_END   (LEFT_LINE_A_LINE_36_Y_START-11)

#define LEFT_LINE_A_LINE_37_X_START (LEFT_LINE_A_LINE_36_X_END )  // modified
#define LEFT_LINE_A_LINE_37_X_END   (LEFT_LINE_A_LINE_37_X_START-1)
#define LEFT_LINE_A_LINE_37_Y_START LEFT_LINE_A_LINE_36_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_37_Y_END   (LEFT_LINE_A_LINE_37_Y_START-11)

#define LEFT_LINE_A_LINE_38_X_START (LEFT_LINE_A_LINE_37_X_END )  // modified
#define LEFT_LINE_A_LINE_38_X_END   (LEFT_LINE_A_LINE_38_X_START-1)
#define LEFT_LINE_A_LINE_38_Y_START LEFT_LINE_A_LINE_37_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_38_Y_END   (LEFT_LINE_A_LINE_38_Y_START-11)

#define LEFT_LINE_A_LINE_39_X_START (LEFT_LINE_A_LINE_38_X_END )  // modified
#define LEFT_LINE_A_LINE_39_X_END   (LEFT_LINE_A_LINE_39_X_START-1)
#define LEFT_LINE_A_LINE_39_Y_START LEFT_LINE_A_LINE_38_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_39_Y_END   (LEFT_LINE_A_LINE_39_Y_START-11)

#define LEFT_LINE_A_LINE_40_X_START (LEFT_LINE_A_LINE_39_X_END )  // modified
#define LEFT_LINE_A_LINE_40_X_END   (LEFT_LINE_A_LINE_40_X_START-2 )
#define LEFT_LINE_A_LINE_40_Y_START LEFT_LINE_A_LINE_39_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_40_Y_END   (LEFT_LINE_A_LINE_40_Y_START-11)

#define LEFT_LINE_A_LINE_41_X_START (LEFT_LINE_A_LINE_40_X_END )  // modified
#define LEFT_LINE_A_LINE_41_X_END   (LEFT_LINE_A_LINE_41_X_START +1  )
#define LEFT_LINE_A_LINE_41_Y_START LEFT_LINE_A_LINE_40_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_41_Y_END   (LEFT_LINE_A_LINE_41_Y_START-11)

#define LEFT_LINE_A_LINE_42_X_START (LEFT_LINE_A_LINE_41_X_END -1 )  // modified
#define LEFT_LINE_A_LINE_42_X_END   (LEFT_LINE_A_LINE_42_X_START+1 )
#define LEFT_LINE_A_LINE_42_Y_START LEFT_LINE_A_LINE_41_Y_END //+ 1  + 1     // modified
#define LEFT_LINE_A_LINE_42_Y_END   (LEFT_LINE_A_LINE_42_Y_START-11)

#define LEFT_LINE_A_LINE_43_X_START (LEFT_LINE_A_LINE_42_X_END )  // modified
#define LEFT_LINE_A_LINE_43_X_END   (LEFT_LINE_A_LINE_43_X_START+3 + 1 )
#define LEFT_LINE_A_LINE_43_Y_START LEFT_LINE_A_LINE_42_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_43_Y_END   (LEFT_LINE_A_LINE_43_Y_START-11)

#define LEFT_LINE_A_LINE_44_X_START (LEFT_LINE_A_LINE_43_X_END )  // modified
#define LEFT_LINE_A_LINE_44_X_END   (LEFT_LINE_A_LINE_44_X_START+3 )
#define LEFT_LINE_A_LINE_44_Y_START LEFT_LINE_A_LINE_43_Y_END + 1  + 1     // modified
#define LEFT_LINE_A_LINE_44_Y_END   (LEFT_LINE_A_LINE_44_Y_START-6)

#define LEFT_LINE_A_LINE_45_X_START (LEFT_LINE_A_LINE_44_X_END -1 )  // modified
#define LEFT_LINE_A_LINE_45_X_END   (LEFT_LINE_A_LINE_45_X_START+4 )
#define LEFT_LINE_A_LINE_45_Y_START LEFT_LINE_A_LINE_44_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_45_Y_END   (LEFT_LINE_A_LINE_45_Y_START-6)

#define LEFT_LINE_A_LINE_46_X_START (LEFT_LINE_A_LINE_45_X_END -1 )  // modified
#define LEFT_LINE_A_LINE_46_X_END   (LEFT_LINE_A_LINE_46_X_START+4 )
#define LEFT_LINE_A_LINE_46_Y_START LEFT_LINE_A_LINE_45_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_46_Y_END   (LEFT_LINE_A_LINE_46_Y_START-3)

#define LEFT_LINE_A_LINE_47_X_START (LEFT_LINE_A_LINE_46_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_47_X_END   (LEFT_LINE_A_LINE_47_X_START+4 )
#define LEFT_LINE_A_LINE_47_Y_START LEFT_LINE_A_LINE_46_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_47_Y_END   (LEFT_LINE_A_LINE_47_Y_START-4)

#define LEFT_LINE_A_LINE_48_X_START (LEFT_LINE_A_LINE_47_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_48_X_END   (LEFT_LINE_A_LINE_48_X_START+7 )
#define LEFT_LINE_A_LINE_48_Y_START LEFT_LINE_A_LINE_47_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_48_Y_END   (LEFT_LINE_A_LINE_48_Y_START-4)

#define LEFT_LINE_A_LINE_49_X_START (LEFT_LINE_A_LINE_48_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_49_X_END   (LEFT_LINE_A_LINE_49_X_START+11 )
#define LEFT_LINE_A_LINE_49_Y_START LEFT_LINE_A_LINE_48_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_49_Y_END   (LEFT_LINE_A_LINE_49_Y_START-7)

#define LEFT_LINE_A_LINE_50_X_START (LEFT_LINE_A_LINE_49_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_50_X_END   (LEFT_LINE_A_LINE_50_X_START+11 )
#define LEFT_LINE_A_LINE_50_Y_START LEFT_LINE_A_LINE_49_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_50_Y_END   (LEFT_LINE_A_LINE_50_Y_START-5)

#define LEFT_LINE_A_LINE_51_X_START (LEFT_LINE_A_LINE_50_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_51_X_END   (LEFT_LINE_A_LINE_51_X_START+11 )
#define LEFT_LINE_A_LINE_51_Y_START LEFT_LINE_A_LINE_50_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_51_Y_END   (LEFT_LINE_A_LINE_51_Y_START-5)

#define LEFT_LINE_A_LINE_52_X_START (LEFT_LINE_A_LINE_51_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_52_X_END   (LEFT_LINE_A_LINE_52_X_START+11 )
#define LEFT_LINE_A_LINE_52_Y_START LEFT_LINE_A_LINE_51_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_52_Y_END   (LEFT_LINE_A_LINE_52_Y_START-5)

#define LEFT_LINE_A_LINE_53_X_START (LEFT_LINE_A_LINE_52_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_53_X_END   (LEFT_LINE_A_LINE_53_X_START+11 )
#define LEFT_LINE_A_LINE_53_Y_START LEFT_LINE_A_LINE_52_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_53_Y_END   (LEFT_LINE_A_LINE_53_Y_START-3)

#define LEFT_LINE_A_LINE_54_X_START (LEFT_LINE_A_LINE_53_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_54_X_END   (LEFT_LINE_A_LINE_54_X_START+11 )
#define LEFT_LINE_A_LINE_54_Y_START LEFT_LINE_A_LINE_53_Y_END       // modified
#define LEFT_LINE_A_LINE_54_Y_END   (LEFT_LINE_A_LINE_54_Y_START-4)

#define LEFT_LINE_A_LINE_55_X_START (LEFT_LINE_A_LINE_54_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_55_X_END   (LEFT_LINE_A_LINE_55_X_START+11 )
#define LEFT_LINE_A_LINE_55_Y_START LEFT_LINE_A_LINE_54_Y_END + 1      // modified
#define LEFT_LINE_A_LINE_55_Y_END   (LEFT_LINE_A_LINE_55_Y_START-3)

#define LEFT_LINE_A_LINE_56_X_START (LEFT_LINE_A_LINE_55_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_56_X_END   (LEFT_LINE_A_LINE_56_X_START+11 )
#define LEFT_LINE_A_LINE_56_Y_START LEFT_LINE_A_LINE_55_Y_END       // modified
#define LEFT_LINE_A_LINE_56_Y_END   (LEFT_LINE_A_LINE_56_Y_START-3)

#define LEFT_LINE_A_LINE_57_X_START (LEFT_LINE_A_LINE_56_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_57_X_END   (LEFT_LINE_A_LINE_57_X_START+11 )
#define LEFT_LINE_A_LINE_57_Y_START LEFT_LINE_A_LINE_56_Y_END       // modified
#define LEFT_LINE_A_LINE_57_Y_END   (LEFT_LINE_A_LINE_57_Y_START-4)

#define LEFT_LINE_A_LINE_58_X_START (LEFT_LINE_A_LINE_57_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_58_X_END   (LEFT_LINE_A_LINE_58_X_START+11 )
#define LEFT_LINE_A_LINE_58_Y_START LEFT_LINE_A_LINE_57_Y_END  +1     // modified
#define LEFT_LINE_A_LINE_58_Y_END   (LEFT_LINE_A_LINE_58_Y_START-3)

#define LEFT_LINE_A_LINE_59_X_START (LEFT_LINE_A_LINE_58_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_59_X_END   (LEFT_LINE_A_LINE_59_X_START+11 )
#define LEFT_LINE_A_LINE_59_Y_START LEFT_LINE_A_LINE_58_Y_END       // modified
#define LEFT_LINE_A_LINE_59_Y_END   (LEFT_LINE_A_LINE_59_Y_START-4)

#define LEFT_LINE_A_LINE_60_X_START (LEFT_LINE_A_LINE_59_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_60_X_END   (LEFT_LINE_A_LINE_60_X_START+11 )
#define LEFT_LINE_A_LINE_60_Y_START LEFT_LINE_A_LINE_59_Y_END  + 1     // modified
#define LEFT_LINE_A_LINE_60_Y_END   (LEFT_LINE_A_LINE_60_Y_START-3)

#define LEFT_LINE_A_LINE_61_X_START (LEFT_LINE_A_LINE_60_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_61_X_END   (LEFT_LINE_A_LINE_61_X_START+11 )
#define LEFT_LINE_A_LINE_61_Y_START LEFT_LINE_A_LINE_60_Y_END       // modified
#define LEFT_LINE_A_LINE_61_Y_END   (LEFT_LINE_A_LINE_61_Y_START-3)

#define LEFT_LINE_A_LINE_62_X_START (LEFT_LINE_A_LINE_61_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_62_X_END   (LEFT_LINE_A_LINE_62_X_START+11 )
#define LEFT_LINE_A_LINE_62_Y_START LEFT_LINE_A_LINE_61_Y_END       // modified
#define LEFT_LINE_A_LINE_62_Y_END   (LEFT_LINE_A_LINE_62_Y_START-4)

#define LEFT_LINE_A_LINE_63_X_START (LEFT_LINE_A_LINE_62_X_END -2 )  // modified
#define LEFT_LINE_A_LINE_63_X_END   (LEFT_LINE_A_LINE_63_X_START+11 )
#define LEFT_LINE_A_LINE_63_Y_START LEFT_LINE_A_LINE_62_Y_END  + 1     // modified
#define LEFT_LINE_A_LINE_63_Y_END   (LEFT_LINE_A_LINE_63_Y_START-4)

uint8_t left_draw_line_1_first_draw_forward = 1;
uint8_t left_draw_line_1_first_draw_forward_switch = 1;
uint8_t left_draw_line_1_draw_backward_switch = 0;
uint8_t left_draw_line_1_draw_backward_switch_case = 0;
uint8_t left_draw_line_1_draw_forward_switch = 0;
uint8_t left_draw_line_1_draw_forward_switch_case = 0;
uint8_t line_1_start_timer;
uint8_t line_1_start_timer_exp;

extern volatile uint32_t drawing_screen;
extern volatile uint32_t drawing_screen_inc_enable;
extern volatile uint8_t  left_start_drawing;
extern volatile uint8_t right_start_drawing;

volatile uint8_t left_init_entry;

//#define LEFT_DRAW_LINE_1_COLOR_RED 1

void left_draw_line_1(void)
{
//static lv_point_t line_points[] = { {214, 369}, {88, 357}};
//
//    /*Create style*/
//    static lv_style_t style_line;
//    lv_style_init(&style_line);
//    lv_style_set_line_width(&style_line, 12);
//    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
//    lv_style_set_line_rounded(&style_line, false);
//
//    /*Create a line and apply the new style*/
//    lv_obj_t * line1;
//    line1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//    lv_line_set_points(line1, line_points, 2);     /*Set the points*/
//    lv_obj_add_style(line1, &style_line, 0);
//    //lv_obj_center(line1);

	if(left_init_entry == 0)
	{
		line_1_start_timer = 1;
		line_1_start_timer_exp = 1;
		left_draw_line_1_first_draw_forward = 1;

		left_init_entry = 1;
	}

#ifndef LEFT_DRAW_LINE_1_COLOR_RED
	lv_color_t first_line_color = LV_COLOR_MAKE(0,0,255);
#endif
	//lv_color_t last_line_color = LV_COLOR_MAKE(254,43,43);
	lv_color_t last_line_color = LV_COLOR_MAKE(168,16,31);
	//lv_color_t last_line_color = LV_COLOR_MAKE(255,85,85);
	//lv_color_t last_line_color = LV_COLOR_MAKE(255,0,0);

//	static lv_style_t style_line_L_11;
//	lv_style_init(&style_line_L_11);
//	lv_style_set_line_rounded(&style_line_L_11, false);

//	static lv_style_t style_line_L_fix;
//	lv_style_init(&style_line_L_fix);
//	lv_style_set_line_rounded(&style_line_L_fix, false);
//
//	static lv_style_t style_line_L_fix_temp;
//	lv_style_init(&style_line_L_fix_temp);
//	lv_style_set_line_rounded(&style_line_L_fix_temp, false);

	//left_draw_line_1_first_draw_forward_switch = 13;
	//while(1)
	if(left_start_drawing)
	{
		if(line_1_start_timer_exp)
		{
			//while(1)
			if(left_draw_line_1_first_draw_forward)
			{
				switch(left_draw_line_1_first_draw_forward_switch)
				{

				case 1 :
					;
					// Line - 1
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = -(10+1)
					// starting -- x = prev line ending (x +1)
					//static lv_point_t line_points[] = { {214, 369}, {203, 368}};
					static lv_point_t line_points_L_0[] = { {LEFT_LINE_A_LINE_1_X_START, LEFT_LINE_A_LINE_1_Y_START}, {LEFT_LINE_A_LINE_1_X_END, LEFT_LINE_A_LINE_1_Y_END}};
					//lv_color_t
					/*Create style*/
					static lv_style_t style_line;
					lv_style_init(&style_line);
					lv_style_set_line_width(&style_line, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line, 56);
					lv_style_set_line_color(&style_line, first_line_color);
#else
					lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line1;
					guider_ui.line1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line1, line_points_L_0, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line1, &style_line, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 2 :
					;
					// Line - 2
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					//static lv_point_t line_points_L_1[] = { {204, 368}, {193, 367}};
					static lv_point_t line_points_L_1[] = { {LEFT_LINE_A_LINE_2_X_START, LEFT_LINE_A_LINE_2_Y_START}, {LEFT_LINE_A_LINE_2_X_END, LEFT_LINE_A_LINE_2_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_1;
					lv_style_init(&style_line_L_1);
					lv_style_set_line_width(&style_line_L_1, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_1, 56);
					lv_style_set_line_color(&style_line_L_1, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_1, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_1, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line2;
					guider_ui.line2 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line2, line_points_L_1, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line2, &style_line_L_1, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 3 :
					;
					// Line - 3
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t line_points_L_2[] = { {LEFT_LINE_A_LINE_3_X_START, LEFT_LINE_A_LINE_3_Y_START}, {LEFT_LINE_A_LINE_3_X_END, LEFT_LINE_A_LINE_3_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_2;
					lv_style_init(&style_line_L_2);
					lv_style_set_line_width(&style_line_L_2, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					////lv_style_set_line_opa(&style_line_L_2, 56);
					lv_style_set_line_color(&style_line_L_2, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_2, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_2, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line3;
					guider_ui.line3 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line3, line_points_L_2, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line3, &style_line_L_2, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 4 :
					;
					// Line - 4
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t line_points_L_3[] = { {LEFT_LINE_A_LINE_4_X_START, LEFT_LINE_A_LINE_4_Y_START}, {LEFT_LINE_A_LINE_4_X_END, LEFT_LINE_A_LINE_4_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_3;
					lv_style_init(&style_line_L_3);
					lv_style_set_line_width(&style_line_L_3, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_3, 56);
					lv_style_set_line_color(&style_line_L_3, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_3, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_3, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line4;
					guider_ui.line4 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line4, line_points_L_3, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line4, &style_line_L_3, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 5 :
					;
					// Line - 5
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t line_points_L_4[] = { {LEFT_LINE_A_LINE_5_X_START, LEFT_LINE_A_LINE_5_Y_START}, {LEFT_LINE_A_LINE_5_X_END, LEFT_LINE_A_LINE_5_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_4;
					lv_style_init(&style_line_L_4);
					lv_style_set_line_width(&style_line_L_4, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_4, 56);
					lv_style_set_line_color(&style_line_L_4, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_4, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_4, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line5;
					guider_ui.line5 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line5, line_points_L_4, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line5, &style_line_L_4, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 6 :
					;
					// Line - 6
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t line_points_L_5[] = { {LEFT_LINE_A_LINE_6_X_START, LEFT_LINE_A_LINE_6_Y_START}, {LEFT_LINE_A_LINE_6_X_END, LEFT_LINE_A_LINE_6_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_5;
					lv_style_init(&style_line_L_5);
					lv_style_set_line_width(&style_line_L_5, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_5, 56);
					lv_style_set_line_color(&style_line_L_5, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_5, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_5, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line6;
					guider_ui.line6 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line6, line_points_L_5, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line6, &style_line_L_5, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 7 :
					;
					// Line - 7
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t line_points_L_6[] = { {LEFT_LINE_A_LINE_7_X_START, LEFT_LINE_A_LINE_7_Y_START}, {LEFT_LINE_A_LINE_7_X_END, LEFT_LINE_A_LINE_7_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_6;
					lv_style_init(&style_line_L_6);
					lv_style_set_line_width(&style_line_L_6, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_6, 56);
					lv_style_set_line_color(&style_line_L_6, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_6, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_6, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line7;
					guider_ui.line7 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line7, line_points_L_6, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line7, &style_line_L_6, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 8 :
					;
					// Line - 8
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t line_points_L_7[] = { {LEFT_LINE_A_LINE_8_X_START, LEFT_LINE_A_LINE_8_Y_START}, {LEFT_LINE_A_LINE_8_X_END, LEFT_LINE_A_LINE_8_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_7;
					lv_style_init(&style_line_L_7);
					lv_style_set_line_width(&style_line_L_7, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_7, 56);
					lv_style_set_line_color(&style_line_L_7, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_7, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_7, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line8;
					guider_ui.line8 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line8, line_points_L_7, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line8, &style_line_L_7, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 9 :
					;
					// Line - 9
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t line_points_L_8[] = { {LEFT_LINE_A_LINE_9_X_START, LEFT_LINE_A_LINE_9_Y_START}, {LEFT_LINE_A_LINE_9_X_END, LEFT_LINE_A_LINE_9_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_8;
					lv_style_init(&style_line_L_8);
					lv_style_set_line_width(&style_line_L_8, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_8, 56);
					lv_style_set_line_color(&style_line_L_8, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_8, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_8, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line9;
					guider_ui.line9 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line9, line_points_L_8, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line9, &style_line_L_8, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 10 :
					;
					// Line - 10
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t line_points_L_9[] = { {LEFT_LINE_A_LINE_10_X_START, LEFT_LINE_A_LINE_10_Y_START}, {LEFT_LINE_A_LINE_10_X_END, LEFT_LINE_A_LINE_10_Y_END}};
					/*Create style*/
					static lv_style_t style_line_L_9;
					lv_style_init(&style_line_L_9);
					lv_style_set_line_width(&style_line_L_9, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_9, 56);
					lv_style_set_line_color(&style_line_L_9, first_line_color);
#else
					lv_style_set_line_color(&style_line_L_9, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&style_line_L_9, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line10;
					guider_ui.line10 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line10, line_points_L_9, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line10, &style_line_L_9, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display

					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 11 :
					;
					// Line - 11
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t temp_line_points_L_11[] = { {LEFT_LINE_A_LINE_11_X_START, LEFT_LINE_A_LINE_11_Y_START}, {LEFT_LINE_A_LINE_11_X_END, LEFT_LINE_A_LINE_11_Y_END}};
					/*Create style*/
//					static lv_style_t style_line_L_11;
//					lv_style_init(&style_line_L_11);
					static lv_style_t temp_style_line_L_11;
					lv_style_init(&temp_style_line_L_11);
					lv_style_set_line_rounded(&temp_style_line_L_11, false);
					lv_style_set_line_width(&temp_style_line_L_11, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_9, 56);
					lv_style_set_line_color(&temp_style_line_L_11, first_line_color);
#else
					lv_style_set_line_color(&temp_style_line_L_11, lv_palette_main(LV_PALETTE_RED));
#endif
					//lv_style_set_line_color(&temp_style_line_L_11, lv_palette_main(LV_PALETTE_RED));
//					lv_style_set_line_rounded(&temp_style_line_L_11, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line11;
					guider_ui.line11 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line11, temp_line_points_L_11, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line11, &temp_style_line_L_11, 0);
					//lv_obj_center(line1);
					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 12 :
					;
					// Line - 12
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t temp_line_points_L_12[] = { {LEFT_LINE_A_LINE_12_X_START, LEFT_LINE_A_LINE_12_Y_START}, {LEFT_LINE_A_LINE_12_X_END, LEFT_LINE_A_LINE_12_Y_END}};
					/*Create style*/
//					static lv_style_t style_line_L_fix;
//					lv_style_init(&style_line_L_fix);
					static lv_style_t temp_style_line_L_12;
					lv_style_init(&temp_style_line_L_12);
					lv_style_set_line_rounded(&temp_style_line_L_12, false);
					lv_style_set_line_width(&temp_style_line_L_12, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&style_line_L_9, 56);
					lv_style_set_line_color(&temp_style_line_L_12, first_line_color);
#else
					lv_style_set_line_color(&temp_style_line_L_12, lv_palette_main(LV_PALETTE_RED));
#endif
//					lv_style_set_line_rounded(&style_line_L_fix, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line12;
					guider_ui.line12 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line12, temp_line_points_L_12, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.line12, &temp_style_line_L_12, 0);
					//lv_obj_center(line1);

					left_draw_line_1_first_draw_forward_switch++;
					break;

				case 13 :
					;
					static lv_point_t line_points_L_13[] = { {LEFT_LINE_A_LINE_13_X_START, LEFT_LINE_A_LINE_13_Y_START}, {LEFT_LINE_A_LINE_13_X_END, LEFT_LINE_A_LINE_13_Y_END}};
    				guider_ui.line13 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line13, line_points_L_13, 2);     /*Set the points*/
					static lv_style_t style_line_L_13;
					lv_style_init(&style_line_L_13);
					lv_style_set_line_rounded(&style_line_L_13, true);
					lv_style_set_line_width(&style_line_L_13, 12);
					lv_style_set_line_color(&style_line_L_13, first_line_color);
	    			lv_obj_add_style(guider_ui.line13, &style_line_L_13, 0);

	    			//lv_task_handler();  // Update the display

	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 14 :
					;

					static lv_point_t line_points_L_14[] = { {LEFT_LINE_A_LINE_14_X_START, LEFT_LINE_A_LINE_14_Y_START}, {LEFT_LINE_A_LINE_14_X_END, LEFT_LINE_A_LINE_14_Y_END}};
    				guider_ui.line14 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line14, line_points_L_14, 2);     /*Set the points*/
					static lv_style_t style_line_L_14;
					lv_style_init(&style_line_L_14);
					lv_style_set_line_rounded(&style_line_L_14, true);
					lv_style_set_line_width(&style_line_L_14, 12);
					lv_style_set_line_color(&style_line_L_14, first_line_color);
	    			lv_obj_add_style(guider_ui.line14, &style_line_L_14, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 15 :
					;
					static lv_point_t line_points_L_15[] = { {LEFT_LINE_A_LINE_15_X_START, LEFT_LINE_A_LINE_15_Y_START}, {LEFT_LINE_A_LINE_15_X_END, LEFT_LINE_A_LINE_15_Y_END}};
    				guider_ui.line15 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line15, line_points_L_15, 2);     /*Set the points*/
					static lv_style_t style_line_L_15;
					lv_style_init(&style_line_L_15);
					lv_style_set_line_rounded(&style_line_L_15, true);
					lv_style_set_line_width(&style_line_L_15, 12);
					lv_style_set_line_color(&style_line_L_15, first_line_color);
	    			lv_obj_add_style(guider_ui.line15, &style_line_L_15, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 16 :
					;
					static lv_point_t line_points_L_16[] = { {LEFT_LINE_A_LINE_16_X_START, LEFT_LINE_A_LINE_16_Y_START}, {LEFT_LINE_A_LINE_16_X_END, LEFT_LINE_A_LINE_16_Y_END}};
    				guider_ui.line16 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line16, line_points_L_16, 2);     /*Set the points*/
					static lv_style_t style_line_L_16;
					lv_style_init(&style_line_L_16);
					lv_style_set_line_rounded(&style_line_L_16, true);
					lv_style_set_line_width(&style_line_L_16, 12);
					lv_style_set_line_color(&style_line_L_16, first_line_color);
	    			lv_obj_add_style(guider_ui.line16, &style_line_L_16, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 17 :
					;
					static lv_point_t line_points_L_17[] = { {LEFT_LINE_A_LINE_17_X_START, LEFT_LINE_A_LINE_17_Y_START}, {LEFT_LINE_A_LINE_17_X_END, LEFT_LINE_A_LINE_17_Y_END}};
    				guider_ui.line17 = lv_line_create(guider_ui.screen_drawing_container_drawing);
    				lv_line_set_points(guider_ui.line17, line_points_L_17, 2);     /*Set the points*/
					static lv_style_t style_line_L_17;
					lv_style_init(&style_line_L_17);
					lv_style_set_line_rounded(&style_line_L_17, true);
					lv_style_set_line_width(&style_line_L_17, 14);
					lv_style_set_line_color(&style_line_L_17, first_line_color);
	    			lv_obj_add_style(guider_ui.line17, &style_line_L_17, 0);

					//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 18 :
					;
					static lv_point_t line_points_L_18[] = { {LEFT_LINE_A_LINE_18_X_START, LEFT_LINE_A_LINE_18_Y_START}, {LEFT_LINE_A_LINE_18_X_END, LEFT_LINE_A_LINE_18_Y_END}};
    				guider_ui.line18 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line18, line_points_L_18, 2);     /*Set the points*/
					static lv_style_t style_line_L_18;
					lv_style_init(&style_line_L_18);
					lv_style_set_line_rounded(&style_line_L_18, true);
					lv_style_set_line_width(&style_line_L_18, 14);
					lv_style_set_line_color(&style_line_L_18, first_line_color);
	    			lv_obj_add_style(guider_ui.line18, &style_line_L_18, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 19 :
					;
					static lv_point_t line_points_L_19[] = { {LEFT_LINE_A_LINE_19_X_START, LEFT_LINE_A_LINE_19_Y_START}, {LEFT_LINE_A_LINE_19_X_END, LEFT_LINE_A_LINE_19_Y_END}};
    				guider_ui.line19 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line19, line_points_L_19, 2);     /*Set the points*/
					static lv_style_t style_line_L_19;
					lv_style_init(&style_line_L_19);
					lv_style_set_line_rounded(&style_line_L_19, true);
					lv_style_set_line_width(&style_line_L_19, 14);
					lv_style_set_line_color(&style_line_L_19, first_line_color);
	    			lv_obj_add_style(guider_ui.line19, &style_line_L_19, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 20 :
					;
					static lv_point_t line_points_L_20[] = { {LEFT_LINE_A_LINE_20_X_START, LEFT_LINE_A_LINE_20_Y_START}, {LEFT_LINE_A_LINE_20_X_END, LEFT_LINE_A_LINE_20_Y_END}};
    				guider_ui.line20 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line20, line_points_L_20, 2);     /*Set the points*/
					static lv_style_t style_line_L_20;
					lv_style_init(&style_line_L_20);
					lv_style_set_line_rounded(&style_line_L_20, true);
					lv_style_set_line_width(&style_line_L_20, 14);
					lv_style_set_line_color(&style_line_L_20, first_line_color);
	    			lv_obj_add_style(guider_ui.line20, &style_line_L_20, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 21 :
					;
					static lv_point_t line_points_L_21[] = { {LEFT_LINE_A_LINE_21_X_START, LEFT_LINE_A_LINE_21_Y_START}, {LEFT_LINE_A_LINE_21_X_END, LEFT_LINE_A_LINE_21_Y_END}};
    				guider_ui.line21 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line21, line_points_L_21, 2);     /*Set the points*/
					static lv_style_t style_line_L_21;
					lv_style_init(&style_line_L_21);
					lv_style_set_line_rounded(&style_line_L_21, true);
					lv_style_set_line_width(&style_line_L_21, 14);
					lv_style_set_line_color(&style_line_L_21, first_line_color);
	    			lv_obj_add_style(guider_ui.line21, &style_line_L_21, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 22 :
					;
	    			/// bunch
	    			static lv_point_t line_points_L_22[] = { {LEFT_LINE_A_LINE_22_X_START, LEFT_LINE_A_LINE_22_Y_START}, {LEFT_LINE_A_LINE_22_X_END, LEFT_LINE_A_LINE_22_Y_END}};
	    			guider_ui.line22 = lv_line_create(guider_ui.screen_drawing_container_drawing);
	    			lv_line_set_points(guider_ui.line22, line_points_L_22, 2);     /*Set the points*/
					static lv_style_t style_line_L_22;
					lv_style_init(&style_line_L_22);
					lv_style_set_line_rounded(&style_line_L_22, true);
					lv_style_set_line_width(&style_line_L_22, 14);
					lv_style_set_line_color(&style_line_L_22, first_line_color);
	    			lv_obj_add_style(guider_ui.line22, &style_line_L_22, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 23 :
					;
					static lv_point_t line_points_L_23[] = { {LEFT_LINE_A_LINE_23_X_START, (LEFT_LINE_A_LINE_23_Y_START-2)}, {LEFT_LINE_A_LINE_23_X_END, LEFT_LINE_A_LINE_23_Y_END}};
    				guider_ui.line23 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line23, line_points_L_23, 2);     /*Set the points*/
					static lv_style_t style_line_L_23;
					lv_style_init(&style_line_L_23);
					lv_style_set_line_rounded(&style_line_L_23, true);
					lv_style_set_line_width(&style_line_L_23, 14);
					lv_style_set_line_color(&style_line_L_23, first_line_color);
	    			lv_obj_add_style(guider_ui.line23, &style_line_L_23, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;

					break;

				case 24 :
					;
					static lv_point_t line_points_L_24[] = { {LEFT_LINE_A_LINE_24_X_START, (LEFT_LINE_A_LINE_24_Y_START-2)}, {LEFT_LINE_A_LINE_24_X_END, LEFT_LINE_A_LINE_24_Y_END}};
    				guider_ui.line24 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line24, line_points_L_24, 2);     /*Set the points*/
					static lv_style_t style_line_L_24;
					lv_style_init(&style_line_L_24);
					lv_style_set_line_rounded(&style_line_L_24, true);
					lv_style_set_line_width(&style_line_L_24, 14);
					lv_style_set_line_color(&style_line_L_24, first_line_color);
	    			lv_obj_add_style(guider_ui.line24, &style_line_L_24, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 25 :
					;
					static lv_point_t line_points_L_25[] = { {LEFT_LINE_A_LINE_25_X_START, LEFT_LINE_A_LINE_25_Y_START}, {LEFT_LINE_A_LINE_25_X_END, LEFT_LINE_A_LINE_25_Y_END}};
    				guider_ui.line25 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line25, line_points_L_25, 2);     /*Set the points*/
					static lv_style_t style_line_L_25;
					lv_style_init(&style_line_L_25);
					lv_style_set_line_rounded(&style_line_L_25, true);
					lv_style_set_line_width(&style_line_L_25, 14);
					lv_style_set_line_color(&style_line_L_25, first_line_color);
	    			lv_obj_add_style(guider_ui.line25, &style_line_L_25, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 26 :
					;
					static lv_point_t line_points_L_26[] = { {LEFT_LINE_A_LINE_26_X_START, LEFT_LINE_A_LINE_26_Y_START}, {LEFT_LINE_A_LINE_26_X_END, LEFT_LINE_A_LINE_26_Y_END}};
    				guider_ui.line26 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line26, line_points_L_26, 2);     /*Set the points*/
					static lv_style_t style_line_L_26;
					lv_style_init(&style_line_L_26);
					lv_style_set_line_rounded(&style_line_L_26, true);
					lv_style_set_line_width(&style_line_L_26, 14);
					lv_style_set_line_color(&style_line_L_26, first_line_color);
	    			lv_obj_add_style(guider_ui.line26, &style_line_L_26, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

					//bunch
				case 27 :
					;

					static lv_point_t line_points_L_27[] = { {LEFT_LINE_A_LINE_27_X_START, LEFT_LINE_A_LINE_27_Y_START}, {LEFT_LINE_A_LINE_27_X_END, LEFT_LINE_A_LINE_27_Y_END}};
    				guider_ui.line27 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line27, line_points_L_27, 2);     /*Set the points*/
					static lv_style_t style_line_L_27;
					lv_style_init(&style_line_L_27);
					lv_style_set_line_rounded(&style_line_L_27, true);
					lv_style_set_line_width(&style_line_L_27, 14);
					lv_style_set_line_color(&style_line_L_27, first_line_color);
	    			lv_obj_add_style(guider_ui.line27, &style_line_L_27, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_28[] = { {LEFT_LINE_A_LINE_28_X_START, LEFT_LINE_A_LINE_28_Y_START}, {(LEFT_LINE_A_LINE_28_X_END-1), LEFT_LINE_A_LINE_28_Y_END}};
    				guider_ui.line28 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line28, line_points_L_28, 2);     /*Set the points*/
					static lv_style_t style_line_L_28;
					lv_style_init(&style_line_L_28);
					lv_style_set_line_rounded(&style_line_L_28, true);
					lv_style_set_line_width(&style_line_L_28, 14);
					lv_style_set_line_color(&style_line_L_28, first_line_color);
	    			lv_obj_add_style(guider_ui.line28, &style_line_L_28, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 28 :
					;
					static lv_point_t line_points_L_29[] = { {LEFT_LINE_A_LINE_29_X_START, LEFT_LINE_A_LINE_29_Y_START}, {(LEFT_LINE_A_LINE_29_X_END-1), LEFT_LINE_A_LINE_29_Y_END}};
    				guider_ui.line29 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line29, line_points_L_29, 2);     /*Set the points*/
					static lv_style_t style_line_L_29;
					lv_style_init(&style_line_L_29);
					lv_style_set_line_width(&style_line_L_29, 16);
					lv_style_set_line_color(&style_line_L_29, first_line_color);
					lv_style_set_line_rounded(&style_line_L_29, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line29, &style_line_L_29, 0);

	    			//lv_task_handler();  // Update the display


					static lv_point_t line_points_L_30[] = { {LEFT_LINE_A_LINE_30_X_START, LEFT_LINE_A_LINE_30_Y_START}, {LEFT_LINE_A_LINE_30_X_END, LEFT_LINE_A_LINE_30_Y_END}};
    				guider_ui.line30 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line30, line_points_L_30, 2);     /*Set the points*/
					static lv_style_t style_line_L_30;
					lv_style_init(&style_line_L_30);
					lv_style_set_line_width(&style_line_L_30, 16);
					lv_style_set_line_color(&style_line_L_30, first_line_color);
					lv_style_set_line_rounded(&style_line_L_30, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line30, &style_line_L_30, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 29 :
					;

					static lv_point_t line_points_L_31[] = { {LEFT_LINE_A_LINE_31_X_START, LEFT_LINE_A_LINE_31_Y_START}, {LEFT_LINE_A_LINE_31_X_END, LEFT_LINE_A_LINE_31_Y_END}};
    				guider_ui.line31 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line31, line_points_L_31, 2);     /*Set the points*/
					static lv_style_t style_line_L_31;
					lv_style_init(&style_line_L_31);
					lv_style_set_line_width(&style_line_L_31, 16);
					lv_style_set_line_color(&style_line_L_31, first_line_color);
					lv_style_set_line_rounded(&style_line_L_31, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line31, &style_line_L_31, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_32[] = { {LEFT_LINE_A_LINE_32_X_START, LEFT_LINE_A_LINE_32_Y_START}, {LEFT_LINE_A_LINE_32_X_END, LEFT_LINE_A_LINE_32_Y_END}};
    				guider_ui.line32 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line32, line_points_L_32, 2);     /*Set the points*/
					static lv_style_t style_line_L_32;
					lv_style_init(&style_line_L_32);
					lv_style_set_line_width(&style_line_L_32, 16);
					lv_style_set_line_color(&style_line_L_32, first_line_color);
					lv_style_set_line_rounded(&style_line_L_32, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line32, &style_line_L_32, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 30 :
					;
					static lv_point_t line_points_L_33[] = { {LEFT_LINE_A_LINE_33_X_START, LEFT_LINE_A_LINE_33_Y_START}, {LEFT_LINE_A_LINE_33_X_END, LEFT_LINE_A_LINE_33_Y_END}};
    				guider_ui.line33 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line33, line_points_L_33, 2);     /*Set the points*/
					static lv_style_t style_line_L_33;
					lv_style_init(&style_line_L_33);
					lv_style_set_line_width(&style_line_L_33, 15);
					lv_style_set_line_color(&style_line_L_33, first_line_color);
					lv_style_set_line_rounded(&style_line_L_33, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line33, &style_line_L_33, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_34[] = { {LEFT_LINE_A_LINE_34_X_START, LEFT_LINE_A_LINE_34_Y_START}, {LEFT_LINE_A_LINE_34_X_END, LEFT_LINE_A_LINE_34_Y_END}};
    				guider_ui.line34 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line34, line_points_L_34, 2);     /*Set the points*/
					static lv_style_t style_line_L_34;
					lv_style_init(&style_line_L_34);
					lv_style_set_line_width(&style_line_L_34, 15);
					lv_style_set_line_color(&style_line_L_34, first_line_color);
					lv_style_set_line_rounded(&style_line_L_34, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line34, &style_line_L_34, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 31 :
					;
					static lv_point_t line_points_L_35[] = { {LEFT_LINE_A_LINE_35_X_START, LEFT_LINE_A_LINE_35_Y_START}, {LEFT_LINE_A_LINE_35_X_END, LEFT_LINE_A_LINE_35_Y_END}};
    				guider_ui.line35 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line35, line_points_L_35, 2);     /*Set the points*/
					static lv_style_t style_line_L_35;
					lv_style_init(&style_line_L_35);
					lv_style_set_line_width(&style_line_L_35, 15);
					lv_style_set_line_color(&style_line_L_35, first_line_color);
					lv_style_set_line_rounded(&style_line_L_35, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line35, &style_line_L_35, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_36[] = { {LEFT_LINE_A_LINE_36_X_START, LEFT_LINE_A_LINE_36_Y_START}, {LEFT_LINE_A_LINE_36_X_END, LEFT_LINE_A_LINE_36_Y_END}};
    				guider_ui.line36 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line36, line_points_L_36, 2);     /*Set the points*/
					static lv_style_t style_line_L_36;
					lv_style_init(&style_line_L_36);
					lv_style_set_line_width(&style_line_L_36, 15);
					lv_style_set_line_color(&style_line_L_36, first_line_color);
					lv_style_set_line_rounded(&style_line_L_36, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line36, &style_line_L_36, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 32 :
					;
					static lv_point_t line_points_L_37[] = { {LEFT_LINE_A_LINE_37_X_START, LEFT_LINE_A_LINE_37_Y_START}, {LEFT_LINE_A_LINE_37_X_END, LEFT_LINE_A_LINE_37_Y_END}};
    				guider_ui.line37 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line37, line_points_L_37, 2);     /*Set the points*/
					static lv_style_t style_line_L_37;
					lv_style_init(&style_line_L_37);
					lv_style_set_line_width(&style_line_L_37, 15);
					lv_style_set_line_color(&style_line_L_37, first_line_color);
					lv_style_set_line_rounded(&style_line_L_37, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line37, &style_line_L_37, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_38[] = { {LEFT_LINE_A_LINE_38_X_START, LEFT_LINE_A_LINE_38_Y_START}, {LEFT_LINE_A_LINE_38_X_END, LEFT_LINE_A_LINE_38_Y_END}};
    				guider_ui.line38 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line38, line_points_L_38, 2);     /*Set the points*/
					static lv_style_t style_line_L_38;
					lv_style_init(&style_line_L_38);
					lv_style_set_line_width(&style_line_L_38, 16);
					lv_style_set_line_color(&style_line_L_38, first_line_color);
					lv_style_set_line_rounded(&style_line_L_38, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line38, &style_line_L_38, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 33 :
					;
					static lv_point_t line_points_L_39[] = { {LEFT_LINE_A_LINE_39_X_START, LEFT_LINE_A_LINE_39_Y_START}, {LEFT_LINE_A_LINE_39_X_END, LEFT_LINE_A_LINE_39_Y_END}};
    				guider_ui.line39 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line39, line_points_L_39, 2);     /*Set the points*/
					static lv_style_t style_line_L_39;
					lv_style_init(&style_line_L_39);
					lv_style_set_line_width(&style_line_L_39, 16);
					lv_style_set_line_color(&style_line_L_39, first_line_color);
					lv_style_set_line_rounded(&style_line_L_39, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line39, &style_line_L_39, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_40[] = { {LEFT_LINE_A_LINE_40_X_START, LEFT_LINE_A_LINE_40_Y_START}, {LEFT_LINE_A_LINE_40_X_END, LEFT_LINE_A_LINE_40_Y_END}};
    				guider_ui.line40 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line40, line_points_L_40, 2);     /*Set the points*/
					static lv_style_t style_line_L_40;
					lv_style_init(&style_line_L_40);
					lv_style_set_line_width(&style_line_L_40, 17);
					lv_style_set_line_color(&style_line_L_40, first_line_color);
					lv_style_set_line_rounded(&style_line_L_40, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line40, &style_line_L_40, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 34 :
					;
					static lv_point_t line_points_L_41[] = { {LEFT_LINE_A_LINE_41_X_START, LEFT_LINE_A_LINE_41_Y_START}, {LEFT_LINE_A_LINE_41_X_END, LEFT_LINE_A_LINE_41_Y_END}};
    				guider_ui.line41 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line41, line_points_L_41, 2);     /*Set the points*/
					static lv_style_t style_line_L_41;
					lv_style_init(&style_line_L_41);
					lv_style_set_line_width(&style_line_L_41, 17);
					lv_style_set_line_color(&style_line_L_41, first_line_color);
					lv_style_set_line_rounded(&style_line_L_41, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line41, &style_line_L_41, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_42[] = { {LEFT_LINE_A_LINE_42_X_START, LEFT_LINE_A_LINE_42_Y_START}, {LEFT_LINE_A_LINE_42_X_END, LEFT_LINE_A_LINE_42_Y_END}};
    				guider_ui.line42 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line42, line_points_L_42, 2);     /*Set the points*/
					static lv_style_t style_line_L_42;
					lv_style_init(&style_line_L_42);
					lv_style_set_line_width(&style_line_L_42, 17);
					lv_style_set_line_color(&style_line_L_42, last_line_color);
					lv_style_set_line_rounded(&style_line_L_42, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line42, &style_line_L_42, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;

	    			// start drawing right screen
	    			right_start_drawing = 1;
					break;

				case 35 :
					;
					static lv_point_t line_points_L_43[] = { {LEFT_LINE_A_LINE_43_X_START, LEFT_LINE_A_LINE_43_Y_START}, {LEFT_LINE_A_LINE_43_X_END, LEFT_LINE_A_LINE_43_Y_END}};
    				guider_ui.line43 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line43, line_points_L_43, 2);     /*Set the points*/
					static lv_style_t style_line_L_43;
					lv_style_init(&style_line_L_43);
					lv_style_set_line_width(&style_line_L_43, 16);
					lv_style_set_line_color(&style_line_L_43, last_line_color);
					lv_style_set_line_rounded(&style_line_L_43, true); // rectangle false
	    			lv_obj_add_style(guider_ui.line43, &style_line_L_43, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_44[] = { {LEFT_LINE_A_LINE_44_X_START, LEFT_LINE_A_LINE_44_Y_START}, {LEFT_LINE_A_LINE_44_X_END, LEFT_LINE_A_LINE_44_Y_END}};
    				guider_ui.line44 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line44, line_points_L_44, 2);     /*Set the points*/
					static lv_style_t style_line_L_44;
					lv_style_init(&style_line_L_44);
					lv_style_set_line_width(&style_line_L_44, 16);
					lv_style_set_line_color(&style_line_L_44, last_line_color);
					lv_style_set_line_rounded(&style_line_L_44, true); // rectangle false
	    			lv_obj_add_style(guider_ui.line44, &style_line_L_44, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 36 :
					;
					static lv_point_t line_points_L_45[] = { {LEFT_LINE_A_LINE_45_X_START, LEFT_LINE_A_LINE_45_Y_START}, {LEFT_LINE_A_LINE_45_X_END, LEFT_LINE_A_LINE_45_Y_END}};
    				guider_ui.line45 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line45, line_points_L_45, 2);     /*Set the points*/
					static lv_style_t style_line_L_45;
					lv_style_init(&style_line_L_45);
					lv_style_set_line_width(&style_line_L_45, 16);
					lv_style_set_line_color(&style_line_L_45, last_line_color);
					lv_style_set_line_rounded(&style_line_L_45, true); // rectangle false
	    			lv_obj_add_style(guider_ui.line45, &style_line_L_45, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_46[] = { {LEFT_LINE_A_LINE_46_X_START, LEFT_LINE_A_LINE_46_Y_START}, {LEFT_LINE_A_LINE_46_X_END, LEFT_LINE_A_LINE_46_Y_END}};
    				guider_ui.line46 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line46, line_points_L_46, 2);     /*Set the points*/
					static lv_style_t style_line_L_46;
					lv_style_init(&style_line_L_46);
					lv_style_set_line_width(&style_line_L_46, 15);
					lv_style_set_line_color(&style_line_L_46, last_line_color);
					lv_style_set_line_rounded(&style_line_L_46, true); // rectangle false
	    			lv_obj_add_style(guider_ui.line46, &style_line_L_46, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 37:
					;
					static lv_point_t line_points_L_47[] = { {LEFT_LINE_A_LINE_47_X_START, LEFT_LINE_A_LINE_47_Y_START}, {LEFT_LINE_A_LINE_47_X_END, LEFT_LINE_A_LINE_47_Y_END}};
    				guider_ui.line47 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line47, line_points_L_47, 2);     /*Set the points*/
					static lv_style_t style_line_L_47;
					lv_style_init(&style_line_L_47);
					lv_style_set_line_width(&style_line_L_47, 15);
					lv_style_set_line_color(&style_line_L_47, last_line_color);
					lv_style_set_line_rounded(&style_line_L_47, true); // rectangle false
	    			lv_obj_add_style(guider_ui.line47, &style_line_L_47, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_48[] = { {LEFT_LINE_A_LINE_48_X_START, LEFT_LINE_A_LINE_48_Y_START}, {LEFT_LINE_A_LINE_48_X_END, LEFT_LINE_A_LINE_48_Y_END}};
    				guider_ui.line48 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line48, line_points_L_48, 2);     /*Set the points*/
					static lv_style_t style_line_L_48;
					lv_style_init(&style_line_L_48);
					lv_style_set_line_width(&style_line_L_48, 14);
					lv_style_set_line_color(&style_line_L_48, last_line_color);
					lv_style_set_line_rounded(&style_line_L_48, true); // rectangle false
	    			lv_obj_add_style(guider_ui.line48, &style_line_L_48, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 38 :
					;
					static lv_point_t line_points_L_49[] = { {LEFT_LINE_A_LINE_49_X_START, LEFT_LINE_A_LINE_49_Y_START}, {LEFT_LINE_A_LINE_49_X_END, LEFT_LINE_A_LINE_49_Y_END}};
    				guider_ui.line49 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line49, line_points_L_49, 2);     /*Set the points*/
					static lv_style_t style_line_L_49;
					lv_style_init(&style_line_L_49);
					lv_style_set_line_width(&style_line_L_49, 14);
					lv_style_set_line_color(&style_line_L_49, last_line_color);
					lv_style_set_line_rounded(&style_line_L_49, true); // rectangle false
	    			lv_obj_add_style(guider_ui.line49, &style_line_L_49, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_50[] = { {LEFT_LINE_A_LINE_50_X_START, LEFT_LINE_A_LINE_50_Y_START}, {LEFT_LINE_A_LINE_50_X_END, LEFT_LINE_A_LINE_50_Y_END}};
    				guider_ui.line50 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line50, line_points_L_50, 2);     /*Set the points*/
					static lv_style_t style_line_L_50;
					lv_style_init(&style_line_L_50);
					lv_style_set_line_width(&style_line_L_50, 14);
					lv_style_set_line_color(&style_line_L_50, last_line_color);
					lv_style_set_line_rounded(&style_line_L_50, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line50, &style_line_L_50, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 39 :
					;
					static lv_point_t line_points_L_51[] = { {LEFT_LINE_A_LINE_51_X_START, LEFT_LINE_A_LINE_51_Y_START}, {LEFT_LINE_A_LINE_51_X_END, LEFT_LINE_A_LINE_51_Y_END}};
    				guider_ui.line51 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line51, line_points_L_51, 2);     /*Set the points*/
					static lv_style_t style_line_L_51;
					lv_style_init(&style_line_L_51);
					lv_style_set_line_width(&style_line_L_51, 14);
					lv_style_set_line_color(&style_line_L_51, last_line_color);
					lv_style_set_line_rounded(&style_line_L_51, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line51, &style_line_L_51, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_52[] = { {LEFT_LINE_A_LINE_52_X_START, LEFT_LINE_A_LINE_52_Y_START}, {LEFT_LINE_A_LINE_52_X_END, LEFT_LINE_A_LINE_52_Y_END}};
    				guider_ui.line52 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line52, line_points_L_52, 2);     /*Set the points*/
					static lv_style_t style_line_L_52;
					lv_style_init(&style_line_L_52);
					lv_style_set_line_width(&style_line_L_52, 14);
					lv_style_set_line_color(&style_line_L_52, last_line_color);
					lv_style_set_line_rounded(&style_line_L_52, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line52, &style_line_L_52, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 40 :
					;
					static lv_point_t line_points_L_53[] = { {LEFT_LINE_A_LINE_53_X_START, LEFT_LINE_A_LINE_53_Y_START}, {LEFT_LINE_A_LINE_53_X_END, LEFT_LINE_A_LINE_53_Y_END}};
    				guider_ui.line53 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line53, line_points_L_53, 2);     /*Set the points*/
					static lv_style_t style_line_L_53;
					lv_style_init(&style_line_L_53);
					lv_style_set_line_width(&style_line_L_53, 14);
					lv_style_set_line_color(&style_line_L_53, last_line_color);
					lv_style_set_line_rounded(&style_line_L_53, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line53, &style_line_L_53, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_54[] = { {LEFT_LINE_A_LINE_54_X_START, LEFT_LINE_A_LINE_54_Y_START}, {LEFT_LINE_A_LINE_54_X_END, LEFT_LINE_A_LINE_54_Y_END}};
    				guider_ui.line54 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line54, line_points_L_54, 2);     /*Set the points*/
					static lv_style_t style_line_L_54;
					lv_style_init(&style_line_L_54);
					lv_style_set_line_width(&style_line_L_54, 14);
					lv_style_set_line_color(&style_line_L_54, last_line_color);
					lv_style_set_line_rounded(&style_line_L_54, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line54, &style_line_L_54, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 41 :
					;
					static lv_point_t line_points_L_55[] = { {LEFT_LINE_A_LINE_55_X_START, LEFT_LINE_A_LINE_55_Y_START}, {LEFT_LINE_A_LINE_55_X_END, LEFT_LINE_A_LINE_55_Y_END}};
    				guider_ui.line55 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line55, line_points_L_55, 2);     /*Set the points*/
					static lv_style_t style_line_L_55;
					lv_style_init(&style_line_L_55);
					lv_style_set_line_width(&style_line_L_55, 14);
					lv_style_set_line_color(&style_line_L_55, last_line_color);
					lv_style_set_line_rounded(&style_line_L_55, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line55, &style_line_L_55, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_56[] = { {LEFT_LINE_A_LINE_56_X_START, LEFT_LINE_A_LINE_56_Y_START}, {LEFT_LINE_A_LINE_56_X_END, LEFT_LINE_A_LINE_56_Y_END}};
    				guider_ui.line56 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line56, line_points_L_56, 2);     /*Set the points*/
					static lv_style_t style_line_L_56;
					lv_style_init(&style_line_L_56);
					lv_style_set_line_width(&style_line_L_56, 14);
					lv_style_set_line_color(&style_line_L_56, last_line_color);
					lv_style_set_line_rounded(&style_line_L_56, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line56, &style_line_L_56, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 42 :
					;
					static lv_point_t line_points_L_57[] = { {LEFT_LINE_A_LINE_57_X_START, LEFT_LINE_A_LINE_57_Y_START}, {LEFT_LINE_A_LINE_57_X_END, LEFT_LINE_A_LINE_57_Y_END}};
    				guider_ui.line57 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line57, line_points_L_57, 2);     /*Set the points*/
					static lv_style_t style_line_L_57;
					lv_style_init(&style_line_L_57);
					lv_style_set_line_width(&style_line_L_57, 14);
					lv_style_set_line_color(&style_line_L_57, last_line_color);
					lv_style_set_line_rounded(&style_line_L_57, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line57, &style_line_L_57, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t line_points_L_58[] = { {LEFT_LINE_A_LINE_58_X_START, LEFT_LINE_A_LINE_58_Y_START}, {LEFT_LINE_A_LINE_58_X_END, LEFT_LINE_A_LINE_58_Y_END}};
    				guider_ui.line58 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line58, line_points_L_58, 2);     /*Set the points*/
					static lv_style_t style_line_L_58;
					lv_style_init(&style_line_L_58);
					lv_style_set_line_width(&style_line_L_58, 14);
					lv_style_set_line_color(&style_line_L_58, last_line_color);
					lv_style_set_line_rounded(&style_line_L_58, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line58, &style_line_L_58, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 43 :
					;
					static lv_point_t line_points_L_59[] = { {LEFT_LINE_A_LINE_59_X_START, LEFT_LINE_A_LINE_59_Y_START}, {LEFT_LINE_A_LINE_59_X_END, LEFT_LINE_A_LINE_59_Y_END}};
    				guider_ui.line59 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line59, line_points_L_59, 2);     /*Set the points*/
					static lv_style_t style_line_L_59;
					lv_style_init(&style_line_L_59);
					lv_style_set_line_width(&style_line_L_59, 14);
					lv_style_set_line_color(&style_line_L_59, last_line_color);
					lv_style_set_line_rounded(&style_line_L_59, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line59, &style_line_L_59, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 44 :
					;
					static lv_point_t line_points_L_60[] = { {LEFT_LINE_A_LINE_60_X_START, LEFT_LINE_A_LINE_60_Y_START}, {LEFT_LINE_A_LINE_60_X_END, LEFT_LINE_A_LINE_60_Y_END}};
    				guider_ui.line60 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line60, line_points_L_60, 2);     /*Set the points*/
					static lv_style_t style_line_L_60;
					lv_style_init(&style_line_L_60);
					lv_style_set_line_width(&style_line_L_60, 14);
					lv_style_set_line_color(&style_line_L_60, last_line_color);
					lv_style_set_line_rounded(&style_line_L_60, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line60, &style_line_L_60, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 45 :
					;
					static lv_point_t line_points_L_61[] = { {LEFT_LINE_A_LINE_61_X_START, LEFT_LINE_A_LINE_61_Y_START}, {LEFT_LINE_A_LINE_61_X_END, LEFT_LINE_A_LINE_61_Y_END}};
    				guider_ui.line61 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line61, line_points_L_61, 2);     /*Set the points*/
					static lv_style_t style_line_L_61;
					lv_style_init(&style_line_L_61);
					lv_style_set_line_width(&style_line_L_61, 14);
					lv_style_set_line_color(&style_line_L_61, last_line_color);
					lv_style_set_line_rounded(&style_line_L_61, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line61, &style_line_L_61, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 46 :
					;
					static lv_point_t line_points_L_62[] = { {LEFT_LINE_A_LINE_62_X_START, LEFT_LINE_A_LINE_62_Y_START}, {LEFT_LINE_A_LINE_62_X_END, LEFT_LINE_A_LINE_62_Y_END}};
    				guider_ui.line62 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line62, line_points_L_62, 2);     /*Set the points*/
					static lv_style_t style_line_L_62;
					lv_style_init(&style_line_L_62);
					lv_style_set_line_width(&style_line_L_62, 14);
					lv_style_set_line_color(&style_line_L_62, last_line_color);
					lv_style_set_line_rounded(&style_line_L_62, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line62, &style_line_L_62, 0);

	    			//lv_task_handler();  // Update the display
	    			left_draw_line_1_first_draw_forward_switch++;
					break;

				case 47 :
					;
					static lv_point_t line_points_L_63[] = { {LEFT_LINE_A_LINE_63_X_START, LEFT_LINE_A_LINE_63_Y_START}, {LEFT_LINE_A_LINE_63_X_END, LEFT_LINE_A_LINE_63_Y_END}};
    				guider_ui.line63 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.line63, line_points_L_63, 2);     /*Set the points*/
					static lv_style_t style_line_L_63;
					lv_style_init(&style_line_L_63);
					lv_style_set_line_width(&style_line_L_63, 14);
					lv_style_set_line_color(&style_line_L_63, last_line_color);
					lv_style_set_line_rounded(&style_line_L_63, false); // rectangle false
	    			lv_obj_add_style(guider_ui.line63, &style_line_L_63, 0);

	    			//lv_task_handler();  // Update the display

	    			//final
	    			// first time draw completed
	    			left_draw_line_1_first_draw_forward_switch=0;
	    			left_draw_line_1_first_draw_forward = 0;
	    			left_draw_line_1_draw_backward_switch = 1;
					break;

				default :
					break;
				}

				//lv_task_handler();  // Update the display
			}
			else
			{
				if(left_draw_line_1_draw_backward_switch)
				{
					switch (left_draw_line_1_draw_backward_switch_case)
					{
					case 0 :
						lv_obj_add_flag(guider_ui.line63, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 1 :
						lv_obj_add_flag(guider_ui.line62, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 2 :
						lv_obj_add_flag(guider_ui.line61, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 3 :
						lv_obj_add_flag(guider_ui.line60, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 4 :
						lv_obj_add_flag(guider_ui.line59, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 5 :
						lv_obj_add_flag(guider_ui.line58, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line57, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 6 :
						lv_obj_add_flag(guider_ui.line56, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line55, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 7 :
						lv_obj_add_flag(guider_ui.line54, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line53, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 8 :
						lv_obj_add_flag(guider_ui.line52, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line51, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 9 :
						lv_obj_add_flag(guider_ui.line50, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line49, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 10 :
						lv_obj_add_flag(guider_ui.line48, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line47, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 11 :
						lv_obj_add_flag(guider_ui.line46, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line45, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 12 :
						lv_obj_add_flag(guider_ui.line44, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line43, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 13 :
						lv_obj_add_flag(guider_ui.line42, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line41, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 14 :
						lv_obj_add_flag(guider_ui.line40, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line39, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 15 :
						lv_obj_add_flag(guider_ui.line38, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line37, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 16 :
						lv_obj_add_flag(guider_ui.line36, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line35, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 17 :
						lv_obj_add_flag(guider_ui.line34, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line33, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 18 :
						lv_obj_add_flag(guider_ui.line32, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line31, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 19 :
						lv_obj_add_flag(guider_ui.line30, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line29, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 20 :
						lv_obj_add_flag(guider_ui.line28, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.line27, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 21 :
						lv_obj_add_flag(guider_ui.line26, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 22 :
						lv_obj_add_flag(guider_ui.line25, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 23 :
						lv_obj_add_flag(guider_ui.line24, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 24 :
						lv_obj_add_flag(guider_ui.line23, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 25 :
						lv_obj_add_flag(guider_ui.line22, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 26 :
						lv_obj_add_flag(guider_ui.line21, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 27 :
						lv_obj_add_flag(guider_ui.line20, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 28 :
						lv_obj_add_flag(guider_ui.line19, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 29 :
						lv_obj_add_flag(guider_ui.line18, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 30 :
						lv_obj_add_flag(guider_ui.line17, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 31 :
						lv_obj_add_flag(guider_ui.line16, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 32 :
						lv_obj_add_flag(guider_ui.line15, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 33 :
						lv_obj_add_flag(guider_ui.line14, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 34 :
						lv_obj_add_flag(guider_ui.line13, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 35 :
						lv_obj_add_flag(guider_ui.line12, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 36 :
						lv_obj_add_flag(guider_ui.line11, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 37 :
						lv_obj_add_flag(guider_ui.line10, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 38 :
						lv_obj_add_flag(guider_ui.line9, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 39 :
						lv_obj_add_flag(guider_ui.line8, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 40 :
						lv_obj_add_flag(guider_ui.line7, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 41 :
						lv_obj_add_flag(guider_ui.line6, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 42 :
						lv_obj_add_flag(guider_ui.line5, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 43 :
						lv_obj_add_flag(guider_ui.line4, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 44 :
						lv_obj_add_flag(guider_ui.line3, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 45 :
						lv_obj_add_flag(guider_ui.line2, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;
						break;
					case 46 :
						lv_obj_add_flag(guider_ui.line1, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_backward_switch_case++;

						left_draw_line_1_draw_backward_switch_case=0;
						left_draw_line_1_draw_backward_switch = 0;
						left_draw_line_1_draw_forward_switch = 1;
						left_draw_line_1_draw_forward_switch_case = 0;
						break;
					default:
						break;
					}

				}
				else if (left_draw_line_1_draw_forward_switch)
				{
					switch (left_draw_line_1_draw_forward_switch_case)
					{
					case 0 :
						lv_obj_clear_flag(guider_ui.line1, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 1 :
						lv_obj_clear_flag(guider_ui.line2, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 2 :
						lv_obj_clear_flag(guider_ui.line3, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 3 :
						lv_obj_clear_flag(guider_ui.line4, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 4 :
						lv_obj_clear_flag(guider_ui.line5, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 5 :
						lv_obj_clear_flag(guider_ui.line6, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 6 :
						lv_obj_clear_flag(guider_ui.line7, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 7 :
						lv_obj_clear_flag(guider_ui.line8, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 8 :
						lv_obj_clear_flag(guider_ui.line9, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 9 :
						lv_obj_clear_flag(guider_ui.line10, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 10 :
						lv_obj_clear_flag(guider_ui.line11, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 11 :
						lv_obj_clear_flag(guider_ui.line12, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 12 :
						lv_obj_clear_flag(guider_ui.line13, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 13 :
						lv_obj_clear_flag(guider_ui.line14, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 14 :
						lv_obj_clear_flag(guider_ui.line15, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 15 :
						lv_obj_clear_flag(guider_ui.line16, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 16 :
						lv_obj_clear_flag(guider_ui.line17, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 17 :
						lv_obj_clear_flag(guider_ui.line18, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 18 :
						lv_obj_clear_flag(guider_ui.line19, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 19 :
						lv_obj_clear_flag(guider_ui.line20, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 20 :
						lv_obj_clear_flag(guider_ui.line21, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 21 :
						lv_obj_clear_flag(guider_ui.line22, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 22 :
						lv_obj_clear_flag(guider_ui.line23, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 23 :
						lv_obj_clear_flag(guider_ui.line24, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 24 :
						lv_obj_clear_flag(guider_ui.line25, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 25 :
						lv_obj_clear_flag(guider_ui.line26, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 26 :
						lv_obj_clear_flag(guider_ui.line27, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line28, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 27 :
						lv_obj_clear_flag(guider_ui.line29, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line30, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 28 :
						lv_obj_clear_flag(guider_ui.line31, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line32, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 29 :
						lv_obj_clear_flag(guider_ui.line33, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line34, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 30 :
						lv_obj_clear_flag(guider_ui.line35, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line36, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 31 :
						lv_obj_clear_flag(guider_ui.line37, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line38, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 32 :
						lv_obj_clear_flag(guider_ui.line39, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line40, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 33 :
						lv_obj_clear_flag(guider_ui.line41, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line42, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 34 :
						lv_obj_clear_flag(guider_ui.line43, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line44, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 35 :
						lv_obj_clear_flag(guider_ui.line45, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line46, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 36 :
						lv_obj_clear_flag(guider_ui.line47, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line48, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 37 :
						lv_obj_clear_flag(guider_ui.line49, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line50, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 38 :
						lv_obj_clear_flag(guider_ui.line51, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line52, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 39 :
						lv_obj_clear_flag(guider_ui.line53, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line54, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 40 :
						lv_obj_clear_flag(guider_ui.line55, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line56, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 41 :
						lv_obj_clear_flag(guider_ui.line57, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.line58, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 42 :
						lv_obj_clear_flag(guider_ui.line59, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 43 :
						lv_obj_clear_flag(guider_ui.line60, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 44 :
						lv_obj_clear_flag(guider_ui.line61, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 45 :
						lv_obj_clear_flag(guider_ui.line62, LV_OBJ_FLAG_HIDDEN);
						left_draw_line_1_draw_forward_switch_case++;
						break;
					case 46 :
						lv_obj_clear_flag(guider_ui.line63, LV_OBJ_FLAG_HIDDEN);

						left_draw_line_1_draw_forward_switch_case = 0;
						left_draw_line_1_draw_forward_switch = 0;
						left_draw_line_1_draw_backward_switch = 1;
						left_draw_line_1_draw_backward_switch_case = 0;
						break;
					default:
						break;
					}

				}
				else
				{
					// do nothing
				}

			}

		}

		if(line_1_start_timer)
		{
			drawing_screen = 0;
			drawing_screen_inc_enable = 1;

			line_1_start_timer_exp = 0;
			line_1_start_timer = 0;
		}
		// 35 msec : keep calling : lv_task_handler()
		if (drawing_screen >= 5)  // Minimum : delay for 10 msec --> i.e animation time --> till that time call --> lv_task_handler()
		{
			line_1_start_timer_exp = 1;
			drawing_screen_inc_enable = 0;
			line_1_start_timer = 1;

		}


		//lv_task_handler();  // Update the display

	}

}
