LOCAL_PATH:= $(call my-dir)

#
# Eco.PKCS8
#
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../../Eco.Core1/SharedFiles
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../Eco.InterfaceBus1/SharedFiles
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../Eco.MemoryManager1/SharedFiles
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../HeaderFiles
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../SharedFiles
TARGET_PLATFORM := android-9
TARGET_OUT := $(LOCAL_PATH)/../../../../BuildFiles/Android/$(TARGET_ARCH_ABI)/$(CONFIGURATION)
LOCAL_SRC_FILES := ../../../../SourceFiles/CEcoPKCS8.c \
../../../../SourceFiles/CEcoPKCS8Factory.c

ifeq ($(TARGET_LINK),0)

LOCAL_MODULE := libC59F9A8DF5F540038C405629A0A4CE6B
LOCAL_CFLAGS := -std=c99 -DECO_LIB -DECO_ANDROID -DUGUID_UTILITY -D__ANDROID__

include $(BUILD_STATIC_LIBRARY)

else

LOCAL_MODULE := C59F9A8DF5F540038C405629A0A4CE6B
LOCAL_CFLAGS := -std=c99 -DECO_DLL -DECO_ANDROID -DUGUID_UTILITY -D__ANDROID__

include $(BUILD_SHARED_LIBRARY)

endif