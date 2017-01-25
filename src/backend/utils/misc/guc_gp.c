/*--------------------------------------------------------------------
 * guc_gp.c
 *
 * Additional Greenplum-specific GUCs are defined in this file, to
 * avoid adding so much stuff to guc.c. This makes it easier to diff
 * and merge with upstream.
 *
 * Portions Copyright (c) 2005-2010, Greenplum inc
 * Copyright (c) 2000-2009, PostgreSQL Global Development Group
 *
 * IDENTIFICATION
 *	  src/backend/utils/misc/guc_gp.c
 *
 *--------------------------------------------------------------------
 */
#include "postgres.h"

#include "cdb/cdbvars.h"
#include "postmaster/postmaster.h"
#include "utils/guc_tables.h"

struct config_string ConfigureNamesString_gp[] =
{
	{
		{"gp_role", PGC_SUSET, CLIENT_CONN_OTHER,
			gettext_noop("Sets the role for the session."),
			gettext_noop("Valid values are DISPATCH, EXECUTE, and UTILITY."),
			GUC_NOT_IN_SAMPLE | GUC_DISALLOW_IN_FILE
		},
		&gp_role_string,
		"dispatch", NULL, assign_gp_role, show_gp_role
	},
	{
		{"gp_session_role", PGC_BACKEND, CUSTOM_OPTIONS,
			gettext_noop("Reports the default role for the session."),
			gettext_noop("Valid values are DISPATCH, EXECUTE, and UTILITY."),
			GUC_NO_SHOW_ALL | GUC_NOT_IN_SAMPLE | GUC_DISALLOW_IN_FILE
		},
		&gp_session_role_string,
		"dispatch", NULL, assign_gp_session_role, show_gp_session_role
	},
	/* End-of-list marker */
	{
		{NULL, 0, 0, NULL, NULL}, NULL, NULL, NULL, NULL, NULL
	}
};

struct config_int ConfigureNamesInt_gp[] =
{
	{
		{"gp_dbid", PGC_POSTMASTER, PRESET_OPTIONS,
				gettext_noop("The dbid used by this server."),
				NULL,
				GUC_NOT_IN_SAMPLE | GUC_DISALLOW_IN_FILE
		},
		&GpIdentity.dbid,
		UNINITIALIZED_GP_IDENTITY_VALUE, PG_INT32_MIN, PG_INT32_MAX,
		NULL, NULL, NULL
	},

	{
		{"gp_contentid", PGC_POSTMASTER, PRESET_OPTIONS,
				gettext_noop("The contentid used by this server."),
				NULL,
				GUC_NOT_IN_SAMPLE | GUC_DISALLOW_IN_FILE
		},
		&GpIdentity.segindex,
		UNINITIALIZED_GP_IDENTITY_VALUE, PG_INT32_MIN, PG_INT32_MAX,
		NULL, NULL, NULL
	},

	{
		{"gp_num_contents_in_cluster", PGC_POSTMASTER, PRESET_OPTIONS,
				gettext_noop("Sets the number of segments in the cluster."),
				NULL,
				GUC_NOT_IN_SAMPLE | GUC_DISALLOW_IN_FILE
		},
		&GpIdentity.numsegments,
		UNINITIALIZED_GP_IDENTITY_VALUE, PG_INT32_MIN, PG_INT32_MAX,
		NULL, NULL, NULL
	},

	/* End-of-list marker */
	{
		{NULL, 0, 0, NULL, NULL}, NULL, NULL, NULL, NULL, NULL
	}
};

struct config_bool ConfigureNamesBool_gp[] =
{
	{
		{"silent_mode", PGC_POSTMASTER, LOGGING_WHEN,
				gettext_noop("Runs the server silently."),
				gettext_noop("If this parameter is set, the server will automatically run in the "
									 "background and any controlling terminals are dissociated."),
				GUC_NOT_IN_SAMPLE | GUC_NO_SHOW_ALL
		},
		&SilentMode,
		false, NULL, NULL, NULL
	},
	/* End-of-list marker */
	{
		{NULL, 0, 0, NULL, NULL}, NULL, false, NULL, NULL, NULL
	}
};