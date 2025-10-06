# CMake 최소 요구 버전을 지정합니다.
cmake_minimum_required(VERSION 3.20)

# 프로젝트의 이름을 정하고, 사용할 언어를 C++(CXX)와 C로 지정합니다.
project(ProblemSolving CXX C)

# 모든 실행 파일의 출력 경로를 현재 빌드 디렉토리(cmake-build-debug)로 설정합니다.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# C++ 표준을 20로 설정합니다.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------------------
# [개선된 자동화 스크립트]
# 현재 프로젝트 폴더 아래의 모든 하위 폴더들을 찾습니다.
# --------------------------------------------------------------------

# 최상위 폴더 바로 아래에 있는 모든 폴더 목록을 가져옵니다. (예: BOJ, Techweek)
file(GLOB SUB_DIRS ./*)

# 찾은 폴더 목록을 하나씩 순회합니다.
foreach(SUB_DIR ${SUB_DIRS})
    # 현재 항목이 진짜 '폴더'인지 확인합니다. (.gitignore 같은 파일은 제외)
    if(IS_DIRECTORY ${SUB_DIR})
        # 해당 폴더 안의 모든 .cpp 와 .c 파일을 찾습니다.
        file(GLOB SOURCES "${SUB_DIR}/*.cpp" "${SUB_DIR}/*.c")

        # 폴더 안에서 찾은 소스 파일들을 다시 하나씩 순회합니다.
        foreach(SOURCE_FILE ${SOURCES})
            # 소스 파일의 경로에서 확장자를 뺀 순수 파일 이름만 가져옵니다.
            get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)

            # 해당 이름으로 실행 파일을 만들도록 CMake에 지시합니다.
            add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
        endforeach()
    endif()
endforeach()