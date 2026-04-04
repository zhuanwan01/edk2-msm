[Defines]
  VENDOR_NAME                    = Xiaomi
  PLATFORM_NAME                  = venus
  PLATFORM_GUID                  = f1fb494a-845e-4b64-86b0-1ac52919bee5
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010019
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = Platform/Qualcomm/sm8350/sm8350.fdf
  DEVICE_DXE_FV_COMPONENTS       = Platform/Xiaomi/sm8250/venus.fdf.inc

!include Platform/Qualcomm/sm8350/sm8350.dsc

[BuildOptions.common]
  GCC:*_*_AARCH64_CC_FLAGS = -DENABLE_SIMPLE_INIT

[PcdsFixedAtBuild.common]
  gQcomTokenSpaceGuid.PcdMipiFrameBufferWidth|1440
  gQcomTokenSpaceGuid.PcdMipiFrameBufferHeight|3200

  gSimpleInitTokenSpaceGuid.PcdGuiDefaultDPI|515

  gRenegadePkgTokenSpaceGuid.PcdDeviceVendor|"Xiaomi"
  gRenegadePkgTokenSpaceGuid.PcdDeviceProduct|"Mi 11"
  gRenegadePkgTokenSpaceGuid.PcdDeviceCodeName|"venus"
  
