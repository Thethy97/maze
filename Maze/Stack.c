#include"Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (DataType*)malloc(sizeof(DataType) * 3);//创建空间
	ps->_top = 0;
	ps->_capacity = 3;//容量是3
}
void StackDestory(Stack* ps)
{
	assert(ps);

	if (ps->_a)//顺序栈不为空
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = ps->_top = 0;
	}
}
void StackPush(Stack* ps, DataType x)
{
	assert(ps);

	if (ps->_top == ps->_capacity)//满栈
	{
		ps->_a = (DataType*)realloc(ps->_a, sizeof(DataType) * 3);
		//功能：改变mem_address所指内存区域的大小为newsize长度。 
		//说明：如果重新分配成功则返回指向被分配内存的指针，否则返回空指针NULL。
		//当内存不再使用时，应使用free()函数将内存块释放。
		//注意：这里原始内存中的数据还是保持不变的。

		assert(ps->_a);//为了防止内存没有分配成功

		ps->_capacity *= 2;//容量每次增加一倍
	}
	ps->_a[ps->_top++] = x;
}
void StackPop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top > 0);

	ps->_top--;
}
DataType StackTop(Stack* ps)//获取栈顶数字
{
	assert(ps->_a && ps->_top > 0);

	return ps->_a[ps->_top - 1];
}
//空 0
//非空 1
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return 0;
	else
		return 1;
}
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}
