// MySdiDoc.h : CMySdiDoc ��Ľӿ�
//


#pragma once


class CMySdiDoc : public CDocument
{
protected: // �������л�����
	CMySdiDoc();
	DECLARE_DYNCREATE(CMySdiDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMySdiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


