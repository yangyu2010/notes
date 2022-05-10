
```
int a = 10;
int &ref = a;
ref = 11;

cout << "a is " << a << endl;
cout << "ref is " << ref << endl;

// 11
// 11
```
引用加上`const`修饰, 不可以通过引用修改数据了，称为常引用
`const`必须写在&符号的左边，才能算是常引用

```
int a = 10;
const int &ref = a;
//ref = 11;

// const int *p = &a;
// *p = 11;
// 不行 常量指针 有const修饰

cout << "a is " << a << endl;
cout << "ref is " << ref << endl;
```

当`const`写在&符号的右边时, 可以通过引用修改数据
```
int a = 10;
int & const ref = a;
ref = 11;

cout << "a is " << a << endl;
```
类似于指针, 不能修改指针的指向, 但是可以通过`*p`修改指针指向的数据
```
int a = 10;
int b = 20;
int *const p = &a;
//p = &b;
*p = 11;

cout << "a is " << a << endl;
```

---

◼ 当常引用指向了不同类型的数据时，会产生临时变量，即引用指向的并不是初始化时的那个变量

```
int a = 10;
const int &ref = a;
// ref = 20;
a = 20;
cout << "a is " << a << endl;
cout << "ref is " << ref << endl;

// 20
// 20
```

```
	int a = 10;
 mov         dword ptr [ebp-8],0Ah  
	const int &ref = a;
 lea         eax,[ebp-8]  
 mov         dword ptr [ebp-0Ch],eax  
	// ref = 20;
	a = 20;
 mov         dword ptr [ebp-8],14h  
	cout << "a is " << a << endl;
```

----

```
int a = 10;
const long &ref = a;
// ref = 20;
a = 20;
cout << "ref is " << ref << endl;
cout << "a is " << a << endl;

// 20
// 10
```

```
	int a = 10;
 mov         dword ptr [ebp-0Ch],0Ah  
	const long &ref = a;
 mov         eax,dword ptr [ebp-0Ch]  
 mov         dword ptr [ebp-8],eax  
 lea         ecx,[ebp-8]  
 mov         dword ptr [ebp-10h],ecx  
	// ref = 20;
	a = 20;
 mov         dword ptr [ebp-0Ch],14h  
	cout << "a is " << a << endl;
```

