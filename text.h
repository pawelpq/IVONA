#ifndef TEXT_H
#define TEXT_H
#include <QTextCursor>
#include <QTextDocument>
#include "wstaw.h"
class text : public QTextDocument
{
    Q_OBJECT
public:
    explicit text(QObject *parent = 0);

signals:

public slots:

};

#endif // TEXT_H
