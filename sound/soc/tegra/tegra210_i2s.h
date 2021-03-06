/*
 * tegra210_i2s.h - Definitions for Tegra210 I2S driver
 *
 * Copyright (c) 2014, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TEGRA210_I2S_H__
#define __TEGRA210_I2S_H__

#include "tegra210_ahub_utils.h"


/* I2S Rx path (w.r.to AXBAR) Registers */
#define TEGRA210_I2S_AXBAR_RX_ENABLE						0x00
#define TEGRA210_I2S_AXBAR_RX_SOFT_RESET					0x04
#define TEGRA210_I2S_AXBAR_RX_STATUS						0x0c
#define TEGRA210_I2S_AXBAR_RX_INT_STATUS					0x10
#define TEGRA210_I2S_AXBAR_RX_INT_MASK						0x14
#define TEGRA210_I2S_AXBAR_RX_INT_SET						0x18
#define TEGRA210_I2S_AXBAR_RX_INT_CLEAR						0x1c
#define TEGRA210_I2S_AXBAR_RX_CIF_CTRL						0x20
#define TEGRA210_I2S_AXBAR_RX_CTRL							0x24
#define TEGRA210_I2S_AXBAR_RX_SLOT_CTRL						0x28
#define TEGRA210_I2S_AXBAR_RX_CLK_TRIM						0x2c
#define TEGRA210_I2S_AXBAR_RX_CIF_FIFO_STATUS				0x34

/* I2S Tx path (w.r.to AXBAR) Registers */
#define TEGRA210_I2S_AXBAR_TX_ENABLE						0x40
#define TEGRA210_I2S_AXBAR_TX_SOFT_RESET					0x44
#define TEGRA210_I2S_AXBAR_TX_STATUS						0x4c
#define TEGRA210_I2S_AXBAR_TX_INT_STATUS					0x50
#define TEGRA210_I2S_AXBAR_TX_INT_MASK						0x54
#define TEGRA210_I2S_AXBAR_TX_INT_SET						0x58
#define TEGRA210_I2S_AXBAR_TX_INT_CLEAR						0x5c
#define TEGRA210_I2S_AXBAR_TX_CIF_CTRL						0x60
#define TEGRA210_I2S_AXBAR_TX_CTRL							0x64
#define TEGRA210_I2S_AXBAR_TX_SLOT_CTRL						0x68
#define TEGRA210_I2S_AXBAR_TX_CLK_TRIM						0x6c
#define TEGRA210_I2S_AXBAR_TX_CIF_FIFO_STATUS				0x74

/* Register offsets from TEGRA210_I2S*_BASE  */
#define TEGRA210_I2S_ENABLE									0x80
#define TEGRA210_I2S_SOFT_RESET								0x84
#define TEGRA210_I2S_CG										0x88
#define TEGRA210_I2S_STATUS									0x8c
#define TEGRA210_I2S_INT_STATUS								0x90
#define TEGRA210_I2S_CTRL									0xa0
#define TEGRA210_I2S_TIMING									0xa4
#define TEGRA210_I2S_SLOT_CTRL								0xa8
#define TEGRA210_I2S_CLK_TRIM								0xac

/* Fields in TEGRA210_I2S_STATUS  */
#define TEGRA210_I2S_STATUS_TX_ENABLED						BIT(0)
#define TEGRA210_I2S_STATUS_TXCIF_FIFO_EMPTY				BIT(1)
#define TEGRA210_I2S_STATUS_TXCIF_FIFO_FULL					BIT(2)

#define TEGRA210_I2S_STATUS_RX_ENABLED						BIT(8)
#define TEGRA210_I2S_STATUS_RXCIF_FIFO_EMPTY				BIT(9)
#define TEGRA210_I2S_STATUS_RXCIF_FIFO_FULL					BIT(10)
#define TEGRA210_I2S_STATUS_SLCG_CLKEN						BIT(12)

/* Fields in TEGRA210_I2S_INT_STATUS  */
#define TEGRA210_I2S_INT_STATUS_TX_DONE						BIT(0)
#define TEGRA210_I2S_INT_STATUS_TXCIF_FIFO_OVERRUN			BIT(1)
#define TEGRA210_I2S_INT_STATUS_RX_DONE						BIT(8)
#define TEGRA210_I2S_INT_STATUS_RXCIF_FIFO_UNDERRUN			BIT(9)

/* Fields in TEGRA210_I2S_CTRL */
/* (FSYNC width - 1) in bit clocks */
#define TEGRA210_I2S_CTRL_FSYNC_WIDTH_SHIFT		24
#define TEGRA210_I2S_CTRL_FSYNC_WIDTH_MASK_US		0xff
#define TEGRA210_I2S_CTRL_FSYNC_WIDTH_MASK		(TEGRA210_I2S_CTRL_FSYNC_WIDTH_MASK_US << TEGRA210_I2S_CTRL_FSYNC_WIDTH_SHIFT)

#define TEGRA210_I2S_POS_EDGE				0
#define TEGRA210_I2S_NEG_EDGE				1

#define TEGRA210_I2S_CTRL_EGDE_CTRL_SHIFT			20
#define TEGRA210_I2S_CTRL_EGDE_CTRL_MASK			(1 << TEGRA210_I2S_CTRL_EGDE_CTRL_SHIFT)
#define TEGRA210_I2S_CTRL_EGDE_CTRL_POS_EDGE		(TEGRA210_I2S_POS_EDGE << TEGRA210_I2S_CTRL_EGDE_CTRL_SHIFT)
#define TEGRA210_I2S_CTRL_EGDE_CTRL_NEG_EDGE		(TEGRA210_I2S_NEG_EDGE << TEGRA210_I2S_CTRL_EGDE_CTRL_SHIFT)

#define TEGRA210_I2S_CTRL_PIPE_MACRO_EN_SHIFT		19
#define TEGRA210_I2S_CTRL_PIPE_MACRO_EN_MASK		(1 << TEGRA210_I2S_CTRL_PIPE_MACRO_EN_SHIFT)

#define TEGRA210_I2S_FRAME_FORMAT_LRCK			0
#define TEGRA210_I2S_FRAME_FORMAT_FSYNC			1

#define TEGRA210_I2S_CTRL_FRAME_FORMAT_SHIFT		12
#define TEGRA210_I2S_CTRL_FRAME_FORMAT_MASK			(7 << TEGRA210_I2S_CTRL_FRAME_FORMAT_SHIFT)
#define TEGRA210_I2S_CTRL_FRAME_FORMAT_LRCK			(TEGRA210_I2S_FRAME_FORMAT_LRCK  << TEGRA210_I2S_CTRL_FRAME_FORMAT_SHIFT)
#define TEGRA210_I2S_CTRL_FRAME_FORMAT_FSYNC		(TEGRA210_I2S_FRAME_FORMAT_FSYNC << TEGRA210_I2S_CTRL_FRAME_FORMAT_SHIFT)

#define TEGRA210_I2S_CTRL_MASTER_ENABLE				(1 << 10)

#define TEGRA210_I2S_LRCK_LEFT_LOW			0
#define TEGRA210_I2S_LRCK_RIGHT_LOW			1

#define TEGRA210_I2S_CTRL_LRCK_SHIFT			9
#define TEGRA210_I2S_CTRL_LRCK_MASK				(1 << TEGRA210_I2S_CTRL_LRCK_SHIFT)
#define TEGRA210_I2S_CTRL_LRCK_L_LOW			(TEGRA210_I2S_LRCK_LEFT_LOW  << TEGRA210_I2S_CTRL_LRCK_SHIFT)
#define TEGRA210_I2S_CTRL_LRCK_R_LOW			(TEGRA210_I2S_LRCK_RIGHT_LOW << TEGRA210_I2S_CTRL_LRCK_SHIFT)

#define TEGRA210_I2S_CTRL_LPBK_ENABLE			(1 << 8)

#define TEGRA210_I2S_BITS_8					1
#define TEGRA210_I2S_BITS_12				2
#define TEGRA210_I2S_BITS_16				3
#define TEGRA210_I2S_BITS_20				4
#define TEGRA210_I2S_BITS_24				5
#define TEGRA210_I2S_BITS_28				6
#define TEGRA210_I2S_BITS_32				7

/* Sample container size; see {RX,TX}_MASK field in CH_CTRL below */
#define TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT		0
#define TEGRA210_I2S_CTRL_BIT_SIZE_MASK			(7                   << TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT)
#define TEGRA210_I2S_CTRL_BIT_SIZE_8			(TEGRA210_I2S_BITS_8  << TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT)
#define TEGRA210_I2S_CTRL_BIT_SIZE_12			(TEGRA210_I2S_BITS_12 << TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT)
#define TEGRA210_I2S_CTRL_BIT_SIZE_16			(TEGRA210_I2S_BITS_16 << TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT)
#define TEGRA210_I2S_CTRL_BIT_SIZE_20			(TEGRA210_I2S_BITS_20 << TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT)
#define TEGRA210_I2S_CTRL_BIT_SIZE_24			(TEGRA210_I2S_BITS_24 << TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT)
#define TEGRA210_I2S_CTRL_BIT_SIZE_28			(TEGRA210_I2S_BITS_28 << TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT)
#define TEGRA210_I2S_CTRL_BIT_SIZE_32			(TEGRA210_I2S_BITS_32 << TEGRA210_I2S_CTRL_BIT_SIZE_SHIFT)

/* Fields in TEGRA210_I2S_TIMING */
#define TEGRA210_I2S_TIMING_NON_SYM_ENABLE		(1 << 12)
#define TEGRA210_I2S_TIMING_CHANNEL_BIT_COUNT_SHIFT	0
#define TEGRA210_I2S_TIMING_CHANNEL_BIT_COUNT_MASK_US	0x7ff
#define TEGRA210_I2S_TIMING_CHANNEL_BIT_COUNT_MASK	(TEGRA210_I2S_TIMING_CHANNEL_BIT_COUNT_MASK_US << TEGRA210_I2S_TIMING_CHANNEL_BIT_COUNT_SHIFT)

/* Fields in TEGRA210_I2S_SLOT_CTRL */
/* Number of slots in frame, minus 1 */
#define TEGRA210_I2S_SLOT_CTRL_TOTAL_SLOTS_SHIFT		0
#define TEGRA210_I2S_SLOT_CTRL_TOTAL_SLOTS_MASK_US	0xf
#define TEGRA210_I2S_SLOT_CTRL_TOTAL_SLOTS_MASK		(TEGRA210_I2S_SLOT_CTRL_TOTAL_SLOTS_MASK_US << TEGRA210_I2S_SLOT_CTRL_TOTAL_SLOTS_SHIFT)

/* Fields in I2S_AXBAR_TX_CTRL_0  */
#define TEGRA210_I2S_AXBAR_TX_CTRL_DATA_OFFSET_SHIFT			8
#define TEGRA210_I2S_AXBAR_TX_CTRL_DATA_OFFSET_MASK_US			0x7ff
#define TEGRA210_I2S_AXBAR_TX_CTRL_DATA_OFFSET_MASK		(TEGRA210_I2S_AXBAR_TX_CTRL_DATA_OFFSET_MASK_US << TEGRA210_I2S_AXBAR_TX_CTRL_DATA_OFFSET_SHIFT)

/* Sample size is # bits from BIT_SIZE minus this field */
#define TEGRA210_I2S_AXBAR_TX_CTRL_MASK_BITS_SHIFT		4
#define TEGRA210_I2S_AXBAR_TX_CTRL_MASK_BITS_MASK_US	7
#define TEGRA210_I2S_AXBAR_TX_CTRL_MASK_BITS_MASK		(TEGRA210_I2S_AXBAR_TX_CTRL_MASK_BITS_MASK_US << TEGRA210_I2S_AXBAR_TX_CTRL_MASK_BITS_SHIFT)

#define TEGRA210_I2S_MSB_FIRST				0
#define TEGRA210_I2S_LSB_FIRST				1

#define TEGRA210_I2S_AXBAR_TX_CTRL_BIT_ORDER_SHIFT		0
#define TEGRA210_I2S_AXBAR_TX_CTRL_BIT_ORDER_MASK		(1                     << TEGRA210_I2S_AXBAR_TX_CTRL_BIT_ORDER_SHIFT)
#define TEGRA210_I2S_AXBAR_TX_CTRL_BIT_ORDER_MSB_FIRST	(TEGRA210_I2S_MSB_FIRST << TEGRA210_I2S_AXBAR_TX_CTRL_BIT_ORDER_SHIFT)
#define TEGRA210_I2S_AXBAR_TX_CTRL_BIT_ORDER_LSB_FIRST	(TEGRA210_I2S_LSB_FIRST << TEGRA210_I2S_AXBAR_TX_CTRL_BIT_ORDER_SHIFT)

#define TEGRA210_I2S_SLOT_CTRL_TX_SLOT_ENABLES_SHIFT	0
#define TEGRA210_I2S_SLOT_CTRL_TX_SLOT_ENABLES_MASK	(0xffff << TEGRA210_I2S_SLOT_CTRL_TX_SLOT_ENABLES_SHIFT)

/* Fields in I2S_AXBAR_RX_CTRL_0  */
#define TEGRA210_I2S_AXBAR_RX_CTRL_DATA_OFFSET_SHIFT			8
#define TEGRA210_I2S_AXBAR_RX_CTRL_DATA_OFFSET_MASK_US			0x7ff
#define TEGRA210_I2S_AXBAR_RX_CTRL_DATA_OFFSET_MASK		(TEGRA210_I2S_AXBAR_RX_CTRL_DATA_OFFSET_MASK_US << TEGRA210_I2S_AXBAR_RX_CTRL_DATA_OFFSET_SHIFT)

#define TEGRA210_I2S_AXBAR_RX_CTRL_MASK_BITS_SHIFT		4
#define TEGRA210_I2S_AXBAR_RX_CTRL_MASK_BITS_MASK_US	7
#define TEGRA210_I2S_AXBAR_RX_CTRL_MASK_BITS_MASK		(TEGRA210_I2S_AXBAR_RX_CTRL_MASK_BITS_MASK_US << TEGRA210_I2S_AXBAR_RX_CTRL_MASK_BITS_SHIFT)

#define TEGRA210_I2S_HIGHZ_NO				0
#define TEGRA210_I2S_HIGHZ_YES				1
#define TEGRA210_I2S_HIGHZ_ON_HALF_BIT_CLK		2

#define TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_SHIFT		1
#define TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_MASK		(3                                 << TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_SHIFT)
#define TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_NO		(TEGRA210_I2S_HIGHZ_NO              << TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_SHIFT)
#define TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_YES		(TEGRA210_I2S_HIGHZ_YES             << TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_SHIFT)
#define TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_ON_HALF_BIT_CLK	(TEGRA210_I2S_HIGHZ_ON_HALF_BIT_CLK << TEGRA210_I2S_AXBAR_RX_CTRL_HIGHZ_CTRL_SHIFT)

#define TEGRA210_I2S_AXBAR_RX_CTRL_BIT_ORDER_SHIFT		0
#define TEGRA210_I2S_AXBAR_RX_CTRL_BIT_ORDER_MASK		(1                     << TEGRA210_I2S_AXBAR_RX_CTRL_BIT_ORDER_SHIFT)
#define TEGRA210_I2S_AXBAR_RX_CTRL_BIT_ORDER_MSB_FIRST	(TEGRA210_I2S_MSB_FIRST << TEGRA210_I2S_AXBAR_RX_CTRL_BIT_ORDER_SHIFT)
#define TEGRA210_I2S_AXBAR_RX_CTRL_BIT_ORDER_LSB_FIRST	(TEGRA210_I2S_LSB_FIRST << TEGRA210_I2S_AXBAR_RX_CTRL_BIT_ORDER_SHIFT)

/* TDM mode slot enable bitmask */
#define TEGRA210_I2S_SLOT_CTRL_RX_SLOT_ENABLES_SHIFT	0
#define TEGRA210_I2S_SLOT_CTRL_RX_SLOT_ENABLES_MASK	(0xffff << TEGRA210_I2S_SLOT_CTRL_RX_SLOT_ENABLES_SHIFT)

/* Number of i2s controllers */
#define TEGRA210_I2S_COUNT				5

int tegra210_i2s_get(enum tegra210_ahub_cifs cif);
int tegra210_i2s_put(enum tegra210_ahub_cifs cif);
int tegra210_i2s_soft_reset(enum tegra210_ahub_cifs cif);
int tegra210_i2s_set_acif_param(enum tegra210_ahub_cifs cif,
				struct tegra210_axbar_cif_param *acif);
void tegra210_i2s_set_channel_bit_count(enum tegra210_ahub_cifs cif,
				int i2sclock, int srate);
void tegra210_i2s_set_data_offset(enum tegra210_ahub_cifs cif,
				int data_offset);
void tegra210_i2s_set_slot_control(enum tegra210_ahub_cifs cif,
				int slot_enables, int total_slots);
int tegra210_i2s_set_fmt(enum tegra210_ahub_cifs cif,
				unsigned int fmt, unsigned int bit_size,
				int fsync_width);
void tegra210_i2s_loopback_enable(enum tegra210_ahub_cifs cif);
void tegra210_i2s_start_capture(enum tegra210_ahub_cifs cif);
void tegra210_i2s_start_playback(enum tegra210_ahub_cifs cif);
void tegra210_i2s_stop_capture(enum tegra210_ahub_cifs cif);
void tegra210_i2s_stop_playback(enum tegra210_ahub_cifs cif);
void tegra210_i2s_enable(enum tegra210_ahub_cifs cif, bool en);
void tegra210_i2s_slcg_enable(enum tegra210_ahub_cifs cif, bool en);
#endif

