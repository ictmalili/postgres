/*-------------------------------------------------------------------------
 *
 * gp_san_config.h
 *    a san configuration table
 *
 * Copyright (c) 2009-2011, Greenplum Inc.
 *
 *-------------------------------------------------------------------------
 */
#ifndef _GP_SAN_CONFIG_H_
#define _GP_SAN_CONFIG_H_

#include "catalog/genbki.h"

/*
 * Defines for gp_san_config table.
 *
 * Stores info for failover using SAN.
 */
#define GpSanConfigRelationName		"gp_san_configuration"

/* ----------------
 *		gp_san_configuration definition.  cpp turns this into
 *		typedef struct FormData_gp_san_configuration
 * ----------------
 */
#define GpSanConfigRelationId	5035

CATALOG(gp_san_configuration,5035) BKI_SHARED_RELATION BKI_WITHOUT_OIDS
{
	int16	mountid;
	char	active_host;
	char	san_type;
#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	text	primary_host;
	text	primary_mountpoint;
	text	primary_device;
	text	mirror_host;
	text	mirror_mountpoint;
	text	mirror_device;
#endif
} FormData_gp_san_configuration;

/* no foreign keys */

/* ----------------
 *		Form_gp_san_configuration corresponds to a pointer to a tuple with
 *		the format of gp_san_configuration relation.
 * ----------------
 */
typedef FormData_gp_san_configuration *Form_gp_san_configuration;


/* ----------------
 *		compiler constants for gp_san_configuration
 * ----------------
 */
#define Natts_gp_san_configuration						9
#define Anum_gp_san_configuration_mountid				1
#define Anum_gp_san_configuration_active_host			2
#define Anum_gp_san_configuration_san_type				3
#define Anum_gp_san_configuration_primary_host			4
#define Anum_gp_san_configuration_primary_mountpoint	5
#define Anum_gp_san_configuration_primary_device		6
#define Anum_gp_san_configuration_mirror_host			7
#define Anum_gp_san_configuration_mirror_mountpoint		8
#define Anum_gp_san_configuration_mirror_device			9

#endif /*_GP_SAN_CONFIG_H_*/
