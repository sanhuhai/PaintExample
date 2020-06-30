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
	path.cubicTo(300, 100, 200, 200, 300, 300);//���Ʊ���������
	path.cubicTo(100, 300, 200, 200, 100, 100);
	path.setFillRule(fillRule);
	switch (shape) {
	case Line://ֱ��
		painter.drawLine(rect.topLeft(), rect.bottomRight());
		break;
	case Rectangle://������
		painter.drawRect(rect);
		break;
	case RoundRect://Բ�Ƿ���
		painter.drawRoundRect(rect);
		break;
	case Ellipse://��Բ��
		painter.drawEllipse(rect);
		break;
	case Polygon://�����
		painter.drawPolygon(points, 4);
		break;
	case Polyline://�����
		painter.drawPolyline(points, 4);
		break;
	case Points://��
		painter.drawPoints(points, 4);
		break;
	case Arc://��
		painter.drawArc(rect, startAngel, spanAngel);
		break;
	case Path://·��
		painter.drawPath(path);
		break;
	case Text://�ı�
		painter.drawText(rect, Qt::AlignCenter, "������");
		break;
	case Pixmap://ͼƬ
		painter.drawPixmap(0,0, QPixmap("../img/yhyl.jpg"));
		break;
	default:
		break;
	}
}