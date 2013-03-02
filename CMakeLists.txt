cmake_minimum_required(VERSION 2.8)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
        "Choose the type of build, options are: None Debug Release
RelWithDebInfo MinSizeRel."
	      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

option(USE_STATIC_VIEW "Compile view statically into binary" OFF)

if(WIN32 OR CYGWIN)
	add_definitions(-DDLL_EXPORT)
endif()

project(anemotion)

set(TARGET_EXEC anemotion)

set(SRC 
anemotion.cpp 
datasession.cpp)

set(APP_SOURCE 
apps/master.cpp 
apps/list.cpp 
apps/user/profile.cpp 
apps/user/usermaster.cpp 
apps/user/useritemslist.cpp 
apps/user/user.cpp apps/user/editdetails.cpp 
apps/details.cpp)

set(MODEL_SOURCE 
model/frame.cpp 
model/video.cpp 
model/image.cpp 
model/user.cpp)

add_subdirectory(model)

find_library(CPPCMS cppcms)
find_library(BOOSTER booster)
find_library(DBO wtdbo PATHS /usr/lib)
find_library(SQLITE wtdbosqlite3 PATHS /usr/lib)

find_program(TMPLCC cppcms_tmpl_cc)

#target_link_libraries(anemotion cppcms wtdbo wtdbosqlite3)

#main templates
set(VIEW_FOLDER view)

set(TEMPLATES
	content.tmpl master.tmpl details.tmpl list.tmpl
)

set(TEMPLATE_CPP
	view.cpp
)

add_custom_target(${TEMPLATE_CPP} ALL
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${USER_VIEW_FOLDER}
)
add_custom_command(
	OUTPUT ${TEMPLATE_CPP}
	COMMAND ${TMPLCC} ${TEMPLATES} -o ${CMAKE_CURRENT_SOURCE_DIR}/build/${TEMPLATE_CPP}
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${VIEW_FOLDER}
)
# 
# add_custom_command(
# 	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${TEMPLATE_CPP}
# 	COMMAND ${TMPLCC}
# 		-d ${TARGET_EXEC}
# 		-o ${CMAKE_CURRENT_SOURCE_DIR}/${TEMPLATE_CPP}
# 			${TEMPLATES}
# 	DEPENDS ${TEMPLATES})
# set(TEMPLATE_TARGETS ${CMAKE_CURRENT_SOURCE_DIR}/${TEMPLATE_CPP})
# 

#user templates
set(USER_VIEW_FOLDER view/user)

set(USER_TEMPLATES
	master.tmpl profile.tmpl details.tmpl list.tmpl
)

set(USER_TEMPLATE_CPP
	userview.cpp
)

add_custom_target(${USER_TEMPLATE_CPP} ALL
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${USER_VIEW_FOLDER}
)
add_custom_command(
	OUTPUT ${USER_TEMPLATE_CPP}
	COMMAND ${TMPLCC} ${USER_TEMPLATES} -o ${CMAKE_CURRENT_SOURCE_DIR}/build/${USER_TEMPLATE_CPP}
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${USER_VIEW_FOLDER}
)

add_custom_target(remove_view ALL
	COMMAND rm -f ${CMAKE_CURRENT_SOURCE_DIR}/build/*.cpp
)

if(USE_STATIC_VIEW)
	add_executable(${TARGET_EXEC} ${SRC} ${TEMPLATE_CPP} ${USER_TEMPLATE_TARGETS} ${SRC} ${APP_SOURCE})
	target_link_libraries(${TARGET_EXEC} ${BOOSTER} ${CPPCMS} ${DBO} ${SQLITE})
else()
	add_executable(${TARGET_EXEC} ${SRC} ${APP_SOURCE})
 	add_library(view SHARED ${TEMPLATE_CPP} ${USER_TEMPLATE_CPP})
 	add_library(model SHARED ${MODEL_SOURCE})
	target_link_libraries(${TARGET_EXEC} view model ${BOOSTER} ${CPPCMS} ${DBO} ${SQLITE})
endif()

add_dependencies(view remove_view)

install(TARGETS ${TARGET_EXEC} RUNTIME DESTINATION bin)