/****************
*File:CzBasiType.h
*Time:20180802 161735
*Note:
*		1.以//@开头的行为标注,不可删除
*		2.建议使用单行注释
****************/
#ifndef _H_CzBasiType_
#define _H_CzBasiType_
#include "AFCDataPackComm.h"
#ifdef __cplusplus
extern "C"  {
#endif
//@BYTESEQ=BO_MOTO
//1 :not 4 bytes , 4:4 bytes
//@4BYTE=1
//0:定长 1：变长
//@LENTYPE=0

/**
	typedef uint8_t U8_t
*/
typedef struct U8_t
{ 
	uint8_t data;
}U8_t;

/**
	typedef uint16_t U16_t
*/
typedef struct U16_t
{ 
	uint16_t data;
}U16_t;

/**
	typedef uint32_t U32_t
*/
typedef struct U32_t
{ 
	uint32_t data;
}U32_t;

/**
	typedef int8_t S8_t
*/
typedef struct S8_t
{ 
	int8_t data;
}S8_t;

/**
	typedef int16_t S16_t
*/
typedef struct S16_t
{ 
	int16_t data;
}S16_t;

/**
	typedef int32_t S32_t
*/
typedef struct S32_t
{ 
	int32_t data;
}S32_t;

/**
	typedef U8_t Boolean_t
*/
typedef struct Boolean_t
{ 
	U8_t data;
}Boolean_t;

/**
	typedef S32_t ValueCent_t
*/
typedef struct ValueCent_t
{ 
	S32_t data;
}ValueCent_t;

/**
	typedef U16_t SJTValueCent_t
*/
typedef struct SJTValueCent_t
{ 
	U16_t data;
}SJTValueCent_t;

/**
	typedef S16_t MultiRideNumber_t
*/
typedef struct MultiRideNumber_t
{ 
	S16_t data;
}MultiRideNumber_t;

/**
	typedef U32_t MSecond_t
*/
typedef struct MSecond_t
{ 
	U32_t data;
}MSecond_t;

/**
	typedef U32_t Second_t
*/
typedef struct Second_t
{ 
	U32_t data;
}Second_t;

/**
	typedef U32_t TimeIntervalID_t
*/
typedef struct TimeIntervalID_t
{ 
	U32_t data;
}TimeIntervalID_t;

/**
	typedef U32_t Duration_t => U16 //mod 20180607
*/
typedef struct Duration_t
{ 
	U16_t data;
}Duration_t;

/**
	typedef U32_t UTCTime_t
*/
typedef struct UTCTime_t
{ 
	U32_t data;
}UTCTime_t;

/**
	typedef U32_t BaseTime_t
*/
typedef struct BaseTime_t
{ 
	U32_t data;
}BaseTime_t;

/**
	typedef U16_t Date2_t
*/
typedef struct Date2_t
{ 
	U16_t data;
}Date2_t;

/**
	typedef U32_t TimeStamp_t
*/
typedef struct TimeStamp_t
{ 
	U32_t data;
}TimeStamp_t;

/**
	typedef U8_t ENChar_t
*/
typedef struct ENChar_t
{ 
	U8_t data;
}ENChar_t;

/**
	typedef U16_t CNChar_t
*/
typedef struct CNChar_t
{ 
	U16_t data;
}CNChar_t;

/**
	typedef U8_t[20] Name_t
*/
typedef struct Name_t
{ 
	// U8_t[20] data;
	block_t data[20];
}Name_t;

/**
	typedef U8_t[64] LongName_t
*/
typedef struct LongName_t
{
	// U8_t[64] data;
	block_t data[64];
}LongName_t;

/**
	typedef ENChar_t[100] FileName_t
*/
typedef struct FileName_t
{ 
	// ENChar_t[100] data;
	block_t data[100];
}FileName_t;

/**
	typedef U8_t Gender_t
*/
typedef struct Gender_t
{ 
	U8_t data;
}Gender_t;

/**
	typedef U8_t Language_t
*/
typedef struct Language_t
{ 
	U8_t data;
}Language_t;

/**
	typedef U8_t Percentage_t
*/
typedef struct Percentage_t
{ 
	U8_t data;
}Percentage_t;

/**
	typedef U32_t Quantity_t
*/
typedef struct Quantity_t
{ 
	U32_t data;
}Quantity_t;

/**
	typedef U16_t MiddleQuantity_t
*/
typedef struct MiddleQuantity_t
{ 
	U16_t data;
}MiddleQuantity_t;

/**
	typedef U8_t SmallQuantity_t
*/
typedef struct SmallQuantity_t
{ 
	U8_t data;
}SmallQuantity_t;

/**
	typedef U8_t VersionType_t
*/
typedef struct VersionType_t
{ 
	U8_t data;
}VersionType_t;

/**
	typedef U16_t VersionID_t
*/
typedef struct VersionID_t
{ 
	U16_t data;
}VersionID_t;

/**
	typedef U8_t KeyVersionID_t
*/
typedef struct KeyVersionID_t
{ 
	U8_t data;
}KeyVersionID_t;

/**
	typedef U16_t LayoutVersionID_t
*/
typedef struct LayoutVersionID_t
{ 
	U16_t data;
}LayoutVersionID_t;

/**
	typedef U8_t SJTLayoutVersionID_t
*/
typedef struct SJTLayoutVersionID_t
{ 
	U8_t data;
}SJTLayoutVersionID_t;

/**
	typedef U8_t BatchCode_t
*/
typedef struct BatchCode_t
{ 
	U8_t data;
}BatchCode_t;

/**
	typedef U32_t SN_t
*/
typedef struct SN_t
{ 
	U32_t data;
}SN_t;

/**
	typedef U8_t SynchronizationType_t
*/
typedef struct SynchronizationType_t
{ 
	U8_t data;
}SynchronizationType_t;

/**
	typedef U32_t CoordinateUnit_t
*/
typedef struct CoordinateUnit_t
{ 
	U32_t data;
}CoordinateUnit_t;

/**
	typedef U32_t[4] MD5_t
*/
typedef struct MD5_t
{ 
	// U32_t[4] data;
	block_t data[16];
}MD5_t;

/**
	typedef U32_t TAC_t
*/
typedef struct TAC_t
{ 
	U32_t data;
}TAC_t;

/**
	typedef U16_t InitMAC_t
*/
typedef struct InitMAC_t
{ 
	U16_t data;
}InitMAC_t;

/**
	typedef U32_t MAC_t
*/
typedef struct MAC_t
{ 
	U32_t data;
}MAC_t;

/**
	typedef U16_t AddressPort_t
*/
typedef struct AddressPort_t
{ 
	U16_t data;
}AddressPort_t;

/**
	typedef U32_t Reserved_t
*/
typedef struct Reserved_t
{ 
	U32_t data;
}Reserved_t;

/**
	typedef U16_t CityCode_t
*/
typedef struct CityCode_t
{ 
	U16_t data;
}CityCode_t;

/**
	typedef U16_t IndustryCode_t
*/
typedef struct IndustryCode_t
{ 
	U16_t data;
}IndustryCode_t;

/**
	typedef U16_t ServiceProviderID_t
*/
typedef struct ServiceProviderID_t
{ 
	U16_t data;
}ServiceProviderID_t;

/**
	typedef U8_t ServiceProviderRoleCode_t
*/
typedef struct ServiceProviderRoleCode_t
{ 
	U8_t data;
}ServiceProviderRoleCode_t;

/**
	typedef U8_t CardFactory_t
*/
typedef struct CardFactory_t
{ 
	U8_t data;
}CardFactory_t;

/**
	typedef U8_t LineID_t
*/
typedef struct LineID_t
{ 
	U8_t data;
}LineID_t;

/**
	typedef U16_t StationID_t
*/
typedef struct StationID_t
{ 
	U16_t data;
}StationID_t;

/**
	typedef U16_t StationGlobalID_t
*/
typedef struct StationGlobalID_t
{ 
	U16_t data;
}StationGlobalID_t;

/**
	typedef U16_t SJTStationID_t
*/
typedef struct SJTStationID_t
{ 
	U16_t data;
}SJTStationID_t;

/**
	typedef U8_t StationLevel_t
*/
typedef struct StationLevel_t
{ 
	U8_t data;
}StationLevel_t;

/**
	typedef U8_t StationType_t
*/
typedef struct StationType_t
{ 
	U8_t data;
}StationType_t;

/**
	typedef U8_t TransferStationID_t
*/
typedef struct TransferStationID_t
{ 
	U8_t data;
}TransferStationID_t;

/**
	typedef U8_t ZoneID_t
*/
typedef struct ZoneID_t
{ 
	U8_t data;
}ZoneID_t;

/**
	typedef U8_t SegmentID_t
*/
typedef struct SegmentID_t
{ 
	U8_t data;
}SegmentID_t;

/**
	typedef U8_t UpDown_t
*/
typedef struct UpDown_t
{ 
	U8_t data;
}UpDown_t;

/**
	typedef U8_t SpecialDateType_t
*/
typedef struct SpecialDateType_t
{ 
	U8_t data;
}SpecialDateType_t;

/**
	typedef U8_t TimeZoneType_t
*/
typedef struct TimeZoneType_t
{ 
	U8_t data;
}TimeZoneType_t;

// /**
// 	typedef U16_t TimeIntervalID_t
// */
// typedef struct TimeIntervalID_t
// { 
// 	U16_t data;
// }TimeIntervalID_t;

/**
	typedef U8_t ValidDateType_t
*/
typedef struct ValidDateType_t
{ 
	U8_t data;
}ValidDateType_t;

/**
	typedef U8_t DurationType_t
*/
typedef struct DurationType_t
{ 
	U8_t data;
}DurationType_t;

// /**
// 	typedef U16_t Duration_t
// */
// typedef struct Duration_t
// { 
// 	U16_t data;
// }Duration_t;

/**
	typedef U8_t DeviceType_t
*/
typedef struct DeviceType_t
{ 
	U8_t data;
}DeviceType_t;

/**
	typedef U32_t DeviceID_t
*/
typedef struct DeviceID_t
{ 
	U32_t data;
}DeviceID_t;

/**
	typedef U8_t SJTDeviceID_t
*/
typedef struct SJTDeviceID_t
{ 
	U8_t data;
}SJTDeviceID_t;

/**
	typedef U32_t ModuleID_t
*/
typedef struct ModuleID_t
{ 
	U32_t data;
}ModuleID_t;

/**
	typedef U8_t EquipmentStatusID_t
*/
typedef struct EquipmentStatusID_t
{ 
	U8_t data;
}EquipmentStatusID_t;

/**
	typedef U8_t ModuleStatusID_t
*/
typedef struct ModuleStatusID_t
{ 
	U8_t data;
}ModuleStatusID_t;

/**
	typedef U8_t WorkingStatus_t
*/
typedef struct WorkingStatus_t
{ 
	U8_t data;
}WorkingStatus_t;

/**
	typedef U8_t PassageModelType_t
*/
typedef struct PassageModelType_t
{ 
	U8_t data;
}PassageModelType_t;

/**
	typedef U8_t LampColorType_t
*/
typedef struct LampColorType_t
{ 
	U8_t data;
}LampColorType_t;

/**
	typedef U8_t HZ_t
*/
typedef struct HZ_t
{ 
	U8_t data;
}HZ_t;

/**
	typedef U8_t ConcessionalLampID_t
*/
typedef struct ConcessionalLampID_t
{ 
	U8_t data;
}ConcessionalLampID_t;

/**
	typedef U8_t SoundDisplayID_t
*/
typedef struct SoundDisplayID_t
{ 
	U8_t data;
}SoundDisplayID_t;

/**
	typedef U16_t TVMInterfaceID_t
*/
typedef struct TVMInterfaceID_t
{ 
	U16_t data;
}TVMInterfaceID_t;

/**
	typedef U8_t BtnID_t
*/
typedef struct BtnID_t
{ 
	U8_t data;
}BtnID_t;

/**
	typedef U8_t TVMPicIndex_t
*/
typedef struct TVMPicIndex_t
{ 
	U8_t data;
}TVMPicIndex_t;

/**
	typedef U8_t TVMIndexType_t
*/
typedef struct TVMIndexType_t
{ 
	U8_t data;
}TVMIndexType_t;

/**
	typedef U8_t TopPanelDisplayID_t
*/
typedef struct TopPanelDisplayID_t
{ 
	U8_t data;
}TopPanelDisplayID_t;

/**
	typedef U8_t ADItemID_t
*/
typedef struct ADItemID_t
{ 
	U8_t data;
}ADItemID_t;

/**
	typedef U8_t ADPlayMeans_t
*/
typedef struct ADPlayMeans_t
{ 
	U8_t data;
}ADPlayMeans_t;

/**
	typedef U32_t ContainerID_t
*/
typedef struct ContainerID_t
{ 
	U32_t data;
}ContainerID_t;

/**
	typedef U8_t BoxOperationType_t
*/
typedef struct BoxOperationType_t
{ 
	U8_t data;
}BoxOperationType_t;

/**
	typedef U8_t BoxType_t
*/
typedef struct BoxType_t
{ 
	U8_t data;
}BoxType_t;

/**
	typedef U32_t CoinBoxID_t
*/
typedef struct CoinBoxID_t
{ 
	U32_t data;
}CoinBoxID_t;

/**
	typedef U32_t BankNoteBoxID_t
*/
typedef struct BankNoteBoxID_t
{ 
	U32_t data;
}BankNoteBoxID_t;

/**
	typedef U32_t DrumBlockID_t
*/
typedef struct DrumBlockID_t
{ 
	U32_t data;
}DrumBlockID_t;

/**
	typedef U32_t HopperID_t
*/
typedef struct HopperID_t
{ 
	U32_t data;
}HopperID_t;

/**
	typedef U32_t DeviceSoftType_t
*/
typedef struct DeviceSoftType_t
{ 
	U32_t data;
}DeviceSoftType_t;

/**
	typedef U8_t RWCommandID_t
*/
typedef struct RWCommandID_t
{ 
	U8_t data;
}RWCommandID_t;

/**
	typedef U8_t RWAnswerID_t
*/
typedef struct RWAnswerID_t
{ 
	U8_t data;
}RWAnswerID_t;

/**
	typedef U8_t PassengerTypeID_t
*/
typedef struct PassengerTypeID_t
{ 
	U8_t data;
}PassengerTypeID_t;

/**
	typedef U8_t PersonIDType_t
*/
typedef struct PersonIDType_t
{ 
	U8_t data;
}PersonIDType_t;

/**
	typedef EnChar_t[18] PersonIDSN_t
*/
typedef struct PersonIDSN_t
{ 
	// EnChar_t[18] data;
	block_t data[18];
}PersonIDSN_t;

/**
	typedef U32_t StaffID_t
*/
typedef struct StaffID_t
{ 
	U32_t data;
}StaffID_t;

/**
	typedef U8_t StaffType_t
*/
typedef struct StaffType_t
{ 
	U8_t data;
}StaffType_t;

/**
	typedef U32_t DepartmentID_t
*/
typedef struct DepartmentID_t
{ 
	U32_t data;
}DepartmentID_t;

/**
	typedef U32_t StaffBitmap_t
*/
typedef struct StaffBitmap_t
{ 
	U32_t data;
}StaffBitmap_t;

/**
	typedef U8_t AuthorityType_t
*/
typedef struct AuthorityType_t
{ 
	U8_t data;
}AuthorityType_t;

/**
	typedef U32_t Password_t
*/
typedef struct Password_t
{ 
	U32_t data;
}Password_t;

/**
	typedef U8_t ChipType_t
*/
typedef struct ChipType_t
{ 
	U8_t data;
}ChipType_t;

/**
	typedef U8_t TicketFamily_t
*/
typedef struct TicketFamily_t
{ 
	U8_t data;
}TicketFamily_t;

/**
	typedef U16_t TicketType_t
*/
typedef struct TicketType_t
{ 
	U16_t data;
}TicketType_t;

/**
	typedef U16_t MediaType_t
*/
typedef struct MediaType_t
{ 
	U16_t data;
}MediaType_t;

/**
	typedef U8_t[8] TicketLogicalID_t
*/
typedef struct TicketLogicalID_t
{ 
	// U8_t[8] data;
	block_t data[8];
}TicketLogicalID_t;

/**
	typedef U8_t[8] TicketPrintNumber_t
*/
typedef struct TicketPrintNumber_t
{ 
	// U8_t[8] data;
	block_t data[8];
}TicketPrintNumber_t;

/**
	typedef U8_t[8] TicketPhyID_t
*/
typedef struct TicketPhyID_t
{ 
	// U8_t[8] data;
	block_t data[8];
}TicketPhyID_t;

/**
	typedef Boolean_t TestFlag_t
*/
typedef struct TestFlag_t
{ 
	Boolean_t data;
}TestFlag_t;

/**
	typedef Boolean_t ActiveFlag_t
*/
typedef struct ActiveFlag_t
{ 
	Boolean_t data;
}ActiveFlag_t;

/**
	typedef Boolean_t SouvenirFlag_t
*/
typedef struct SouvenirFlag_t
{ 
	Boolean_t data;
}SouvenirFlag_t;

/**
	typedef Boolean_t SouvenirUsedFlag_t
*/
typedef struct SouvenirUsedFlag_t
{ 
	Boolean_t data;
}SouvenirUsedFlag_t;

/**
	typedef U8_t TicketFareTypeID_t
*/
typedef struct TicketFareTypeID_t
{ 
	U8_t data;
}TicketFareTypeID_t;

/**
	typedef Boolean_t EntryFlag_t
*/
typedef struct EntryFlag_t
{ 
	Boolean_t data;
}EntryFlag_t;

/**
	typedef Boolean_t ExitFlag_t
*/
typedef struct ExitFlag_t
{ 
	Boolean_t data;
}ExitFlag_t;

/**
	typedef U32_t OperationSN_t
*/
typedef struct OperationSN_t
{ 
	U32_t data;
}OperationSN_t;

/**
	typedef U8_t RenewFlag_t
*/
typedef struct RenewFlag_t
{ 
	U8_t data;
}RenewFlag_t;

/**
	typedef U8_t PenaltyCode_t
*/
typedef struct PenaltyCode_t
{ 
	U8_t data;
}PenaltyCode_t;

/**
	typedef U8_t TicketStatus_t
*/
typedef struct TicketStatus_t
{ 
	U8_t data;
}TicketStatus_t;

/**
	typedef U8_t TicketStatusFlag_t
*/
typedef struct TicketStatusFlag_t
{ 
	U8_t data;
}TicketStatusFlag_t;

/**
	typedef U8_t TicketPhyStatus_t
*/
typedef struct TicketPhyStatus_t
{ 
	U8_t data;
}TicketPhyStatus_t;

/**
	typedef Duration_t Depreciation_t
*/
typedef struct Depreciation_t
{ 
	Duration_t data;
}Depreciation_t;

/**
	typedef U16_t DepreciationPeriod_t
*/
typedef struct DepreciationPeriod_t
{ 
	U16_t data;
}DepreciationPeriod_t;

/**
	typedef U8_t Discount_t
*/
typedef struct Discount_t
{ 
	U8_t data;
}Discount_t;

/**
	typedef U8_t RefundReasonCode_t
*/
typedef struct RefundReasonCode_t
{ 
	U8_t data;
}RefundReasonCode_t;

/**
	typedef U8_t BlockCode_t
*/
typedef struct BlockCode_t
{ 
	U8_t data;
}BlockCode_t;

/**
	typedef U8_t UnBlockCode_t
*/
typedef struct UnBlockCode_t
{ 
	U8_t data;
}UnBlockCode_t;

/**
	typedef U8_t TPFlag_t
*/
typedef struct TPFlag_t
{ 
	U8_t data;
}TPFlag_t;

/**
	typedef U8_t ChargingMode_t
*/
typedef struct ChargingMode_t
{ 
	U8_t data;
}ChargingMode_t;

/**
	typedef U8_t FareType_t
*/
typedef struct FareType_t
{ 
	U8_t data;
}FareType_t;

/**
	typedef U8_t FareRate_t
*/
typedef struct FareRate_t
{ 
	U8_t data;
}FareRate_t;

/**
	typedef U8_t FareGroup_t
*/
typedef struct FareGroup_t
{ 
	U8_t data;
}FareGroup_t;

/**
	typedef U8_t SalePriceMode_t
*/
typedef struct SalePriceMode_t
{ 
	U8_t data;
}SalePriceMode_t;

/**
	typedef U8_t AddValueCode_t
*/
typedef struct AddValueCode_t
{ 
	U8_t data;
}AddValueCode_t;

/**
	typedef U8_t FavourID_t
*/
typedef struct FavourID_t
{ 
	U8_t data;
}FavourID_t;

/**
	typedef U8_t ConcessionType_t
*/
typedef struct ConcessionType_t
{ 
	U8_t data;
}ConcessionType_t;

/**
	typedef U8_t BonusPointsID_t
*/
typedef struct BonusPointsID_t
{ 
	U8_t data;
}BonusPointsID_t;

/**
	typedef U16_t OperationMode_t
*/
typedef struct OperationMode_t
{ 
	U16_t data;
}OperationMode_t;

/**
	typedef U8_t UrgencyMode_t
*/
typedef struct UrgencyMode_t
{ 
	U8_t data;
}UrgencyMode_t;

/**
	typedef U16_t TransactionType_t
*/
typedef struct TransactionType_t
{ 
	U16_t data;
}TransactionType_t;

/**
	typedef U8_t CoinTrasactionSubType_t
*/
typedef struct CoinTrasactionSubType_t
{ 
	U8_t data;
}CoinTrasactionSubType_t;

/**
	typedef U8_t BankNoteTrsactionSubType_t
*/
typedef struct BankNoteTrsactionSubType_t
{ 
	U8_t data;
}BankNoteTrsactionSubType_t;

/**
	typedef U8_t ContainerTrasactionSubType_t
*/
typedef struct ContainerTrasactionSubType_t
{ 
	U8_t data;
}ContainerTrasactionSubType_t;

/**
	typedef U8_t PullPushReason_t
*/
typedef struct PullPushReason_t
{ 
	U8_t data;
}PullPushReason_t;

/**
	typedef U8_t RecycleSelect_t
*/
typedef struct RecycleSelect_t
{ 
	U8_t data;
}RecycleSelect_t;

/**
	typedef U16_t ARType_t
*/
typedef struct ARType_t
{ 
	U16_t data;
}ARType_t;

/**
	typedef U16_t EventID_t
*/
typedef struct EventID_t
{ 
	U16_t data;
}EventID_t;

/**
	typedef U32_t EventValue_t
*/
typedef struct EventValue_t
{ 
	U32_t data;
}EventValue_t;

/**
	typedef U16_t MessageType_t
*/
typedef struct MessageType_t
{ 
	U16_t data;
}MessageType_t;

/**
	typedef U8_t MACK_t
*/
typedef struct MACK_t
{ 
	U8_t data;
}MACK_t;

/**
	typedef U8_t PaymentMeans_t
*/
typedef struct PaymentMeans_t
{ 
	U8_t data;
}PaymentMeans_t;

/**
	typedef U8_t RefundType_t
*/
typedef struct RefundType_t
{ 
	U8_t data;
}RefundType_t;

/**
	typedef U8_t BOMShiftID_t
*/
typedef struct BOMShiftID_t
{ 
	U8_t data;
}BOMShiftID_t;

/**
	typedef U8_t RejectCode_t
*/
typedef struct RejectCode_t
{ 
	U8_t data;
}RejectCode_t;

/**
	typedef U8_t[8] SAMID_t
*/
typedef struct SAMID_t
{ 
	// U8_t[8] data;
	block_t data[8];
}SAMID_t;

/**
	typedef U8_t SAMType_t
*/
typedef struct SAMType_t
{ 
	U8_t data;
}SAMType_t;

/**
	typedef U32_t SAMPPSValue_t
*/
typedef struct SAMPPSValue_t
{ 
	U32_t data;
}SAMPPSValue_t;

/**
	typedef U32_t ePurseSN_t
*/
typedef struct ePurseSN_t
{ 
	U32_t data;
}ePurseSN_t;

/**
	typedef U16_t FileType_t
*/
typedef struct FileType_t
{ 
	U16_t data;
}FileType_t;

/**
	typedef U8_t ParamType_t
*/
typedef struct ParamType_t
{ 
	U8_t data;
}ParamType_t;

/**
	typedef U32_t DisposeCode_t
*/
typedef struct DisposeCode_t
{ 
	U32_t data;
}DisposeCode_t;

/**
	typedef U8_t FileTag_t
*/
typedef struct FileTag_t
{ 
	U8_t data;
}FileTag_t;

/**
	typedef U8_t EntryExitBit_t
*/
typedef struct EntryExitBit_t
{ 
	U8_t data;
}EntryExitBit_t;

/**
	typedef U32_t LastRideID_t
*/
typedef struct LastRideID_t
{ 
	U32_t data;
}LastRideID_t;

/**
	typedef S32_t ReceiptNumber_t
*/
typedef struct ReceiptNumber_t
{ 
	S32_t data;
}ReceiptNumber_t;

/**
	typedef U8_t CardClass_t
*/
typedef struct CardClass_t
{ 
	U8_t data;
}CardClass_t;

/**
	typedef U8_t CardVersion_t
*/
typedef struct CardVersion_t
{ 
	U8_t data;
}CardVersion_t;

/**
	typedef U8_t YKTKeyIndex_t
*/
typedef struct YKTKeyIndex_t
{ 
	U8_t data;
}YKTKeyIndex_t;

/**
	typedef U8_t CardRandomData_t
*/
typedef struct CardRandomData_t
{ 
	U8_t data;
}CardRandomData_t;

/**
	typedef U8_t TradeTransactionType_t
*/
typedef struct TradeTransactionType_t
{ 
	U8_t data;
}TradeTransactionType_t;

/**
	typedef U8_t[8] YKTSAMID_t
*/
typedef struct YKTSAMID_t
{ 
	// U8_t[8] data;
	block_t data[8];
}YKTSAMID_t;

/**
	typedef U16_t YKTSAMKeyVersion_t
*/
typedef struct YKTSAMKeyVersion_t
{ 
	U16_t data;
}YKTSAMKeyVersion_t;

/**
	typedef U8_t YKTPosSeq_t
*/
typedef struct YKTPosSeq_t
{ 
	U8_t data;
}YKTPosSeq_t;

/**
	typedef U8_t YKTDivfactor_t
*/
typedef struct YKTDivfactor_t
{ 
	U8_t data;
}YKTDivfactor_t;

/**
	typedef U8_t YKTTradeIndex_t
*/
typedef struct YKTTradeIndex_t
{ 
	U8_t data;
}YKTTradeIndex_t;

/**
	typedef U8_t YKTTRDType_t
*/
typedef struct YKTTRDType_t
{ 
	U8_t data;
}YKTTRDType_t;

/**
	typedef U8_t YKTTAppChildType_t
*/
typedef struct YKTTAppChildType_t
{ 
	U8_t data;
}YKTTAppChildType_t;

/**
	typedef U8_t YPTCPUKeyIndex_t
*/
typedef struct YPTCPUKeyIndex_t
{ 
	U8_t data;
}YPTCPUKeyIndex_t;

/**
	typedef U8_t YPTCPUTRDTypex_t
*/
typedef struct YPTCPUTRDTypex_t
{ 
	U8_t data;
}YPTCPUTRDTypex_t;

/**
	typedef U16_t YPTCPUSAMKeyVersion_t
*/
typedef struct YPTCPUSAMKeyVersion_t
{ 
	U16_t data;
}YPTCPUSAMKeyVersion_t;

/**
	typedef U32_t YPTPSAMSeq_t
*/
typedef struct YPTPSAMSeq_t
{ 
	U32_t data;
}YPTPSAMSeq_t;




int adp_U8_t(ADP* adp,U8_t* value);
int adp_U16_t(ADP* adp,U16_t* value);
int adp_U32_t(ADP* adp,U32_t* value);
int adp_S8_t(ADP* adp,S8_t* value);
int adp_S16_t(ADP* adp,S16_t* value);
int adp_S32_t(ADP* adp,S32_t* value);
int adp_Boolean_t(ADP* adp,Boolean_t* value);
int adp_ValueCent_t(ADP* adp,ValueCent_t* value);
int adp_SJTValueCent_t(ADP* adp,SJTValueCent_t* value);
int adp_MultiRideNumber_t(ADP* adp,MultiRideNumber_t* value);
int adp_MSecond_t(ADP* adp,MSecond_t* value);
int adp_Second_t(ADP* adp,Second_t* value);
int adp_TimeIntervalID_t(ADP* adp,TimeIntervalID_t* value);
int adp_Duration_t(ADP* adp,Duration_t* value);
int adp_UTCTime_t(ADP* adp,UTCTime_t* value);
int adp_BaseTime_t(ADP* adp,BaseTime_t* value);
int adp_Date2_t(ADP* adp,Date2_t* value);
int adp_TimeStamp_t(ADP* adp,TimeStamp_t* value);
int adp_ENChar_t(ADP* adp,ENChar_t* value);
int adp_CNChar_t(ADP* adp,CNChar_t* value);
int adp_Name_t(ADP* adp,Name_t* value);
int adp_LongName_t(ADP* adp,LongName_t* value);
int adp_FileName_t(ADP* adp,FileName_t* value);
int adp_Gender_t(ADP* adp,Gender_t* value);
int adp_Language_t(ADP* adp,Language_t* value);
int adp_Percentage_t(ADP* adp,Percentage_t* value);
int adp_Quantity_t(ADP* adp,Quantity_t* value);
int adp_MiddleQuantity_t(ADP* adp,MiddleQuantity_t* value);
int adp_SmallQuantity_t(ADP* adp,SmallQuantity_t* value);
int adp_VersionType_t(ADP* adp,VersionType_t* value);
int adp_VersionID_t(ADP* adp,VersionID_t* value);
int adp_KeyVersionID_t(ADP* adp,KeyVersionID_t* value);
int adp_LayoutVersionID_t(ADP* adp,LayoutVersionID_t* value);
int adp_SJTLayoutVersionID_t(ADP* adp,SJTLayoutVersionID_t* value);
int adp_BatchCode_t(ADP* adp,BatchCode_t* value);
int adp_SN_t(ADP* adp,SN_t* value);
int adp_SynchronizationType_t(ADP* adp,SynchronizationType_t* value);
int adp_CoordinateUnit_t(ADP* adp,CoordinateUnit_t* value);
int adp_MD5_t(ADP* adp,MD5_t* value);
int adp_TAC_t(ADP* adp,TAC_t* value);
int adp_InitMAC_t(ADP* adp,InitMAC_t* value);
int adp_MAC_t(ADP* adp,MAC_t* value);
int adp_AddressPort_t(ADP* adp,AddressPort_t* value);
int adp_Reserved_t(ADP* adp,Reserved_t* value);
int adp_CityCode_t(ADP* adp,CityCode_t* value);
int adp_IndustryCode_t(ADP* adp,IndustryCode_t* value);
int adp_ServiceProviderID_t(ADP* adp,ServiceProviderID_t* value);
int adp_ServiceProviderRoleCode_t(ADP* adp,ServiceProviderRoleCode_t* value);
int adp_CardFactory_t(ADP* adp,CardFactory_t* value);
int adp_LineID_t(ADP* adp,LineID_t* value);
int adp_StationID_t(ADP* adp,StationID_t* value);
int adp_StationGlobalID_t(ADP* adp,StationGlobalID_t* value);
int adp_SJTStationID_t(ADP* adp,SJTStationID_t* value);
int adp_StationLevel_t(ADP* adp,StationLevel_t* value);
int adp_StationType_t(ADP* adp,StationType_t* value);
int adp_TransferStationID_t(ADP* adp,TransferStationID_t* value);
int adp_ZoneID_t(ADP* adp,ZoneID_t* value);
int adp_SegmentID_t(ADP* adp,SegmentID_t* value);
int adp_UpDown_t(ADP* adp,UpDown_t* value);
int adp_SpecialDateType_t(ADP* adp,SpecialDateType_t* value);
int adp_TimeZoneType_t(ADP* adp,TimeZoneType_t* value);
int adp_ValidDateType_t(ADP* adp,ValidDateType_t* value);
int adp_DurationType_t(ADP* adp,DurationType_t* value);
int adp_DeviceType_t(ADP* adp,DeviceType_t* value);
int adp_DeviceID_t(ADP* adp,DeviceID_t* value);
int adp_SJTDeviceID_t(ADP* adp,SJTDeviceID_t* value);
int adp_ModuleID_t(ADP* adp,ModuleID_t* value);
int adp_EquipmentStatusID_t(ADP* adp,EquipmentStatusID_t* value);
int adp_ModuleStatusID_t(ADP* adp,ModuleStatusID_t* value);
int adp_WorkingStatus_t(ADP* adp,WorkingStatus_t* value);
int adp_PassageModelType_t(ADP* adp,PassageModelType_t* value);
int adp_LampColorType_t(ADP* adp,LampColorType_t* value);
int adp_HZ_t(ADP* adp,HZ_t* value);
int adp_ConcessionalLampID_t(ADP* adp,ConcessionalLampID_t* value);
int adp_SoundDisplayID_t(ADP* adp,SoundDisplayID_t* value);
int adp_TVMInterfaceID_t(ADP* adp,TVMInterfaceID_t* value);
int adp_BtnID_t(ADP* adp,BtnID_t* value);
int adp_TVMPicIndex_t(ADP* adp,TVMPicIndex_t* value);
int adp_TVMIndexType_t(ADP* adp,TVMIndexType_t* value);
int adp_TopPanelDisplayID_t(ADP* adp,TopPanelDisplayID_t* value);
int adp_ADItemID_t(ADP* adp,ADItemID_t* value);
int adp_ADPlayMeans_t(ADP* adp,ADPlayMeans_t* value);
int adp_ContainerID_t(ADP* adp,ContainerID_t* value);
int adp_BoxOperationType_t(ADP* adp,BoxOperationType_t* value);
int adp_BoxType_t(ADP* adp,BoxType_t* value);
int adp_CoinBoxID_t(ADP* adp,CoinBoxID_t* value);
int adp_BankNoteBoxID_t(ADP* adp,BankNoteBoxID_t* value);
int adp_DrumBlockID_t(ADP* adp,DrumBlockID_t* value);
int adp_HopperID_t(ADP* adp,HopperID_t* value);
int adp_DeviceSoftType_t(ADP* adp,DeviceSoftType_t* value);
int adp_RWCommandID_t(ADP* adp,RWCommandID_t* value);
int adp_RWAnswerID_t(ADP* adp,RWAnswerID_t* value);
int adp_PassengerTypeID_t(ADP* adp,PassengerTypeID_t* value);
int adp_PersonIDType_t(ADP* adp,PersonIDType_t* value);
int adp_PersonIDSN_t(ADP* adp,PersonIDSN_t* value);
int adp_StaffID_t(ADP* adp,StaffID_t* value);
int adp_StaffType_t(ADP* adp,StaffType_t* value);
int adp_DepartmentID_t(ADP* adp,DepartmentID_t* value);
int adp_StaffBitmap_t(ADP* adp,StaffBitmap_t* value);
int adp_AuthorityType_t(ADP* adp,AuthorityType_t* value);
int adp_Password_t(ADP* adp,Password_t* value);
int adp_ChipType_t(ADP* adp,ChipType_t* value);
int adp_TicketFamily_t(ADP* adp,TicketFamily_t* value);
int adp_TicketType_t(ADP* adp,TicketType_t* value);
int adp_MediaType_t(ADP* adp,MediaType_t* value);
int adp_TicketLogicalID_t(ADP* adp,TicketLogicalID_t* value);
int adp_TicketPrintNumber_t(ADP* adp,TicketPrintNumber_t* value);
int adp_TicketPhyID_t(ADP* adp,TicketPhyID_t* value);
int adp_TestFlag_t(ADP* adp,TestFlag_t* value);
int adp_ActiveFlag_t(ADP* adp,ActiveFlag_t* value);
int adp_SouvenirFlag_t(ADP* adp,SouvenirFlag_t* value);
int adp_SouvenirUsedFlag_t(ADP* adp,SouvenirUsedFlag_t* value);
int adp_TicketFareTypeID_t(ADP* adp,TicketFareTypeID_t* value);
int adp_EntryFlag_t(ADP* adp,EntryFlag_t* value);
int adp_ExitFlag_t(ADP* adp,ExitFlag_t* value);
int adp_OperationSN_t(ADP* adp,OperationSN_t* value);
int adp_RenewFlag_t(ADP* adp,RenewFlag_t* value);
int adp_PenaltyCode_t(ADP* adp,PenaltyCode_t* value);
int adp_TicketStatus_t(ADP* adp,TicketStatus_t* value);
int adp_TicketStatusFlag_t(ADP* adp,TicketStatusFlag_t* value);
int adp_TicketPhyStatus_t(ADP* adp,TicketPhyStatus_t* value);
int adp_Depreciation_t(ADP* adp,Depreciation_t* value);
int adp_DepreciationPeriod_t(ADP* adp,DepreciationPeriod_t* value);
int adp_Discount_t(ADP* adp,Discount_t* value);
int adp_RefundReasonCode_t(ADP* adp,RefundReasonCode_t* value);
int adp_BlockCode_t(ADP* adp,BlockCode_t* value);
int adp_UnBlockCode_t(ADP* adp,UnBlockCode_t* value);
int adp_TPFlag_t(ADP* adp,TPFlag_t* value);
int adp_ChargingMode_t(ADP* adp,ChargingMode_t* value);
int adp_FareType_t(ADP* adp,FareType_t* value);
int adp_FareRate_t(ADP* adp,FareRate_t* value);
int adp_FareGroup_t(ADP* adp,FareGroup_t* value);
int adp_SalePriceMode_t(ADP* adp,SalePriceMode_t* value);
int adp_AddValueCode_t(ADP* adp,AddValueCode_t* value);
int adp_FavourID_t(ADP* adp,FavourID_t* value);
int adp_ConcessionType_t(ADP* adp,ConcessionType_t* value);
int adp_BonusPointsID_t(ADP* adp,BonusPointsID_t* value);
int adp_OperationMode_t(ADP* adp,OperationMode_t* value);
int adp_UrgencyMode_t(ADP* adp,UrgencyMode_t* value);
int adp_TransactionType_t(ADP* adp,TransactionType_t* value);
int adp_CoinTrasactionSubType_t(ADP* adp,CoinTrasactionSubType_t* value);
int adp_BankNoteTrsactionSubType_t(ADP* adp,BankNoteTrsactionSubType_t* value);
int adp_ContainerTrasactionSubType_t(ADP* adp,ContainerTrasactionSubType_t* value);
int adp_PullPushReason_t(ADP* adp,PullPushReason_t* value);
int adp_RecycleSelect_t(ADP* adp,RecycleSelect_t* value);
int adp_ARType_t(ADP* adp,ARType_t* value);
int adp_EventID_t(ADP* adp,EventID_t* value);
int adp_EventValue_t(ADP* adp,EventValue_t* value);
int adp_MessageType_t(ADP* adp,MessageType_t* value);
int adp_MACK_t(ADP* adp,MACK_t* value);
int adp_PaymentMeans_t(ADP* adp,PaymentMeans_t* value);
int adp_RefundType_t(ADP* adp,RefundType_t* value);
int adp_BOMShiftID_t(ADP* adp,BOMShiftID_t* value);
int adp_RejectCode_t(ADP* adp,RejectCode_t* value);
int adp_SAMID_t(ADP* adp,SAMID_t* value);
int adp_SAMType_t(ADP* adp,SAMType_t* value);
int adp_SAMPPSValue_t(ADP* adp,SAMPPSValue_t* value);
int adp_ePurseSN_t(ADP* adp,ePurseSN_t* value);
int adp_FileType_t(ADP* adp,FileType_t* value);
int adp_ParamType_t(ADP* adp,ParamType_t* value);
int adp_DisposeCode_t(ADP* adp,DisposeCode_t* value);
int adp_FileTag_t(ADP* adp,FileTag_t* value);
int adp_EntryExitBit_t(ADP* adp,EntryExitBit_t* value);
int adp_LastRideID_t(ADP* adp,LastRideID_t* value);
int adp_ReceiptNumber_t(ADP* adp,ReceiptNumber_t* value);
int adp_CardClass_t(ADP* adp,CardClass_t* value);
int adp_CardVersion_t(ADP* adp,CardVersion_t* value);
int adp_YKTKeyIndex_t(ADP* adp,YKTKeyIndex_t* value);
int adp_CardRandomData_t(ADP* adp,CardRandomData_t* value);
int adp_TradeTransactionType_t(ADP* adp,TradeTransactionType_t* value);
int adp_YKTSAMID_t(ADP* adp,YKTSAMID_t* value);
int adp_YKTSAMKeyVersion_t(ADP* adp,YKTSAMKeyVersion_t* value);
int adp_YKTPosSeq_t(ADP* adp,YKTPosSeq_t* value);
int adp_YKTDivfactor_t(ADP* adp,YKTDivfactor_t* value);
int adp_YKTTradeIndex_t(ADP* adp,YKTTradeIndex_t* value);
int adp_YKTTRDType_t(ADP* adp,YKTTRDType_t* value);
int adp_YKTTAppChildType_t(ADP* adp,YKTTAppChildType_t* value);
int adp_YPTCPUKeyIndex_t(ADP* adp,YPTCPUKeyIndex_t* value);
int adp_YPTCPUTRDTypex_t(ADP* adp,YPTCPUTRDTypex_t* value);
int adp_YPTCPUSAMKeyVersion_t(ADP* adp,YPTCPUSAMKeyVersion_t* value);
int adp_YPTPSAMSeq_t(ADP* adp,YPTPSAMSeq_t* value);
#ifdef __cplusplus
}
#endif
#endif
