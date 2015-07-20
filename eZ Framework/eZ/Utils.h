/** Copyright (c) 2015 <zaklaus@github.io>. All rights reserved.
*
* This file is part of parent project and is released under ZaKlaus Public Code License Version 1.2 (the 'Licence'). You may not use this file
* except in compliance with the License. The rights granted to you under the
* License may not be used to create, or enable the creation or redistribution
* of, unlawful or unlicensed copies of a parent project, or to
* circumvent, violate, or enable the circumvention or violation of, any terms
* of an parent's project software license agreement.
*
* You may obtain a copy of the License at
* https://gist.github.com/zaklaus/ffc1accfc93af8ad4e41 and read it before using this file.
*
* The Original Code and all software distributed under the License are
* distributed on an 'AS IS' basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY
* KIND, either express or implied. See the License for the specific language
* governing permissions and limitations under the License.
* Contributors:
* - <zaklaus@github.io>
**/
#pragma once

#define EZ_FOR(p, q) for (int i = p; i < q; i++)

namespace eZ
{

	inline void *memcpy(void *dest, const void *src, size_t count)
	{
		const char *sp = (const char *)src;
		char *dp = (char *)dest;
		for (; count != 0; count--) *dp++ = *sp++;
		return dest;
	}

	inline void *memset(void *dest, char val, size_t count)
	{
		char *temp = (char *)dest;
		for (; count != 0; count--) *temp++ = val;
		return dest;
	}

	inline unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count)
	{
		unsigned short *temp = (unsigned short *)dest;
		for (; count != 0; count--) *temp++ = val;
		return dest;
	}

	inline size_t strlen(const char *str)
	{
		size_t retval;
		for (retval = 0; *str != '\0'; str++) retval++;
		return retval;
	}

	inline char* strcat(char *dest, const char *src)
	{
		char *rdest = dest;

		while (*dest)
			dest++;
		while (*dest++ = *src++)
			;
		return rdest;
	}
}