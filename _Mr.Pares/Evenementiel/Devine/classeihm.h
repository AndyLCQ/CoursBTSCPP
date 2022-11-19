#ifndef CLASSEIHM_H
#define CLASSEIHM_H

#include <QDialog>

namespace Ui {
class classeIHM;
}

class classeIHM : public QDialog
{
    Q_OBJECT
    
public:
    explicit classeIHM(QWidget *parent = 0);
    ~classeIHM();
    
private:
    Ui::classeIHM *ui;
};

#endif // CLASSEIHM_H
