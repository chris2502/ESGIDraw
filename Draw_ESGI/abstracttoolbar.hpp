#ifndef ABSTRACTTOOLBAR_HPP
#define ABSTRACTTOOLBAR_HPP
#include "abstractallapplication.hpp"
#include <QVector>
#include <QToolBar>
#include <QStatusBar>

class AbstractToolBar
{
public:
    virtual QVector<QToolBar> ListToolBar()=0;
    virtual QStatusBar myStatusBar()=0;
};

#endif // ABSTRACTTOOLBAR_HPP
