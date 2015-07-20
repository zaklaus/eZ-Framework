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

namespace eZ
{
	class String;

	class StringIterator
	{
	private:
		char* ptr;
		char* begin;
		char* end;
	public:

		StringIterator();
		StringIterator(char* ptr);
		StringIterator(String * A);
		StringIterator(StringIterator * A);
		~StringIterator();

		char* Begin();
		char* End();

		void SeekBegin();
		void SeekEnd();

		void operator =(char* ptr);
		void operator =(StringIterator * A);
		void operator =(String * A);
		void operator &(char c);
		char operator *();
		StringIterator& operator ++();
		StringIterator& operator --();
		void operator <<(size_t size);
		void operator >>(size_t size);
	};

	class String
	{
	private:
		char*			buffer;
		char*			begin;
		void			InitString(const char* str);
		void			AppendString(const char* str);
		StringIterator*	iter;
	public:
		String();
		String(const char* text);
		String(String* A);
		~String();

		char* CStr();
		char* Begin();
		char* End();
		StringIterator* It();


		void operator =(const char* text);
		void operator +=(const char* text);
		void operator +=(String * A);
		void operator =(String * A);
		char operator [](size_t ptr);
		void operator <<(const char* text);
		void operator <<(String * A);
	};
}

