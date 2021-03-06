#ifndef MODEL_H
#define MODEL_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QPainter>
#include <QPaintEvent>

class Model
{
public:
    Model();
    Model(const Model&);

    ~Model();

public:
	void step(int elapsed);
	void add(int x, int y, qreal angle);
	void clear();

	void paint(QPainter *painter, QPaintEvent *event);
	void setDim(int w, int h);

	int getNumber() const;
    QVector<qreal> getTime() const;
    QVector<qreal> getImpulses() const;
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	void setNumber(int newNum);
	void setSide(int);
	void setSpeed(qreal);
	void setAtomR(qreal);
	void setElectronR(qreal);
	void setBinsNumber(int);
	void setBinIndex(int);
	void setPaintTraceOnly(bool);

	void save();
	void load();

	void setShowBins(bool);

	static const qreal timeStep;
	static const qreal measurePeriod;
	static const int MAX_HISTORY;

public:
	void checkBorders(QPointF& p, qreal& phi);
	void checkAtom(QPointF& p, qreal& phi, QPointF pOld);

	int width;
	int height;

	int xBegin;
	int yBegin;

	QBrush background;
	QBrush traceBrush;
	QBrush atomBrush;
	QBrush electronBrush;
	QBrush binBrush;

	int side;
	qreal atomR;
	qreal electronR;
	qreal speed;

	int num;
	QVector<qreal> speedDir;
	QVector<QPointF> positions;

	QVector<qreal> speedDir_save;
	QVector<QPointF> positions_save;

    bool paintTraceOnly;

    qreal timeFull, impulseSum;
    QVector<qreal> time;		// values of time
	QVector<qreal> impulses;	// overall sum of collision impulses
};

#endif
