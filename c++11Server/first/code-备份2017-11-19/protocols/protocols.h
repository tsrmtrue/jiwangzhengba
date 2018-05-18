#ifndef __PROTOCOLS_H__
#define	__PROTOCOLS_H__

enum EProtocolVersion
{
	E_PROTOCOL_NOW = 0x1e, //��ǰ�汾2013-10-16,��ʽ1.5�汾
};

enum EProtocolId
{
	Protocol_Start,

	//�汾��У��,������Э�鶼�����Ƕ����Ƹ�ʽcoding��
	S_2_C_Protocol_Version_Ntf, //SProtocolVersionNtf
	C_2_S_Protocol_Type_Rpt, //SProtocolTypeRpt����Ҫʹ��jsonЭ���ʽ��ʱ�򣬿��Է�����������̿��Բ��� 
	S_2_C_Protocol_Type_Rsp, //SProtocolTypeRsp���������õ�ʱ��,������������0.

	S_2_C_AllRoom_List_Ntf, //SAllroomListNtf�����з�����б�
	C_2_S_EnterRoom_By_ID_Ask,	//SEnterRoomByIDAsk������ָ��id�ķ���
	S_2_C_EnterRoom_By_ID_Rsp,  //SEnterRoomByIDRsp�����ط����ڵ���Ϣ

	C_2_S_Objects_Action_Ask,	//SObjectsActionAsk������ָ��id�ķ���
	S_2_C_Objects_Action_Rsp,	//SObjectsActionRsp�����ط����ڵ���Ϣ

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
	unsigned int showLevel;  //�μ�EShowLevel��
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
	int exploit; //��ѫ
	int vigor; //����
	int vigorMax; //��������
	int leaderForce; //�쵼��
	int killingValue;//ɱ¾ֵ
	int halliconId; //����ͷ��
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
	E_ObjectAction_Enter,		//������볡��
	E_ObjectAction_Leave,		//��������
	E_ObjectAction_Move_Start,	//��ʼ�ƶ�
	E_ObjectAction_Move_Stop,	//ֹͣ�ƶ�
	E_ObjectAction_Died,		//��������
	E_ObjectAction_Reborn,		//���󸴻�
	E_ObjectAction_UseSkill,	//ʹ�ü���
	E_ObjectAction_TakeHurt,	//��Ѫ
};

struct SObjectMoveInfo
{
	float pos_x;	//����
	float pos_y;
	float pos_z;
	float dir_x;	//����
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
