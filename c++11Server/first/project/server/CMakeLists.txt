################ PROJECT NAME #####################
cmake_minimum_required (VERSION 2.8)

add_compile_options(-std=c++11)
add_compile_options(-o0)
set( CMAKE_USE_RELATIVE_PATHS on)

        
PROJECT ( map_server )

set (PRONAME "map_server")


################ OSBIT #####################
IF(CMAKE_SIZEOF_VOID_P MATCHES 4)
    set ( OSBIT    32)
    MESSAGE(STATUS "OSBIT    32")
ELSE()
    set ( OSBIT 64)
    MESSAGE(STATUS "OSBIT    64")
ENDIF(CMAKE_SIZEOF_VOID_P MATCHES 4)


################ DEBUG/RELEASE #####################
set( CMAKE_BUILD_TYPE Debug )



################ PATH #####################
set(PATH_CUR "./")
set(PATH_CODE "../../code")
set(PATH_BASE "../../code/base")
set(PATH_LOGIC "../../code/logic")
set(PATH_PROTOCOLS "../../code/protocols")

IF(WIN32)	
	set(PATH_THIRD_CODE_LIBEVENT "../../third-code/libevent-2.1.8-stable/include")
ELSE()
ENDIF(WIN32)


################ MACRO #####################



################ INCLUDE #####################
include_directories("${PATH_CUR}")
include_directories("${PATH_CODE}")
include_directories("${PATH_PROTOCOLS}")
IF(WIN32)	
	include_directories("${PATH_THIRD_CODE_LIBEVENT}")
ELSE()
ENDIF(WIN32)



################ LIBRARY #####################
IF(WIN32)
	set( LIBS ws2_32  libevent)   
ELSE()
	set( LIBS  
		event
		pthread
		)
ENDIF(WIN32)        


################ LINK_DIRECTORIES #####################
IF(WIN32)
	LINK_DIRECTORIES( "${CMAKE_CURRENT_SOURCE_DIR}/../../third-libs" )
ELSE()
ENDIF(WIN32)        


################ SOURCE_FILES #####################
AUX_SOURCE_DIRECTORY(${PATH_BASE} SOURCE_FILES)
AUX_SOURCE_DIRECTORY(${PATH_LOGIC} SOURCE_FILES)
AUX_SOURCE_DIRECTORY(${PATH_PROTOCOLS} SOURCE_FILES)


################ HEAD_FILES #####################

MESSAGE( "search headfiles ")

FILE(GLOB_RECURSE  HEAD_FILES_3 "${PATH_CUR}/*.h")
FILE(GLOB_RECURSE  HEAD_FILES_4 "${PATH_BASE}/*.h")
FILE(GLOB_RECURSE  HEAD_FILES_5 "${PATH_LOGIC}/*.h")
FILE(GLOB_RECURSE  HEAD_FILES_7 "${PATH_PROTOCOLS}/*.h")



set(HEAD_FILES 
		${HEAD_FILES_3}
		${HEAD_FILES_4}
		${HEAD_FILES_5}
		${HEAD_FILES_7}
		)


################ MSVC FILTER #####################


################ CUSTOM COMMANDS #####################



macro(source_group_by_dir source_files)
    if(MSVC)
        set(sgbd_cur_dir ${PATH_CODE})
		MESSAGE(${sgbd_cur_dir})
        foreach(sgbd_file ${${source_files}})
			MESSAGE(${sgbd_file})
            string(REGEX MATCH  ${sgbd_cur_dir}/\(.*\) sgbd_fpath ${sgbd_file})
			MESSAGE(${sgbd_fpath})
            string(REGEX REPLACE  ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_fpath})
			MESSAGE(${sgbd_fpath})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            if(sgbd_nogroup)
                set(sgbd_group_name "\\")
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
			MESSAGE(${sgbd_group_name})
        endforeach(sgbd_file)
    endif(MSVC)
endmacro(source_group_by_dir)

set(all_files ${HEAD_FILES} ${SOURCE_FILES})
source_group_by_dir(all_files )

AUX_SOURCE_DIRECTORY(${PATH_CUR} SOURCE_FILES)

################ BUILD #####################

ADD_EXECUTABLE( ${PRONAME} ${SOURCE_FILES} ${HEAD_FILES} )              
TARGET_LINK_LIBRARIES( ${PRONAME} ${LIBS})

SET(EXECUTABLE_OUTPUT_PATH ${PATH_CUR}) 


################ INSTALL #####################
