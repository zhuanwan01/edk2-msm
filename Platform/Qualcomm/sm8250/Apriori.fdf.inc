APRIORI DXE {

  # 1. 核心架构与基础协议 (必须最先加载)
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF ArmPkg/Drivers/ArmGic/ArmGicDxe.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf

  # 2. 硬件抽象与平台基础 (DAL/Smem)
  FILE DRIVER = f541d663-4a48-40aa-aabf-ff158ccae34c {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/SmemDxe/SmemDxe.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/SmemDxe/SmemDxe.efi
    SECTION UI = "SmemDxe"
  }

  FILE DRIVER = 8E9BD160-B184-11DF-94E2-0800200C9A66 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/DALSys/DALSys.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/DALSys/DALSys.efi
    SECTION UI = "DALSys"
  }

  FILE DRIVER = 5776232e-082d-4b75-9a0e-fe1d13f7a5d9 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/PmicDxe/PmicDxe.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/PmicDxe/PmicDxe.efi
    SECTION UI = "PmicDxe"
  }

  FILE DRIVER = 4DB5DEA6-5302-4D1A-8A82-677A683B0D29 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/ClockDxe/ClockDxe.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/ClockDxe/ClockDxe.efi
    SECTION UI = "ClockDxe"
  }

  FILE DRIVER = 8681cc5a-0df6-441e-b4b8-e915c538f067 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/DALTLMM/DALTLMM.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/DALTLMM/DALTLMM.efi
    SECTION UI = "DALTLMM"
  }

  FILE DRIVER = 2a7b4bef-80cd-49e1-b473-374ba4d673fc {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/SPMI/SPMI.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/SPMI/SPMI.efi
    SECTION UI = "SPMI"
  }

  # 3. 存储驱动 (确保 UFS 在 Shell 启动前就绪)
  FILE DRIVER = 0d35cd8e-97ea-4f9a-96af-0f0d89f76567 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/UFSDxe/UFSDxe.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/UFSDxe/UFSDxe.efi
    SECTION UI = "UFSDxe"
  }

  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF FatPkg/EnhancedFatDxe/Fat.inf

  # 4. USB 硬件供电与控制器 (解决不亮灯的关键)
  FILE DRIVER = 11faed4c-b21f-4d88-8e48-c4c28a1e50df {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/UsbPwrCtrlDxe/UsbPwrCtrlDxe.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/UsbPwrCtrlDxe/UsbPwrCtrlDxe.efi
    SECTION UI = "UsbPwrCtrlDxe"
  }

  FILE DRIVER = cd823a4d-7dec-4531-ae5d-4134fa4127b8 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/UsbConfigDxe/UsbConfigDxe.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/UsbConfigDxe/UsbConfigDxe.efi
    SECTION UI = "UsbConfigDxe"
  }

  FILE DRIVER = beb12bee-f6e1-11e1-9fb8-6c626de4aeb1 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/XhciPciEmulation/XhciPciEmulation.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/XhciPciEmulation/XhciPciEmulation.efi
    SECTION UI = "XhciPciEmulation"
  }

  FILE DRIVER = b7f50e91-a759-412c-ade4-dcd03e7f7c28 {
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/XhciDxe/XhciDxe.efi
    SECTION UI = "XhciDxe"
  }

  # 5. USB 设备类驱动 (让 Shell 能用键盘鼠标)
  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMouseDxe/UsbMouseDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  # 6. 其他必要的系统驱动
  FILE DRIVER = af9763a2-033b-4109-8e17-56a98d380c92 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/HWIODxeDriver/HWIODxeDriver.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/HWIODxeDriver/HWIODxeDriver.efi
    SECTION UI = "HWIODxeDriver"
  }

  FILE DRIVER = 10e193df-9966-44e7-b17c-59dd831e20fc {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/ChipInfo/ChipInfo.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/ChipInfo/ChipInfo.efi
    SECTION UI = "ChipInfo"
  }

  FILE DRIVER = B105211B-BBBD-4ADD-A3B0-D1CF4A52154C {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/PlatformInfoDxeDriver/PlatformInfoDxeDriver.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/PlatformInfoDxeDriver/PlatformInfoDxeDriver.efi
    SECTION UI = "PlatformInfoDxeDriver"
  }

  FILE DRIVER = 04DE8591-D2B3-4077-BBBE-B12070094EB6 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/I2C/I2C.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/I2C/I2C.efi
    SECTION UI = "I2C"
  }

  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf
  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf
  
  # 剩下的补全
  FILE DRIVER = 5bd181db-0487-4f1a-ae73-820e165611b3 {
    SECTION DXE_DEPEX = Platform/EFI_Binaries/Drivers/sm8250/ButtonsDxe/ButtonsDxe.depex
    SECTION PE32 = Platform/EFI_Binaries/Drivers/sm8250/ButtonsDxe/ButtonsDxe.efi
    SECTION UI = "ButtonsDxe"
  }

}

