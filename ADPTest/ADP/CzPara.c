#include "CzPara.h"
int adp_PARA_ACC_EOD_Server_t(ADP* adp,PARA_ACC_EOD_Server_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00001;
      return ADP_FALSE;
  }
  if(!adp_ServiceProviderID_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00002;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->CnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00003;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->CnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00004;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->EnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00005;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->EnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00006;
      return ADP_FALSE;
  }
  if(!adp_ServiceProviderRoleCode_t(adp,&(value->RoleCode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00007;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_LINE_STATION_DETAIL_t(ADP* adp,PARA_LINE_STATION_DETAIL_t* value)
{
  if(!adp_StationID_t(adp,&(value->StaionID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00008;
      return ADP_FALSE;
  }
  if(!adp_StationGlobalID_t(adp,&(value->StationGlobalID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00009;
      return ADP_FALSE;
  }
  if(!adp_U8_t(adp,&(value->Seq)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000A;
      return ADP_FALSE;
  }
  if(!adp_StationLevel_t(adp,&(value->Level)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000B;
      return ADP_FALSE;
  }
  if(!adp_StationType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_LINE_STATION_t(ADP* adp,PARA_LINE_STATION_t* value)
{
  if(!adp_LineID_t(adp,&(value->LineID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000D;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->StaQty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000E;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_LINE_STATION_DETAIL),(unsigned int)(value->StaQty.data.data),~0,sizeof(PARA_LINE_STATION_DETAIL_t),(adpproc_t)adp_PARA_LINE_STATION_DETAIL_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_LINE_EXT_t(ADP* adp,PARA_LINE_EXT_t* value)
{
  if(!adp_LineID_t(adp,&(value->LineID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00010;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->CnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00011;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->CnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00012;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->EnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00013;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->EnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00014;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_STATION_EXT_t(ADP* adp,PARA_STATION_EXT_t* value)
{
  if(!adp_StationID_t(adp,&(value->StationID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00015;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->CnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00016;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->CnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00017;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->EnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00018;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->EnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00019;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ZONE_DETAIL_t(ADP* adp,PARA_ZONE_DETAIL_t* value)
{
  if(!adp_StationID_t(adp,&(value->StationID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ZONE_t(ADP* adp,PARA_ZONE_t* value)
{
  if(!adp_ZoneID_t(adp,&(value->ZoneID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001B;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->ZoneName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001C;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->StaQty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001D;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_ZONE_DETAIL),(unsigned int)(value->StaQty.data.data),~0,sizeof(PARA_ZONE_DETAIL_t),(adpproc_t)adp_PARA_ZONE_DETAIL_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_SEGMENT_t(ADP* adp,PARA_SEGMENT_t* value)
{
  if(!adp_SegmentID_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001F;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00020;
      return ADP_FALSE;
  }
  if(!adp_StationID_t(adp,&(value->Sta1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00021;
      return ADP_FALSE;
  }
  if(!adp_StationID_t(adp,&(value->Sta2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00022;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TRANSFER_STATION_t(ADP* adp,PARA_TRANSFER_STATION_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00023;
      return ADP_FALSE;
  }
  if(!adp_TransferStationID_t(adp,&(value->Sta)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00024;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_NetworkTopo_t(ADP* adp,PARA_ACC_EOD_NetworkTopo_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->LioneQty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00025;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_LINE_STATION),(unsigned int)(value->LioneQty.data.data),~0,sizeof(PARA_LINE_STATION_t),(adpproc_t)adp_PARA_LINE_STATION_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00026;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->LineQty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00027;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_LINE_EXT),(unsigned int)(value->LineQty.data.data),~0,sizeof(PARA_LINE_EXT_t),(adpproc_t)adp_PARA_LINE_EXT_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00028;
      return ADP_FALSE;
  }
  if(!adp_MiddleQuantity_t(adp,&(value->StaQty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00029;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_STATION_EXT),(unsigned int)(value->StaQty.data.data),~0,sizeof(PARA_STATION_EXT_t),(adpproc_t)adp_PARA_STATION_EXT_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002A;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->ZoneQty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002B;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_ZONE),(unsigned int)(value->ZoneQty.data.data),~0,sizeof(PARA_ZONE_t),(adpproc_t)adp_PARA_ZONE_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002C;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002D;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_SEGMENT),(unsigned int)(value->Qty.data.data),~0,sizeof(PARA_SEGMENT_t),(adpproc_t)adp_PARA_SEGMENT_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_DURATION_t(ADP* adp,PARA_DURATION_t* value)
{
  if(!adp_Duration_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002F;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->Sta)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00030;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->End)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00031;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_SPECIAL_DATE_t(ADP* adp,PARA_SPECIAL_DATE_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00032;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->Date)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00033;
      return ADP_FALSE;
  }
  if(!adp_SpecialDateType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00034;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_ZONE_t(ADP* adp,PARA_TIME_ZONE_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00035;
      return ADP_FALSE;
  }
  if(!adp_U8_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00036;
      return ADP_FALSE;
  }
  if(!adp_SpecialDateType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00037;
      return ADP_FALSE;
  }
  if(!adp_TimeZoneType_t(adp,&(value->ZoneType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00038;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->Sta)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00039;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->End)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_RUN_DATE_t(ADP* adp,PARA_RUN_DATE_t* value)
{
  if(!adp_UTCTime_t(adp,&(value->DiffTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003B;
      return ADP_FALSE;
  }
  if(!adp_BaseTime_t(adp,&(value->BaseTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003C;
      return ADP_FALSE;
  }
  if(!adp_Duration_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003D;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->Date)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_RUN_TIME_t(ADP* adp,PARA_RUN_TIME_t* value)
{
  if(!adp_Second_t(adp,&(value->Sta)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003F;
      return ADP_FALSE;
  }
  if(!adp_Second_t(adp,&(value->End)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00040;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_UP_t(ADP* adp,PARA_TIME_INTERVAL_UP_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->TranUpTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00041;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->EventUpTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00042;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->AuditUpTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00043;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->PassUpTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00044;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_QUERY_t(ADP* adp,PARA_TIME_INTERVAL_QUERY_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->QueryTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00045;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_DOWN_t(ADP* adp,PARA_TIME_INTERVAL_DOWN_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->YKTDownTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00046;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->YKTRetTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00047;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->LineDownTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00048;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->StaDownTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00049;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->DevDownTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_BLACK_t(ADP* adp,PARA_TIME_INTERVAL_BLACK_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->BlackDownTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_DEV_AUTH_t(ADP* adp,PARA_TIME_INTERVAL_DEV_AUTH_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_STATU_QUERY_t(ADP* adp,PARA_TIME_INTERVAL_STATU_QUERY_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_STATISTICS_t(ADP* adp,PARA_TIME_INTERVAL_STATISTICS_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_MAX_INSTATION_t(ADP* adp,PARA_TIME_INTERVAL_MAX_INSTATION_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_NOINS_RETURN_t(ADP* adp,PARA_TIME_INTERVAL_NOINS_RETURN_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00050;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_INTERVAL_TICK_REPORT_t(ADP* adp,PARA_TIME_INTERVAL_TICK_REPORT_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00051;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TIME_NTP_DIFF_t(ADP* adp,PARA_TIME_NTP_DIFF_t* value)
{
  if(!adp_Second_t(adp,&(value->MinTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00052;
      return ADP_FALSE;
  }
  if(!adp_Second_t(adp,&(value->MaxTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00053;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_Calendar_t(ADP* adp,PARA_ACC_EOD_Calendar_t* value)
{
  if(!adp_PARA_DURATION_t(adp,&(value->PARA_DUARTION)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00054;
      return ADP_FALSE;
  }
  if(!adp_PARA_SPECIAL_DATE_t(adp,&(value->PARA_SPECIAL_DATE)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00055;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_ZONE_t(adp,&(value->PARA_TIME_ZONE)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00056;
      return ADP_FALSE;
  }
  if(!adp_PARA_RUN_DATE_t(adp,&(value->PARA_RUN_DATE)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00057;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_UP_t(adp,&(value->PARA_TIME_INTERVAL_UP)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00058;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_QUERY_t(adp,&(value->PARA_TIME_INTERVAL_QUERY)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00059;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_DOWN_t(adp,&(value->PARA_TIME_INTERVAL_DOWN)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005A;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_BLACK_t(adp,&(value->PARA_TIME_INTERVAL_BLACK)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005B;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_DEV_AUTH_t(adp,&(value->PARA_TIME_INTERVAL_DEV_AUTH)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005C;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_STATU_QUERY_t(adp,&(value->PARA_TIME_INTERVAL_STATU_QUERY)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005D;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_STATISTICS_t(adp,&(value->PARA_TIME_INTERVAL_STATISTICS)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005E;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_MAX_INSTATION_t(adp,&(value->PARA_TIME_INTERVAL_MAX_INSTATION)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005F;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_NOINS_RETURN_t(adp,&(value->PARA_TIME_INTERVAL_NOINS_RETURN)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00060;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_INTERVAL_TICK_REPORT_t(adp,&(value->PARA_TIME_INTERVAL_TICK_REPORT)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00061;
      return ADP_FALSE;
  }
  if(!adp_PARA_TIME_NTP_DIFF_t(adp,&(value->PARA_TIME_NTP_DIFF)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00062;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_WaiverDateC_t(ADP* adp,PARA_ACC_WaiverDateC_t* value)
{
  if(!adp_U16_t(adp,&(value->Id)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00063;
      return ADP_FALSE;
  }
  if(!adp_OperationMode_t(adp,&(value->ModeCode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00064;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->RunDate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00065;
      return ADP_FALSE;
  }
  if(!adp_StationID_t(adp,&(value->Sta)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00066;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->StaTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00067;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->EndTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00068;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->sensitiveEnd)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00069;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_WaiverDate_t(ADP* adp,PARA_ACC_WaiverDate_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006A;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_ACC_WaiverDateC_val),(unsigned int)(value->Qty.data.data),~0,sizeof(PARA_ACC_WaiverDateC_t),(adpproc_t)adp_PARA_ACC_WaiverDateC_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_CHIP_TYPE_t(ADP* adp,PARA_CHIP_TYPE_t* value)
{
  if(!adp_ChipType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006C;
      return ADP_FALSE;
  }
  if(!adp_CardFactory_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006D;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->Date)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006E;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->Count)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_CHIP_TYPE_EXT_t(ADP* adp,PARA_CHIP_TYPE_EXT_t* value)
{
  if(!adp_ChipType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00070;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->CnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00071;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->CnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00072;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->EnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00073;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->EnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00074;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICKET_FAMILY_t(ADP* adp,PARA_TICKET_FAMILY_t* value)
{
  if(!adp_TicketFamily_t(adp,&(value->Family)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00075;
      return ADP_FALSE;
  }
  if(!adp_ChipType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00076;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICKET_FAMILY_EXT_t(ADP* adp,PARA_TICKET_FAMILY_EXT_t* value)
{
  if(!adp_TicketFamily_t(adp,&(value->Family)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00077;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->CnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00078;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->CnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00079;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->EnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007A;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->EnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICKET_TYPE_t(ADP* adp,PARA_TICKET_TYPE_t* value)
{
  if(!adp_TicketType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007C;
      return ADP_FALSE;
  }
  if(!adp_TicketFamily_t(adp,&(value->Family)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007D;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->Deposit)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007E;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->SingleFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007F;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->Luggage)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00080;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->ExitFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00081;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->OrderFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00082;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->AuthFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00083;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->RecoveryFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00084;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->RegFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00085;
      return ADP_FALSE;
  }
  if(!adp_SouvenirFlag_t(adp,&(value->CommemorativeFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00086;
      return ADP_FALSE;
  }
  if(!adp_SalePriceMode_t(adp,&(value->SellMode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00087;
      return ADP_FALSE;
  }
  if(!adp_FavourID_t(adp,&(value->FavourID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00088;
      return ADP_FALSE;
  }
  if(!adp_ChargingMode_t(adp,&(value->BillMode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00089;
      return ADP_FALSE;
  }
  if(!adp_FareType_t(adp,&(value->FareType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008A;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->IfLimitTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008B;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->IfLimitZone)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008C;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->IfLimitSegment)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008D;
      return ADP_FALSE;
  }
  if(!adp_ActiveFlag_t(adp,&(value->IfRecharge)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008E;
      return ADP_FALSE;
  }
  if(!adp_ValidDateType_t(adp,&(value->ValidDateType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008F;
      return ADP_FALSE;
  }
  if(!adp_ActiveFlag_t(adp,&(value->AllowDalayTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00090;
      return ADP_FALSE;
  }
  if(!adp_ActiveFlag_t(adp,&(value->AllowRetTicket)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00091;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->RetFee)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00092;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->RetLimitAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00093;
      return ADP_FALSE;
  }
  if(!adp_ActiveFlag_t(adp,&(value->AllowRetCard)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00094;
      return ADP_FALSE;
  }
  if(!adp_ActiveFlag_t(adp,&(value->AllowChange)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00095;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->ServiceFee)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00096;
      return ADP_FALSE;
  }
  if(!adp_Depreciation_t(adp,&(value->Depreciation)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00097;
      return ADP_FALSE;
  }
  if(!adp_MediaType_t(adp,&(value->MediaType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00098;
      return ADP_FALSE;
  }
  if(!adp_BonusPointsID_t(adp,&(value->BonusPointsID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00099;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->EntryMinBalance)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009A;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->ExitMinBalance)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009B;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->MaxBalance)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009C;
      return ADP_FALSE;
  }
  if(!adp_ActiveFlag_t(adp,&(value->AllowOverdraft)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009D;
      return ADP_FALSE;
  }
  if(!adp_ConcessionType_t(adp,&(value->ConcessionType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009E;
      return ADP_FALSE;
  }
  if(!adp_ActiveFlag_t(adp,&(value->TicketTypeOpenSign)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICKET_TYPE_EXT_t(ADP* adp,PARA_TICKET_TYPE_EXT_t* value)
{
  if(!adp_TicketType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A0;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->CnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A1;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->CnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A2;
      return ADP_FALSE;
  }
  if(!adp_LongName_t(adp,&(value->EnLongName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A3;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->EnName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A4;
      return ADP_FALSE;
  }
  if(!adp_ConcessionalLampID_t(adp,&(value->LedID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A5;
      return ADP_FALSE;
  }
  if(!adp_SoundDisplayID_t(adp,&(value->SoundID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A6;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICKET_VALIDDATE_t(ADP* adp,PARA_TICKET_VALIDDATE_t* value)
{
  if(!adp_ValidDateType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A7;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A8;
      return ADP_FALSE;
  }
  if(!adp_DurationType_t(adp,&(value->ValidType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A9;
      return ADP_FALSE;
  }
  if(!adp_Duration_t(adp,&(value->ValidDate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AA;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->Sta)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AB;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->End)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AC;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICKET_FAVOUR_t(ADP* adp,PARA_TICKET_FAVOUR_t* value)
{
  if(!adp_FavourID_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AD;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AE;
      return ADP_FALSE;
  }
  if(!adp_Discount_t(adp,&(value->Discount)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000AF;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_MediaCard_t(ADP* adp,PARA_ACC_EOD_MediaCard_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B0;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_CHIP_TYPE),(unsigned int)(value->Qty1.data.data),~0,sizeof(PARA_CHIP_TYPE_t),(adpproc_t)adp_PARA_CHIP_TYPE_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B1;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B2;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_CHIP_TYPE_EXT),(unsigned int)(value->Qty2.data.data),~0,sizeof(PARA_CHIP_TYPE_EXT_t),(adpproc_t)adp_PARA_CHIP_TYPE_EXT_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B3;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty3)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B4;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_TICKET_FAMILY),(unsigned int)(value->Qty3.data.data),~0,sizeof(PARA_TICKET_FAMILY_t),(adpproc_t)adp_PARA_TICKET_FAMILY_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B5;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty4)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B6;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_TICKET_FAMILY_EXT),(unsigned int)(value->Qty4.data.data),~0,sizeof(PARA_TICKET_FAMILY_EXT_t),(adpproc_t)adp_PARA_TICKET_FAMILY_EXT_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B7;
      return ADP_FALSE;
  }
  if(!adp_MiddleQuantity_t(adp,&(value->Qty5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B8;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_TICKET_TYPE),(unsigned int)(value->Qty5.data.data),~0,sizeof(PARA_TICKET_TYPE_t),(adpproc_t)adp_PARA_TICKET_TYPE_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000B9;
      return ADP_FALSE;
  }
  if(!adp_MiddleQuantity_t(adp,&(value->Qty6)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BA;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_TICKET_TYPE_EXT),(unsigned int)(value->Qty6.data.data),~0,sizeof(PARA_TICKET_TYPE_EXT_t),(adpproc_t)adp_PARA_TICKET_TYPE_EXT_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BB;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty7)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BC;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_TICKET_VALIDDATE),(unsigned int)(value->Qty7.data.data),~0,sizeof(PARA_TICKET_VALIDDATE_t),(adpproc_t)adp_PARA_TICKET_VALIDDATE_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BD;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty8)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BE;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_TICKET_FOVOUR),(unsigned int)(value->Qty8.data.data),~0,sizeof(PARA_TICKET_FAVOUR_t),(adpproc_t)adp_PARA_TICKET_FAVOUR_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000BF;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_ClearingRule_t(ADP* adp,PARA_ACC_EOD_ClearingRule_t* value)
{
  if(!adp_Percentage_t(adp,&(value->RechargeServiceFee)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C0;
      return ADP_FALSE;
  }
  if(!adp_Percentage_t(adp,&(value->SellServiceFee)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C1;
      return ADP_FALSE;
  }
  if(!adp_Duration_t(adp,&(value->RetentionPeriod)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C2;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C3;
      return ADP_FALSE;
  }
  if(!adp_LineID_t(adp,&(value->Line)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C4;
      return ADP_FALSE;
  }
  if(!adp_Percentage_t(adp,&(value->ApportionmentRatio)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_PAY_ATTR_t(ADP* adp,PARA_PAY_ATTR_t* value)
{
  if(!adp_ValueCent_t(adp,&(value->BankPayMinAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C6;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->CashPayMaxAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C7;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_FARE_TYPE_t(ADP* adp,PARA_FARE_TYPE_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_FARE_LEVEL_t(ADP* adp,PARA_FARE_LEVEL_t* value)
{
  if(!adp_Quantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C8;
      return ADP_FALSE;
  }
  if(!adp_StationID_t(adp,&(value->Sta)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000C9;
      return ADP_FALSE;
  }
  if(!adp_StationID_t(adp,&(value->End)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CA;
      return ADP_FALSE;
  }
  if(!adp_FareRate_t(adp,&(value->Level)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CB;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_FARE_TYPE_GROUP_t(ADP* adp,PARA_FARE_TYPE_GROUP_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CC;
      return ADP_FALSE;
  }
  if(!adp_FareType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CD;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CE;
      return ADP_FALSE;
  }
  if(!adp_U8_t(adp,&(value->TimeCode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000CF;
      return ADP_FALSE;
  }
  if(!adp_FareGroup_t(adp,&(value->FareGroup)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D0;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_FARE_TBL_t(ADP* adp,PARA_FARE_TBL_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D1;
      return ADP_FALSE;
  }
  if(!adp_FareGroup_t(adp,&(value->FareGroup)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D2;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D3;
      return ADP_FALSE;
  }
  if(!adp_FareRate_t(adp,&(value->Level)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D4;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->FareRate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D5;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_FARE_TIME_t(ADP* adp,PARA_FARE_TIME_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D6;
      return ADP_FALSE;
  }
  if(!adp_FareRate_t(adp,&(value->Level)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D7;
      return ADP_FALSE;
  }
  if(!adp_TimeIntervalID_t(adp,&(value->StopLimit)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D8;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_FARE_OTHER_t(ADP* adp,PARA_FARE_OTHER_t* value)
{
  if(!adp_TimeIntervalID_t(adp,&(value->ShortRetTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000D9;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->ShortRetFee)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DA;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->MaxAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DB;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->MinEntryAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DC;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->MinExitAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DD;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_Fare_t(ADP* adp,PARA_ACC_EOD_Fare_t* value)
{
  if(!adp_PARA_PAY_ATTR_t(adp,&(value->PARA_PAY_ATTR)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DE;
      return ADP_FALSE;
  }
  if(!adp_PARA_FARE_TYPE_t(adp,&(value->PARA_FARE_TYPE)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000DF;
      return ADP_FALSE;
  }
  if(!adp_PARA_FARE_LEVEL_t(adp,&(value->PARA_FARE_LEVEL)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E0;
      return ADP_FALSE;
  }
  if(!adp_PARA_FARE_TYPE_GROUP_t(adp,&(value->PARA_FARE_TYPE_GROUP)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E1;
      return ADP_FALSE;
  }
  if(!adp_PARA_FARE_TBL_t(adp,&(value->PARA_FARE_TBL)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E2;
      return ADP_FALSE;
  }
  if(!adp_PARA_FARE_TIME_t(adp,&(value->PARA_FARE_TIME)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E3;
      return ADP_FALSE;
  }
  if(!adp_PARA_FARE_OTHER_t(adp,&(value->PARA_FARE_OTHER)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E4;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_PENALTY_t(ADP* adp,PARA_TICK_PENALTY_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E5;
      return ADP_FALSE;
  }
  if(!adp_PenaltyCode_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E6;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->Amt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E7;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_DISCOUNT_t(ADP* adp,PARA_TICK_DISCOUNT_t* value)
{
  if(!adp_Second_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E8;
      return ADP_FALSE;
  }
  if(!adp_Discount_t(adp,&(value->Rate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000E9;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->Amt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EA;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_ALARM_t(ADP* adp,PARA_TICK_ALARM_t* value)
{
  if(!adp_ConcessionalLampID_t(adp,&(value->ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EB;
      return ADP_FALSE;
  }
  if(!adp_SoundDisplayID_t(adp,&(value->SoundID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EC;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_PROCESS_t(ADP* adp,PARA_TICK_PROCESS_t* value)
{
  if(!adp_PARA_TICK_PENALTY_t(adp,&(value->PARA_TICK_PENALTY)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000ED;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_DISCOUNT_t(adp,&(value->PARA_TICK_DISCOUNT)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EE;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_ALARM_t(adp,&(value->PARA_TICK_ALARM)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000EF;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_RECHARGE_1_C_t(ADP* adp,PARA_RECHARGE_1_C_t* value)
{
  if(!adp_AddValueCode_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F0;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->PayAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F1;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->RechargeAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F2;
      return ADP_FALSE;
  }
  if(!adp_Duration_t(adp,&(value->Validity)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F3;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_RECHARGE_2_C_t(ADP* adp,PARA_RECHARGE_2_C_t* value)
{
  if(!adp_AddValueCode_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F4;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->PayAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F5;
      return ADP_FALSE;
  }
  if(!adp_MultiRideNumber_t(adp,&(value->RechargeAmt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F6;
      return ADP_FALSE;
  }
  if(!adp_Duration_t(adp,&(value->Validity)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F7;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_RECHARGE_t(ADP* adp,PARA_RECHARGE_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F8;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_RECHARGE_1_C_val),(unsigned int)(value->Qty1.data.data),~0,sizeof(PARA_RECHARGE_1_C_t),(adpproc_t)adp_PARA_RECHARGE_1_C_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000F9;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FA;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_RECHARGE_2_C_val),(unsigned int)(value->Qty2.data.data),~0,sizeof(PARA_RECHARGE_2_C_t),(adpproc_t)adp_PARA_RECHARGE_2_C_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FB;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_SELL_t(ADP* adp,PARA_TICK_SELL_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FC;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->Type1_val),(unsigned int)(value->Qty1.data.data),~0,sizeof(TicketType_t),(adpproc_t)adp_TicketType_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FD;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FE;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->Type_val),(unsigned int)(value->Qty2.data.data),~0,sizeof(AddValueCode_t),(adpproc_t)adp_AddValueCode_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000FF;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_RECHARGE_t(ADP* adp,PARA_TICK_RECHARGE_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00100;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->Type1_val),(unsigned int)(value->Qty1.data.data),~0,sizeof(TicketType_t),(adpproc_t)adp_TicketType_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00101;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00102;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->Type2_val),(unsigned int)(value->Qty2.data.data),~0,sizeof(AddValueCode_t),(adpproc_t)adp_AddValueCode_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00103;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_LIMIT_TIME_t(ADP* adp,PARA_TICK_LIMIT_TIME_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00104;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->Type1_val),(unsigned int)(value->Qty1.data.data),~0,sizeof(TicketType_t),(adpproc_t)adp_TicketType_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00105;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00106;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->Type2_val),(unsigned int)(value->Qty2.data.data),~0,sizeof(U8_t),(adpproc_t)adp_U8_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00107;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_ZONE_t(ADP* adp,PARA_TICK_ZONE_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00108;
      return ADP_FALSE;
  }
  if(!adp_TicketType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00109;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010A;
      return ADP_FALSE;
  }
  if(!adp_ZoneID_t(adp,&(value->ZoneID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_SEGMENT_t(ADP* adp,PARA_TICK_SEGMENT_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010C;
      return ADP_FALSE;
  }
  if(!adp_TicketType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010D;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010E;
      return ADP_FALSE;
  }
  if(!adp_SegmentID_t(adp,&(value->SegmentID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0010F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_AUTH_t(ADP* adp,PARA_TICK_AUTH_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00110;
      return ADP_FALSE;
  }
  if(!adp_TicketType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00111;
      return ADP_FALSE;
  }
  if(!adp_AuthorityType_t(adp,&(value->AuthType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00112;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_MAX_CNT_t(ADP* adp,PARA_TICK_MAX_CNT_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00113;
      return ADP_FALSE;
  }
  if(!adp_TicketType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00114;
      return ADP_FALSE;
  }
  if(!adp_MultiRideNumber_t(adp,&(value->Cnt)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00115;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_MAX_FARE_t(ADP* adp,PARA_TICK_MAX_FARE_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00116;
      return ADP_FALSE;
  }
  if(!adp_TicketType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00117;
      return ADP_FALSE;
  }
  if(!adp_FareRate_t(adp,&(value->Rate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00118;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_BOUNS_t(ADP* adp,PARA_TICK_BOUNS_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00119;
      return ADP_FALSE;
  }
  if(!adp_BonusPointsID_t(adp,&(value->ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011A;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011B;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->Quantity)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_TICK_ATTR_t(ADP* adp,PARA_TICK_ATTR_t* value)
{
  if(!adp_PARA_RECHARGE_t(adp,&(value->PARA_RECHARGE)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011D;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_SELL_t(adp,&(value->PARA_TICK_SELL)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011E;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_RECHARGE_t(adp,&(value->PARA_TICK_RECHARGE)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0011F;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_LIMIT_TIME_t(adp,&(value->PARA_TICK_LIMIT_TIME)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00120;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_ZONE_t(adp,&(value->PARA_TICK_ZONE)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00121;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_SEGMENT_t(adp,&(value->PARA_TICK_SEGMENT)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00122;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_AUTH_t(adp,&(value->PARA_TICK_AUTH)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00123;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_MAX_CNT_t(adp,&(value->PARA_TICK_MAX_CNT)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00124;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_MAX_FARE_t(adp,&(value->PARA_TICK_MAX_FARE)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00125;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_BOUNS_t(adp,&(value->PARA_TICK_BOUNS)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00126;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_Ticket_t(ADP* adp,PARA_ACC_EOD_Ticket_t* value)
{
  if(!adp_PARA_TICK_PROCESS_t(adp,&(value->PARA_TICK_PROCESS)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00127;
      return ADP_FALSE;
  }
  if(!adp_PARA_TICK_ATTR_t(adp,&(value->PARA_TICK_ATTR)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00128;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_BLK_t(ADP* adp,PARA_BLK_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_BLK_YKT_RECORD_t(ADP* adp,PARA_BLK_YKT_RECORD_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00129;
      return ADP_FALSE;
  }
  if(!adp_TicketPhyID_t(adp,&(value->PhyID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012A;
      return ADP_FALSE;
  }
  if(!adp_BlockCode_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_BLK_YKT_SEGMENT_t(ADP* adp,PARA_BLK_YKT_SEGMENT_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012C;
      return ADP_FALSE;
  }
  if(!adp_TicketPhyID_t(adp,&(value->BeginID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012D;
      return ADP_FALSE;
  }
  if(!adp_TicketPhyID_t(adp,&(value->EndID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012E;
      return ADP_FALSE;
  }
  if(!adp_BlockCode_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0012F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_BLK_YPT_RECORD_t(ADP* adp,PARA_BLK_YPT_RECORD_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00130;
      return ADP_FALSE;
  }
  if(!adp_TicketLogicalID_t(adp,&(value->ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00131;
      return ADP_FALSE;
  }
  if(!adp_BlockCode_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00132;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_BLK_YPT_SEGMENT_t(ADP* adp,PARA_BLK_YPT_SEGMENT_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00133;
      return ADP_FALSE;
  }
  if(!adp_TicketLogicalID_t(adp,&(value->BeginDI)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00134;
      return ADP_FALSE;
  }
  if(!adp_TicketLogicalID_t(adp,&(value->EndID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00135;
      return ADP_FALSE;
  }
  if(!adp_BlockCode_t(adp,&(value->Code)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00136;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_BLK_SAM_t(ADP* adp,PARA_BLK_SAM_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00137;
      return ADP_FALSE;
  }
  if(!adp_SAMID_t(adp,&(value->SAMID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00138;
      return ADP_FALSE;
  }
  if(!adp_SAMType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00139;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_GRY_t(ADP* adp,PARA_GRY_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013A;
      return ADP_FALSE;
  }
  if(!adp_TicketPhyID_t(adp,&(value->PhyID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013B;
      return ADP_FALSE;
  }
  if(!adp_MiddleQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013C;
      return ADP_FALSE;
  }
  if(!adp_TicketLogicalID_t(adp,&(value->LogicalID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_BLK_YKT_FULL_t(ADP* adp,PARA_BLK_YKT_FULL_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_BLK_YKT_INCR_t(ADP* adp,PARA_BLK_YKT_INCR_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_BLK_ACC_FULL_t(ADP* adp,PARA_BLK_ACC_FULL_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_BLK_ACC_INCR_t(ADP* adp,PARA_BLK_ACC_INCR_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_BLK_Dev_FULL_t(ADP* adp,PARA_BLK_Dev_FULL_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_GRY_FULL_t(ADP* adp,PARA_GRY_FULL_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_DEV_COMM_t(ADP* adp,PARA_DEV_COMM_t* value)
{
  if(!adp_MSecond_t(adp,&(value->Timeout)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013E;
      return ADP_FALSE;
  }
  if(!adp_MSecond_t(adp,&(value->NoPacketTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0013F;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->ACCIP)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00140;
      return ADP_FALSE;
  }
  if(!adp_AddressPort_t(adp,&(value->ACCPort)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00141;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->ACCIP2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00142;
      return ADP_FALSE;
  }
  if(!adp_AddressPort_t(adp,&(value->ACCPort2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00143;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_AGM_LED_t(ADP* adp,PARA_AGM_LED_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00144;
      return ADP_FALSE;
  }
  if(!adp_ConcessionalLampID_t(adp,&(value->ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00145;
      return ADP_FALSE;
  }
  if(!adp_LampColorType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00146;
      return ADP_FALSE;
  }
  if(!adp_HZ_t(adp,&(value->HZ1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00147;
      return ADP_FALSE;
  }
  if(!adp_MSecond_t(adp,&(value->MSecond)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00148;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_AGM_AUDIT_t(ADP* adp,PARA_AGM_AUDIT_t* value)
{
  if(!adp_SmallQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00149;
      return ADP_FALSE;
  }
  if(!adp_SoundDisplayID_t(adp,&(value->ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0014A;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->FileName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0014B;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0014C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_AGM_t(ADP* adp,PARA_EOD_AGM_t* value)
{
  if(!adp_PARA_AGM_LED_t(adp,&(value->PARA_AGM_LED)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0014D;
      return ADP_FALSE;
  }
  if(!adp_PARA_AGM_AUDIT_t(adp,&(value->PARA_AGM_AUDIT)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0014E;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_TVM_1_C_t(ADP* adp,PARA_ACC_EOD_TVM_1_C_t* value)
{
  if(!adp_TVMInterfaceID_t(adp,&(value->InterfaceCode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0014F;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->FileName)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00150;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_TVM_2_C_t(ADP* adp,PARA_ACC_EOD_TVM_2_C_t* value)
{
  if(!adp_BtnID_t(adp,&(value->BtnID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00151;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->BtnLeftX)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00152;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->BtnLeftY)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00153;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->BtnWidth)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00154;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->BtnHeight)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00155;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_TVM_3_C_t(ADP* adp,PARA_ACC_EOD_TVM_3_C_t* value)
{
  if(!adp_TVMPicIndex_t(adp,&(value->Index)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00156;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->IndexLeftX)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00157;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->IndexLeftY)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00158;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->IndexWidth)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00159;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->IndexHeight)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0015A;
      return ADP_FALSE;
  }
  if(!adp_TVMIndexType_t(adp,&(value->IndexType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0015B;
      return ADP_FALSE;
  }
  if(!adp_TVMInterfaceID_t(adp,&(value->IndexInterface)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0015C;
      return ADP_FALSE;
  }
  if(!adp_StationID_t(adp,&(value->IndexStation)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0015D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_TVM_t(ADP* adp,PARA_EOD_TVM_t* value)
{
  if(!adp_CoordinateUnit_t(adp,&(value->ScreenWidth)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0015E;
      return ADP_FALSE;
  }
  if(!adp_CoordinateUnit_t(adp,&(value->ScreenHeight)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0015F;
      return ADP_FALSE;
  }
  if(!adp_MiddleQuantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00160;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_ACC_EOD_TVM_1_C_val),(unsigned int)(value->Qty1.data.data),~0,sizeof(PARA_ACC_EOD_TVM_1_C_t),(adpproc_t)adp_PARA_ACC_EOD_TVM_1_C_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00161;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00162;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_ACC_EOD_TVM_2_C_val),(unsigned int)(value->Qty2.data.data),~0,sizeof(PARA_ACC_EOD_TVM_2_C_t),(adpproc_t)adp_PARA_ACC_EOD_TVM_2_C_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00163;
      return ADP_FALSE;
  }
  if(!adp_SmallQuantity_t(adp,&(value->Qty3)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00164;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_ACC_EOD_TVM_3_C_val),(unsigned int)(value->Qty3.data.data),~0,sizeof(PARA_ACC_EOD_TVM_3_C_t),(adpproc_t)adp_PARA_ACC_EOD_TVM_3_C_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00165;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_BOM_t(ADP* adp,PARA_EOD_BOM_t* value)
{
  return ADP_TRUE;
}

int adp_PARA_ACC_EOD_DEV_t(ADP* adp,PARA_ACC_EOD_DEV_t* value)
{
  if(!adp_PARA_DEV_COMM_t(adp,&(value->PARA_DEV_COMM)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00166;
      return ADP_FALSE;
  }
  if(!adp_PARA_EOD_AGM_t(adp,&(value->PARA_EOD_AGM)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00167;
      return ADP_FALSE;
  }
  if(!adp_PARA_EOD_TVM_t(adp,&(value->PARA_EOD_TVM)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00168;
      return ADP_FALSE;
  }
  if(!adp_PARA_EOD_BOM_t(adp,&(value->PARA_EOD_BOM)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00169;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_PARA_1_C_t(ADP* adp,PARA_EOD_PARA_1_C_t* value)
{
  if(!adp_FileName_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0016A;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0016B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_PARA_2_C_t(ADP* adp,PARA_EOD_PARA_2_C_t* value)
{
  if(!adp_FileName_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0016C;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0016D;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_PARA_t(ADP* adp,PARA_EOD_PARA_t* value)
{
  if(!adp_TimeStamp_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0016E;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->Time1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0016F;
      return ADP_FALSE;
  }
  if(!adp_ParamType_t(adp,&(value->Type1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00170;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->Name1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00171;
      return ADP_FALSE;
  }
  if(!adp_VersionID_t(adp,&(value->Ver1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00172;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD51)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00173;
      return ADP_FALSE;
  }
  if(!adp_ParamType_t(adp,&(value->Type2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00174;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->Name2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00175;
      return ADP_FALSE;
  }
  if(!adp_VersionID_t(adp,&(value->Ver2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00176;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->Time2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00177;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD52)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00178;
      return ADP_FALSE;
  }
  if(!adp_ParamType_t(adp,&(value->Type3)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00179;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->Name3)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017A;
      return ADP_FALSE;
  }
  if(!adp_VersionID_t(adp,&(value->Ver3)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017B;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->Time3)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017C;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD53)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017D;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->Qty1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017E;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_EOD_PARA_1_C_val),(unsigned int)(value->Qty1.data.data),~0,sizeof(PARA_EOD_PARA_1_C_t),(adpproc_t)adp_PARA_EOD_PARA_1_C_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0017F;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->Qty2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00180;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_EOD_PARA_2_C_val),(unsigned int)(value->Qty2.data.data),~0,sizeof(PARA_EOD_PARA_2_C_t),(adpproc_t)adp_PARA_EOD_PARA_2_C_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00181;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_MODE_t(ADP* adp,PARA_EOD_MODE_t* value)
{
  if(!adp_TimeStamp_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00182;
      return ADP_FALSE;
  }
  if(!adp_ParamType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00183;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00184;
      return ADP_FALSE;
  }
  if(!adp_VersionID_t(adp,&(value->Ver)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00185;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->ActiveTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00186;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->FileMD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00187;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->EODMD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00188;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_BLK_t(ADP* adp,PARA_EOD_BLK_t* value)
{
  if(!adp_TimeStamp_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00189;
      return ADP_FALSE;
  }
  if(!adp_ParamType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018A;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->IfExist1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018B;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->Name1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018C;
      return ADP_FALSE;
  }
  if(!adp_VersionID_t(adp,&(value->Ver1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018D;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->ActiveTime1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018E;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD51)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0018F;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->IfExist2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00190;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->Name2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00191;
      return ADP_FALSE;
  }
  if(!adp_VersionID_t(adp,&(value->Ver2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00192;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->ActiveTime2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00193;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD52)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00194;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->EODMD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00195;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_TP_C_t(ADP* adp,PARA_EOD_TP_C_t* value)
{
  if(!adp_MiddleQuantity_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00196;
      return ADP_FALSE;
  }
  if(!adp_FileName_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00197;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->MD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00198;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_TP_t(ADP* adp,PARA_EOD_TP_t* value)
{
  if(!adp_TimeStamp_t(adp,&(value->Time)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00199;
      return ADP_FALSE;
  }
  if(!adp_ParamType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019A;
      return ADP_FALSE;
  }
  if(!adp_VersionID_t(adp,&(value->Ver)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019B;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->ActiveTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019C;
      return ADP_FALSE;
  }
  if(!adp_MiddleQuantity_t(adp,&(value->Qty)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019D;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->PARA_EOD_TP_C_val),(unsigned int)(value->Qty.data.data),~0,sizeof(PARA_EOD_TP_C_t),(adpproc_t)adp_PARA_EOD_TP_C_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019E;
      return ADP_FALSE;
  }
  if(!adp_MD5_t(adp,&(value->EODMD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0019F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PARA_EOD_t(ADP* adp,PARA_EOD_t* value)
{
  if(!adp_FileType_t(adp,&(value->FileType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A0;
      return ADP_FALSE;
  }
  if(!adp_ParamType_t(adp,&(value->Type)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A1;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->Timeout)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001A2;
      return ADP_FALSE;
  }
  switch(value->Type.data.data)
  {
    case 2:
      if (!adp_PARA_ACC_EOD_Server_t(adp,&(value->body_u.PARA_ACC_EOD_Server)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001A3;
          return ADP_FALSE;
      }
      break;
    case 3:
      if (!adp_PARA_ACC_EOD_NetworkTopo_t(adp,&(value->body_u.PARA_ACC_EOD_NetworkTopo)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001A4;
          return ADP_FALSE;
      }
      break;
    case 4:
      if (!adp_PARA_ACC_EOD_Calendar_t(adp,&(value->body_u.PARA_ACC_EOD_Calendar)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001A5;
          return ADP_FALSE;
      }
      break;
    case 5:
      if (!adp_PARA_ACC_EOD_MediaCard_t(adp,&(value->body_u.PARA_ACC_EOD_MediaCard)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001A6;
          return ADP_FALSE;
      }
      break;
    case 6:
      if (!adp_PARA_ACC_EOD_ClearingRule_t(adp,&(value->body_u.PARA_ACC_EOD_ClearingRule)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001A7;
          return ADP_FALSE;
      }
      break;
    case 7:
      if (!adp_PARA_ACC_EOD_Fare_t(adp,&(value->body_u.PARA_ACC_EOD_Fare)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001A8;
          return ADP_FALSE;
      }
      break;
    case 8:
      if (!adp_PARA_ACC_EOD_Ticket_t(adp,&(value->body_u.PARA_ACC_EOD_Ticket)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001A9;
          return ADP_FALSE;
      }
      break;
    case 51:
      if (!adp_PARA_ACC_EOD_DEV_t(adp,&(value->body_u.PARA_ACC_EOD_DEV)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001AA;
          return ADP_FALSE;
      }
      break;
    case 52:
      if (!adp_PARA_EOD_AGM_t(adp,&(value->body_u.PARA_EOD_AGM)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001AB;
          return ADP_FALSE;
      }
      break;
    case 53:
      if (!adp_PARA_EOD_TVM_t(adp,&(value->body_u.PARA_EOD_TVM)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001AC;
          return ADP_FALSE;
      }
      break;
    case 54:
      if (!adp_PARA_EOD_BOM_t(adp,&(value->body_u.PARA_EOD_BOM)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001AD;
          return ADP_FALSE;
      }
      break;
    case 61:
      if (!adp_PARA_EOD_MODE_t(adp,&(value->body_u.PARA_EOD_MODE)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001AE;
          return ADP_FALSE;
      }
      break;
    case 71:
      if (!adp_PARA_EOD_BLK_t(adp,&(value->body_u.PARA_EOD_BLK)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001AF;
          return ADP_FALSE;
      }
      break;
    case 81:
      if (!adp_PARA_EOD_TP_t(adp,&(value->body_u.PARA_EOD_TP)))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x001B0;
          return ADP_FALSE;
      }
      break;
  }
  if(!adp_MD5_t(adp,&(value->MD5)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B1;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_MainEODStu_t(ADP* adp,MainEODStu_t* value)
{
  if(!adp_uint8_t(adp,&(value->ParaType),1))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B2;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->EODName,100))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B3;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->MainEODVer),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B4;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->ActiveTime),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B5;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->md5,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B6;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaPic_t(ADP* adp,ParaPic_t* value)
{
  if(!adp_fixstring_t(adp,value->fileName,100))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B7;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->md5,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B8;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaSound_t(ADP* adp,ParaSound_t* value)
{
  if(!adp_fixstring_t(adp,value->fileName,100))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001B9;
      return ADP_FALSE;
  }
  if(!adp_fixstring_t(adp,value->md5,16))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BA;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_ParaMainConfigure_t(ADP* adp,ParaMainConfigure_t* value)
{
  if(!adp_uint16_t(adp,&(value->fileType),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BB;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->editTimeStamp),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BC;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->activeTimeStamp),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BD;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->component_cnt),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BE;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->component_val),(unsigned int)(value->component_cnt),~0,sizeof(MainEODStu_t),(adpproc_t)adp_MainEODStu_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001BF;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->pic_cnt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C0;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->pic_val),(unsigned int)(value->pic_cnt),~0,sizeof(ParaPic_t),(adpproc_t)adp_ParaPic_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C1;
      return ADP_FALSE;
  }
  if(!adp_uint32_t(adp,&(value->sound_cnt),4,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C2;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->sound_val),(unsigned int)(value->sound_cnt),~0,sizeof(ParaSound_t),(adpproc_t)adp_ParaSound_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x001C3;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

