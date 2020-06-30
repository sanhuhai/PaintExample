#include "paintarea.h"

PaintArea::PaintArea(QWidget* parent /* = Q_NULLPTR */) {
	setPalette(Qt::white);
	setAutoFillBackground(true);
	setMinimumSize(400, 400);
}

void PaintArea::setShape(Shape shape) {
	this->shape = shape;
	update();
}

void PaintArea::setPen(QPen pen) {
	this->pen = pen;
	update();
}

void PaintArea::setBrush(QBrush brush) {
	this->brush = brush;
	update();
}

void PaintArea::setFillRule(Qt::FillRule fillRule) {
	this->fillRule = fillRule;
	update();
}

void PaintArea::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setPen(pen);
	painter.setBrush(brush);
	QRect rect(50, 100, 300, 200);
	static const QPoint points[4] = { QPoint(150,100),QPoint(300,150),QPoint(350,250),QPoint(100,300) };
	int startAngel = 30 * 16;
	int spanAngel = 120 * 16;
	QPainterPath path;
	path.addRect(150, 150, 100, 100);
	path.moveTo(100, 100);
	path.cubicTo(300, 100, 200, 200, 300, 300);//绘制贝塞尔曲线
	path.cubicTo(100, 300, 200, 200, 100, 100);
	path.setFillRule(fillRule);
	switch (shape) {
	case Line://直线
		painter.drawLine(rect.topLeft(), rect.bottomRight());
		break;
	case Rectangle://长方形
		painter.drawRect(rect);
		break;
	case RoundRect://圆角方形
		painter.drawRoundRect(rect);
		break;
	case Ellipse://椭圆形
		painter.drawEllipse(rect);
		break;
	case Polygon://多边形
		painter.drawPolygon(points, 4);
		break;
	case Polyline://多边线
		painter.drawPolyline(points, 4);
		break;
	case Points://点
		painter.drawPoints(points, 4);
		break;
	case Arc://弧
		painter.drawArc(rect, startAngel, spanAngel);
		break;
	case Path://路径
		painter.drawPath(path);
		break;
	case Text://文本
		painter.drawText(rect, Qt::AlignCenter, "杨启招");
		break;
	case Pixmap://图片
		painter.drawPixmap(0,0, QPixmap("../img/yhyl.jpg"));
		break;
	default:
		break;
	}
}