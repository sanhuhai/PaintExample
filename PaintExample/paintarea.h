#pragma once
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QWidget>
#include <QPainterPath>
#include <QRect>
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif //WIN32

class PaintArea:public QWidget {
	Q_OBJECT
public:
	enum Shape{Line,Rectangle,RoundRect,Ellipse,Polygon,Polyline,Points,Arc,Path,Text,Pixmap};
	explicit PaintArea(QWidget* parent = Q_NULLPTR);
	void setShape(Shape);
	void setPen(QPen);
	void setBrush(QBrush);
	void setFillRule(Qt::FillRule);
	void paintEvent(QPaintEvent* event);

protected:

private:
	Shape shape;
	QPen pen;
	QBrush brush;
	Qt::FillRule fillRule;
};