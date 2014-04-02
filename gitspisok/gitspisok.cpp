// gitspisok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
 /*!
       * General function 
       */
template <typename valueType> class List
{
//  конструктор
    List(valueType Value = 0, List *Next = NULL)
    {
        this->Value = Value;
        this->Next = Next;
    }

    void Clone(List *to)
    {

    }

	 /*!
       * Input to the end
       */
//  Вставка значения в конец списка
    void Append(valueType Value)
    {
        List *newValue = new List(Value);
        List *tmp = this;

        while(tmp->Next) 
            tmp = tmp->Next;

        tmp->Next = newValue;
    }
	 /*!
       * Output from the end
       */

//  Удаление из списка по номеру
    void Delete(unsigned int index)
    {
        List *tmp = this;

        if(!index)
        {
            tmp = this->Next;

            this->Value = this->Next->Value;
            this->Next = this->Next->Next;

            delete tmp;

            return;
        }

        List *tmpDeleted;

        for(int i = 0; i < index - 1; ++i)
            tmp = tmp->Next;

        tmpDeleted = tmp->Next;
        tmp->Next = tmp->Next->Next;

        delete tmpDeleted;
    }

	 /*!
       * Return number 
       */
//  Возврат значения по номеру
    valueType GetValue(unsigned int index)
    {
        if(!index)
            return this->Value;

        List *tmp = this;

        for(unsigned int i = 0; i < index; ++i)
            tmp = tmp->Next;

        return tmp->Value;
    }
