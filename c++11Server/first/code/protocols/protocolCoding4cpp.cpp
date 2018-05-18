#ifdef WIN32
#include <Winsock2.h>
#else
#include <arpa/inet.h> 
#endif
#include "protocolCoding4cpp.h"
#include <string.h>

int decode_STestNetworkRsp(STestNetworkRsp& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        for (unsigned __j__=0; __j__<1; ++__j__)
        {
            if (__used__  > bufLength)
            {
                return -1;
            }
            int __r__ = decode_STestNetwork(st.rsp, pSrc+__used__, bufLength-__used__);
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int decode_STestNetwork(STestNetwork& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.idx = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.time = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload1 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload2 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload3 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload4 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload5 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload6 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload7 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload8 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload9 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.payload10 = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SObjectsActionRsp(SObjectsActionRsp& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        for (unsigned __j__=0; __j__<1; ++__j__)
        {
            if (__used__  > bufLength)
            {
                return -1;
            }
            int __r__ = decode_SObjectActions(st.oas, pSrc+__used__, bufLength-__used__);
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int decode_SEnterRoomByIDAsk(SEnterRoomByIDAsk& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pSrc + __used__);
        st.roomid = (*__i__);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SObjectActions(SObjectActions& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.count = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    {
        
        if (st.count > 30)
        {
            return -1;
        }
        for (unsigned __j__=0; __j__<st.count; ++__j__)
        {
            if (__used__  > bufLength)
            {
                return -1;
            }
            int __r__ = decode_SObjectAction(st.a[__j__], pSrc+__used__, bufLength-__used__);
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int decode_SProtocolHead(SProtocolHead& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(short) <= bufLength)
    {
        short* __i__ = (short *)(pSrc + __used__);
        st.totalLength = (*__i__);
        __used__ += sizeof(short);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(short) <= bufLength)
    {
        short* __i__ = (short *)(pSrc + __used__);
        st.protocolId = (*__i__);
        __used__ += sizeof(short);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.debugIndex = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SObjectAction(SObjectAction& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pSrc + __used__);
        st.objID = (*__i__);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    {
        
        for (unsigned __j__=0; __j__<1; ++__j__)
        {
            if (__used__  > bufLength)
            {
                return -1;
            }
            int __r__ = decode_SObjectMoveInfo(st.minfo, pSrc+__used__, bufLength-__used__);
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    if (__used__ + sizeof(unsigned short) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short *)(pSrc + __used__);
        st.action = (*__i__);
        __used__ += sizeof(unsigned short);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SObjectsActionAsk(SObjectsActionAsk& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        for (unsigned __j__=0; __j__<1; ++__j__)
        {
            if (__used__  > bufLength)
            {
                return -1;
            }
            int __r__ = decode_SObjectActions(st.oas, pSrc+__used__, bufLength-__used__);
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int decode_STestNetworkAsk(STestNetworkAsk& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        for (unsigned __j__=0; __j__<1; ++__j__)
        {
            if (__used__  > bufLength)
            {
                return -1;
            }
            int __r__ = decode_STestNetwork(st.ask, pSrc+__used__, bufLength-__used__);
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int decode_SAllroomListNtf(SAllroomListNtf& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        if (__used__ + sizeof(st.roomids[0]) * 30 <= bufLength)
        {
            for(unsigned int __j__=0; __j__<30; ++__j__)
            {            
                unsigned int* __i__ = (unsigned int *)(pSrc + __used__);
                st.roomids[__j__] = (*__i__);
                __used__ += sizeof(unsigned int);
            }
        }
        else
        {
            return -1;
        }
    }


    return __used__;
}


int decode_SObjectMoveInfo(SObjectMoveInfo& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pSrc + __used__);
        st.pos_x = (*__i__);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pSrc + __used__);
        st.pos_y = (*__i__);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pSrc + __used__);
        st.pos_z = (*__i__);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pSrc + __used__);
        st.dir_x = (*__i__);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pSrc + __used__);
        st.dir_y = (*__i__);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pSrc + __used__);
        st.dir_z = (*__i__);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SProtocolVersionNtf(SProtocolVersionNtf& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.version = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SProtocolTypeRsp(SProtocolTypeRsp& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(short) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short*)(pSrc + __used__);
        unsigned short __l__ = (*__i__);
        __used__ += sizeof(unsigned short);
        if (__used__ + __l__> bufLength)
        {
            return -1;
        }
        memcpy(st.rsp, pSrc + __used__, __l__);
        __used__ += __l__;
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SProtocolTypeRpt(SProtocolTypeRpt& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.type = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SEnterRoomByIDRsp(SEnterRoomByIDRsp& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.i = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    {
        
        if (st.i > 2)
        {
            return -1;
        }
        for (unsigned __j__=0; __j__<st.i; ++__j__)
        {
            if (__used__  > bufLength)
            {
                return -1;
            }
            int __r__ = decode_SBasicRoleInfo(st.s[__j__], pSrc+__used__, bufLength-__used__);
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pSrc + __used__);
        st.f = (*__i__);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int decode_SBasicRoleInfo(SBasicRoleInfo& st, unsigned char* pSrc, int bufLength )
{
    if (pSrc == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pSrc + __used__);
        st.userid = (*__i__);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.guid = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pSrc + __used__);
        st.showLevel = (*__i__);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pSrc + __used__);
        st.mateid = (*__i__);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(short) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short*)(pSrc + __used__);
        unsigned short __l__ = (*__i__);
        __used__ += sizeof(unsigned short);
        if (__used__ + __l__> bufLength)
        {
            return -1;
        }
        memcpy(st.macAddress, pSrc + __used__, __l__);
        __used__ += __l__;
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(short) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short*)(pSrc + __used__);
        unsigned short __l__ = (*__i__);
        __used__ += sizeof(unsigned short);
        if (__used__ + __l__> bufLength)
        {
            return -1;
        }
        memcpy(st.rolename, pSrc + __used__, __l__);
        __used__ += __l__;
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.level = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.professionId = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.exp = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.popularity = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.expTotal = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    {
        
        if (__used__ + sizeof(st.diamond[0]) * 2 <= bufLength)
        {
            for(unsigned int __j__=0; __j__<2; ++__j__)
            {            
                int* __i__ = (int *)(pSrc + __used__);
                st.diamond[__j__] = (*__i__);
                __used__ += sizeof(int);
            }
        }
        else
        {
            return -1;
        }
    }


    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.money = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.exploit = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.vigor = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.vigorMax = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.leaderForce = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.killingValue = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pSrc + __used__);
        st.halliconId = (*__i__);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pSrc + __used__);
        st.f = (*__i__);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(short) <= bufLength)
    {
        short* __i__ = (short *)(pSrc + __used__);
        st.te = (*__i__);
        __used__ += sizeof(short);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned short) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short *)(pSrc + __used__);
        st.tes = (*__i__);
        __used__ += sizeof(unsigned short);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(char) <= bufLength)
    {
        char* __i__ = (char *)(pSrc + __used__);
        st.c = (*__i__);
        __used__ += sizeof(char);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned char) <= bufLength)
    {
        unsigned char* __i__ = (unsigned char *)(pSrc + __used__);
        st.uc = (*__i__);
        __used__ += sizeof(unsigned char);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(long long) <= bufLength)
    {
        long long* __i__ = (long long *)(pSrc + __used__);
        st.ll = (*__i__);
        __used__ += sizeof(long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pSrc + __used__);
        st.ull = (*__i__);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_STestNetworkRsp(STestNetworkRsp& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        for (unsigned int __j__=0; __j__<1; ++__j__)
        {
            if (__used__ > bufLength)
            {
                return -1;
            }
            int __r__ = encode_STestNetwork(st.rsp, pBuf+__used__, bufLength - __used__ );
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int encode_STestNetwork(STestNetwork& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.idx);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.time);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload1);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload2);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload3);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload4);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload5);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload6);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload7);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload8);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload9);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.payload10);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SObjectsActionRsp(SObjectsActionRsp& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        for (unsigned int __j__=0; __j__<1; ++__j__)
        {
            if (__used__ > bufLength)
            {
                return -1;
            }
            int __r__ = encode_SObjectActions(st.oas, pBuf+__used__, bufLength - __used__ );
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int encode_SEnterRoomByIDAsk(SEnterRoomByIDAsk& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pBuf + __used__);
        *__i__ = (st.roomid);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SObjectActions(SObjectActions& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.count);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    {
        
        if (st.count > 30)
        {
            return -1;
        }
        for (unsigned int __j__=0; __j__<st.count; ++__j__)
        {
            if (__used__ > bufLength)
            {
                return -1;
            }
            int __r__ = encode_SObjectAction(st.a[__j__], pBuf+__used__, bufLength - __used__ );
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int encode_SProtocolHead(SProtocolHead& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(short) <= bufLength)
    {
        short* __i__ = (short *)(pBuf + __used__);
        *__i__ = (st.totalLength);
        __used__ += sizeof(short);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(short) <= bufLength)
    {
        short* __i__ = (short *)(pBuf + __used__);
        *__i__ = (st.protocolId);
        __used__ += sizeof(short);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.debugIndex);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SObjectAction(SObjectAction& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pBuf + __used__);
        *__i__ = (st.objID);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    {
        
        for (unsigned int __j__=0; __j__<1; ++__j__)
        {
            if (__used__ > bufLength)
            {
                return -1;
            }
            int __r__ = encode_SObjectMoveInfo(st.minfo, pBuf+__used__, bufLength - __used__ );
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    if (__used__ + sizeof(unsigned short) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short *)(pBuf + __used__);
        *__i__ = (st.action);
        __used__ += sizeof(unsigned short);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SObjectsActionAsk(SObjectsActionAsk& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        for (unsigned int __j__=0; __j__<1; ++__j__)
        {
            if (__used__ > bufLength)
            {
                return -1;
            }
            int __r__ = encode_SObjectActions(st.oas, pBuf+__used__, bufLength - __used__ );
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int encode_STestNetworkAsk(STestNetworkAsk& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        for (unsigned int __j__=0; __j__<1; ++__j__)
        {
            if (__used__ > bufLength)
            {
                return -1;
            }
            int __r__ = encode_STestNetwork(st.ask, pBuf+__used__, bufLength - __used__ );
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    return __used__;
}


int encode_SAllroomListNtf(SAllroomListNtf& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    {
        
        if (__used__ + sizeof(st.roomids[0]) * 30 <= bufLength)
        {
            for(unsigned int __j__=0; __j__<30; ++__j__)
            {            
                unsigned int* __i__ = (unsigned int *)(pBuf + __used__);
                *__i__ = (st.roomids[__j__]);
                __used__ += sizeof(unsigned int);
            }
        }
        else
        {
            return -1;
        }
    }


    return __used__;
}


int encode_SObjectMoveInfo(SObjectMoveInfo& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pBuf + __used__);
        *__i__ = (st.pos_x);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pBuf + __used__);
        *__i__ = (st.pos_y);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pBuf + __used__);
        *__i__ = (st.pos_z);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pBuf + __used__);
        *__i__ = (st.dir_x);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pBuf + __used__);
        *__i__ = (st.dir_y);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pBuf + __used__);
        *__i__ = (st.dir_z);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SProtocolVersionNtf(SProtocolVersionNtf& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.version);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SProtocolTypeRsp(SProtocolTypeRsp& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(short) + strlen(st.rsp) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short*)(pBuf + __used__);
        *__i__ = (strlen(st.rsp));
        __used__ += sizeof(unsigned short);
    
        memcpy(pBuf + __used__, st.rsp, strlen(st.rsp));
        __used__ += strlen(st.rsp);
    }
    else
    {
        return -1;
    }


    return __used__;
}


int encode_SProtocolTypeRpt(SProtocolTypeRpt& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.type);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SEnterRoomByIDRsp(SEnterRoomByIDRsp& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.i);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    {
        
        if (st.i > 2)
        {
            return -1;
        }
        for (unsigned int __j__=0; __j__<st.i; ++__j__)
        {
            if (__used__ > bufLength)
            {
                return -1;
            }
            int __r__ = encode_SBasicRoleInfo(st.s[__j__], pBuf+__used__, bufLength - __used__ );
            if (__r__>0)
            {
                __used__ += __r__;
            }
            else
            {
                return -1;
            }
        }
    }


    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pBuf + __used__);
        *__i__ = (st.f);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    return __used__;
}


int encode_SBasicRoleInfo(SBasicRoleInfo& st, unsigned char* pBuf, int bufLength )
{
    if (pBuf == NULL)
    {
        return -1;
    }
    unsigned int __used__ = 0;

    
    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pBuf + __used__);
        *__i__ = (st.userid);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.guid);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pBuf + __used__);
        *__i__ = (st.showLevel);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned int) <= bufLength)
    {
        unsigned int* __i__ = (unsigned int *)(pBuf + __used__);
        *__i__ = (st.mateid);
        __used__ += sizeof(unsigned int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(short) + strlen(st.macAddress) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short*)(pBuf + __used__);
        *__i__ = (strlen(st.macAddress));
        __used__ += sizeof(unsigned short);
    
        memcpy(pBuf + __used__, st.macAddress, strlen(st.macAddress));
        __used__ += strlen(st.macAddress);
    }
    else
    {
        return -1;
    }


    if (__used__ + sizeof(short) + strlen(st.rolename) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short*)(pBuf + __used__);
        *__i__ = (strlen(st.rolename));
        __used__ += sizeof(unsigned short);
    
        memcpy(pBuf + __used__, st.rolename, strlen(st.rolename));
        __used__ += strlen(st.rolename);
    }
    else
    {
        return -1;
    }


    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.level);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.professionId);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.exp);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.popularity);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.expTotal);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    {
        
        if (__used__ + sizeof(st.diamond[0]) * 2 <= bufLength)
        {
            for(unsigned int __j__=0; __j__<2; ++__j__)
            {            
                int* __i__ = (int *)(pBuf + __used__);
                *__i__ = (st.diamond[__j__]);
                __used__ += sizeof(int);
            }
        }
        else
        {
            return -1;
        }
    }


    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.money);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.exploit);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.vigor);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.vigorMax);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.leaderForce);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.killingValue);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(int) <= bufLength)
    {
        int* __i__ = (int *)(pBuf + __used__);
        *__i__ = (st.halliconId);
        __used__ += sizeof(int);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(float) <= bufLength)
    {
        float* __i__ = (float *)(pBuf + __used__);
        *__i__ = (st.f);
        __used__ += sizeof(float);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(short) <= bufLength)
    {
        short* __i__ = (short *)(pBuf + __used__);
        *__i__ = (st.te);
        __used__ += sizeof(short);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned short) <= bufLength)
    {
        unsigned short* __i__ = (unsigned short *)(pBuf + __used__);
        *__i__ = (st.tes);
        __used__ += sizeof(unsigned short);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(char) <= bufLength)
    {
        char* __i__ = (char *)(pBuf + __used__);
        *__i__ = (st.c);
        __used__ += sizeof(char);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned char) <= bufLength)
    {
        unsigned char* __i__ = (unsigned char *)(pBuf + __used__);
        *__i__ = (st.uc);
        __used__ += sizeof(unsigned char);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(long long) <= bufLength)
    {
        long long* __i__ = (long long *)(pBuf + __used__);
        *__i__ = (st.ll);
        __used__ += sizeof(long long);
    }
    else
    {
        return -1;
    }



    if (__used__ + sizeof(unsigned long long) <= bufLength)
    {
        unsigned long long* __i__ = (unsigned long long *)(pBuf + __used__);
        *__i__ = (st.ull);
        __used__ += sizeof(unsigned long long);
    }
    else
    {
        return -1;
    }



    return __used__;
}


