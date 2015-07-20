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
	template<class T>
	class Iterator
	{
	private:
		T** ptr;
		T* begin;
		T* end;
	public:

		Iterator();
		Iterator(T ** A);
		Iterator(Iterator * A);
		~Iterator();

		T* Begin();
		T* End();

		void SeekBegin();
		void SeekEnd();

		void operator =(T* ptr);
		void operator =(Iterator * A);
		void operator &(T * c);
		T* operator *();
		Iterator& operator ++();
		Iterator& operator --();
		void operator <<(size_t size);
		void operator >>(size_t size);
	};

	template<class T>
	inline Iterator<T>::Iterator()
	{
	}
	template<class T>
	inline Iterator<T>::Iterator(T ** A)
	{
		this->ptr = A;
		this->begin = A;
		this->end = sizeof(ptr);
	}
	template<class T>
	inline Iterator<T>::Iterator(Iterator * A)
	{
		this->ptr = A->ptr;
		this->begin = A->begin;
		this->end = A->end;
	}
	template<class T>
	inline Iterator<T>::~Iterator()
	{
	}
	template<class T>
	inline T * Iterator<T>::Begin()
	{
		return this->begin;
	}
	template<class T>
	inline T * Iterator<T>::End()
	{
		return this->end;
	}
	template<class T>
	inline void Iterator<T>::SeekBegin()
	{
		this->ptr = this->begin;
	}
	template<class T>
	inline void Iterator<T>::SeekEnd()
	{
		this->ptr = this->end;
	}
	template<class T>
	inline void Iterator<T>::operator=(T * ptr)
	{
		this->ptr = ptr;
		this->begin = ptr->Begin();
		this->end = ptr->End();
	}
	template<class T>
	inline void Iterator<T>::operator=(Iterator * A)
	{
		this->ptr = A->ptr;
		this->begin = A->begin;
		this->end = A->end;
	}
	template<class T>
	inline void Iterator<T>::operator&(T * c)
	{
		*this->ptr = c;
	}
	template<class T>
	inline T* Iterator<T>::operator*()
	{
		return *this->ptr;
	}
	template<class T>
	inline Iterator<T>& Iterator<T>::operator++()
	{
		this->ptr++;

		if (this->ptr > this->end)
			this->ptr = this->end - 1;

		return *this;
	}
	template<class T>
	inline Iterator<T>& Iterator<T>::operator--()
	{
		this->ptr--;

		if (this->ptr < this->begin)
			this->ptr = this->begin;

		return *this;
	}
	template<class T>
	inline void Iterator<T>::operator<<(size_t size)
	{
		this->ptr -= size;

		if (this->ptr < this->begin)
			this->ptr = this->begin;
	}
	template<class T>
	inline void Iterator<T>::operator>>(size_t size)
	{
		this->ptr += size;

		if (this->ptr > this->end)
			this->ptr = this->end - 1;
	}

}