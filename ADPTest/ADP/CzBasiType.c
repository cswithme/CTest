#include "CzBasiType.h"
int adp_U8_t(ADP* adp,U8_t* value)
{
  if(!adp_uint8_t(adp,&(value->data),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00001;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_U16_t(ADP* adp,U16_t* value)
{
  if(!adp_uint16_t(adp,&(value->data),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00002;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_U32_t(ADP* adp,U32_t* value)
{
  if(!adp_uint32_t(adp,&(value->data),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00003;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_S8_t(ADP* adp,S8_t* value)
{
  if(!adp_int8_t(adp,&(value->data),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00004;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_S16_t(ADP* adp,S16_t* value)
{
  if(!adp_int16_t(adp,&(value->data),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00005;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_S32_t(ADP* adp,S32_t* value)
{
  if(!adp_int32_t(adp,&(value->data),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00006;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Boolean_t(ADP* adp,Boolean_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00007;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ValueCent_t(ADP* adp,ValueCent_t* value)
{
  if(!adp_S32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00008;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SJTValueCent_t(ADP* adp,SJTValueCent_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00009;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MultiRideNumber_t(ADP* adp,MultiRideNumber_t* value)
{
  if(!adp_S16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MSecond_t(ADP* adp,MSecond_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Second_t(ADP* adp,Second_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TimeIntervalID_t(ADP* adp,TimeIntervalID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Duration_t(ADP* adp,Duration_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_UTCTime_t(ADP* adp,UTCTime_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BaseTime_t(ADP* adp,BaseTime_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00010;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Date2_t(ADP* adp,Date2_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00011;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TimeStamp_t(ADP* adp,TimeStamp_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00012;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ENChar_t(ADP* adp,ENChar_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00013;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CNChar_t(ADP* adp,CNChar_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00014;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Name_t(ADP* adp,Name_t* value)
{
  if(!adp_block_t(adp,value->data,20))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00015;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LongName_t(ADP* adp,LongName_t* value)
{
  if(!adp_block_t(adp,value->data,64))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00016;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FileName_t(ADP* adp,FileName_t* value)
{
  if(!adp_block_t(adp,value->data,100))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00017;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Gender_t(ADP* adp,Gender_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00018;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Language_t(ADP* adp,Language_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00019;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Percentage_t(ADP* adp,Percentage_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Quantity_t(ADP* adp,Quantity_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MiddleQuantity_t(ADP* adp,MiddleQuantity_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SmallQuantity_t(ADP* adp,SmallQuantity_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_VersionType_t(ADP* adp,VersionType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_VersionID_t(ADP* adp,VersionID_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_KeyVersionID_t(ADP* adp,KeyVersionID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00020;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LayoutVersionID_t(ADP* adp,LayoutVersionID_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00021;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SJTLayoutVersionID_t(ADP* adp,SJTLayoutVersionID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00022;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BatchCode_t(ADP* adp,BatchCode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00023;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SN_t(ADP* adp,SN_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00024;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SynchronizationType_t(ADP* adp,SynchronizationType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00025;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CoordinateUnit_t(ADP* adp,CoordinateUnit_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00026;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MD5_t(ADP* adp,MD5_t* value)
{
  if(!adp_block_t(adp,value->data,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00027;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TAC_t(ADP* adp,TAC_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00028;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_InitMAC_t(ADP* adp,InitMAC_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00029;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MAC_t(ADP* adp,MAC_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_AddressPort_t(ADP* adp,AddressPort_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Reserved_t(ADP* adp,Reserved_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CityCode_t(ADP* adp,CityCode_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_IndustryCode_t(ADP* adp,IndustryCode_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ServiceProviderID_t(ADP* adp,ServiceProviderID_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ServiceProviderRoleCode_t(ADP* adp,ServiceProviderRoleCode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00030;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CardFactory_t(ADP* adp,CardFactory_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00031;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LineID_t(ADP* adp,LineID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00032;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StationID_t(ADP* adp,StationID_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00033;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StationGlobalID_t(ADP* adp,StationGlobalID_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00034;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SJTStationID_t(ADP* adp,SJTStationID_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00035;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StationLevel_t(ADP* adp,StationLevel_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00036;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StationType_t(ADP* adp,StationType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00037;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TransferStationID_t(ADP* adp,TransferStationID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00038;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ZoneID_t(ADP* adp,ZoneID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00039;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SegmentID_t(ADP* adp,SegmentID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_UpDown_t(ADP* adp,UpDown_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SpecialDateType_t(ADP* adp,SpecialDateType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TimeZoneType_t(ADP* adp,TimeZoneType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ValidDateType_t(ADP* adp,ValidDateType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DurationType_t(ADP* adp,DurationType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DeviceType_t(ADP* adp,DeviceType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00040;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DeviceID_t(ADP* adp,DeviceID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00041;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SJTDeviceID_t(ADP* adp,SJTDeviceID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00042;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ModuleID_t(ADP* adp,ModuleID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00043;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_EquipmentStatusID_t(ADP* adp,EquipmentStatusID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00044;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ModuleStatusID_t(ADP* adp,ModuleStatusID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00045;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_WorkingStatus_t(ADP* adp,WorkingStatus_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00046;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PassageModelType_t(ADP* adp,PassageModelType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00047;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LampColorType_t(ADP* adp,LampColorType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00048;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_HZ_t(ADP* adp,HZ_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00049;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ConcessionalLampID_t(ADP* adp,ConcessionalLampID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SoundDisplayID_t(ADP* adp,SoundDisplayID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMInterfaceID_t(ADP* adp,TVMInterfaceID_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BtnID_t(ADP* adp,BtnID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMPicIndex_t(ADP* adp,TVMPicIndex_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TVMIndexType_t(ADP* adp,TVMIndexType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TopPanelDisplayID_t(ADP* adp,TopPanelDisplayID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00050;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ADItemID_t(ADP* adp,ADItemID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00051;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ADPlayMeans_t(ADP* adp,ADPlayMeans_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00052;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ContainerID_t(ADP* adp,ContainerID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00053;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BoxOperationType_t(ADP* adp,BoxOperationType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00054;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BoxType_t(ADP* adp,BoxType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00055;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CoinBoxID_t(ADP* adp,CoinBoxID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00056;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BankNoteBoxID_t(ADP* adp,BankNoteBoxID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00057;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DrumBlockID_t(ADP* adp,DrumBlockID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00058;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_HopperID_t(ADP* adp,HopperID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00059;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DeviceSoftType_t(ADP* adp,DeviceSoftType_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_RWCommandID_t(ADP* adp,RWCommandID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_RWAnswerID_t(ADP* adp,RWAnswerID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PassengerTypeID_t(ADP* adp,PassengerTypeID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PersonIDType_t(ADP* adp,PersonIDType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PersonIDSN_t(ADP* adp,PersonIDSN_t* value)
{
  if(!adp_block_t(adp,value->data,18))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StaffID_t(ADP* adp,StaffID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00060;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StaffType_t(ADP* adp,StaffType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00061;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DepartmentID_t(ADP* adp,DepartmentID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00062;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_StaffBitmap_t(ADP* adp,StaffBitmap_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00063;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_AuthorityType_t(ADP* adp,AuthorityType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00064;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Password_t(ADP* adp,Password_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00065;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ChipType_t(ADP* adp,ChipType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00066;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketFamily_t(ADP* adp,TicketFamily_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00067;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketType_t(ADP* adp,TicketType_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00068;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MediaType_t(ADP* adp,MediaType_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00069;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketLogicalID_t(ADP* adp,TicketLogicalID_t* value)
{
  if(!adp_block_t(adp,value->data,8))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketPrintNumber_t(ADP* adp,TicketPrintNumber_t* value)
{
  if(!adp_block_t(adp,value->data,8))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketPhyID_t(ADP* adp,TicketPhyID_t* value)
{
  if(!adp_block_t(adp,value->data,8))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TestFlag_t(ADP* adp,TestFlag_t* value)
{
  if(!adp_Boolean_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ActiveFlag_t(ADP* adp,ActiveFlag_t* value)
{
  if(!adp_Boolean_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SouvenirFlag_t(ADP* adp,SouvenirFlag_t* value)
{
  if(!adp_Boolean_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SouvenirUsedFlag_t(ADP* adp,SouvenirUsedFlag_t* value)
{
  if(!adp_Boolean_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00070;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketFareTypeID_t(ADP* adp,TicketFareTypeID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00071;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_EntryFlag_t(ADP* adp,EntryFlag_t* value)
{
  if(!adp_Boolean_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00072;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ExitFlag_t(ADP* adp,ExitFlag_t* value)
{
  if(!adp_Boolean_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00073;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_OperationSN_t(ADP* adp,OperationSN_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00074;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_RenewFlag_t(ADP* adp,RenewFlag_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00075;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PenaltyCode_t(ADP* adp,PenaltyCode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00076;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketStatus_t(ADP* adp,TicketStatus_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00077;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketStatusFlag_t(ADP* adp,TicketStatusFlag_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00078;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TicketPhyStatus_t(ADP* adp,TicketPhyStatus_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00079;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Depreciation_t(ADP* adp,Depreciation_t* value)
{
  if(!adp_Duration_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DepreciationPeriod_t(ADP* adp,DepreciationPeriod_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_Discount_t(ADP* adp,Discount_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_RefundReasonCode_t(ADP* adp,RefundReasonCode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BlockCode_t(ADP* adp,BlockCode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_UnBlockCode_t(ADP* adp,UnBlockCode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TPFlag_t(ADP* adp,TPFlag_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00080;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ChargingMode_t(ADP* adp,ChargingMode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00081;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FareType_t(ADP* adp,FareType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00082;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FareRate_t(ADP* adp,FareRate_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00083;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FareGroup_t(ADP* adp,FareGroup_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00084;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SalePriceMode_t(ADP* adp,SalePriceMode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00085;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_AddValueCode_t(ADP* adp,AddValueCode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00086;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FavourID_t(ADP* adp,FavourID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00087;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ConcessionType_t(ADP* adp,ConcessionType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00088;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BonusPointsID_t(ADP* adp,BonusPointsID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00089;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_OperationMode_t(ADP* adp,OperationMode_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_UrgencyMode_t(ADP* adp,UrgencyMode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TransactionType_t(ADP* adp,TransactionType_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CoinTrasactionSubType_t(ADP* adp,CoinTrasactionSubType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BankNoteTrsactionSubType_t(ADP* adp,BankNoteTrsactionSubType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ContainerTrasactionSubType_t(ADP* adp,ContainerTrasactionSubType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PullPushReason_t(ADP* adp,PullPushReason_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00090;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_RecycleSelect_t(ADP* adp,RecycleSelect_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00091;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ARType_t(ADP* adp,ARType_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00092;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_EventID_t(ADP* adp,EventID_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00093;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_EventValue_t(ADP* adp,EventValue_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00094;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MessageType_t(ADP* adp,MessageType_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00095;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MACK_t(ADP* adp,MACK_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00096;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PaymentMeans_t(ADP* adp,PaymentMeans_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00097;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_RefundType_t(ADP* adp,RefundType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00098;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_BOMShiftID_t(ADP* adp,BOMShiftID_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00099;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_RejectCode_t(ADP* adp,RejectCode_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SAMID_t(ADP* adp,SAMID_t* value)
{
  if(!adp_block_t(adp,value->data,8))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SAMType_t(ADP* adp,SAMType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_SAMPPSValue_t(ADP* adp,SAMPPSValue_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ePurseSN_t(ADP* adp,ePurseSN_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FileType_t(ADP* adp,FileType_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParamType_t(ADP* adp,ParamType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A0;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_DisposeCode_t(ADP* adp,DisposeCode_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A1;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FileTag_t(ADP* adp,FileTag_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A2;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_EntryExitBit_t(ADP* adp,EntryExitBit_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A3;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_LastRideID_t(ADP* adp,LastRideID_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A4;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ReceiptNumber_t(ADP* adp,ReceiptNumber_t* value)
{
  if(!adp_S32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CardClass_t(ADP* adp,CardClass_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A6;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CardVersion_t(ADP* adp,CardVersion_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A7;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YKTKeyIndex_t(ADP* adp,YKTKeyIndex_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A8;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CardRandomData_t(ADP* adp,CardRandomData_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A9;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_TradeTransactionType_t(ADP* adp,TradeTransactionType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AA;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YKTSAMID_t(ADP* adp,YKTSAMID_t* value)
{
  if(!adp_block_t(adp,value->data,8))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AB;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YKTSAMKeyVersion_t(ADP* adp,YKTSAMKeyVersion_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AC;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YKTPosSeq_t(ADP* adp,YKTPosSeq_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AD;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YKTDivfactor_t(ADP* adp,YKTDivfactor_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AE;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YKTTradeIndex_t(ADP* adp,YKTTradeIndex_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AF;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YKTTRDType_t(ADP* adp,YKTTRDType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B0;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YKTTAppChildType_t(ADP* adp,YKTTAppChildType_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B1;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YPTCPUKeyIndex_t(ADP* adp,YPTCPUKeyIndex_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B2;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YPTCPUTRDTypex_t(ADP* adp,YPTCPUTRDTypex_t* value)
{
  if(!adp_U8_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B3;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YPTCPUSAMKeyVersion_t(ADP* adp,YPTCPUSAMKeyVersion_t* value)
{
  if(!adp_U16_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B4;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_YPTPSAMSeq_t(ADP* adp,YPTPSAMSeq_t* value)
{
  if(!adp_U32_t(adp,&(value->data)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

