# car_promac — STM32F103 智能小车工程

基于 STM32CubeMX 生成的 HAL 工程，使用 Keil MDK-ARM 编译。

| 项 | 值 |
| --- | --- |
| MCU | STM32F103C8Tx（STM32F1 系列，LQFP48） |
| 工程生成 | STM32CubeMX（`car_promac.ioc`） |
| IDE / 工具链 | Keil MDK-ARM（`MDK-ARM/car_promac.uvprojx`） |

## 目录结构

| 目录 | 说明 |
| --- | --- |
| `Core/` | CubeMX 生成的 `main.c`、中断、MSP、HAL 配置 |
| `BSP/` | 板级驱动：电机（`m_whell`）、编码器、PID、串口收发与协议解析、蜂鸣器（`BLUE`）、`GOZ` 等 |
| `Drivers/` | STM32F1xx HAL 驱动与 CMSIS |
| `MDK-ARM/` | Keil 工程文件（`*.uvprojx` / `*.uvoptx`），编译产物已由 `.gitignore` 忽略 |

## 编译

1. 用 Keil MDK-ARM 打开 `MDK-ARM/car_promac.uvprojx`
2. Rebuild，然后下载到板子

## 分支说明

- `main`：保留旧的 atk_f103 工程
- `car_promac`：本工程（STM32CubeMX + HAL 版本）
