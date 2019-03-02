#include"Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (DataType*)malloc(sizeof(DataType) * 3);//�����ռ�
	ps->_top = 0;
	ps->_capacity = 3;//������3
}
void StackDestory(Stack* ps)
{
	assert(ps);

	if (ps->_a)//˳��ջ��Ϊ��
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = ps->_top = 0;
	}
}
void StackPush(Stack* ps, DataType x)
{
	assert(ps);

	if (ps->_top == ps->_capacity)//��ջ
	{
		ps->_a = (DataType*)realloc(ps->_a, sizeof(DataType) * 3);
		//���ܣ��ı�mem_address��ָ�ڴ�����Ĵ�СΪnewsize���ȡ� 
		//˵����������·���ɹ��򷵻�ָ�򱻷����ڴ��ָ�룬���򷵻ؿ�ָ��NULL��
		//���ڴ治��ʹ��ʱ��Ӧʹ��free()�������ڴ���ͷš�
		//ע�⣺����ԭʼ�ڴ��е����ݻ��Ǳ��ֲ���ġ�

		assert(ps->_a);//Ϊ�˷�ֹ�ڴ�û�з���ɹ�

		ps->_capacity *= 2;//����ÿ������һ��
	}
	ps->_a[ps->_top++] = x;
}
void StackPop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top > 0);

	ps->_top--;
}
DataType StackTop(Stack* ps)//��ȡջ������
{
	assert(ps->_a && ps->_top > 0);

	return ps->_a[ps->_top - 1];
}
//�� 0
//�ǿ� 1
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
