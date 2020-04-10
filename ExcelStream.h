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
        //запись будем производить из верхнего левого узла листа
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
        str(std::basic_string<CharT>());//очистка текстового буфера
        return 0;
    }

protected:
    Excel::RangePtr rng_;
    int irow_;

    int icol_offset_;
    int icol_;

    //в отличие от библиотечной isspace не учитывает пробел в качестве разделителя
    bool IsSpace(char c) const {
        return (c == colDelim) || (c == rowDelim) || (c == '\r');
    }

    /**
     * Записывает строку s в файл Excel.
     * При этом признаком перехода к следующему столбцу является символ '\t',
     * а к следующей строке - '\n'.
     * Пример: строка вида "1\t2\n3\t4 5" будет записана в виде
     *		(1,1) = 1
     *		(1,2) = 2
     *		(2,1) = 3
     *		(2,2) = 4 5,
     * где (i,j) - координаты ячейки
     * todo: добавить обработку переполнения количества строк/столбцов
     */
    void output_string(const std::string& s);
};

void
excel_stringbuf::output_string(const std::string& s)
{
    //плавающий указатель на символы строки, отличные от пробельных (\n \t)
    std::string::const_iterator be = s.begin();
    std::string::const_iterator en = s.end();
    std::string::const_iterator it = be;

    while (it != en) {
        bool dump = false;
        bool isTab = false;
        bool isEnd = false;

        //если встретился символ перевода столбца или строки определяем,
        //необходимо ли произвести запись в текущую ячейку (iRow, iCol)

        if (*it == colDelim) {
            isTab = true;
            dump = !IsSpace(*be);
        }
        else if (*it == rowDelim) {
            isEnd = true;
            dump = !IsSpace(*be);
        }
        else {
            //как только встретился не разделительный символ, выставить на него be
            if (IsSpace(*be))
                be = it;

            if (it + 1 == en) {
                //прочли последний символ и он не пробельный
                dump = true;
                //при записи в ячейку предполагается, что
                //it указывает на разделительный символ
                it = en;
            }
        }

        if (dump) {
            //записать в текущую ячейку часть строки из промежутка [be, it)
            const std::string& item = s.substr(be - s.begin(), it - be);
            rng_->Item[irow_][icol_] = _variant_t(item.c_str());
        }

        //обновляем координаты положения в файле следующей строки
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
            //достигли конца строки
            break;
        }
        else
            it++;
    }
}

/**
 * Класс для записи в Excel с синтаксисом как у STL потоков
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
