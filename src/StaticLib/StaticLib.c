#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	if (l == NULL || p == NULL)
		return;
	
	p->pPrev = NULL;
	if (l->header == NULL) {
		p->pNext = NULL;
		l->header = p;
		l->footer = p;

	}

	else {
		p->pNext = l->header;
		l->header->pPrev = p;
		l->header = p;
	}
	
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{

	if (l == NULL || p == NULL)
		return;

	p->pNext = NULL;
	if (l->footer == NULL) {
		p->pPrev = NULL;
		l->header = p;
		l->footer = p;
	}
	else {
		p->pPrev = l->footer;
		l->footer->pNext = p;
		l->footer = p;
	}

}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (l == NULL || p == NULL)
		return;
	if (p->pPrev != NULL && p->pNext != NULL) {
		p->pPrev->pNext = p->pNext;
		p->pNext->pPrev = p->pPrev;

	}
	else if (p->pPrev == NULL) {
		l->header = p->pNext;

		if (p->pNext != NULL)
			p->pNext->pPrev = NULL;
		else
		{
			l->header = NULL;
			l->footer = NULL;
		}
	}
	else if (p->pNext == NULL) {
		l->footer = p->pPrev;
		p->pPrev->pNext = NULL;

		if (p->pPrev != NULL)
			p->pPrev->pNext = NULL;
		else
		{
			l->header = NULL;
			l->footer = NULL;
		}
	}
	p->pNext = NULL;
	p->pPrev = NULL;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (l == NULL || p == NULL)
		return;
	remove_node(l, p->pNext);
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (l == NULL || p == NULL)
		return;
	remove_node(l, p->pPrev);
}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
