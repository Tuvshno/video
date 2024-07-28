cmake_minimum_required(VERSION 3.28)
project(Video)

set(CMAKE_CXX_STANDARD 17)

# Set FFmpeg and SDL2 directories
set(FFMPEG_DIR "C:/ffmpeg")
set(SDL2_DIR "C:/SDL2-2.30.1")

# Include directories for FFmpeg and SDL2
include_directories(${FFMPEG_DIR}/include ${SDL2_DIR}/include)

# Link directories for FFmpeg and SDL2
link_directories(${FFMPEG_DIR}/lib ${SDL2_DIR}/lib/x64)

# Add source files
add_executable(Video main.c)

# Link FFmpeg libraries
target_link_libraries(Video
        ${FFMPEG_DIR}/lib/avcodec.lib
        ${FFMPEG_DIR}/lib/avformat.lib
        ${FFMPEG_DIR}/lib/avutil.lib
        ${FFMPEG_DIR}/lib/swscale.lib
        ${FFMPEG_DIR}/lib/avdevice.lib
        ${FFMPEG_DIR}/lib/avfilter.lib
)

# Link SDL2 libraries
target_link_libraries(Video
        ${SDL2_DIR}/lib/x64/SDL2.lib
        ${SDL2_DIR}/lib/x64/SDL2main.lib
)
