
#include "stdafx.h"
#include "eZ/String.h"
#include "eZ/Vector.h"

int _tmain(int argc, _TCHAR* argv[])
{
	eZ::String str("Hello C++  ");

	printf("%s\n", str.CStr());
	printf("%c\n", str[0]);

	str.CStr()[9] = '1';
	str.CStr()[10] = '1';
	str.CStr()[11] = '\0';
	printf("%s\n", str.CStr());

	eZ::String app("Your name is ");

	app += "Trevor and I wanna say:\n";
	app += &str;
	printf("%s\n", app.CStr());

	eZ::String test("abc d e fg");
	printf("%s\n", test.CStr());

	eZ::StringIterator Iter = test.It();
	Iter & 'c';
	++Iter;
	Iter & 'c';

	Iter >> 2;
	Iter & 'x';
	Iter >> 999;	// caps to string length-1
	Iter << 1;
	Iter & 'z';

	printf("%s\n", test.CStr());
	
	Iter.SeekBegin();
	printf("%c\n", *Iter);

	printf("%s\n", "Vector:");

	eZ::Vector<eZ::String> vec(&test);
	printf("SIZE: %d\n", vec.Length());
	vec.Push(&app);
	printf("SIZE: %d\n", vec.Length());
	printf("TEXT[1]: %s\n", vec[1]->CStr());
	eZ::String *app_ptr = vec.Pop();
	printf("TEXT_PTR: %s\n", app_ptr->CStr());
	printf("SIZE: %d\n", vec.Length());
	vec.Push(app_ptr);
	printf("SIZE: %d\n", vec.Length());
	printf("TEXT[1]: %s\n", vec[1]->CStr());

	getchar();
	return 0;
}

