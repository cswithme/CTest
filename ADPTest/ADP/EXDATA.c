#include "EXDATA.h"
int adp_PrjFileTran_t(ADP* adp,PrjFileTran_t* value)
{
  if(!adp_TransactionType_t(adp,&(value->TransactionType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00001;
      return ADP_FALSE;
  }
  if(!adp_SN_t(adp,&(value->UDSN)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00002;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->BusinessDay)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00003;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->TransactionDateTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00004;
      return ADP_FALSE;
  }
  if(!adp_ServiceProviderID_t(adp,&(value->TransactionServiceProvider)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00005;
      return ADP_FALSE;
  }
  if(!adp_LineID_t(adp,&(value->LineID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00006;
      return ADP_FALSE;
  }
  if(!adp_StationID_t(adp,&(value->StationID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00007;
      return ADP_FALSE;
  }
  if(!adp_DeviceID_t(adp,&(value->DeviceID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00008;
      return ADP_FALSE;
  }
  if(!adp_OperationMode_t(adp,&(value->OperationMode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00009;
      return ADP_FALSE;
  }
  if(!adp_SAMID_t(adp,&(value->SAMID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000A;
      return ADP_FALSE;
  }
  if(!adp_Language_t(adp,&(value->LanguageBit)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000B;
      return ADP_FALSE;
  }
  if(!adp_ContainerID_t(adp,&(value->ContainerID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000C;
      return ADP_FALSE;
  }
  if(!adp_StaffID_t(adp,&(value->Operator)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000D;
      return ADP_FALSE;
  }
  if(!adp_BOMShiftID_t(adp,&(value->BOMShiftID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000E;
      return ADP_FALSE;
  }
  if(!adp_TicketPhyID_t(adp,&(value->CardPhysicalNO)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0000F;
      return ADP_FALSE;
  }
  if(!adp_TicketLogicalID_t(adp,&(value->CardLogicNO)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00010;
      return ADP_FALSE;
  }
  if(!adp_TicketType_t(adp,&(value->TicketType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00011;
      return ADP_FALSE;
  }
  if(!adp_TestFlag_t(adp,&(value->TestFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00012;
      return ADP_FALSE;
  }
  if(!adp_Boolean_t(adp,&(value->RecycleFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00013;
      return ADP_FALSE;
  }
  if(!adp_TicketStatusFlag_t(adp,&(value->TicketStatusFlag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00014;
      return ADP_FALSE;
  }
  if(!adp_BlockCode_t(adp,&(value->BlockorUnBlockCode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00015;
      return ADP_FALSE;
  }
  if(!adp_OperationSN_t(adp,&(value->OperationSN)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00016;
      return ADP_FALSE;
  }
  if(!adp_LayoutVersionID_t(adp,&(value->CardLayoutVersionNumber)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00017;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->InitDate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00018;
      return ADP_FALSE;
  }
  if(!adp_BatchCode_t(adp,&(value->InitBatchCode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00019;
      return ADP_FALSE;
  }
  if(!adp_MediaType_t(adp,&(value->MediaType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001A;
      return ADP_FALSE;
  }
  if(!adp_ChargingMode_t(adp,&(value->ChargingMode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001B;
      return ADP_FALSE;
  }
  if(!adp_ValidDateType_t(adp,&(value->DurationMode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001C;
      return ADP_FALSE;
  }
  if(!adp_ActiveFlag_t(adp,&(value->DurationExtension)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001D;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->CSCStartDate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001E;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->CSCEndDate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0001F;
      return ADP_FALSE;
  }
  if(!adp_DurationType_t(adp,&(value->CSCDurationUnit)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00020;
      return ADP_FALSE;
  }
  if(!adp_Duration_t(adp,&(value->CSCDuration)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00021;
      return ADP_FALSE;
  }
  if(!adp_PassengerTypeID_t(adp,&(value->PersonType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00022;
      return ADP_FALSE;
  }
  if(!adp_Name_t(adp,&(value->Name)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00023;
      return ADP_FALSE;
  }
  if(!adp_Gender_t(adp,&(value->Gender)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00024;
      return ADP_FALSE;
  }
  if(!adp_PersonIDType_t(adp,&(value->CertificateType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00025;
      return ADP_FALSE;
  }
  if(!adp_PersonIDSN_t(adp,&(value->PersonID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00026;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->CheckDate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00027;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->FavourEndDate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00028;
      return ADP_FALSE;
  }
  if(!adp_StaffID_t(adp,&(value->StaffID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00029;
      return ADP_FALSE;
  }
  if(!adp_DepartmentID_t(adp,&(value->DepartmentID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002A;
      return ADP_FALSE;
  }
  if(!adp_AuthorityType_t(adp,&(value->TravelRights)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002B;
      return ADP_FALSE;
  }
  if(!adp_MultiRideNumber_t(adp,&(value->AllowedUses)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002C;
      return ADP_FALSE;
  }
  if(!adp_SegmentID_t(adp,&(value->AllowedStationID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002D;
      return ADP_FALSE;
  }
  if(!adp_ZoneID_t(adp,&(value->ZoneID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002E;
      return ADP_FALSE;
  }
  if(!adp_StaffBitmap_t(adp,&(value->StaffOperationRights)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0002F;
      return ADP_FALSE;
  }
  if(!adp_LineID_t(adp,&(value->EntryLineID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00030;
      return ADP_FALSE;
  }
  if(!adp_StationID_t(adp,&(value->EntryStationID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00031;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->Entrytime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00032;
      return ADP_FALSE;
  }
  if(!adp_RenewFlag_t(adp,&(value->SurchargeStatus)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00033;
      return ADP_FALSE;
  }
  if(!adp_RejectCode_t(adp,&(value->EntryExitRejectCode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00034;
      return ADP_FALSE;
  }
  if(!adp_RefundReasonCode_t(adp,&(value->RefundReason)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00035;
      return ADP_FALSE;
  }
  if(!adp_PenaltyCode_t(adp,&(value->PenaltyCode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00036;
      return ADP_FALSE;
  }
  if(!adp_TicketFareTypeID_t(adp,&(value->TicketWalletOrder)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00037;
      return ADP_FALSE;
  }
  if(!adp_ePurseSN_t(adp,&(value->ePurseTransactionSN)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00038;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->TicketValueBefore)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00039;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->AccountBalance)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003A;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->OperatorConfirmedValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003B;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->AmoutReceivable)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003C;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->InsertValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003D;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->Poundage)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003E;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->CardDepositValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0003F;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->DepreciationValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00040;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->ChangeAmount)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00041;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->TransactionValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00042;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->WalletChangeValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00043;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->RemainingValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00044;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->AccumulativeLoadedValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00045;
      return ADP_FALSE;
  }
  if(!adp_PaymentMeans_t(adp,&(value->Paymentmeans)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00046;
      return ADP_FALSE;
  }
  if(!adp_FareRate_t(adp,&(value->FareTier)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00047;
      return ADP_FALSE;
  }
  if(!adp_ReceiptNumber_t(adp,&(value->ReceiptNumber)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00048;
      return ADP_FALSE;
  }
  if(!adp_TAC_t(adp,&(value->TAC)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00049;
      return ADP_FALSE;
  }
  if(!adp_U16_t(adp,&(value->EndOfRecord)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004A;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_CurrencyCodeQty_t(ADP* adp,CurrencyCodeQty_t* value)
{
  if(!adp_CurrencyCode_t(adp,&(value->Currencycode)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004B;
      return ADP_FALSE;
  }
  if(!adp_MiddleQuantity_t(adp,&(value->Number)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjFileOper_t(ADP* adp,PrjFileOper_t* value)
{
  if(!adp_TransactionType_t(adp,&(value->TransactionType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004D;
      return ADP_FALSE;
  }
  if(!adp_SN_t(adp,&(value->UDSN)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004E;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->BusinessDay)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0004F;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->TransactionDateTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00050;
      return ADP_FALSE;
  }
  if(!adp_DeviceType_t(adp,&(value->DeviceType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00051;
      return ADP_FALSE;
  }
  if(!adp_DeviceID_t(adp,&(value->DeviceID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00052;
      return ADP_FALSE;
  }
  if(!adp_StaffID_t(adp,&(value->Operator)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00053;
      return ADP_FALSE;
  }
  if(!adp_BOMShiftID_t(adp,&(value->BOMShiftID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00054;
      return ADP_FALSE;
  }
  if(!adp_ContainerID_t(adp,&(value->ContainerID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00055;
      return ADP_FALSE;
  }
  if(!adp_BoxOperationType_t(adp,&(value->BoxOperationType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00056;
      return ADP_FALSE;
  }
  if(!adp_BoxType_t(adp,&(value->BoxType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00057;
      return ADP_FALSE;
  }
  if(!adp_U8_t(adp,&(value->BoxLocationID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00058;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->TimeStamp)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00059;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->TotalAmount)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005A;
      return ADP_FALSE;
  }
  if(!adp_MiddleQuantity_t(adp,&(value->CurCount)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005B;
      return ADP_FALSE;
  }
  if(!adp_array(adp,(caddr_t*)&(value->CurrencyCodeQty),(unsigned int)(value->CurCount.data.data),~0,sizeof(CurrencyCodeQty_t),(adpproc_t)adp_CurrencyCodeQty_t))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005C;
      return ADP_FALSE;
  }
  if(!adp_TicketType_t(adp,&(value->TicketType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005D;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->InstallAmount)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005E;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->CurrentAmount)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0005F;
      return ADP_FALSE;
  }
  if(!adp_U16_t(adp,&(value->EndOfRecord)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00060;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjFileAudit_t(ADP* adp,PrjFileAudit_t* value)
{
  return ADP_TRUE;
}

int adp_PrjFileFTP_t(ADP* adp,PrjFileFTP_t* value)
{
  return ADP_TRUE;
}

int adp_PrjFileFTPDiff_t(ADP* adp,PrjFileFTPDiff_t* value)
{
  return ADP_TRUE;
}

int adp_PrjFileBalance_t(ADP* adp,PrjFileBalance_t* value)
{
  return ADP_TRUE;
}

int adp_PrjFileEvent_t(ADP* adp,PrjFileEvent_t* value)
{
  if(!adp_Date2_t(adp,&(value->BusinessDay)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00061;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->TransactionDateTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00062;
      return ADP_FALSE;
  }
  if(!adp_DeviceID_t(adp,&(value->DeviceID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00063;
      return ADP_FALSE;
  }
  if(!adp_EventID_t(adp,&(value->EventID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00064;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->EventName,6))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00065;
      return ADP_FALSE;
  }
  if(!adp_EventValue_t(adp,&(value->EventValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00066;
      return ADP_FALSE;
  }
  if(!adp_EquipmentStatusID_t(adp,&(value->EquipmentStatusID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00067;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->Reserved,7))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00068;
      return ADP_FALSE;
  }
  if(!adp_U16_t(adp,&(value->EndOfRecord)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00069;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjFileTvmBalance_t(ADP* adp,PrjFileTvmBalance_t* value)
{
  if(!adp_DeviceType_t(adp,&(value->DeviceType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006A;
      return ADP_FALSE;
  }
  if(!adp_DeviceID_t(adp,&(value->DeviceID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006B;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->Coin1ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006C;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->Coin1Value)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006D;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->Coin2ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006E;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->Coin2Value)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0006F;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->Coin3ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00070;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->Coin3Value)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00071;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->CoinCircle1ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00072;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->CoinCircle1Value)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00073;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->CoinCircle2ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00074;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->CoinCircle2Value)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00075;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->CoinCircle3ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00076;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->CoinCircle3Value)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00077;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->CoinCircle4ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00078;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->CoinCircle4Value)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00079;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->CoinCircle5ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007A;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->CoinCircle5Value)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007B;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->CoinRecoverID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007C;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->CoinRecoverValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007D;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->PaperRecoverID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007E;
      return ADP_FALSE;
  }
  if(!adp_ValueCent_t(adp,&(value->PaperRecoverValue)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0007F;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->TicketBox1ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00080;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->Quantity1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00081;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->TicketBox2ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00082;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->Quantity2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00083;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->Rest,5))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00084;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjFileBomAgBalance_t(ADP* adp,PrjFileBomAgBalance_t* value)
{
  if(!adp_DeviceType_t(adp,&(value->DeviceType)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00085;
      return ADP_FALSE;
  }
  if(!adp_DeviceID_t(adp,&(value->DeviceID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00086;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->TicketBox1ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00087;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->Quantity1)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00088;
      return ADP_FALSE;
  }
  if(!adp_U32_t(adp,&(value->TicketBox2ID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00089;
      return ADP_FALSE;
  }
  if(!adp_Quantity_t(adp,&(value->Quantity2)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008A;
      return ADP_FALSE;
  }
  if(!adp_block_t(adp,value->Rest,2))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008B;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjFileHeader_t(ADP* adp,PrjFileHeader_t* value)
{
	adp->pMsgType =(caddr_t *)(&value->FileHeaderTag.data.data);
  if(!adp_FileType_t(adp,&(value->FileHeaderTag)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008C;
      return ADP_FALSE;
  }
  if(!adp_DeviceID_t(adp,&(value->DeviceID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008D;
      return ADP_FALSE;
  }
  if(!adp_Date2_t(adp,&(value->BusinessDay)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008E;
      return ADP_FALSE;
  }
  if(!adp_TimeStamp_t(adp,&(value->FileCreationTime)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0008F;
      return ADP_FALSE;
  }
  if(!adp_SN_t(adp,&(value->FileSN)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00090;
      return ADP_FALSE;
  }
  if(!adp_VersionID_t(adp,&(value->FileFormatVersionID)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00091;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjFileBody_t(ADP* adp,PrjFileBody_t* value)
{
  if(!adp_Quantity_t(adp,&(value->RecordCount)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x00092;
      return ADP_FALSE;
  }
  switch(*(uint16_t*)adp->pMsgType)
  {
    case 0x1000:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileTran_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileTran_t),(adpproc_t)adp_PrjFileTran_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00093;
          return ADP_FALSE;
      }
      break;
    case 0x1200:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileOper_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileOper_t),(adpproc_t)adp_PrjFileOper_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00094;
          return ADP_FALSE;
      }
      break;
    case 0x2002:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileAudit_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileAudit_t),(adpproc_t)adp_PrjFileAudit_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00095;
          return ADP_FALSE;
      }
      break;
    case 0x2003:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileEvent_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileEvent_t),(adpproc_t)adp_PrjFileEvent_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00096;
          return ADP_FALSE;
      }
      break;
    case 0x2004:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileBalance_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileBalance_t),(adpproc_t)adp_PrjFileBalance_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00097;
          return ADP_FALSE;
      }
      break;
    case 0x2006:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileFTP_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileFTP_t),(adpproc_t)adp_PrjFileFTP_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00098;
          return ADP_FALSE;
      }
      break;
    case 0x2007:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileFTPDiff_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileFTPDiff_t),(adpproc_t)adp_PrjFileFTPDiff_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x00099;
          return ADP_FALSE;
      }
      break;
    case 0x2008:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileTvmBalance_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileTvmBalance_t),(adpproc_t)adp_PrjFileTvmBalance_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0009A;
          return ADP_FALSE;
      }
      break;
    case 0x2009:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileBomAgBalance_val),(unsigned int)(value->RecordCount.data.data),~0,sizeof(PrjFileBomAgBalance_t),(adpproc_t)adp_PrjFileBomAgBalance_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x0009B;
          return ADP_FALSE;
      }
      break;
  }
  return ADP_TRUE;
}

int adp_PrjFileTail_t(ADP* adp,PrjFileTail_t* value)
{
  if(!adp_MD5_t(adp,&(value->Security_Certificate)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009C;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_PrjFile_t(ADP* adp,PrjFile_t* value)
{
  if(!adp_PrjFileHeader_t(adp,&(value->PrjFileHeader)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009D;
      return ADP_FALSE;
  }
  if(!adp_PrjFileBody_t(adp,&(value->PrjFileBody)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009E;
      return ADP_FALSE;
  }
  if(!adp_PrjFileTail_t(adp,&(value->PrjFileTail)))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x0009F;
      return ADP_FALSE;
  }
  return ADP_TRUE;
}

int adp_FilesAll_t(ADP* adp,FilesAll_t* value)
{
  if(!adp_uint16_t(adp,&(value->Type),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A0;
      return ADP_FALSE;
  }
  if(!adp_uint16_t(adp,&(value->Len),2,BO_MOTO))
  {
      if (adp->iErrNo==0)
        adp->iErrNo=0x000A1;
      return ADP_FALSE;
  }
  switch(value->Type)
  {
    case 0x1000:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileTran_val),(unsigned int)(value->Len),~0,sizeof(PrjFileTran_t),(adpproc_t)adp_PrjFileTran_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x000A2;
          return ADP_FALSE;
      }
      break;
    case 0x1200:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileOper_val),(unsigned int)(value->Len),~0,sizeof(PrjFileOper_t),(adpproc_t)adp_PrjFileOper_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x000A3;
          return ADP_FALSE;
      }
      break;
    case 0x2002:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileAudit_val),(unsigned int)(value->Len),~0,sizeof(PrjFileAudit_t),(adpproc_t)adp_PrjFileAudit_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x000A4;
          return ADP_FALSE;
      }
      break;
    case 0x2003:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileEvent_val),(unsigned int)(value->Len),~0,sizeof(PrjFileEvent_t),(adpproc_t)adp_PrjFileEvent_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x000A5;
          return ADP_FALSE;
      }
      break;
    case 0x2004:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileBalance_val),(unsigned int)(value->Len),~0,sizeof(PrjFileBalance_t),(adpproc_t)adp_PrjFileBalance_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x000A6;
          return ADP_FALSE;
      }
      break;
    case 0x2006:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileFTP_val),(unsigned int)(value->Len),~0,sizeof(PrjFileFTP_t),(adpproc_t)adp_PrjFileFTP_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x000A7;
          return ADP_FALSE;
      }
      break;
    case 0x2007:
      if(!adp_array(adp,(caddr_t*)&(value->body_u.PrjFileFTPDiff_val),(unsigned int)(value->Len),~0,sizeof(PrjFileFTPDiff_t),(adpproc_t)adp_PrjFileFTPDiff_t))
      {
          if (adp->iErrNo==0)
            adp->iErrNo=0x000A8;
          return ADP_FALSE;
      }
      break;
  }
  return ADP_TRUE;
}

