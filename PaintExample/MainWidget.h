#pragma once
#include "paintarea.h"
#include <QtWidgets/QWidget>
#include "ui_MainWidget.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGradient>
#include <QGridLayout>
#include <QColorDialog>
#include <QHBoxLayout>
#include <QColor>
#include <QColorDialog>
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif // WIN32

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = Q_NULLPTR);
    void display();

private slots:
    void showShape(int);
    void showPenWidth(int);
    void showPenColor();
    void showPenStyle(int);
    void showPenCap(int);
    void showPenJoinPoint(int);
    void showSpreadStyle();
    void showFillRule();
    void showBrushColor();
    void showBrush(int);

private:
    Ui::MainWidgetClass ui;
    PaintArea* paintarea;
    QLabel* shapeLabel, * penColorLabel, * penWidthLabel, * penStyleLabel, * penCapLabel,
        * penJoinPointLabel, * fillRuleLabel, * spreadLabel, * brushLabel, * brushColorLabel, * brushStyleLabel;
    QComboBox* shapeComboBox, * penStyleComboBox, * penCapComboBox, * penJoinPointComboBox, 
             * fillRuleComboBox, * spreadComboBox, * brushStyleComboBox;
    QFrame* penColorFrame, * brushColorFrame;
    QSpinBox* penWidthSpinBox;
    QGradient::Spread spread;
    QPushButton* brushColorButton, * penColorButton;
    QGridLayout* rightLayout;
};
