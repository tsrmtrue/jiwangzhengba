#ifndef __PROTOCOLS_H__
#define	__PROTOCOLS_H__

enum EProtocolVersion
{
	E_PROTOCOL_NOW = 0x1e, //当前版本2013-10-16,正式1.5版本
};

enum EProtocolId
{
	Protocol_Start,

	//版本号校验,这两个协议都必须是二进制格式coding。
	S_2_C_Protocol_Version_Ntf, //SProtocolVersionNtf
	C_2_S_Protocol_Type_Rpt, //SProtocolTypeRpt，当要使用json协议格式的时候，可以发这个正常流程可以不发 
	S_2_C_Protocol_Type_Rsp, //SProtocolTypeRsp，当可以用的时候,服务器返回下0.

	S_2_C_AllRoom_List_Ntf, //SAllroomListNtf，所有房间的列表
	C_2_S_EnterRoom_By_ID_Ask,	//SEnterRoomByIDAsk，进入指定id的房间
	S_2_C_EnterRoom_By_ID_Rsp,  //SEnterRoomByIDRsp，返回房间内的信息

	C_2_S_Objects_Action_Ask,	//SObjectsActionAsk，进入指定id的房间
	S_2_C_Objects_Action_Rsp,	//SObjectsActionRsp，返回房间内的信息

};

struct SProtocolHead
{
	short totalLength;
	short protocolId;
	int	  debugIndex;
};

struct SBasicRoleInfo
{
	unsigned int userid;
	int guid;
	unsigned int showLevel;  //参见EShowLevel。
	unsigned int mateid;
	char macAddress[20];
	char rolename[64];
	int level;
	int professionId;
	int exp;
	int popularity;
	int expTotal;
	int diamond[2];
	int money;
	int exploit; //功勋
	int vigor; //体力
	int vigorMax; //体力上限
	int leaderForce; //领导力
	int killingValue;//杀戮值
	int halliconId; //主城头像
	float f;
	short te;
	unsigned short tes;
	char c;
	unsigned char uc;
	long long ll;
	unsigned long long ull;
};


struct SProtocolVersionNtf
{
	int version;
};

struct SProtocolTypeRpt
{
	int type;
};
struct SProtocolTypeRsp
{
	char rsp[32];
};

struct SAllroomListNtf
{
	unsigned int roomids[30];
};

struct SEnterRoomByIDAsk
{
	unsigned int roomid;
};

struct SEnterRoomByIDRsp
{
	int i;
	SBasicRoleInfo s[2/*i*/];
	float f;
};

enum EObjectAction
{
	E_ObjectAction_Enter,		//对象进入场景
	E_ObjectAction_Leave,		//对象消除
	E_ObjectAction_Move_Start,	//开始移动
	E_ObjectAction_Move_Stop,	//停止移动
	E_ObjectAction_Died,		//对象死亡
	E_ObjectAction_Reborn,		//对象复活
	E_ObjectAction_UseSkill,	//使用技能
	E_ObjectAction_TakeHurt,	//掉血
};

struct SObjectMoveInfo
{
	float pos_x;	//坐标
	float pos_y;
	float pos_z;
	float dir_x;	//方向
	float dir_y;
	float dir_z;
};

struct SObjectAction
{
	unsigned int objID;
	SObjectMoveInfo minfo;
	unsigned short action;//EObjectAction
};

struct SObjectActions
{
	int count;
	SObjectAction a[30/*count*/];
};

struct SObjectsActionAsk
{
	SObjectActions oas;
};

struct SObjectsActionRsp
{
	SObjectActions oas;
};

#endif	//__PROTOCOLS_H__
