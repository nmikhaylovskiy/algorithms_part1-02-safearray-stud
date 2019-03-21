////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Definition of some methods for class Subject
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
///
////////////////////////////////////////////////////////////////////////////////


#include "subject.h"


namespace xi
{


std::ostream &operator<<(std::ostream &outs, const Subject &subj)
{
    outs << subj.name << ": " << subj.title << "\n";

    int index = 0;
    int maxSubj = subj.description.getCapacity();               // добавочка по наводке Данила Кашина

    while (index < maxSubj && subj.description[index] != "")
        outs << subj.description[index++] << "\n";

    return outs;
}


std::istream &operator>>(std::istream &ins, Subject &subj)
{
    std::getline( ins, subj.name);
    std::getline( ins, subj.title);
    std::string line;

    for (int i = 0; i < Subject::MAX_LINES; ++i)
    {
        getline(ins, line);

        if(!line.empty())
        {
            subj.description[i] = line;
        } else
        {
            break;
        }

    }
    return ins;
}


} // namespace xi

