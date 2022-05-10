#include <iostream>
#include <string.h>
using namespace std;

int sum(int v1, int v2) {
	return v1 + v2;
}

//int main() {
	//return 0;
//}

int main() {

	int a = 10;
	int b = 20;
	int *const p = &a;
	//p = &b;
	*p = 11;

	cout << "a is " << a << endl;

	return 0;
}

int main6() {

	int a = 10;
	const long &ref = a;
	// ref = 20;
	a = 20;
	cout << "a is " << a << endl;
	cout << "ref is " << ref << endl;

	/*
	mov         dword ptr [ebp-4],eax
	mov         dword ptr [ebp-0Ch],0Ah
	mov         eax,dword ptr [ebp-0Ch]
	mov         dword ptr [ebp-8],eax
	lea         ecx,[ebp-8]
	mov         dword ptr [ebp-10h],ecx
	mov         dword ptr [ebp-0Ch],14h
	*/

	getchar();
	return 0;
}

int main5() {
	
	int a = 10;
	int *p = &a;
	*p = 30;
	cout << a << endl;

	return 0;
}


int main4() {
	int c = sum(10, 20);
	cout << c << endl;
	return 0;
}

int main2() {
	// cout << "hello world" << endl; 
	
	char s1[] = "abc";
	char s2[] = "abc";
	char s3[] = "aBc";
	char s4[] = "ccb";
	
	printf("%d, %d, %d", strcmp(s1, s2), strcmp(s1, s3), strcmp(s1, s4));

	getchar();
	return 0;
}

/*
指针变量
*/
int main3() {
	
	/*
	int a = 10;
	//printf("修改前，a的值：%d\n", a);
	int *p;
	p = &a;
	*p = 9;
	//printf("修改后，a的值：%d", a);
	*/

	//char a = 10, b = 9;
	//printf("更换前：a=%d, b=%d\n", a, b);
	//swap(a, b);
	//printf("更换后：a=%d, b=%d", a, b);

	//char *s = "abc";
	//int len = strlen(s);
	//printf("字符串长度：%d", len);

	getchar();
	return 0;
}

void swap(char v1, char v2) {
	printf("更换前：v1=%d, v2=%d\n", v1, v2);

	char temp;
	temp = v1;
	v1 = v2;
	v2 = temp;

	printf("更换后：v1=%d, v2=%d\n", v1, v2);
}
