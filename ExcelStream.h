#pragma once

#include <sstream>
#include "MSExcel.h"

typedef char CharT;
typedef std::char_traits<CharT> TraitsT;

class excel_stringbuf : public std::basic_stringbuf<CharT, TraitsT> {
public:
    static const char colDelim = '\t';
    static const char rowDelim = '\n';

    virtual ~excel_stringbuf() {
        sync();
    }

    void SetRange(Excel::RangePtr pRange, int irow_offset, int icol_offset) {
        rng_ = pRange;
        //������ ����� ����������� �� �������� ������ ���� �����
        irow_ = irow_offset;

        icol_offset_ = icol_offset;
        icol_ = icol_offset;
    }

    Excel::RangePtr GetRange() const {
        return rng_;
    }

    int& CurRow() {
        return irow_;
    }

    int& CurCol() {
        return icol_;
    }

    int sync() {
        output_string(str().c_str());
        str(std::basic_string<CharT>());//������� ���������� ������
        return 0;
    }

protected:
    Excel::RangePtr rng_;
    int irow_;

    int icol_offset_;
    int icol_;

    //� ������� �� ������������ isspace �� ��������� ������ � �������� �����������
    bool IsSpace(char c) const {
        return (c == colDelim) || (c == rowDelim) || (c == '\r');
    }

    /**
     * ���������� ������ s � ���� Excel.
     * ��� ���� ��������� �������� � ���������� ������� �������� ������ '\t',
     * � � ��������� ������ - '\n'.
     * ������: ������ ���� "1\t2\n3\t4 5" ����� �������� � ����
     *		(1,1) = 1
     *		(1,2) = 2
     *		(2,1) = 3
     *		(2,2) = 4 5,
     * ��� (i,j) - ���������� ������
     * todo: �������� ��������� ������������ ���������� �����/��������
     */
    void output_string(const std::string& s);
};

void
excel_stringbuf::output_string(const std::string& s)
{
    //��������� ��������� �� ������� ������, �������� �� ���������� (\n \t)
    std::string::const_iterator be = s.begin();
    std::string::const_iterator en = s.end();
    std::string::const_iterator it = be;

    while (it != en) {
        bool dump = false;
        bool isTab = false;
        bool isEnd = false;

        //���� ���������� ������ �������� ������� ��� ������ ����������,
        //���������� �� ���������� ������ � ������� ������ (iRow, iCol)

        if (*it == colDelim) {
            isTab = true;
            dump = !IsSpace(*be);
        }
        else if (*it == rowDelim) {
            isEnd = true;
            dump = !IsSpace(*be);
        }
        else {
            //��� ������ ���������� �� �������������� ������, ��������� �� ���� be
            if (IsSpace(*be))
                be = it;

            if (it + 1 == en) {
                //������ ��������� ������ � �� �� ����������
                dump = true;
                //��� ������ � ������ ��������������, ���
                //it ��������� �� �������������� ������
                it = en;
            }
        }

        if (dump) {
            //�������� � ������� ������ ����� ������ �� ���������� [be, it)
            const std::string& item = s.substr(be - s.begin(), it - be);
            rng_->Item[irow_][icol_] = _variant_t(item.c_str());
        }

        //��������� ���������� ��������� � ����� ��������� ������
        if (isTab) {
            icol_++;
            be = it;
        }
        else if (isEnd) {
            irow_++;
            icol_ = icol_offset_;
            be = it;
        }

        if (it == en) {
            //�������� ����� ������
            break;
        }
        else
            it++;
    }
}

/**
 * ����� ��� ������ � Excel � ����������� ��� � STL �������
 */
class excelstream : public std::basic_ostream<CharT, TraitsT> {
public:
    excelstream(Excel::RangePtr& rng, int irow_offset = 1, int icol_offset = 1)
        : std::basic_ostream<CharT, TraitsT>(&buf_) {
        buf_.SetRange(rng, irow_offset, icol_offset);
    }

    virtual ~excelstream() {
        flush();
    }

private:
    excel_stringbuf buf_;
};
