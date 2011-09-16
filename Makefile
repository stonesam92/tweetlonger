#DEBUG = 1
GO_EASY_ON_ME = 1
SDKVERSION = 4.3
THEOS_DEVICE_IP = 192.168.1.86
include theos/makefiles/common.mk

TWEAK_NAME = TweetLonger
TweetLonger_FILES = Tweak.xm
TweetLonger_FRAMEWORKS = Foundation UIKit QuartzCore CoreGraphics

include $(THEOS_MAKE_PATH)/tweak.mk
