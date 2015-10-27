
IF(NOT DISABLE_ZPNG AND NOT LIBCHAOS_WITH_PNG)
    # Find zlib and libpng
    FIND_PATH(ZLIB_INCLUDE   NAMES zlib.h)
    FIND_LIBRARY(ZLIB_LIB    NAMES libzlibstatic.a libz.a)
    FIND_PATH(LIBPNG_INCLUDE NAMES png.h)
    FIND_LIBRARY(LIBPNG_LIB  NAMES libpng.a)

    IF(ZLIB_LIB AND ZLIB_INCLUDE AND LIBPNG_LIB AND LIBPNG_INCLUDE)
        SET(LIBCHAOS_WITH_PNG TRUE)
        SET(CORE_LIBS ${CORE_LIBS} "PNG")
        SET(LIBCHAOS_CXX_FLAGS "${LIBCHAOS_CXX_FLAGS} -DLIBCHAOS_HAS_PNG")
    ENDIF()
ENDIF()

IF(NOT DIABLE_ZJPEG AND NOT LIBCHAOS_WITH_JPEG)
    # Find libjpeg
    FIND_PATH(LIBJPEG_INCLUDE NAMES jpeglib.h)
    FIND_LIBRARY(LIBJPEG_LIB  NAMES libturbojpeg.a libjpeg.a)

    IF(LIBJPEG_LIB AND LIBJPEG_INCLUDE)
        SET(LIBCHAOS_WITH_JPEG TRUE)
        SET(CORE_LIBS ${CORE_LIBS} "JPEG")
        SET(LIBCHAOS_CXX_FLAGS "${LIBCHAOS_CXX_FLAGS} -DLIBCHAOS_HAS_JPEG")
    ENDIF()
ENDIF()

IF(NOT DISABLE_ZWEBP AND NOT LIBCHAOS_WITH_WEBP)
    # Find libwebp
    FIND_PATH(LIBWEBP_INCLUDE NAMES webp/decode.h webp/encode.h)
    FIND_LIBRARY(LIBWEBP_LIB NAMES libwebp.a)

    IF(LIBWEBP_INCLUDE AND LIBWEBP_LIB)
        SET(LIBCHAOS_WITH_WEBP TRUE)
        SET(CORE_LIBS ${CORE_LIBS} "WebP")
        SET(LIBCHAOS_CXX_FLAGS "${LIBCHAOS_CXX_FLAGS} -DLIBCHAOS_HAS_WEBP")
    ENDIF()
ENDIF()
