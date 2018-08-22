#include "AFCEX.h"
int adp_CssHeader_t(ADP* adp,CssHeader_t* value)
{
  if(!adp_uint32_t(adp,&(value->MsgLen),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00001;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Sender,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00002;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->Time,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00003;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->Ver),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00004;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->MSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00005;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranSeq),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00006;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CRC),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00007;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DevList_t(ADP* adp,DevList_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00008;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DevIP),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00009;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StationList_t(ADP* adp,StationList_t* value)
{
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DevRange_t(ADP* adp,DevRange_t* value)
{
  if(!adp_uint8_t(adp,&(value->Type),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000B;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DevType,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000C;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->StationList_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000D;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->StationList),(unsigned int)(value->StationList_Cnt),~0,sizeof(StationList_t),(adpproc_t)adp_StationList_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000E;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->DevList_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000F;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->DevList),(unsigned int)(value->DevList_Cnt),~0,sizeof(DevList_t),(adpproc_t)adp_DevList_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00010;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FileSeqList_t(ADP* adp,FileSeqList_t* value)
{
  if(!adp_uint16_t(adp,&(value->FileSeq),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00011;
      return ADP_FALSE;
  }
  if(!adp_DevRange_t(adp,&(value->DevRange)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00012;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TranRange_t(ADP* adp,TranRange_t* value)
{
  if(!adp_uint32_t(adp,&(value->TranBegin),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00013;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranEnd),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00014;
      return ADP_FALSE;
  }
  if(!adp_DevRange_t(adp,&(value->DevRange)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00015;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaInfo_t(ADP* adp,ParaInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->ParaType,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00016;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->ParaVerType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00017;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ParaVer,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00018;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ParaActiveTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00019;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ParaFile,40))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001A;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->Result),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaList_t(ADP* adp,ParaList_t* value)
{
  if(!adp_fixstring_t(adp,value->ParaType,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StatusInfo_t(ADP* adp,StatusInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->StatusID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001D;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StatusValue,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LoginReq_t(ADP* adp,LoginReq_t* value)
{
  if(!adp_fixstring_t(adp,value->DevID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001F;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00020;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->PassWd,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00021;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LoginNotice_t(ADP* adp,LoginNotice_t* value)
{
  if(!adp_fixstring_t(adp,value->DevID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00022;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00023;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->LoginType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00024;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PassWdInfo_t(ADP* adp,PassWdInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00025;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->PassWdOld,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00026;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->PassWdNew,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00027;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ModOperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00028;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LoginCtl_t(ADP* adp,LoginCtl_t* value)
{
  if(!adp_uint16_t(adp,&(value->Value),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00029;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002A;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Source,1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002B;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002C;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DevID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002D;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->RecvOperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_OperLock_t(ADP* adp,OperLock_t* value)
{
  if(!adp_uint16_t(adp,&(value->Value),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002F;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00030;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Source,1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00031;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00032;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->RecvOperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00033;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LoginResult_t(ADP* adp,LoginResult_t* value)
{
  if(!adp_fixstring_t(adp,value->DevID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00034;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00035;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->Result),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00036;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ModeInfo_t(ADP* adp,ModeInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->ModeSetters,1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00037;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00038;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00039;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->Code),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003A;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->Time,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003B;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->CodeOri),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ModeQuery_t(ADP* adp,ModeQuery_t* value)
{
  if(!adp_uint16_t(adp,&(value->StationList_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003D;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->StationList),(unsigned int)(value->StationList_Cnt),~0,sizeof(StationList_t),(adpproc_t)adp_StationList_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ModeNotice_t(ADP* adp,ModeNotice_t* value)
{
  if(!adp_uint8_t(adp,&(value->Type),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003F;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->ModeInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00040;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->ModeInfo),(unsigned int)(value->ModeInfo_Cnt),~0,sizeof(ModeInfo_t),(adpproc_t)adp_ModeInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00041;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaPublish_t(ADP* adp,ParaPublish_t* value)
{
  if(!adp_uint8_t(adp,&(value->Type),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00042;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->ParaList_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00043;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->ParaList_val),(unsigned int)(value->ParaList_Cnt),~0,sizeof(ParaList_t),(adpproc_t)adp_ParaList_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00044;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaSync_t(ADP* adp,ParaSync_t* value)
{
  if(!adp_fixstring_t(adp,value->DevID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00045;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->Type),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00046;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->ParaInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00047;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->ParaInfo_val),(unsigned int)(value->ParaInfo_Cnt),~0,sizeof(ParaInfo_t),(adpproc_t)adp_ParaInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00048;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaReport_t(ADP* adp,ParaReport_t* value)
{
  if(!adp_fixstring_t(adp,value->DevID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00049;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->Type),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004A;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->ParaInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004B;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->ParaInfo_val),(unsigned int)(value->ParaInfo_Cnt),~0,sizeof(ParaInfo_t),(adpproc_t)adp_ParaInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PartParaInfo_t(ADP* adp,PartParaInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->PartID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004D;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->PartMainVer,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004E;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->PartSubVer,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PartParaReport_t(ADP* adp,PartParaReport_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00050;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->PartParaInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00051;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PartParaInfo_val),(unsigned int)(value->PartParaInfo_Cnt),~0,sizeof(PartParaInfo_t),(adpproc_t)adp_PartParaInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00052;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TPUPara_t(ADP* adp,TPUPara_t* value)
{
  if(!adp_fixstring_t(adp,value->ParaType,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00053;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ParaVer,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00054;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TPUParaInfo_t(ADP* adp,TPUParaInfo_t* value)
{
  if(!adp_uint8_t(adp,&(value->CardReaderID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00055;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TPUPara_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00056;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TPUPara_val),(unsigned int)(value->TPUPara_Cnt),~0,sizeof(TPUPara_t),(adpproc_t)adp_TPUPara_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00057;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TPUParaReport_t(ADP* adp,TPUParaReport_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00058;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TPUParaInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00059;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TPUParaInfo_val),(unsigned int)(value->TPUParaInfo_Cnt),~0,sizeof(TPUParaInfo_t),(adpproc_t)adp_TPUParaInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PSAMCardInfo_t(ADP* adp,PSAMCardInfo_t* value)
{
  if(!adp_uint8_t(adp,&(value->SlotNum),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005B;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OLD_PSAMCardNO,12))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005C;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->OLD_PSAMType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005D;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->NEW_PSAMCardNO,12))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005E;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->NEW_PSAMType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CRWInfo_t(ADP* adp,CRWInfo_t* value)
{
  if(!adp_uint8_t(adp,&(value->ReaderLoc),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00060;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->OLD_CRWNO),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00061;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->NEW_CRWNO),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00062;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->PSAMCardInfo_len),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00063;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PSAMCardInfo_val),(unsigned int)(value->PSAMCardInfo_len),~0,sizeof(PSAMCardInfo_t),(adpproc_t)adp_PSAMCardInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00064;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SAMCardInfoReport_t(ADP* adp,SAMCardInfoReport_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00065;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Station,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00066;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->CRWInfo_len),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00067;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->CRWInfo_val),(unsigned int)(value->CRWInfo_len),~0,sizeof(CRWInfo_t),(adpproc_t)adp_CRWInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00068;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FileVerify_t(ADP* adp,FileVerify_t* value)
{
  if(!adp_uint16_t(adp,&(value->FileType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00069;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->FileName,50))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006A;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->Result),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FileNotice_t(ADP* adp,FileNotice_t* value)
{
  if(!adp_uint16_t(adp,&(value->FileType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006C;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->FileName,50))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006D;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->MD5,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DataImport_t(ADP* adp,DataImport_t* value)
{
  if(!adp_uint8_t(adp,&(value->ImportType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006F;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ImportPath,128))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00070;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FileSpecify_t(ADP* adp,FileSpecify_t* value)
{
  if(!adp_uint8_t(adp,&(value->Type),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00071;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->FileType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00072;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->TranDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00073;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->FileSeqList_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00074;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->FileSeqList),(unsigned int)(value->FileSeqList_Cnt),~0,sizeof(FileSeqList_t),(adpproc_t)adp_FileSeqList_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00075;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TranSpecify_t(ADP* adp,TranSpecify_t* value)
{
  if(!adp_uint16_t(adp,&(value->FileType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00076;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->TranDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00077;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TranRange_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00078;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TranRange),(unsigned int)(value->TranRange_Cnt),~0,sizeof(TranRange_t),(adpproc_t)adp_TranRange_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00079;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DevRunCfg_t(ADP* adp,DevRunCfg_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007A;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->DeviceType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007B;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->DeviceSubType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007C;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->LineID,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007D;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007E;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->Code),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007F;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->FtpServerIP,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00080;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->FtpUser,32))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00081;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->FtpPasswd,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00082;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->Run24Hour),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00083;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->RunExtend),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00084;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LinkLive_t(ADP* adp,LinkLive_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00085;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DevStatus_t(ADP* adp,DevStatus_t* value)
{
  if(!adp_uint16_t(adp,&(value->StatusType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00086;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->StatusInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00087;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->StatusInfo_val),(unsigned int)(value->StatusInfo_Cnt),~0,sizeof(StatusInfo_t),(adpproc_t)adp_StatusInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00088;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BoxInfo_t(ADP* adp,BoxInfo_t* value)
{
  if(!adp_uint8_t(adp,&(value->BoxType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00089;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->LocationID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008A;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->BoxID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CashTickCode),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008C;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008D;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Amt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BoxReport_t(ADP* adp,BoxReport_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008F;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->BoxInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00090;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->BoxInfo_val),(unsigned int)(value->BoxInfo_Cnt),~0,sizeof(BoxInfo_t),(adpproc_t)adp_BoxInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00091;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DevCmd_t(ADP* adp,DevCmd_t* value)
{
  if(!adp_uint16_t(adp,&(value->Code),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00092;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->Value),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00093;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Source,1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00094;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00095;
      return ADP_FALSE;
  }
  if(!adp_DevRange_t(adp,&(value->DevRange)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00096;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SaleLimit_t(ADP* adp,SaleLimit_t* value)
{
  if(!adp_uint16_t(adp,&(value->Value),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00097;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Source,1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00098;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00099;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009A;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->StartTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009B;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->EndTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009C;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->StationList_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009D;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->StationList),(unsigned int)(value->StationList_Cnt),~0,sizeof(StationList_t),(adpproc_t)adp_StationList_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DataUploadRecordsC_t(ADP* adp,DataUploadRecordsC_t* value)
{
  if(!adp_uint16_t(adp,&(value->FileType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Total),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A0;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Sended),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A1;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DataUploadRecords_t(ADP* adp,DataUploadRecords_t* value)
{
  if(!adp_uint16_t(adp,&(value->records_len),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A2;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->DataUploadRecordsC_val),(unsigned int)(value->records_len),~0,sizeof(DataUploadRecordsC_t),(adpproc_t)adp_DataUploadRecordsC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A3;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Event_t(ADP* adp,Event_t* value)
{
  if(!adp_uint16_t(adp,&(value->Code),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A4;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Value,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashStock_t(ADP* adp,CashStock_t* value)
{
  if(!adp_uint8_t(adp,&(value->CurrencyCode),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A6;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CurrencyNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A7;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ReserveMax),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A8;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Reserve),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A9;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Income),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AA;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DeliveRing),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AB;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TvmReserveOut),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BomReserveOut),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AD;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashReport_t(ADP* adp,CashReport_t* value)
{
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AE;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->DataType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AF;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B0;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B1;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->CashStock_val),(unsigned int)(value->Count),~0,sizeof(CashStock_t),(adpproc_t)adp_CashStock_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B2;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CurrencyCode_t(ADP* adp,CurrencyCode_t* value)
{
  if(!adp_uint8_t(adp,&(value->CurrencyCode),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B3;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashQuery_t(ADP* adp,CashQuery_t* value)
{
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B4;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B5;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B6;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B7;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->CurrencyCode_val),(unsigned int)(value->Count),~0,sizeof(CurrencyCode_t),(adpproc_t)adp_CurrencyCode_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B8;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashLackInfo_t(ADP* adp,CashLackInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B9;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ReportID,32))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BA;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DocumentID,32))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BB;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->DocumentStatus),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ShorageAmt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BD;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->ErrorType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BE;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ErrorOperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BF;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ErrorDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C0;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->RepenishmentDeadline,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C1;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShortStartDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C2;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShortEndDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C3;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ErrorReason,200))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C4;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ErrorInstruction,200))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashLack_t(ADP* adp,CashLack_t* value)
{
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C6;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->AuditDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C7;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperDateTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C8;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->AuditOperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C9;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CA;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->CashLackInfo_val),(unsigned int)(value->Count),~0,sizeof(CashLackInfo_t),(adpproc_t)adp_CashLackInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CB;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashReplenishInfo_t(ADP* adp,CashReplenishInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->DocumentID,32))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CC;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ReplenishmentID,32))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CD;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->ErrorOperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CE;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->AuditOperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CF;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ReplenishmentAmt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D0;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashReplenish_t(ADP* adp,CashReplenish_t* value)
{
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D1;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ReplenishmentDateTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D2;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D3;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->CashReplenishInfo_val),(unsigned int)(value->Count),~0,sizeof(CashReplenishInfo_t),(adpproc_t)adp_CashReplenishInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D4;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SpareCashBringReturn_t(ADP* adp,SpareCashBringReturn_t* value)
{
  if(!adp_uint8_t(adp,&(value->OperType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D5;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D6;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->LastBalancesAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D7;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->OperationAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D8;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BalancesAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D9;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashBomIncome_t(ADP* adp,CashBomIncome_t* value)
{
  if(!adp_fixstring_t(adp,value->LineID,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DA;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DB;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DC;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DD;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->RunDate,8))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DE;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CaculateAmt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DF;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->RealAmt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E0;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,128))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E1;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickStock_t(ADP* adp,TickStock_t* value)
{
  if(!adp_uint32_t(adp,&(value->StoreID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E2;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->TickAreaID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E3;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TickManaType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E4;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->StatusFlag),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E5;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->IssuerID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E6;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Price),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E7;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->Validate,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E8;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->StoreNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E9;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EA;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickReport_t(ADP* adp,TickReport_t* value)
{
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EB;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->DataType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000ED;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickStock_val),(unsigned int)(value->Count),~0,sizeof(TickStock_t),(adpproc_t)adp_TickStock_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EE;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickReqC_t(ADP* adp,TickReqC_t* value)
{
  if(!adp_uint16_t(adp,&(value->TickManaType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EF;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->TickStatus),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F0;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ValidateDate,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F1;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F2;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Price),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F3;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->MediaType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F4;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->StroeID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F5;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->TickAreaID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F6;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F7;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickReq_t(ADP* adp,TickReq_t* value)
{
  if(!adp_fixstring_t(adp,value->DispatchNO,40))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F8;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->DispatchType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F9;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ApplyTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FA;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DispatchIn,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FB;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DispatchOut,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FC;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ExpectTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FD;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FE;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,128))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FF;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00100;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickReqC_val),(unsigned int)(value->Count),~0,sizeof(TickReqC_t),(adpproc_t)adp_TickReqC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00101;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickRespC_t(ADP* adp,TickRespC_t* value)
{
  if(!adp_uint16_t(adp,&(value->TickManaType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00102;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->TickStatus),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00103;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ValidateDate,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00104;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00105;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DispacthNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00106;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Price),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00107;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->MediaType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00108;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->StroeID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00109;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->TickAreaID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010A;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickResp_t(ADP* adp,TickResp_t* value)
{
  if(!adp_fixstring_t(adp,value->DispatchNO,40))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010C;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->AssociateNO,40))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010D;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->DispatchType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010E;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ApplyTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010F;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DispatchIn,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00110;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DispatchOut,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00111;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ExpectTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00112;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->DispatchTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00113;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00114;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,128))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00115;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00116;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickRespC_val),(unsigned int)(value->Count),~0,sizeof(TickRespC_t),(adpproc_t)adp_TickRespC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00117;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickDetailC_t(ADP* adp,TickDetailC_t* value)
{
  if(!adp_uint32_t(adp,&(value->StroeID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00118;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->TickAreaID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00119;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TickManaType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011A;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->MediaType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011B;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->InventoryStatus),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011C;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->BatchNo,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011D;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ValidateDate,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ValidNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->InvalidNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00120;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00121;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Price),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00122;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00123;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickDetail_t(ADP* adp,TickDetail_t* value)
{
  if(!adp_fixstring_t(adp,value->DispatchNO,40))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00124;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->OperType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00125;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00126;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->SourceID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00127;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DestID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00128;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00129;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,128))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012B;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickDetailC_val),(unsigned int)(value->Count),~0,sizeof(TickDetailC_t),(adpproc_t)adp_TickDetailC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickCheckC_t(ADP* adp,TickCheckC_t* value)
{
  if(!adp_uint32_t(adp,&(value->StroeID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012D;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->TickAreaID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012E;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TickManaType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickPrice),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00130;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->SysNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00131;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->RealNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00132;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->InvalidSysNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00133;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->InvalidRealNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00134;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickCheck_t(ADP* adp,TickCheck_t* value)
{
  if(!adp_fixstring_t(adp,value->DispatchNO,40))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00135;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00136;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->OperType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00137;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00138;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00139;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,128))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013B;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickCheckC_val),(unsigned int)(value->Count),~0,sizeof(TickCheckC_t),(adpproc_t)adp_TickCheckC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickQueryC_t(ADP* adp,TickQueryC_t* value)
{
  if(!adp_uint16_t(adp,&(value->TickManaType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickQuery_t(ADP* adp,TickQuery_t* value)
{
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013E;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DevicdID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013F;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00140;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00141;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickQueryC_val),(unsigned int)(value->Count),~0,sizeof(TickQueryC_t),(adpproc_t)adp_TickQueryC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00142;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CssBody_t(ADP* adp,CssBody_t* value)
{
  if(!adp_uint16_t(adp,&(value->MsgType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00143;
      return ADP_FALSE;
  }
  switch(value->MsgType)
  {
    case 0X0101:
      if (!adp_LoginReq_t(adp,&(value->body_u.LoginReq0101)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00144;
          return ADP_FALSE;
      }
      break;
    case 0X0102:
      if (!adp_LoginNotice_t(adp,&(value->body_u.LoginNotice0102)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00145;
          return ADP_FALSE;
      }
      break;
    case 0X0103:
      if (!adp_PassWdInfo_t(adp,&(value->body_u.PassWdInfo0103)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00146;
          return ADP_FALSE;
      }
      break;
    case 0X0104:
      if (!adp_LoginCtl_t(adp,&(value->body_u.LoginCtl0104)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00147;
          return ADP_FALSE;
      }
      break;
    case 0X0105:
      if (!adp_OperLock_t(adp,&(value->body_u.OperLock0105)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00148;
          return ADP_FALSE;
      }
      break;
    case 0X0111:
      if (!adp_LoginResult_t(adp,&(value->body_u.LoginResult0111)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00149;
          return ADP_FALSE;
      }
      break;
    case 0X0201:
      if (!adp_ParaPublish_t(adp,&(value->body_u.ParaPublish0201)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0014A;
          return ADP_FALSE;
      }
      break;
    case 0X0202:
      if (!adp_ParaSync_t(adp,&(value->body_u.ParaSync0202)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0014B;
          return ADP_FALSE;
      }
      break;
    case 0X0204:
      if (!adp_ParaReport_t(adp,&(value->body_u.ParaReport0204)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0014C;
          return ADP_FALSE;
      }
      break;
    case 0x0205:
      if (!adp_PartParaReport_t(adp,&(value->body_u.PartParaReport0205)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0014D;
          return ADP_FALSE;
      }
      break;
    case 0x0206:
      if (!adp_TPUParaReport_t(adp,&(value->body_u.TPUParaReport0206)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0014E;
          return ADP_FALSE;
      }
      break;
    case 0x0207:
      if (!adp_SAMCardInfoReport_t(adp,&(value->body_u.SAMCardInfoReport0207)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0014F;
          return ADP_FALSE;
      }
      break;
    case 0X0406:
      if (!adp_FileVerify_t(adp,&(value->body_u.FileVerify0406)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00150;
          return ADP_FALSE;
      }
      break;
    case 0X0411:
      if (!adp_FileNotice_t(adp,&(value->body_u.FileNotice0411)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00151;
          return ADP_FALSE;
      }
      break;
    case 0X0412:
      if(!adp_uint16_t(adp,&(value->body_u.FileType),2,BO_MOTO))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00152;
          return ADP_FALSE;
      }
      break;
    case 0X0421:
      if (!adp_DataImport_t(adp,&(value->body_u.DataImport0421)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00153;
          return ADP_FALSE;
      }
      break;
    case 0X0422:
      if (!adp_FileSpecify_t(adp,&(value->body_u.FileSpecify0422)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00154;
          return ADP_FALSE;
      }
      break;
    case 0X0423:
      if (!adp_TranSpecify_t(adp,&(value->body_u.TranSpecify0423)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00155;
          return ADP_FALSE;
      }
      break;
    case 0x0601:
      if (!adp_DevRunCfg_t(adp,&(value->body_u.DevRunCfg0601)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00156;
          return ADP_FALSE;
      }
      break;
    case 0x0602:
      if (!adp_LinkLive_t(adp,&(value->body_u.LinkLive0602)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00157;
          return ADP_FALSE;
      }
      break;
    case 0x0604:
      if (!adp_DevStatus_t(adp,&(value->body_u.DevStatus0604)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00158;
          return ADP_FALSE;
      }
      break;
    case 0x0605:
      if (!adp_BoxReport_t(adp,&(value->body_u.BoxReport0605)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00159;
          return ADP_FALSE;
      }
      break;
    case 0x0606:
      if (!adp_DevCmd_t(adp,&(value->body_u.DevCmd0606)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0015A;
          return ADP_FALSE;
      }
      break;
    case 0x0607:
      if (!adp_SaleLimit_t(adp,&(value->body_u.SaleLimit0607)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0015B;
          return ADP_FALSE;
      }
      break;
    case 0x0608:
      if (!adp_DataUploadRecords_t(adp,&(value->body_u.DataUploadRecords0608)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0015C;
          return ADP_FALSE;
      }
      break;
    case 0x0701:
      if (!adp_ModeNotice_t(adp,&(value->body_u.ModeNotice0701)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0015D;
          return ADP_FALSE;
      }
      break;
    case 0x0702:
      if (!adp_ModeInfo_t(adp,&(value->body_u.ModeInfo0702)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0015E;
          return ADP_FALSE;
      }
      break;
    case 0x0703:
      if (!adp_ModeQuery_t(adp,&(value->body_u.ModeQuery0703)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0015F;
          return ADP_FALSE;
      }
      break;
    case 0x0801:
      if (!adp_Event_t(adp,&(value->body_u.Event0801)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00160;
          return ADP_FALSE;
      }
      break;
    case 0x1101:
      if (!adp_CashReport_t(adp,&(value->body_u.CashReport1101)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00161;
          return ADP_FALSE;
      }
      break;
    case 0x1102:
      if (!adp_CashQuery_t(adp,&(value->body_u.CashQuery1102)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00162;
          return ADP_FALSE;
      }
      break;
    case 0x1103:
      if (!adp_CashLack_t(adp,&(value->body_u.CashLack1103)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00163;
          return ADP_FALSE;
      }
      break;
    case 0x1104:
      if (!adp_CashReplenish_t(adp,&(value->body_u.CashReplenish1104)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00164;
          return ADP_FALSE;
      }
      break;
    case 0x1105:
      if (!adp_CashBomIncome_t(adp,&(value->body_u.CashBomIncome1105)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00165;
          return ADP_FALSE;
      }
      break;
    case 0x1106:
      if (!adp_SpareCashBringReturn_t(adp,&(value->body_u.SpareCashBringReturn1106)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00166;
          return ADP_FALSE;
      }
      break;
    case 0x1501:
      if (!adp_TickReport_t(adp,&(value->body_u.TickReport1501)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00167;
          return ADP_FALSE;
      }
      break;
    case 0x1503:
      if (!adp_TickReq_t(adp,&(value->body_u.TickReq1503)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00168;
          return ADP_FALSE;
      }
      break;
    case 0x1504:
      if (!adp_TickResp_t(adp,&(value->body_u.TickResp1504)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00169;
          return ADP_FALSE;
      }
      break;
    case 0x1505:
      if (!adp_TickDetail_t(adp,&(value->body_u.TickDetail1505)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0016A;
          return ADP_FALSE;
      }
      break;
    case 0x1506:
      if (!adp_TickCheck_t(adp,&(value->body_u.TickCheck1506)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0016B;
          return ADP_FALSE;
      }
      break;
    case 0x1507:
      if (!adp_TickQuery_t(adp,&(value->body_u.TickQuery1507)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0016C;
          return ADP_FALSE;
      }
      break;
    case 0x1523:
      if (!adp_TickReq_t(adp,&(value->body_u.TickReq1523)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0016D;
          return ADP_FALSE;
      }
      break;
    case 0x1524:
      if (!adp_TickResp_t(adp,&(value->body_u.TickResp1524)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0016E;
          return ADP_FALSE;
      }
      break;
    case 0x1525:
      if (!adp_TickDetail_t(adp,&(value->body_u.TickDetail1525)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0016F;
          return ADP_FALSE;
      }
      break;
  }
  return ADP_TRUE;
}

int adp_Css_t(ADP* adp,Css_t* value)
{
  if(!adp_CssHeader_t(adp,&(value->CssHeader)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00170;
      return ADP_FALSE;
  }
  if(!adp_CssBody_t(adp,&(value->CssBody)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00171;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->MD5,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00172;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketSaleC_t(ADP* adp,TicketSaleC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00173;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickSaleNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00174;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickSaleAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00175;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketRechargeC_t(ADP* adp,TicketRechargeC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00176;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRechargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00177;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRechargeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00178;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketUpdateC_t(ADP* adp,TicketUpdateC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00179;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->TickUpdateReason,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017A;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->TickPayType,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickUpdateNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017C;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickUpdateAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_AffairDealC_t(ADP* adp,AffairDealC_t* value)
{
  if(!adp_uint32_t(adp,&(value->AffairCode),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017E;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->AffairNum),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->AffairAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00180;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketDelayC_t(ADP* adp,TicketDelayC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00181;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickDelayNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00182;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketRefundInsC_t(ADP* adp,TicketRefundInsC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00183;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketRefundNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00184;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRefundAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00185;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRefundDeposit),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00186;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketRefundNoInsC_t(ADP* adp,TicketRefundNoInsC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00187;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRefundNoInsNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00188;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRefundNoInsBlance),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00189;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRefundNoInsDeposit),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRefundNoInsPenalty),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketRefundNoInsApplyC_t(ADP* adp,TicketRefundNoInsApplyC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018C;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickRefundNoInsApplyNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ChongZhengC_t(ADP* adp,ChongZhengC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ChongZhengNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ChongZhengAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00190;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketUnlockC_t(ADP* adp,TicketUnlockC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00191;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickUnlockNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00192;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_GateBoxData_t(ADP* adp,GateBoxData_t* value)
{
  if(!adp_bcd_t(adp,value->DeviceID,5))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00193;
      return ADP_FALSE;
  }
  if(!adp_string_t(adp,&(value->OperatorID),6,0,0,0))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00194;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TokenBoxID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00195;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->RemoveTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00196;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->SerialNO),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00197;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->TicketType,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00198;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TicketNum),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00199;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_OperLog_t(ADP* adp,OperLog_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019A;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019B;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->Opertime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019C;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperCode,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019D;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Result,1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019E;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,300))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FaultLogC_t(ADP* adp,FaultLogC_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A0;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A1;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A2;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OccurTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A3;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->MaintainCode),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A4;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->FaultType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A5;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->FaultID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A6;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->KeyFld1,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A7;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->KeyFld2,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A8;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FaultLog_t(ADP* adp,FaultLog_t* value)
{
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A9;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->FaultLogC_val),(unsigned int)(value->Count),~0,sizeof(FaultLogC_t),(adpproc_t)adp_FaultLogC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001AA;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_AuditPacket_t(ADP* adp,AuditPacket_t* value)
{
  if(!adp_uint8_t(adp,&(value->PacketType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001AB;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->AuditSeq),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001AC;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->AuditBeginTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001AD;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->AuditEndTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001AE;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->PackageID,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001AF;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->RecordInPacket),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B0;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BeginUDSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B1;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->EndUDSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B2;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_AuditTran_t(ADP* adp,AuditTran_t* value)
{
  if(!adp_uint8_t(adp,&(value->PacketType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B3;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->AuditSeq),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B4;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->AuditBeginTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B5;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->AuditEndTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B6;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalUDNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B7;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BeginUDSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B8;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->EndUDSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B9;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_AudDataC_t(ADP* adp,AudDataC_t* value)
{
  if(!adp_fixstring_t(adp,value->TranType,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BA;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->PayMode,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BB;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->TickType,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TRXCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BD;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TRXAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BE;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_AGMAudData_t(ADP* adp,AGMAudData_t* value)
{
  if(!adp_fixstring_t(adp,value->DataType,1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BF;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperationDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C0;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C1;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->CurTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C2;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->SJTNum),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C3;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TransactionC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C4;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->AudDataC_val),(unsigned int)(value->TransactionC_len),~0,sizeof(AudDataC_t),(adpproc_t)adp_AudDataC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMAudData_t(ADP* adp,TVMAudData_t* value)
{
  if(!adp_fixstring_t(adp,value->DataType,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C6;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->OperationDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C7;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C8;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->CurTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C9;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TokenHoppers),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001CA;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->CoinHopper),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001CB;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001CC;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TokenClean),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001CD;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->CoinClean),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001CE;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinCleanAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001CF;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->CoinBoxCount),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D0;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinBoxAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D1;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->NoteBoxCount),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D2;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteBoxAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D3;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TransactionC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D4;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->AudDataC_val),(unsigned int)(value->TransactionC_len),~0,sizeof(AudDataC_t),(adpproc_t)adp_AudDataC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashOperC_t(ADP* adp,CashOperC_t* value)
{
  if(!adp_uint32_t(adp,&(value->MoneyActionType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D6;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CashType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D7;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DenominationType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D8;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickOperC_t(ADP* adp,TickOperC_t* value)
{
  if(!adp_uint32_t(adp,&(value->TicketActionType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001D9;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001DA;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CardSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001DB;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->OperResult),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001DC;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMOperAudData_t(ADP* adp,TVMOperAudData_t* value)
{
  if(!adp_fixstring_t(adp,value->TransID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001DD;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->BeginDate,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001DE;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->EndDate,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001DF;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DestinationStation,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E0;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E1;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketSubType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E2;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->PassengerType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E3;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CardType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E4;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->PaymentMethod),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E5;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CountFromPassenger),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E6;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->UnitPrice),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E7;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalPrice),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E8;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->PaymentAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001E9;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TransCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001EA;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TransAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001EB;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ChangeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001EC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->OutFailCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001ED;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->PrintVoucher),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001EE;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001EF;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->CashOperC_val),(unsigned int)(value->Count),~0,sizeof(CashOperC_t),(adpproc_t)adp_CashOperC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F0;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->OperCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F1;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickOperC_val),(unsigned int)(value->OperCount),~0,sizeof(TickOperC_t),(adpproc_t)adp_TickOperC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F2;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Currency_t(ADP* adp,Currency_t* value)
{
  if(!adp_uint8_t(adp,&(value->CurrencyCode),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F3;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->Num),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F4;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Amount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashBoxInfoC_t(ADP* adp,CashBoxInfoC_t* value)
{
  if(!adp_fixstring_t(adp,value->BoxID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F6;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->SerialNum),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F7;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->OperType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F8;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->BoxType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001F9;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->LocationID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001FA;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->InstallTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001FB;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->Time,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001FC;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->CurrencyCount),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001FD;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->Currency_val),(unsigned int)(value->CurrencyCount),~0,sizeof(Currency_t),(adpproc_t)adp_Currency_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001FE;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CashBoxChangeData_t(ADP* adp,CashBoxChangeData_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001FF;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00200;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->BoxInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00201;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->CashBoxInfoC_val),(unsigned int)(value->BoxInfo_Cnt),~0,sizeof(CashBoxInfoC_t),(adpproc_t)adp_CashBoxInfoC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00202;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickBoxInfoC_t(ADP* adp,TickBoxInfoC_t* value)
{
  if(!adp_fixstring_t(adp,value->BoxID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00203;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->SerialNum),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00204;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->OperType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00205;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->BoxType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00206;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->LocationID),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00207;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->TicketCode),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00208;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->InstallTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00209;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->Time,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0020A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Num),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0020B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickBoxChangeData_t(ADP* adp,TickBoxChangeData_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0020C;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0020D;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->BoxInfo_Cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0020E;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickBoxInfoC_val),(unsigned int)(value->BoxInfo_Cnt),~0,sizeof(TickBoxInfoC_t),(adpproc_t)adp_TickBoxInfoC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0020F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TickCashInfoC_t(ADP* adp,TickCashInfoC_t* value)
{
  if(!adp_uint8_t(adp,&(value->OperType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00210;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->BoxType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00211;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->BoxLocation),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00212;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Count),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00213;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Amount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00214;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMAutoData_t(ADP* adp,TVMAutoData_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00215;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00216;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->SettlementDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00217;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->SettlementUDSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00218;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->SettlementType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00219;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->StartTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0021A;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->EndTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0021B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CashSaleNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0021C;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CashSaleSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0021D;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->YKTSaleNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0021E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->YKTSaleSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0021F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->YKTChargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00220;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->YKTChargeSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00221;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BankCardChargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00222;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BankCardChargeSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00223;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DebitCardChargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00224;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DebitCardChargeSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00225;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CreditCardChargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00226;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CreditCardChargeSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00227;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->FaultTranNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00228;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->FaultTranSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00229;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ChargeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0022A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteAmountIn),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0022B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinAmountIn),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0022C;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteChangeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0022D;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinChangeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0022E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->InvalidCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0022F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TickCashRecord_Cnt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00230;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TickCashInfo_val),(unsigned int)(value->TickCashRecord_Cnt),~0,sizeof(TickCashInfoC_t),(adpproc_t)adp_TickCashInfoC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00231;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalBlanceAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00232;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->Rest,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00233;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMCheckout_t(ADP* adp,TVMCheckout_t* value)
{
  if(!adp_bcd_t(adp,value->SettlementDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00234;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00235;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->SettlementUDSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00236;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->SettlementType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00237;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00238;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->StartTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00239;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->EndTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0023A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CashSaleNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0023B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CashSaleSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0023C;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->YKTSaleNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0023D;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->YKTSaleSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0023E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->YKTChargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0023F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->YKTChargeSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00240;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BankCardChargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00241;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BankCardChargeSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00242;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DebitCardChargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00243;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DebitCardChargeSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00244;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CreditCardChargeNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00245;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CreditCardChargeSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00246;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->FaultTranNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00247;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->FaultTranSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00248;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteChangeBoxIn),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00249;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinChangeBoxIn),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0024A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteAcceptAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0024B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinAcceptAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0024C;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteChangeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0024D;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinChangeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0024E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->InvalidCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0024F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketBox1Amount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00250;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketBox2Amount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00251;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BalanceAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00252;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00253;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->Rest,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00254;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BOMShiftData_t(ADP* adp,BOMShiftData_t* value)
{
  if(!adp_fixstring_t(adp,value->SettlementsSN,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00255;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00256;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00257;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShiftID,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00258;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShiftSeq,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00259;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShiftStart,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0025A;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShiftEnd,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0025B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketSaleC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0025C;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TicketSaleC_val),(unsigned int)(value->TicketSaleC_len),~0,sizeof(TicketSaleC_t),(adpproc_t)adp_TicketSaleC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0025D;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalSaleAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0025E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketRechargeC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0025F;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TicketRechargeC_val),(unsigned int)(value->TicketRechargeC_len),~0,sizeof(TicketRechargeC_t),(adpproc_t)adp_TicketRechargeC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00260;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalAddAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00261;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketUpdateC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00262;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TicketUpdateC_val),(unsigned int)(value->TicketUpdateC_len),~0,sizeof(TicketUpdateC_t),(adpproc_t)adp_TicketUpdateC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00263;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->UpdateCash),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00264;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalUpdateAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00265;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->AffairDealC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00266;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->AffairDealC_val),(unsigned int)(value->AffairDealC_len),~0,sizeof(AffairDealC_t),(adpproc_t)adp_AffairDealC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00267;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->AffairRefusedAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00268;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->AffairAddAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00269;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketDelayC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0026A;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TicketDelayC_val),(unsigned int)(value->TicketDelayC_len),~0,sizeof(TicketDelayC_t),(adpproc_t)adp_TicketDelayC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0026B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketRefundInsC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0026C;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TicketRefundInsC_val),(unsigned int)(value->TicketRefundInsC_len),~0,sizeof(TicketRefundInsC_t),(adpproc_t)adp_TicketRefundInsC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0026D;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalRefundInsAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0026E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketRefundNoInsC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0026F;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TicketRefundNoInsC_val),(unsigned int)(value->TicketRefundNoInsC_len),~0,sizeof(TicketRefundNoInsC_t),(adpproc_t)adp_TicketRefundNoInsC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00270;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalRefundNoIns),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00271;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketRefundNoInsApplyC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00272;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TicketRefundNoInsApplyC_val),(unsigned int)(value->TicketRefundNoInsApplyC_len),~0,sizeof(TicketRefundNoInsApplyC_t),(adpproc_t)adp_TicketRefundNoInsApplyC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00273;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ChongZhengC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00274;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->ChongZhengC_val),(unsigned int)(value->ChongZhengC_len),~0,sizeof(ChongZhengC_t),(adpproc_t)adp_ChongZhengC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00275;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalChongZhengAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00276;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketUnlockC_len),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00277;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TicketUnlockC_val),(unsigned int)(value->TicketUnlockC_len),~0,sizeof(TicketUnlockC_t),(adpproc_t)adp_TicketUnlockC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00278;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalNoCash),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00279;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalCash),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0027A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BOMAdminData_t(ADP* adp,BOMAdminData_t* value)
{
  if(!adp_uint16_t(adp,&(value->TranType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0027B;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0027C;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0027D;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->TranTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0027E;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->TranSN,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0027F;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->FaultCertificateID,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00280;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00281;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->ProcessType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00282;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Remark,30))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00283;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->Udsn),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00284;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->ShiftSeq),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00285;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->CardID,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00286;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Rest,32))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00287;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMFaultTran_t(ADP* adp,TVMFaultTran_t* value)
{
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00288;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->FailTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00289;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->FaultCertificateID,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0028A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->UDSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0028B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->RefundmentCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0028C;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->FaultReason),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0028D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SideDoorRecord_t(ADP* adp,SideDoorRecord_t* value)
{
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0028E;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Source,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0028F;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->DateTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00290;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00291;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00292;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Type,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00293;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Reason,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00294;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Number,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00295;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->PassengerName,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00296;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->CertificateID,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00297;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->Note,30))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00298;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TransCountInfoC_t(ADP* adp,TransCountInfoC_t* value)
{
  if(!adp_uint32_t(adp,&(value->AgentID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00299;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CardIssuerID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0029A;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0029B;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0029C;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranSubType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0029D;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->PayMeansCode),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0029E;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0029F;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A0;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMBalance_t(ADP* adp,TVMBalance_t* value)
{
  if(!adp_bcd_t(adp,value->SettlementDate,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A1;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A2;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->SettlementUDSN),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A3;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->SettlementType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A4;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A5;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->StartTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A6;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->EndTime,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A7;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteChangeBoxIn),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A8;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinChangeBoxIn),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002A9;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteAcceptAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002AA;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinAcceptAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002AB;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->NoteChangeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002AC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CoinChangeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002AD;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->InvalidCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002AE;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketBox1Amount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002AF;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketBox2Amount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B0;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->FaultTranNum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B1;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->FaultTranSum),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B2;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BalanceAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B3;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TransCountInfo_Cnt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B4;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->TransCountInfoC_val),(unsigned int)(value->TransCountInfo_Cnt),~0,sizeof(TransCountInfoC_t),(adpproc_t)adp_TransCountInfoC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B5;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalNonCashCollected),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B6;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B7;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->Rest,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B8;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BomTicketSaleC_t(ADP* adp,BomTicketSaleC_t* value)
{
  if(!adp_uint32_t(adp,&(value->AgentID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002B9;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CardIssuerID),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002BA;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TicketType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002BB;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002BC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranSubType),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002BD;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->TicketOperation),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002BE;
      return ADP_FALSE;
  }
  if(!adp_uint8_t(adp,&(value->ReceiptOperation),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002BF;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->PayMeansCode),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C0;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranCount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C1;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->DepositAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C2;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TranAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C3;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->FreeAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C4;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->CostAmount),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BOMBalance_t(ADP* adp,BOMBalance_t* value)
{
  if(!adp_fixstring_t(adp,value->SettlementsSN,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C6;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->DeviceID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C7;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->OperatorID,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C8;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShiftID,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002C9;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShiftSeq,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002CA;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShiftStart,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002CB;
      return ADP_FALSE;
  }
  if(!adp_bcd_t(adp,value->ShiftEnd,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002CC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->BomTicketSale_Cnt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002CD;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->BomTicketSaleC_val),(unsigned int)(value->BomTicketSale_Cnt),~0,sizeof(BomTicketSaleC_t),(adpproc_t)adp_BomTicketSaleC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002CE;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalNonCashCollected),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002CF;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->TotalCashCollected),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002D0;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->Rest,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002D1;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjBomData_t(ADP* adp,PrjBomData_t* value)
{
  if(!adp_uint32_t(adp,&(value->temp),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002D2;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjTvmData_t(ADP* adp,PrjTvmData_t* value)
{
  if(!adp_uint32_t(adp,&(value->temp),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002D3;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjAgData_t(ADP* adp,PrjAgData_t* value)
{
  if(!adp_uint32_t(adp,&(value->temp),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002D4;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjRegData_t(ADP* adp,PrjRegData_t* value)
{
  if(!adp_uint32_t(adp,&(value->temp),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002D5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CssFile_t(ADP* adp,CssFile_t* value)
{
  if(!adp_uint16_t(adp,&(value->FileType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002D6;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->records_len),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002D7;
      return ADP_FALSE;
  }
  switch((value->FileType))
  {
    case 0x6101:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.OperLog_val),(unsigned int)(value->records_len),~0,sizeof(OperLog_t),(adpproc_t)adp_OperLog_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002D8;
          return ADP_FALSE;
      }
      break;
    case 0x6102:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.FaultLog_val),(unsigned int)(value->records_len),~0,sizeof(FaultLog_t),(adpproc_t)adp_FaultLog_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002D9;
          return ADP_FALSE;
      }
      break;
    case 0x6103:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.AuditPacket_val),(unsigned int)(value->records_len),~0,sizeof(AuditPacket_t),(adpproc_t)adp_AuditPacket_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002DA;
          return ADP_FALSE;
      }
      break;
    case 0x6104:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.AuditTran_val),(unsigned int)(value->records_len),~0,sizeof(AuditTran_t),(adpproc_t)adp_AuditTran_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002DB;
          return ADP_FALSE;
      }
      break;
    case 0x6105:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.AGMAudData_val),(unsigned int)(value->records_len),~0,sizeof(AGMAudData_t),(adpproc_t)adp_AGMAudData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002DC;
          return ADP_FALSE;
      }
      break;
    case 0x6106:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.TVMAudData_val),(unsigned int)(value->records_len),~0,sizeof(TVMAudData_t),(adpproc_t)adp_TVMAudData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002DD;
          return ADP_FALSE;
      }
      break;
    case 0x6107:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.TVMOperAudData_val),(unsigned int)(value->records_len),~0,sizeof(TVMOperAudData_t),(adpproc_t)adp_TVMOperAudData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002DE;
          return ADP_FALSE;
      }
      break;
    case 0x6108:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.CashBoxChangeData_val),(unsigned int)(value->records_len),~0,sizeof(CashBoxChangeData_t),(adpproc_t)adp_CashBoxChangeData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002DF;
          return ADP_FALSE;
      }
      break;
    case 0x6109:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.TickBoxChangeData_val),(unsigned int)(value->records_len),~0,sizeof(TickBoxChangeData_t),(adpproc_t)adp_TickBoxChangeData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E0;
          return ADP_FALSE;
      }
      break;
    case 0x7001:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.TVMAutoData_val),(unsigned int)(value->records_len),~0,sizeof(TVMAutoData_t),(adpproc_t)adp_TVMAutoData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E1;
          return ADP_FALSE;
      }
      break;
    case 0x7002:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.TVMCheckout_val),(unsigned int)(value->records_len),~0,sizeof(TVMCheckout_t),(adpproc_t)adp_TVMCheckout_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E2;
          return ADP_FALSE;
      }
      break;
    case 0x7003:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.BOMShiftData_val),(unsigned int)(value->records_len),~0,sizeof(BOMShiftData_t),(adpproc_t)adp_BOMShiftData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E3;
          return ADP_FALSE;
      }
      break;
    case 0x7004:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.BOMAdminData_val),(unsigned int)(value->records_len),~0,sizeof(BOMAdminData_t),(adpproc_t)adp_BOMAdminData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E4;
          return ADP_FALSE;
      }
      break;
    case 0x7005:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.TVMFaultTran_val),(unsigned int)(value->records_len),~0,sizeof(TVMFaultTran_t),(adpproc_t)adp_TVMFaultTran_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E5;
          return ADP_FALSE;
      }
      break;
    case 0x7006:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.SideDoorRecord_val),(unsigned int)(value->records_len),~0,sizeof(SideDoorRecord_t),(adpproc_t)adp_SideDoorRecord_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E6;
          return ADP_FALSE;
      }
      break;
    case 0x7007:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.TVMBalance_val),(unsigned int)(value->records_len),~0,sizeof(TVMBalance_t),(adpproc_t)adp_TVMBalance_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E7;
          return ADP_FALSE;
      }
      break;
    case 0x7008:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.BOMBalance_val),(unsigned int)(value->records_len),~0,sizeof(BOMBalance_t),(adpproc_t)adp_BOMBalance_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E8;
          return ADP_FALSE;
      }
      break;
    case 0x8001:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjBomData_val),(unsigned int)(value->records_len),~0,sizeof(PrjBomData_t),(adpproc_t)adp_PrjBomData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002E9;
          return ADP_FALSE;
      }
      break;
    case 0x8002:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjTvmData_val),(unsigned int)(value->records_len),~0,sizeof(PrjTvmData_t),(adpproc_t)adp_PrjTvmData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002EA;
          return ADP_FALSE;
      }
      break;
    case 0x8003:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjAgData_val),(unsigned int)(value->records_len),~0,sizeof(PrjAgData_t),(adpproc_t)adp_PrjAgData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002EB;
          return ADP_FALSE;
      }
      break;
    case 0x8005:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjRegData_val),(unsigned int)(value->records_len),~0,sizeof(PrjRegData_t),(adpproc_t)adp_PrjRegData_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x002EC;
          return ADP_FALSE;
      }
      break;
  }
  return ADP_TRUE;
}

int adp_ParaLineInfo_t(ADP* adp,ParaLineInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->LineID,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002ED;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->LineCnName,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002EE;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->LineEnName,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002EF;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaStationInfo_t(ADP* adp,ParaStationInfo_t* value)
{
  if(!adp_fixstring_t(adp,value->StationID,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F0;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->LocationNumber,10))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F1;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationCnName,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F2;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationEnName,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F3;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationType,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F4;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->Rest,32))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaA800_t(ADP* adp,ParaA800_t* value)
{
  if(!adp_fixstring_t(adp,value->LineCount,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F6;
      return ADP_FALSE;
  }
	uint32_t iLineCount = atoi(value->LineCount);
	adp->iRecCnt = iLineCount;
  if(!adp_array(adp,(caddr_t*)&(value->ParaLineInfo_val),(unsigned int)(adp->iRecCnt),~0,sizeof(ParaLineInfo_t),(adpproc_t)adp_ParaLineInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F7;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->StationCount,4))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F8;
      return ADP_FALSE;
  }
	uint32_t iStationCount = atoi(value->StationCount);
	adp->iRecCnt = iStationCount;
  if(!adp_array(adp,(caddr_t*)&(value->ParaStationInfo_val),(unsigned int)(adp->iRecCnt),~0,sizeof(ParaStationInfo_t),(adpproc_t)adp_ParaStationInfo_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x002F9;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

