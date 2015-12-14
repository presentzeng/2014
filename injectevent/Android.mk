LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := injectevent
LOCAL_MODULE_TAGS := eng optional
LOCAL_SRC_FILES := main.c input_parser.c record.c replay.c
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)
include $(BUILD_EXECUTABLE)

