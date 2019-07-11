/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2018 NXP
 * Copyright 2019 Linaro Ltd.
 */

#ifndef __IMX8QXP_AI_ML_H
#define __IMX8QXP_AI_ML_H

#include <linux/sizes.h>
#include <asm/arch/imx-regs.h>

#ifdef CONFIG_SPL_BUILD
#define CONFIG_SPL_MAX_SIZE				(124 * 1024)
#define CONFIG_SYS_MONITOR_LEN				(1024 * 1024)
#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_USE_SECTOR
#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR		0x250
#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION		0

#define CONFIG_SPL_LDSCRIPT		"arch/arm/cpu/armv8/u-boot-spl.lds"
#define CONFIG_SPL_STACK		0x013E000
#define CONFIG_SPL_BSS_START_ADDR	0x00128000
#define CONFIG_SPL_BSS_MAX_SIZE		0x1000	/* 4 KB */
#define CONFIG_SYS_SPL_MALLOC_START	0x00120000
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x3000	/* 12 KB */
#define CONFIG_SERIAL_LPUART_BASE	0x5a080000
#define CONFIG_MALLOC_F_ADDR		0x00120000

#define CONFIG_SPL_RAW_IMAGE_ARM_TRUSTED_FIRMWARE

#define CONFIG_SPL_ABORT_ON_RAW_IMAGE

#define CONFIG_OF_EMBED
#endif

#define CONFIG_REMAKE_ELF

#define CONFIG_BOARD_EARLY_INIT_F

/* Flat Device Tree Definitions */
#define CONFIG_OF_BOARD_SETUP

#define CONFIG_FSL_USDHC

#define CONFIG_ENV_OVERWRITE

#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG

#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 1) \
	func(DHCP, dhcp, na)

#include <config_distro_bootcmd.h>
/* Initial environment variables */
#define CONFIG_EXTRA_ENV_SETTINGS				\
	"console=ttyLP2 earlycon\0" \
	"fdt_addr_r=0x83000000\0" \
	"kernel_addr_r=0x81000000\0" \
	"ramdisk_addr_r=0x94400000\0" \
	"scriptaddr=0x89000000\0" \
	"fdtfile=imx8qxp-ai_ml.dtb\0"	\
	"fdt_high=0xffffffffffffffff\0"		\
	"image=Image\0" \
	"initrd_addr=0x83800000\0" \
	"initrd_high=0xffffffffffffffff\0" \
	"netargs=setenv bootargs console=${console},${baudrate} " \
		"root=/dev/nfs ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp" \
		"\0" \
	"nfsboot=run netargs; dhcp ${loadaddr} ${image}; tftp ${fdt_addr} " \
		"imx8qxp-ai_ml/${fdt_file}; booti ${loadaddr} - ${fdt_addr}\0" \
	BOOTENV

/* Link Definitions */
#define CONFIG_LOADADDR			0x80280000

#define CONFIG_SYS_LOAD_ADDR           CONFIG_LOADADDR

#define CONFIG_SYS_INIT_SP_ADDR         0x80200000

/* Default environment is in SD */
#define CONFIG_ENV_SIZE			0x1000
#define CONFIG_ENV_OFFSET		(64 * SZ_64K)

/* USDHC2 is the SD card interface */
#define CONFIG_SYS_MMC_ENV_DEV		1   /* USDHC2 */
#define CONFIG_SYS_FSL_USDHC_NUM	2

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		((CONFIG_ENV_SIZE + (32 * 1024)) * 1024)

#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define PHYS_SDRAM_1			0x80000000
#define PHYS_SDRAM_2			0x880000000
#define PHYS_SDRAM_1_SIZE		SZ_2G		/* 2 GB */
#define PHYS_SDRAM_2_SIZE		0x00000000	/* 0 GB */

/* Generic Timer Definitions */
#define COUNTER_FREQUENCY		8000000	/* 8MHz */

/* Networking */
#define CONFIG_FEC_XCV_TYPE		RGMII
#define FEC_QUIRK_ENET_MAC

#endif /* __IMX8QXP_AI_ML_H */
