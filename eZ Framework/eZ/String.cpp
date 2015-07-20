#include "stdafx.h"
#include "String.h"
#include "Utils.h"

void eZ::String::InitString(const char * str)
{
	delete[] this->buffer;
	this->buffer = new char[eZ::strlen(str) + 1];
	eZ::memcpy(this->buffer, str, strlen(str) + 1);

	this->begin = this->buffer;
}

void eZ::String::AppendString(const char * str)
{
	char* temp = new char[eZ::strlen(this->begin)+eZ::strlen(str)+1];
	eZ::memcpy(temp, this->begin, eZ::strlen(this->begin)+1);

	this->buffer = eZ::strcat(temp, str);
}

eZ::String::String()
{
	this->iter = new StringIterator(this);
}

eZ::String::String(const char * text)
{
	this->InitString(text);
	this->iter = new StringIterator(this);
}

eZ::String::String(String * A)
{
	this->InitString(A->buffer);
	this->iter = new StringIterator(this);
}


eZ::String::~String()
{
	delete[] this->buffer;
}

char * eZ::String::CStr()
{
	return this->buffer;
}

char * eZ::String::Begin()
{
	return this->begin;
}

char * eZ::String::End()
{
	return this->begin + eZ::strlen(this->begin);
}

eZ::StringIterator * eZ::String::It()
{
	return this->iter;
}

void eZ::String::operator=(const char * text)
{
	this->InitString(text);
}

void eZ::String::operator+=(const char * text)
{
	this->AppendString(text);
}

void eZ::String::operator+=(String * A)
{
	this->AppendString(A->buffer);
}

void eZ::String::operator=(String * A)
{
	this->AppendString(A->buffer);
}

char eZ::String::operator[](size_t ptr)
{
	return this->buffer[ptr];
}

void eZ::String::operator<<(const char * text)
{
	this->AppendString(text);
}

void eZ::String::operator<<(String * A)
{
	this->AppendString(A->buffer);
}

eZ::StringIterator::StringIterator()
{
}

eZ::StringIterator::StringIterator(char * ptr)
{
	this->ptr = ptr;
	this->begin = ptr;
	this->end = ptr + eZ::strlen(ptr);
}

eZ::StringIterator::StringIterator(String * A)
{
	this->ptr = A->CStr();
	this->begin = A->Begin();
	this->end = A->End();
}

eZ::StringIterator::StringIterator(StringIterator * A)
{
	this->ptr = A->ptr;
	this->begin = A->begin;
	this->end = A->end;
}

eZ::StringIterator::~StringIterator()
{
}

char * eZ::StringIterator::Begin()
{
	return this->begin;
}

char * eZ::StringIterator::End()
{
	return this->end;
}

void eZ::StringIterator::SeekBegin()
{
	this->ptr = this->begin;
}

void eZ::StringIterator::SeekEnd()
{
	this->ptr = this->end;
}

void eZ::StringIterator::operator=(char * ptr)
{
	this->ptr = ptr;
	this->begin = ptr;
	this->end = ptr + eZ::strlen(ptr);
}

void eZ::StringIterator::operator=(StringIterator * A)
{
	this->ptr = A->ptr;
	this->begin = A->begin;
	this->end = A->end;
}

void eZ::StringIterator::operator=(String * A)
{
	this->ptr = A->CStr();
	this->begin = A->Begin();
	this->end = A->End();
}

void eZ::StringIterator::operator&(char c)
{
	*this->ptr = c;
}

char eZ::StringIterator::operator*()
{
	return *this->ptr;
}

eZ::StringIterator& eZ::StringIterator::operator++()
{
	this->ptr++;

	if (this->ptr > this->end)
		this->ptr = this->end-1;

	return *this;
}

eZ::StringIterator& eZ::StringIterator::operator--()
{
	this->ptr--;

	if (this->ptr < this->begin)
		this->ptr = this->begin;

	return *this;
}

void eZ::StringIterator::operator<<(size_t size)
{
	this->ptr -= size;

	if (this->ptr < this->begin)
		this->ptr = this->begin;
}

void eZ::StringIterator::operator>>(size_t size)
{
	this->ptr += size;

	if (this->ptr > this->end)
		this->ptr = this->end-1;
}
