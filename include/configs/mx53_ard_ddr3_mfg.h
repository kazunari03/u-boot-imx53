/*
 * Copyright (C) 2011 Freescale Semiconductor, Inc.
 *
 * MFG Configuration settings for the MX53-ARD-DDR3 Freescale board.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/arch/mx53.h>

 /* High Level Configuration Options */
#define CONFIG_MFG	1
#define CONFIG_ARMV7		/* This is armv7 Cortex-A8 CPU core */
#define CONFIG_MXC
#define CONFIG_MX53
#define CONFIG_MX53_ARD_DDR3
#define CONFIG_FLASH_HEADER
#define CONFIG_FLASH_HEADER_OFFSET 0x400
#define CONFIG_MX53_CLK32	32768

#define CONFIG_SKIP_RELOCATE_UBOOT

#define CONFIG_ARCH_CPU_INIT
#define CONFIG_ARCH_MMU

#define CONFIG_MX53_HCLK_FREQ	24000000
#define CONFIG_SYS_PLL2_FREQ    400
#define CONFIG_SYS_AHB_PODF     2
#define CONFIG_SYS_AXIA_PODF    0
#define CONFIG_SYS_AXIB_PODF    1

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_SYS_64BIT_VSPRINTF

#define BOARD_LATE_INIT
/*
 * Disabled for now due to build problems under Debian and a significant
 * increase in the final file size: 144260 vs. 109536 Bytes.
 */

#define CONFIG_CMDLINE_TAG		1	/* enable passing of ATAGs */
#define CONFIG_REVISION_TAG		1
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_INITRD_TAG		1

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 2 * 1024 * 1024)
/* size in bytes reserved for initial data */
#define CONFIG_SYS_GBL_DATA_SIZE	128

/*
 * Hardware drivers
 */
#define CONFIG_MXC_UART 1
#define CONFIG_UART_BASE_ADDR   UART1_BASE_ADDR

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{9600, 19200, 38400, 57600, 115200}

/***********************************************************
 * Command definition
 ***********************************************************/

#include <config_cmd_default.h>

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_NET_RETRY_COUNT  100
#define CONFIG_NET_MULTI 1
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_DNS
#define CONFIG_CMD_IIM
#define CONFIG_CMD_MMC
#define CONFIG_CMD_ENV

#define CONFIG_CMD_CLOCK
#define CONFIG_REF_CLK_FREQ CONFIG_MX53_HCLK_FREQ

#undef CONFIG_CMD_IMLS

#define CONFIG_BOOTDELAY	0

#define CONFIG_PRIME	"smc911x"

#define CONFIG_LOADADDR		0x70800000	/* loadaddr env var */
#define CONFIG_RD_LOADADDR	(CONFIG_LOADADDR + 0x300000)

#define CONFIG_BOOTARGS         "console=ttymxc0,115200 "\
				"rdinit=/linuxrc"
#define CONFIG_BOOTCOMMAND      "bootm 0x70800000 0x70B00000"
#define CONFIG_ENV_IS_EMBEDDED

#define CONFIG_ARP_TIMEOUT	200UL

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_PROMPT		"MX53-ARD-DDR3 MFG U-Boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	16	/* max number of command args */
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE /* Boot Argument Buffer Size */

#define CONFIG_SYS_MEMTEST_START	0	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x10000

#undef	CONFIG_SYS_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR

#define CONFIG_SYS_HZ				1000

#define CONFIG_CMDLINE_EDITING	1

/*Support LAN9217*/
#define CONFIG_SMC911X        1
#define CONFIG_SMC911X_16_BIT 1
#define CONFIG_SMC911X_BASE CS1_BASE_ADDR

#define CONFIG_MII
#define CONFIG_MII_GASKET
#define CONFIG_DISCOVER_PHY

/*
 * FUSE Configs
  * */
#ifdef CONFIG_CMD_IIM
	#define CONFIG_IMX_IIM
	#define IMX_IIM_BASE    IIM_BASE_ADDR
	#define CONFIG_IIM_MAC_BANK     1
	#define CONFIG_IIM_MAC_ROW      9
#endif
/*
 * I2C Configs
 */
#define CONFIG_CMD_I2C          1
#define CONFIG_HARD_I2C         1
#define CONFIG_I2C_MXC          1
#define CONFIG_SYS_I2C_PORT             I2C2_BASE_ADDR
#define CONFIG_SYS_I2C_SPEED            100000
#define CONFIG_SYS_I2C_SLAVE            0xfe


/*
 * SPI Configs
 */
#define CONFIG_FSL_SF		1
#define CONFIG_CMD_SPI
#define CONFIG_CMD_SF
#define CONFIG_SPI_FLASH_IMX_ATMEL	1
#define CONFIG_SPI_FLASH_CS	1
#define CONFIG_IMX_ECSPI
#define IMX_CSPI_VER_2_3        1
#define MAX_SPI_BYTES		(64 * 4)

/*
 * MMC Configs
 */
#ifdef CONFIG_CMD_MMC
	#define CONFIG_MMC				1
	#define CONFIG_GENERIC_MMC
	#define CONFIG_IMX_MMC
	#define CONFIG_SYS_FSL_ESDHC_NUM        2
	#define CONFIG_SYS_FSL_ESDHC_ADDR       0
	#define CONFIG_SYS_MMC_ENV_DEV  0
	#define CONFIG_DOS_PARTITION	1
	#define CONFIG_CMD_FAT		1
	#define CONFIG_CMD_EXT2		1
#endif
/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128 * 1024)	/* regular stack */

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	2
#define PHYS_SDRAM_1		CSD0_BASE_ADDR
#define PHYS_SDRAM_1_SIZE	(512 * 1024 * 1024)
#define PHYS_SDRAM_2          CSD1_BASE_ADDR
#define PHYS_SDRAM_2_SIZE     (512 * 1024 * 1024)

#define iomem_valid_addr(addr, size) \
	((addr >= PHYS_SDRAM_1 && addr <= (PHYS_SDRAM_1 + PHYS_SDRAM_1_SIZE)) \
	|| (addr >= PHYS_SDRAM_2 && addr <= (PHYS_SDRAM_2 + PHYS_SDRAM_2_SIZE)))

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_NO_FLASH


#define CONFIG_ENV_SECT_SIZE    (128 * 1024)
#define CONFIG_ENV_SIZE         CONFIG_ENV_SECT_SIZE

#define CONFIG_ENV_IS_NOWHERE

#endif				/* __CONFIG_H */
