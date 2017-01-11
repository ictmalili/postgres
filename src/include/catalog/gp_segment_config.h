/*-------------------------------------------------------------------------
 *
 * gp_segment_config.h
 *    a segment configuration table
 *
 *-------------------------------------------------------------------------
 */
#ifndef _GP_SEGMENT_CONFIG_H_
#define _GP_SEGMENT_CONFIG_H_

#include "catalog/genbki.h"

/*
 * Defines for gp_segment_config table
 */
#define GpSegmentConfigRelationName		"gp_segment_configuration"

#define MASTER_DBID 1
#define MASTER_CONTENT_ID (-1)
#define InvalidDbid 0

/* ----------------
 *		gp_segment_configuration definition.  cpp turns this into
 *		typedef struct FormData_gp_segment_configuration
 * ----------------
 */
#define GpSegmentConfigRelationId	5036

CATALOG(gp_segment_configuration,5036) BKI_SHARED_RELATION BKI_WITHOUT_OIDS
{
	int16		dbid;				/* up to 32767 segment databases */
	int16		content;			/* up to 32767 contents -- only 16384 usable with mirroring (see dbid) */

	char		role;
	char		preferred_role;
	char		mode;
	char		status;
	int32		port;

	int32		replication_port BKI_FORCE_NULL;
	int2vector	san_mounts;			/* one or more mount-points used by this segment. */

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	text		hostname;
	text		address;
#endif
} FormData_gp_segment_configuration;

/* no foreign keys */

/* ----------------
 *		Form_gp_segment_configuration corresponds to a pointer to a tuple with
 *		the format of gp_segment_configuration relation.
 * ----------------
 */
typedef FormData_gp_segment_configuration *Form_gp_segment_configuration;


/* ----------------
 *		compiler constants for gp_segment_configuration
 * ----------------
 */
#define Natts_gp_segment_configuration					11
#define Anum_gp_segment_configuration_dbid				1
#define Anum_gp_segment_configuration_content			2
#define Anum_gp_segment_configuration_role				3
#define Anum_gp_segment_configuration_preferred_role	4
#define Anum_gp_segment_configuration_mode				5
#define Anum_gp_segment_configuration_status			6
#define Anum_gp_segment_configuration_port				7
#define Anum_gp_segment_configuration_replication_port	8
#define Anum_gp_segment_configuration_san_mounts		9
#define Anum_gp_segment_configuration_hostname			10
#define Anum_gp_segment_configuration_address			11


#endif /*_GP_SEGMENT_CONFIG_H_*/