#ifndef SEQLIST_HPP
#define SEQLIST_HPP
#define SEQ_INIT_SIZE 10
#define SEQ_INC_SIZE  2

typedef int ElemType;
typedef struct SeqList
{
	ElemType* data;  // .heap malloc 
	int capacity;   //容量
	int cursize;    // 当前元素的个数
}SeqList;

extern void InitSeqList(SeqList* plist);
extern void DestroySeqList(SeqList* plist);
extern int GetCapa(const SeqList* plist);
extern int GetSize(const SeqList* plist);
extern bool IsEmpty(const SeqList* plist);
extern bool IsFull(const SeqList* plist);
extern bool InsertElem(SeqList* plist, int pos, ElemType val);
extern bool Push_Back(SeqList* plist, ElemType val);
extern bool Push_Front(SeqList* plist, ElemType val);
extern void PrintInfo(const SeqList* plist);

extern int FindValue(const SeqList* plist, ElemType val);
// not val  ret -1;  have val ret index;
extern bool ErasePos(SeqList* plist, int index);
extern bool RemoveElem(SeqList* plist, ElemType val);
extern bool RemoveElemAll(SeqList* plist, ElemType val);
extern bool Pop_Back(SeqList* plist);
extern bool Pop_Front(SeqList* plist);

extern void BubbleSort(SeqList* plist);
extern void InsertSort(SeqList* plist);
extern void SelectSort(SeqList* plist);

extern int BinFindValue(const SeqList* plist, ElemType val);
extern ElemType GetElem(const SeqList* plist, int index);
extern bool GetElem(const SeqList* plist, int index, ElemType* pval);
extern bool Back(const SeqList* plist, ElemType* pval);
extern bool Front(const SeqList* plist, ElemType* pval);
extern void ClearSeqList(SeqList* plist);


#endif 
