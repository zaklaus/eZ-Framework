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

#include "Utils.h"
#include "Iterator.h"

namespace eZ
{
	template<class T>
	class Vector
	{
	private:
		size_t			length;
		T**				data;
		T*				begin;
		T*				end;

		void		Expand(size_t length);
		void		Shrink(size_t length);
		void		Clear(size_t begin, size_t end);
		
	public:
		Vector();
		Vector(T * A);
		~Vector();

		size_t	Length();
		void	Push(T * A);
		void	Erase();
		void	Erase(size_t begin, size_t end);
		T*		Pop();
		T*		At(size_t index);
		T*		Begin();
		T*		End();

		T*		operator [](size_t index);
	};


	template<class T>
	inline void Vector<T>::Expand(size_t length)
	{
		size_t newSize = this->length + length;
		T** newArr = new T*[newSize];

		eZ::memcpy(newArr, this->data, this->length * sizeof(T));

		EZ_FOR(0, this->length)
		{
			this->data[i] = nullptr;
		}
		this->data = nullptr;
		this->length = newSize;
		this->data = newArr;
		this->end += length;
	}

	template<class T>
	inline void Vector<T>::Shrink(size_t length)
	{
		if (this->length == 0)
			return;

		size_t newSize = this->length - 1;
		T** newArr = new T*[newSize];

		eZ::memcpy(newArr, this->data, (this->length - 1) * sizeof(T));

		EZ_FOR(0, this->length)
		{
			this->data[i] = nullptr;
		}
		this->data = nullptr;
		this->length = newSize;
		this->data = newArr;
		this->end -= length;
	}
	template<class T>
	inline void Vector<T>::Clear(size_t begin, size_t end)
	{
		EZ_FOR(begin, end)
		{
			delete this->data[i];
			this->data[i] = nullptr;
		}
	}
	template<class T>
	inline Vector<T>::Vector()
	{
		this->length = 0;
		this->data = nullptr;
		this->begin = nullptr;
		this->end = nullptr;
	}

	template<class T>
	inline Vector<T>::Vector(T * A)
	{
		this->Expand(1);
		this->data[this->length] = A;
		this->begin = this->data[0];
		this->end = this->data[0];
	}

	template<class T>
	inline Vector<T>::~Vector()
	{
		EZ_FOR(0, this->length)
		{
			this->data[i] = nullptr;
		}
		this->data = nullptr;
	}
	template<class T>
	inline size_t Vector<T>::Length()
	{
		return this->length;
	}
	template<class T>
	inline void Vector<T>::Push(T * A)
	{
		this->Expand(1);
		this->data[this->length] = A;
	}
	template<class T>
	inline void Vector<T>::Erase()
	{
		this->Clear(0, this->length);
	}
	template<class T>
	inline void eZ::Vector<T>::Erase(size_t begin, size_t end)
	{
		this->Clear(begin, end);
	}
	template<class T>
	inline T* Vector<T>::Pop()
	{
		T* ret = this->data[this->length - 1];
		this->Shrink(1);
		return ret;
	}
	template<class T>
	inline T* Vector<T>::At(size_t index)
	{
		if (index < 0 || index >= this->length)
		{
			//TODO: RAISE 'OUT_OF_BOUNDS' EXCEPTION
			return new T();
		}

		return this->data[index];
	}
	template<class T>
	inline T * eZ::Vector<T>::Begin()
	{
		return this->begin;
	}
	template<class T>
	inline T * eZ::Vector<T>::End()
	{
		return this->end;
	}
	template<class T>
	inline T* Vector<T>::operator[](size_t index)
	{
		return this->At(index);
	}

}

