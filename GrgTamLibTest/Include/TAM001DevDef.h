/////////////////////////////////////////////////////
//
//	TAM001DevDef.h
//

#ifndef _TAM001DEVDEF_H_
#define _TAM001DEVDEF_H_


#define  W_TAM001_BASE								47300							// 警告码基址

#define  E_TAM001_BASE								W_TAM001_BASE +	20				// 错误码基址


#define  W_TAM001_SLOT_WITH_CARD					(W_TAM001_BASE + 1)				//47301 插卡口位置有卡
#define  W_TAM001_CARD_READER_WITH_CARD				(W_TAM001_BASE + 2)				//47302 读卡器位置有卡
#define  W_TAM001_CARD_READ_AREA_WITHOUT_CARD		(W_TAM001_BASE + 3)				//47303 读卡区无卡
#define  W_TAM001_CARD_BOX_A_NEAR_FULL				(W_TAM001_BASE + 4)				//47304 卡箱A 将满
#define  W_TAM001_CARD_BOX_A_FULL					(W_TAM001_BASE + 5)				//47305 卡箱A 满
#define  W_TAM001_CARD_BOX_B_NEAR_FULL				(W_TAM001_BASE + 6)				//47306 卡箱B 将满
#define  W_TAM001_CARD_BOX_B_FULL					(W_TAM001_BASE + 7)				//47307 卡箱B 满
#define  W_TAM001_CARD_BOX_A_UNEXIST				(W_TAM001_BASE + 8)				//47308 卡箱A 不存在警告
#define  W_TAM001_CARD_BOX_B_UNEXIST				(W_TAM001_BASE + 9)				//47309 卡箱B 不存在警告


#define  E_TAM001_COMMAND_INVALID					(E_TAM001_BASE + 1)				//47321 无效命令 
#define  E_TAM001_PARAMETER							(E_TAM001_BASE + 2)				//47322 无效参数 

#define  E_TAM001_CARD_BOXS_AVAILABLE				(E_TAM001_BASE + 3) 			//47323 无可用卡箱回收票卡

#define  E_TAM001_SENSOR_IN_SLOT					(E_TAM001_BASE + 4)				//47324 入口处传感器故障
#define  E_TAM001_SENSOR_REJECT_PAS					(E_TAM001_BASE + 5)				//47325 废票箱上部通道处传感器故障
#define  E_TAM001_SENSOR_BOX_A_PAS					(E_TAM001_BASE + 6)				//47326 卡箱A上部处传感器故障
#define  E_TAM001_SENSOR_BOX_B_PAS					(E_TAM001_BASE + 7)				//47327 卡箱B上部处传感器故障
#define  E_TAM001_SENSOR_IN_REJECT_BOX				(E_TAM001_BASE + 8)				//47328 废票箱处传感器故障
#define  E_TAM001_SENSOR_IN_BOX_A					(E_TAM001_BASE + 9)				//47329 卡箱A处传感器故障
#define  E_TAM001_SENSOR_IN_BOX_B					(E_TAM001_BASE + 10)			//47330 卡箱B处传感器故障

#define  E_TAM001_STUCK_IN_SENSOR_CIS				(E_TAM001_BASE + 11)			//47331 CIS 传感器位置卡票
#define  E_TAM001_STUCK_BETWEEN_CIS_RPS				(E_TAM001_BASE + 12)			//47332 CIS 到RPS 之间卡票
#define  E_TAM001_STUCK_IN_SENSOR_RPS				(E_TAM001_BASE + 13)			//47333 RPS 传感器位置卡票
#define  E_TAM001_STUCK_BETWEEN_RPS_CAES			(E_TAM001_BASE + 14)			//47334 RPS 到CAES 之间卡票
#define  E_TAM001_STUCK_IN_SENSOR_CAES				(E_TAM001_BASE + 15)			//47335 CAES 传感器位置卡票
#define  E_TAM001_STUCK_BETWEEN_CAES_CCAS			(E_TAM001_BASE + 16)			//47336 CAES 到CCAS 之间卡票
#define  E_TAM001_STUCK_IN_SENSOR_CCAS				(E_TAM001_BASE + 17)			//47337 CCAS 传感器位置卡票
#define  E_TAM001_STUCK_BETWEEN_CCAS_TAPS			(E_TAM001_BASE + 18)			//47338 CCAS 到TAPS 之间卡票
#define  E_TAM001_STUCK_IN_SENSOR_TAPS				(E_TAM001_BASE + 19)			//47339 TAPS 传感器位置卡票
#define  E_TAM001_STUCK_BETWEEN_RPS_CBES			(E_TAM001_BASE + 20)			//47340 RPS 到CBES 之间卡票
#define  E_TAM001_STUCK_IN_SENSOR_CBES				(E_TAM001_BASE + 21)			//47341 CBES 传感器位置卡票
#define  E_TAM001_STUCK_BETWEEN_CBES_CCBS			(E_TAM001_BASE + 22)			//47342 CBES 到CCBS 之间卡票
#define  E_TAM001_STUCK_IN_SENSOR_CCBS				(E_TAM001_BASE + 23)			//47343 CCBS 传感器位置卡票
#define  E_TAM001_STUCK_BETWEEN_CCBS_TBPS			(E_TAM001_BASE + 24)			//47344 CCBS 到TBPS 之间卡票
#define  E_TAM001_STUCK_IN_SENSOR_TBPS				(E_TAM001_BASE + 25)			//47345 TBPS 传感器位置卡票
#define  E_TAM001_STUCK_IN_SENSOR_UCCS				(E_TAM001_BASE + 26)			//47346 UCCS 传感器位置卡票

//#define  0x81 参数错
#define  E_TAM001_CARD_BOX_A_ROUTER_OPEN			(E_TAM001_BASE + 27)			//47347 卡箱A上部换向器无法打开、或换向器传感器故障
#define  E_TAM001_CARD_BOX_A_ROUTER_CLOSE			(E_TAM001_BASE + 28)			//47348 卡箱A上部换向器无法关闭，或换向器传感器故障
#define  E_TAM001_SHUTTER_OPEN						(E_TAM001_BASE + 29)			//47349 闸门无法打开，或闸门传感器错
#define  E_TAM001_SHUTTER_CLOSE						(E_TAM001_BASE + 30)			//47350 闸门无法关闭，或闸门传感器错
#define  E_TAM001_CARD_BOX_A_UNEXIST				(E_TAM001_BASE + 31)			//47351 卡箱A 不存在
#define  E_TAM001_CARD_BOX_B_UNEXIST				(E_TAM001_BASE + 32)			//47352 卡箱B 不存在
#define  E_TAM001_REJECT_BOX_UNEXIST				(E_TAM001_BASE + 33)			//47353 废卡箱不存在
#define  E_TAM001_CARD_BOX_A_LID_UNOPEN				(E_TAM001_BASE + 34)			//47354 卡箱A 上盖没打开
#define  E_TAM001_CARD_BOX_B_LID_UNOPEN				(E_TAM001_BASE + 35)			//47355 卡箱B 上盖没打开
#define  E_TAM001_REJECT_BOX_LID_UNOPEN				(E_TAM001_BASE + 36)			//47356 废卡箱上盖没打开
#define  E_TAM001_TRAY_A_ASCEND_IN_PLACE			(E_TAM001_BASE + 37)			//47357 托盘A 不能上升到位
#define  E_TAM001_TRAY_A_DESCEND_IN_PLACE			(E_TAM001_BASE + 38)			//47358 托盘A 不能下降到位
#define  E_TAM001_TRAY_B_ASCEND_IN_PLACE			(E_TAM001_BASE + 39)			//47359 托盘B 不能上升到位
#define  E_TAM001_TRAY_B_DESCEND_IN_PLACE			(E_TAM001_BASE + 40)			//47360 托盘B 不能下降到位
#define  E_TAM001_RETURN_CARD						(E_TAM001_BASE + 41)			//47361 退卡错
#define  E_TAM001_INIT								(E_TAM001_BASE + 42)			//47362 初始化错（除以列出的错误外）
#define  E_TAM001_INIT_TRAY_A						(E_TAM001_BASE + 43)			//47363 托盘A 初始化出错
#define  E_TAM001_INIT_TRAY_B						(E_TAM001_BASE + 44)			//47364 托盘B 初始化出错
#define  E_TAM001_CARD_BOX_A_FULL					(E_TAM001_BASE + 45)			//47365 回收卡错，卡箱A 满
#define  E_TAM001_CARD_BOX_B_FULL					(E_TAM001_BASE + 46)			//47366 回收卡错，卡箱B 满
#define  E_TAM001_REJECT_BOX_FULL					(E_TAM001_BASE + 47)			//47367 回收卡错，废卡箱满
#define	 E_TAM001_REJECT_BOX_ROUTER_OPEN			(E_TAM001_BASE + 48)			//47368 废卡箱换向器无法打开，或传感器错
#define  E_TAM001_REJECT_BOX_ROUTER_CLOSE			(E_TAM001_BASE + 49)			//47369 废卡箱换向器无法关闭，或传感器错
#define  E_TAM001_NO_BOX_RFID						(E_TAM001_BASE + 50)			//47370 无法检测到票箱的RFID卡
#define  E_TAM001_RW_BOX_RFID						(E_TAM001_BASE + 51)			//47371 读写卡箱RFID 错

#define  E_TAM001_INVALIDHANDLE						(E_TAM001_BASE + 68)			//47388	无效句柄
#define  E_TAM001_TOO_MANY_DEVICES					(E_TAM001_BASE + 69)			//47389 打开的设备太多

// COMMUNIATION ERROR
#define E_TAM001_OTHER								(E_TAM001_BASE + 70)			//47390 未知错 

#define E_TAM001_CFG	    						(E_TAM001_BASE + 72)			//47392 读写配置文件错        
#define E_TAM001_SETCOM	    						(E_TAM001_BASE + 73)			//47393 串口配置错             
#define E_TAM001_RECEIVE_NAK						(E_TAM001_BASE + 74)			//47394 收到NAK,发送数据有错
#define E_TAM001_REVDATA_ERROR						(E_TAM001_BASE + 75)			//47395 接收到的数据有误      
#define E_TAM001_SENDENQ_ERROR	 					(E_TAM001_BASE + 76)			//47396 发送ENQ出错            
#define E_TAM001_SENDCMD_ERROR						(E_TAM001_BASE + 77)			//47397 发送命令错              
#define E_TAM001_WAITACK_TIMEOUT					(E_TAM001_BASE + 78)			//47398 等待ACK超时            
#define E_TAM001_WAITRSP_TIMEOUT					(E_TAM001_BASE + 79)			//47399 等待响应超时

#endif





















