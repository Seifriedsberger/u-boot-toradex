/*
 * Copyright (C) 2014-2016, Toradex AG
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/*
 * Helpers for Freescale PMIC PF0100
*/

#ifndef PF0100_H_
#define PF0100_H_

/* bit definitions */
#define PFUZE100_BIT_0			(0x01 << 0)
#define PFUZE100_BIT_1			(0x01 << 1)
#define PFUZE100_BIT_2			(0x01 << 2)
#define PFUZE100_BIT_3			(0x01 << 3)
#define PFUZE100_BIT_4			(0x01 << 4)
#define PFUZE100_BIT_5			(0x01 << 5)
#define PFUZE100_BIT_6			(0x01 << 6)
#define PFUZE100_BIT_7			(0x01 << 7)

/* 7-bit I2C bus slave address */
#define PFUZE100_I2C_ADDR		(0x08)
/* Register Addresses */
#define PFUZE100_DEVICEID		(0x0)
#define PFUZE100_REVID			(0x3)
#define PFUZE100_INTSTAT3		(0xe)
#define 	PFUZE100_BIT_OTP_ECCI	PFUZE100_BIT_7
#define PFUZE100_SW1AMODE		(0x23)
#define PFUZE100_SW1ACON		36
#define PFUZE100_SW1ACON_SPEED_VAL	(0x1<<6)	/*default */
#define PFUZE100_SW1ACON_SPEED_M	(0x3<<6)
#define PFUZE100_SW1CCON		49
#define PFUZE100_SW1CCON_SPEED_VAL	(0x1<<6)	/*default */
#define PFUZE100_SW1CCON_SPEED_M	(0x3<<6)
#define PFUZE100_SW1AVOL		32
#define PFUZE100_SW1AVOL_VSEL_M		(0x3f<<0)
#define PFUZE100_SW1CVOL		46
#define PFUZE100_SW1CVOL_VSEL_M		(0x3f<<0)
#define PFUZE100_VGEN1CTL		(0x6c)
#define PFUZE100_VGEN1_VAL		(0x30 + 0x08) /* Always ON, 1.2V */
#define PFUZE100_SWBSTCTL		(0x66)
/* Always ON, Auto Switching Mode, 5.0V */
#define PFUZE100_SWBST_VAL		(0x40 + 0x08 + 0x00)

/* chooses the extended page (registers 0x80..0xff) */
#define PFUZE100_PAGE_REGISTER		0x7f
#define PFUZE100_PAGE_REGISTER_PAGE_M	(0x1f << 0)
#define PFUZE100_PAGE_REGISTER_PAGE1	(0x01 & PFUZE100_PAGE_REGISTER_PAGE_M)
#define PFUZE100_PAGE_REGISTER_PAGE2	(0x02 & PFUZE100_PAGE_REGISTER_PAGE_M)

/* extended page 1 */
#define PFUZE100_OTP_ECC_SE1		0x8a
#define 	PFUZE100_BIT_ECC1_SE	PFUZE100_BIT_0
#define 	PFUZE100_BIT_ECC2_SE	PFUZE100_BIT_1
#define 	PFUZE100_BIT_ECC3_SE	PFUZE100_BIT_2
#define 	PFUZE100_BIT_ECC4_SE	PFUZE100_BIT_3
#define 	PFUZE100_BIT_ECC5_SE	PFUZE100_BIT_4
#define 	PFUZE100_BITS_ECC_SE1  ((PFUZE100_BIT_ECC1_SE) | \
					(PFUZE100_BIT_ECC2_SE) | \
					(PFUZE100_BIT_ECC3_SE) | \
					(PFUZE100_BIT_ECC4_SE) | \
					(PFUZE100_BIT_ECC5_SE))
#define PFUZE100_OTP_ECC_SE2		0x8b
#define 	PFUZE100_BIT_ECC6_SE	PFUZE100_BIT_0
#define 	PFUZE100_BIT_ECC7_SE	PFUZE100_BIT_1
#define 	PFUZE100_BIT_ECC8_SE	PFUZE100_BIT_2
#define 	PFUZE100_BIT_ECC9_SE	PFUZE100_BIT_3
#define 	PFUZE100_BIT_ECC10_SE	PFUZE100_BIT_4
#define 	PFUZE100_BITS_ECC_SE2  ((PFUZE100_BIT_ECC6_SE) | \
					(PFUZE100_BIT_ECC7_SE) | \
					(PFUZE100_BIT_ECC8_SE) | \
					(PFUZE100_BIT_ECC9_SE) | \
					(PFUZE100_BIT_ECC10_SE))
#define PFUZE100_OTP_ECC_DE1		0x8c
#define 	PFUZE100_BIT_ECC1_DE	PFUZE100_BIT_0
#define 	PFUZE100_BIT_ECC2_DE	PFUZE100_BIT_1
#define 	PFUZE100_BIT_ECC3_DE	PFUZE100_BIT_2
#define 	PFUZE100_BIT_ECC4_DE	PFUZE100_BIT_3
#define 	PFUZE100_BIT_ECC5_DE	PFUZE100_BIT_4
#define 	PFUZE100_BITS_ECC_DE1  ((PFUZE100_BIT_ECC1_DE) | \
					(PFUZE100_BIT_ECC2_DE) | \
					(PFUZE100_BIT_ECC3_DE) | \
					(PFUZE100_BIT_ECC4_DE) | \
					(PFUZE100_BIT_ECC5_DE))
#define PFUZE100_OTP_ECC_DE2		0x8d
#define 	PFUZE100_BIT_ECC6_DE	PFUZE100_BIT_0
#define 	PFUZE100_BIT_ECC7_DE	PFUZE100_BIT_1
#define 	PFUZE100_BIT_ECC8_DE	PFUZE100_BIT_2
#define 	PFUZE100_BIT_ECC9_DE	PFUZE100_BIT_3
#define 	PFUZE100_BIT_ECC10_DE	PFUZE100_BIT_4
#define 	PFUZE100_BITS_ECC_DE2  ((PFUZE100_BIT_ECC6_DE) | \
					(PFUZE100_BIT_ECC7_DE) | \
					(PFUZE100_BIT_ECC8_DE) | \
					(PFUZE100_BIT_ECC9_DE) | \
					(PFUZE100_BIT_ECC10_DE))
#define PFUZE100_FUSE_POR1		0xe4
#define PFUZE100_FUSE_POR2		0xe5
#define PFUZE100_FUSE_POR3		0xe6
#define PFUZE100_FUSE_POR_M		(0x1 << 1)


/* output some informational messages, return the number FUSE_POR=1 */
/* i.e. 0: unprogrammed, 3: programmed, other: undefined prog. state */
unsigned pmic_init(void);

/* programmes OTP fuses to values required on a Toradex Apalis iMX6 */
int pf0100_prog(void);

#endif /* PF0100_H_ */
