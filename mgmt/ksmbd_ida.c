// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *   Copyright (C) 2018 Samsung Electronics Co., Ltd.
 */

#include "../glob.h"
#include "ksmbd_ida.h"

#ifdef CONFIG_SMB_INSECURE_SERVER
int ksmbd_acquire_smb1_tid(struct ida *ida)
{
	return ida_alloc_range(ida, 1, 0xFFFE, KSMBD_DEFAULT_GFP);
}
#endif

int ksmbd_acquire_smb2_tid(struct ida *ida)
{
	return ida_alloc_range(ida, 1, 0xFFFFFFFE, KSMBD_DEFAULT_GFP);

}

#ifdef CONFIG_SMB_INSECURE_SERVER
int ksmbd_acquire_smb1_uid(struct ida *ida)
{
	return ida_alloc_range(ida, 1, 0xFFFE, KSMBD_DEFAULT_GFP);
}
#endif

int ksmbd_acquire_smb2_uid(struct ida *ida)
{
	int id;

	id = ida_alloc_min(ida, 1, KSMBD_DEFAULT_GFP);
	if (id == 0xFFFE)
		id = ida_alloc_min(ida, 1, KSMBD_DEFAULT_GFP);

	return id;
}

int ksmbd_acquire_async_msg_id(struct ida *ida)
{
	return ida_alloc_min(ida, 1, KSMBD_DEFAULT_GFP);
}

int ksmbd_acquire_id(struct ida *ida)
{
	return ida_alloc(ida, KSMBD_DEFAULT_GFP);
}

void ksmbd_release_id(struct ida *ida, int id)
{
	ida_free(ida, id);
}
