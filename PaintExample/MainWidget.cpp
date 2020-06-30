#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    display();
}

void MainWidget::display() {
    paintarea = new PaintArea;
    shapeLabel = new QLabel("形状:");
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem("Line", PaintArea::Line);
    shapeComboBox->addItem("Rectangle", PaintArea::Rectangle);
    shapeComboBox->addItem("RountRect", PaintArea::RoundRect);
    shapeComboBox->addItem("Ellipse", PaintArea::Ellipse);
    shapeComboBox->addItem("Polygon", PaintArea::Polygon);
    shapeComboBox->addItem("Polyline", PaintArea::Polyline);
    shapeComboBox->addItem("Points", PaintArea::Points);
    shapeComboBox->addItem("Arc", PaintArea::Arc);
    shapeComboBox->addItem("Path", PaintArea::Path);
    shapeComboBox->addItem("Text", PaintArea::Text);
    shapeComboBox->addItem("Pixmap", PaintArea::Pixmap);
    connect(shapeComboBox, SIGNAL(activated(int)), this, SLOT(showShape(int)));

    penColorLabel = new QLabel("画笔颜色:");
    penColorFrame = new QFrame;
    penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    penColorFrame->setAutoFillBackground(true);
    penColorFrame->setPalette(Qt::blue);
    penColorButton = new QPushButton("更改");
    connect(penColorButton, SIGNAL(clicked()), this, SLOT(showPenColor()));

    penWidthLabel = new QLabel("画笔线宽:");
    penWidthSpinBox = new QSpinBox;
    penWidthSpinBox->setRange(0, 20);
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(showPenWidth(int)));

    penStyleLabel = new QLabel("画笔风格:");
    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem("SolidLine", static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem("DashLine", static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem("DotLine", static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem("DashDotLine", static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem("DashDotDotLine", static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem("CustomDashLine", static_cast<int>(Qt::CustomDashLine));
    connect(penStyleComboBox, SIGNAL(activated(int)), this, SLOT(showPenStyle(int)));

    penCapLabel = new QLabel("画笔顶帽:");
    penCapComboBox = new QComboBox;
    penCapComboBox->addItem("SquareCap", Qt::SquareCap);
    penCapComboBox->addItem("FlatCap", Qt::FlatCap);
    penCapComboBox->addItem("RoundCap", Qt::RoundCap);
    connect(penCapComboBox, SIGNAL(activated(int)), this, SLOT(showPenCap(int)));

    penJoinPointLabel = new QLabel("画笔连接点:");
    penJoinPointComboBox = new QComboBox;
    penJoinPointComboBox->addItem("BevelJoin", Qt::BevelJoin);
    penJoinPointComboBox->addItem("MiterJoin", Qt::MiterJoin);
    penJoinPointComboBox->addItem("RoundJoin", Qt::RoundJoin);
    connect(penJoinPointComboBox, SIGNAL(activated(int)), this, SLOT(showPenJoinPoint(int)));

    fillRuleLabel = new QLabel("填充模式:");
    fillRuleComboBox = new QComboBox;
    fillRuleComboBox->addItem("OddEven", Qt::OddEvenFill);
    fillRuleComboBox->addItem("Winding", Qt::WindingFill);
    connect(fillRuleComboBox, SIGNAL(activated(int)), this, SLOT(showFillRule()));

    spreadLabel = new QLabel("铺展效果:");
    spreadComboBox = new QComboBox;
    spreadComboBox->addItem("PadSpread", QGradient::PadSpread);
    spreadComboBox->addItem("RepeatSpread", QGradient::RepeatSpread);
    spreadComboBox->addItem("ReflectSpread", QGradient::ReflectSpread);
    connect(spreadComboBox, SIGNAL(activated(int)), this, SLOT(showSpreadStyle()));

    brushColorLabel = new QLabel("画刷颜色:");
    brushColorFrame = new QFrame;
    brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    brushColorFrame->setAutoFillBackground(true);
    brushColorFrame->setPalette(Qt::green);
    brushColorButton = new QPushButton("更改");
    connect(brushColorButton, SIGNAL(clicked()), this, SLOT(showBrushColor()));

    brushStyleLabel = new QLabel("画刷风格:");
    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem("SolidPattern", static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem("Dense1Pattern", static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem("Dense2Pattern", static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem("Dense3Pattern", static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem("Dense4Pattern", static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem("Dense5Pattern", static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem("Dense6Pattern", static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem("Dense7Pattern", static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem("HorPattern", static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem("VerPattern", static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem("CrossPattern", static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem("BDialogPattern", static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem("FDialogPattern", static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem("DialogCrossPattern", static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem("LinearGradientPattern", static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem("ConicalGradientPattern", static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem("RadialGradientPattern", static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem("TexturePattern", static_cast<int>(Qt::TexturePattern));
    connect(brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(showBrush(int)));

    rightLayout = new QGridLayout;
    rightLayout->addWidget(shapeLabel, 0, 0);
    rightLayout->addWidget(shapeComboBox, 0, 1);
    rightLayout->addWidget(penColorLabel, 1, 0);
    rightLayout->addWidget(penColorFrame, 1,1);
    rightLayout->addWidget(penColorButton, 1, 2);
    rightLayout->addWidget(penWidthLabel, 2, 0);
    rightLayout->addWidget(penWidthSpinBox, 2, 1);
    rightLayout->addWidget(penStyleLabel, 3, 0);
    rightLayout->addWidget(penStyleComboBox, 3, 1);
    rightLayout->addWidget(penCapLabel, 4, 0);
    rightLayout->addWidget(penCapComboBox, 4, 1);
    rightLayout->addWidget(penJoinPointLabel, 5, 0);
    rightLayout->addWidget(penJoinPointComboBox, 5, 1);
    rightLayout->addWidget(fillRuleLabel, 6, 0);
    rightLayout->addWidget(fillRuleComboBox, 6, 1);
    rightLayout->addWidget(spreadLabel, 7, 0);
    rightLayout->addWidget(spreadComboBox, 7, 1);
    rightLayout->addWidget(brushStyleLabel, 8, 0);
    rightLayout->addWidget(brushColorFrame, 8, 1);
    rightLayout->addWidget(brushColorButton, 8, 2);
    rightLayout->addWidget(brushStyleLabel, 9, 0);
    rightLayout->addWidget(brushStyleComboBox, 9, 1);
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(paintarea);
    mainLayout->addLayout(rightLayout);
    //mainLayout->addStretchFactor(paintarea, 1);
    //mainLayout->addStretchFactor(rightLayout, 0);
    showShape(shapeComboBox->currentIndex());
}

void MainWidget::showShape(int value) {
    PaintArea::Shape shape = PaintArea::Shape(shapeComboBox->itemData(value, Qt::UserRole).toInt());
    paintarea->setShape(shape);
}

void MainWidget::showPenColor() {
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
	penColorFrame->setPalette(QPalette(color));
	int value = penWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinPointComboBox->itemData(penJoinPointComboBox->currentIndex(), Qt::UserRole).toInt());
	paintarea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showPenStyle(int styleValue) {
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    penColorFrame->setPalette(QPalette(color));
    int value = penWidthSpinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(styleValue, Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinPointComboBox->itemData(penJoinPointComboBox->currentIndex(), Qt::UserRole).toInt());
    paintarea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showPenWidth(int value) {
    QColor color = penColorFrame->palette().color(QPalette::Window);
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinPointComboBox->itemData(penJoinPointComboBox->currentIndex(), Qt::UserRole).toInt());
	paintarea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showPenCap(int capValue) {
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(capValue, Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinPointComboBox->itemData(penJoinPointComboBox->currentIndex(), Qt::UserRole).toInt());
	paintarea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showPenJoinPoint(int joinValue) {
	QColor color = penColorFrame->palette().color(QPalette::Window);
	int value = penWidthSpinBox->value();
	Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(penCapComboBox->currentIndex(), Qt::UserRole).toInt());
	Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinPointComboBox->itemData(joinValue, Qt::UserRole).toInt());
	paintarea->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::showFillRule() {
    Qt::FillRule fillrule = Qt::FillRule(fillRuleComboBox->itemData(fillRuleComboBox->currentIndex(), Qt::UserRole).toInt());
    paintarea->setFillRule(fillrule);
}

void MainWidget::showSpreadStyle() {
    spread = QGradient::Spread(spreadComboBox->itemData(spreadComboBox->currentIndex(), Qt::UserRole).toInt());
}

void MainWidget::showBrush(int value) {
    QColor color = brushColorFrame->palette().color(QPalette::Window);
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(value, Qt::UserRole).toInt());
    if (style == Qt::LinearGradientPattern) {
        QLinearGradient linearGradient(0, 0, 400, 400);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, color);
        linearGradient.setColorAt(1.0, Qt::black);
        linearGradient.setSpread(spread);
        paintarea->setBrush(linearGradient);
    }
    else if (style == Qt::RadialGradientPattern) {
        QRadialGradient radialGradient(200, 200, 250, 250, 100);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, color);
        radialGradient.setColorAt(1.0, Qt::black);
        radialGradient.setSpread(spread);
        paintarea->setBrush(radialGradient);
    }
    else if (style == Qt::ConicalGradientPattern) {
        QConicalGradient conicalGradient(200, 200, 30);
        conicalGradient.setColorAt(0.0, Qt::white);
        conicalGradient.setColorAt(0.2, color);
        conicalGradient.setColorAt(1.0, Qt::black);
        conicalGradient.setSpread(spread);
        paintarea->setBrush(conicalGradient);
    }
    else if (style==Qt::TexturePattern) {
        paintarea->setBrush(QBrush(QPixmap("../img/yhyl.jpg")));
    }
    else
    {
        paintarea->setBrush(QBrush(color, style));
    }
}

void MainWidget::showBrushColor() {
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    brushColorFrame->setPalette(QPalette(color));
    showBrush(brushStyleComboBox->currentIndex());
}