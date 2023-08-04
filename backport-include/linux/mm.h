/*
 * Copyright © 2022 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 *
 */

#ifndef _BACKPORT_LINUX_MM_H
#define _BACKPORT_LINUX_MM_H
#include <linux/version.h>
#include <linux/pagevec.h>
#include <linux/kref.h>

#include_next <linux/mm.h>

#ifdef BPM_TOTALRAM_PAGES_FUNC_NOT_PRESENT
#define totalram_pages() totalram_pages
#endif

#ifdef BPM_VMA_SET_FILE_NOT_PRESENT
#define vma_set_file LINUX_DMABUF_BACKPORT(vma_set_file)
void vma_set_file(struct vm_area_struct *vma, struct file *file);
#endif

#ifdef BPM_IS_COW_MAPPING_NOT_PRESENT
static inline bool is_cow_mapping(vm_flags_t flags)
{
	return (flags & (VM_SHARED | VM_MAYWRITE)) == VM_MAYWRITE;
}
#endif

#endif /* _BACKPORT_LINUX_MM_H */
