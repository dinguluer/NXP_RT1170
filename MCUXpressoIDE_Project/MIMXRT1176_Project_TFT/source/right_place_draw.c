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

#define RIGHT_PLANE_OFFSET 384
#define RIGHT_LINE_A_LINE_1_X_START (214 + RIGHT_PLANE_OFFSET)  // 598
#define RIGHT_LINE_A_LINE_1_X_END   (RIGHT_LINE_A_LINE_1_X_START+11)
#define RIGHT_LINE_A_LINE_1_Y_START 368 - 1 //369
#define RIGHT_LINE_A_LINE_1_Y_END   (RIGHT_LINE_A_LINE_1_Y_START-1)

#define RIGHT_LINE_A_LINE_2_X_START (RIGHT_LINE_A_LINE_1_X_END -1)
#define RIGHT_LINE_A_LINE_2_X_END   (RIGHT_LINE_A_LINE_2_X_START+11)
#define RIGHT_LINE_A_LINE_2_Y_START RIGHT_LINE_A_LINE_1_Y_END
#define RIGHT_LINE_A_LINE_2_Y_END   (RIGHT_LINE_A_LINE_2_Y_START-1)

#define RIGHT_LINE_A_LINE_3_X_START (RIGHT_LINE_A_LINE_2_X_END -1)
#define RIGHT_LINE_A_LINE_3_X_END   (RIGHT_LINE_A_LINE_3_X_START+11)
#define RIGHT_LINE_A_LINE_3_Y_START RIGHT_LINE_A_LINE_2_Y_END
#define RIGHT_LINE_A_LINE_3_Y_END   (RIGHT_LINE_A_LINE_3_Y_START-1)

#define RIGHT_LINE_A_LINE_4_X_START (RIGHT_LINE_A_LINE_3_X_END -1)
#define RIGHT_LINE_A_LINE_4_X_END   (RIGHT_LINE_A_LINE_4_X_START+11)
#define RIGHT_LINE_A_LINE_4_Y_START RIGHT_LINE_A_LINE_3_Y_END
#define RIGHT_LINE_A_LINE_4_Y_END   (RIGHT_LINE_A_LINE_4_Y_START-1)

#define RIGHT_LINE_A_LINE_5_X_START (RIGHT_LINE_A_LINE_4_X_END -1)
#define RIGHT_LINE_A_LINE_5_X_END   (RIGHT_LINE_A_LINE_5_X_START+11)
#define RIGHT_LINE_A_LINE_5_Y_START RIGHT_LINE_A_LINE_4_Y_END
#define RIGHT_LINE_A_LINE_5_Y_END   (RIGHT_LINE_A_LINE_5_Y_START-1)

#define RIGHT_LINE_A_LINE_6_X_START (RIGHT_LINE_A_LINE_5_X_END -1)
#define RIGHT_LINE_A_LINE_6_X_END   (RIGHT_LINE_A_LINE_6_X_START+11)
#define RIGHT_LINE_A_LINE_6_Y_START RIGHT_LINE_A_LINE_5_Y_END
#define RIGHT_LINE_A_LINE_6_Y_END   (RIGHT_LINE_A_LINE_6_Y_START-1)

#define RIGHT_LINE_A_LINE_7_X_START (RIGHT_LINE_A_LINE_6_X_END -1)
#define RIGHT_LINE_A_LINE_7_X_END   (RIGHT_LINE_A_LINE_7_X_START+11)
#define RIGHT_LINE_A_LINE_7_Y_START RIGHT_LINE_A_LINE_6_Y_END
#define RIGHT_LINE_A_LINE_7_Y_END   (RIGHT_LINE_A_LINE_7_Y_START-1)

#define RIGHT_LINE_A_LINE_8_X_START (RIGHT_LINE_A_LINE_7_X_END -1)
#define RIGHT_LINE_A_LINE_8_X_END   (RIGHT_LINE_A_LINE_8_X_START+11)
#define RIGHT_LINE_A_LINE_8_Y_START RIGHT_LINE_A_LINE_7_Y_END
#define RIGHT_LINE_A_LINE_8_Y_END   (RIGHT_LINE_A_LINE_8_Y_START-1)

#define RIGHT_LINE_A_LINE_9_X_START (RIGHT_LINE_A_LINE_8_X_END -1)
#define RIGHT_LINE_A_LINE_9_X_END   (RIGHT_LINE_A_LINE_9_X_START+11)
#define RIGHT_LINE_A_LINE_9_Y_START RIGHT_LINE_A_LINE_8_Y_END
#define RIGHT_LINE_A_LINE_9_Y_END   (RIGHT_LINE_A_LINE_9_Y_START-1)

#define RIGHT_LINE_A_LINE_10_X_START (RIGHT_LINE_A_LINE_9_X_END -1)   //124
#define RIGHT_LINE_A_LINE_10_X_END   (RIGHT_LINE_A_LINE_10_X_START+11) //360
#define RIGHT_LINE_A_LINE_10_Y_START RIGHT_LINE_A_LINE_9_Y_END         // 113
#define RIGHT_LINE_A_LINE_10_Y_END   (RIGHT_LINE_A_LINE_10_Y_START-1)  // 359


#define RIGHT_LINE_A_LINE_11_X_START (RIGHT_LINE_A_LINE_10_X_END -1)
#define RIGHT_LINE_A_LINE_11_X_END   (RIGHT_LINE_A_LINE_11_X_START+16)
#define RIGHT_LINE_A_LINE_11_Y_START RIGHT_LINE_A_LINE_10_Y_END
#define RIGHT_LINE_A_LINE_11_Y_END   (RIGHT_LINE_A_LINE_11_Y_START-1)

#define RIGHT_LINE_A_LINE_12_X_START (RIGHT_LINE_A_LINE_11_X_END -1)
#define RIGHT_LINE_A_LINE_12_X_END   (RIGHT_LINE_A_LINE_12_X_START+10)
#define RIGHT_LINE_A_LINE_12_Y_START RIGHT_LINE_A_LINE_11_Y_END
#define RIGHT_LINE_A_LINE_12_Y_END   (RIGHT_LINE_A_LINE_12_Y_START-1)

#define RIGHT_LINE_A_LINE_13_X_START (RIGHT_LINE_A_LINE_12_X_END -4)// modified
#define RIGHT_LINE_A_LINE_13_X_END   (RIGHT_LINE_A_LINE_13_X_START+6)
#define RIGHT_LINE_A_LINE_13_Y_START RIGHT_LINE_A_LINE_12_Y_END  //-->
#define RIGHT_LINE_A_LINE_13_Y_END   (RIGHT_LINE_A_LINE_13_Y_START-1)

#define RIGHT_LINE_A_LINE_14_X_START (RIGHT_LINE_A_LINE_13_X_END -2)// modified
#define RIGHT_LINE_A_LINE_14_X_END   (RIGHT_LINE_A_LINE_14_X_START+6)
#define RIGHT_LINE_A_LINE_14_Y_START RIGHT_LINE_A_LINE_13_Y_END      // modified
#define RIGHT_LINE_A_LINE_14_Y_END   (RIGHT_LINE_A_LINE_14_Y_START-1)

#define RIGHT_LINE_A_LINE_15_X_START (RIGHT_LINE_A_LINE_14_X_END -2)// modified
#define RIGHT_LINE_A_LINE_15_X_END   (RIGHT_LINE_A_LINE_15_X_START+6)
#define RIGHT_LINE_A_LINE_15_Y_START RIGHT_LINE_A_LINE_14_Y_END      // modified
#define RIGHT_LINE_A_LINE_15_Y_END   (RIGHT_LINE_A_LINE_15_Y_START-1)

#define RIGHT_LINE_A_LINE_16_X_START (RIGHT_LINE_A_LINE_15_X_END -2)
#define RIGHT_LINE_A_LINE_16_X_END   (RIGHT_LINE_A_LINE_16_X_START+6)
#define RIGHT_LINE_A_LINE_16_Y_START RIGHT_LINE_A_LINE_15_Y_END      // modified
#define RIGHT_LINE_A_LINE_16_Y_END   (RIGHT_LINE_A_LINE_16_Y_START-1)

#define RIGHT_LINE_A_LINE_17_X_START (RIGHT_LINE_A_LINE_16_X_END -2)
#define RIGHT_LINE_A_LINE_17_X_END   (RIGHT_LINE_A_LINE_17_X_START+6)
#define RIGHT_LINE_A_LINE_17_Y_START RIGHT_LINE_A_LINE_16_Y_END      // modified
#define RIGHT_LINE_A_LINE_17_Y_END   (RIGHT_LINE_A_LINE_17_Y_START-1 -1 -1)

#define RIGHT_LINE_A_LINE_18_X_START (RIGHT_LINE_A_LINE_17_X_END -2)
#define RIGHT_LINE_A_LINE_18_X_END   (RIGHT_LINE_A_LINE_18_X_START+6)
#define RIGHT_LINE_A_LINE_18_Y_START RIGHT_LINE_A_LINE_17_Y_END      // modified
#define RIGHT_LINE_A_LINE_18_Y_END   (RIGHT_LINE_A_LINE_18_Y_START-2 -1)

//#define RIGHT_LINE_A_LINE_18_X_START (RIGHT_LINE_A_LINE_17_X_END +2)  // modified
//#define RIGHT_LINE_A_LINE_18_X_END   (RIGHT_LINE_A_LINE_18_X_START-6)
//#define RIGHT_LINE_A_LINE_18_Y_START RIGHT_LINE_A_LINE_17_Y_END      // modified
//#define RIGHT_LINE_A_LINE_18_Y_END   (RIGHT_LINE_A_LINE_18_Y_START-2)

#define RIGHT_LINE_A_LINE_19_X_START (RIGHT_LINE_A_LINE_18_X_END -2)  // modified
#define RIGHT_LINE_A_LINE_19_X_END   (RIGHT_LINE_A_LINE_19_X_START+6)
#define RIGHT_LINE_A_LINE_19_Y_START RIGHT_LINE_A_LINE_18_Y_END      // modified
#define RIGHT_LINE_A_LINE_19_Y_END   (RIGHT_LINE_A_LINE_19_Y_START-2 -1)

#define RIGHT_LINE_A_LINE_20_X_START (RIGHT_LINE_A_LINE_19_X_END -2)  // modified
#define RIGHT_LINE_A_LINE_20_X_END   (RIGHT_LINE_A_LINE_20_X_START+6 -1)
#define RIGHT_LINE_A_LINE_20_Y_START RIGHT_LINE_A_LINE_19_Y_END      // modified
#define RIGHT_LINE_A_LINE_20_Y_END   (RIGHT_LINE_A_LINE_20_Y_START-3 -1)

#define RIGHT_LINE_A_LINE_21_X_START (RIGHT_LINE_A_LINE_20_X_END -2)  // modified
#define RIGHT_LINE_A_LINE_21_X_END   (RIGHT_LINE_A_LINE_21_X_START+2)
#define RIGHT_LINE_A_LINE_21_Y_START RIGHT_LINE_A_LINE_20_Y_END + 1     // modified
#define RIGHT_LINE_A_LINE_21_Y_END   (RIGHT_LINE_A_LINE_21_Y_START-2)

#define RIGHT_LINE_A_LINE_22_X_START (RIGHT_LINE_A_LINE_21_X_END -2)  // modified
#define RIGHT_LINE_A_LINE_22_X_END   (RIGHT_LINE_A_LINE_22_X_START+4 -1)
#define RIGHT_LINE_A_LINE_22_Y_START RIGHT_LINE_A_LINE_21_Y_END + 1     // modified
#define RIGHT_LINE_A_LINE_22_Y_END   (RIGHT_LINE_A_LINE_22_Y_START-2)

#define RIGHT_LINE_A_LINE_23_X_START (RIGHT_LINE_A_LINE_22_X_END -2)  // modified
#define RIGHT_LINE_A_LINE_23_X_END   (RIGHT_LINE_A_LINE_23_X_START+4 -1)
#define RIGHT_LINE_A_LINE_23_Y_START RIGHT_LINE_A_LINE_22_Y_END + 5     // modified
#define RIGHT_LINE_A_LINE_23_Y_END   (RIGHT_LINE_A_LINE_23_Y_START-4 - 2)

#define RIGHT_LINE_A_LINE_24_X_START (RIGHT_LINE_A_LINE_23_X_END -2)  // modified
#define RIGHT_LINE_A_LINE_24_X_END   (RIGHT_LINE_A_LINE_24_X_START+1)
#define RIGHT_LINE_A_LINE_24_Y_START RIGHT_LINE_A_LINE_23_Y_END + 1 + 1 + 3   // modified
#define RIGHT_LINE_A_LINE_24_Y_END   (RIGHT_LINE_A_LINE_24_Y_START-6)

#define RIGHT_LINE_A_LINE_25_X_START (RIGHT_LINE_A_LINE_24_X_END -2)  // modified
#define RIGHT_LINE_A_LINE_25_X_END   (RIGHT_LINE_A_LINE_25_X_START+4 + 3 -1 -1 -1)
#define RIGHT_LINE_A_LINE_25_Y_START RIGHT_LINE_A_LINE_24_Y_END + 1  + 2     // modified
#define RIGHT_LINE_A_LINE_25_Y_END   (RIGHT_LINE_A_LINE_25_Y_START-7)

#define RIGHT_LINE_A_LINE_26_X_START (RIGHT_LINE_A_LINE_25_X_END -2)  // modified
#define RIGHT_LINE_A_LINE_26_X_END   (RIGHT_LINE_A_LINE_26_X_START+4)
#define RIGHT_LINE_A_LINE_26_Y_START RIGHT_LINE_A_LINE_25_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_26_Y_END   (RIGHT_LINE_A_LINE_26_Y_START-7)

#define RIGHT_LINE_A_LINE_27_X_START (RIGHT_LINE_A_LINE_26_X_END +1 -1)  // modified
#define RIGHT_LINE_A_LINE_27_X_END   (RIGHT_LINE_A_LINE_27_X_START+4 - 2)
#define RIGHT_LINE_A_LINE_27_Y_START RIGHT_LINE_A_LINE_26_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_27_Y_END   (RIGHT_LINE_A_LINE_27_Y_START-7)

#define RIGHT_LINE_A_LINE_28_X_START (RIGHT_LINE_A_LINE_27_X_END -3 +1)  // modified
#define RIGHT_LINE_A_LINE_28_X_END   (RIGHT_LINE_A_LINE_28_X_START+4 +1)
#define RIGHT_LINE_A_LINE_28_Y_START RIGHT_LINE_A_LINE_27_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_28_Y_END   (RIGHT_LINE_A_LINE_28_Y_START-11)

#define RIGHT_LINE_A_LINE_29_X_START (RIGHT_LINE_A_LINE_28_X_END )  // modified
#define RIGHT_LINE_A_LINE_29_X_END   (RIGHT_LINE_A_LINE_29_X_START+2 -1)
#define RIGHT_LINE_A_LINE_29_Y_START RIGHT_LINE_A_LINE_28_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_29_Y_END   (RIGHT_LINE_A_LINE_29_Y_START-11)

#define RIGHT_LINE_A_LINE_30_X_START (RIGHT_LINE_A_LINE_29_X_END )  // modified
#define RIGHT_LINE_A_LINE_30_X_END   (RIGHT_LINE_A_LINE_30_X_START+2 -1)
#define RIGHT_LINE_A_LINE_30_Y_START RIGHT_LINE_A_LINE_29_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_30_Y_END   (RIGHT_LINE_A_LINE_30_Y_START-11)

#define RIGHT_LINE_A_LINE_31_X_START (RIGHT_LINE_A_LINE_30_X_END )  // modified
#define RIGHT_LINE_A_LINE_31_X_END   (RIGHT_LINE_A_LINE_31_X_START+1)
#define RIGHT_LINE_A_LINE_31_Y_START RIGHT_LINE_A_LINE_30_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_31_Y_END   (RIGHT_LINE_A_LINE_31_Y_START-11)

#define RIGHT_LINE_A_LINE_32_X_START (RIGHT_LINE_A_LINE_31_X_END )  // modified
#define RIGHT_LINE_A_LINE_32_X_END   (RIGHT_LINE_A_LINE_32_X_START+2)
#define RIGHT_LINE_A_LINE_32_Y_START RIGHT_LINE_A_LINE_31_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_32_Y_END   (RIGHT_LINE_A_LINE_32_Y_START-11)

#define RIGHT_LINE_A_LINE_33_X_START (RIGHT_LINE_A_LINE_32_X_END )  // modified
#define RIGHT_LINE_A_LINE_33_X_END   (RIGHT_LINE_A_LINE_33_X_START+1)
#define RIGHT_LINE_A_LINE_33_Y_START RIGHT_LINE_A_LINE_32_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_33_Y_END   (RIGHT_LINE_A_LINE_33_Y_START-11)

#define RIGHT_LINE_A_LINE_34_X_START (RIGHT_LINE_A_LINE_33_X_END )  // modified
#define RIGHT_LINE_A_LINE_34_X_END   (RIGHT_LINE_A_LINE_34_X_START+2)
#define RIGHT_LINE_A_LINE_34_Y_START RIGHT_LINE_A_LINE_33_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_34_Y_END   (RIGHT_LINE_A_LINE_34_Y_START-11)

#define RIGHT_LINE_A_LINE_35_X_START (RIGHT_LINE_A_LINE_34_X_END )  // modified
#define RIGHT_LINE_A_LINE_35_X_END   (RIGHT_LINE_A_LINE_35_X_START+1)
#define RIGHT_LINE_A_LINE_35_Y_START RIGHT_LINE_A_LINE_34_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_35_Y_END   (RIGHT_LINE_A_LINE_35_Y_START-11)

#define RIGHT_LINE_A_LINE_36_X_START (RIGHT_LINE_A_LINE_35_X_END )  // modified
#define RIGHT_LINE_A_LINE_36_X_END   (RIGHT_LINE_A_LINE_36_X_START+2)
#define RIGHT_LINE_A_LINE_36_Y_START RIGHT_LINE_A_LINE_35_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_36_Y_END   (RIGHT_LINE_A_LINE_36_Y_START-11)

#define RIGHT_LINE_A_LINE_37_X_START (RIGHT_LINE_A_LINE_36_X_END )  // modified
#define RIGHT_LINE_A_LINE_37_X_END   (RIGHT_LINE_A_LINE_37_X_START+1)
#define RIGHT_LINE_A_LINE_37_Y_START RIGHT_LINE_A_LINE_36_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_37_Y_END   (RIGHT_LINE_A_LINE_37_Y_START-11)

#define RIGHT_LINE_A_LINE_38_X_START (RIGHT_LINE_A_LINE_37_X_END )  // modified
#define RIGHT_LINE_A_LINE_38_X_END   (RIGHT_LINE_A_LINE_38_X_START+1)
#define RIGHT_LINE_A_LINE_38_Y_START RIGHT_LINE_A_LINE_37_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_38_Y_END   (RIGHT_LINE_A_LINE_38_Y_START-11)

#define RIGHT_LINE_A_LINE_39_X_START (RIGHT_LINE_A_LINE_38_X_END )  // modified
#define RIGHT_LINE_A_LINE_39_X_END   (RIGHT_LINE_A_LINE_39_X_START+1)
#define RIGHT_LINE_A_LINE_39_Y_START RIGHT_LINE_A_LINE_38_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_39_Y_END   (RIGHT_LINE_A_LINE_39_Y_START-11)

#define RIGHT_LINE_A_LINE_40_X_START (RIGHT_LINE_A_LINE_39_X_END )  // modified
#define RIGHT_LINE_A_LINE_40_X_END   (RIGHT_LINE_A_LINE_40_X_START+2 )
#define RIGHT_LINE_A_LINE_40_Y_START RIGHT_LINE_A_LINE_39_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_40_Y_END   (RIGHT_LINE_A_LINE_40_Y_START-11)

#define RIGHT_LINE_A_LINE_41_X_START (RIGHT_LINE_A_LINE_40_X_END )  // modified
#define RIGHT_LINE_A_LINE_41_X_END   (RIGHT_LINE_A_LINE_41_X_START -1  -1 )
#define RIGHT_LINE_A_LINE_41_Y_START RIGHT_LINE_A_LINE_40_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_41_Y_END   (RIGHT_LINE_A_LINE_41_Y_START-11)

#define RIGHT_LINE_A_LINE_42_X_START (RIGHT_LINE_A_LINE_41_X_END +1 )  // modified
#define RIGHT_LINE_A_LINE_42_X_END   (RIGHT_LINE_A_LINE_42_X_START-1 -1 -1)
#define RIGHT_LINE_A_LINE_42_Y_START RIGHT_LINE_A_LINE_41_Y_END //+ 1  + 1     // modified
#define RIGHT_LINE_A_LINE_42_Y_END   (RIGHT_LINE_A_LINE_42_Y_START-11)

#define RIGHT_LINE_A_LINE_43_X_START (RIGHT_LINE_A_LINE_42_X_END )  // modified
#define RIGHT_LINE_A_LINE_43_X_END   (RIGHT_LINE_A_LINE_43_X_START-3 - 1 -1 -1 )
#define RIGHT_LINE_A_LINE_43_Y_START RIGHT_LINE_A_LINE_42_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_43_Y_END   (RIGHT_LINE_A_LINE_43_Y_START-11)

#define RIGHT_LINE_A_LINE_44_X_START (RIGHT_LINE_A_LINE_43_X_END )  // modified
#define RIGHT_LINE_A_LINE_44_X_END   (RIGHT_LINE_A_LINE_44_X_START-3 -1 -1 )
#define RIGHT_LINE_A_LINE_44_Y_START RIGHT_LINE_A_LINE_43_Y_END + 1  + 1     // modified
#define RIGHT_LINE_A_LINE_44_Y_END   (RIGHT_LINE_A_LINE_44_Y_START-6)

#define RIGHT_LINE_A_LINE_45_X_START (RIGHT_LINE_A_LINE_44_X_END +1 )  // modified
#define RIGHT_LINE_A_LINE_45_X_END   (RIGHT_LINE_A_LINE_45_X_START-4 -3 )
#define RIGHT_LINE_A_LINE_45_Y_START RIGHT_LINE_A_LINE_44_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_45_Y_END   (RIGHT_LINE_A_LINE_45_Y_START-6)

#define RIGHT_LINE_A_LINE_46_X_START (RIGHT_LINE_A_LINE_45_X_END +1 )  // modified
#define RIGHT_LINE_A_LINE_46_X_END   (RIGHT_LINE_A_LINE_46_X_START-4 -1)
#define RIGHT_LINE_A_LINE_46_Y_START RIGHT_LINE_A_LINE_45_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_46_Y_END   (RIGHT_LINE_A_LINE_46_Y_START-3)

#define RIGHT_LINE_A_LINE_47_X_START (RIGHT_LINE_A_LINE_46_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_47_X_END   (RIGHT_LINE_A_LINE_47_X_START-4 -2 -1)
#define RIGHT_LINE_A_LINE_47_Y_START RIGHT_LINE_A_LINE_46_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_47_Y_END   (RIGHT_LINE_A_LINE_47_Y_START-4)

#define RIGHT_LINE_A_LINE_48_X_START (RIGHT_LINE_A_LINE_47_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_48_X_END   (RIGHT_LINE_A_LINE_48_X_START-7 -1 )
#define RIGHT_LINE_A_LINE_48_Y_START RIGHT_LINE_A_LINE_47_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_48_Y_END   (RIGHT_LINE_A_LINE_48_Y_START-4)

#define RIGHT_LINE_A_LINE_49_X_START (RIGHT_LINE_A_LINE_48_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_49_X_END   (RIGHT_LINE_A_LINE_49_X_START-11 -3 -1 )
#define RIGHT_LINE_A_LINE_49_Y_START RIGHT_LINE_A_LINE_48_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_49_Y_END   (RIGHT_LINE_A_LINE_49_Y_START-7)

#define RIGHT_LINE_A_LINE_50_X_START (RIGHT_LINE_A_LINE_49_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_50_X_END   (RIGHT_LINE_A_LINE_50_X_START-11 )
#define RIGHT_LINE_A_LINE_50_Y_START RIGHT_LINE_A_LINE_49_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_50_Y_END   (RIGHT_LINE_A_LINE_50_Y_START-5)

#define RIGHT_LINE_A_LINE_51_X_START (RIGHT_LINE_A_LINE_50_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_51_X_END   (RIGHT_LINE_A_LINE_51_X_START-11-2 )
#define RIGHT_LINE_A_LINE_51_Y_START RIGHT_LINE_A_LINE_50_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_51_Y_END   (RIGHT_LINE_A_LINE_51_Y_START-5)

#define RIGHT_LINE_A_LINE_52_X_START (RIGHT_LINE_A_LINE_51_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_52_X_END   (RIGHT_LINE_A_LINE_52_X_START-11 -2)
#define RIGHT_LINE_A_LINE_52_Y_START RIGHT_LINE_A_LINE_51_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_52_Y_END   (RIGHT_LINE_A_LINE_52_Y_START-5)

#define RIGHT_LINE_A_LINE_53_X_START (RIGHT_LINE_A_LINE_52_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_53_X_END   (RIGHT_LINE_A_LINE_53_X_START-11 )
#define RIGHT_LINE_A_LINE_53_Y_START RIGHT_LINE_A_LINE_52_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_53_Y_END   (RIGHT_LINE_A_LINE_53_Y_START-3)

#define RIGHT_LINE_A_LINE_54_X_START (RIGHT_LINE_A_LINE_53_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_54_X_END   (RIGHT_LINE_A_LINE_54_X_START-11 )
#define RIGHT_LINE_A_LINE_54_Y_START RIGHT_LINE_A_LINE_53_Y_END       // modified
#define RIGHT_LINE_A_LINE_54_Y_END   (RIGHT_LINE_A_LINE_54_Y_START-4)

#define RIGHT_LINE_A_LINE_55_X_START (RIGHT_LINE_A_LINE_54_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_55_X_END   (RIGHT_LINE_A_LINE_55_X_START-11 )
#define RIGHT_LINE_A_LINE_55_Y_START RIGHT_LINE_A_LINE_54_Y_END + 1      // modified
#define RIGHT_LINE_A_LINE_55_Y_END   (RIGHT_LINE_A_LINE_55_Y_START-3)

#define RIGHT_LINE_A_LINE_56_X_START (RIGHT_LINE_A_LINE_55_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_56_X_END   (RIGHT_LINE_A_LINE_56_X_START-11 )
#define RIGHT_LINE_A_LINE_56_Y_START RIGHT_LINE_A_LINE_55_Y_END       // modified
#define RIGHT_LINE_A_LINE_56_Y_END   (RIGHT_LINE_A_LINE_56_Y_START-3)

#define RIGHT_LINE_A_LINE_57_X_START (RIGHT_LINE_A_LINE_56_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_57_X_END   (RIGHT_LINE_A_LINE_57_X_START-11 )
#define RIGHT_LINE_A_LINE_57_Y_START RIGHT_LINE_A_LINE_56_Y_END       // modified
#define RIGHT_LINE_A_LINE_57_Y_END   (RIGHT_LINE_A_LINE_57_Y_START-4)

#define RIGHT_LINE_A_LINE_58_X_START (RIGHT_LINE_A_LINE_57_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_58_X_END   (RIGHT_LINE_A_LINE_58_X_START-11 )
#define RIGHT_LINE_A_LINE_58_Y_START RIGHT_LINE_A_LINE_57_Y_END  +1     // modified
#define RIGHT_LINE_A_LINE_58_Y_END   (RIGHT_LINE_A_LINE_58_Y_START-3)

#define RIGHT_LINE_A_LINE_59_X_START (RIGHT_LINE_A_LINE_58_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_59_X_END   (RIGHT_LINE_A_LINE_59_X_START-11 )
#define RIGHT_LINE_A_LINE_59_Y_START RIGHT_LINE_A_LINE_58_Y_END       // modified
#define RIGHT_LINE_A_LINE_59_Y_END   (RIGHT_LINE_A_LINE_59_Y_START-4)

#define RIGHT_LINE_A_LINE_60_X_START (RIGHT_LINE_A_LINE_59_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_60_X_END   (RIGHT_LINE_A_LINE_60_X_START-11 )
#define RIGHT_LINE_A_LINE_60_Y_START RIGHT_LINE_A_LINE_59_Y_END  + 1     // modified
#define RIGHT_LINE_A_LINE_60_Y_END   (RIGHT_LINE_A_LINE_60_Y_START-3)

#define RIGHT_LINE_A_LINE_61_X_START (RIGHT_LINE_A_LINE_60_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_61_X_END   (RIGHT_LINE_A_LINE_61_X_START-11 )
#define RIGHT_LINE_A_LINE_61_Y_START RIGHT_LINE_A_LINE_60_Y_END       // modified
#define RIGHT_LINE_A_LINE_61_Y_END   (RIGHT_LINE_A_LINE_61_Y_START-3)

#define RIGHT_LINE_A_LINE_62_X_START (RIGHT_LINE_A_LINE_61_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_62_X_END   (RIGHT_LINE_A_LINE_62_X_START-11 )
#define RIGHT_LINE_A_LINE_62_Y_START RIGHT_LINE_A_LINE_61_Y_END       // modified
#define RIGHT_LINE_A_LINE_62_Y_END   (RIGHT_LINE_A_LINE_62_Y_START-4)

#define RIGHT_LINE_A_LINE_63_X_START (RIGHT_LINE_A_LINE_62_X_END +2 )  // modified
#define RIGHT_LINE_A_LINE_63_X_END   (RIGHT_LINE_A_LINE_63_X_START-11 )
#define RIGHT_LINE_A_LINE_63_Y_START RIGHT_LINE_A_LINE_62_Y_END  + 1     // modified
#define RIGHT_LINE_A_LINE_63_Y_END   (RIGHT_LINE_A_LINE_63_Y_START-4)

uint8_t right_draw_line_1_first_draw_forward = 1;
uint8_t right_draw_line_1_first_draw_forward_switch = 1;
uint8_t right_draw_line_1_draw_backward_switch = 0;
uint8_t right_draw_line_1_draw_backward_switch_case = 0;
uint8_t right_draw_line_1_draw_forward_switch = 0;
uint8_t right_draw_line_1_draw_forward_switch_case = 0;
uint8_t right_line_1_start_timer;
uint8_t right_line_1_start_timer_exp;

extern volatile uint32_t right_drawing_screen;
extern volatile uint32_t right_drawing_screen_inc_enable;
extern volatile uint8_t right_start_drawing;
//#define LEFT_DRAW_LINE_1_COLOR_RED 1

volatile uint8_t right_init_entry;

void right_draw_line_1(void)
{
//static lv_point_t line_points_R[] = { {214, 369}, {88, 357}};
//
//    /*Create style*/
//    static lv_style_t right_style_line;
//    lv_style_init(&right_style_line);
//    lv_style_set_line_width(&right_style_line, 12);
//    lv_style_set_line_color(&right_style_line, lv_palette_main(LV_PALETTE_RED));
//    lv_style_set_line_rounded(&right_style_line, false);
//
//    /*Create a line and apply the new style*/
//    lv_obj_t * line1;
//    line1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//    lv_line_set_points(line1, line_points_R, 2);     /*Set the points*/
//    lv_obj_add_style(line1, &right_style_line, 0);
//    //lv_obj_center(line1);
	if(right_init_entry == 0)
	{
		right_line_1_start_timer = 1;
		right_line_1_start_timer_exp = 1;
		right_draw_line_1_first_draw_forward = 1;

		right_init_entry = 1;
	}
#ifndef RIGHT_DRAW_LINE_1_COLOR_RED
	lv_color_t right_first_line_color = LV_COLOR_MAKE(0,0,255);
#endif
	//lv_color_t right_last_line_color = LV_COLOR_MAKE(254,43,43);
	lv_color_t right_last_line_color = LV_COLOR_MAKE(168,16,31);
	//lv_color_t right_last_line_color = LV_COLOR_MAKE(255,85,85);
	//lv_color_t right_last_line_color = LV_COLOR_MAKE(255,0,0);

//	static lv_style_t right_right_style_line_L_11;
//	lv_style_init(&right_right_style_line_L_11);
//	lv_style_set_line_rounded(&right_right_style_line_L_11, false);

//	static lv_style_t right_style_line_L_fix;
//	lv_style_init(&right_style_line_L_fix);
//	lv_style_set_line_rounded(&right_style_line_L_fix, false);
//
//	static lv_style_t right_style_line_L_fix_temp;
//	lv_style_init(&right_style_line_L_fix_temp);
//	lv_style_set_line_rounded(&right_style_line_L_fix_temp, false);

	//right_draw_line_1_first_draw_forward_switch = 40;
	//while(1)
	if(right_start_drawing)
	{
		if(right_line_1_start_timer_exp)
		{
			//while(1)
			if(right_draw_line_1_first_draw_forward)
			{
				switch(right_draw_line_1_first_draw_forward_switch)
				{

				case 1 :
					;
					// Line - 1
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = -(10+1)
					// starting -- x = prev line ending (x +1)
					//static lv_point_t line_points_R[] = { {214, 369}, {203, 368}};
					static lv_point_t line_points_R[] = { {RIGHT_LINE_A_LINE_1_X_START, RIGHT_LINE_A_LINE_1_Y_START}, {RIGHT_LINE_A_LINE_1_X_END, RIGHT_LINE_A_LINE_1_Y_END}};
					//lv_color_t
					/*Create style*/
					static lv_style_t right_style_line;
					lv_style_init(&right_style_line);
					lv_style_set_line_width(&right_style_line, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line, 56);
					lv_style_set_line_color(&right_style_line, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_style_line, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line1;
					guider_ui.right_line1 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line1, line_points_R, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line1, &right_style_line, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 2 :
					;
					// Line - 2
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					//static lv_point_t right_right_line_points_L_1[] = { {204, 368}, {193, 367}};
					static lv_point_t right_right_line_points_L_1[] = { {RIGHT_LINE_A_LINE_2_X_START, RIGHT_LINE_A_LINE_2_Y_START}, {RIGHT_LINE_A_LINE_2_X_END, RIGHT_LINE_A_LINE_2_Y_END}};
					/*Create style*/
					static lv_style_t right_right_style_line_L_1;
					lv_style_init(&right_right_style_line_L_1);
					lv_style_set_line_width(&right_right_style_line_L_1, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_right_style_line_L_1, 56);
					lv_style_set_line_color(&right_right_style_line_L_1, right_first_line_color);
#else
					lv_style_set_line_color(&right_right_style_line_L_1, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_right_style_line_L_1, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line2;
					guider_ui.right_line2 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line2, right_right_line_points_L_1, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line2, &right_right_style_line_L_1, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 3 :
					;
					// Line - 3
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_right_line_points_L_2[] = { {RIGHT_LINE_A_LINE_3_X_START, RIGHT_LINE_A_LINE_3_Y_START}, {RIGHT_LINE_A_LINE_3_X_END, RIGHT_LINE_A_LINE_3_Y_END}};
					/*Create style*/
					static lv_style_t right_right_style_line_L_2;
					lv_style_init(&right_right_style_line_L_2);
					lv_style_set_line_width(&right_right_style_line_L_2, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					////lv_style_set_line_opa(&right_right_style_line_L_2, 56);
					lv_style_set_line_color(&right_right_style_line_L_2, right_first_line_color);
#else
					lv_style_set_line_color(&right_right_style_line_L_2, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_right_style_line_L_2, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line3;
					guider_ui.right_line3 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line3, right_right_line_points_L_2, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line3, &right_right_style_line_L_2, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 4 :
					;
					// Line - 4
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_3[] = { {RIGHT_LINE_A_LINE_4_X_START, RIGHT_LINE_A_LINE_4_Y_START}, {RIGHT_LINE_A_LINE_4_X_END, RIGHT_LINE_A_LINE_4_Y_END}};
					/*Create style*/
					static lv_style_t right_style_line_L_3;
					lv_style_init(&right_style_line_L_3);
					lv_style_set_line_width(&right_style_line_L_3, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_3, 56);
					lv_style_set_line_color(&right_style_line_L_3, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line_L_3, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_style_line_L_3, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line4;
					guider_ui.right_line4 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line4, right_line_points_L_3, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line4, &right_style_line_L_3, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 5 :
					;
					// Line - 5
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_4[] = { {RIGHT_LINE_A_LINE_5_X_START, RIGHT_LINE_A_LINE_5_Y_START}, {RIGHT_LINE_A_LINE_5_X_END, RIGHT_LINE_A_LINE_5_Y_END}};
					/*Create style*/
					static lv_style_t right_style_line_L_4;
					lv_style_init(&right_style_line_L_4);
					lv_style_set_line_width(&right_style_line_L_4, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_4, 56);
					lv_style_set_line_color(&right_style_line_L_4, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line_L_4, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_style_line_L_4, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line5;
					guider_ui.right_line5 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line5, right_line_points_L_4, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line5, &right_style_line_L_4, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 6 :
					;
					// Line - 6
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_5[] = { {RIGHT_LINE_A_LINE_6_X_START, RIGHT_LINE_A_LINE_6_Y_START}, {RIGHT_LINE_A_LINE_6_X_END, RIGHT_LINE_A_LINE_6_Y_END}};
					/*Create style*/
					static lv_style_t right_style_line_L_5;
					lv_style_init(&right_style_line_L_5);
					lv_style_set_line_width(&right_style_line_L_5, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_5, 56);
					lv_style_set_line_color(&right_style_line_L_5, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line_L_5, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_style_line_L_5, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line6;
					guider_ui.right_line6 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line6, right_line_points_L_5, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line6, &right_style_line_L_5, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 7 :
					;
					// Line - 7
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_6[] = { {RIGHT_LINE_A_LINE_7_X_START, RIGHT_LINE_A_LINE_7_Y_START}, {RIGHT_LINE_A_LINE_7_X_END, RIGHT_LINE_A_LINE_7_Y_END}};
					/*Create style*/
					static lv_style_t right_style_line_L_6;
					lv_style_init(&right_style_line_L_6);
					lv_style_set_line_width(&right_style_line_L_6, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_6, 56);
					lv_style_set_line_color(&right_style_line_L_6, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line_L_6, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_style_line_L_6, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line7;
					guider_ui.right_line7 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line7, right_line_points_L_6, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line7, &right_style_line_L_6, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 8 :
					;
					// Line - 8
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_7[] = { {RIGHT_LINE_A_LINE_8_X_START, RIGHT_LINE_A_LINE_8_Y_START}, {RIGHT_LINE_A_LINE_8_X_END, RIGHT_LINE_A_LINE_8_Y_END}};
					/*Create style*/
					static lv_style_t right_style_line_L_7;
					lv_style_init(&right_style_line_L_7);
					lv_style_set_line_width(&right_style_line_L_7, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_7, 56);
					lv_style_set_line_color(&right_style_line_L_7, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line_L_7, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_style_line_L_7, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line8;
					guider_ui.right_line8 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line8, right_line_points_L_7, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line8, &right_style_line_L_7, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 9 :
					;
					// Line - 9
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_8[] = { {RIGHT_LINE_A_LINE_9_X_START, RIGHT_LINE_A_LINE_9_Y_START}, {RIGHT_LINE_A_LINE_9_X_END, RIGHT_LINE_A_LINE_9_Y_END}};
					/*Create style*/
					static lv_style_t right_style_line_L_8;
					lv_style_init(&right_style_line_L_8);
					lv_style_set_line_width(&right_style_line_L_8, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_8, 56);
					lv_style_set_line_color(&right_style_line_L_8, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line_L_8, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_style_line_L_8, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line9;
					guider_ui.right_line9 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line9, right_line_points_L_8, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line9, &right_style_line_L_8, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 10 :
					;
					// Line - 10
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_9[] = { {RIGHT_LINE_A_LINE_10_X_START, RIGHT_LINE_A_LINE_10_Y_START}, {RIGHT_LINE_A_LINE_10_X_END, RIGHT_LINE_A_LINE_10_Y_END}};
					/*Create style*/
					static lv_style_t right_style_line_L_9;
					lv_style_init(&right_style_line_L_9);
					lv_style_set_line_width(&right_style_line_L_9, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_9, 56);
					lv_style_set_line_color(&right_style_line_L_9, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line_L_9, lv_palette_main(LV_PALETTE_RED));
#endif
					lv_style_set_line_rounded(&right_style_line_L_9, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line10;
					guider_ui.right_line10 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line10, right_line_points_L_9, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line10, &right_style_line_L_9, 0);
					//lv_obj_center(line1);
					//lv_task_handler();  // Update the display

					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 11 :
					;
					// Line - 11
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_11[] = { {RIGHT_LINE_A_LINE_11_X_START, RIGHT_LINE_A_LINE_11_Y_START}, {RIGHT_LINE_A_LINE_11_X_END, RIGHT_LINE_A_LINE_11_Y_END}};
					/*Create style*/
//					static lv_style_t right_right_style_line_L_11;
//					lv_style_init(&right_right_style_line_L_11);
					static lv_style_t right_right_style_line_L_11;
					lv_style_init(&right_right_style_line_L_11);
					lv_style_set_line_rounded(&right_right_style_line_L_11, false);
					lv_style_set_line_width(&right_right_style_line_L_11, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_9, 56);
					lv_style_set_line_color(&right_right_style_line_L_11, right_first_line_color);
#else
					lv_style_set_line_color(&right_right_style_line_L_11, lv_palette_main(LV_PALETTE_RED));
#endif
					//lv_style_set_line_color(&right_right_style_line_L_11, lv_palette_main(LV_PALETTE_RED));
//					lv_style_set_line_rounded(&right_right_style_line_L_11, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line11;
					guider_ui.right_line11 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line11, right_line_points_L_11, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line11, &right_right_style_line_L_11, 0);
					//lv_obj_center(line1);
					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 12 :
					;
					// Line - 12
					//12 lines : y = 12/12 = 1 --> each Y dec by 1 each time
					//12 lines : x = 128/12 = 10.66 = 10+1
					// starting -- x = prev line ending (x +1)
					static lv_point_t right_line_points_L_12[] = { {RIGHT_LINE_A_LINE_12_X_START, RIGHT_LINE_A_LINE_12_Y_START}, {RIGHT_LINE_A_LINE_12_X_END, RIGHT_LINE_A_LINE_12_Y_END}};
					/*Create style*/
//					static lv_style_t right_style_line_L_fix;
//					lv_style_init(&right_style_line_L_fix);
					static lv_style_t right_style_line_L_12;
					lv_style_init(&right_style_line_L_12);
					lv_style_set_line_rounded(&right_style_line_L_12, false);
					lv_style_set_line_width(&right_style_line_L_12, 12);
#ifndef LEFT_DRAW_LINE_1_COLOR_RED
					//lv_style_set_line_opa(&right_style_line_L_9, 56);
					lv_style_set_line_color(&right_style_line_L_12, right_first_line_color);
#else
					lv_style_set_line_color(&right_style_line_L_12, lv_palette_main(LV_PALETTE_RED));
#endif
//					lv_style_set_line_rounded(&right_style_line_L_fix, false);
					/*Create a line and apply the new style*/
					//lv_obj_t * line12;
					guider_ui.right_line12 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line12, right_line_points_L_12, 2);     /*Set the points*/
					lv_obj_add_style(guider_ui.right_line12, &right_style_line_L_12, 0);
					//lv_obj_center(line1);

					right_draw_line_1_first_draw_forward_switch++;
					break;

				case 13 :
					;
					static lv_point_t right_line_points_L_13[] = { {RIGHT_LINE_A_LINE_13_X_START, RIGHT_LINE_A_LINE_13_Y_START}, {RIGHT_LINE_A_LINE_13_X_END, RIGHT_LINE_A_LINE_13_Y_END}};
    				guider_ui.right_line13 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line13, right_line_points_L_13, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_13;
					lv_style_init(&right_style_line_L_13);
					lv_style_set_line_rounded(&right_style_line_L_13, true);
					lv_style_set_line_width(&right_style_line_L_13, 14);
					lv_style_set_line_color(&right_style_line_L_13, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line13, &right_style_line_L_13, 0);

	    			//lv_task_handler();  // Update the display

	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 14 :
					;

					static lv_point_t right_line_points_L_14[] = { {RIGHT_LINE_A_LINE_14_X_START, RIGHT_LINE_A_LINE_14_Y_START}, {RIGHT_LINE_A_LINE_14_X_END, RIGHT_LINE_A_LINE_14_Y_END}};
    				guider_ui.right_line14 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line14, right_line_points_L_14, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_14;
					lv_style_init(&right_style_line_L_14);
					lv_style_set_line_rounded(&right_style_line_L_14, true);
					lv_style_set_line_width(&right_style_line_L_14, 12);
					lv_style_set_line_color(&right_style_line_L_14, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line14, &right_style_line_L_14, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 15 :
					;
					static lv_point_t right_line_points_L_15[] = { {RIGHT_LINE_A_LINE_15_X_START, RIGHT_LINE_A_LINE_15_Y_START}, {RIGHT_LINE_A_LINE_15_X_END, RIGHT_LINE_A_LINE_15_Y_END}};
    				guider_ui.right_line15 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line15, right_line_points_L_15, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_15;
					lv_style_init(&right_style_line_L_15);
					lv_style_set_line_rounded(&right_style_line_L_15, true);
					lv_style_set_line_width(&right_style_line_L_15, 14);
					lv_style_set_line_color(&right_style_line_L_15, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line15, &right_style_line_L_15, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 16 :
					;
					static lv_point_t right_line_points_L_16[] = { {RIGHT_LINE_A_LINE_16_X_START, RIGHT_LINE_A_LINE_16_Y_START}, {RIGHT_LINE_A_LINE_16_X_END, RIGHT_LINE_A_LINE_16_Y_END}};
    				guider_ui.right_line16 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line16, right_line_points_L_16, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_16;
					lv_style_init(&right_style_line_L_16);
					lv_style_set_line_rounded(&right_style_line_L_16, true);
					lv_style_set_line_width(&right_style_line_L_16, 14);
					lv_style_set_line_color(&right_style_line_L_16, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line16, &right_style_line_L_16, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 17 :
					;
					static lv_point_t right_line_points_L_17[] = { {RIGHT_LINE_A_LINE_17_X_START, RIGHT_LINE_A_LINE_17_Y_START}, {RIGHT_LINE_A_LINE_17_X_END, RIGHT_LINE_A_LINE_17_Y_END}};
    				guider_ui.right_line17 = lv_line_create(guider_ui.screen_drawing_container_drawing);
    				lv_line_set_points(guider_ui.right_line17, right_line_points_L_17, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_17;
					lv_style_init(&right_style_line_L_17);
					lv_style_set_line_rounded(&right_style_line_L_17, true);
					lv_style_set_line_width(&right_style_line_L_17, 14);
					lv_style_set_line_color(&right_style_line_L_17, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line17, &right_style_line_L_17, 0);

					//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 18 :
					;
					static lv_point_t right_line_points_L_18[] = { {RIGHT_LINE_A_LINE_18_X_START, RIGHT_LINE_A_LINE_18_Y_START}, {RIGHT_LINE_A_LINE_18_X_END, RIGHT_LINE_A_LINE_18_Y_END}};
    				guider_ui.right_line18 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line18, right_line_points_L_18, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_18;
					lv_style_init(&right_style_line_L_18);
					lv_style_set_line_rounded(&right_style_line_L_18, true);
					lv_style_set_line_width(&right_style_line_L_18, 14);
					lv_style_set_line_color(&right_style_line_L_18, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line18, &right_style_line_L_18, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 19 :
					;
					static lv_point_t right_line_points_L_19[] = { {RIGHT_LINE_A_LINE_19_X_START, RIGHT_LINE_A_LINE_19_Y_START}, {RIGHT_LINE_A_LINE_19_X_END, RIGHT_LINE_A_LINE_19_Y_END}};
    				guider_ui.right_line19 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line19, right_line_points_L_19, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_19;
					lv_style_init(&right_style_line_L_19);
					lv_style_set_line_rounded(&right_style_line_L_19, true);
					lv_style_set_line_width(&right_style_line_L_19, 14);
					lv_style_set_line_color(&right_style_line_L_19, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line19, &right_style_line_L_19, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 20 :
					;
					static lv_point_t right_line_points_L_20[] = { {RIGHT_LINE_A_LINE_20_X_START, RIGHT_LINE_A_LINE_20_Y_START}, {RIGHT_LINE_A_LINE_20_X_END, RIGHT_LINE_A_LINE_20_Y_END}};
    				guider_ui.right_line20 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line20, right_line_points_L_20, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_20;
					lv_style_init(&right_style_line_L_20);
					lv_style_set_line_rounded(&right_style_line_L_20, true);
					lv_style_set_line_width(&right_style_line_L_20, 14);
					lv_style_set_line_color(&right_style_line_L_20, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line20, &right_style_line_L_20, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 21 :
					;
					static lv_point_t right_line_points_L_21[] = { {RIGHT_LINE_A_LINE_21_X_START, RIGHT_LINE_A_LINE_21_Y_START}, {RIGHT_LINE_A_LINE_21_X_END, RIGHT_LINE_A_LINE_21_Y_END}};
    				guider_ui.right_line21 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line21, right_line_points_L_21, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_21;
					lv_style_init(&right_style_line_L_21);
					lv_style_set_line_rounded(&right_style_line_L_21, true);
					lv_style_set_line_width(&right_style_line_L_21, 14);
					lv_style_set_line_color(&right_style_line_L_21, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line21, &right_style_line_L_21, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 22 :
					;
	    			/// bunch
	    			static lv_point_t right_line_points_L_22[] = { {RIGHT_LINE_A_LINE_22_X_START, RIGHT_LINE_A_LINE_22_Y_START}, {RIGHT_LINE_A_LINE_22_X_END, RIGHT_LINE_A_LINE_22_Y_END}};
	    			guider_ui.right_line22 = lv_line_create(guider_ui.screen_drawing_container_drawing);
	    			lv_line_set_points(guider_ui.right_line22, right_line_points_L_22, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_22;
					lv_style_init(&right_style_line_L_22);
					lv_style_set_line_rounded(&right_style_line_L_22, true);
					lv_style_set_line_width(&right_style_line_L_22, 14);
					lv_style_set_line_color(&right_style_line_L_22, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line22, &right_style_line_L_22, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 23 :
					;
					static lv_point_t right_line_points_L_23[] = { {RIGHT_LINE_A_LINE_23_X_START, (RIGHT_LINE_A_LINE_23_Y_START-2)}, {RIGHT_LINE_A_LINE_23_X_END, RIGHT_LINE_A_LINE_23_Y_END}};
    				guider_ui.right_line23 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line23, right_line_points_L_23, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_23;
					lv_style_init(&right_style_line_L_23);
					lv_style_set_line_rounded(&right_style_line_L_23, true);
					lv_style_set_line_width(&right_style_line_L_23, 14);
					lv_style_set_line_color(&right_style_line_L_23, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line23, &right_style_line_L_23, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;

					break;

				case 24 :
					;
					static lv_point_t right_line_points_L_24[] = { {RIGHT_LINE_A_LINE_24_X_START, (RIGHT_LINE_A_LINE_24_Y_START-2)}, {RIGHT_LINE_A_LINE_24_X_END, RIGHT_LINE_A_LINE_24_Y_END}};
    				guider_ui.right_line24 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line24, right_line_points_L_24, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_24;
					lv_style_init(&right_style_line_L_24);
					lv_style_set_line_rounded(&right_style_line_L_24, true);
					lv_style_set_line_width(&right_style_line_L_24, 14);
					lv_style_set_line_color(&right_style_line_L_24, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line24, &right_style_line_L_24, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 25 :
					;
					static lv_point_t right_line_points_L_25[] = { {RIGHT_LINE_A_LINE_25_X_START, RIGHT_LINE_A_LINE_25_Y_START}, {RIGHT_LINE_A_LINE_25_X_END, RIGHT_LINE_A_LINE_25_Y_END}};
    				guider_ui.right_line25 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line25, right_line_points_L_25, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_25;
					lv_style_init(&right_style_line_L_25);
					lv_style_set_line_rounded(&right_style_line_L_25, true);
					lv_style_set_line_width(&right_style_line_L_25, 14);
					lv_style_set_line_color(&right_style_line_L_25, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line25, &right_style_line_L_25, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 26 :
					;
					static lv_point_t right_line_points_L_26[] = { {RIGHT_LINE_A_LINE_26_X_START, RIGHT_LINE_A_LINE_26_Y_START}, {RIGHT_LINE_A_LINE_26_X_END, RIGHT_LINE_A_LINE_26_Y_END}};
    				guider_ui.right_line26 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line26, right_line_points_L_26, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_26;
					lv_style_init(&right_style_line_L_26);
					lv_style_set_line_rounded(&right_style_line_L_26, true);
					lv_style_set_line_width(&right_style_line_L_26, 14);
					lv_style_set_line_color(&right_style_line_L_26, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line26, &right_style_line_L_26, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

					//bunch
				case 27 :
					;

					static lv_point_t right_line_points_L_27[] = { {RIGHT_LINE_A_LINE_27_X_START, RIGHT_LINE_A_LINE_27_Y_START}, {RIGHT_LINE_A_LINE_27_X_END, RIGHT_LINE_A_LINE_27_Y_END}};
    				guider_ui.right_line27 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line27, right_line_points_L_27, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_27;
					lv_style_init(&right_style_line_L_27);
					lv_style_set_line_rounded(&right_style_line_L_27, true);
					lv_style_set_line_width(&right_style_line_L_27, 14);
					lv_style_set_line_color(&right_style_line_L_27, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line27, &right_style_line_L_27, 0);

	    			lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_28[] = { {RIGHT_LINE_A_LINE_28_X_START, RIGHT_LINE_A_LINE_28_Y_START}, {(RIGHT_LINE_A_LINE_28_X_END-1), RIGHT_LINE_A_LINE_28_Y_END}};
    				guider_ui.right_line28 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line28, right_line_points_L_28, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_28;
					lv_style_init(&right_style_line_L_28);
					lv_style_set_line_rounded(&right_style_line_L_28, true);
					lv_style_set_line_width(&right_style_line_L_28, 14);
					lv_style_set_line_color(&right_style_line_L_28, right_first_line_color);
	    			lv_obj_add_style(guider_ui.right_line28, &right_style_line_L_28, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 28 :
					;
					static lv_point_t right_line_points_L_29[] = { {(RIGHT_LINE_A_LINE_29_X_START -1), RIGHT_LINE_A_LINE_29_Y_START}, {(RIGHT_LINE_A_LINE_29_X_END-1), RIGHT_LINE_A_LINE_29_Y_END}};
    				guider_ui.right_line29 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line29, right_line_points_L_29, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_29;
					lv_style_init(&right_style_line_L_29);
					lv_style_set_line_width(&right_style_line_L_29, 14);
					lv_style_set_line_color(&right_style_line_L_29, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_29, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line29, &right_style_line_L_29, 0);

	    			lv_task_handler();  // Update the display


					static lv_point_t right_line_points_L_30[] = { {RIGHT_LINE_A_LINE_30_X_START, RIGHT_LINE_A_LINE_30_Y_START}, {RIGHT_LINE_A_LINE_30_X_END, RIGHT_LINE_A_LINE_30_Y_END}};
    				guider_ui.right_line30 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line30, right_line_points_L_30, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_30;
					lv_style_init(&right_style_line_L_30);
					lv_style_set_line_width(&right_style_line_L_30, 15);
					lv_style_set_line_color(&right_style_line_L_30, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_30, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line30, &right_style_line_L_30, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 29 :
					;

					static lv_point_t right_line_points_L_31[] = { {RIGHT_LINE_A_LINE_31_X_START, RIGHT_LINE_A_LINE_31_Y_START}, {RIGHT_LINE_A_LINE_31_X_END, RIGHT_LINE_A_LINE_31_Y_END}};
    				guider_ui.right_line31 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line31, right_line_points_L_31, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_31;
					lv_style_init(&right_style_line_L_31);
					lv_style_set_line_width(&right_style_line_L_31, 15);
					lv_style_set_line_color(&right_style_line_L_31, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_31, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line31, &right_style_line_L_31, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_32[] = { {RIGHT_LINE_A_LINE_32_X_START, RIGHT_LINE_A_LINE_32_Y_START}, {RIGHT_LINE_A_LINE_32_X_END, RIGHT_LINE_A_LINE_32_Y_END}};
    				guider_ui.right_line32 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line32, right_line_points_L_32, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_32;
					lv_style_init(&right_style_line_L_32);
					lv_style_set_line_width(&right_style_line_L_32, 15);
					lv_style_set_line_color(&right_style_line_L_32, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_32, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line32, &right_style_line_L_32, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 30 :
					;
					static lv_point_t right_line_points_L_33[] = { {RIGHT_LINE_A_LINE_33_X_START, RIGHT_LINE_A_LINE_33_Y_START}, {RIGHT_LINE_A_LINE_33_X_END, RIGHT_LINE_A_LINE_33_Y_END}};
    				guider_ui.right_line33 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line33, right_line_points_L_33, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_33;
					lv_style_init(&right_style_line_L_33);
					lv_style_set_line_width(&right_style_line_L_33, 15);
					lv_style_set_line_color(&right_style_line_L_33, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_33, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line33, &right_style_line_L_33, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_34[] = { {RIGHT_LINE_A_LINE_34_X_START, RIGHT_LINE_A_LINE_34_Y_START}, {RIGHT_LINE_A_LINE_34_X_END, RIGHT_LINE_A_LINE_34_Y_END}};
    				guider_ui.right_line34 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line34, right_line_points_L_34, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_34;
					lv_style_init(&right_style_line_L_34);
					lv_style_set_line_width(&right_style_line_L_34, 15);
					lv_style_set_line_color(&right_style_line_L_34, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_34, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line34, &right_style_line_L_34, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 31 :
					;
					static lv_point_t right_line_points_L_35[] = { {RIGHT_LINE_A_LINE_35_X_START, RIGHT_LINE_A_LINE_35_Y_START}, {RIGHT_LINE_A_LINE_35_X_END, RIGHT_LINE_A_LINE_35_Y_END}};
    				guider_ui.right_line35 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line35, right_line_points_L_35, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_35;
					lv_style_init(&right_style_line_L_35);
					lv_style_set_line_width(&right_style_line_L_35, 15);
					lv_style_set_line_color(&right_style_line_L_35, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_35, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line35, &right_style_line_L_35, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_36[] = { {RIGHT_LINE_A_LINE_36_X_START, RIGHT_LINE_A_LINE_36_Y_START}, {RIGHT_LINE_A_LINE_36_X_END, RIGHT_LINE_A_LINE_36_Y_END}};
    				guider_ui.right_line36 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line36, right_line_points_L_36, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_36;
					lv_style_init(&right_style_line_L_36);
					lv_style_set_line_width(&right_style_line_L_36, 15);
					lv_style_set_line_color(&right_style_line_L_36, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_36, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line36, &right_style_line_L_36, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 32 :
					;
					static lv_point_t right_line_points_L_37[] = { {RIGHT_LINE_A_LINE_37_X_START, RIGHT_LINE_A_LINE_37_Y_START}, {RIGHT_LINE_A_LINE_37_X_END, RIGHT_LINE_A_LINE_37_Y_END}};
    				guider_ui.right_line37 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line37, right_line_points_L_37, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_37;
					lv_style_init(&right_style_line_L_37);
					lv_style_set_line_width(&right_style_line_L_37, 15);
					lv_style_set_line_color(&right_style_line_L_37, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_37, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line37, &right_style_line_L_37, 0);

	    			lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_38[] = { {RIGHT_LINE_A_LINE_38_X_START, RIGHT_LINE_A_LINE_38_Y_START}, {RIGHT_LINE_A_LINE_38_X_END, RIGHT_LINE_A_LINE_38_Y_END}};
    				guider_ui.right_line38 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line38, right_line_points_L_38, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_38;
					lv_style_init(&right_style_line_L_38);
					lv_style_set_line_width(&right_style_line_L_38, 15);
					lv_style_set_line_color(&right_style_line_L_38, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_38, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line38, &right_style_line_L_38, 0);

	    			lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 33 :
					;
					static lv_point_t right_line_points_L_39[] = { {RIGHT_LINE_A_LINE_39_X_START, RIGHT_LINE_A_LINE_39_Y_START}, {RIGHT_LINE_A_LINE_39_X_END, RIGHT_LINE_A_LINE_39_Y_END}};
    				guider_ui.right_line39 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line39, right_line_points_L_39, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_39;
					lv_style_init(&right_style_line_L_39);
					lv_style_set_line_width(&right_style_line_L_39, 15);
					lv_style_set_line_color(&right_style_line_L_39, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_39, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line39, &right_style_line_L_39, 0);

	    			lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_40[] = { {RIGHT_LINE_A_LINE_40_X_START, RIGHT_LINE_A_LINE_40_Y_START}, {RIGHT_LINE_A_LINE_40_X_END, RIGHT_LINE_A_LINE_40_Y_END}};
    				guider_ui.right_line40 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line40, right_line_points_L_40, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_40;
					lv_style_init(&right_style_line_L_40);
					lv_style_set_line_width(&right_style_line_L_40, 17);
					lv_style_set_line_color(&right_style_line_L_40, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_40, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line40, &right_style_line_L_40, 0);

	    			lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 34 :
					;
					static lv_point_t right_line_points_L_41[] = { {RIGHT_LINE_A_LINE_41_X_START, RIGHT_LINE_A_LINE_41_Y_START}, {RIGHT_LINE_A_LINE_41_X_END, RIGHT_LINE_A_LINE_41_Y_END}};
    				guider_ui.right_line41 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line41, right_line_points_L_41, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_41;
					lv_style_init(&right_style_line_L_41);
					lv_style_set_line_width(&right_style_line_L_41, 17);
					lv_style_set_line_color(&right_style_line_L_41, right_first_line_color);
					lv_style_set_line_rounded(&right_style_line_L_41, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line41, &right_style_line_L_41, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_42[] = { {RIGHT_LINE_A_LINE_42_X_START, RIGHT_LINE_A_LINE_42_Y_START}, {RIGHT_LINE_A_LINE_42_X_END, RIGHT_LINE_A_LINE_42_Y_END}};
    				guider_ui.right_line42 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line42, right_line_points_L_42, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_42;
					lv_style_init(&right_style_line_L_42);
					lv_style_set_line_width(&right_style_line_L_42, 17);
					lv_style_set_line_color(&right_style_line_L_42, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_42, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line42, &right_style_line_L_42, 0);

	    			lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 35 :
					;
					static lv_point_t right_line_points_L_43[] = { {RIGHT_LINE_A_LINE_43_X_START, RIGHT_LINE_A_LINE_43_Y_START}, {RIGHT_LINE_A_LINE_43_X_END, RIGHT_LINE_A_LINE_43_Y_END}};
    				guider_ui.right_line43 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line43, right_line_points_L_43, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_43;
					lv_style_init(&right_style_line_L_43);
					lv_style_set_line_width(&right_style_line_L_43, 16);
					lv_style_set_line_color(&right_style_line_L_43, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_43, true); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line43, &right_style_line_L_43, 0);


					static lv_point_t right_line_points_L_44[] = { {RIGHT_LINE_A_LINE_44_X_START, RIGHT_LINE_A_LINE_44_Y_START}, {RIGHT_LINE_A_LINE_44_X_END, RIGHT_LINE_A_LINE_44_Y_END}};
    				guider_ui.right_line44 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line44, right_line_points_L_44, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_44;
					lv_style_init(&right_style_line_L_44);
					lv_style_set_line_width(&right_style_line_L_44, 16);
					lv_style_set_line_color(&right_style_line_L_44, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_44, true); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line44, &right_style_line_L_44, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 36 :
					;
					static lv_point_t right_line_points_L_45[] = { {RIGHT_LINE_A_LINE_45_X_START, RIGHT_LINE_A_LINE_45_Y_START}, {RIGHT_LINE_A_LINE_45_X_END, RIGHT_LINE_A_LINE_45_Y_END}};
    				guider_ui.right_line45 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line45, right_line_points_L_45, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_45;
					lv_style_init(&right_style_line_L_45);
					lv_style_set_line_width(&right_style_line_L_45, 16);
					lv_style_set_line_color(&right_style_line_L_45, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_45, true); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line45, &right_style_line_L_45, 0);

	    			lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_46[] = { {RIGHT_LINE_A_LINE_46_X_START, RIGHT_LINE_A_LINE_46_Y_START}, {RIGHT_LINE_A_LINE_46_X_END, RIGHT_LINE_A_LINE_46_Y_END}};
    				guider_ui.right_line46 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line46, right_line_points_L_46, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_46;
					lv_style_init(&right_style_line_L_46);
					lv_style_set_line_width(&right_style_line_L_46, 15);
					lv_style_set_line_color(&right_style_line_L_46, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_46, true); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line46, &right_style_line_L_46, 0);

	    			lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 37:
					;
					static lv_point_t right_line_points_L_47[] = { {RIGHT_LINE_A_LINE_47_X_START, RIGHT_LINE_A_LINE_47_Y_START}, {RIGHT_LINE_A_LINE_47_X_END, RIGHT_LINE_A_LINE_47_Y_END}};
    				guider_ui.right_line47 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line47, right_line_points_L_47, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_47;
					lv_style_init(&right_style_line_L_47);
					lv_style_set_line_width(&right_style_line_L_47, 15);
					lv_style_set_line_color(&right_style_line_L_47, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_47, true); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line47, &right_style_line_L_47, 0);

	    			lv_task_handler();  // Update the display
//	    			right_draw_line_1_first_draw_forward_switch = 88;
//	    			break;

					static lv_point_t right_line_points_L_48[] = { {RIGHT_LINE_A_LINE_48_X_START, RIGHT_LINE_A_LINE_48_Y_START}, {RIGHT_LINE_A_LINE_48_X_END, RIGHT_LINE_A_LINE_48_Y_END}};
    				guider_ui.right_line48 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line48, right_line_points_L_48, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_48;
					lv_style_init(&right_style_line_L_48);
					lv_style_set_line_width(&right_style_line_L_48, 14);
					lv_style_set_line_color(&right_style_line_L_48, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_48, true); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line48, &right_style_line_L_48, 0);

	    			lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
//	    			right_draw_line_1_first_draw_forward_switch = 88;
					break;

				case 38 :
					;
					static lv_point_t right_line_points_L_49[] = { {RIGHT_LINE_A_LINE_49_X_START, RIGHT_LINE_A_LINE_49_Y_START}, {RIGHT_LINE_A_LINE_49_X_END, RIGHT_LINE_A_LINE_49_Y_END}};
    				guider_ui.right_line49 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line49, right_line_points_L_49, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_49;
					lv_style_init(&right_style_line_L_49);
					lv_style_set_line_width(&right_style_line_L_49, 14);
					lv_style_set_line_color(&right_style_line_L_49, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_49, true); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line49, &right_style_line_L_49, 0);

	    			lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_50[] = { {RIGHT_LINE_A_LINE_50_X_START, RIGHT_LINE_A_LINE_50_Y_START}, {RIGHT_LINE_A_LINE_50_X_END, RIGHT_LINE_A_LINE_50_Y_END}};
    				guider_ui.right_line50 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line50, right_line_points_L_50, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_50;
					lv_style_init(&right_style_line_L_50);
					lv_style_set_line_width(&right_style_line_L_50, 14);
					lv_style_set_line_color(&right_style_line_L_50, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_50, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line50, &right_style_line_L_50, 0);

	    			lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
	    			//right_draw_line_1_first_draw_forward_switch = 88;
					break;

				case 39 :
					;
					static lv_point_t right_line_points_L_51[] = { {RIGHT_LINE_A_LINE_51_X_START, RIGHT_LINE_A_LINE_51_Y_START}, {RIGHT_LINE_A_LINE_51_X_END, RIGHT_LINE_A_LINE_51_Y_END}};
    				guider_ui.right_line51 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line51, right_line_points_L_51, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_51;
					lv_style_init(&right_style_line_L_51);
					lv_style_set_line_width(&right_style_line_L_51, 14);
					lv_style_set_line_color(&right_style_line_L_51, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_51, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line51, &right_style_line_L_51, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_52[] = { {RIGHT_LINE_A_LINE_52_X_START, RIGHT_LINE_A_LINE_52_Y_START}, {RIGHT_LINE_A_LINE_52_X_END, RIGHT_LINE_A_LINE_52_Y_END}};
    				guider_ui.right_line52 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line52, right_line_points_L_52, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_52;
					lv_style_init(&right_style_line_L_52);
					lv_style_set_line_width(&right_style_line_L_52, 14);
					lv_style_set_line_color(&right_style_line_L_52, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_52, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line52, &right_style_line_L_52, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
	    			//right_draw_line_1_first_draw_forward_switch = 88;
					break;

				case 40 :
					;
					static lv_point_t right_line_points_L_53[] = { {RIGHT_LINE_A_LINE_53_X_START, RIGHT_LINE_A_LINE_53_Y_START}, {RIGHT_LINE_A_LINE_53_X_END, RIGHT_LINE_A_LINE_53_Y_END}};
    				guider_ui.right_line53 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line53, right_line_points_L_53, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_53;
					lv_style_init(&right_style_line_L_53);
					lv_style_set_line_width(&right_style_line_L_53, 14);
					lv_style_set_line_color(&right_style_line_L_53, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_53, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line53, &right_style_line_L_53, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_54[] = { {RIGHT_LINE_A_LINE_54_X_START, RIGHT_LINE_A_LINE_54_Y_START}, {RIGHT_LINE_A_LINE_54_X_END, RIGHT_LINE_A_LINE_54_Y_END}};
    				guider_ui.right_line54 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line54, right_line_points_L_54, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_54;
					lv_style_init(&right_style_line_L_54);
					lv_style_set_line_width(&right_style_line_L_54, 14);
					lv_style_set_line_color(&right_style_line_L_54, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_54, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line54, &right_style_line_L_54, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 41 :
					;
					static lv_point_t right_line_points_L_55[] = { {RIGHT_LINE_A_LINE_55_X_START, RIGHT_LINE_A_LINE_55_Y_START}, {RIGHT_LINE_A_LINE_55_X_END, RIGHT_LINE_A_LINE_55_Y_END}};
    				guider_ui.right_line55 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line55, right_line_points_L_55, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_55;
					lv_style_init(&right_style_line_L_55);
					lv_style_set_line_width(&right_style_line_L_55, 14);
					lv_style_set_line_color(&right_style_line_L_55, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_55, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line55, &right_style_line_L_55, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_56[] = { {RIGHT_LINE_A_LINE_56_X_START, RIGHT_LINE_A_LINE_56_Y_START}, {RIGHT_LINE_A_LINE_56_X_END, RIGHT_LINE_A_LINE_56_Y_END}};
    				guider_ui.right_line56 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line56, right_line_points_L_56, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_56;
					lv_style_init(&right_style_line_L_56);
					lv_style_set_line_width(&right_style_line_L_56, 14);
					lv_style_set_line_color(&right_style_line_L_56, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_56, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line56, &right_style_line_L_56, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
	    			//right_draw_line_1_first_draw_forward_switch = 88;
					break;

				case 42 :
					;
					static lv_point_t right_line_points_L_57[] = { {RIGHT_LINE_A_LINE_57_X_START, RIGHT_LINE_A_LINE_57_Y_START}, {RIGHT_LINE_A_LINE_57_X_END, RIGHT_LINE_A_LINE_57_Y_END}};
    				guider_ui.right_line57 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line57, right_line_points_L_57, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_57;
					lv_style_init(&right_style_line_L_57);
					lv_style_set_line_width(&right_style_line_L_57, 14);
					lv_style_set_line_color(&right_style_line_L_57, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_57, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line57, &right_style_line_L_57, 0);

	    			//lv_task_handler();  // Update the display

					static lv_point_t right_line_points_L_58[] = { {RIGHT_LINE_A_LINE_58_X_START, RIGHT_LINE_A_LINE_58_Y_START}, {RIGHT_LINE_A_LINE_58_X_END, RIGHT_LINE_A_LINE_58_Y_END}};
    				guider_ui.right_line58 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line58, right_line_points_L_58, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_58;
					lv_style_init(&right_style_line_L_58);
					lv_style_set_line_width(&right_style_line_L_58, 14);
					lv_style_set_line_color(&right_style_line_L_58, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_58, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line58, &right_style_line_L_58, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 43 :
					;
					static lv_point_t right_line_points_L_59[] = { {RIGHT_LINE_A_LINE_59_X_START, RIGHT_LINE_A_LINE_59_Y_START}, {RIGHT_LINE_A_LINE_59_X_END, RIGHT_LINE_A_LINE_59_Y_END}};
    				guider_ui.right_line59 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line59, right_line_points_L_59, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_59;
					lv_style_init(&right_style_line_L_59);
					lv_style_set_line_width(&right_style_line_L_59, 14);
					lv_style_set_line_color(&right_style_line_L_59, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_59, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line59, &right_style_line_L_59, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
//	    			right_draw_line_1_first_draw_forward_switch = 88;
					break;

				case 44 :
					;
					static lv_point_t right_line_points_L_60[] = { {RIGHT_LINE_A_LINE_60_X_START, RIGHT_LINE_A_LINE_60_Y_START}, {RIGHT_LINE_A_LINE_60_X_END, RIGHT_LINE_A_LINE_60_Y_END}};
    				guider_ui.right_line60 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line60, right_line_points_L_60, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_60;
					lv_style_init(&right_style_line_L_60);
					lv_style_set_line_width(&right_style_line_L_60, 14);
					lv_style_set_line_color(&right_style_line_L_60, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_60, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line60, &right_style_line_L_60, 0);

	    			//lv_task_handler();  // Update the display
	    			right_draw_line_1_first_draw_forward_switch++;
					break;

				case 45 :
					;
					static lv_point_t right_line_points_L_61[] = { {RIGHT_LINE_A_LINE_61_X_START, RIGHT_LINE_A_LINE_61_Y_START}, {RIGHT_LINE_A_LINE_61_X_END, RIGHT_LINE_A_LINE_61_Y_END}};
    				guider_ui.right_line61 = lv_line_create(guider_ui.screen_drawing_container_drawing);
					lv_line_set_points(guider_ui.right_line61, right_line_points_L_61, 2);     /*Set the points*/
					static lv_style_t right_style_line_L_61;
					lv_style_init(&right_style_line_L_61);
					lv_style_set_line_width(&right_style_line_L_61, 14);
					lv_style_set_line_color(&right_style_line_L_61, right_last_line_color);
					lv_style_set_line_rounded(&right_style_line_L_61, false); // rectangle false
	    			lv_obj_add_style(guider_ui.right_line61, &right_style_line_L_61, 0);

	    			//lv_task_handler();  // Update the display
	    			//right_draw_line_1_first_draw_forward_switch++;
	    			//final
	    			// first time draw completed
	    			right_draw_line_1_first_draw_forward_switch=0;
	    			right_draw_line_1_first_draw_forward = 0;
	    			right_draw_line_1_draw_backward_switch = 1;
					break;

//				case 46 :
//					;
//					static lv_point_t right_line_points_L_62[] = { {RIGHT_LINE_A_LINE_62_X_START, RIGHT_LINE_A_LINE_62_Y_START}, {RIGHT_LINE_A_LINE_62_X_END, RIGHT_LINE_A_LINE_62_Y_END}};
//    				guider_ui.right_line62 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.right_line62, right_line_points_L_62, 2);     /*Set the points*/
//					static lv_style_t right_style_line_L_62;
//					lv_style_init(&right_style_line_L_62);
//					lv_style_set_line_width(&right_style_line_L_62, 14);
//					lv_style_set_line_color(&right_style_line_L_62, right_last_line_color);
//					lv_style_set_line_rounded(&right_style_line_L_62, false); // rectangle false
//	    			lv_obj_add_style(guider_ui.right_line62, &right_style_line_L_62, 0);
//
//	    			//lv_task_handler();  // Update the display
//	    			right_draw_line_1_first_draw_forward_switch++;
//	    			//right_draw_line_1_first_draw_forward_switch = 88;
//					break;
//
//				case 47 :
//					;
//					static lv_point_t right_line_points_L_63[] = { {RIGHT_LINE_A_LINE_63_X_START, RIGHT_LINE_A_LINE_63_Y_START}, {RIGHT_LINE_A_LINE_63_X_END, RIGHT_LINE_A_LINE_63_Y_END}};
//    				guider_ui.right_line63 = lv_line_create(guider_ui.screen_drawing_container_drawing);
//					lv_line_set_points(guider_ui.right_line63, right_line_points_L_63, 2);     /*Set the points*/
//					static lv_style_t right_style_line_L_63;
//					lv_style_init(&right_style_line_L_63);
//					lv_style_set_line_width(&right_style_line_L_63, 14);
//					lv_style_set_line_color(&right_style_line_L_63, right_last_line_color);
//					lv_style_set_line_rounded(&right_style_line_L_63, false); // rectangle false
//	    			lv_obj_add_style(guider_ui.right_line63, &right_style_line_L_63, 0);
//
//	    			//lv_task_handler();  // Update the display
//
//	    			//final
//	    			// first time draw completed
//	    			right_draw_line_1_first_draw_forward_switch=0;
//	    			right_draw_line_1_first_draw_forward = 0;
//	    			right_draw_line_1_draw_backward_switch = 1;
//					break;

				default :
					break;
				}

				lv_task_handler();  // Update the display
			}
			else
			{
				if(right_draw_line_1_draw_backward_switch)
				{
					switch (right_draw_line_1_draw_backward_switch_case)
					{
//					case 0 :
//						lv_obj_add_flag(guider_ui.right_line63, LV_OBJ_FLAG_HIDDEN);
//						right_draw_line_1_draw_backward_switch_case++;
//						break;
//					case 1 :
//						lv_obj_add_flag(guider_ui.right_line62, LV_OBJ_FLAG_HIDDEN);
//						right_draw_line_1_draw_backward_switch_case++;
//						break;
					case 0 :
						lv_obj_add_flag(guider_ui.right_line61, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 1 :
						lv_obj_add_flag(guider_ui.right_line60, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 2 :
						lv_obj_add_flag(guider_ui.right_line59, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 3 :
						lv_obj_add_flag(guider_ui.right_line58, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line57, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 4 :
						lv_obj_add_flag(guider_ui.right_line56, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line55, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 5 :
						lv_obj_add_flag(guider_ui.right_line54, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line53, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 6 :
						lv_obj_add_flag(guider_ui.right_line52, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line51, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 7 :
						lv_obj_add_flag(guider_ui.right_line50, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line49, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 8 :
						lv_obj_add_flag(guider_ui.right_line48, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line47, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 9 :
						lv_obj_add_flag(guider_ui.right_line46, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line45, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 10 :
						lv_obj_add_flag(guider_ui.right_line44, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line43, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 11 :
						lv_obj_add_flag(guider_ui.right_line42, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line41, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 12 :
						lv_obj_add_flag(guider_ui.right_line40, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line39, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 13 :
						lv_obj_add_flag(guider_ui.right_line38, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line37, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 14 :
						lv_obj_add_flag(guider_ui.right_line36, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line35, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 15 :
						lv_obj_add_flag(guider_ui.right_line34, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line33, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 16 :
						lv_obj_add_flag(guider_ui.right_line32, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line31, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 17 :
						lv_obj_add_flag(guider_ui.right_line30, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line29, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 18 :
						lv_obj_add_flag(guider_ui.right_line28, LV_OBJ_FLAG_HIDDEN);
						lv_obj_add_flag(guider_ui.right_line27, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 19 :
						lv_obj_add_flag(guider_ui.right_line26, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 20 :
						lv_obj_add_flag(guider_ui.right_line25, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 21 :
						lv_obj_add_flag(guider_ui.right_line24, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 22 :
						lv_obj_add_flag(guider_ui.right_line23, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 23 :
						lv_obj_add_flag(guider_ui.right_line22, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 24 :
						lv_obj_add_flag(guider_ui.right_line21, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 25 :
						lv_obj_add_flag(guider_ui.right_line20, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 26 :
						lv_obj_add_flag(guider_ui.right_line19, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 27 :
						lv_obj_add_flag(guider_ui.right_line18, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 28 :
						lv_obj_add_flag(guider_ui.right_line17, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 29 :
						lv_obj_add_flag(guider_ui.right_line16, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 30 :
						lv_obj_add_flag(guider_ui.right_line15, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 31 :
						lv_obj_add_flag(guider_ui.right_line14, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 32 :
						lv_obj_add_flag(guider_ui.right_line13, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 33 :
						lv_obj_add_flag(guider_ui.right_line12, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 34 :
						lv_obj_add_flag(guider_ui.right_line11, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 35 :
						lv_obj_add_flag(guider_ui.right_line10, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 36 :
						lv_obj_add_flag(guider_ui.right_line9, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 37 :
						lv_obj_add_flag(guider_ui.right_line8, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 38 :
						lv_obj_add_flag(guider_ui.right_line7, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 39 :
						lv_obj_add_flag(guider_ui.right_line6, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 40 :
						lv_obj_add_flag(guider_ui.right_line5, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 41 :
						lv_obj_add_flag(guider_ui.right_line4, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 42 :
						lv_obj_add_flag(guider_ui.right_line3, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 43 :
						lv_obj_add_flag(guider_ui.right_line2, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;
						break;
					case 44 :
						lv_obj_add_flag(guider_ui.right_line1, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_backward_switch_case++;

						right_draw_line_1_draw_backward_switch_case=0;
						right_draw_line_1_draw_backward_switch = 0;
						right_draw_line_1_draw_forward_switch = 1;
						right_draw_line_1_draw_forward_switch_case = 0;
						break;
					default:
						break;
					}

				}
				else if (right_draw_line_1_draw_forward_switch)
				{
					switch (right_draw_line_1_draw_forward_switch_case)
					{
					case 0 :
						lv_obj_clear_flag(guider_ui.right_line1, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 1 :
						lv_obj_clear_flag(guider_ui.right_line2, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 2 :
						lv_obj_clear_flag(guider_ui.right_line3, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 3 :
						lv_obj_clear_flag(guider_ui.right_line4, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 4 :
						lv_obj_clear_flag(guider_ui.right_line5, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 5 :
						lv_obj_clear_flag(guider_ui.right_line6, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 6 :
						lv_obj_clear_flag(guider_ui.right_line7, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 7 :
						lv_obj_clear_flag(guider_ui.right_line8, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 8 :
						lv_obj_clear_flag(guider_ui.right_line9, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 9 :
						lv_obj_clear_flag(guider_ui.right_line10, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 10 :
						lv_obj_clear_flag(guider_ui.right_line11, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 11 :
						lv_obj_clear_flag(guider_ui.right_line12, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 12 :
						lv_obj_clear_flag(guider_ui.right_line13, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 13 :
						lv_obj_clear_flag(guider_ui.right_line14, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 14 :
						lv_obj_clear_flag(guider_ui.right_line15, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 15 :
						lv_obj_clear_flag(guider_ui.right_line16, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 16 :
						lv_obj_clear_flag(guider_ui.right_line17, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 17 :
						lv_obj_clear_flag(guider_ui.right_line18, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 18 :
						lv_obj_clear_flag(guider_ui.right_line19, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 19 :
						lv_obj_clear_flag(guider_ui.right_line20, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 20 :
						lv_obj_clear_flag(guider_ui.right_line21, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 21 :
						lv_obj_clear_flag(guider_ui.right_line22, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 22 :
						lv_obj_clear_flag(guider_ui.right_line23, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 23 :
						lv_obj_clear_flag(guider_ui.right_line24, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 24 :
						lv_obj_clear_flag(guider_ui.right_line25, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 25 :
						lv_obj_clear_flag(guider_ui.right_line26, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 26 :
						lv_obj_clear_flag(guider_ui.right_line27, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line28, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 27 :
						lv_obj_clear_flag(guider_ui.right_line29, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line30, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 28 :
						lv_obj_clear_flag(guider_ui.right_line31, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line32, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 29 :
						lv_obj_clear_flag(guider_ui.right_line33, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line34, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 30 :
						lv_obj_clear_flag(guider_ui.right_line35, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line36, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 31 :
						lv_obj_clear_flag(guider_ui.right_line37, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line38, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 32 :
						lv_obj_clear_flag(guider_ui.right_line39, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line40, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 33 :
						lv_obj_clear_flag(guider_ui.right_line41, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line42, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 34 :
						lv_obj_clear_flag(guider_ui.right_line43, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line44, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 35 :
						lv_obj_clear_flag(guider_ui.right_line45, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line46, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 36 :
						lv_obj_clear_flag(guider_ui.right_line47, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line48, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 37 :
						lv_obj_clear_flag(guider_ui.right_line49, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line50, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 38 :
						lv_obj_clear_flag(guider_ui.right_line51, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line52, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 39 :
						lv_obj_clear_flag(guider_ui.right_line53, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line54, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 40 :
						lv_obj_clear_flag(guider_ui.right_line55, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line56, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 41 :
						lv_obj_clear_flag(guider_ui.right_line57, LV_OBJ_FLAG_HIDDEN);
						lv_obj_clear_flag(guider_ui.right_line58, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 42 :
						lv_obj_clear_flag(guider_ui.right_line59, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 43 :
						lv_obj_clear_flag(guider_ui.right_line60, LV_OBJ_FLAG_HIDDEN);
						right_draw_line_1_draw_forward_switch_case++;
						break;
					case 44 :
						lv_obj_clear_flag(guider_ui.right_line61, LV_OBJ_FLAG_HIDDEN);
						//right_draw_line_1_draw_forward_switch_case++;
						right_draw_line_1_draw_forward_switch_case = 0;
						right_draw_line_1_draw_forward_switch = 0;
						right_draw_line_1_draw_backward_switch = 1;
						right_draw_line_1_draw_backward_switch_case = 0;
						break;
						break;
//					case 45 :
//						lv_obj_clear_flag(guider_ui.right_line62, LV_OBJ_FLAG_HIDDEN);
//						right_draw_line_1_draw_forward_switch_case++;
//						break;
//					case 46 :
//						lv_obj_clear_flag(guider_ui.right_line63, LV_OBJ_FLAG_HIDDEN);
//
//						right_draw_line_1_draw_forward_switch_case = 0;
//						right_draw_line_1_draw_forward_switch = 0;
//						right_draw_line_1_draw_backward_switch = 1;
//						right_draw_line_1_draw_backward_switch_case = 0;
//						break;
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

		if(right_line_1_start_timer)
		{
			right_drawing_screen = 0;
			right_drawing_screen_inc_enable = 1;

			right_line_1_start_timer_exp = 0;
			right_line_1_start_timer = 0;
		}
		// 35 msec : keep calling : lv_task_handler()
		if (right_drawing_screen >= 5)  // Minimum : delay for 10 msec --> i.e animation time --> till that time call --> lv_task_handler()
		{
			right_line_1_start_timer_exp = 1;
			right_drawing_screen_inc_enable = 0;
			right_line_1_start_timer = 1;

		}


	//	lv_task_handler();  // Update the display

	}

}
