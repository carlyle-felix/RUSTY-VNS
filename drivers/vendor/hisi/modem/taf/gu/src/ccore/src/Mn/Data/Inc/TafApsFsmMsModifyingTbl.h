/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : TafApsFsmMsModifyingTbl.h
  版 本 号   : 初稿
  作    者   : s62952
  生成日期   : 2011年12月16日
  最近修改   :
  功能描述   : TafApsFsmMsModifying.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2011年12月16日
    作    者   : s62952
    修改内容   : 创建文件

******************************************************************************/

#ifndef __TAFAPSFSMMSMODIFYINGTBL_H__
#define __TAFAPSFSMMSMODIFYINGTBL_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"
#include  "TafFsm.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
extern TAF_STA_STRU                             g_astTafApsMsModifyingStaTbl[];
#define TAF_APS_GetMsModifyingStaTbl()          (g_astTafApsMsModifyingStaTbl)


/*****************************************************************************
  3 枚举定义
*****************************************************************************/
/*****************************************************************************
 枚举名    : TAF_APS_MS_MODIFYING_SUBSTA_ENUM_UINT32
 枚举说明  : MS MODIFYING主状态下子状态枚举定义
 1.日    期   : 2011年12月15日
   作    者   : h44270
   修改内容   : 新建

*****************************************************************************/
enum TAF_APS_MS_MODIFYING_SUBSTA_ENUM
{
    TAF_APS_MS_MODIFYING_SUBSTA_INIT,                                           /* MS MODIFYIN状态机的初始状态 */
    TAF_APS_MS_MODIFYING_SUBSTA_SUSPEND,                                        /* MS MODIFYIN状态机的挂起状态 */
    TAF_APS_MS_MODIFYING_SUBSTA_WAIT_SM_MODIFY_CNF,                             /* APS向SM发起了PDP修改请求，等待SM响应 */
    TAF_APS_MS_MODIFYING_SUBSTA_WAIT_SM_MODIFY_CNF_SUSPEND,                     /* APS向SM发起了PDP修改请求，等待SM响应时被挂起 */
    TAF_APS_MS_MODIFYING_SUBSTA_WAIT_SNDCP_MODIFY_RSP,                          /* APS向SNDCP发起修改SNDCP指示，等待SNDCP响应 */
    TAF_APS_MS_MODIFYING_SUBSTA_WAIT_SNDCP_MODIFY_RSP_SUSPEND,                  /* APS向SNDCP发起修改SNDCP指示，等待SNDCP响应时被挂起 */
#if (FEATURE_ON == FEATURE_LTE)
    TAF_APS_MS_MODIFYING_SUBSTA_WAIT_ESM_MODIFY_CNF,                            /* APS向ESM发起了PDP修改请求，等待ESM响应 */
    TAF_APS_MS_MODIFYING_SUBSTA_WAIT_ESM_MODIFY_CNF_SUSPEND,                    /* APS向ESM发起了PDP修改请求，等待ESM响应时被挂起 */
#endif
    TAF_APS_MS_MODIFYING_SUBSTA_BUTT
} ;
typedef VOS_UINT32 TAF_APS_MS_MODIFYING_SUBSTA_ENUM_UINT32;


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
VOS_UINT32 TAF_APS_GetMsModifyingStaTblSize( VOS_VOID );
TAF_FSM_DESC_STRU * TAF_APS_GetMsModifyingFsmDescAddr( VOS_VOID );




#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of TafApsFsmMsModifying.h */
