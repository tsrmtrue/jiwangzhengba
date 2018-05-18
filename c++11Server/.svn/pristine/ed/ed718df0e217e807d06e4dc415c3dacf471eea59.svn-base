using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Completed
{
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

    
    public class SProtocolHead
    {
        public Int16  totalLength = 0;
        public Int16  protocolId = 0;
        public Int32  debugIndex = 0;

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref totalLength))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref protocolId))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref debugIndex))
            {
                return false;
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, totalLength))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, protocolId))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, debugIndex))
            {
                return false;
            }



            return true;
        }

    } 


    public class SBasicRoleInfo
    {
        public UInt32  userid = 0;
        public Int32  guid = 0;
        public UInt32  showLevel = 0;
        public UInt32  mateid = 0;
        public string  macAddress = "";
        public string  rolename = "";
        public Int32  level = 0;
        public Int32  professionId = 0;
        public Int32  exp = 0;
        public Int32  popularity = 0;
        public Int32  expTotal = 0;
        public Int32 [] diamond = new Int32[2];
        public Int32  money = 0;
        public Int32  exploit = 0;
        public Int32  vigor = 0;
        public Int32  vigorMax = 0;
        public Int32  leaderForce = 0;
        public Int32  killingValue = 0;
        public Int32  halliconId = 0;
        public float  f = 0;
        public Int16  te = 0;
        public UInt16  tes = 0;
        public byte  c = 0;
        public byte  uc = 0;
        public Int64  ll = 0;
        public UInt64  ull = 0;

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref userid))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref guid))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref showLevel))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref mateid))
            {
                return false;
            }


            {
                short __s__ = 0;
                if (CProtocolHelp.Read(__buff__, ref __used__, ref __s__))
                {
                    if(!CProtocolHelp.Read(__buff__, ref __used__, __s__, ref macAddress))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }


            {
                short __s__ = 0;
                if (CProtocolHelp.Read(__buff__, ref __used__, ref __s__))
                {
                    if(!CProtocolHelp.Read(__buff__, ref __used__, __s__, ref rolename))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref level))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref professionId))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref exp))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref popularity))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref expTotal))
            {
                return false;
            }


            {
                if (__used__ + sizeof(Int32) * 2 <= __buff__.Length)
                {
                    for(int __i__=0; __i__<2; ++__i__)
                    {
                        Int32 __t__ = 0;
                        if ( !CProtocolHelp.Read(__buff__, ref __used__, ref __t__))
                        {
                            return false;
                        }
                        diamond[__i__] = __t__;
                    }
                }
                else
                {
                    return false;
                }
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref money))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref exploit))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref vigor))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref vigorMax))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref leaderForce))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref killingValue))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref halliconId))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref f))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref te))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref tes))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref c))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref uc))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref ll))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref ull))
            {
                return false;
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, userid))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, guid))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, showLevel))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, mateid))
            {
                return false;
            }



            {
                short __s__ = (short)macAddress.Length;
                if (CProtocolHelp.Write(ref __buff__, ref __used__, __s__))
                {
                    if(!CProtocolHelp.Write(ref __buff__, ref __used__, __s__, macAddress))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }

            }


            {
                short __s__ = (short)rolename.Length;
                if (CProtocolHelp.Write(ref __buff__, ref __used__, __s__))
                {
                    if(!CProtocolHelp.Write(ref __buff__, ref __used__, __s__, rolename))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }

            }


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, level))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, professionId))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, exp))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, popularity))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, expTotal))
            {
                return false;
            }



            {
                if (__used__ + sizeof(Int32) * 2 <= __buff__.Length)
                {
                    for(int __i__=0; __i__<2; ++__i__)
                    {
                        Int32 __t__ = diamond[__i__];
                        if ( !CProtocolHelp.Write(ref __buff__, ref __used__, __t__))
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
            }


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, money))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, exploit))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, vigor))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, vigorMax))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, leaderForce))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, killingValue))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, halliconId))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, f))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, te))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, tes))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, c))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, uc))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, ll))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, ull))
            {
                return false;
            }



            return true;
        }

    } 


    public class SProtocolVersionNtf
    {
        public Int32  version = 0;

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref version))
            {
                return false;
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, version))
            {
                return false;
            }



            return true;
        }

    } 


    public class SProtocolTypeRpt
    {
        public Int32  type = 0;

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref type))
            {
                return false;
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, type))
            {
                return false;
            }



            return true;
        }

    } 


    public class SProtocolTypeRsp
    {
        public string  rsp = "";

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            {
                short __s__ = 0;
                if (CProtocolHelp.Read(__buff__, ref __used__, ref __s__))
                {
                    if(!CProtocolHelp.Read(__buff__, ref __used__, __s__, ref rsp))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            {
                short __s__ = (short)rsp.Length;
                if (CProtocolHelp.Write(ref __buff__, ref __used__, __s__))
                {
                    if(!CProtocolHelp.Write(ref __buff__, ref __used__, __s__, rsp))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }

            }


            return true;
        }

    } 


    public class SAllroomListNtf
    {
        public UInt32 [] roomids = new UInt32[30];

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            {
                if (__used__ + sizeof(UInt32) * 30 <= __buff__.Length)
                {
                    for(int __i__=0; __i__<30; ++__i__)
                    {
                        UInt32 __t__ = 0;
                        if ( !CProtocolHelp.Read(__buff__, ref __used__, ref __t__))
                        {
                            return false;
                        }
                        roomids[__i__] = __t__;
                    }
                }
                else
                {
                    return false;
                }
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            {
                if (__used__ + sizeof(UInt32) * 30 <= __buff__.Length)
                {
                    for(int __i__=0; __i__<30; ++__i__)
                    {
                        UInt32 __t__ = roomids[__i__];
                        if ( !CProtocolHelp.Write(ref __buff__, ref __used__, __t__))
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    return false;
                }
            }


            return true;
        }

    } 


    public class SEnterRoomByIDAsk
    {
        public UInt32  roomid = 0;

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref roomid))
            {
                return false;
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, roomid))
            {
                return false;
            }



            return true;
        }

    } 


    public class SEnterRoomByIDRsp
    {
        public Int32  i = 0;
        public SBasicRoleInfo [] s = new SBasicRoleInfo[2];
        public float  f = 0;

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref i))
            {
                return false;
            }


            {
                for (int __i__=0; __i__<i; ++__i__)
                {
                    SBasicRoleInfo __t__ = new SBasicRoleInfo();
                    if (! __t__.decode(__buff__, ref __used__) )
                    {
                        return false;
                    }
                    s[__i__] = __t__;
                }
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref f))
            {
                return false;
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, i))
            {
                return false;
            }



            {
                for (int __i__=0; __i__<i; ++__i__)
                {
                    if (! s[__i__].encode(ref __buff__, ref __used__) )
                    {
                        return false;
                    }
                }
            }


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, f))
            {
                return false;
            }



            return true;
        }

    } 


    public class SObjectMoveInfo
    {
        public float  pos_x = 0;
        public float  pos_y = 0;
        public float  pos_z = 0;
        public float  dir_x = 0;
        public float  dir_y = 0;
        public float  dir_z = 0;

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref pos_x))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref pos_y))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref pos_z))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref dir_x))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref dir_y))
            {
                return false;
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref dir_z))
            {
                return false;
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, pos_x))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, pos_y))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, pos_z))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, dir_x))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, dir_y))
            {
                return false;
            }



            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, dir_z))
            {
                return false;
            }



            return true;
        }

    } 


    public class SObjectAction
    {
        public UInt32  objID = 0;
        public SObjectMoveInfo  minfo =  new SObjectMoveInfo();
        public UInt16  action = 0;

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref objID))
            {
                return false;
            }


            {
                for (int __i__=0; __i__<1; ++__i__)
                {
                    SObjectMoveInfo __t__ = new SObjectMoveInfo();
                    if (! __t__.decode(__buff__, ref __used__) )
                    {
                        return false;
                    }
                    minfo = __t__;
                }
            }


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref action))
            {
                return false;
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, objID))
            {
                return false;
            }



            {
                for (int __i__=0; __i__<1; ++__i__)
                {
                    if (! minfo.encode(ref __buff__, ref __used__) )
                    {
                        return false;
                    }
                }
            }


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, action))
            {
                return false;
            }



            return true;
        }

    } 


    public class SObjectActions
    {
        public Int32  count = 0;
        public SObjectAction [] a = new SObjectAction[30];

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Read(__buff__, ref __used__, ref count))
            {
                return false;
            }


            {
                for (int __i__=0; __i__<count; ++__i__)
                {
                    SObjectAction __t__ = new SObjectAction();
                    if (! __t__.decode(__buff__, ref __used__) )
                    {
                        return false;
                    }
                    a[__i__] = __t__;
                }
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            if ( !CProtocolHelp.Write(ref __buff__, ref __used__, count))
            {
                return false;
            }



            {
                for (int __i__=0; __i__<count; ++__i__)
                {
                    if (! a[__i__].encode(ref __buff__, ref __used__) )
                    {
                        return false;
                    }
                }
            }


            return true;
        }

    } 


    public class SObjectsActionAsk
    {
        public SObjectActions  oas =  new SObjectActions();

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            {
                for (int __i__=0; __i__<1; ++__i__)
                {
                    SObjectActions __t__ = new SObjectActions();
                    if (! __t__.decode(__buff__, ref __used__) )
                    {
                        return false;
                    }
                    oas = __t__;
                }
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            {
                for (int __i__=0; __i__<1; ++__i__)
                {
                    if (! oas.encode(ref __buff__, ref __used__) )
                    {
                        return false;
                    }
                }
            }


            return true;
        }

    } 


    public class SObjectsActionRsp
    {
        public SObjectActions  oas =  new SObjectActions();

        
        public bool decode(byte [] __buff__, ref int __used__)
        {


            {
                for (int __i__=0; __i__<1; ++__i__)
                {
                    SObjectActions __t__ = new SObjectActions();
                    if (! __t__.decode(__buff__, ref __used__) )
                    {
                        return false;
                    }
                    oas = __t__;
                }
            }


            return true;
        }

        
        public bool encode(ref byte[] __buff__, ref int __used__)
        {


            {
                for (int __i__=0; __i__<1; ++__i__)
                {
                    if (! oas.encode(ref __buff__, ref __used__) )
                    {
                        return false;
                    }
                }
            }


            return true;
        }

    } 

}
